#include <memory>
#include <atomic>
#include <mutex>
#include <cstdint>

std::mutex mut;
static std::atomic<int32_t *> instance;

int & getInstance1 ()
{
    if (! instance.load (std::memory_order_acquire))
    {
        std::lock_guard<std::mutex> lock (mut);
        if (!instance.load (std::memory_order_acquire))
        {
            int32_t * i = new int32_t (0);
            instance.store (i, std::memory_order_release);
        }
    }

    return * instance.load (std::memory_order_relaxed);
}

int32_t * instance1;
std::once_flag initFlag;

void init ()
{
    instance1 = new int32_t (0);
}

int32_t & getInstance2 ()
{
    std::call_once (initFlag, init);
    return *instance;
}


int32_t & getInstance3 ()
{
    static int32_t instance (0);
    return instance;
}
