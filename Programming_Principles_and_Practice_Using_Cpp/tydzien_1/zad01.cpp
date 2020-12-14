#include "std_lib_facilities.hpp"

int main()
{
    //Exercise 4
    int val1; int val2;

    cout << "Enter first integer value: ";
    cin >> val1;
    cout << "Enter second integer value: ";
    cin >> val2;

    if(val1>val2)
    {
        cout << "Smaller is " << val2 << "\n";
        cout << "Larger is " << val1 << "\n";
    }
    else if(val1<val2)
    {
        cout << "Smaller is " << val1 << "\n";
        cout << "Larger is " << val2 << "\n";
    }
    else if(val1==val2)
        cout << "values are equal";

    cout << "sum = " << val1+val2 << "\n";
    cout << "difference = " << val1 - val2 << "\n";
    cout << "product = " << val1*val2 << "\n";
    if(val2!=0)
    cout << "ratio = " << val1/val2 << "\n";
    else
        simple_error("denominator = 0");

    //Exercise 5
    double val3; double val4;

    cout << "Enter first floating-point value: ";
    cin >> val3;
    cout << "Enter second floating-point value: ";
    cin >> val4;

    if(val3>val4)
    {
        cout << "Smaller is " << val4 << "\n";
        cout << "Larger is " << val3 << "\n";
    }
    else if(val3<val4)
    {
        cout << "Smaller is " << val3 << "\n";
        cout << "Larger is " << val4 << "\n";
    }
    else if(val3==val4)
        cout << "values are equal";

    cout << "sum = " << val3+val4 << "\n";
    cout << "difference = " << val3 - val4 << "\n";
    cout << "product = " << val3*val4 << "\n";
    if(val2!=0)
    cout << "ratio = " << val3/val4 << "\n";
    else
        simple_error("denominator = 0");
}
//Comparision:
//Results not the same.
//Double is more precise.

//Kamil Petk 27.02.2020
