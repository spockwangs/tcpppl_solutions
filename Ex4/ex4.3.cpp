/*
 * Exercise 4.3
 *
 * Print sizes of various basic types, pointer types and some enum
 * types.
 */

#include <iostream>
using namespace std;

#define PRINT_SIZE(name, type) \
    cout << "sizeof " << name << ": " << sizeof(type) << endl

int main()
{
    PRINT_SIZE("bool", bool);
    PRINT_SIZE("char", char);
    PRINT_SIZE("unsigned char", unsigned char);
    PRINT_SIZE("signed char", signed char);
    PRINT_SIZE("short", short);
    PRINT_SIZE("unsigned short", unsigned char);
    PRINT_SIZE("signed short", signed short);
    PRINT_SIZE("int", int);
    PRINT_SIZE("signed int", signed int);
    PRINT_SIZE("unsigned int", unsigned int);
    PRINT_SIZE("long", long);
    PRINT_SIZE("unsigned long", unsigned long);
    PRINT_SIZE("signed long", signed long);
    PRINT_SIZE("float", float);
    PRINT_SIZE("double", double);
    PRINT_SIZE("long double", long double);
    PRINT_SIZE("void *", void *);
    PRINT_SIZE("bool *", bool *);
    PRINT_SIZE("int *", int *);
    PRINT_SIZE("long *", long *);
    PRINT_SIZE("double *", double *);

    enum flag { FALSE, TRUE };
    enum color { red, green, blue, white, black, cyan };
    enum data1 { A = -10, B = 1000 };
    enum data2 { C = -100, D = 100000 };
    enum data3 { E = -1, F = 1000000000 };
    PRINT_SIZE("enum flag", enum flag);
    PRINT_SIZE("enum color", enum color);
    PRINT_SIZE("enum data1", enum data1);
    PRINT_SIZE("enum data2", enum data2);
    PRINT_SIZE("enum data3", enum data3);
}
