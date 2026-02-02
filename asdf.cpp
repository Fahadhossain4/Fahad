#include <iostream>
using namespace std;

// Calculator class with three variables
class Calculator {
private:
    // Three variables as required
    double operand1;  // First number for operations
    double operand2;  // Second number for operations
    double result;    // Stores the result of operations

public:
    // Constructor - initializes the calculator
    Calculator(double op1 = 0, double op2 = 0) {
        operand1 = op1;
        operand2 = op2;
        result = 0;
    }
    
    // Setter functions to set values
    void setOperand1(double value) {
        operand1 = value;
    }
    
    void setOperand2(double value) {
        operand2 = value;
    }
    
    void setResult(double value) {
        result = value;
    }
    
    // Getter functions to get values
    double getOperand1() {
        return operand1;
    }
    
    double getOperand2() {
        return operand2;
    }
    
    double getResult() {
        return result;
    }
    
    // ============ BINARY OPERATIONS ============
    
    // Addition: operand1 + operand2
    double add() {
        result = operand1 + operand2;
        cout << "Addition: " << operand1 << " + " << operand2 << " = " << result << endl;
        return result;
    }
    
    // Subtraction: operand1 - operand2
    double subtract() {
        result = operand1 - operand2;
        cout << "Subtraction: " << operand1 << " - " << operand2 << " = " << result << endl;
        return result;
    }
    
    // Multiplication: operand1 * operand2
    double multiply() {
        result = operand1 * operand2;
        cout << "Multiplication: " << operand1 << " * " << operand2 << " = " << result << endl;
        return result;
    }
    
    // Division: operand1 / operand2
    double divide() {
        if (operand2 == 0) {
            cout << "Error: Cannot divide by zero!" << endl;
            result = 0;
        } else {
            result = operand1 / operand2;
            cout << "Division: " << operand1 << " / " << operand2 << " = " << result << endl;
        }
        return result;
    }
    
    // ============ UNARY OPERATIONS ============
    
    // Prefix Increment: ++result
    // Increments FIRST, then returns the new value
    double prefixIncrement() {
        ++result;  // Increment first
        cout << "Prefix Increment: ++result = " << result << endl;
        return result;
    }
    
    // Postfix Increment: result++
    // Returns the OLD value, then increments
    double postfixIncrement() {
        double oldValue = result;  // Save old value
        result++;  // Increment after
        cout << "Postfix Increment: result++ (old value: " << oldValue 
             << ", new value: " << result << ")" << endl;
        return oldValue;  // Return the old value
    }
    
    // Prefix Decrement: --result
    // Decrements FIRST, then returns the new value
    double prefixDecrement() {
        --result;  // Decrement first
        cout << "Prefix Decrement: --result = " << result << endl;
        return result;
    }
    
    // Postfix Decrement: result--
    // Returns the OLD value, then decrements
    double postfixDecrement() {
        double oldValue = result;  // Save old value
        result--;  // Decrement after
        cout << "Postfix Decrement: result-- (old value: " << oldValue 
             << ", new value: " << result << ")" << endl;
        return oldValue;  // Return the old value
    }
    
    // ============ HELPER FUNCTIONS ============
    
    // Add a value to the current result
    double addToResult(double value) {
        result += value;
        cout << "Added " << value << " to result: " << result << endl;
        return result;
    }
    
    // Check if two calculators have equal results
    bool equals(Calculator &other) {
        bool isEqual = (result == other.result);
        cout << "Comparison: " << result << " == " << other.result 
             << " -> " << (isEqual ? "True" : "False") << endl;
        return isEqual;
    }
    
    // Display calculator information
    void display() {
        cout << "Calculator(operand1=" << operand1 
             << ", operand2=" << operand2 
             << ", result=" << result << ")" << endl;
    }
};

// Main function
int main() {
    cout << "============================================================" << endl;
    cout << "            CALCULATOR DEMONSTRATION (C++)                  " << endl;
    cout << "============================================================" << endl;
    
    // ===== PART 1: BINARY OPERATIONS =====
    cout << "\n--- Creating calc1 with values 15 and 5 ---" << endl;
    Calculator calc1(15, 5);
    calc1.display();
    
    cout << "\n--- BINARY OPERATIONS ---" << endl;
    calc1.add();           // 15 + 5 = 20
    calc1.subtract();      // 15 - 5 = 10
    calc1.multiply();      // 15 * 5 = 75
    calc1.divide();        // 15 / 5 = 3
    
    // ===== PART 2: UNARY OPERATIONS =====
    cout << "\n--- Creating calc2 for unary operations ---" << endl;
    Calculator calc2;
    calc2.setResult(10);  // Set result to 10
    cout << "Initial result = " << calc2.getResult() << endl;
    
    cout << "\n--- UNARY OPERATIONS ---" << endl;
    calc2.prefixIncrement();   // ++10 = 11
    calc2.postfixIncrement();  // 11++ returns 11, becomes 12
    calc2.prefixDecrement();   // --12 = 11
    calc2.postfixDecrement();  // 11-- returns 11, becomes 10
    
    // ===== PART 3: SPECIAL SEQUENCE (AS PER REQUIREMENTS) =====
    cout << "\n============================================================" << endl;
    cout << "           SPECIAL SEQUENCE (REQUIREMENTS)                  " << endl;
    cout << "============================================================" << endl;
    
    // Step 1: Create calc3 and perform addition
    cout << "\nStep 1: Create calc3 and perform addition" << endl;
    Calculator calc3(25, 75);
    calc3.display();
    double additionResult = calc3.add();  // 25 + 75 = 100
    
    // Step 2: Assign result to a new object
    cout << "\nStep 2: Create newCalc with the addition result" << endl;
    Calculator newCalc;
    newCalc.setResult(additionResult);
    newCalc.display();
    
    // Step 3: Perform postfix increment on new object
    cout << "\nStep 3: Perform postfix increment on newCalc" << endl;
    double oldValue = newCalc.postfixIncrement();  // Returns 100, becomes 101
    
    // Step 4: Add 100 to the result
    cout << "\nStep 4: Add 100 to newCalc result" << endl;
    newCalc.addToResult(100);  // 101 + 100 = 201
    
    // Step 5: Create comparison object and check equality
    cout << "\nStep 5: Create comparison object with result = 201" << endl;
    Calculator comparisonCalc;
    comparisonCalc.setResult(201);
    comparisonCalc.display();
    
    cout << "\nStep 6: Check if newCalc equals comparisonCalc" << endl;
    newCalc.equals(comparisonCalc);  // Should be True (201 == 201)
    
    cout << "\nBonus: Compare newCalc with calc3" << endl;
    newCalc.equals(calc3);  // Should be False (201 != 100)
    
    // ===== FINAL STATE =====
    cout << "\n============================================================" << endl;
    cout << "              FINAL STATE OF ALL OBJECTS                    " << endl;
    cout << "============================================================" << endl;
    cout << "calc1: "; calc1.display();
    cout << "calc2: "; calc2.display();
    cout << "calc3: "; calc3.display();
    cout << "newCalc: "; newCalc.display();
    cout << "comparisonCalc: "; comparisonCalc.display();
    cout << "============================================================" << endl;
    
    return 0;
}