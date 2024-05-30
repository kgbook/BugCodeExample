#include <string>
#include <cassert>

class C
{
public:
    C ();

    std::string m_id;
};

class D
{
public:
    D ();

    std::string const & getId () const
    {
        assert (! m_id.empty () && "Id not yet specified");
        return m_id;
    }

private:
    std::string m_id;
};

extern "C"
{
struct S
{
    int i;
    int j;
};
}
