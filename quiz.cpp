#include <iostream>
using namespace std;
class car{
    string brand;
    int model;
    public:
    car(){
        brand ="Toyota";
        model =123456;
        cout << "constructor called."<<endl;
    }
    car(const car &c)
    {
        brand=c.brand;
        model=c.model;
        cout<<"copy c c"<<endl;
    }
    ~car(){
        cout<<"destructor called"<<endl;
    }
};

int main ()
{
    car c1;
    car c2=c1;

}