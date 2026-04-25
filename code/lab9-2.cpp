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
    int getResult() {
        return result;
    }
    void displayResult() {
        cout << "Result: " << result << endl;
    }
    friend Calculator operator+(Calculator c1, Calculator c2);
    friend Calculator operator-(Calculator c1, Calculator c2);
    friend Calculator operator*(Calculator c1, Calculator c2);
    friend Calculator operator/(Calculator c1, Calculator c2);
    friend Calculator operator++(Calculator &c);
    friend Calculator operator++(Calculator &c, int);
    friend Calculator operator--(Calculator &c);
    friend Calculator operator--(Calculator &c, int);
    friend bool operator==(Calculator c1, Calculator c2);
};

    Calculator operator+(Calculator c1, Calculator c2)
    {
        Calculator temp;
        temp.result = c1.x + c2.x;
        cout << "Addition Result: " << temp.result << endl;
        return temp;
    }
    Calculator operator-(Calculator c1, Calculator c2)
    {
        Calculator temp;
        temp.result = c1.x - c2.x;
        cout << "Subtraction Result: " << temp.result << endl;
        return temp;
    }
    Calculator operator*(Calculator c1, Calculator c2)
    {
        Calculator temp;
        temp.result = c1.x * c2.x;
        cout << "Multiplication Result: " << temp.result << endl;
        return temp;
    }
    Calculator operator/(Calculator c1, Calculator c2)
    {
        Calculator temp;
        if (c2.x != 0)
        {
            temp.result = c1.x / c2.x;
            cout << "Division Result: " << temp.result << endl;
        }
        else
        {
            cout << "Division by zero error!" << endl;
            temp.result = 0;
        }
        return temp;
    }
    Calculator operator++(Calculator &c)
    {
        ++c.result;
        cout << "Prefix Increment Result: " << c.result << endl;
        return c;
    }
    Calculator operator++(Calculator &c, int)
    {
        Calculator temp = c;
        c.result++;
        cout << "Postfix Increment Result: " << c.result << endl;
        return temp;
    }
    Calculator operator--(Calculator &c)
    {
        --c.result;
        cout << "Prefix Decrement Result: " << c.result << endl;
        return c;
    }
    Calculator operator--(Calculator &c, int)
    {
        Calculator temp = c;
        c.result--;
        cout << "Postfix Decrement Result: " << c.result << endl;
        return temp;
    }
    bool operator==(Calculator c1, Calculator c2)
    {
        return c1.result == c2.result;
    }
int main()

{
    Calculator c1(20,12), c2(10,5);

    Calculator add = c1 + c2;
    c1 - c2;
    c1 * c2;
    c1 / c2;

    Calculator newObj = add;

    newObj++;

    newObj.result += 100;
    cout << "New Object Result after +100: " << newObj.result << endl;

    
    if (newObj == c1 + c2)
        cout << "New Object is EQUAL to add object" << endl;
    else
        cout << "New Object is NOT EQUAL to add object" << endl;

    return 0;

}
