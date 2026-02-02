#include <iostream>
using namespace std;

class Calculator
{
public:
    int x, y, result;


    Calculator(int a = 0, int b = 0)
    {
        x = a;
        y = b;
        result = 0;
    }


    Calculator operator+(Calculator c)
    {
        Calculator temp;
        temp.result = this->x + c.x;
        cout << "Addition Result: " << temp.result << endl;
        return temp;
    }

    Calculator operator-(Calculator c)
    {
        Calculator temp;
        temp.result = this->x - c.x;
        cout << "Subtraction Result: " << temp.result << endl;
        return temp;
    }

    Calculator operator*(Calculator c)
    {
        Calculator temp;
        temp.result = this->x * c.x;
        cout << "Multiplication Result: " << temp.result << endl;
        return temp;
    }

    Calculator operator/(Calculator c)
    {
        Calculator temp;
        if (c.x != 0)
        {
            temp.result = this->x / c.x;
            cout << "Division Result: " << temp.result << endl;
        }
        else
        {
            cout << "Division by zero error!" << endl;
            temp.result = 0;
        }
        return temp;
    }



    Calculator operator++()
    {
        ++result;
        cout << "Prefix Increment Result: " << result << endl;
        return *this;
    }


    Calculator operator++(int)
    {
        Calculator temp = *this;
        result++;
        cout << "Postfix Increment Result: " << result << endl;
        return temp;
    }


    Calculator operator--()
    {
        --result;
        cout << "Prefix Decrement Result: " << result << endl;
        return *this;
    }


    Calculator operator--(int)
    {
        Calculator temp = *this;
        result--;
        cout << "Postfix Decrement Result: " << result << endl;
        return temp;
    }


    bool operator==(Calculator c)
    {
        return (this->result == c.result);
    }
};

int main()
{
    Calculator c1(20, 10);
    Calculator c2(5, 2);


    Calculator add = c1 + c2;
    Calculator sub = c1 - c2;
    Calculator mul = c1 * c2;
    Calculator div = c1 / c2;


    ++add;
    add++;
    --add;
    add--;


    Calculator newObj = c1 + c2;


    newObj++;

    newObj.result += 100;
    cout << "New Object Result after +100: " << newObj.result << endl;

    
    if (newObj == add)
        cout << "New Object is EQUAL to add object" << endl;
    else
        cout << "New Object is NOT EQUAL to add object" << endl;

    return 0;
}
