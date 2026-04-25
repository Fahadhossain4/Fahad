#include <iostream>
using namespace std;

class Payable
{
    public:
    virtual double getAmount()=0;
    virtual ~Payable() {}
};

class HourlyEmployee : public Payable
{
    int id;
    int hours;
    double hour_rate;
    public:
    HourlyEmployee(int x,int h,double r)
    {
        id=x;
        hours=h;
        hour_rate=r;   
    }
    double getAmount() override
    {
        return hours * hour_rate;
    }
};

class WeeklyEmployee : public Payable
{
    int id;
    int weeks;
    double week_rate;
    public:
    WeeklyEmployee(int x,int w, double wr)
    {
        id=x;
        weeks=w;
        week_rate=wr;
    }
    double getAmount() override
    {
        return weeks * week_rate;
    }
};


class Invoice : public Payable
{
    int id;
    int quantity;
    double price_per_item;
    public:
    Invoice(int x,int q,double ppi)
    {
        id=x;
        quantity=q;
        price_per_item=ppi;
    }
    double getAmount() override
    {
        return quantity * price_per_item;
    }
};

void salary (Payable* em)
{
    cout<<em->getAmount()<<endl;
}

Payable* create_HourlyEmployee(int x, int h, double r)
{
    return new HourlyEmployee(x,h,r);
}

int main()
{
    Payable* em1 = new HourlyEmployee(2410003,8,200);
    Payable* em2 = new WeeklyEmployee(2410002,3,20000);
    Payable* em3 = new Invoice(2410015,10,1000);
    cout<<"Salary for Hourly Payable:";
    salary(em1);
    cout<<endl<<"Salary for Weekly Payable:";
    salary(em2);
    cout<<endl<<"Salary for Invoice:";
    salary(em3);
    Payable* em4 = create_HourlyEmployee(2410005,7,300);
    cout<<endl<<"Salary for new Hourly Payable:";
    salary(em3);
    cout<<endl;
    delete em1;
    delete em2;
    delete em3;
    delete em4;
    return 0;
}