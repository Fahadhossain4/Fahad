#include<iostream>
using namespace std;

class A
{
    private:
    int i;
    protected:
    int j;
    public:
    int k;
    void get_A(int q,int w,int e);
    void show_A()
    {
        cout<<i<<" "<<j<<" "<<k<<"\n";
    }
};

void A :: get_A(int q,int w,int e)
{
    i=q;
    j=w;
    k=e;
}

class B : protected A
{
    private:
    int l;
    protected:
    int m;
    public:
    int o;
    void get_B(int x,int y,int z);
    void show_B()
    {
        cout<<j<<" "<<k<<" "<<l<<" "<<m<<" "<<o<<"\n";    //i is private so can not be accessed
    }
};

void B :: get_B(int x,int y,int z)
{
    l=x;
    m=y;
    o=z;
}

class C : public B
{
    private:
    int s;
    protected:
    int d;
    public:
    int f;
    void get_C(int g,int h,int j);
    void show_c()
    {
        cout<<j<<" "<<k<<" "<<m<<" "<<o<<" "<<s<<" "<<d<<" "<<f<<"\n";   //i and l can not be acessed
    }
};

void C :: get_C(int g,int h,int j)
{
    s=g;
    d=h;
    f=j;
}

int main()
{
    A ob1;
    B ob2;
    C ob3;
    ob1.get_A(1,2,3);
    ob2.get_B(4,5,6);
    ob3.get_C(7,8,9);
    ob1.show_A();
    ob2.show_B();
    ob3.show_c();
    return 0;

}

