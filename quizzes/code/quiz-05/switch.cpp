#include <iostream>
using std::cout;
using std::endl;

int main() {
    // SECTION BEGIN test
    // (using a for loop for testing)
    for (int a = 0; a <= 7; a++) {
        switch(a) {
            case 0:
            case 1:
            case 2:
            case 3: cout << "tiny";
                    break;
            case 4:
            case 5: cout << "small";
                    break;
            default: cout << "medium";
                     break;
        }
        cout << endl;
    }
    // SECTION END test

    return 0;
}
