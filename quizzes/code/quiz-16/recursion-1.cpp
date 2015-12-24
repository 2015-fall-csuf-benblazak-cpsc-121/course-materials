#include <iostream>

using std::cout;
using std::endl;

// SECTION BEGIN function
int sum_from_1_to(int n) {
    if (n < 1)
        return 0;  // error

    if (n == 1)
        return n;

    return n + sum_from_1_to(n-1);
}
// SECTION END function

// SECTION BEGIN main
int main() {
    for (int i = 0; i <= 5; i++)
        cout << sum_from_1_to(i) << " ";

    return 0;
}
// SECTION END main
