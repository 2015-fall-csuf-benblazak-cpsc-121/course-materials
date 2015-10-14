#include <iostream>
using std::cout;
using std::endl;

int main() {
    {
        int i = 3;

        int * p = &i;
        // here, we
        // - declare p to be a pointer to int
        // - set p equal to the address of i
        //
        // in this case, the `*` means "pointer to", and the `&` means "address
        // of"

        *p = 5;
        // here, we dereference p, which gives us a variable of type int, and
        // then set that variable equal to 5; so in this case the `*` means
        // "dereference"

        int & r = i;
        // here, we declare r to be a reference to int, and initialize it to
        // refer to the same memory location as i
        //
        // in this case, the `&` means "reference to"
        //
        // interestingly, this definition *cannot* be split into two lines:
        // reference variables must be initialized when they are created

        r = 7;
        // no `&` is necessary here

        cout << i << " " << *p << " " << r << endl;  // output: 7 7 7
    }
    {
        // just for fun, here's an example with a little more symmetry

        int i = 3;

        int * p1 = &i;   // * = pointer to,   & = address of
        int & r1 = *p1;  // & = reference to, * = dereference

        int & r2 = i;    // & = reference to
        int * p2 = &r2;  // * = pointer to,   & = address of

        r1 = 4;  // no `&` necessary
        r2 = 5;  // no `&` necessary

        *p1 = 6;  // * = dereference
        *p2 = 7;  // * = dereference

        cout << i << " "
             << *p1 << " " << r1 << " "
             << r2 << " " << *p2 << endl;
        // output: 7 7 7 7 7
    }

    return 0;
}

/**
 * Notes:
 *
 * - In the expression `int * p = &i;`, `*` is part of the type; it is not an
 *   operator.
 *
 * - In the expression `*p = 5;`, `*` is an operator.  This operator happens to
 *   modify the type of its operand (taking `p`, which is of type `int *`, and
 *   returning a variable of type `int`) but this statement does not contain
 *   any type cast, and `*` is not in this case describing any type.
 *
 * - Similarly, in the expression `int & p = i;`, `&` is part of the type; it
 *   is not an operator.
 *
 * - In the expression `int * p = &i;`, `&` is an operator.  This operator
 *   happens to modify the type of its operand (taking `i`, which is of type
 *   `int`, and returning a value of type `int *`) but this statement does not
 *   contain any type cast, and `&` is not in this case describing any type.
 *
 * - As operators, `*` and `&` are opposites.
 *
 * - As a part of a type declaration, `*` and `&` mean fairly different things,
 *   and it doesn't quite feel right to me to call them opposites.
 *
 * - Finally, for completeness, note that `*` is also the multiplication
 *   operator (as in the statement `int i = 4 * 5;`), and that `&` is also the
 *   "bitwise and" operator (as in the statement `int i = 4 & 5;`) (which you
 *   can read about on your own if you like, preferably after the midterm; we
 *   probably won't need it in this class).
 */

