#include <iostream>
using std::cout;
using std::endl;

int main() {
    // SECTION BEGIN loop
    for (int a = 1; a <= 5; a++) {
        for (int b = 5; b >= a; b--) {
            cout << b << " ";
        }
        cout << endl;
    }
    // SECTION END loop

    return 0;
}
