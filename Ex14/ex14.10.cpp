/*
 * Exercise 14.10
 *
 * There are 2 ways to do this:
 *  1. Use specialized template parameter to pass a function pointer;
 *  2. Use constructor to pass a function pointer.
 */

#include <iostream.h>


struct Callback {
    virtual void operator()() = 0;
};

// PF is a function pointer with external linkage.
template<void (*PF)()>
struct Callbackfunction: public Callback {
    virtual void operator()() { PF(); }
};


struct Callbackobject {
    typedef void (*PF)();
private:
    PF funp;
public:
    Callbackobject(PF p) : funp(p) { }
    void operator()() { funp(); }
    PF setFunction(PF p) { PF tmp = funp; funp = p; return tmp; }
};

// Test callback.
void apply1(Callback& f)
{
    f();
}

// Test callbackobject.
void apply2(Callbackobject& f)
{
    f();
}

void print()
{
    cout << "In print()\n";
}

int main()
{
    Callbackfunction<&print> f1;
    Callbackobject f2(&print);

    apply1(f1);
    apply2(f2);
}
