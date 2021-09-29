#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the number: ";
    int number;
    cin >> number;
    
    if (number == 0)
        cout << "You have entered 0";
    else
    {
        int counter = 0;
        while (number != 0)
        {
            number /= 10;
            counter++;
        }
        cout << counter << " digits";
    }
    system("pause>0");
}