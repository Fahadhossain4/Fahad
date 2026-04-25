#include<iostream>
using namespace std;

class emni
{
    private:
    double width;
    public:
    void set_width(double w);
    friend void get_width(emni& b);
};

void emni::set_width(double w)
{
    width = w;
}

void get_width(emni& b)
{
    cout<<"Width is:"<<b.width<<"\n";
}

int main()
{
    emni ob;
    ob.set_width(10.123);
    get_width(ob);
    return 0;
}