#include <iostream>
#include <string>
using namespace std;

class car
{
    public:
    string brand;
    string model;
    int year;
    car(string x,string y,int z);
};

car :: car (string x,string y,int z)
{
    brand = x;
    model = y;
    year = z;
}

int main ()
{
    car obj1("Toyota","corola",2020);
    car obj2("BMW","WZX",2023);
    car obj3("Bugadi","FZS",2025);
    cout <<  obj1.brand << " " << obj1.model << " " << obj1.year << "\n";
    cout <<  obj2.brand << " " << obj2.model << " " << obj2.year << "\n";
    cout <<  obj3.brand << " " << obj3.model << " " << obj3.year << "\n";
    return 0;
}
