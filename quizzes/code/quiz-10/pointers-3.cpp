#include <cstdint>

#include <iostream>
using std::cout;
using std::endl;

int main() {
    int a[3] = {};
    int * p = a;  // would `int * p = &a[0];` produce the same result?
    int & r = a[0];

    cout << ( (uintptr_t)a == (uintptr_t)&a ) << " "  // a and &a, same value?
         << ( (uintptr_t)p == (uintptr_t)&p ) << " "  // p and &p, same value?
         << ( (uintptr_t)r == (uintptr_t)&r ) << " "  // r and &r, same value?
         << "--- "
         << ( a[0] == p[0] ) << " "
         << ( *a == *p ) << " "
         << "--- "
         << sizeof(a) << " "  // assuming `sizeof(int)` is 4
         << sizeof(p) << " "  // on a typical 64 bit system
         << endl;

    return 0;
}
