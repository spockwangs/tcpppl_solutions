/*
 * Exercise 17.6
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

template<class T>
class Stack {
private:
    vector<T> v;
public:
    typedef typename vector<T>::size_type size_type;

    Stack() : v() {}
    Stack(const Stack& s) : v(s.v) { }

    bool empty() const { return v.empty(); }
    size_type size() const { return v.size(); }
    const T& top() const { return v.back(); }
    
    void pop() { v.pop_back(); }
    void push(const T& t) { v.push_back(t); }
};

    
template<class T, class A = allocator<T> >
class Queue {
private:
    mutable Stack<T> in, out;
public:
    typedef typename A::value_type value_type;
    typedef typename A::size_type size_type;

    class underflow { };

    Queue() : in(), out() { }
    Queue(const Queue& q) : in(q.in), out(q.out) {}

    bool empty() const { return in.empty() and out.empty(); }
    size_type size() const { return in.size()+out.size(); }
    
    inline T front() const throw(underflow);
    inline T back() const throw(underflow);

    void push(const T& x) { in.push(x); }
    void pop() throw(underflow) 
    { 
        if (empty()) throw underflow();
        in_to_out(); 
        out.pop(); 
    }
private:
    void out_to_in() const;
    void in_to_out() const;
};

template<class T, class A>
inline T Queue<T, A>::front() const throw(underflow)
{ 
    if (empty())
        throw underflow();
    in_to_out(); 
    return out.top(); 
}

template<class T, class A>
inline T Queue<T, A>::back() const throw(underflow)
{ 
    if (empty())
        throw underflow();
    out_to_in(); 
    return in.top();
}

template<class T, class A>
void Queue<T, A>::out_to_in() const
{
    if (in.empty()) {
        while (!out.empty()) {
            in.push(out.top);
            out.pop();
        }
    }
}

template<class T, class A>
void Queue<T, A>::in_to_out() const
{
    if (out.empty())
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
}

int main()
{
    Queue<string> q;

    cout << "Input your favorite food: \n";
    string s;
    while (cin >> s)
        q.push(s);

    cout << "\n--- Your favorite food ---\n";
    try {
        while (true) {
            cout << q.front() << ' ';
            q.pop();
        }
    } catch(Queue<string>::underflow) {
        cout << "\nOops! The queue is empty!\n";
    }
}
