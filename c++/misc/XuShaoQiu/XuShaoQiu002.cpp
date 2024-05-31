#include <cstdio>
#include <cstring>
#include <functional>
#include <thread>
#include <atomic>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class EPoll {
public:
    EPoll(int maxEvents, std::function<void(int fd)> readAvailableCallback);
    ~EPoll();

    bool insertFd(int fd) const;

private:
    void eventLoop();
private:
    const int maxEvents_;
    int epollFd_ = -1;
    int exitEventFd_ = -1;
    std::function<void(int fd)> readAvailableCallback_;
    std::thread thread_;
    std::atomic<bool> interrupted_{};
};

EPoll::EPoll(const int maxEvents, std::function<void(int)> readAvailableCallback) : maxEvents_(maxEvents) {
    readAvailableCallback_ = std::move(readAvailableCallback);
    epollFd_ = epoll_create1(0);
    if (epollFd_ <= 0) {
        printf("epoll_create error: %s\n", strerror(errno));
        return;
    }

    exitEventFd_ = eventfd(0, 0);
    if (exitEventFd_ <= 0) {
        printf("create eventfd error: %s\n", strerror(errno));
        return;
    }
    insertFd(exitEventFd_);

    interrupted_.store(false);
    thread_ = std::thread(&EPoll::eventLoop, this);
}

EPoll::~EPoll() {
    interrupted_.store(true);
    auto ret = eventfd_write(exitEventFd_, 0);
    if (ret != 0) {
        printf("eventfd_write error : ret = %d, error: %s\n", ret, strerror(errno));
    }
    thread_.join();
    close(exitEventFd_);
    close(epollFd_);
}

bool EPoll::insertFd(int fd) const {
    struct epoll_event event{};
    event.events = EPOLLIN;
    event.data.fd = fd;
    if (epoll_ctl(epollFd_, EPOLL_CTL_ADD, fd, &event) < 0) {
        printf("epoll_ctl add error: %s\n", strerror(errno));
        return false;
    }

    return true;
}

void EPoll::eventLoop() {
    while (!interrupted_.load()) {
        struct epoll_event events[maxEvents_];
        int count = epoll_wait(epollFd_, events, maxEvents_, -1);
        if (count == -1) {
            printf("epoll_wait error: %s\n", strerror(errno));
            continue;
        }

        for (int i = 0; i < count; ++i) {
            if (events[i].data.fd == exitEventFd_) {
                printf("exit event loop\n");
                return;
            }
            readAvailableCallback_(events[i].data.fd);
        }
    }
}

// 使用 nc -u localhost 10086 命令发送 udp 数据
int main() {
    constexpr int UDP_MAX_PAYLOAD = 1500;
    bool exit = false;
    printf("XuShaoQiu002 start\n");
    auto *ePoll = new EPoll(16, [&](int fd){
        printf("fd readable\n");
        char buffer[UDP_MAX_PAYLOAD];
        auto ret = read(fd, buffer, UDP_MAX_PAYLOAD);
        if (ret > 0) {
            printf("receive msg: %s\n", buffer);
            if (strstr(buffer, "exit") == buffer) {
                printf("request exit\n");
                exit = true;
            }
        } else {
            exit = true;
        }
    });

    int socketFd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    struct sockaddr_in mySockaddr{};
    memset(&mySockaddr, 0, sizeof(mySockaddr));
    mySockaddr.sin_family = AF_INET;
    mySockaddr.sin_port = htons(10086);
    mySockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(socketFd, (struct sockaddr *) &mySockaddr, sizeof(mySockaddr));
    ePoll->insertFd(socketFd);

    while (!exit) {
        sleep(1);
    }

    delete ePoll;
    printf("XuShaoQiu002 finish\n");
    return 0;
}
