#include <iostream>
using namespace std;

int fac(int n)
{
    int sum = 1;
    for(int i=1;i<=n;i++)
    {
        sum=sum*i;
    }
    return sum;
}

int main()
{
    int i,j;
    cout<<"Input the number:";
    cin>>i;
    j=i;
    int sum = 0;
    while(j>0)
    {
        sum=sum+fac(j%10);
        j=j/10;
    }
    if(sum==i)
    {
        cout<<"The number is a strong number."<<endl;
    }
    else
    {
        cout<<"The number is not a strong number."<<endl;
    }
    return 0;
}