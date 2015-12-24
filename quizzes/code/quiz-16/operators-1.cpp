#include <iostream>
using std::cout;
using std::endl;

int main() {
    int a, b;

    a = 3; b = 3;
    cout << a << " " << b << " ";
    cout << --a << " " << b-- << " ";
    cout << a << " " << b << endl;

    for (int i = 0; i <= 9; i++)
        cout << ( i % 5 ) << " ";
    cout << endl;

    cout << ( 'x' == 'y' || 'z' ) << endl;

    return 0;
}
