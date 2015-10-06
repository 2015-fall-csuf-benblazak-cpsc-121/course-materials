// ----------------------------------------------------------------------------
// in-class demo
// ----------------------------------------------------------------------------

#include <iostream>

// ----------------------------------------------------------------------------

enum DogState {
    DEAD,
    ALIVE,
};

// ----------------------------------------------------------------------------

class House {
    private:
        DogState dog;

    public:
        House();
        void ringDoorbell();
};

House::House() : dog(ALIVE) {}

void House::ringDoorbell() {
    if (dog == ALIVE)
        std::cout << "bark!\n";
}

// ............................................................................

class DogHouse : public House {
    public:
        void throwBone();
};

void DogHouse::throwBone() {
    std::cout << "barkbark!!\n";
}

// ----------------------------------------------------------------------------

int main() {
    House h;
    h.ringDoorbell();

    DogHouse dh;
    dh.ringDoorbell();
    dh.throwBone();

    return 0;
}

