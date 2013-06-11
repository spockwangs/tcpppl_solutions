/*
 * Exercise 16.15
 */

#include <iostream.h>
#include <string>
#include <vector>

using namespace std;

void duplicate_elements(vector<string>& f)
{
    int i = 0;
    vector<string>::iterator p;
    for (p = f.begin(); i < 6; ++p, ++i)
        f.insert(p, *p);
}

int main()
{
    vector<string> fruits;

    fruits.push_back("don't");
    fruits.push_back("do");
    fruits.push_back("this");

    fruits.reserve(10);
    duplicate_elements(fruits);

    for (vector<string>::iterator p = fruits.begin(); p != fruits.end(); p++)
        cout << *p << '\n';
}
