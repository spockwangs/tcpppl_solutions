/*
 * Exercise 21.13
 */

#include <fstream>
#include <iostream>
#include <error.h>  // for error() 
#include <errno.h>

using namespace std;

struct MappedFile {
    MappedFile(fstream& file) : file_(file) {}

    MappedFile& operator[](fstream::pos_type n)
    {
        file_.seekg(n);
        file_.seekp(n);
        return *this;
    }

    MappedFile& operator=(char c)
    {
        file_.put(c);
        return *this;
    }

    operator char()
    {
        return char(file_.get());
    }
private:
    fstream& file_;
};

int main()
{
    fstream inout;
    MappedFile m(inout);
    int i;

    inout.open("test.txt", ios_base::out);
    if (!inout)
        error(1, 0, "cannot open file for writing.\n");

    for (i = 0; i < 10; i++)
        m[i] = 'A'+i;
    m[i] = '\n';
    inout.close();

    inout.open("test.txt", ios_base::in);
    if (!inout)
        error(1, 0, "cannot open file for reading.\n");

    for (i = 0; i < 10; i++)
        cout << m[i];
    cout << m[i];

    return 0;
}
