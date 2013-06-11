/*
 * Exercise 18.19
 */

#include <iostream>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <functional>
#include <list>
#include <string>
#include <vector>

using namespace std;

template<class T, class Less, class Cursor>
void quicksort(Less fun, Cursor left, Cursor right)
{
    Cursor probe = left;
    if (probe == right or ++probe == right)
        return;
    
    T pivot = *left;
    Cursor p = partition(left, right, bind2nd(fun, pivot));
    if (p == left)
        ++p;
    else if (p == right)
        --p;

    quicksort<T>(fun, left, p);
    quicksort<T>(fun, p, right);
}

void test_quicksort(istream& in)
{
    list<string> words;
    string word;
    while (in >> word)
        words.push_back(word);

    clock_t start = clock();
    quicksort<string>(less<string>(), words.begin(), words.end());
    cout << "Quicksort: "
         << (clock()-start)/CLOCKS_PER_SEC << endl;
}

void test_copysort(istream& in)
{
    list<string> words;
    string word;
    while (in >> word)
        words.push_back(word);

    clock_t start = clock();
    vector<string> tmp(words.size());
    copy(words.begin(), words.end(), tmp.begin());
    sort(tmp.begin(), tmp.end(), less<string>());
    copy(tmp.begin(), tmp.end(), words.begin());
    cout << "Copy+sort: "
         << (clock()-start)/CLOCKS_PER_SEC << endl;
}

int main()
{
    test_quicksort(cin);
    test_copysort(cin);

    return 0;
}
