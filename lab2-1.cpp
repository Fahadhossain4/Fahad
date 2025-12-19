#include<iostream>
using namespace std;

class student
{
    private:
    int x=10;
    void fun1();
    public:
    int y=12;
    void fun2();
    protected:
    int z=4;
    void fun3();
};

void student::fun1()
{
    cout<<"This is in private";
}

void student::fun2()
{
    cout<<"This is in public";
}

void student::fun3()
{
    cout<<"This is in protected";
}

int main()
{
    student ob;
    cout<<ob.x<<"\n"<<ob.y<<"\n"<<ob.z<<"\n";
    ob.fun1();
    ob.fun2();
    ob.fun3();
    return 0;
}