#include<iostream>
using namespace std;

class animal
{
    public:
    virtual void makesound()
    {
        cout<<"making sound"<<"\n";
    }
};

class dog: public animal
{
   void makesound() override
    {
        cout<<"veu veu"<<"\n";
    }
};

class cat: public animal
{
   void makesound() override
    {
        cout<<"meaw meaw"<<"\n";
    }
};

int main()
{
    animal *a;
    dog d;
    cat c;
    a=&d;
    a->makesound();
    a=&c;
    a->makesound();
    return 0;
}