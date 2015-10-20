/**
 * Notes:
 * - Since this is meant to be an example, it is somewhat over-commented.
 */

#include <iostream>
using std::cout;
using std::endl;

// ----------------------------------------------------------------------------

class Point {
    private:
        double x;
        double y;

    public:
        Point(double x = 0, double y = 0);  // default / other constructor

        Point(const Point & p);              // copy constructor
        Point & operator=(const Point & b);  // overload the `=` operator

        friend std::ostream & operator<<(std::ostream & os, const Point & p);
        // overload the `<<` operator
        // - this cannot be a member function, but it needs access to the
        //   private variables `x` and `y`; thus it must be a friend
};

// default / other constructor
Point::Point(double x, double y)
    : x(x), y(y) {}

// copy constructor
Point::Point(const Point & p)
    : x(2*p.x), y(2*p.y) {}

// overload the `=` operator
Point & Point::operator=(const Point & b) {
    x = 3*b.x;
    y = 3*b.y;

    return *this;
}

// ............................................................................

// overload the `<<` operator
std::ostream & operator<<(std::ostream & os, const Point & p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

// ----------------------------------------------------------------------------

int main() {
    Point z;       // calls the default / other constructor
    Point a(1,1);  // calls the default / other constructor

    Point b(a);   // calls the copy constructor
    Point c = a;  // calls the copy constructor

    Point d;      // calls the default / other constructor
    d = a;        // calls operator=

    cout << z << " " << a << " " << b << " " << c << " " << d << endl;

    return 0;
}

