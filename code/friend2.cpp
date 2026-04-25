#include <iostream>
using namespace std;

class box
{
    private:
    double hight;
    public:
    void set_hight(double h);
    friend void get_hight(box& b);
};

void box::set_hight(double h)
{
    hight=h;
}

void get_hight(box& b)
{
    cout<<"The hight is:"<<b.hight<<"\n";
}

int main ()
{
    box ob;
    ob.set_hight(123.123884);
    get_hight(ob);
    return 0;
}