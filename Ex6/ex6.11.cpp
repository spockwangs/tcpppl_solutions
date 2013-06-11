void f(int a, int b)
{
    if (a = 3)          // a warning
        ;   // a warning

    if ( a&077 == 0)    // not any warning
        ;   // a warning

    a := b+ 1   // ERROR!
}
