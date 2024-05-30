//// @@- Non-Compliant example -@@
//void foo (bool isLarge, bool isBright)
//{
///* temporarily disable the code
//if (isLarge)
//{
//if (isBright)
//{
///* if isLarge && isBright do something special
//*/
//}
//}
//*/
//// compilation error on unmatched '*/'
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