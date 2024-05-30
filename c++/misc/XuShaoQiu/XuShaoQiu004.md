# bug
1. 递归锁问题：
   1.1 在消息回调函数 processClientDisconnect 中又调用了消息发布接口，导致 eventQueueMutex_ 死锁
   1.2 在消息回调函数 processStopSource 中调用了 removeEventListener 接口，导致 listenerMutex_ 死锁
2. 迭代器失效问题（解决了上面的递归锁问题之后）
   publishEventSync 中遍历 listenerList_，调用回调函数， 在消息回调函数 processStopSource 中调用了 removeEventListener 接口。
     removeEventListener 操作会导致 publishEventSync 中的迭代器失效

# 解决方案
1.1 缩小加锁范围，在 publishEventSync 之前手动解锁。最小加锁范围是个好习惯
```c++
    void eventLoop() {
        std::unique_lock<std::mutex> lock(eventQueueMutex_);
        ...
        auto event = eventQueue_.front();
        eventQueue_.pop_front();
        lock.unlock(); //
        publishEventSync(event);
    }
```

1.2 这种死锁问题属于“重入死锁”（reentrant deadlock），因为同一个线程尝试重入获取它已经持有的锁。改用递归锁即可
```c++
std::recursive_mutex listenerMutex_; //定义
std::lock_guard<std::recursive_mutex> lock(listenerMutex_); // 使用
```

2. 由于遍历与删除操作不在同一个函数内，没法使用这种方法
```c++
for (auto iter = list.begin(); iter != list.end(); ) {
    if (*iter == 2) {
        iter = list.erase(iter);
    } else {
        ++iter;
    }
}
```

一种可行的方案是使用临时的监听器列表副本来避免在通知监听器时直接修改原始列表。
```c++
void EventHub::publishEventSync(int event) {
    std::list<EventListener*> listenersCopy;
    {
        std::lock_guard<std::mutex> lock(listenerMutex_);
        listenersCopy = listenerList_; // Make a copy of the listener list
    }

    for (auto const &listener : listenersCopy) {
        if (listener) { // Check if listener is valid
            listener->onEvent(event);
        }
    }
}

```