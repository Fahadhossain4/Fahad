#include <iostream>
using namespace std;

int main()
{
    int i,j,riv=0;
    cin>>i;
    j=i;
    while(i>0)
    {
        riv=riv*10+i%10;
        i=i/10;
    }
    if(j==riv)
    {
        cout<<j<<"-> Palindrome";
    }
    else
    {
        cout<<j<<"-> Not palindrome";
    }
    return 0;
}