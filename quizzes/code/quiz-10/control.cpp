#include <iostream>
using std::cout;
using std::endl;

int main() {
    // SECTION BEGIN all
    for (int a = 1; a <= 5; a++) {
        for (int b = a; b <= 5; b++) {
            cout << "* ";
        }
        cout << a << endl;
    }
    // SECTION END all

    return 0;
}
