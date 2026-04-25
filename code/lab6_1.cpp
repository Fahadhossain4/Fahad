#include <iostream>
using namespace std;

class square
{
    private:
    int i;
    public:
    square(int n)
    {
        i=n;
    }
    void set_i(int n)
    {
        i=n;
    }
    int get_i()
    {
        return i;
    }
};

void sqr(square o)
{
    o.set_i(o . get_i() * o . get_i());
    cout<<o.get_i()<<endl;
}

void sqr_ref(square *o)
{
    o->set_i(o->get_i()*o->get_i());
    cout<<o->get_i()<<endl;
}

int main ()
{
    square a(10);
    cout<<"square by value:";
    sqr(a);
    cout<<"After call by value i:" << a.get_i() << endl;
    cout<<"square by ref:";
    sqr_ref(&a);
    cout<<"After call by ref i:" << a.get_i() << endl;
    return 0;
}