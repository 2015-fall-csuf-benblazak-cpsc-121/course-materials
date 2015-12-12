#include <iostream>
using std::cout;
using std::endl;

class Rectangle {
    private:
        float length;
        float width;

    public:
        Rectangle(const float length, const float width)
            : length(length), width(width) {}

        float area() const { return length * width; }
};

class Square : public Rectangle {
    public:
        Square(const float edge)
            : Rectangle(edge, edge) {}
};

int main() {
    Rectangle r{2,3};
    Square s{5};

    cout << "area of rectangle: " << r.area() << endl;
    cout << "area of square: " << s.area() << endl;

    return 0;  // success
}

