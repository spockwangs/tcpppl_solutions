/*
 * Exercise 5.7
 */

#include <iostream>
using namespace std;

#define NELEM(array) (sizeof(array)/sizeof(array[0]))

int main()
{
    const char *mon[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    int days[] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    for (int i = 0; i < (signed) NELEM(mon); i++) {
        cout << mon[i] << ": " << days[i] << endl;
    }

    struct {
        const char *mon;
        int days;
    } mon_days[] = {
        { "Jan", 31 },
		{ "Feb", 28 },
		{ "Mar", 31 },
		{ "Apr", 30 },
		{ "May", 31 },
		{ "Jun", 30 },
		{ "Jul", 31 },
		{ "Aug", 31 },
		{ "Sep", 30 },
		{ "Oct", 31 },
		{ "Nov", 30 },
		{ "Dec", 31 }
    };
    cout << "\n";
    for (int i = 0; i < (signed)NELEM(mon_days); i++) {
        cout << mon_days[i].mon << ": " << mon_days[i].days << endl;
    }
}
