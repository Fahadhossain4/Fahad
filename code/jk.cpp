#include <iostream>
using namespace std;

class Sample {
    int x;

public:
    // Normal constructor
    Sample(int a = 0) {
        x = a;
        cout << "Constructor called. x = " << x << endl;
    }

    // Copy constructor
    Sample(const Sample &obj) {
        x = obj.x;
        cout << "Copy Constructor called. x = " << x << endl;
    }

    // Destructor
    ~Sample() {
        cout << "Destructor called. x = " << x << endl;
    }

    void show() {
        cout << "x = " << x << endl;
    }
};

// Function to demonstrate copy constructor
void display(Sample obj) {
    cout << "Inside function display()" << endl;
    obj.show();
}

int main() {
    cout << "Creating object obj1:" << endl;
    Sample obj1(10);   // Normal constructor

    cout << "\nAssigning obj1 to obj2:" << endl;
    Sample obj2;       // Normal constructor
    obj2 = obj1;       // Assignment (bitwise copy)

    cout << "\nPassing obj1 to function:" << endl;
    display(obj1);     // Copy constructor called

    cout << "\nEnd of main()" << endl;
    return 0;
}