//

#include <mutex>

void manipulate_shared_data(std::mutex &pm) {
    pm.lock();

    // Perform work on shared data.

    pm.unlock();
}