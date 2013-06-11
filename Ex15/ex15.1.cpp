/*
 * Exercise 15.1
 */

#include <iostream.h>
#include <stdexcept>

using namespace std;

template<class T>
T ptr_cast(void *p) throw(bad_cast)
{
    T cp = dynamic_cast<T>(p);
    if (cp)
        return cp;
    else
        throw bad_cast();
}

class A {};
class B: public A {};

int main()
{
    A a;
    B b;
    A *ap = ptr_cast<A*>(&b);
}
    
