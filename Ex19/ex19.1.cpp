/*
 * Exercise 19.1
 */

#include <iostream.h>
#include <iterator>
#include <vector>
#include <list>

using std::iterator;
using std::iterator_traits;

template<class Bi>
void bi_reverse(Bi begin, Bi end)
{
    --end;  // skip the end;
    while (begin != end) {
        std::swap(*begin, *end);
        ++begin;
        if (begin == end)
            break;
        --end;
    }
}

template<class For>
void forward_reverse(For begin, int len)
{
    if (len > 1) {
        int half_len = len/2;
        For half_end = begin;
        for (int k = 0; k != half_len; ++k)
            ++half_end;
        For half_begin = half_end;
        if (len%2 != 0)
            ++half_begin;
        swap_ranges(begin, half_end, half_begin);
        forward_reverse(begin, half_len);
        forward_reverse(half_begin, half_len);
    }
}

template<class For>
int length(For begin, For end)
{
    int len = 0;
    while (begin != end) {
        ++begin;
        ++len;
    }
    return len;
}

template<class For>
inline void tagged_reverse(For begin, For end, std::forward_iterator_tag)
{
    forward_reverse(begin, length(begin, end));
}

template<class Bi>
inline void tagged_reverse(Bi begin, Bi end, std::bidirectional_iterator_tag)
{
    bi_reverse(begin, end);
}

template<class It>
inline void my_reverse(It begin, It end)
{
    tagged_reverse(begin, end, typename iterator_traits<It>::iterator_category());
}

int main()
{
    using std::vector;
    using std::list;
    using std::ostream_iterator;

    ostream_iterator<int> oo(cout, " ");

    // test bi_reverse
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    my_reverse(v.begin(), v.end());
    copy(v.begin(), v.end(), oo);
    cout << endl;

    // test forward_reverse
    list<int> l;
    copy(v.begin(), v.end(), back_inserter(l));
    reverse(l.begin(), l.end());
    copy(l.begin(), l.end(), oo);
    cout << endl;

    return 0;
}

