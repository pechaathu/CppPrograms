// This program finds whether the triangle is an equilateral or isosceles or scalene, by taking the values of their sides as input

#include <iostream>
using namespace std;

void main()
{
    float a, b, c;
    cout << "Please enter the value of sides, a, b, c: " << endl;
    cin >> a >> b >> c;
    if (a == b && a == c)
        cout << "Equilateral triangle" << endl;
    else if (a != b && b != c && a != c)
        cout << "Scalene triangle" << endl;
    else
        cout << "Isosceles triangle" << endl;
    system("pause>0");
}