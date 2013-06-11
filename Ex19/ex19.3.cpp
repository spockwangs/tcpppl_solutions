/*
 * Exercise 19.3
 */

#include <iostream.h>
#include <iterator>

using std::iterator;
using std::iterator_traits;

template<class Iter>
class reverse_iterator : public iterator<
                         typename iterator_traits<Iter>::iterator_category,
                         typename iterator_traits<Iter>::value_type,
                         typename iterator_traits<Iter>::difference_type,
                         typename iterator_traits<Iter>::pointer,
                         typename iterator_traits<Iter>::reference > {
protected:
    Iter current;   // current points to element after this points to
public:
    typedef Iter iterator_type;
    typedef typename iterator_traits<Iter>::difference_type difference_type;
    typedef typename iterator_traits<Iter>::pointer pointer;
    typedef typename iterator_traits<Iter>::reference reference;

    reverse_iterator() : current() { }
    explicit reverse_iterator(Iter x) : current(x) { }
    template<class U> 
        reverse_iterator(const reverse_iterator<U>& x) : current(x.base()) { }

    Iter base() const { return current; }

    reference operator*() const { Iter tmp = current; return *--tmp; }
    pointer operator->() const { return &*--current; }
    reference operator[](difference_type n) const { return current[-n-1]; }
    
    reverse_iterator& operator++() { --current; return *this; }
    reverse_iterator operator++(int) { reverse_iterator t = current; --current; return t; }
    reverse_iterator& operator--() { ++current; return *this; }
    reverse_iterator operator--(int) { reverse_iterator t(current); ++current; return t; }

    reverse_iterator operator+(difference_type n) const 
    { reverse_iterator t(current); t.current -= n; return t; }
    reverse_iterator& operator+=(difference_type n) { current -= n; return *this; }
    reverse_iterator operator-(difference_type n) const
    { reverse_iterator t(current); t.current += n; return t; }
    reverse_iterator& operator-=(difference_type n) { current += n; return *this; }

    template<class I>
        friend difference_type operator-(reverse_iterator<I> const& x, reverse_iterator<I> const& y)
        { return y.current - x.current; }

    template<class I>
        friend bool operator!=(reverse_iterator<I> const& x, reverse_iterator<I> const& y)
        { return x.current != y.current; }
};

#include <list>
#include <vector>
#include <algorithm>

using std::list;
using std::vector;
using std::copy;
using std::ostream_iterator;

int main()
{
    vector<int> v;

    for (int i = 0; i < 10; ++i)
        v.push_back(i);

    copy(reverse_iterator<vector<int>::iterator>(v.end()), 
         reverse_iterator<vector<int>::iterator>(v.begin()), ostream_iterator<int>(cout, " "));

    return 0;
}
