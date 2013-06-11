/*
 * Exercise 19.2
 */

#include <iterator>
#include <vector>

using std::iterator;
using std::output_iterator_tag;

struct Sink : public iterator<output_iterator_tag, void, void, void, void> {
    Sink& operator*() { return *this; }
    Sink& operator++() { return *this; }
    Sink operator++(int) { return *this; }
    template<class T>
    Sink& operator=(const T&) { return *this; }
};

int main()
{
    using std::vector;

    vector<int> v(10);
    copy(v.begin(), v.end(), Sink());

    return 0;
}
