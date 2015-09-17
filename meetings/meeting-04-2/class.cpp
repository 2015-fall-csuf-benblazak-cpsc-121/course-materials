#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

// ----------------------------------------------------------------------------

class Animal {
    protected:
        static int classCounter;
        const int instanceNumber;
        string name;  // if this was `private`, `Monkey` couldn't access it
    public:
        Animal(string n) : name(n), instanceNumber(classCounter+1) {
            classCounter++;

            name = n;  // initialize name again
            this->name = n;  // initialize name again

            cout << "Animal " << instanceNumber << ": constructor\n";
        }

        void speak(std::ostream & os = cout) const {
            os << "Animal " << instanceNumber << ": I am a " << name << endl;
        }

        ~Animal() {
            classCounter--;
            cout << "Animal " << instanceNumber << ": destructor\n";
        }
};
int Animal::classCounter = 0;

class Monkey : public Animal {
    public:
        Monkey() : Animal("monkey") {
            cout << "Monkey " << instanceNumber << ": constructor\n";
        }
        ~Monkey() {
            cout << "Monkey " << instanceNumber << ": destructor\n";
        }
        const string getName() const {
            return name;
        }
        void setName(const string & newName) {
            name = newName;
        }
};

class Dolphin : public Animal {
    public:
        Dolphin();
        ~Dolphin();
};

Dolphin::Dolphin() : Animal("dolphin") {
    cout << "Dolphin " << instanceNumber << ": constructor\n";
}

Dolphin::~Dolphin() {
    cout << "Dolphin " << instanceNumber << ": destructor\n";
}

std::ostream & operator<<(std::ostream & os, const Animal & a) {
    a.speak(os);
    return os;
}

// ----------------------------------------------------------------------------

int main() {
    cout << "-------\n";
    {
        string s = "hello";
        cout << "main: s = " << s << endl;
        cout << "main: s.length() = " << s.length() << endl;
    }
    cout << "-------\n";
    {
        Animal a("normal animal");
        a.speak();
    }
    cout << "-------\n";
    {
        Monkey m;
        m.speak();
        cout << "main: the monkey's name is \"" << m.getName() << "\"" << endl;
        m.setName("awesome monkey");
        cout << "main: the monkey's name is \"" << m.getName() << "\"" << endl;
    }
    cout << "-------\n";
    {
        Dolphin d = Dolphin();
        cout << d;
        cout << Dolphin();
        cout << "main: hello" << endl;
    }
    cout << "-------\n";

    return 0;  // success
}

