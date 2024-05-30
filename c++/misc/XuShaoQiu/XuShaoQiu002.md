# bug
1. 析构函数 ~EPoll 中 eventfd_write(exitEventFd_, 0); 的目的是唤醒 epoll_wait ， 以便能结束循环，
   但 eventfd_write 写入的值要大于 0，才会唤醒 epoll_wait
2. bind 绑定 socket 到端口，没有处理返回值，如果端口已经被使用，会绑定失败
3. char buffer[UDP_MAX_PAYLOAD]; 缓冲区未初始化

# 解决方案
1. eventfd_write(exitEventFd_, 1) 即可
2. 返回值小 0 表示bind错误
3. char buffer[UDP_MAX_PAYLOAD] = {0}; 即可