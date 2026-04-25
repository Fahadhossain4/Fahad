#include <iostream>
using namespace std;

const int SIZE = 10;

class A
{
    int x[SIZE];
public:
    A()
    {
        for (int i=0; i<SIZE; i++)
        {
            x[i] = i*10;
        }
    }
    int &operator[](int i)
    {
        return x[i];
    }
};

int main()
{
    A a;
    for (int i=0; i<SIZE; i++)
    {
        cout << "a[" << i << "] = " << a[i] << endl;
    }
    return 0;
}