#include <iostream>
using std::cout;
using std::endl;

// SECTION BEGIN a
int min(int, int);

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}
// SECTION END a

// SECTION BEGIN b
int squares(int &, int &);

int squares(int & a, int & b) {
    a *= a;
    b *= b;
    return min(a,b);
}
// SECTION END b

// SECTION BEGIN main
int main() {
    int a = 2, b = -5;
    cout << min(a,b) << endl;
    cout << squares(a,b) << endl;
    cout << a << " " << b;
    return 0;
}
// SECTION END main
