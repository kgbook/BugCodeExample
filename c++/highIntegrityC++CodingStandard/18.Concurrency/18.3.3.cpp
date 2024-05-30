#include <mutex>
#include <cstdint>

class DataWrapper
{
public:
    int32_t incrementAndReturnData()
    {
        std::lock_guard<std::recursive_mutex> guard(mut);
        incrementData();
        return data;
    }

    void incrementData()
    {
        std::lock_guard<std::recursive_mutex> guard(mut);
        ++data;
    }

private:
    mutable std::recursive_mutex mut;
    int32_t data;
};

class DataWrapper1
{
public:
    int32_t incrementAndReturnData()
    {
        std::lock_guard<std::mutex> guard(mut);
        inc();
        return data;
    }

    void incrementData()
    {
        std::lock_guard<std::mutex> guard(mut);
        inc();
    }

private:
    void inc()
    {
        ++data;
    }

    mutable std::mutex mut;
    int32_t data;
};

#include <functional>

std::unique_lock<std::mutex> getGlobalLock ();

void f1(int32_t val)
{
    static std::mutex mut;
    std::unique_lock<std::mutex> lock(mut);
}

void f2()
{
    auto lock = getGlobalLock ();
}

#include <mutex>

std::mutex mut;
void f()
{
    std::lock_guard<std::mutex> lock(mut);
    mut.unlock ();
}

#include <atomic>

template<typename T>
class CountingConsumer
{
public:
    explicit CountingConsumer(T *ptr, int32_t counter)
            : m_ptr(ptr), m_counter(counter)
    { }

    void consume (int data)
    {
        m_ptr->consume (data);

        if (m_counter.fetch_sub (1, std::memory_order_release) == 1)
        {
            delete m_ptr;
        }
    }

    T * m_ptr;
    std::atomic<int32_t> m_counter;
};
