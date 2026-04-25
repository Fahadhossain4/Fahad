#include<iostream>
#include<string>
using namespace std;

class Employee
{
    private:
    string name;
    int employeeID;
    double baseSalary;
    public:
    Employee(string n,int ei,double bs)
    {
        name=n;
        employeeID=ei;
        baseSalary=bs;
    }
    friend class HRDepartment;
};

class PermanentEmployee : public Employee
{
    private:
    int yearsOfService;
    public:
    PermanentEmployee(string n,int ei,double bs,int y)
    :Employee(n,ei,bs)
    {
        yearsOfService=y;
    }
    friend class HRDepartment;
};

class ContractEmployee : public Employee
{
    private:
    int contractDuration;
    public:
    ContractEmployee(string n,int ei,double bs,int y)
    : Employee(n,ei,bs)
    {
        contractDuration=y;
    }
    friend class HRDepartment;
 };

 class HRDepartment
 {
    public:
    void calculatebonus (PermanentEmployee& p)
    {
        double bonus=0.1 * p.baseSalary+ 1000 * p.yearsOfService;
        cout<<"Bonus for Permanent Employee "<<p.name<<":"<<bonus<<"\n";
    }

    void calculatebonus (ContractEmployee& c)
    {
        double bonus=0.05*c.baseSalary;
        cout<<"Bonus for Contract Employee "<<c.name<<":"<<bonus<<"\n";
    }
 };

 int main ()
 {
    PermanentEmployee p1("John",12345,100000,5);
    ContractEmployee c1("Alice",123456,50000,4);

    HRDepartment hr;

    hr.calculatebonus(p1);
    hr.calculatebonus(c1);
    return 0;

 }