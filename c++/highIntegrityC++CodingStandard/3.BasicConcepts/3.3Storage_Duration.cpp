#include <cstdint>

static int32_t foo ();
extern int32_t ga (foo ());
extern int32_t gb (ga);

namespace
{
    int32_t la (0);
    const int32_t SIZE (100);
}

class Application
{

};

Application const & theApp()
{
    static Application app;
    return app;
}