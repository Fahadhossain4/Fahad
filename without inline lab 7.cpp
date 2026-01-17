#include <iostream>
using namespace std;

long long int fac(int x)
{
    long long int f=1;
    for(int i=1;i<=x;i++)
    f=f*i;
    return f;
}

int main()
{
    int n;
    cout<<"Input the number:";
    cin>>n;
    cout<<"Factorial is:"<<fac(n);
    return 0;
}