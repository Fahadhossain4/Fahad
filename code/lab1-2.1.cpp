#include <iostream>
#include <string>
using namespace std;

class car
{
private:
    string company;
    string model;
    int year;
public:
    car()
    {
        cout<<"Input the variables:";
        cin>>company>>model>>year;
        cout<<"Company:"<<company<<"\n"<<"Model:"<<model<<"\n"<<"Year:"<<year;
    }
};

int main()
{
    car obj;
    return 0;
}
