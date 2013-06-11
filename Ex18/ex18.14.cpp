/*
 * Exercise 18.14
 */

#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <string>\n";
        exit(1);
    }

    vector<string> perms;
    char *first = argv[1], *end = argv[1]+strlen(argv[1]);
    sort(first, end);
    cout << "The permutations of " << first << " are: \n";
    do {
        perms.push_back(first);
    } while (next_permutation(first, end));

    ostream_iterator<string, char> out(cout, " ");
    unique_copy(perms.begin(), perms.end(), out);
    cout << "\n";

    return 0;
}
