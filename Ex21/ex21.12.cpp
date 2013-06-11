/*
 * Exercise 21.12
 */

#include <fstream>

using namespace std;

struct MappedFile {
    MappedFile(ifstream& file) : file_(file) {}
    char operator[](ifstream::pos_type i) const
    {
        file_.seekg(i);
        return char(file_.get());
    }
private:
    ifstream& file_;
};

#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        cerr << argv[0] << ": wrong number of arguments.\n";
        exit(1);
    }
    ifstream pass0(argv[1]);
    if (!pass0) {
        cerr << argv[0] << ": error: cannot open file '" << argv[1]
             << "' for reading.\n";
        exit(1);
    }
    int n = 0;
    int chksum0 = 0;
    while (pass0) {
        chksum0 += char(pass0.get());
        ++n;
    }

    cerr << "Reading " << n << " characters.\n";
    cerr << chksum0 << '\n';
    int chksum1 = 0;
    ifstream pass1(argv[1]);
    if (!pass1) {
        cerr << argv[0] << ": cannot open file '" << argv[1]
             << "' for reading.\n";
        exit(1);
    }
    MappedFile accessor(pass1);
    for (size_t k = 0; k != (unsigned) n; ++k)
        chksum1 += accessor[k];
    cerr << chksum1 << '\n';
    return 0;
}
