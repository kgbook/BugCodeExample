#include <cstdint>
#include <mutex>

class A
{
public:
    void f1()
    {
        std::lock_guard<std::mutex> lock1(mut1);
        std::lock_guard<std::mutex> lock2(mut2);
        ++i;
    }

    void f2()
    {
        std::lock_guard<std::mutex> lock2(mut2);
        std::lock_guard<std::mutex> lock1(mut1);
        ++i;
    }

private:
    std::mutex mut1;
    std::mutex mut2;
    int32_t i;
};


class B
{
public:
    void f1()
    {
        std::lock_guard<std::mutex> lock1(mut1);
        std::lock_guard<std::mutex> lock2(mut2);
        ++i;
    }

    void f2()
    {
        std::lock_guard<std::mutex> lock1(mut1);
        std::lock_guard<std::mutex> lock2(mut2);
        ++i;
    }

private:
    std::mutex mut1;
    std::mutex mut2;
    int32_t i;
};