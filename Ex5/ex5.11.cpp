/*
 * Exercise 5.11
 */

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    string input;
    vector<string> words;

    for (;;) {
        cin >> input;
        if (input == "quit")
            break;
        
        words.push_back(input);
    }
    cout << "\n";

    // output
    ostream_iterator<string> oo(cout, "\n");
    unique_copy(words.begin(), words.end(), oo);

    // sort and output
    cout << "\n";
    sort(words.begin(), words.end());
    unique_copy(words.begin(), words.end(), oo);

    return !cout.eof();
}

