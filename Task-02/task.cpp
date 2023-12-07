// Develop a calculator program that performs basic arithmetic
// operations such as addition, subtraction, multiplication, and
// division. Allow the user to input two numbers and choose an
// operation to perform.

#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char operation;

    // Get user input
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    std::cin >> num2;

    // Get the operation to perform
    cout << "Choose operation (+, -, *, /): ";
    cin >> operation;

    // Perform the selected operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            // Check for division by zero
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero.\n";
                return 1; // Exit program with an error code
            }
            break;
        default:
            cout << "Invalid operation.\n";
            return 1; // Exit program with an error code
    }

    // Display the result
    cout << "Result: " << result << endl;

    return 0;
}
