#include <iostream>
#include <string>

// Abstract base class Employee
class Employee {
protected:
    std::string name;  // Common attribute for all employees
public:
    Employee(std::string n) : name(n) {}
    virtual ~Employee() {}  // Virtual destructor for proper cleanup
    virtual double getAmount() = 0;  // Pure virtual function
    std::string getName() { return name; }
};

// Derived class for hourly employees
class HourlyEmployee : public Employee {
private:
    int hoursWorked;
    double ratePerHour;
public:
    HourlyEmployee(std::string n, int h, double r) : Employee(n), hoursWorked(h), ratePerHour(r) {}
    double getAmount() override {
        return hoursWorked * ratePerHour;
    }
};

// Derived class for weekly employees
class WeeklyEmployee : public Employee {
private:
    int weeksWorked;
    double paymentPerWeek;
public:
    WeeklyEmployee(std::string n, int w, double p) : Employee(n), weeksWorked(w), paymentPerWeek(p) {}
    double getAmount() override {
        return weeksWorked * paymentPerWeek;
    }
};

// Function that accepts an Employee object as argument (by reference)
void printEmployeePayment(const Employee& emp) {
    std::cout << "Employee: " << emp.getName() << " earns $" << emp.getAmount() << std::endl;
}

// Function that returns an Employee object (using pointer for polymorphism)
Employee* createEmployee(bool isHourly) {
    if (isHourly) {
        return new HourlyEmployee("John Doe", 40, 15.0);  // 40 hours at $15/hour
    } else {
        return new WeeklyEmployee("Jane Smith", 4, 600.0);  // 4 weeks at $600/week
    }
}

int main() {
    // Create objects
    HourlyEmployee hourlyEmp("Alice", 30, 20.0);  // 30 hours at $20/hour
    WeeklyEmployee weeklyEmp("Bob", 2, 500.0);    // 2 weeks at $500/week

    // Use base class pointer to access derived class objects
    Employee* empPtr;

    empPtr = &hourlyEmp;
    std::cout << "Using base class pointer: ";
    printEmployeePayment(*empPtr);

    empPtr = &weeklyEmp;
    std::cout << "Using base class pointer: ";
    printEmployeePayment(*empPtr);

    // Function that returns an Employee object
    Employee* newEmp = createEmployee(true);  // Create hourly employee
    printEmployeePayment(*newEmp);
    delete newEmp;  // Clean up

    newEmp = createEmployee(false);  // Create weekly employee
    printEmployeePayment(*newEmp);
    delete newEmp;  // Clean up

    return 0;
}
