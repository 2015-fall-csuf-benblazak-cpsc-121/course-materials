#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    // declare and initialize the array
    int a[] = { 3, 5, 7 };

    // print the array
    for (int i = 0; i < 3; i++)
        cout << a[i] << " ";
    cout << endl;

    // set each element in the array to 5 times its index
    for (int i = 0; i < 3; i++)
        a[i] = i * 5;

    // print the array
    for (int i = 0; i < 3; i++)
        cout << a[i] << " ";
    cout << endl;

    // read data into the array from stdin
    cout << "enter 3 integers: ";
    for (int i = 0; i < 3; i++)
        cin >> a[i];

    // print the array
    for (int i = 0; i < 3; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;  // success
}

