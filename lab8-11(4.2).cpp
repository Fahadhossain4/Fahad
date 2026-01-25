#include <iostream>
using namespace std;

class myclass
{
    private:
    int a,b;
    public:
    myclass(int x, int y)
    {
        a = x;
        b = y;
    }
    int show_a()
    {
        return a;
    }
    int show_b()
    {
        return b;
    }
};
int main()
{
    myclass obj[2][3]={
        myclass(1,2), myclass(3,4), myclass(5,6),
        myclass(7,8), myclass(9,10), myclass(11,12)
    };
    myclass *p;
    p = &obj[0][0];
    cout<< "a" << " " << "b" << endl;
    cout<< "----" << endl;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << p->show_a() <<" ";
            cout << p->show_b() << endl;
            p++;
        }
    }
    return 0;
}