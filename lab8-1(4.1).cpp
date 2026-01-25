#include <iostream>
using namespace std;

class square
{
    private:
    int x;
    public:
    void set_x(int a)
    {
        x = a;
    }
    int sq()
    {
        return x * x;
    }
};

int main()
{
    square s[5];
    for(int i=0;i<5;i++)
    {
        s[i].set_x(i+1);
    }
    for(int i=0;i<5;i++)
    {
        cout << "Square:" << s[i].sq() << endl;
    }
    return 0;

}