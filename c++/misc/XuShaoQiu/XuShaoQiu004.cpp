#include <list>
#include <mutex>
#include <functional>
#include <memory>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <csignal>

class EventListener {
public:
    virtual void onEvent(int event) = 0;
};

class EventHub {
public:
    EventHub() {
        eventThead_ = std::thread(&EventHub::eventThread, this);
    }

    ~EventHub() {
        interrupted_.store(true);
        eventQueueCondition_.notify_one();
        eventThead_.join();
    }

    void eventThread() {
        while (!interrupted_.load()) {
            eventLoop();
        }
    }

    void eventLoop() {
        std::unique_lock<std::mutex> lock(eventQueueMutex_);
        while (eventQueue_.empty()) {
            if (interrupted_.load()) {
                return;
            }
            eventQueueCondition_.wait(lock);
        }

        auto event = eventQueue_.front();
        eventQueue_.pop_front();
        publishEventSync(event);
    }

    void addEventListener(EventListener *listener) {
        std::lock_guard<std::mutex> lock(listenerMutex_);
        printf("addEventListener %p\n", listener);
        listenerList_.push_back(listener);
    }

    void removeEventListener(EventListener *listener) {
        std::lock_guard<std::mutex> lock(listenerMutex_);
        printf("removeEventListener %p\n", listener);
        for (auto it = listenerList_.begin(); it != listenerList_.end();) {
            if (*it == listener) {
                it = listenerList_.erase(it);
            } else {
                ++it;
            }
        }
    }

    void clearEventListener() {
        listenerList_.clear();
    }

    void publishEventSync(int event) {
        std::lock_guard<std::mutex> lock(listenerMutex_);
        for (auto const &listener : listenerList_) {
            listener->onEvent(event);
        }
    }

    void publishEventAsync(int event) {
        std::lock_guard<std::mutex> lock(eventQueueMutex_);
        eventQueue_.push_back(event);
        eventQueueCondition_.notify_one();
    }

private:
    std::mutex listenerMutex_;
    std::list<EventListener*> listenerList_;

    std::mutex eventQueueMutex_;
    std::condition_variable eventQueueCondition_;
    std::list<int> eventQueue_;

    std::thread eventThead_;
    std::atomic<bool> interrupted_{false};
};

static EventHub *eventHub;

enum EventType {
    INIT_SUCCESS,
    CONNECT_SUCCESS,
    CONNECT_ABORT,
    STOP_SOURCE
};

void processClientDisconnect() {
    eventHub->publishEventAsync(STOP_SOURCE);
}

void processStopSource(EventListener *listener) {
    eventHub->removeEventListener(listener);
}

class EventListener1 : public EventListener {
    void onEvent(int event) override {
        printf("EventListener1:%d\n", event);
        if (event == STOP_SOURCE) {
            processStopSource(this);
        }
    }
};

class EventListener2 : public EventListener {
    void onEvent(int event) override {
        printf("EventListener2:%d\n", event);
        if (event == CONNECT_ABORT) {
            processClientDisconnect();
        }
    }
};

int main() {
    eventHub = new EventHub();
    EventListener *listener1 = new EventListener1();
    EventListener *listener2 = new EventListener2();
    eventHub->addEventListener(listener1);
    eventHub->addEventListener(listener2);
    eventHub->publishEventSync(INIT_SUCCESS);
    usleep(100);
    eventHub->publishEventAsync(CONNECT_SUCCESS);
    usleep(100);
    eventHub->publishEventAsync(CONNECT_ABORT);
    usleep(1000);
    eventHub->clearEventListener();
    delete eventHub;
    delete listener1;
    delete listener2;
    return 0;
}