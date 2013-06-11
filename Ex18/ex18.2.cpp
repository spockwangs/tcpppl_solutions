/*
 * Exercise 18.2
 */

#include <vector>
#include <iostream.h>
#include <iterator>

using std::vector;

template<class R, class T>
class mem_fun_t {
    typedef R (T:: *PMF)();     // PMF is a type of pointer to a member function

    PMF pmf;
public:
    explicit mem_fun_t(PMF p) : pmf(p) { }
    R operator()(T* p) const { return (p->*pmf)(); }
};

template<class R, class T1, class T2>
class mem_fun1_t {
    typedef R (T1:: *PMF)(T2);

    PMF pmf;
public:
    explicit mem_fun1_t(PMF p) : pmf(p) { }
    R operator()(T1* p, T2 arg2) const { return (p->*pmf)(arg2); }
};

template<class R, class T>
class const_mem_fun_t {
    typedef R (T:: *PMF)() const;     // PMF is a type of pointer to a member function

    PMF pmf;
public:
    explicit const_mem_fun_t(PMF p) : pmf(p) { }
    R operator()(const T* p) const { return (p->*pmf)(); }
};

template<class R, class T1, class T2>
class const_mem_fun1_t {
    typedef R (T1:: *PMF)(T2) const;

    PMF pmf;
public:
    explicit const_mem_fun1_t(PMF p) : pmf(p) { }
    R operator()(const T1* p, T2 arg2) const { return (p->*pmf)(arg2); }
};

template<class R, class T>
mem_fun_t<R, T> mem_fun(R (T:: *f)())
{
    return mem_fun_t<R, T>(f);
}

template<class R, class T1, class T2>
mem_fun1_t<R, T1, T2> mem_fun1(R (T1:: *f)(T2))
{
    return mem_fun1_t<R, T1, T2>(f);
}

template<class R, class T>
const_mem_fun_t<R, T> const_mem_fun(R (T:: *f)() const)
{
    return const_mem_fun_t<R, T>(f);
}

template<class R, class T1, class T2>
const_mem_fun1_t<R, T1, T2> const_mem_fun1(R (T1:: *f)(T2) const)
{
    return const_mem_fun1_t<R, T1, T2>(f);
}

template<class R, class T>
class mem_fun_ref_t {
    typedef R (T:: *PMF)();     // PMF is a type of pointer to a member function

    PMF pmf;
public:
    explicit mem_fun_ref_t(PMF p) : pmf(p) { }
    R operator()(T& obj) const { return (obj.*pmf)(); }
};

template<class R, class T1, class T2>
class mem_fun1_ref_t {
    typedef R (T1:: *PMF)(T2);

    PMF pmf;
public:
    explicit mem_fun1_ref_t(PMF p) : pmf(p) { }
    R operator()(T1& obj, T2 arg2) const { return (obj.*pmf)(arg2); }
};

template<class R, class T>
class const_mem_fun_ref_t {
    typedef R (T:: *PMF)() const;     // PMF is a type of pointer to a member function

    PMF pmf;
public:
    explicit const_mem_fun_ref_t(PMF p) : pmf(p) { }
    R operator()(const T& obj) const { return (obj.*pmf)(); }
};

template<class R, class T1, class T2>
class const_mem_fun1_ref_t {
    typedef R (T1:: *PMF)(T2) const;

    PMF pmf;
public:
    explicit const_mem_fun1_ref_t(PMF p) : pmf(p) { }
    R operator()(const T1& obj, T2 arg2) const { return (obj.*pmf)(arg2); }
};

template<class R, class T>
mem_fun_ref_t<R, T> mem_fun_ref(R (T:: *f)())
{
    return mem_fun_ref_t<R, T>(f);
}

template<class R, class T1, class T2>
mem_fun1_ref_t<R, T1, T2> mem_fun1_ref(R (T1:: *f)(T2))
{
    return mem_fun1_ref_t<R, T1, T2>(f);
}

template<class R, class T>
const_mem_fun_ref_t<R, T> const_mem_fun_ref(R (T:: *f)() const)
{
    return const_mem_fun_ref_t<R, T>(f);
}

template<class R, class T1, class T2>
const_mem_fun1_ref_t<R, T1, T2> const_mem_fun1_ref(R (T1:: *f)(T2) const)
{
    return const_mem_fun1_ref_t<R, T1, T2>(f);
}

class INT {
private:
    int a;
public:
    INT(int i = 0) : a(i) {}
    void print(int ) const { cout << a << endl; }
    int operator+(const INT& i) const
    { return a+i.a; }
};

int main()
{
    vector<INT> v(10);
    vector<INT> v2(10);
    for (int i = 0; i < 10; i++)
        v[i] = i;

    transform(v.begin(), v.end(), v2.begin(), std::ostream_iterator<int>(cout, " "),
            const_mem_fun1_ref(&INT::operator+));
    cout << '\n';
    return 0;
}
