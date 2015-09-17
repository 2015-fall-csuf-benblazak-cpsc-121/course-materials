#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

// ----------------------------------------------------------------------------

struct Person {
    int age;
    string name;
};

// ----------------------------------------------------------------------------

void print_person(Person p) {
    cout << "I am " << p.name << " and I am " << p.age << " years old!\n";
}

// ----------------------------------------------------------------------------

int main() {
    {
        struct Person p = { 7, "Ben" };
        print_person(p);
    }
    cout << "-------\n";
    {
        Person p = { 7, "Ben" };
        print_person(p);
    }
    cout << "-------\n";
    {
        Person people[3];
        people[0].name = "Molly";
        people[1].name = "Eris";
        people[2].name = "Evelyn";
        for (int i = 0; i < 3; i++) {
            people[i].age = i*10;
        }
        for (int i = 0; i < 3; i++) {
            print_person(people[i]);
        }
    }

    return 0;
}

