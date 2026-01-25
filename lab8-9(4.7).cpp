#include <iostream>
using namespace std;

class myclass
{
    private:
    int a;
    public:
    myclass(int x)
    {
        a = x;
        cout << "Constructor called" << endl;
    }
    int id()
    {
        return a;
    }
    void show(myclass &obj)
    {
        cout << "Value of a: " << obj.id() << endl;
    }
    ~myclass()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    myclass p(10);
    p.show(p);
    return 0;
}