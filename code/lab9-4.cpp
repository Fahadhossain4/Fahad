#include <iostream>
using namespace std;

class Calculator
{
private:
    int result;
public:
    Calculator(int r=0)
    {
        this->result = r;
    }

    Calculator& set(int result)
    {
        this->result = result;
        return *this;
    }

    Calculator& add(int x)
    {
        this->result += x;
        return *this;
    }

    Calculator& operator++()
    {
        ++this->result;
        return *this;
    }

    void display()
    {
        cout << "Result: " << result << endl;
    }

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
};

int main()
{
    Calculator c;
    c.set(10).add(5).add(15);
    c.display();
    ++c;
    c.display(); 
    int a = 5, b = 10;
    cout << "Before Swap: a = " << a << ", b = " << b<< endl;
    c.swap(a, b);
    cout << "After Swap: a = " << a << ", b = " << b<< endl;
    return 0;
}