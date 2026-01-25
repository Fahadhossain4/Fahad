#include <iostream>
using namespace std;

void ref(int &x)
{
    x =10;
}

int main()
{
    int a = 5;
    cout << "Before ref function call: " << a << endl;
    ref(a);
    cout << "After ref function call: " << a << endl;
    return 0;
}