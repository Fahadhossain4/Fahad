#include<iostream>
using namespace std;

class myclass
{
    int a;
    public:
    void set_a(int num);
    int get_a();
};

void myclass :: set_a(int num)
{
    a=num;
}

int myclass :: get_a()
{
    return a;
}

int main()
{
    myclass obj1,obj2;
    obj1.set_a(2);
    obj2.set_a(90);
    cout<< obj1.get_a()<<"\n";
    cout<< obj2.get_a()<<"\n";
    return 0;
}