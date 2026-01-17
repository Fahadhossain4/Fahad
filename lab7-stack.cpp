#include <iostream>
using namespace std;

#define SIZE 10

class stack
{
    char stck[SIZE];
    int tos;
    public:
    stack();
    char pop();
    void push(char ch);
};

stack::stack()
{
    tos=0;
    cout<<"Constructing stack....."<<endl;
}

void stack::push(char ch)
{
    if(tos==SIZE)
    {
        cout<<"Stack is full.";
        return;
    }
    stck[tos]=ch;
    tos++;
}

char stack::pop()
{
    if(tos==0)
    {
        cout<<"The stack is empty."<<endl;
        return 0;
    }
    tos--;
    return stck[tos];
}

int main()
{
    stack s1,s2;
    int i;
    s1.push('a');
    s1.push('b');
    s1.push('c');
    s2=s1;
    for(i=0;i<3;i++)
    {
        cout<<"pop s1 : "<<s1.pop()<<endl;
    }
    for(i=0;i<3;i++)
    {
        cout<<"pop s2 : "<<s2.pop()<<endl;
    }
    return 0;
}