#include <iostream>

using std::cout;
using std::endl;

// ----------------------------------------------------------------------------

template <typename T>
T multiply(T a, T b) {
    return a * b;
}

// ----------------------------------------------------------------------------

template <typename T>
class Complex {
    public:
        T r;  // real part
        T i;  // imaginary part

        Complex operator*(const Complex & c) const;
};

template <typename T>
Complex<T> Complex<T>::operator*(const Complex<T> & c) const {
    Complex<T> ans;
    ans.r = r * c.r - i * c.i;
    ans.i = r * c.i + i * c.r;
    return ans;

    // we could just say
    // ```
    // return Complex<T>{ r * c.r - i * c.i, r * c.i + i * c.r };
    // ```
    // but i didn't here since we haven't talked about doing that without
    // declaring a constructor
}

// ----------------------------------------------------------------------------

int main() {
    Complex<int> a, b;
    a.r = 1; a.i = 2;
    b.r = 3; b.i = 4;

    Complex<int> c = multiply(a,b);

    cout << c.r << " + " << c.i << "i\n";

    return 0;
}
