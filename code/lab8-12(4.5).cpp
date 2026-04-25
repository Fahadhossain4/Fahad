#include <iostream>
using namespace std;

class myclass
{
    private:
    int i,j;
    public:
    void set_ij(int a, int b)
    {
        i = a;
        j = b;
    }
    int get_sub()
    {
        return i - j;
    }
    ~myclass()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    myclass *m = new myclass[10];
    if(!m)
    {
        cout << "Memory allocation failed" << endl;
        return 1;
    }
    for(int k = 0; k < 10; k++)
    {
        m[k].set_ij(k + 10, k);
        cout << "Subtraction for object " << k << ": " << m[k].get_sub() << endl;
    }
    delete[] m;
    return 0;
}