#include <iostream>
#include <string>
using namespace std;

class Dog
{
    public:
    void bark();
};

void Dog :: bark()
{
    cout << "Woof!";
}

int main()
{
    Dog obj;
    obj.bark();
    return 0;
}
