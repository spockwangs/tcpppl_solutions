/*
 * Exercise 5.12
 */

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int count1(string str, const char *pair)
{
    int count;

    count = 0;
    for (int i = 0; i < (signed) str.size(); i++)
        if (pair[0] == str[i] && pair[1] == str[i+1])
            count++;

    return count;
}

int count2(const char *str, const char *pair)
{
    int count;

    count = 0;
    for (int i = 0; i < (signed) strlen(str); i++)
        if (pair[0] == str[i] && pair[1] == str[i+1])
            count++;

    return count;
}

int main()
{
    string str1 = "xabaacbaxabb";
    const char *str2 = "xabaacbaxabb";
    const char *pair = "ab";
    
    cout << pair << " occurred " << count1(str1, pair) << " times in "
         << str1 << endl;
    cout << pair << " occurred " << count2(str2, pair) << " times in "
         << str2 << endl;
}
