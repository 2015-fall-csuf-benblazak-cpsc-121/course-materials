#include <iostream>
using std::cout;
using std::endl;

int main() {
    // SECTION BEGIN test
    // (using a for loop for testing)
    for (int a = 0; a <= 7; a++) {
        if (a <= 3)
            cout << "tiny";
        else if (a <= 5)
            cout << "small";
        else
            cout << "medium";

        cout << endl;
    }
    // SECTION END test

    return 0;
}
