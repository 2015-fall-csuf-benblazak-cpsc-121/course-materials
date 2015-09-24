#include <iostream>
using std::cout;
using std::endl;

int main() {
    // SECTION BEGIN array
    int a[3] = { 3, 5 };
    int b[3];
    b[0] = 0;
    b[2] = 2;
    int c[] = { 7, 11, 13, 17, 19 };
    c[3] = 3;
    int d[3] = {};
    for (int i = 0; i < 3; i++)
        d[i] = i*2;
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
