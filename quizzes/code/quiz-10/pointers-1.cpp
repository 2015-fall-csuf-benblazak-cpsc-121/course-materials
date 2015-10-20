#include <iostream>
using std::cout;
using std::endl;

int main() {

    // SECTION BEGIN all
    float f = 3.14;

    float * p = &f;
    *p += 2;

    float & r = f;
    r = 7.25;

    cout << f << " " << *p << " " << r
         << endl;
    // SECTION END all

    return 0;
}

