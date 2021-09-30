#include <iostream>
using namespace std;

void main()
{
    int a;
    cout << "Please enter a number: ";
    cin >> a;
    if (a % 2 == 0)
    {
        cout << "The number " << a << " is an Even number" << endl;
    }
    else
    {
        cout << "The number " << a << " is an Odd number" << endl;
    }
    system("pause>0");
}
