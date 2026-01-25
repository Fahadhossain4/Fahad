#include <iostream>
using namespace std;

int main()
{
    int a,b;
    long long x=1,y=1;
    cin>>a>>b;
    for (int i=0;i<b;i++)
    {
        x=x*a;
    }
    for (int j=0;j<a;j++)
    {
        y=y*b;
    }
    cout<<x-y<<endl;
    return 0;
}