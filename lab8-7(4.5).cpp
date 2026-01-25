#include <iostream>
using namespace std;

class Base 
{
    int a;
    public:
    void set_a(int x){ a = x;}
    void show()
    {
        cout<< a << endl;
    }
};

int main()
{
    Base *p;
    p=new Base [3];
    if(!p)
    {
        cout << "Memory allocation failed" << endl;
        return 1;
    }
        for(int j=0;j<3;j++)
        {
            p[j].set_a(j+1);
            p[j].show();
        }
    delete [] p;
    return 0;
}