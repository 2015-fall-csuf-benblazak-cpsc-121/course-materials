#include <iostream>
using std::cout;
using std::endl;

void f(int i, int * p, int & r) {
    i++;
    (*p)++;
    r++;
}

int main() {
    int a = 1;
    int b = 1;
    int c = 1;

    f(a, &b, c);

    cout << a << " " << b << " " << c;

    return 0;
}
