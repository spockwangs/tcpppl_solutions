/*
 * Exercise 12.2
 */

#include <iostream.h>
#include <assert.h>
#include <stdarg.h>

template<class T>
T max(T t1, T t2)
{
    return t1 > t2 ? t1 : t2;
}

template<class T>
T min(T t1, T t2)
{
    return t1 < t2 ? t1 : t2;
}

template<class T>
T avg(T t1, T t2)
{
    return static_cast<T>((t1+t2)/2.0);
}

class Point {
public:
    int x, y;

    Point(int xx = 0, int yy = 0) : x(xx), y(yy) { }
};

class Shape {
public:
    virtual Point east() const = 0; 
    virtual Point west() const = 0; 
    virtual Point north() const = 0; 
    virtual Point south() const = 0; 
    virtual Point north_east() const = 0;
    virtual Point north_west() const = 0;
    virtual Point south_east() const = 0;
    virtual Point south_west() const = 0;
    virtual Point center() const = 0;
};

class Dot : public Shape {
private:
    Point c;
public:
    Dot(int xx = 0, int yy = 0) : c(xx, yy) { }

    Point east() const { return c; }
    Point west() const { return c; }
    Point north() const { return c; }
    Point south() const { return c; }
    Point north_east() const { return c; }
    Point north_west() const { return c; }
    Point south_east() const { return c; }
    Point south_west() const { return c; }
    Point center() const { return c; }
};

class Line : public Shape {
private:
    Point end1, end2;
    Point e, w, n, s, ne, nw, se, sw, c;
public:
    Line(Point e1 = Point(0, 0), Point e2 = Point(0, 0)) 
        : end1(e1), end2(e2)
    {
        e.x = max(end1.x, end2.x);
        e.y = avg(end1.y, end2.y);

        w = Point(min(end1.x, end2.x), avg(end1.y, end2.y));
        n = Point(avg(end1.x, end2.x), max(end1.y, end2.y));
        s = Point(avg(end1.x, end2.x), min(end1.y, end2.y));
        ne = Point(max(end1.x, end2.x), max(end1.y, end2.y));
        nw = Point(min(end1.x, end2.x), max(end1.y, end2.y));
        sw = Point(min(end1.x, end2.x), min(end1.y, end2.y));
        se = Point(max(end1.x, end2.x), min(end1.y, end2.y));
        c = Point(avg(end1.x, end2.x), avg(end1.y, end2.y));
    }

    Point east() const { return e; }
    Point west() const { return w; }
    Point north() const { return n; }
    Point south() const { return s; }
    Point north_east() const { return ne; }
    Point north_west() const { return nw; }
    Point south_east() const { return se; }
    Point south_west() const { return sw; }
    Point center() const { return c; }
};

class Rect : public Shape {
private:
    Point e, w, n, s, ne, nw, se, sw, c;
public:
    Rect(Point lb = Point(0, 0), Point rt = Point(0, 0))
    {
        sw = lb;
        ne = rt;
        n = Point(avg(lb.x, rt.x), rt.y);
        s = Point(avg(lb.x, rt.x), lb.y);
        w = Point(lb.x, avg(lb.y, rt.y));
        e = Point(rt.x, avg(lb.y, rt.y));
        nw = Point(lb.x, rt.y);
        se = Point(rt.x, lb.y);
    }

    Point east() const { return e; }
    Point west() const { return w; }
    Point north() const { return n; }
    Point south() const { return s; }
    Point north_east() const { return ne; }
    Point north_west() const { return nw; }
    Point south_east() const { return se; }
    Point south_west() const { return sw; }
    Point center() const { return c; }
};

class Circle : public Shape {
private:
    Point e, w, n, s, ne, nw, se, sw, c;
    int r;
public:
    Circle(Point c = Point(0, 0), int rr = 0)
    {
        this->c = c;
        r = rr;
        n = Point(c.x, c.y+r);
        s = Point(c.x, c.y-r);
        w = Point(c.x-r, c.y);
        e = Point(c.x+r, c.y);
        ne = Point(e.x, n.y);
        nw = Point(w.x, n.y);
        sw = Point(w.x, s.y);
        se = Point(e.x, s.y);
    }

    Point east() const { return e; }
    Point west() const { return w; }
    Point north() const { return n; }
    Point south() const { return s; }
    Point north_east() const { return ne; }
    Point north_west() const { return nw; }
    Point south_east() const { return se; }
    Point south_west() const { return sw; }
    Point center() const { return c; }
    int radius() const { return r; }
};

class Window {
private:
    Point cur;      // current position
    int rows, cols;
public:
    Window(int n = 0, int m = 0)
    {
        rows = m;
        cols = n;
        cur = Point(0, 0);
    }

    Point current() const { return cur; }
    Window& current(Point p)
    {
        cur = p;
        return *this;
    }

    void draw(Dot d)
    {
        draw_border();

        Point c = d.center();
        int i;
        for (i = 0; i < rows-c.y; i++)
            draw_line();
        if (c.y <= rows)
            draw_points(c.x, 0);
        i++;
        for (; i < rows; i++)
            draw_line();
        draw_border();
    }

private:
    /* draw "+------------------+" */
    void draw_border()
    {
        cout << '+';
        for (int i = 0; i < cols; i++)
            cout << '-';
        cout << '+' << endl;
    }
    /* draw "|                   |" */
    void draw_line()
    {
        cout << '|';
        for (int i = 0; i < cols; i++)
            cout << ' ';
        cout << '|' << endl;
    }
    void draw_points(int x, ... /* 0 */)
    {
        va_list ap;
        va_start(ap, x);

        int pre = 0, xx = x;
        cout << '|';
        for (;;) {
            if (xx <= cols) {
                for (int i = 0; i < xx-pre-1; i++)
                    cout << ' ';
                cout << '+';
                pre = xx;
                xx = va_arg(ap, int);
                if (xx != 0)
                    continue;
            }
            for (int i = 0; i < cols-pre; i++)
                cout << ' ';
            cout << '|' << endl;
            break;
        }
        va_end(ap);
    }
};

int main()
{
    Window w(10, 10);

    for (int i = 10; i > 0; i--)
        w.draw(Dot(i, i));
}
