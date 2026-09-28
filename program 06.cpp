#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string vehicleId;
    string registrationNumber;
    double fuelLevel;

public:
    Vehicle(string vid, string reg)
        : vehicleId(vid),
          registrationNumber(reg),
          fuelLevel(100.0) {}

    void startEngine() const {
        cout << "Vehicle " << vehicleId
             << " engine started." << endl;
    }

    void refuel(double amount) {
        fuelLevel += amount;

        if (fuelLevel > 100.0) {
            fuelLevel = 100.0;
        }
    }

    virtual void displayInfo() const {
        cout << "Vehicle ID: " << vehicleId
             << " | Registration: " << registrationNumber
             << " | Fuel: " << fuelLevel << "%" << endl;
    }

    virtual ~Vehicle() = default;
};

class Truck : public Vehicle {
private:
    double cargoCapacity;

public:
    Truck(string vid, string reg, double capacity)
        : Vehicle(vid, reg), cargoCapacity(capacity) {}

    void displayInfo() const override {
        cout << "Truck | ";
        Vehicle::displayInfo();

        cout << "Cargo capacity: "
             << cargoCapacity << " tonnes" << endl;
    }
};

class DeliveryVan : public Vehicle {
private:
    int packageCount;

public:
    DeliveryVan(string vid, string reg, int packages)
        : Vehicle(vid, reg), packageCount(packages) {}

    void displayInfo() const override {
        cout << "Delivery Van | ";
        Vehicle::displayInfo();

        cout << "Packages loaded: "
             << packageCount << endl;
    }
};

class Bike : public Vehicle {
private:
    bool hasDeliveryBox;

public:
    Bike(string vid, string reg, bool hasBox)
        : Vehicle(vid, reg), hasDeliveryBox(hasBox) {}

    void displayInfo() const override {
        cout << "Delivery Bike | ";
        Vehicle::displayInfo();

        cout << "Delivery box: "
             << (hasDeliveryBox ? "Available" : "Not available")
             << endl;
    }
};

int main() {
    Truck truck("T001", "MH12AB1234", 10);
    DeliveryVan van("V001", "MH12CD5678", 25);
    Bike bike("B001", "MH12EF9012", true);

    cout << "=== Vehicle Fleet ===" << endl;

    truck.displayInfo();
    van.displayInfo();
    bike.displayInfo();

    truck.startEngine();
    van.startEngine();
    bike.startEngine();

    return 0;
}
