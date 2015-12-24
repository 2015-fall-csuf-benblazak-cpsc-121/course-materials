#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using std::vector;

// ----------------------------------------------------------------------------

template <typename T>
std::ostream & operator<<(std::ostream & os, vector<T> v) {
    os << "( ";

    for (T e : v)
        os << e << " ";
    // for each element in the vector.  we could use a regular for loop here,
    // for most purposes, but this is a little safer, and a lot easier to
    // write, and probably a bit faster as well.

    os << ")";

    return os;
}
// we don't really need to use templates here, and this question is not about
// templates, but since vectors are templated it's good practice.

// ----------------------------------------------------------------------------

int main() {
    vector<int> v = { 1, 2, 3, };
    v.push_back(4);
    v[1] = 5;
    cout << v << endl;

    return 0;
}
