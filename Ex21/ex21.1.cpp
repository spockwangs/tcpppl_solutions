/*
 * Exercise 21.1
 */

#include <complex>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << argv[0] << ": wrong number of arguments\n";
        exit(1);
    }

    ifstream input(argv[1]);
    if (!input) {
        cout << argv[0] << ": error: cannot open file for reading.\n";
        exit(1);
    }
    double re, im;
    while (input >> re) {
        if (input >> im)
            cout << complex<double>(re, im) << endl;
        else
            cout << argv[0] << ": warning: odd number of values\n";
    }
    return 0;
}
