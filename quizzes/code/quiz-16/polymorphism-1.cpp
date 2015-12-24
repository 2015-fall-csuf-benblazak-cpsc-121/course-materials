#include <iostream>

using std::cout;
using std::endl;

class Dog {
    public:
        virtual void bark() { cout << "normal bark\n"; }
                void walk() { cout << "normal walk\n"; }
};

class SmallDog : public Dog {
    public:
        void bark() { cout << "small bark\n"; }
        void walk() { cout << "small walk\n"; }
};

int main() {
    Dog dog;
    SmallDog small;

    Dog * pdog;
    SmallDog * psmall;

    pdog = &dog;
    pdog->bark();
    pdog->walk();

    pdog = &small;
    pdog->bark();
    pdog->walk();

//     psmall = &dog;
//     psmall->bark();
//     psmall->walk();

    psmall = &small;
    psmall->bark();
    psmall->walk();

    return 0;
}
