#include <iostream>
using std::cout;
using std::endl;

// SECTION BEGIN max
float max(float, float);

float max(float a, float b) {
    if (a > b)
        return a;
    else
        return b;
}
// SECTION END max

// SECTION BEGIN set
void change(int &, int &);

void change(int & a, int & b) {
    a *= 2;
    b *= 2;
}
// SECTION END set

// SECTION BEGIN main
int main() {
    int a = 2, b = 1;
    cout << max(a, b) << endl;
    change(a, b);
    cout << a << " " << b;
    return 0;
}
// SECTION END main
