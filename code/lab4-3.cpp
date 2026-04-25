#include<iostream>
using namespace std;

class vehicle
{
    public:
    virtual void start()
    {
        cout<<"vehical will start.";
    }
};

class car: public vehicle
{
    void start() override
    {
        cout<<"Car will start."<<"\n";
    }
};

class bike: public vehicle
{
    void start() override
    {
        cout<<"Bike will start."<<"\n";
    }
};

int main ()
{
    vehicle *arr[2];
    car obj1;
    bike obj2;
    arr[0]=&obj1;
    arr[1]=&obj2;
    for (int i=0;i<2;i++)
    {
        arr[i]->start();
    }
    return 0;
}
