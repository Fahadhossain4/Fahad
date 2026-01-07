#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string name;
    string model;
    double fuelCapacity;

public:
    Vehicle(string nm, string mdl, double fuel)
    {
        name = nm;
        model = mdl;
        fuelCapacity = fuel;
    }

    virtual void startEngine()
    {
        cout << "Vehicle engine starts." << "\n";
    }
};

class LandVehicle : virtual public Vehicle
{
public:
    LandVehicle(string nm, string mdl, double fuel) : Vehicle(nm, mdl, fuel)
    {
    }
};

class FuelVehicle : virtual public Vehicle
{
public:
    FuelVehicle(string nm, string mdl, double fuel) : Vehicle(nm, mdl, fuel)
    {
    }
};

class Car : public LandVehicle, public FuelVehicle
{
public:
    Car(string nm, string mdl, double fuel) : Vehicle(nm, mdl, fuel),LandVehicle(nm, mdl, fuel),FuelVehicle(nm, mdl, fuel)
    {
    }

    void startEngine() override
    {
        cout << "Car engine makes less sound." << "\n";
    }
};

class Truck : public LandVehicle, public FuelVehicle
{
public:
    Truck(string nm, string mdl, double fuel) : Vehicle(nm, mdl, fuel),LandVehicle(nm, mdl, fuel),FuelVehicle(nm, mdl, fuel)
    {
    }

    void startEngine() override
    {
        cout << "Truck engine makes more sound" << "\n";
    }
};

int main()
{
    Vehicle* v1 = new Car("Toyota", "Corolla", 50);
    Vehicle* v2 = new Truck("Volvo", "FH16", 300);

    v1->startEngine();
    v2->startEngine();

    return 0;
}
