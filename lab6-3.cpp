#include <iostream>
using namespace std;

class Sample
{
    int x;
public:
    Sample(int a = 0)
    {
        x = a;
        cout << "Constructor called. x = " << x << endl;
    }
    Sample(const Sample &obj)
    {
        x = obj.x;
        cout << "Copy Constructor called. x = " << x << endl;
    }
    ~Sample()
    {
        cout << "Destructor called. x = " << x << endl;
    }
    void show()
    {
        cout << "x = " << x << endl;
    }
};
void display(Sample obj)
{
    cout << "Inside function display()" << endl;
    obj.show();
}
int main()
{
    cout << "Creating object obj1:" << endl;
    Sample obj1(10);

    cout << "\nAssigning obj1 to obj2:" << endl;
    Sample obj2;
    obj2 = obj1;

    cout << "\nPassing obj1 to function:" << endl;
    display(obj1);

    cout << "\nEnd of main()" << endl;
    return 0;
}
