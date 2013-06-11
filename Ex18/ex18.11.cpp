/*
 * Exercise 18.11
 */

#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    istream_iterator<string, char> in(cin), in_end;
    ostream_iterator<string, char> out(cout, " ");

    unique_copy(in, in_end, out);
    return 0;
}
