#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

int main() {
    ifstream infile("input.txt");
    if (! infile.is_open() )
        return 1;  // error

    ofstream outfile("output.gen.txt");
    if (! outfile.is_open() )
        return 1; // error

    int n;
    infile >> n;
    while (infile.good()) {
        outfile << n*2 << " ";
        infile >> n;
    }

    return 0;  // success
}

