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
    A(int q,int w,int e)
    {
    i=q;
    j=w;
    k=e;
    cout<<i <<" "<<j <<" "<<k<<" ";
    }
};

class B : public A
{
    private:
    int l;
    protected:
    int m;
    public:
    int o;
    B(int q,int w,int e,int x,int y,int z):A(q,w,e)
    {
        l=x;
        m=y;
        o=z;
        cout<<l<<" " <<m<<" " <<o<<" ";
    }
};

class C : public B
{
    private:
    int s;
    protected:
    int d;
    public:
    int f;
    C(int q,int w,int e,int x,int y,int z,int g,int h,int j):B(q,w,e,x,y,z)
    {
        s=g;
        d=h;
        f=j;
        cout<<s<<" " <<d<<" " <<f<<" ";
    }
};

int main()
{
    C ob1(1,2,3,4,5,6,7,8,9);
    cout<<"\n";
    B ob2(9,76,34,75,96,23);
    cout<<"\n";
    A ob3(100,200,300);
    return 0;

}
