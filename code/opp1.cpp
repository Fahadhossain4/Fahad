#include <iostream>
#include <string>
using namespace std;

class Book
{
    public:
    string title;
    string author;
    int year;
};

int main ()
{
    Book obj1;
    obj1.title = "Matilda";
    obj1.author = "Roald Dahl";
    obj1.year = 1964;

    Book obj2;
    obj2.title = "The Giving Tree";
    obj2.author = "Shel Silverstein";
    obj2.year = 1964;

    cout << obj1.title <<", "<< obj1.author <<", "<< obj1.year<<"\n";
    cout << obj2.title <<", "<< obj2.author <<", "<< obj2.year<<"\n";

    return 0;
}
