#include <pthread.h>
void* thread1(void*);
void f1()
{
    pthread_t t1;
    pthread_create(&t1, nullptr, thread1, 0);
}

#include <thread>
void thread2();
void f2()
{
    std::thread t1(thread2);
}