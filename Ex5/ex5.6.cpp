/*
 * Exercise 5.6
 */

#include <iostream>
using namespace std;

void f(char c)
{
    cout << "in f(): " << c << endl;
}

void g(char &c)
{
    cout << "in g(): " << c << endl;
}

void h(const char &c)
{
    cout << "in h(): " << c << endl;
}

int main()
{
    char c;
    unsigned char uc;
    signed char sc;

    f('a');
    f(49);
    f(3300);    // warning: overflow
    f(c);
    f(uc);
    f(sc);

    g('a');     // error: non-const reference must be initialized from a lvalue
    g(49);      // error
    g(3300);    // error
    g(c);
    g(uc);      // error: initialized from unsigned char
    g(sc);      // error: initialized from signed char

    h('a');
    h(49);
    h(3300);
    h(c);
    h(uc);
    h(sc);

}
