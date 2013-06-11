/*
 * Exercise 4.5
 */

#include <iostream>
#include <limits>

using namespace std;

#define PRINT_RANGE(name, type) \
    cout << name << ": max = " << numeric_limits<type>::max() \
         << ", min = " << numeric_limits<type>::min() << endl

int main()
{
    PRINT_RANGE("bool", bool);
    PRINT_RANGE("char", char);
    PRINT_RANGE("unsigned char", unsigned char);
    PRINT_RANGE("signed char", signed char);
    PRINT_RANGE("short", short);
    PRINT_RANGE("unsigned short", unsigned char);
    PRINT_RANGE("signed short", signed short);
    PRINT_RANGE("int", int);
    PRINT_RANGE("signed int", signed int);
    PRINT_RANGE("unsigned int", unsigned int);
    PRINT_RANGE("long", long);
    PRINT_RANGE("unsigned long", unsigned long);
    PRINT_RANGE("signed long", signed long);
    PRINT_RANGE("float", float);
    PRINT_RANGE("double", double);
    PRINT_RANGE("long double", long double);
}
