#include <iostream>

using namespace std;

// Hybrid / Virtual Inheritance

class Vehicle {

    public:

    Vehicle() {

        cout << "Vehicle Default Constructor\n";
    }

    Vehicle(int x) {

        cout << x << " Vehicle Custom Constructor\n";
    }

    ~ Vehicle() {

        cout << "Vehicle Destructor\n";
    }
    
    void print() {

        cout << "Vehicle\n";
    }
};

class Bus : virtual public Vehicle {

    public:

    Bus() : Vehicle(1) {

        cout << "Bus Default Constructor\n";
    }

    ~ Bus() {

        cout << "Bus Destructor\n";
    }
};

class Truck : virtual public Vehicle {

    public:

    Truck() : Vehicle() {

        cout << "Truck Default Constructor\n";
    }

    ~ Truck() {

        cout << "Truck Destructor\n";
    }
};

class Roadways : public Bus, public Truck {

    public:

    Roadways() : Vehicle(3) {

        cout << "Roadways Default Constructor\n";
    }

    ~ Roadways() {

        cout << "Roadways Destructor\n";
    }
};

int main() {

    Roadways r;

    r.print();

    return 0;
}
