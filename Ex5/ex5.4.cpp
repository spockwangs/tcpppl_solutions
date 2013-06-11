/*
 * Exercise 5.4
 */

#include <iostream>
using namespace std;

/*
 * swap_p --
 *   Swap two integers using pointers.
 */
void swap_p(int *x, int *y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

/*
 * swap_r --
 *   Swap two integers using references.
 */
void swap_r(int &x, int &y)
{
    int tmp;

    tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int x, y;

    x = 1;
    y = 2;

    // test swap_p
    swap_p(&x, &y);
    if (x != 2 || y != 1)
        cout << "swap_p is wrong\n";
    else
        cout << "swap_p is good\n";

    // test swap_r
    x = 1;
    y = 2;
    swap_r(x, y);
    if (x != 2 || y != 1)
        cout << "swap_r is wrong\n";
    else
        cout << "swap_r is good\n";
}
