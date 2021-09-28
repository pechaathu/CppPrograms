#include <iostream>
using namespace std;

int main()
{
    float w, h, bmi;
    cout << "Enter your weight (in kg): ";
    cin >> w;
    cout << "Enter your height (in m): ";
    cin >> h;
    bmi = w / (h * h);
    if (bmi < 18.5)
        cout << "Underweight";
    else if (bmi >25)
        cout << "Overweight";
    else
        cout << "Normal";
    cout << "Your BMI is: " << bmi << endl;
    system("pause>0");
}