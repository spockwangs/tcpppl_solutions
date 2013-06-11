/*
 * Exercise 4.4
 */

#include <iostream>

using namespace std;

int main()
{
    char ca[] = "abcdefghijklmnopqrstuvwxyz0123456789";

    for (int i = 0; ca[i]; i++) {
        cout << ca[i] << ": " << (int) ca[i] << endl;
    }
}
