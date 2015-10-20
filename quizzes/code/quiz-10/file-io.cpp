#include <fstream>
using std::ifstream;
using std::ofstream;

int main() {
    ifstream infile("file-io-input.txt");
    if (! infile.is_open() )
        return 1;  // error

    ofstream outfile("file-io-output.gen.txt");
    if (! outfile.is_open() )
        return 1; // error

    int n;
    infile >> n;
    while (infile.good()) {
        outfile << n*n << " ";
        infile >> n;
    }

    return 0;  // success
}

