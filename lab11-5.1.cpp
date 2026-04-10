/*Write a C++ program to overload the subscript operator [] for a class that
stores student marks.*/
#include <iostream>
using namespace std;
class student
{
    int marks[5];
public:
    student()
    {
        for (int i=0; i<5; i++)
        {
            marks[i] = i*10;
        }
    }
    int &operator[](int i)
    {
        return marks[i];
    }
};
int main()
{
    student a;
    for (int i=0; i<5; i++)
    {
        cout << "a[" << i << "] = " << a[i] << endl;
    }
    return 0;
}