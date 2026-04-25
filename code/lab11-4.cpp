#include <iostream>
using namespace std;
class A
{
    int x,y;
public:
    A(int a=0,int b=0)
    {
        x=a;
        y=b;
    }
    void display()
    {
        cout<<x<<" "<<y<<endl;
    }
    int operator==(A a);

};
int A::operator==(A a)
{
    return (x==a.x && y==a.y);
}
int main(){
    A a(10,20),b(20,30),C(10,20);
    if(a==b)
    {
        cout<<"a and b are equal"<<endl;
    }
    else
    {
        cout<<"a and b are not equal"<<endl;
    }
    if(a==C)
    {
        cout<<"a and C are equal"<<endl;
    }
    else
    {
        cout<<"a and C are not equal"<<endl;
    }
    return 0;
}