#include<iostream>
using namespace std;

int main()
{
    int t,n,i,j;
    cin>>t;
    int a[t];
    for (i=0;i<t;i++)
    {
        cin>>a[i];
    }
    for (j=0;j<t;j++)
    {
        cout<<a[j]%10+a[j]/10<<"\n";
    }
    return 0;
    
}