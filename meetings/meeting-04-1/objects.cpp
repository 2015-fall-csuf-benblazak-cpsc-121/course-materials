#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

// ----------------------------------------------------------------------------

class Animal {
    private:
        string name;
    public:
        Animal(string name) { 
            this->name = name;
        }
        void speak() {
            cout << "Animal: I am a " << name << endl;
        }
};

// ----------------------------------------------------------------------------

int main() {
    string s = "hello";
    cout << "main: s = " << s << endl;
    cout << "main: s.length() = " << s.length() << endl;

    cout << "-------\n";

    Animal a("normal animal");
    a.speak();

    return 0;  // success
}

