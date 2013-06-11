/*
 * Exercise 12.1
 */

#include <iostream.h>

class Base {
public:
    virtual void iam() { cout << "Base\n"; }
};

class Cat: public Base {
public:
    void iam() { cout << "Cat\n"; }
};

class Dog: public Base {
public:
    void iam() { cout << "Dog\n"; }
};

int main()
{
    Base b;
    Cat c;
    Dog d;

    b.iam();    // "Base"
    c.iam();    // "Cat"
    d.iam();    // "Dog"

    Base *p = &c;
    p->iam();   // "Cat"
    p = &d;
    p->iam();   // "Dog"
}
