#include <iostream>
using namespace std;

class myclass 
{
public:
    int value;
    myclass(int i = 0) 
    {
        value = i;
    }

    myclass& operator=(const myclass& obj) 
    {
        value = obj.value;
        return *this;
    }

    void display() 
    {
        cout << value << endl;
    }
};

int main() {
    myclass ob1, ob2, ob3, ob4(50);

    ob1 = ob2 = ob3 = ob4;

    ob1.display();
    ob2.display();
    ob3.display();
    ob4.display();

    return 0;
}
