#include <iostream>
using namespace std;

class myclass {
    int x;

public:
    myclass(int a = 0)
    {
        x = a;
        cout << "Constructor called x = " << x << endl;
    }
    ~myclass()
    {
        cout << "Destructor called x = " << x << endl;
    }

    void show()
    {
        cout << "x = " << x << endl;
    }
};
void display(myclass o)
{
    cout << "Inside function display()" << endl;
    o.show();
}

int main() {
    cout << "Creating object o1:" << endl;
    myclass o1(10);
    cout << "Assigning o1 to o2:" << endl;
    myclass o2;
    o2 = o1;
    return 0;
}