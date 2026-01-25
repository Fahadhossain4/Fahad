#include <iostream>
using namespace std;

int x, y;
int & findMax()
{
    if (x > y)
        return x;
    else
        return y;
}

int main()
{
    x=15;
    y=25;
    cout << "Max in case 1: " << findMax() << endl;
    x=10;
    y=20;
    cout << "Max in case 2: " << findMax() << endl;
    return 0;
}