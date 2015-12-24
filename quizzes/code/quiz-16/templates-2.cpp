#include <iostream>

using std::cout;
using std::endl;

// ----------------------------------------------------------------------------

template <typename T>
T add(T a, T b) {
    return a + b;
}

// ----------------------------------------------------------------------------

template <typename T>
class Complex {
    public:
        T r;  // real part
        T i;  // imaginary part

        Complex operator+(const Complex & c) const;
};

template <typename T>
Complex<T> Complex<T>::operator+(const Complex<T> & c) const {
    Complex<T> ans;
    ans.r = r + c.r;
    ans.i = i + c.i;
    return ans;

    // we could just say
    // ```
    // return Complex<T>{ r + c.r, i + c.i };
    // ```
    // but i didn't here since we haven't talked about doing that without
    // declaring a constructor
}

// ----------------------------------------------------------------------------

int main() {
    Complex<int> a, b;
    a.r = 1; a.i = 2;
    b.r = 3; b.i = 4;

    Complex<int> c = add(a,b);

    cout << c.r << " + " << c.i << "i\n";

    return 0;
}
