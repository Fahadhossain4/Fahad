#include <iostream>
#include <string>
using namespace std;

class employee
{
    string name;
    int id;
    int salary;
public:
    void fun(string n,int i,int s);
    string get_n();
    int get_s();
};

void employee :: fun(string n,int i,int s)
{
    name=n;
    id=i;
    salary=s;
}

string employee :: get_n()
{
    return name;
}

int employee :: get_s()
{
    return salary;
}

int main()
{
    int e;
    cout << "Input the number of employee:";
    cin>>e;
    employee ob[e];
    for (int j=0;j<e;j++)
    {
        string n;
        int i;
        int s;
        cout<<"Input name:";
        cin>>n;
        cout<<"Input id:";
        cin>>i;
        cout<<"Input salary:";
        cin>>s;
        ob[j].fun(n,i,s);
    }
    int max=0;
    for (int j=1;j<e;j++)
    {
        if(ob[j].get_s()>ob[max].get_s())
        max=j;
    }
    cout<<"The employee with hight salary:"<<ob[max].get_n()<<"\n";
    return 0;
}