#include <iostream>
using namespace std;

class date
{
private:
    int day;
    int month;
    int year;
public:
    void fun(int d,int m,int y);
    int getd();
    int getm();
    int gety();
    void valid();
};

void date :: fun(int d,int m,int y)
{
    day=d;
    month=m;
    year=y;
}

int date :: getd()
{
    return day;
}

int date :: getm()
{
    return month;
}

int date :: gety()
{
    return year;
}

void date :: valid()
{
    if(month<1 || month>12)
    {
        cout<<"Not valid";
        return;
    }
    else
    {
        if ((year%400==0)||(year%4==0 && year%100!=0))
        {
            if (month==2)
            {
                if(day>29 || day<1)
                {
                    cout<<"Not valid";
                    return;
                }
            }
            else if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
            {
                if (day>31 || day<1)
                {
                    cout<<"Not valid";
                    return;
                }
            }
            else if (month==4 || month==6 || month==9 || month==11)
            {
                if(day>30 || day<1)
                {
                    cout<<"Not valid";
                    return;
                }
            }
        }
        else
        {
            if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
            {
                if (day>31 || day<1)
                {
                    cout<<"Not valid";
                    return;
                }
            }
            else if (month==4 || month==6 || month==9 || month==11)
            {
                if(day>30 || day<1)
                {
                    cout<<"Not valid";
                    return;
                }
            }
            else if(month==2)
            {
                if (day>28 || day<1)
                {
                    cout<<"Not valid";
                    return;
                }
            }
        }
    }
    cout<<"Valid";
}

int main ()
{
    int d,m,y;
    cout<<"Input date,month,year:";
    cin>>d>>m>>y;
    date ob;
    ob.fun(d,m,y);
    ob.valid();
    return 0;
}