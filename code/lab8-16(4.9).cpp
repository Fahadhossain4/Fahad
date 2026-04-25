#include<iostream>
using namespace std;

int main()
{
    int a = 10;
    int &r = a;
    cout << "Before modification: " << a << endl;
    r = 20;
    cout << "After modification: " << a << endl;
    return 0;
}