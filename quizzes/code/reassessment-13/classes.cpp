/**
 * Short program to sing a country song.
 */

#include <iostream>
using std::cout;

class CountrySong {
    private:
        bool girl;
        bool truck;
        bool dog;

    public:
        bool getGirl() const { return girl; }
        bool getTruck() const { return truck; }
        bool getDog() const { return dog; }

        void setGirl(bool girl) { this->girl = girl; }
        void setTruck(bool truck) { this->truck = truck; }
        void setDog(bool dog) { this->dog = dog; }

        CountrySong(bool girl = true, bool truck = true, bool dog = true);

        void sing() const;
};

CountrySong::CountrySong(bool girl, bool truck, bool dog)
    : girl(girl), truck(truck), dog(dog) {}

void CountrySong::sing() const {
    if (girl)  cout << "My girl, she left me\n";
    if (truck) cout << "My pickup broke down\n";
    if (dog)   cout << "My dog, he died\n";
    cout << "In this small small town\n";
}

int main() {
    CountrySong a(true, true, true);
    CountrySong b = CountrySong(false, true, false);

    CountrySong c = a;
    c.setTruck(false);

    a.sing();
    b.sing();
    c.sing();

    return 0;
}
