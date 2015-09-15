#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

// ----------------------------------------------------------------------------

// These two functions have the same name, but different *signatures*.  When
// the function is called, the compiler will match (at compile time) the call
// to the function with the correct signature.  Behind the scenes, the names of
// these two functions are changed so that they are different (this is called
// "name mangling").
void overload(int);
void overload(int, int);

// You can put default arguments in either the prototype (declaration) or
// definition of the function (or both), but they must be visible wherever the
// function is used.  Thus it's probably best to put them in the prototype.
void default_arguments(int a = 7);

void reference(int &);

void const_reference(const int &);

void object(string);

// Inside this function (defined below) the string is passed by reference
// (avoiding the overhead of copying) but still cannot be changed (since it is
// const).
void const_reference_object(const string &);

// Note that the same things that can be done with fundamental types in
// argument lists can be done with objects, including giving them default
// values.

// ----------------------------------------------------------------------------

int main() {
    overload(1);
    overload(1,2);

    cout << "-------\n";

    default_arguments(3);
    default_arguments();

    cout << "-------\n";

    {
        int n = 10;
        cout << "main: n = " << n << endl;
        reference(n);
        cout << "main: n = " << n << endl;

        // - will this work?
//         reference(5);
    }

    cout << "-------\n";

    {
        int n = 10;
        cout << "main: n = " << n << endl;
        const_reference(n);
        cout << "main: n = " << n << endl;

        // - will this work?
//         const_reference(5);
    }

    cout << "-------\n";

    {
        string a = "hello";
        object(a);
        const_reference_object(a);
    }

    return 0;  // success
}

// ----------------------------------------------------------------------------

void overload(int a) {
    cout << "overload: received 1 int" << endl;
}
void overload(int a, int b) {
    cout << "overload: received 2 ints" << endl;
}

// - what if the default argument is redeclared here with the same value?
// - what if the default argument is redeclared here with a different value?
// - what if the default argument is only declared here?
void default_arguments(int a) {
    cout << "default_arguments: a = " << a << endl;
}

void reference(int & a) {
    a *= 2;
    cout << "reference: setting a *= 2" << endl;
}

void const_reference(const int & a) {
    // - will this work?
//     a *= 2;

    cout << "const_reference: setting a *= 2" << endl;
}

void object(string s){
    cout << "object: " << s << endl;
}

void const_reference_object(const string & s) {
    cout << "const_reference_object: " << s << endl;
}

