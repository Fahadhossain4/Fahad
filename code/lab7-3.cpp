#include <iostream>
using namespace std;

class studentFee
{
    public:
    virtual double getAmount()=0;
    virtual string getFirstname()=0;
    virtual string getLastname()=0;
    virtual string getAddress()=0;
    virtual string getContact()=0;
    virtual ~studentFee() {}
};

class Hostler : public studentFee
{
    string firstname,lastname,address;
    string contact;
    double tutionfee,hostelfee;
    public:
    Hostler(string fn,string ln,string ad,string con,double tf,double hf)
    {
        firstname=fn;
        lastname=ln;
        address=ad;
        contact=con;
        tutionfee=tf;
        hostelfee=hf;
    }
    double getAmount() override
    {
        return tutionfee+hostelfee;
    }
    string getFirstname() override {return firstname;}
    string getLastname() override {return lastname;}
    string getAddress() override {return address;}
    string getContact() override {return contact;}
};

class NonHostler : public studentFee
{
    string firstname,lastname,address;
    string contact;
    double tutionfee,hostelfee;
    public:
    NonHostler(string fn,string ln,string ad,string con,double tf)
    {
        firstname=fn;
        lastname=ln;
        address=ad;
        contact=con;
        tutionfee=tf;
    }
    double getAmount() override
    {
        return tutionfee;
    }
    string getFirstname() override {return firstname;}
    string getLastname() override {return lastname;}
    string getAddress() override {return address;}
    string getContact() override {return contact;}
};

void display(studentFee* sf)
{
    cout<<"Student's first name:"<<sf->getFirstname()<<endl;
    cout<<"Student's last name:"<<sf->getLastname()<<endl;
    cout<<"Stident's address:"<<sf->getAddress()<<endl;
    cout<<"Student's contact:"<<sf->getContact()<<endl;
    cout<<"Student's fees:"<<sf->getAmount()<<endl;
}

studentFee* creatStudent()
{
    return new Hostler("Fahad","Hossain","Natore","fahad@gmail.com",2000,3000);
}

int main()
{
    studentFee* sf1=new Hostler("Nice","Najmul","Narayanganj","nice@gmail.com",2000,3000);
    studentFee* sf2=new NonHostler("Mahi","Mehedi","Savar","mahi@gmail.com",2000);
    display(sf1);
    display(sf2);
    studentFee* sf3=creatStudent();
    display(sf3);
    delete sf1;
    delete sf2;
    delete sf3;
    return 0;
}