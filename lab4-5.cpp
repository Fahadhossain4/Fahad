#include<iostream>
using namespace std;

class LibraryItem
{
    public:
    virtual void displayinfo()
    {
        cout<<"Displaying name.";
    }
};

class book: public LibraryItem
{
    public:
    void displayinfo() override
    {
        cout<<"Displaying book name"<<"\n";
    }
};

class magazine: public LibraryItem
{
    public:
    void displayinfo() override
    {
        cout<<"Displaying magazine name"<<"\n";
    }
};

void fun(LibraryItem*arr[],int i)
{
    for(int j=0;j<i;j++)
    {
        arr[j]->displayinfo();
    }
}

int main()
{
    LibraryItem *arr[2];
    book b;
    magazine m;
    arr[0]=&b;
    arr[1]=&m;
    fun(arr,2);
    return 0;
}