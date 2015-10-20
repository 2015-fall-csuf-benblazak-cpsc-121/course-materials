/**
 * Notes:
 * - Since this is meant to be an example, it is somewhat over-commented.
 */

#include <iostream>
using std::cout;
using std::endl;

class Point;    // forward declaration of the Point class
class Complex;  // forward declaration of the Complex class

// ----------------------------------------------------------------------------

class Point {
    private:
        double x;  // the x coordinate
        double y;  // the y coordinate

    public:
        Point(double x = 0, double y = 0);  // default / other constructor

        operator Complex() const;  // Point to Complex conversion operator

        friend std::ostream & operator<<(std::ostream & os, const Point & p);
        // overload the `<<` operator
        // - this cannot be a member function, but it needs access to the
        //   protected variables `x` and `y`; thus it must be a friend
};

class Complex {
    private:
        double r;  // the real part
        double i;  // the imaginary part

    public:
        Complex(double r = 0, double i = 0);  // default / other constructor

        operator Point() const;  // Complex to Point conversion operator

        friend std::ostream & operator<<(std::ostream & os, const Complex & c);
        // overload the `<<` operator
        // - this cannot be a member function, but it needs access to the
        //   protected variables `x` and `y`; thus it must be a friend
};

// ----------------------------------------------------------------------------
// Point

// default / other constructor
Point::Point(double x, double y)
    : x(x), y(y) {}

// Point to Complex conversion operator
Point::operator Complex() const {
    return Complex{x,y};
}

// ............................................................................

// overload the `<<` operator
std::ostream & operator<<(std::ostream & os, const Point & p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

// ----------------------------------------------------------------------------
// Complex

// default / other constructor
Complex::Complex(double r, double i)
    : r(r), i(i) {}

// Complex to Point conversion operator
Complex::operator Point() const {
    return Point{r,i};
}

// ............................................................................

// overload the `<<` operator
std::ostream & operator<<(std::ostream & os, const Complex & c) {
    os << c.r << "+" << c.i << "i";
    return os;
}

// ----------------------------------------------------------------------------

int main() {
    Point p{1,1};    // uniform initialization syntax, as of C++11
    Complex c{2,2};  // uniform initialization syntax, as of C++11

    cout << p << endl;  // calls the overloaded `<<` operator for Point
    cout << c << endl;  // calls the overloaded `<<` operator for Complex
    cout << endl;

    // C++ functional style type casting
    cout << Complex(p) << endl;  // calls the Point to Complex conversion
                                 //  operator
    cout << Point(c) << endl;    // calls the Complex to Point conversion
                                 //  operator
    cout << endl;

    // C style type casting
    cout << (Complex)p << endl;  // calls the Point to Complex conversion
                                 //  operator
    cout << (Point)c << endl;    // calls the Complex to Point conversion
                                 //  operator
    cout << endl;

    // new C++ style casting
    cout << static_cast<Complex>(p) << endl;  // calls the Point to Complex
                                              //  conversion operator
    cout << static_cast<Point>(c) << endl;    // calls the Complex to Point
                                              //  conversion operator
    cout << endl;

    Point temp = p;  // calls the default (compiler supplied) copy constructor
    p = c;           // implicitly calls the Complex to Point conversion
                     //  operator, and then calls the default (compiler
                     //  supplied) copy constructor
    c = temp;        // implicitly calls the Point to Complex conversion
                     //  operator, and then calls the default (compiler
                     //  supplied) copy constructor

    cout << p << endl;  // calls the overloaded `<<` operator for Point
    cout << c << endl;  // calls the overloaded `<<` operator for Complex
    cout << endl;

    return 0;
}

