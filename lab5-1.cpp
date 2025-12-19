#include<iostream>
using namespace std;

class animal
{
protected:
	string name;
	string species;
	int age;
public:
	virtual void makesound();
	animal(string name,string species,int age);
	    virtual void showInfo()
		{
        cout << "Name: " << name << ", Species: " << species << ", Age: " << age << "\n";
		}
};
void animal::makesound()
{
	cout<<"The animal makes sound";
}
animal::animal(string n,string s,int a)
{
	name=n;
	species=s;
	age=a;
}

class mammal: virtual public animal
{
protected:
	string hasfur;
public:
	mammal(string n,string s,int a,string hf)
	:animal(n,s,a)
	{
		hasfur=hf;
	}
};

class bird: virtual public animal
{
protected:
	string canfly;
public:
	bird(string n,string s,int a,string cf)
	:animal(n,s,a)
	{
		canfly=cf;
	}
};
class dog: public mammal,public bird
{
public:
	dog(string n, int a)
		: animal(n, "Dog", a),
		  mammal(n, "Dog", a, "Yes"),
		  bird(n, "Dog", a, "No")
	{}
	void makesound() override
	{
		cout<<"Dog's sound veu veu."<<"\n";
	}
};

class parrot: public mammal,public bird
{
	public:
    parrot(string n, int a)
        : animal(n, "Parrot", a),
          mammal(n, "Parrot", a, "No"),
          bird(n, "Parrot", a, "Yes")
    {}
	void makesound() override
	{
		cout<<"parrot'sound mithu mithu."<<"\n";
	}
};

int main()
{
    animal* a;

    dog d("Jony", 3);
    parrot p("Mittu", 2);

    a = &d;
    a->makesound();
	a->showInfo();

    a = &p;
    a->makesound();
	a->showInfo();

    return 0;
}