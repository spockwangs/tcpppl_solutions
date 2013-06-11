/*
 * Exercise 13.2
 */

#include <iostream.h>
#include <string>
#include <assert.h>

using namespace std;
/*
 * This is a link list of non-template version, which does not contain
 * any data in it.
 */
class Link {
private:
    Link *next;
public:
    Link(Link *next = 0)
    { this->next = next; }

    friend class Cursor;
    friend class LinkList;
};

// Iterator for LinkList
class Cursor {
    friend class LinkList;
private:
    Link *p;

    // Constructor
    Cursor(Link *pp) : p(pp) { }
public:
    Cursor& operator++() { p = p->next; return *this; }
    Cursor operator++(int) { Cursor old(*this); p = p->next; return old; }

    friend bool operator==(const Cursor&, const Cursor&);
    friend bool operator!=(const Cursor&, const Cursor&);

};

bool operator==(const Cursor& a, const Cursor& b)
{
    return a.p == b.p;
}

bool operator!=(const Cursor& a, const Cursor& b)
{
    return a.p != b.p;
}

class LinkList {
private:
    Link head;
public:
    class Empty { };

    LinkList() : head(&head) { }

    // Observers
    bool isEmpty() const { return head.next == &head; }
    Link& operator[](const Cursor& p)
    { return *p.p; }

    Cursor begin() const
    { 
        if (isEmpty()) throw new Empty();
        return Cursor(head.next);
    }

    Cursor end() const
    {
        return Cursor(const_cast<Link*>(&head));
    }

    // Insert link after p
    LinkList& insert(const Cursor& p, Link *link)
    {
        assert(p.p->next && link && (link->next == 0));
        link->next = p.p->next;
        p.p->next = link;
        return *this;
    }

    Link* extract(Cursor& p)
    {
        assert(p.p && p.p != &head);

        Link *pre = &head;
        while (pre->next != p.p)
            pre = pre->next;
        pre->next = p.p->next;
        p.p->next = 0;

        Link *lp = p.p;
        p.p = p.p->next;
        return lp;
    }
};


/* 
 * Following is a link list of template version which contains data of
 * type T.
 */

template<class T> class TCursor;
template<class T> class TLinkList;

template<class T> class TLink {
    friend class TCursor<T>;
    friend class TLinkList<T>;
private:
    T data;
    TLink *next;
public:
    TLink(T dat) : data(dat), next(0) { }
    TLink(TLink<T> *p) : next(p) { }

    T& value() { return data; }
};

template<class T> class TCursor;

template<class T>
bool operator==(const TCursor<T>&, const TCursor<T>&);

template<class T> class TCursor {
    friend class TLinkList<T>;
private:
    TLink<T> *p;

    TCursor(TLink<T> *pp) : p(pp) { }
public:
    TCursor operator++(int);
    TCursor& operator++();

    friend bool operator==<>(const TCursor<T>& a, const TCursor<T>& b);
    friend bool operator!=(const TCursor<T>& a, const TCursor<T>& b)
    { return a.p != b.p; }
};

template<class T>
bool operator==(const TCursor<T>& a, const TCursor<T>& b)
{ return a.p == b.p; }
template<class T>
TCursor<T> TCursor<T>::operator++(int)
{
    TCursor<T> old(p);
    p = p->next;
    return old;
}

template<class T>
TCursor<T>& TCursor<T>::operator++()
{
    p = p->next;
    return *this;
}

template<class T> class TLinkList {
private:
    TLink<T> head;
public:
    // exceptions
    class Empty { };

    // constructors
    TLinkList() : head(&head) { }
    ~TLinkList();

    // observers
    TCursor<T> begin() const;
    TCursor<T> end() const;
    const T& operator[](const TCursor<T>& p) const;
    bool isEmpty() const;

    // mutators
    T& operator[](const TCursor<T>& p);
    TLinkList<T>& insert(const TCursor<T>& p, T data);
    T remove(TCursor<T>*);
};

template<class T>
TLinkList<T>::~TLinkList()
{
    for (TCursor<T> i = begin(); i != end(); ) {
        remove(&i);
    }
    assert(isEmpty());
}

template<class T>
TCursor<T> TLinkList<T>::begin() const
{
    return TCursor<T>(head.next);
}

template<class T>
TCursor<T> TLinkList<T>::end() const
{
    return TCursor<T>(const_cast<TLink<T>*>(&head));
}


template<class T>
const T& TLinkList<T>::operator[](const TCursor<T>& p) const
{
    return p.p->data;
}

template<class T>
bool TLinkList<T>::isEmpty() const
{
    return head.next == &head;
}

template<class T>
T& TLinkList<T>::operator[](const TCursor<T>& p)
{
    return p.p->data;
}

template<class T>
TLinkList<T>& TLinkList<T>::insert(const TCursor<T>& p, T data)
{
    TLink<T> *lp = new TLink<T>(data);
    lp->next = p.p->next;
    p.p->next = lp;
    return *this;
}

template<class T>
T TLinkList<T>::remove(TCursor<T> *p)
{
    assert(p);
    if (isEmpty()) throw Empty();

    TLink<T> *pre = &head;
    while (pre->next != p->p)
        pre = pre->next;
    pre->next = p->p->next;
    p->p->next = 0;

    T data = p->p->data;
    delete p->p;
    p->p = pre->next;
    return data;
}

class X {
private:
    string s;
public:
    X(const char *p = "") : s(p) { }

    void print()
    { cout << s; }

    friend ostream& operator<<(ostream& o, const X& x)
    { o << x.s; return o; }
};

int main()
{
    TLinkList<X> list;
    TCursor<X> iterator = list.begin();
    X x1("abc"), x2("new"), x3("year");

    list.insert(iterator, x1).insert(iterator, x2).insert(iterator, x3);
    list[++iterator] = x1;
    for (iterator = list.begin(); iterator != list.end(); iterator++)
        list[iterator].print();
    iterator = list.begin();
    try {
        cout << list.remove(&iterator) << endl;
        cout << list.remove(&iterator) << endl;
        cout << list.remove(&iterator) << endl;
        cout << list.remove(&iterator) << endl;
    } catch(TLinkList<X>::Empty) {
        cout << "Error! List is empty!\n";
    }
}
