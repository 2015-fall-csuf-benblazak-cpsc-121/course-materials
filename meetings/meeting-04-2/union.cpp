/*
 * WARNING: This is for example purposes only.  There are times when unions are
 * useful (for instance, when you're working under resource constraints,
 * perhaps on a microcontroller, and you are very concerned with saving memory)
 * but in general, on a desktop machine, it'd probably be better to avoid them.
 * In any case most of this code is stuff that's probably not a good idea,
 * unless you have a good reason and a very good understanding of what's going
 * on.
 */

#include <iostream>
using std::cout;
using std::endl;

#include <cstdint>

// ----------------------------------------------------------------------------

union IntChar {
    // define a `union` type called `IntChar`

    uint32_t i;
    // if you access the union through this, the memory location will be
    // interpreted as a `uint32_t` (an unsigned 32 bit integer)

    char c;
    // if you access the union through this, the memory location will be
    // interpreted as a `char`

} ic;  // Declare an identifier, `ic`, of the `union` type described above.
       // This is optional, but the ability too do this is why we need a
       // semicolon at the end of the union definition

// ----------------------------------------------------------------------------

int main() {
    {
        // in this block, we'll use the `IntChar` we declared at the end of the
        // definition of `IntChar`

        ic.i = 'a';  // set ic (as a `uint32_t`) to the ASCII value 'a'

        cout << ic.c << endl;  // print the value in ic (as a `char`)
        cout << ic.i << endl;  // print the value in ic (as a `uint32_t`)

        ic.i += 1 << 8;
        // add 0b100000000 (`1` shifted left 8 times) to the current value

        cout << ic.c << endl;
        cout << ic.i << endl;
    }
    cout << "-------\n";
    {
        // in this block, we'll make a new variable of type `IntChar`, and use
        // that to do the same thing

        IntChar ic_2;

        ic_2.i = 'a';

        cout << ic_2.c << endl;
        cout << ic_2.i << endl;

        ic_2.i += 1 << 8;

        cout << ic_2.c << endl;
        cout << ic_2.i << endl;
    }

    return 0;
}

