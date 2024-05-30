#include <mutex>
#include <string>
#include <cstdint>

class some_data
{
public:
    void do_something();

private:
    int32_t a;
    std::string b;
};

some_data* unprotected;

void malicious_function(some_data& protected_data)
{
    unprotected=&protected_data;
}

class data_wrapper
{
public:
    template<typename Function>
    void process_data(Function func)
    {
        std::lock_guard<std::mutex> lk(m);
        func(data);
    }

private:
    some_data data;
    mutable std::mutex m;
};

data_wrapper x;

void foo()
{
    x.process_data(malicious_function);

    unprotected->do_something();
}
