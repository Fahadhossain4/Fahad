#include <iostream>
using namespace std;

class Base 
{
    int a;
    public:
    Base(int x) : a(x) {}
    void show()
    {
        cout<< a << endl;
    }
};

int main()
{
    Base b[3][2]={
        1,2,
        3,4,
        5,6
    };
    Base *p;
    p = &b[0][0];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            p->show();
            p++;
        }
    }
    return 0;
}