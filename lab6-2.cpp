#include <iostream>
using namespace std;
class myclass
{
    int a,b;
    public:
    void set_fun(int i,int j)
    {
        a=i;
        b=j;
    }
    void get_fun()
    {
        cout<<"a="<<a<<endl<<"b="<<b<<endl;
    }
};

int main()
{
    myclass ob1, ob2;
    ob1.set_fun(10,20);
    ob1.get_fun();
    cout<<"After assigning another obj"<<endl;
    ob2=ob1;
    ob2.get_fun();
    return 0;
}