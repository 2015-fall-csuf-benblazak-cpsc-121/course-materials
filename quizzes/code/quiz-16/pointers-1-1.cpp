#include <iostream>
using std::cout;
using std::endl;

int main() {

    // SECTION BEGIN all
    int i = 3;

    int * p = &i;
    *p = 4;

    int & r = i;
    r = 5;

    cout << i << " " << *p << " " << r;
    // SECTION END all

    return 0;
}

