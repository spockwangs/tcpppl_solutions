/*
 * Exercise 20.16
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

using std::string;
using std::reverse;

/*
 * itos --
 *   Return the string representation of the integer 'a' of base
 *   'base'.
 * @requires 
 *   2 <= base <= 16
 */
string itos(int a, int base = 10)
{
    string s;
    bool is_neg = false;
    const char str[] = "0123456789ABCDEF";

    if (a < 0)
        is_neg = true;

    while (a != 0) {
        int r = a%base;
        if (is_neg)
            r = r > 0 ? base-r : -r;
        s += str[r];
        a /= base;
    }
    if (is_neg)
        s += '-';
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    using std::cout;
    using std::endl;
    using std::numeric_limits;

    cout << itos(INT_MIN, 16) << endl;
    cout << itos(INT_MAX, 16) << endl;
}

