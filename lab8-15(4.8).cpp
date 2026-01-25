#include <iostream>
using namespace std;

int &f();
int a = 10;
int &f()
{
    return a;
}
int main()
{
    cout << "Before function call: " << a << endl;
    f() = 30;
    cout << "After function call: " << a << endl;
    return 0;
}