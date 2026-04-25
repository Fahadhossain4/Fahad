#include <iostream>
using namespace std;

class bankac
{
    int acno;
    double balance;
    public:
    void set_a(int a,double b);
    int get_balance();
    void withdraw(double withdraw);
    void deposit(double deposit);
};

void bankac :: set_a(int a,double b)
{
    acno=a;
    balance=b;
}

void bankac :: withdraw(double withdraw)
{
    if (withdraw>0)
    {
        if (withdraw>balance)
            {
                cout<<"Insufficiant Balance";
            }
        else
            {
                balance=balance-withdraw;
                cout<<"Withdraw successful.New balance is:"<<balance;
            }
    }
    else
    {
        cout<<"Ivalid input";
    }
}
void bankac :: deposit(double deposit)
{
    if(deposit<=0)
    {
        cout<<"Invalid deposit";
    }
    else
    {
        balance=balance+deposit;
        cout<<"Deposit successful.New balance is:"<<balance;
    }
}

int main ()
{
    bankac ob;
    double deposit;
    double withdraw;
    ob.set_a(1234523,500000);
    int n;
    cout<< "To deposit press 1 or to withdraw 2:";
    cin>> n;
    if(n==1)
    {
        cout<<"Input amount:";
        cin>>deposit;
        ob.deposit(deposit);
    }
    else
    {
        cout<<"Input amount:";
        cin>>withdraw;
        ob.withdraw(withdraw);
    }
    return 0;
}