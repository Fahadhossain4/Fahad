#include<iostream>
#include<string>
using namespace std;

class TeamMember
{
    private:
    string name;
    int memberID;
    double hourlyrate;
    public:
    TeamMember(string n,int mi,double hr)
    {
        name=n;
        memberID=mi;
        hourlyrate=hr;
    }
    friend class projectmanager;
};

class developer : public TeamMember
{
    private:
    int lineofcodewritten;
    public:
    developer(string n,int mi,double hr,int l)
    :TeamMember(n,mi,hr)
    {
        lineofcodewritten=l;
    }
    friend class projectmanager;
};

class tester : public TeamMember
{
    private:
    int bugfound;
    public:
    tester(string n,int mi,double hr,int l)
    : TeamMember(n,mi,hr)
    {
        bugfound=l;
    }
    friend class projectmanager;
 };

 class projectmanager
 {
    public:
    void calculatecost (developer& p)
    {
        double cost=p.hourlyrate * 160 + 0.1 * p.lineofcodewritten;
        cout<<"Cost for Developer "<<p.name<<":"<<cost<<"\n";
    }

    void calculatecost (tester& c)
    {
        double cost=c.hourlyrate*160+50*c.bugfound;
        cout<<"Cost for Tester "<<c.name<<":"<<cost<<"\n";
    }
 };

 int main ()
 {
    developer d1("Raj",12345,1000,150);
    tester t1("Neha",123456,500,50);

    projectmanager pm;

    pm.calculatecost(d1);
    pm.calculatecost(t1);
    return 0;

 }