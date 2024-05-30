这段代码主要两个问题，线程资源不清理或清理异常：
1. 不清理线程资源
线程函数主动退出，提前终止线程循环，此时会执行 `started_ = false;`, 导致 `destory()` 过程不会执行 `join()` 或`detach()` 清理线程资源
修复建议：
```cpp
void Thread::run() {
    do {
        if (paused_) {
            std::unique_lock<std::mutex> lock(mutex_);
            cond_.wait(lock, [&] {
                return !paused_;
            });
        }

        if (!threadLoop()) {
//            started_ = false; // FIXED: 未清理线程资源
            break;
        }
    } while (!interrupted_);
}
```
2. Thread 析构函数 `Thread::~Thread()` 会 abort 异常
`std::thread` 析构前须 `join()` 或 `detach()` 清理线程资源，如果你试图结束线程而没有先调用 `join()` 或 `detach()`，那么 `std::thread` 的析构函数会直接 `abort()` 终止程序，因为这被视为对资源的不正确管理
修复建议：
```cpp
void Thread::destroy() {
    if(!started_) {
        return;
    }
    started_ = false;
    if (thread_.joinable()) {
        thread_.join();
    } else { // FIXED: std::thread abort exception
        thread_.detach();
    }
}
```