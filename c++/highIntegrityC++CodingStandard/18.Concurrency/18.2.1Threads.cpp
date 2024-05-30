// high_integrity.h
#include <thread>
#include <cstdint>
#include <mutex>
#include <atomic>

namespace high_integrity
{
    enum ThreadExec : int32_t
    {
        DETACH,
        JOIN,
    };

    template <ThreadExec thread_exec>
    class thread
    {
    public:
        template <class F, class ...Args>
        thread (F&& f, Args&&...args)
                : m_thread(std::forward<F> (f), std::forward<Args>(args)...)
        {
        }
        thread(thread const &) = delete;
        thread(thread &&) = default;

        ~thread()
        {
            if(m_thread.joinable())
            {
                join_or_detach ();
            }
        }

        inline void join () { m_thread.join (); }

    private:
        inline void join_or_detach ();

    private:
        std::thread m_thread;
    };
    template <> void thread<ThreadExec::DETACH>::join_or_detach ()
    {
        m_thread.detach ();
    }

    template <> void thread<ThreadExec::JOIN>::join_or_detach ()
    {
        m_thread.join ();
    }
}

using high_integrity::thread;
using high_integrity::ThreadExec;

void f(int32_t);
int32_t main()
{
    int32_t i;

    std::thread t(f, i);

    thread<ThreadExec::DETACH> hi_t (f, i);
}


class A
{
public:
    int32_t get1() const
    {
        ++counter1;

        ++counter2;
    }
    int32_t get2() const
    {
        std::lock_guard<std::mutex> guard(mut);
        ++counter1;
    }
private:
    mutable std::mutex           mut;
    mutable int32_t              counter1;
    mutable std::atomic<int32_t> counter2;
};

using high_integrity::thread;
using high_integrity::ThreadExec;

void worker(A & a);
void foo(A & a)
{
    thread<ThreadExec::JOIN> thread (worker, std::ref (a));
}


#include <functional>
#include <unistd.h>

class DataWrapper1
{
public:
    DataWrapper1 ()
            : flag (false)
            , data (0)
    {
    }

    void incrementData()
    {
        while(flag)
        {
            sleep(1000);
        }
        flag = true;
        ++data;
        flag = false;
    }

    int32_t getData() const
    {
        while(flag)
        {
            sleep(1000);
        }
        flag = true;
        int32_t result (data);
        flag = false;

        return result;
    }

private:
    mutable volatile bool flag;
    int32_t data;
};

using high_integrity::thread;
using high_integrity::ThreadExec;

void worker(DataWrapper1 & data);
void foo(DataWrapper1 & data)
{
//    thread<ThreadExec::JOIN> t (worker, std::ref (data));
}


// @@+ Compliant - using locks +@@
class DataWrapper
{
public:
    DataWrapper ()
            : data (0)
    {
    }

    void incrementData()
    {
        std::lock_guard<std::mutex> guard(mut);
        ++data;
    }

    int32_t getData() const
    {
        std::lock_guard<std::mutex> guard(mut);
        return data;
    }

private:
    mutable std::mutex mut;
    int32_t data;
};

using high_integrity::thread;
using high_integrity::ThreadExec;

void worker(DataWrapper & data);
void foo(DataWrapper & data)
{
//    thread<ThreadExec::JOIN> t (worker, std::ref (data));
}