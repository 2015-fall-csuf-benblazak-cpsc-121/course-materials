/*
 * Notes:
 *
 * - A `uintptr_t` is an optional part of C++11 (coming from C99), in the
 *   `<cstdint>` header.  It is defined as "an unsigned integer type with the
 *   property that any valid pointer to void can be converted to this type,
 *   then converted back to pointer to void, and the result will compare equal
 *   to the original pointer" [(note)](http://stackoverflow.com/a/1846648).
 *
 * References:
 *
 * - An awesome wiki on arrays, often mentioning their relationship to
 *   pointers:
 *   <http://stackoverflow.com/questions/4810664/how-do-i-use-arrays-in-c>
 *
 * - Bjarne Stroustrup on
 *     - Why is "this" not a reference?
 *       <http://www.stroustrup.com/bs_faq2.html#this>
 *     - Why does C++ have both pointers and references?
 *       <http://www.stroustrup.com/bs_faq2.html#pointers-and-references>
 *
 * - A great resource for playing with type declarations:
 *   <http://cdecl.org>
 *
 * - The C++ Super FAQ on `const int * p` vs `int * const p`:
 *   <https://isocpp.org/wiki/faq/const-correctness#const-ptr-vs-ptr-const>
 */

#include <cstdint>
#include <iomanip>
#include <typeinfo>

#include <iostream>
using std::cout;
using std::endl;

#include<string>
using std::string;

// ----------------------------------------------------------------------------

void function_1() {
    cout << "function_1 called\n";
}

int function_2(int i) {
    cout << "function_2 called\n";
    return i*2;
}

// ----------------------------------------------------------------------------

void test_address_of() {
    int i = 5;
    int ii = 7;
    string s = "hello";
    string ss = "world";

    cout << "i  = " << i << ";     ";
    cout << "the address of i  is " << &i << endl;

    cout << "ii = " << ii << ";     ";
    cout << "the address of ii is " << &ii << endl;

    cout << "s  = " << s << "; ";
    cout << "the address of s  is " << &s << endl;

    cout << "ss = " << ss << "; ";
    cout << "the address of ss is " << &ss << endl;

    cout << ".......\n";

    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(string) = " << sizeof(string) << endl;

    cout << ".......\n";

    cout << "uintptr_t(&i) - uintptr_t(&ii) = "
         << ( uintptr_t(&i) - uintptr_t(&ii) ) << endl;
//     cout << "uintptr_t(&ii) - uintptr_t(&s) = "
//          << (uintptr_t(&ii) - uintptr_t(&s)) << endl;
    cout << "uintptr_t(&s) - uintptr_t(&ss) = "
         << ( uintptr_t(&s) - uintptr_t(&ss) ) << endl;
}

void test_address_of_array() {
    int w1 = 7, w2 = 16, w3 = 7;  // widths, for setw()
    
    int a[3] = {};  // initialize all elements to 0

    cout << std::setw(w1) << ""
         << std::setw(w2) << "value"
         << std::setw(w3) << "type"
         << endl;
    cout << std::setfill('-') << std::left;
    cout << std::setw(w1) << " "
         << std::setw(w2) << " "
         << std::setw(w3) << " "
         << endl;
    cout << std::setfill(' ') << std::right;
    cout << std::setw(w1) << "a"
         << std::setw(w2) << ( a )
         << std::setw(w3) << typeid(a).name()
         << endl;
    cout << std::setw(w1) << "&a"
         << std::setw(w2) << ( &a )
         << std::setw(w3) << typeid(&a).name()
         << endl;
    cout << std::setw(w1) << "a[0]"
         << std::setw(w2) << ( a[0] )
         << std::setw(w3) << typeid(a[0]).name()
         << endl;
    cout << std::setw(w1) << "&a[0]"
         << std::setw(w2) << ( &a[0] )
         << std::setw(w3) << typeid(&a[0]).name()
         << endl;
    cout << std::setw(w1) << "a[1]"
         << std::setw(w2) << ( a[1] )
         << std::setw(w3) << typeid(a[1]).name()
         << endl;
    cout << std::setw(w1) << "&a[1]"
         << std::setw(w2) << ( &a[1] )
         << std::setw(w3) << typeid(&a[1]).name()
         << endl;
}

void test_indirection() {
    int i = 5;
    int * p = &i;

    cout << "&i = " << ( &i ) << endl;
    cout << "p  = " << ( p ) << endl;
    cout << "i  = " << ( i ) << endl;
    cout << "*p = " << ( *p ) << endl;

    cout << ".......\n";

    i = 7;

    cout << "&i = " << ( &i ) << endl;
    cout << "p  = " << ( p ) << endl;
    cout << "i  = " << ( i ) << endl;
    cout << "*p = " << ( *p ) << endl;

    cout << ".......\n";

    *p = 3;

    cout << "&i = " << ( &i ) << endl;
    cout << "p  = " << ( p ) << endl;
    cout << "i  = " << ( i ) << endl;
    cout << "*p = " << ( *p ) << endl;

    cout << ".......\n";

    int ** pp = &p;

    cout << "i    = " << ( i ) << endl;
    cout << "*p   = " << ( *p ) << endl;
    cout << "**pp = " << ( **pp ) << endl;
    cout << ". . . .\n";
    cout << "&i   = " << ( &i ) << endl;
    cout << "p    = " << ( p ) << endl;
    cout << "*pp  = " << ( *pp ) << endl;
    cout << ". . . .\n";
    cout << "&&i  = " << "[not possible]" << endl;
    cout << "&p   = " << ( &p ) << endl;
    cout << "pp   = " << ( pp ) << endl;

    // other notes:
    // - `p` can be assigned different (arbitrary) values
}

void test_indirection_array() {
    int w1 = 5, w2 = 16, w3 = 8;  // widths, for setw()
    
    int a[3] = {};  // initialize all elements to 0
    int * pi = a;
    int (*pa)[3] = &a;

    cout << std::setw(w1) << ""
         << std::setw(w2) << "value"
         << std::setw(w3) << "type"
         << endl;
    cout << std::setfill('-') << std::left;
    cout << std::setw(w1) << " "
         << std::setw(w2) << " "
         << std::setw(w3) << " "
         << endl;
    cout << std::setfill(' ') << std::right;
    cout << std::setw(w1) << "a"
         << std::setw(w2) << ( a )
         << std::setw(w3) << typeid(a).name()
         << endl;
    cout << std::setw(w1) << "&a"
         << std::setw(w2) << ( &a )
         << std::setw(w3) << typeid(&a).name()
         << endl;
    cout << std::setw(w1) << "pi"
         << std::setw(w2) << ( pi )
         << std::setw(w3) << typeid(pi).name()
         << endl;
    cout << std::setw(w1) << "&pi"
         << std::setw(w2) << ( &pi )
         << std::setw(w3) << typeid(&pi).name()
         << endl;
    cout << std::setw(w1) << "pa"
         << std::setw(w2) << ( pa )
         << std::setw(w3) << typeid(pa).name()
         << endl;
    cout << std::setw(w1) << "&pa"
         << std::setw(w2) << ( &pa )
         << std::setw(w3) << typeid(&pa).name()
         << endl;

    cout << ".......\n";

    int i = 5;
    pi = &i;
//     a = &i;  // clang++: error: array type 'int [3]' is not assignable

    cout << std::setw(w1) << ""
         << std::setw(w2) << "value"
         << std::setw(w3) << "type"
         << endl;
    cout << std::setfill('-') << std::left;
    cout << std::setw(w1) << " "
         << std::setw(w2) << " "
         << std::setw(w3) << " "
         << endl;
    cout << std::setfill(' ') << std::right;
    cout << std::setw(w1) << "i"
         << std::setw(w2) << ( i )
         << std::setw(w3) << typeid(i).name()
         << endl;
    cout << std::setw(w1) << "&i"
         << std::setw(w2) << ( &i )
         << std::setw(w3) << typeid(&i).name()
         << endl;
    cout << std::setw(w1) << "pi"
         << std::setw(w2) << ( pi )
         << std::setw(w3) << typeid(pi).name()
         << endl;
    cout << std::setw(w1) << "&pi"
         << std::setw(w2) << ( &pi )
         << std::setw(w3) << typeid(&pi).name()
         << endl;
}

void test_arithmetic() {
    int * p0 = 0;

    cout << "p0 = " << ( p0 ) << endl;
    p0++;
    cout << "p0 = " << ( p0 ) << endl;

    cout << ".......\n";
    cout << ".......\n";

    int a[] = { 1, 2, 3, };
    int * p = a;

    cout << "a[0] = " << ( a[0] ) << "     "
         << "p[0] = " << ( p[0] ) << endl;
    cout << "a[1] = " << ( a[1] ) << "     "
         << "p[1] = " << ( p[1] ) << endl;
    cout << "a[2] = " << ( a[2] ) << "     "
         << "p[2] = " << ( p[2] ) << endl;
    cout << ".......\n";
    cout << "*a     = " << ( *a ) << "    "
         << "*p     = " << ( *p ) << endl;
    cout << "*(a+0) = " << ( *(a+0) ) << "    "
         << "*(p+0) = " << ( *(p+0) ) << endl;
    cout << "*(a+1) = " << ( *(a+1) ) << "    "
         << "*(p+1) = " << ( *(p+1) ) << endl;
    cout << "*(a+2) = " << ( *(a+2) ) << "    "
         << "*(p+2) = " << ( *(p+2) ) << endl;
    cout << ".......\n";
    cout << "0[a] = " << ( 0[a] ) << "     "
         << "0[p] = " << ( 0[p] ) << endl;
    cout << "1[a] = " << ( 1[a] ) << "     "
         << "1[p] = " << ( 1[p] ) << endl;
    cout << "2[a] = " << ( 2[a] ) << "     "
         << "2[p] = " << ( 2[p] ) << endl;

    cout << ".......\n";
    cout << ".......\n";

    int aa[3][3] = { { 11, 12, 13, },
                     { 21, 22, 23, },
                     { 31, 32, 33, }, };
    int * pp = *aa;

    cout << "**aa     = " << ( **aa ) << endl;
    cout << "*aa[0]   = " << ( *aa[0] ) << endl;
    cout << "aa[0][0] = " << ( aa[0][0] ) << endl;
    cout << ". . . .\n";
    cout << "*pp      = " << ( *pp ) << endl;
    cout << "pp[0]    = " << ( pp[0] ) << endl;
    cout << ".......\n";
    cout << "aa[1][1]            = " << ( aa[1][1] ) << endl;
    cout << "*( aa[1] + 1 )      = " << ( *( aa[1] + 1 ) ) << endl;
    cout << "*( *(aa+1) + 1 )    = " << ( *( *(aa+1) + 1 ) ) << endl;
    cout << ". . . .\n";
    cout << "pp[ 3*1 + 1 ]       = " << ( pp[ 3*1 + 1 ] ) << endl;
    cout << "*( pp + (3*1) + 1 ) = " << ( *( pp + (3*1) + 1 ) ) << endl;
}

void test_function_pointers() {
    {
        void (*fp)();  // declare fp as pointer to function returning void
        fp = &function_1;

        fp();
        (*fp)();
        cout << "function_1  = " << (void *)( function_1 ) << endl;
        cout << "&function_1 = " << (void *)( &function_1 ) << endl;
        cout << "fp          = " << (void *)( fp ) << endl;
    }
    cout << ".......\n";
    {
        // declare fp as pointer to function (int) returning int
        int (*fp)(int);

        fp = &function_2;

        int ret;  // for return values
        ret = fp(5);
        cout << "return value is " << ret << endl;
        ret = (*fp)(7);
        cout << "return value is " << ret << endl;

        cout << "function_2  = " << (void *)( function_2 ) << endl;
        cout << "&function_2 = " << (void *)( &function_2 ) << endl;
        cout << "fp          = " << (void *)( fp ) << endl;
    }
    cout << ".......\n";
    {
        uintptr_t i;

        i = uintptr_t( &function_1 );
        ( (void(*)()) i )();
        ( * (void(*)()) i )();

        cout << ". . . .\n";

        int ret;  // for return values
        i = uintptr_t( &function_2 );
        ret = ( (int(*)(int)) i )(5);
        cout << "return value is " << ret << endl;
        ret = ( (int(*)(int)) i )(7);
        cout << "return value is " << ret << endl;
    }

    // other notes:
    // - we've already seen passing pointers to functions, and returning
    //   pointers from functions is very similar
    // - you can use function pointers as arguments to functions too.  a common
    //   use case for this is "callback functions"

    // challenge:
    // - how would one return an array (not a pointer!) from a function? :)
}

void test_other() {
    cout << "\n....... ";
    {
        cout << "`nullptr` and pointer comparisons\n\n";

        int * p = nullptr;
        int * pp = p+1;

        cout << "p       = " << ( p ) << endl;
        cout << "pp      = " << ( pp ) << endl;
        cout << "p < pp  = " << ( p < pp ) << endl;
        cout << "p == pp = " << ( p == pp ) << endl;
        cout << "p > pp  = " << ( p > pp ) << endl;

        // other notes:
        // - comparing pointers != comparing values
    }
    cout << "\n....... ";
    {
        cout << "references\n\n";

        int i = 5;
        int & r = i;

        cout << "the type of i is " << typeid(i).name() << endl;
        cout << "the type of r is " << typeid(r).name() << endl;

        cout << endl;

        cout << "i = " << ( i ) << "    "
             << "r = " << ( r ) << endl;

        i = 7;

        cout << "i = " << ( i ) << "    "
             << "r = " << ( r ) << endl;

        r = 3;

        cout << "i = " << ( i ) << "    "
             << "r = " << ( r ) << endl;
    }
    cout << "\n....... ";
    cout << endl;

    // questions:
    // - `const int * p` vs `int * const p`: what's the difference between a
    //   pointer to a const value, and a const pointer (to a non-const value)?
    //   (hint: see references at top of page)
}

void test_dynamic_allocation() {
    int * p;

    {
        int i = 5;
        p = &i;
        cout << "*p = " << ( *p ) << endl;
    }
    {
//         cout << "*p = " << ( *p ) << endl;
        // this will probably work, but the behavior is undefined; the `int i`
        // declared in the previous block is now out of scope and no longer
        // exists: <http://stackoverflow.com/a/11137525>
    }
    {
        p = new int;
        *p = 7;
    }
    {
        cout << "*p = " << ( *p ) << endl;
        // this will always behave as expected (as long as `new int` succeeded
        // in the block above)

        delete p;
        // releases the memory allocated by `new int` above
    }
    cout << ".......\n";
    {
        // the C way of doing things

        p = (int *) malloc( sizeof(int) * 1 );  // allocate memory

        *p = 11;
        cout << "*p = " << ( *p ) << endl;

        free(p);  // release memory
    }
    cout << ".......\n";
    {
        // C++ style dynamic array allocation

        p = new int[3];

        for (int i = 0; i < 3; i++)
            p[i] = i+1;
        for (int i = 0; i < 3; i++)
            cout << p[i] << " ";
        cout << endl;

        delete[] p;
    }
    cout << ".......\n";
    {
        // C style dynamic array allocation

        p = (int *) malloc( sizeof(int) * 3 );

        for (int i = 0; i < 3; i++)
            p[i] = i+1;
        for (int i = 0; i < 3; i++)
            cout << p[i] << " ";
        cout << endl;

        free(p);
    }
    cout << ".......\n";
    {
        // C++ style dynamic multi-dimensional array allocation

        int (*pp)[3] = new int[3][3];

        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                pp[a][b] = (a+1)*10 + (b+1);
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++)
                cout << pp[a][b] << " ";
            cout << endl;
        }

        delete[] pp;
    }
    cout << ".......\n";
    {
        // C style dynamic multi-dimensional array allocation

        int (*pp)[3] = (int(*)[3]) malloc( sizeof(int) * 3 * 3 );

        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                pp[a][b] = (a+1)*10 + (b+1);
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++)
                cout << pp[a][b] << " ";
            cout << endl;
        }

        free(pp);
    }

    // WARNING: Do not mix `new`/`delete` and `malloc`/`free`.  They are not
    // required to be compatible (and I think there's a good chance they
    // aren't).

    // WARNING: If you do not `delete` or `free` (as appropriate) your
    // dynamically allocated memory, it will remain allocated until the program
    // stops.  This is called a memory leak.  If you have a long running
    // program, it could easily become a big (and very hard to debug) problem.

    // other notes:
    // - `malloc`/`free` are said to work with the "heap"; `new`/`delete` are
    //   said to work with the "free store".  These are not necessarily the
    //   same areas in memory (though they may be).
    // - `malloc`/`free` and `new`/`delete` both allocate/deallocate memory at
    //   runtime.  If there is not enough memory available, each will fail
    //   (though in different ways).  Handling such failures is the
    //   programmer's responsibility.
    // - There are some advantages to using the C style `malloc`/`free`, but in
    //   general, unless you have a good reason, you should be using the C++
    //   style `new`/`delete`.
}

// ----------------------------------------------------------------------------

int main() {
//     test_address_of();
//     test_address_of_array();
//     test_indirection();
//     test_indirection_array();
//     test_arithmetic();
//     test_function_pointers();
//     test_other();
//     test_dynamic_allocation();

    return 0;
}

