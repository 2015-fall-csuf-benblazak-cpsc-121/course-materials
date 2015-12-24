class Automobile {
    private:
        double fuel;
        double speed;

    public:
        virtual ~Automobile() = default;

        virtual double getFuel() { return fuel; }
        virtual double getSpeed() { return speed; }

        virtual void setFuel(double fuel) { this->fuel = fuel; }
        virtual void setSpeed(double speed) { this->speed = speed; }

        virtual void turnLeft() = 0;
        virtual void turnRight() = 0;
        virtual void raiseHydraulics() = 0;
        virtual void spinRims() = 0;
};
// SECTION END all

int main() {
    return 0;
}
