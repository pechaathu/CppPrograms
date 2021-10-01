#include <iostream>
using namespace std;

int main()
{
    int num, rnum=0;
    cout << "Enter a number: ";
    cin >> num;
    
    while (num > 0)
    {
        rnum *= 10;
        rnum = (num % 10) + rnum;
        num /= 10;
    }
    cout << "Reversed number: " << rnum << endl;

    system("pause>0");
}