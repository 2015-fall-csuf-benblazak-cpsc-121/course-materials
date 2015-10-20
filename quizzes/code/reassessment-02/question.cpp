#include <iostream>
using std::cout;
using std::endl;

int main() {
    // SECTION BEGIN array
    int a[4] = { 1, 1 };
    int b[5];
    b[1] = 1;
    b[3] = 3;
    int c[] = { 3, 3, 3 };
    int d[3] = {};
    for (int i = 0; i < 3; i++)
        d[i] = (3-i)*2;
    // SECTION END array

    for (int i = 0; i < sizeof(a)/sizeof(int); i++)
        cout << a[i] << " ";
    cout << endl;

    for (int i = 0; i < sizeof(b)/sizeof(int); i++)
        cout << b[i] << " ";
    cout << endl;

    for (int i = 0; i < sizeof(c)/sizeof(int); i++)
        cout << c[i] << " ";
    cout << endl;

    for (int i = 0; i < sizeof(d)/sizeof(int); i++)
        cout << d[i] << " ";
    cout << endl;

    return 0;
}
