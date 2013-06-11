/*
 * Exercise 16.2
 */

#include <iostream.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> fruits;

    while (cin) {
        string input;
        cin >> input;
        fruits.push_back(input);
    }

    sort(fruits.begin(), fruits.end());
    for (vector<string>::const_iterator p = fruits.begin();
         p != fruits.end(); p++)
        cout << *p << ' ';
    cout << endl;
}
