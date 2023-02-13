// Simple Calculator.

#include <iostream>
using namespace std;

void simpleCalculator(float num1, float num2, char oper){
    switch (oper) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '/':
            cout << num1 << " / " << num2 << " = " << num1 / num2;
            break;
        default:
            // operator doesn't match any case constant (+, -, *, /)
            cout << "Error! The operator is not correct";
            break;
    }
}

int main() {
    char oper;
    float num1, num2;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> oper;
    cout << "Enter two numbers: " << endl;
    cin >> num1 >> num2;
    simpleCalculator(num1, num2, oper);

    return 0;
}

/*INPUTS
/
1.3
9.2
*/