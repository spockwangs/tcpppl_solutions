/*
 * Exercise 17.3
 */

#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <fstream>

using namespace std;

bool load_nospace_word(string *s);
bool load_letter_word(string *s);

int main()
{
    string word;
    set<string> list;
    bool (*loader)(string*) = load_letter_word;

    while (loader(&word))
        list.insert(word);

    copy(list.begin(), list.end(), ostream_iterator<string>(cout, "\n"));
    
    return 0;
}

bool load_nospace_word(string *s)
{
    return cin >> *s;
}

bool load_letter_word(string *s)
{
    char c;
    bool r;

    while (cin.get(c)) {
        if (isalpha(c)) {
            *s = c;
            break;
        }
    }
    while ((r = cin.get(c))) {
        if (!isalpha(c)) {
            cin.putback(c);
            break;
        }
        *s += c;
    }
    return r;
}
