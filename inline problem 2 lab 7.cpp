#include <iostream>
using namespace std;

class circle
{
    double radious;
    public:
    circle(double r)
    {
        radious=r;
    }
    inline double area()
    {
        return 3.1416*radious*radious;
    }
};

int main ()
{
    circle a(32.75);
    cout<<"The area is: "<<a.area()<<endl;
    return 0;
}
