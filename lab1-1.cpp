#include <iostream>
#include <string>
using namespace std;

class Rectangle
{
private:
    int length;
    int width;
public:
    void rec(int x,int y)
    {
        length=x;
        width=y;
        cout<<"Area is:"<<x*y<<"\n"<<"Perimeter is:"<< 2*(x+y) ;
    }
};

int main ()
{
    Rectangle obj;
    int x,y;
    cout<<"Input the length:";
    cin >>x;
    cout<<"Input the width:";
    cin >>y;
    obj.rec(x,y);
    return 0;
}
