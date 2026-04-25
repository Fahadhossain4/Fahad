#include <iostream>
using namespace std;

class Base
{
    int a;
    public:
    void set_a(int a)
    {
        this->a = a;
    }
    void show()
    {
        cout << a << endl;
    }
};

int main()
{
    Base B;
    B.set_a(10);
    B.show();
    return 0;
}