/*
 * Exercise 6.8
 */

#include <iostream>

using namespace std;

int main()
{
    double f = 1.0;
    int a = 1;

    f = f / 0.0;    // OK. f == inf
    a = a / 0;      // ERROR! Float point exception.
}
