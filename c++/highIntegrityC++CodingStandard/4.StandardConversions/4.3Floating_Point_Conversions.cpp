void foo ()
{
    float f (1.0);
    f = 1.0F;

    double d (1.0L);
    d = 1.0;

    long double ld (1.0);
    ld = 1.0L;

    f = ld;
    d = ld;
    f = d;

    d = f;
    ld = f;
    ld = d;
}
