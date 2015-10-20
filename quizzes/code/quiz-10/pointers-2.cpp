#include <iostream>
using std::cout;
using std::endl;

void f(int i, int * p, int & r) {
    i *= i;
    *p *= *p;
    r *= r;
}

int main() {
    int a = 3;
    int b = 5;
    int c = 7;

    f(a, &b, c);

    cout << a << " " << b << " " << c
         << endl;

    return 0;
}
