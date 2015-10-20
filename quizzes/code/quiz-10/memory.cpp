#include <cstdlib>

int main() {

    // SECTION BEGIN all
    int * a = new int[5];
    delete[] a;
    // or
    int * b = (int *) malloc( sizeof(int) * 5 );
    free(b);
    // SECTION END all

    return 0;
}
