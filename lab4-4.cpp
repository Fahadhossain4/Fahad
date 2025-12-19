#include<iostream>
using namespace std;

class ruet
{
    public:
    string name;
    int roll;
    void input()
    {
        cout<<"Input info:";
        cin>>name>>roll;
    }
    virtual void display()
    {
        cout<<name<<"\n"<<roll<<"\n";
    }
};

class ece: public ruet
{
    public:
    void display() override
    {
        cout<<name<<"\n"<<roll<<"\n"<<"ECE"<<"\n";
    }
};

class student: public ece
{
    public:
    double cgpa;
    void display() override
    {
        cout<<name<<"\n"<<roll<<"\n"<<"ECE"<<"\n"<<"Inter cgpa:";
        cin>>cgpa;
        if(cgpa>3.75)
        {
            cout<<"Honors Candidate.";
        }
        else
        {
            cout<<"Not honors candidate.";
        }
        
    }
};

int main()
{
    ruet *r;
    ece d;
    student s;
    r=&d;
    r->input();
    r->display();
    r=&s;
    r->input();
    r->display();
    return 0;
}