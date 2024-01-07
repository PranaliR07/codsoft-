#include <iostream>
using namespace std;

int main()
{
    char op; // operator
    double num1, num2; // operands
    cout << "Enter an operator choice (1, 2, 3, 4): ";
    cin >> op;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    switch (op)
    {
    case '1':
        cout << "The sum is " << num1 + num2 << endl;
        break;
    case '2':
        cout << "The difference is " << num1 - num2 << endl;
        break;
    case '3':
        cout << "The product is " << num1 * num2 << endl;
        break;
    case '4':
        if (num2 == 0)
        {
            cout << "Cannot divide by zero" << endl;
        }
        else
        {
            cout << "The quotient is " << num1 / num2 << endl;
        }
        break;
    default:
        cout << "Invalid operator" << endl;
        break;
    }

    return 0;
}

