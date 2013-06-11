/*
 * Exercise 16.3
 */

#include <iostream.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class initial {
private:
    const char c;
public:
    explicit initial(char cc) : c(cc) { }
    bool operator()(const string& x) const
    { return x[0] == c; }
};

class initial_not {
private:
    const char c;
public:
    explicit initial_not(char cc) : c(cc) { }
    bool operator()(const string& x) const;
};

bool initial_not::operator()(const string& x) const
{ 
    return (x[0] != c);
}

int main()
{
    vector<string> fruits;

    while (cin) {
        string input;
        cin >> input;
        fruits.push_back(input);
    }

    sort(fruits.begin(), fruits.end());
    vector<string>::iterator p2 = find_if(fruits.begin(), fruits.end(), initial_not('a'));
    vector<string>::iterator p1 = find_if(fruits.begin(), fruits.end(), initial('a'));
    cout << *p2 << endl;
    while (p1 != p2)
        cout << *p1++ << ' ';
    cout << endl;
}
