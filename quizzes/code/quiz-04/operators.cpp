#include <iostream>
using std::cout;
using std::endl;

int main() {
    int a, b, c;

    a = 2, b = 3;
    cout << a << " " << b << endl;
    cout << (5 * ++a * b++) << endl;
    cout << a << " " << b << endl;
    cout << "-----" << endl;

    a = 2, b = 3, c = 5;
    a *= 2; b /= 2; c %= 3;
    cout << a << " " << b << " " << c << endl;
    cout << "-----" << endl;

    cout << (2 == 5 % 3) << endl;
    cout << (12345 % 9) << endl;

    return 0;
}
