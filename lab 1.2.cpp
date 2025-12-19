#include <iostream>
using namespace std;

class rectangle
{
    int length;
    int width;
    void set_a(int l,int w);
    int get_p();
    int get_a();
};

void rectangle :: set_a(int l,int w)
{
    length=l;
    width=w;
}

int rectangle :: get_a()
{
    return length*width;
}

int rectangle :: get_p()
{
    return 2*(length+width);
}

int main()
{
    rectangle ob;
    int l,w;
    cout<<"Input length and width:";
    cin>> l >> w;
    ob.set_a(l,w);
    cout<< "The area is:" << ob.get_a()<<"\n";
    cout<< "The perimeter is:"<< ob.get_p()<<"\n";
    return 0; 

}
