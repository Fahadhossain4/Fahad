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
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            b[i][j].show();
        }
    }
    return 0;
}