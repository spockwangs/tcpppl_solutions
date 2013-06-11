/*
 * Exercise 15.2
 */

#include <iostream.h>
#include <typeinfo>

using namespace std;

#define CTOR(CC) {  \
    cout << #CC " constructor: " \
         << typeid(*this).name() << '\n';   \
    from_outside(this); \
    cout << '\n';   \
}

#define DTOR(CC) {  \
    cout << #CC " destructor: " \
         << typeid(*this).name() << '\n';   \
    from_outside(this); \
    cout << '\n';   \
}

void from_outside(struct A*);

struct A {
    A() CTOR(A)
    ~A() DTOR(A)
};

void from_outside(A *object) 
{
    cout << "Located at address: " << (void*) object
         << "\nFrom outside: " << typeid(*object).name() << endl;
}

void from_outside(struct B *object);

struct B: A {
    B() CTOR(B)
    virtual ~B() DTOR(B)
};

void from_outside(B *object)
{
    cout << "Located at address: " << (void *)object
         << "\nFrom outside: " << typeid(*object).name() << endl;
}

struct C: public B {
    C() CTOR(C)
    virtual ~C() DTOR(C)
};

struct D: public B {
    D() CTOR(D)
    virtual ~D() DTOR(D)
};

void from_outside(struct E*);

struct E: C, D {
    E() CTOR(E)
    virtual ~E() DTOR(E)
};

void from_outside(E *object)
{
    from_outside((C*)object);
    from_outside((D*)object);
}

struct F: virtual B {
    F() CTOR(F)
    virtual ~F() DTOR(F)
};

struct G: virtual B {
    virtual ~G() DTOR(G)
};

struct H: F, G {
    H() CTOR(H)
    virtual ~H() DTOR(H)
};

void from_outside(struct I*);

struct I: E, H {
    I() CTOR(I)
    virtual ~I() DTOR(I)
};

void from_outside(I *object)
{
    from_outside((C*)object);
    from_outside((D*)object);
    from_outside((H*)object);
}

int main()
{
    I complex_object;
    cout << "Total size of I-object: " << sizeof(I) << endl;
    cout << typeid(complex_object).name() << endl;
}
