#include <iostream>
using namespace std;

int main()
{
    cout << "Eswar's Calculator" << endl;
    float num1, num2;
    char op;
    cin >> num1 >> op >> num2;

    switch (op)
    {
    case '+':cout << num1 + num2 << endl; break;
    case '-':cout << num1 - num2 << endl; break;
    case '*':cout << num1 * num2 << endl; break;
    case '/':cout << num1 / num2 << endl; break;
    case '%':
        bool isNum1Int, isNum2Int;
        isNum1Int = ((int)num1 == num1);
        isNum2Int = ((int)num2 == num2);

        if (isNum1Int && isNum2Int)
            cout << (int)num1 % (int)num2 << endl;
        else
            cout << "Not Valid" << endl;
        break;
    default:cout << "Invalid Operation" << endl; break;
    }
    system("pause>0");
}