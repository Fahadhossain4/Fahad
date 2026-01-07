#include <iostream>
using namespace std;

int main()
{
    int i,rev=0,n,j;
    cin>>i;
    n=i;
    while (n>0)
    rev=rev*10+n%10;
    cout<<rev;
}