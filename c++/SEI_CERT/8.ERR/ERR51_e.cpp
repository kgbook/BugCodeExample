
#include <thread>

void throwing_func() noexcept(false);

void thread_start() {
    throwing_func();
}

void f() {
    std::thread t(thread_start);
    t.join();
}

void throwing_func() noexcept(false);

void f1() {
    throwing_func();
}

int main() {
    f();
    f1();
}
