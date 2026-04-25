#include <iostream>
using namespace std;

// ==============================
// Base Class: Animal
// ==============================
class Animal {
protected:
    string name;
    string species;
    int age;

public:
    // Constructor
    Animal(string n, string s, int a) : name(n), species(s), age(a) {}

    // Virtual method so derived classes can override
    virtual void makeSound() {
        cout << name << " makes a generic animal sound." << endl;
    }

    virtual void showInfo() {
        cout << "Name: " << name 
             << ", Species: " << species 
             << ", Age: " << age << endl;
    }
};

// ==============================
// Intermediate Class: Mammal
// Virtual inheritance to avoid diamond problem
// ==============================
class Mammal : virtual public Animal {
protected:
    bool hasFur;

public:
    Mammal(string n, string s, int a, bool fur)
        : Animal(n, s, a), hasFur(fur) {}

    void showMammalInfo() {
        cout << name << " is a mammal. Has fur? " << (hasFur ? "Yes" : "No") << endl;
    }
};

// ==============================
// Intermediate Class: Bird
// Virtual inheritance to avoid diamond problem
// ==============================
class Bird : virtual public Animal {
protected:
    bool canFly;

public:
    Bird(string n, string s, int a, bool fly)
        : Animal(n, s, a), canFly(fly) {}

    void showBirdInfo() {
        cout << name << " is a bird. Can fly? " << (canFly ? "Yes" : "No") << endl;
    }
};

// ==============================
// Derived Class: Dog
// Inherits from Mammal and Bird → Diamond problem solved with virtual inheritance
// ==============================
class Dog : public Mammal, public Bird {
public:
    // Constructor uses the Animal constructor ONCE due to virtual inheritance
    Dog(string n, int a)
        : Animal(n, "Dog", a),
          Mammal(n, "Dog", a, true),
          Bird(n, "Dog", a, false) {}

    void makeSound() override {
        cout << name << " barks: Woof! Woof!" << endl;
    }
};

// ==============================
// Derived Class: Parrot
// ==============================
class Parrot : public Mammal, public Bird {
public:
    Parrot(string n, int a)
        : Animal(n, "Parrot", a),
          Mammal(n, "Parrot", a, false),
          Bird(n, "Parrot", a, true) {}

    void makeSound() override {
        cout << name << " says: Hello! I can talk!" << endl;
    }
};

// ==============================
// MAIN
// ==============================
int main() {
    // Polymorphic use
    Animal* zoo[2];

    zoo[0] =  Dog("Buddy", 5);
    zoo[1] =  Parrot("Rio", 2);

    // Display info and sounds
    for (int i = 0; i < 2; i++) {
        zoo[i]->showInfo();
        zoo[i]->makeSound();
        cout << endl;
    }
    return 0;
}
