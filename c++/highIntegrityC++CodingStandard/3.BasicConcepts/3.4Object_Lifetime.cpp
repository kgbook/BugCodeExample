class String
{
public:
    String (char *);
    String (const String &);
};

String & fn1 (char * myArg)
{
    String temp (myArg);
    return temp;
}

String fn2 (char * myArg)
{
    String temp (myArg);
    return temp;
}

#include <cstdint>

void foo (bool b)
{
    int32_t * p;
    if (b)
    {
        int32_t c = 0;
        p = &c;
    }
}

//#include <cstdint>
//#include "high_integrity.h"
//
//using high_integrity::thread;
//using high_integrity::ThreadExec;
//
//void bar(int32_t &);
//void foo ()
//{
//    int32_t i;
//    thread <ThreadExec::DETACH> t(bar, std::ref(i));
//}

#include <memory>
#include <cstdint>

void foo_v1 ()
{
    int32_t * p = new int32_t;
    delete p;
}

void foo_v2 ()
{
    std::unique_ptr<int32_t> p (new int32_t ());
}

#include <list>
#include <mutex>
#include <cstdint>

class ListWrapper
{
public:
    void add1(int32_t val)
    {
        mut.lock ();
        lst.push_back(val);
        mut.unlock ();
    }

    void add2(int32_t val)
    {
        std::lock_guard<std::mutex> lock(mut);
        lst.push_back(val);
    }


private:
    std::list<int32_t> lst;
    mutable std::mutex mut;
};


#include <cstdint>
#include <cassert>
#include <memory>

int32_t & f1 ()
{
    int32_t * result (new int32_t ());
    return *result;
}

std::unique_ptr<int32_t> f2 ()
{
    std::unique_ptr<int32_t> result (new int32_t ());
    return result;
}

void f3 ()
{
    std::weak_ptr<int32_t> p1;
    {
        std::shared_ptr<int32_t> p2 (std::make_shared<int32_t> (0));
        p1 = p2;
    }

    assert ( ! p1.expired () && "Ensure is still valid" );
    int32_t i = *p1.lock ();
}