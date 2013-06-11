/*
 * Exercise 14.2
 */

#include <iostream.h>
#include <stdexcept>
#include <string>

using namespace std;

template<class T>
class Ptr_to_T {
    T* p;
    T* array;
    int size;
public:
    Ptr_to_T(T* p, T* v, int s) throw (std::invalid_argument, std::out_of_range);
    Ptr_to_T(T* p) throw();

    Ptr_to_T<T>& operator++() throw (std::invalid_argument, std::out_of_range);
    Ptr_to_T<T> operator++(int) throw (std::invalid_argument, std::out_of_range);

    Ptr_to_T<T>& operator--() throw (std::invalid_argument, std::out_of_range);
    Ptr_to_T<T> operator--(int) throw (std::invalid_argument, std::out_of_range);

    T& operator*() throw (std::invalid_argument);
};

template<class T>
Ptr_to_T<T>::Ptr_to_T(T *p, T *v, int s) throw (std::invalid_argument, std::out_of_range)
{
    if (s < 0)
        throw std::invalid_argument(string("Ptr_to_T error"));

    if (p && v && !(p >= v && p < v+s))
        throw std::out_of_range(string("Ptr_to_T error"));

    this->p = p;
    array = v;
    size = s;
}

template<class T>
Ptr_to_T<T>::Ptr_to_T(T *p) throw()
{
    this->p = p;
    array = 0;
    size = 0;
}

template<class T>
Ptr_to_T<T>& Ptr_to_T<T>::operator++() throw(std::out_of_range, std::invalid_argument)
{
    if (p && array) {
        if (p < array+size-1) {
            ++p;
            return *this;
        } else
            throw std::out_of_range(string("Ptr_to_T error"));
    } else
        throw std::invalid_argument(string("Ptr_to_T error"));
}

template<class T>
Ptr_to_T<T> Ptr_to_T<T>::operator++(int) throw(std::out_of_range, std::invalid_argument)
{
    if (p && array) {
        if (p < array+size-1) {
            return Ptr_to_T<T>(p++, array, size);
        } else
            throw std::out_of_range(string("Ptr_to_T error"));
    } else
        throw std::invalid_argument(string("Ptr_to_T error"));
}

template<class T>
Ptr_to_T<T>& Ptr_to_T<T>::operator--() throw(std::out_of_range, std::invalid_argument)
{
    if (p && array) {
        if (p > array) {
            --p;
            return *this;
        } else
            throw std::out_of_range(string("Ptr_to_T error"));
    } else
        throw std::invalid_argument(string("Ptr_to_T error"));
}

template<class T>
Ptr_to_T<T> Ptr_to_T<T>::operator--(int) throw(std::out_of_range, std::invalid_argument)
{
    if (p && array) {
        if (p > array)
            return Ptr_to_T<T>(p--, array, size);
        else
            throw std::out_of_range(string("Ptr_to_T error"));
    } else
        throw std::invalid_argument(string("Ptr_to_T error"));
}

template<class T>
T& Ptr_to_T<T>::operator*() throw(std::invalid_argument)
{
    if (p)
        return *p;
    else
        throw std::invalid_argument(string("Ptr_to_T error"));
}

int main()
{
    int a = 2;
    Ptr_to_T<int> ptr(&a);

    cout << "a = " << *ptr << endl;
    ptr++;
}
