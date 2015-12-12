// SECTION BEGIN all
/**
 * A common interface for automobile classes.
 */
class Automobile {
    private:
        float fuel;
        float speed;

    public:
        virtual ~Automobile() = default;

        virtual float getFuel() { return fuel; }
        virtual float getSpeed() { return speed; }

        virtual void setFuel(float fuel) { this->fuel = fuel; }
        virtual void setSpeed(float speed) { this->speed = speed; }

        virtual void turnLeft() = 0;
        virtual void turnRight() = 0;
        virtual void raiseHydraulics() = 0;
        virtual void spinRims() = 0;
};
// SECTION END all

int main() {
    return 0;
}
