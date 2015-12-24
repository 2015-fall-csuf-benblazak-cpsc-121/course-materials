#include <iostream>
using std::cout;
using std::endl;

void f(int i, int * p, int & r) {
    i--;
    (*p)--;
    r--;
}

int main() {
    int a = 2;
    int b = 2;
    int c = 2;

    f(a, &b, c);

    cout << a << " " << b << " " << c;

    return 0;
}
