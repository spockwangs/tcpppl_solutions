/*
 * Exercise 8.1
 */

#include <iostream>
#include <string>
#include <vector>

namespace Dequeue {
    using std::string;

    struct entry {
        entry *pre;
        entry *next;
        string str;
    };

    entry *head = 0;
    entry *tail = 0;
    class Empty { };

    void insert_head(string) ;
    void insert_back(string);
    string delete_head();
    string delete_back();
    void sort();
    void reverse();
    void print();
    void destroy();
}

void Dequeue::insert_head(string s)
{
    entry *e = new entry;

    e->str = s;
    e->pre = 0;
    e->next = head;
    if (head) {
        head->pre = e;
        head = e;
    } else 
        head = tail = e;
}

void Dequeue::insert_back(string s)
{
    entry *e = new entry;

    e->str = s;
    e->pre = tail;
    e->next = 0;
    if (tail) {
        tail->next = e;
        tail = e;
    } else
        tail = head = e;
}

std::string Dequeue::delete_head()
{
    string *s;
    entry *e;

    if (head) {
        s = &head->str;
        e = head;
        head = head->next;
        if (head)
            head->pre = 0;
        else
            head = tail = 0;
        delete e;
        return *s;
    } else
        throw Empty();
}

std::string Dequeue::delete_back()
{
    string *s;
    entry *e;

    if (tail) {
        e = tail;
        s = &e->str;
        tail = e->pre;
        if (tail)
            tail->next = 0;
        else
            tail = head = 0;
        delete e;
        return *s;
    } else
        throw Empty();
}

/*
 * sort --
 *   Sort the queue in ascending order according to the string using
 *   bubble sort.
 */
void Dequeue::sort()
{
    entry *i, *j, *sentinel;

    if (head == 0)
        return;

    for (sentinel = tail; sentinel != head; sentinel= sentinel->pre)
        for (i = head, j = i->next; j != 0 && i!= sentinel; i = j, j = i->next)
            if (i->str > j->str) {
                string tmp = i->str;
                i->str = j->str;
                j->str = tmp;
            }
}
    
void Dequeue::reverse()
{
    entry *e1, *e2;

    e1 = head;
    while (e1) {
        e2 = e1->next;

        entry *tmp = e1->next;
        e1->next = e1->pre;
        e1->pre = tmp;

        e1 = e2;
    }

    entry *tmp = head;
    head = tail;
    tail = tmp;
}

void Dequeue::destroy()
{
    while (head)
        delete_head();
}

void Dequeue::print()
{
    for (const entry *e = head; e != 0; e = e->next)
        std::cout << e->str << '\n';
}

int main()
{
    using namespace Dequeue;
    using namespace std;
    string s1, s2, s3, s4, s5;

    s1 = "hello";
    s2 = "world";
    s3 = "dequeue";
    s4 = "head";
    s5 = "tail";

    insert_head("hello");
    insert_head(s2);
    insert_head(s3);
    insert_head(s4);
    insert_head(s5);

    print();
    cout << "---------------\n";

    sort();
    print();
}

