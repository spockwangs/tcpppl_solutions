/*
 * Exercise 20.5
 */

#include <string>
#include <iterator>
#include <vector>
#include <iostream>

using std::string;
using std::iterator;

template<class C, class T, class A>
class string_appender : 
    public iterator<std::output_iterator_tag, void, void, void, void> {
protected:
    std::basic_string<C, T, A> s_;
public:
    typedef typename std::basic_string<C, T, A>::value_type value_type;

    explicit string_appender(const std::basic_string<C, T, A>& s) : s_(s) {}

    string_appender& operator=(const value_type& ch)
    { s_.append(ch); return *this; }
    string_appender& operator*() { return *this; }
    string_appender& operator++() { return *this; }
    string_appender operator++(int) { return *this; }
};

template<class C, class T, class A>
string_appender<C, T, A> back_inserter(const std::basic_string<C, T, A>& s)
{
    return back_insert_iterator(s);
}

int main()
{
    using std::vector;

    string s;
    vector<char> v(10);

    for (int i = 0; i < 10; i++)
        v[i] = 'a' + i;

    copy(v.begin(), v.end(), back_inserter(s));
    std::cout << s << std::endl;
}

