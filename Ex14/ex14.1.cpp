/*
 * Exercise 14.1
 *
 * Note:
 *  1. void can not be used as parameter type of a function in C++;
 *  2. The template parameter type can be void, which shows that the
 *     template parameter is absent.
 */

#include <iostream.h>

template<class R = void, class T1 = void, class T2 = void>
struct STC {
    typedef R (*PF)(T1, T2);

    STC(PF pf) { prev_pf = cur_pf; cur_pf = pf; }
    ~STC() { cur_pf = prev_pf; }
    R operator()(T1 a, T2 b) { return cur_pf(a, b); }
private:
    PF prev_pf;
    static PF cur_pf;
};

template<class R, class T1, class T2>
typename STC<R, T1, T2>::PF STC<R, T1, T2>::cur_pf = 0;

template<class R, class T>
struct STC<R, T, void> {
    typedef R (*PF)(T);

    STC(PF pf) { prev_pf = cur_pf; cur_pf = pf; }
    ~STC() { cur_pf = prev_pf; }
    R operator()(T a) { return cur_pf(a); }
private:
    PF prev_pf;
    static PF cur_pf;
};

template<class R, class T>
typename STC<R, T, void>::PF STC<R, T, void>::cur_pf = 0;

template<class R>
struct STC<R, void, void> {
    typedef R (*PF)();

    STC(PF pf) { prev_pf = cur_pf; cur_pf = pf; }
    ~STC() { cur_pf = prev_pf; }
    R operator()() { return cur_pf(); }
private:
    PF prev_pf;
    static PF cur_pf;
};

template<class R>
typename STC<R, void, void>::PF STC<R, void, void>::cur_pf = 0;

void fun1()
{
    cout << "fun1\n";
}

void fun2()
{
    cout << "fun2\n";
}

int main()
{
    STC<void> stc(fun1);

    stc();
    {
        STC<void> stc(fun2);
        stc();
    }
    stc();
}
