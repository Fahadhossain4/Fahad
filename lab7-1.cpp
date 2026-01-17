#include <iostream>
using namespace std;

class Employee
{
    int id;
    public:
    Employee(int x)
    {
        id=x;
    }
    virtual double getAmount()=0;
    virtual ~Employee() {}
};

class HourlyEmployee : public Employee
{
    int hours;
    double hour_rate;
    public:
    HourlyEmployee(int x,int h,double r): Employee(x)
    {
        hours=h;
        hour_rate=r;   
    }
    double getAmount() override
    {
        return hours * hour_rate;
    }
};

class WeeklyEmployee : public Employee
{
    int weeks;
    double week_rate;
    public:
    WeeklyEmployee(int x, int w, double wr) : Employee (x)
    {
        weeks=w;
        week_rate=wr;
    }
    double getAmount() override
    {
        return weeks * week_rate;
    }
};

void salary (Employee* em)
{
    cout<<em->getAmount()<<endl;
}

Employee* create_Hourlyemployee(int x, int h, double r)
{
    return new HourlyEmployee(x,h,r);
}

int main()
{
    Employee* em1 = new HourlyEmployee(2410003,8,200);
    Employee* em2 = new WeeklyEmployee(2410002,3,20000);
    cout<<"Salary for Hourly Employee:";
    salary(em1);
    cout<<endl<<"Salary for Weekly Employee:";
    salary(em2);
    Employee* em3 = create_Hourlyemployee(2410005,7,300);
    cout<<endl<<"Salary for new Hourly Employee:";
    salary(em3);
    cout<<endl;
    delete em1;
    delete em2;
    delete em3;
    return 0;
}