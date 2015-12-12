#include <cstdint>

#include <iostream>
using std::cout;
using std::endl;

int main() {
    int a[] = { 1, 2, 3, };
    int * p = a;
    int & r = a[0];

    cout << ( (uintptr_t)p == (uintptr_t)&a[0] ) << " "
         << ( (uintptr_t)a == (uintptr_t)&a ) << " "  // a, &a, same value?
         << ( (uintptr_t)p == (uintptr_t)&p ) << " "  // p, &p, same value?
         << ( (uintptr_t)r == (uintptr_t)&r ) << " "  // r, &r, same value?
         << endl;

    r = 4;
    cout << a[0] << " " << p[0] << " " << *a     << " " << *p     << " "
         << a[2] << " " << p[2] << " " << *(a+2) << " " << *(p+2) << " "
         << endl;

    cout << sizeof(a) << " "  // assuming `sizeof(int)` is 4
         << sizeof(p) << " "  // on a typical 64 bit system
         << endl;

    return 0;
}
// SECTION END all

#if 0
         << "-- "
         << ( (uintptr_t)a == (uintptr_t)a )  << " "
         << ( (uintptr_t)a == (uintptr_t)&a ) << " "
         << ( (uintptr_t)a == (uintptr_t)p )  << " "
         << ( (uintptr_t)a == (uintptr_t)&p ) << " "
         << ( (uintptr_t)a == (uintptr_t)r )  << " "
         << ( (uintptr_t)a == (uintptr_t)&r ) << " "
         << "-- "
         << ( (uintptr_t)&a == (uintptr_t)a )  << " "
         << ( (uintptr_t)&a == (uintptr_t)&a ) << " "
         << ( (uintptr_t)&a == (uintptr_t)p )  << " "
         << ( (uintptr_t)&a == (uintptr_t)&p ) << " "
         << ( (uintptr_t)&a == (uintptr_t)r )  << " "
         << ( (uintptr_t)&a == (uintptr_t)&r ) << " "
         << "-- "
         << ( (uintptr_t)p == (uintptr_t)a )  << " "
         << ( (uintptr_t)p == (uintptr_t)&a ) << " "
         << ( (uintptr_t)p == (uintptr_t)p )  << " "
         << ( (uintptr_t)p == (uintptr_t)&p ) << " "
         << ( (uintptr_t)p == (uintptr_t)r )  << " "
         << ( (uintptr_t)p == (uintptr_t)&r ) << " "
         << "-- "
         << ( (uintptr_t)&p == (uintptr_t)a )  << " "
         << ( (uintptr_t)&p == (uintptr_t)&a ) << " "
         << ( (uintptr_t)&p == (uintptr_t)p )  << " "
         << ( (uintptr_t)&p == (uintptr_t)&p ) << " "
         << ( (uintptr_t)&p == (uintptr_t)r )  << " "
         << ( (uintptr_t)&p == (uintptr_t)&r ) << " "
         << "-- "
         << ( (uintptr_t)r == (uintptr_t)a )  << " "
         << ( (uintptr_t)r == (uintptr_t)&a ) << " "
         << ( (uintptr_t)r == (uintptr_t)p )  << " "
         << ( (uintptr_t)r == (uintptr_t)&p ) << " "
         << ( (uintptr_t)r == (uintptr_t)r )  << " "
         << ( (uintptr_t)r == (uintptr_t)&r ) << " "
         << "-- "
         << ( (uintptr_t)&r == (uintptr_t)a )  << " "
         << ( (uintptr_t)&r == (uintptr_t)&a ) << " "
         << ( (uintptr_t)&r == (uintptr_t)p )  << " "
         << ( (uintptr_t)&r == (uintptr_t)&p ) << " "
         << ( (uintptr_t)&r == (uintptr_t)r )  << " "
         << ( (uintptr_t)&r == (uintptr_t)&r ) << " "
         << "-- "
#endif
