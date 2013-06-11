/*
 * Exercise 18.22
 */

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template<class C, class For, class T>
void my_remove(C& container, For first, For last, const T& val)
{
    For end = remove(first, last, val);
    container.erase(end, container.end());
}

template<class C, class For, class Pred>
void my_remove_if(C& container, For first, For last, Pred p)
{
    For end = remove(first, last, p);
    container.erase(end, container.end());
}

int main()
{
    list<int> v;

    for (int i = 0; i < 10; i++)
        v.push_back(i);

    my_remove(v, v.begin(), v.end(), 2);
    ostream_iterator<int> out(cout, " ");
    copy(v.begin(), v.end(), out);
    cout << '\n';

    return 0;
}
