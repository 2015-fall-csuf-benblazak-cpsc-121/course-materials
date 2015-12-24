#include <iostream>

using std::cout;
using std::endl;

class Dog {
    public:
                void run() { cout << "normal run\n"; }
        virtual void jump() { cout << "normal jump\n"; }
};

class SmallDog : public Dog {
    public:
        void run() { cout << "small run\n"; }
        void jump() { cout << "small jump\n"; }
};

int main() {
    Dog dog;
    SmallDog small;

    Dog * pdog;
    SmallDog * psmall;

    pdog = &dog;
    pdog->run();
    pdog->jump();

    pdog = &small;
    pdog->run();
    pdog->jump();

//     psmall = &dog;
//     psmall->run();
//     psmall->jump();

    psmall = &small;
    psmall->run();
    psmall->jump();

    return 0;
}
