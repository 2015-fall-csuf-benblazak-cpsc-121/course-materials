#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

// ----------------------------------------------------------------------------

class Point {
    private:
        double x;
        double y;
    public:
        Point(double x, double y) { 
            this->x = x;
            this->y = y;
        }
};

// ----------------------------------------------------------------------------

int main() {
    string s = "hello";
    cout << "main: s = " << s << endl;
    cout << "main: s.length() = " << s.length() << endl;

    cout << "-------\n";

    Point p = Point(1,2);

    return 0;  // success
}

