/*
 * Exercise 13.1
 */

template<class T> class List {
    struct Link {
        Link *pre;
        Link *suc;
        T val;
        Link(Link *p, Link *s, const T& v) :pre(p), suc(s), val(v) { }
    };
    Link *head;
public:
    List() : head(0) { }
    List(const T& t) : head(new Link(0, 0, t)) { }
    void print_all() const { for (Link *p = head; p; p = p->suc) cout << p->val << '\n'; }
};

class Rec { };

void f(const List<int>& li, const List<Rec>& lr)
{
    li.print_all();
    lr.print_all();
}

// The compiler may generate the following codes:

class Rec{ };

class _T_i_List {
    struct Link {
        Link *pre;
        Link *suc;
        int val;
        Link(Link *p, Link *s, const T& v) :pre(p), suc(s), val(v) { }
    };
    Link *head;
public:
    _T_i_List() : head(0) { }
    _T_i_List(const int& t) : head(new Link(0, 0, t)) { }
    inline void print_all() const;
};

class _T_Rec_List {
    struct Link {
        Link *pre;
        Link *suc;
        Rec val;
        Link(Link *p, Link *s, const Rec& v) :pre(p), suc(s), val(v) { }
    };
    Link *head;
public:
    _T_Rec_List() : head(0) { }
    _T_Rec_List(const Rec& t) : head(new Link(0, 0, t)) { }
    inline void print_all() const;
};

void f(_T_i_List& li, _T_rec_List& lr)
{
    li.print_all();     // use point of List<int>
    lr.print_all();     // use point of List<Rec>
}

inline void _T_i_List::print_all()
{
    for (Link *p = head; p; p = p->suc)
        cout << p->val << '\n';
}

inline void _T_rec_List::print_all()
{
    for (Link *p = head; p; p = p->suc)
        cout << p->val << '\n';
}

// Note: the class type Rec must provide operator<< operator.
// Instantiation point of a function must be placed before its use
// point but its defition must be after its use point.
