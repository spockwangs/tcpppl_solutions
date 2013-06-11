/*
 * Exercise 16.1
 */

#include <iostream.h>
#include <vector>

using namespace std;

int main()
{
    vector<char> alphabet(26);

    for (int i = 0; i < 26; i++)
        alphabet[i] = i + 'a';

    cout << "In sequential order: ";
    for (vector<char>::const_iterator p = alphabet.begin();
         p != alphabet.end(); p++)
        cout << *p;
    cout << endl;

    cout << "In reverse order: ";
    for (vector<char>::const_reverse_iterator rp = alphabet.rbegin();
         rp != alphabet.rend(); rp++)
        cout << *rp;
    cout << endl;
}
