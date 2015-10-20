#include <iostream>
using std::cout;
using std::endl;

int main() {
    int a, b;

    a = 1; b = 1;
    cout << a << " " << b << " ";
    cout << ++a << " " << b++ << " ";
    cout << a << " " << b << endl;

    a = 12345;
    a %= 5;
    cout << a << endl;

    cout << ( a == 'b' || 'c' ) << endl;

    return 0;
}
