/*
 * Exercise 6.12
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct data {
    double sum;
    int count;
};

void do_statistics(const pair<string, data>& m)
{
    double avg;

    avg = m.second.sum / m.second.count;
    cout << m.first << ": sum = " << m.second.sum
         << ", avg = " << avg << endl;
}

int main()
{
    map<string, data> table;
    vector<double> value;   // to compute the middle value
    double sum = 0;
    int count = 0;

    while (cin) {
        string input;
        double val;

        cin >> input;
        cin >> val;

        table[input].sum += val;
        table[input].count++;

        value.push_back(val);
        sum += val;
        count++;
    }

    for_each(table.begin(), table.end(), do_statistics);
    cout << "Sum = " << sum << ", Average = " << sum/count;
    sort(value.begin(), value.end());
    cout << ", Middle = " << value[value.size()/2] << endl;
}
