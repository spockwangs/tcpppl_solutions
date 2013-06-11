/*
 * Exercise 11.1
 */

#include <iostream.h>

struct X {
    int i;
    X(int);
    X operator+(int);
};

struct Y {
    int i;
    Y(X);
    Y operator+(X);
    operator int();
};

extern X operator*(X, Y);
extern int f(X);

X x = 1;
Y y = x;
int i = 2;

int main()
{
    i + 10;
    y + 10;     // ambiguous overload; y.operator+(X(10)) or y.operator int() + 10 ?
    y + 19 * y; // ambiguous overload; operator*(X(19), y) or 19 * y.operator int() ?
    x + y + 1;  
    x * x + i;
    f(7);       
    f(y);       // ERROR! Cannot convert y to X
    y + y;
    106 + y;
}
