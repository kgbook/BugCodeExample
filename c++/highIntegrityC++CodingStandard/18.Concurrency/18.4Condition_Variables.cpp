#include <mutex>
#include <condition_variable>
#include <vector>
#include <cstdint>

std::mutex mut;
std::condition_variable_any cv;
std::vector<int32_t> container;

void producerThread()
{
    int32_t i = 0;
    std::lock_guard<std::mutex> guard(mut);

    container.push_back(i);

    cv.notify_one();
}

void consumerThread()
{
    std::unique_lock<std::mutex> guard(mut);

    cv.wait(guard, []{ return !container.empty(); } );

    container.pop_back();
}