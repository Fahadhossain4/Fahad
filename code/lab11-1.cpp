#include <iostream>
using namespace std;
class Shape
{
public:
    virtual void area()=0;
};

class Rectangle:public Shape
{
    int length,breadth;
public:
    Rectangle(int l,int b)
    {
        length=l;
        breadth=b;
    }
    void area()
    {
        cout<<"Area of Rectangle: "<<length*breadth<<endl;
    }
};
class Circle:public Shape
{
    int radius;
public:
    Circle(int r)
    {
        radius=r;
    }
    void area()
    {
        cout<<"Area of Circle: "<<3.14*radius*radius<<endl;
    }
};
int main()
{
    Shape *s1=new Rectangle(10,20);
    Shape *s2=new Circle(5);
    s1->area();
    s2->area();
    delete s1;
    delete s2;
    return 0;
}