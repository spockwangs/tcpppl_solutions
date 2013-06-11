/*
 * Exercise 20.1
 */

#include <iostream.h>
#include <string>

using std::string;

// C++ version
string dotconnect(const string& s1, const string& s2)
{
    return s1 + "." + s2;
}

string dotconnect2(const string& s1, const string& s2)
{
    string r(s1.size()+s2.size()+1, '.');
    r.replace(0, s1.size(), s1);
    r.replace(s1.size()+1, s2.size(), s2);
    return r;
}


#include <string.h>
#include <stddef.h>
#include <stdlib.h>

// C version
char *dotconnect(const char *s1, const char *s2)
{
    size_t len = strlen(s1) + strlen(s2) + 1;
    char *r = (char *) malloc(len);
    strcpy(r, s1);
    strcat(r, s2);
    return r;
}

#include <time.h>   /* for time(), difftime() */

enum { COUNT = 1000000 };

int main()
{
    const char *s1 = "abcdefghijklmnopqrstuvwxyz";
    const char *s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    clock_t start;
    
    start = clock();
    for (int i = 0; i < COUNT; i++)
        dotconnect(string(s1), string(s2));
    cout << "C++ version 1: " << (clock()-start)/double(COUNT) << endl;

    start = clock();
    for (int i = 0; i < COUNT; i++)
        dotconnect2(string(s1), string(s2));
    cout << "C++ version 2: " << (clock()-start)/double(COUNT) << endl;

    start = clock();
    for (int i = 0; i < COUNT; i++) {
        char *s = dotconnect(s1, s2);
        free(s);
    }
    cout << "C version: " << (clock()-start)/double(COUNT) << endl;

    return 0;
}
