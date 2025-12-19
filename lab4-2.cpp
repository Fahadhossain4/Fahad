#include <iostream>
using namespace std;

class person
{
    public:
    virtual void showinfo()
    {
        cout<<"Showing info"<<"\n";
    }
};

class student: public person
{
    public:
    void showinfo() override
    {
        cout<<"Md.Fahad Hossain Tareq"<<"\n"<<"Roll:2410003"<<"\n";
    }
};

void fun(person *p)
{
    p->showinfo();
}

void fun2(person p)
{
    p.showinfo();
}

int main()
{
    person *pt;
    student obj1;
    pt=&obj1;
    fun(pt);
    fun2(obj1);
    return 0;
}