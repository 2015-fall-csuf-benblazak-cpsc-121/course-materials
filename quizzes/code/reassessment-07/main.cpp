/**
 * Short program to make 3 characters from Avatar say their name and what
 * element(s) they bend.
 */

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

// ............................................................................

class Character {
    protected:
        string name;

    public:
        Character(const string & name = "") : name(name) {}

        void sayName() { cout << "My name is " << name << endl; }
};

class AvatarCharacter : public Character {
    protected:
        string element;

    public:
        AvatarCharacter(const string & name = "", const string & element = "")
            : Character(name), element(element) {}

        void sayElement() { cout << "I bend " << element << endl; }
};

// ............................................................................

int main() {
    AvatarCharacter characters[] = {
        AvatarCharacter("Aang", "everything!"),
        AvatarCharacter("Katara", "water :)"),
        AvatarCharacter("Sokka", "nothing :("),
    };

    for (int i = 0; i < 3; i++) {
        characters[i].sayName();
        characters[i].sayElement();
    }
    
    return 0;  // success
}

