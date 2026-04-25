#include<iostream>
using namespace std;

class A
{
    private:
    int x;
    public:
    void set_x(int p);
    friend void get_x(A& a);
    friend class B;
};

class B
{
    public:
    void get_x2(A& q)
    {
    cout<<"x:"<<q.x<<"\n";
    }
};

void A::set_x(int p)
{
    x=p;
}

void get_x(A& a)
{
    cout<<"x:"<<a.x<<"\n";
}

int main()
{
    A ob1;
    B ob2;
    ob1.set_x(100);
    get_x(ob1);
    ob2.get_x2(ob1);
    return 0;
}