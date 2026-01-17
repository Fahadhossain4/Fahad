#include <iostream>
using namespace std;

class book
{
    string name;
    int id;
    public:
    book(string n, int i)
    {
        name=n;
        id=i;
    }
    void get_book()
    {
        cout<<"The name of the book is: "<<name<<endl<<"The id of the book is: "<<id<<endl;
    }
};

book* new_book(string name,int id)
{
    return new book(name,id);
}

int main()
{
    book b("c++",2428);
    b.get_book();
    book* b2= new_book("Analogue circuit",4567);
    b2->get_book();
    return 0;
}