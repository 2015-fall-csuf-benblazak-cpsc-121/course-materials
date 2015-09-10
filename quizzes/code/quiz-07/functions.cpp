#include <iostream>
using std::cout;
using std::endl;

// SECTION BEGIN average
double average(int a, int b, int c);

double average(int a, int b, int c) {
    return (a+b+c)/3.0;
}
// SECTION END average

// SECTION BEGIN set
void set(int a, int & b);

void set(int a, int & b) {
    b = 2*a;
}
// SECTION END set

// SECTION BEGIN main
int main() {
    int a = 3, b = 2, c = 1;
    cout << average(a, b, c) << endl;
    set(a, b);
    cout << a << " " << b << " " << c;
    return 0;
}
// SECTION END main
