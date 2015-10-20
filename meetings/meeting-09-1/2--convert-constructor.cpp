/**
 * Notes:
 *
 * - Since this is meant to be an example, it is somewhat over-commented.
 *
 * - If you'd like to see exactly when different functions (like the convert
 *   constructors) are called, try putting `cout` statements in them.  This
 *   technique is often very useful for debugging (though actual debuggers,
 *   such as those found in Visual Studio, Xcode, and other IDEs, are much more
 *   powerful).
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

        Point(const Complex & c);  // convert constructor

        friend class Complex;
        // to allow the Complex convert constructor access to the private data
        // members of this class
        // - we could restrict the access of this class's private data members
        //   to only the Complex convert constructor by saying
        //   ```
        //   friend Complex::Complex(const Point & p);
        //   ```
        //   but this would have to come after the full definition of the
        //   Complex class, so doing this in both Point and Complex would not
        //   be possible.  there are other ways of accomplishing the same thing
        //   that would probably be better in this case, but we'll do it this
        //   way for now to illustrate friend classes and copy constructors.

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

        Complex(const Point & p);  // convert constructor

        friend class Point;
        // to allow the Point convert constructor access to the private data
        // members of this class
        // - we could restrict the access of this class's private data members
        //   to only the Point convert constructor by saying
        //   ```
        //   friend Point::Point(const Complex & c);
        //   ```
        //   but this would have to come after the full definition of the
        //   Point class, so doing this in both Point and Complex would not
        //   be possible.  there are other ways of accomplishing the same thing
        //   that would probably be better in this case, but we'll do it this
        //   way for now to illustrate friend classes and copy constructors.

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

// convert constructor
// - must be defined after both classes, even though the classes are forward
//   declared
Point::Point(const Complex & c) {
    x = c.r;
    y = c.i;
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

// convert constructor
// - must be defined after both classes, even though the classes are forward
//   declared
Complex::Complex(const Point & p) {
    r = p.x;
    i = p.y;
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
    cout << Complex(p) << endl;  // calls the Complex convert constructor
    cout << Point(c) << endl;    // calls the Point convert constructor
    cout << endl;

    // C style type casting
    cout << (Complex)p << endl;  // calls the Complex convert constructor
    cout << (Point)c << endl;    // calls the Point convert constructor
    cout << endl;

    // new C++ style casting
    cout << static_cast<Complex>(p) << endl;  // calls the Complex convert
                                              //  constructor
    cout << static_cast<Point>(c) << endl;    // calls the Point convert
                                              //  constructor
    cout << endl;

    Point temp = p;  // calls the default (compiler supplied) copy constructor
    p = c;           // implicitly calls the Point convert constructor, and
                     //  then calls the default (compiler supplied) copy
                     //  constructor
    c = temp;        // implicitly calls the Complex convert constructor, and
                     //  then calls the default (compiler supplied) copy
                     //  constructor

    cout << p << endl;  // calls the overloaded `<<` operator for Point
    cout << c << endl;  // calls the overloaded `<<` operator for Complex
    cout << endl;

    return 0;
}

