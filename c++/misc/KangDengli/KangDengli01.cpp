#include <cassert>
#include <utility>
#include <memory>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <iostream>

class Thread {
public:
    explicit Thread(std::string threadName);
    virtual ~Thread() = default;

    virtual void start();

    virtual void stop();

    virtual void pause();

    virtual void resume();

protected:
    virtual bool threadLoop() = 0;
    virtual bool prepare();
    virtual void destroy();

private:
    void interrupt(bool);

    void run();

protected:
    std::thread thread_;
    std::atomic<bool> interrupted_;
    std::atomic<bool> started_;
    std::atomic<bool> paused_;
    std::condition_variable cond_;
    std::mutex mutex_;
    std::string threadName_;
};

Thread::Thread(std::string threadName) :
        interrupted_(false),
        started_(false),
        paused_(false),
        threadName_(std::move(threadName)) {
}

void Thread::start() {
    interrupt(false);
    thread_ = std::thread(&Thread::run, this);
    started_ = true;
}

void Thread::stop() {
    if (!started_) {
        return;
    }
    if (paused_) {
        resume();
    }
    interrupt(true);
    destroy();
}

void Thread::pause() {
    paused_ = true;
}

void Thread::resume() {
    paused_ = false;
    cond_.notify_one();
}

void Thread::destroy() {
    if(!started_) {
        return;
    }
    started_ = false;
    if (thread_.joinable()) {
        thread_.join();
    }
}

void Thread::interrupt(bool flag) {
    interrupted_ = flag;
}

void Thread::run() {
    do {
        if (paused_) {
            std::unique_lock<std::mutex> lock(mutex_);
            cond_.wait(lock, [&] {
                return !paused_;
            });
        }

        if (!threadLoop()) {
            started_ = false;
            break;
        }
    } while (!interrupted_);
}

class MyThread : public Thread {
public:
    MyThread(std::string threadName) : Thread(threadName) {
    }

    virtual bool threadLoop() override {
        std::cout << "threadName: " << threadName_ << std::endl;
        return true;
    }
};

int main() {
    MyThread thread("thread");
    thread.start();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    thread.pause();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    thread.resume();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    thread.stop();
    return 0;
}