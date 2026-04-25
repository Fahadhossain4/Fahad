#include <iostream>
using namespace std;
class A
{
    int x;
public:
    A(int a=0)
    {
        x=a;
    }
    void display()
    {
        cout<<x<<endl;
    }
    A operator=(A a)
    {
        x=a.x;
        return *this;
    }
    bool operator==(A a)
    {
        return x==a.x;
    }
    int operator[](int i)
    {
        if(i==0)            
        return x;
        else            
        return -1;
    }
};
int main(){
    A a(10),b(20),c,d;
    c=d=a;
    a.display();
    b.display();
    c.display();
    d.display();
    if(a==b)        
    cout<<"a and b are equal"<<endl;
    else        
    cout<<"a and b are not equal"<<endl;
    if(a==c)
    cout<<"a and c are equal"<<endl;
    else        
    cout<<"a and c are not equal"<<endl;
    cout<<"a[0] = "<<a[0]<<endl;
    cout<<"a[1] = "<<a[1]<<endl;
    return 0;
}