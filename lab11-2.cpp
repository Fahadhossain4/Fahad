#include <iostream>
using namespace std;
class Student
{
protected:
    string name;
    int rollNo;
public:
    Student(string n,int r)
    {
        name=n;
        rollNo=r;
    }
    virtual ~Student() {}
    virtual void displayResult()=0;
};
class ScienceStudent:public Student
{
    float physics,chemistry,maths;
public:
    ScienceStudent(string n,int r,float p,float c,float m):Student(n,r)
    {
        physics=p;
        chemistry=c;
        maths=m;
    }
    void displayResult()
    {
        cout<<"Science Student: "<<name<<" (Roll No: "<<rollNo<<")"<<endl;
        cout<<"Physics: "<<physics<<endl;
        cout<<"Chemistry: "<<chemistry<<endl;
        cout<<"Maths: "<<maths<<endl;
        cout<<"Total: "<<physics+chemistry+maths<<endl;
        cout<<"Percentage: "<<(physics+chemistry+maths)/3<<"%"<<endl;
    }
};
class ArtsStudent:public Student
{
    float history,geography,english;
public:
    ArtsStudent(string n,int r,float h,float g,float e):Student(n,r)
    {
        history=h;
        geography=g;
        english=e;
    }
    void displayResult()
    {
        cout<<"Arts Student: "<<name<<" (Roll No: "<<rollNo<<")"<<endl;
        cout<<"History: "<<history<<endl;
        cout<<"Geography: "<<geography<<endl;
        cout<<"English: "<<english<<endl;
        cout<<"Total: "<<history+geography+english<<endl;
        cout<<"Percentage: "<<(history+geography+english)/3<<"%"<<endl;
    }
};
int main()
{
    Student *students[2];
    students[0]=new ScienceStudent("Fahad",1,85.5,90.0,92.5);
    students[1]=new ArtsStudent("Nice",2,78.0,82.5,88.0);
    for(int i=0;i<2;i++)
    {
        students[i]->displayResult();
        cout<<endl;
    }
    for(int i=0;i<2;i++)
    {
        delete students[i];
    }
    return 0;
}