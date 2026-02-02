#include <iostream>
using namespace std;

class Calculator {
public:
    int a, b, result;


    Calculator(int x = 0, int y = 0) {
        a = x;
        b = y;
        result = 0;
    }

    Calculator operator+(Calculator c) {
        Calculator temp;
        temp.result = a + c.a;
        return temp;
    }

    Calculator operator-(Calculator c) {
        Calculator temp;
        temp.result = a - c.a;
        return temp;
    }

    Calculator operator*(Calculator c) {
        Calculator temp;
        temp.result = a * c.a;
        return temp;
    }

    Calculator operator/(Calculator c) {
        Calculator temp;
        if (c.a != 0)
            temp.result = a / c.a;
        else
            temp.result = 0;
        return temp;
    }

    Calculator operator++() {
        ++result;
        return *this;
    }

    Calculator operator++(int) {
        Calculator temp = *this;
        result++;
        return temp;
    }

    Calculator operator--() {
        --result;
        return *this;
    }

    Calculator operator--(int) {
        Calculator temp = *this;
        result--;
        return temp;
    }

    bool operator==(Calculator c) {
        return result == c.result;
    }

    void display(string msg) {
        cout << msg << result << endl;
    }
};

int main() {
    Calculator c1(20), c2(10);

    Calculator add = c1 + c2;
    add.display("Addition Result: ");

    Calculator sub = c1 - c2;
    sub.display("Subtraction Result: ");

    Calculator mul = c1 * c2;
    mul.display("Multiplication Result: ");

    Calculator div = c1 / c2;
    div.display("Division Result: ");

    Calculator newObj = add;

    newObj++;
    newObj.display("After Postfix Increment: ");

    newObj.result += 100;
    newObj.display("After Adding 100: ");

    if (newObj == add)
        cout << "New object is equal to addition result object." << endl;
    else
        cout << "New object is NOT equal to addition result object." << endl;

    return 0;
}
