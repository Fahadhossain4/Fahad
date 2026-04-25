#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
    string species;
    int age;

public:
    Animal(string n, string s, int a)
    {
        name = n;
        species = s;
        age = a;
    }

    virtual void makeSound()
    {
        cout << "Animal makes a sound." <<"\n";
    }
};

class Mammal : virtual public Animal
{
protected:
    bool hasFur;

public:
    Mammal(string n, string s, int a, bool fur) : Animal(n, s, a)
    {
        hasFur = fur;
    }
};

class Bird : virtual public Animal
{
protected:
    bool canFly;

public:
    Bird(string n, string s, int a, bool fly) : Animal(n, s, a)
    {
        canFly = fly;
    }
};

class Dog : public Mammal, public Bird
{
public:
    Dog(string n, int a) : Animal(n, "Dog", a),Mammal(n, "Dog", a, true),Bird(n, "Dog", a, false)
    {}

    void makeSound() override 
    {
        cout<< "vew vew" <<"\n";
    }
};

class Parrot : public Mammal, public Bird {
public:
    Parrot(string n, int a) : Animal(n, "Parrot", a),Mammal(n, "Parrot", a, false),Bird(n, "Parrot", a, true)
    {}

    void makeSound() override
    {
        cout << "Mithu Mithu" << "\n";
    }
};

int main() 
{
    Animal* a1 = new Dog("Bob", 4);
    Animal* a2 = new Parrot("Mithu", 2);

    a1->makeSound();
    a2->makeSound();

    return 0;
}
