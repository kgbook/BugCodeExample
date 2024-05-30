class A
{
public:
    bool operator && (A const &);
};

bool operator || (A const &, A const &);
A operator , (A const &, A const &);

class B;

B * foo (B & b)
{
    return & b;
}

class C
{
public:
    C * operator & ();
};
