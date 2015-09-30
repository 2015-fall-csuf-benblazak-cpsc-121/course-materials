/**
 * Short program to make 3 `Dolphin`s `squeak`.
 */

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

// ............................................................................

class Animal {
    protected:
        // This is declared as protected, rather than private, so that child
        // classes can directly access it.
        string name;

    public:
        // Since this constructor has a default value for every argument, it
        // also serves as the default constructor.
        Animal(const string & name = "Animal") : name(name) {}
};

// ............................................................................

class Dolphin : public Animal {
    public:
        Dolphin(const string & name = "Dolphin") : Animal(name) {}

        void squeak() { cout << "My name is " << name << ".  Squeak!\n"; }
};

// ............................................................................

int main() {
    Dolphin dolphins[] = {
        Dolphin("Aang"),
        Dolphin("Katara"),
        Dolphin("Sokka"),
    };

    for (int i = 0; i < 3; i++)
        dolphins[i].squeak();  // My name is Aang.  Squeak!
                               // My name is Katara.  Squeak!
                               // My name is Sokka.  Squeak!
    
    return 0;  // success
}

