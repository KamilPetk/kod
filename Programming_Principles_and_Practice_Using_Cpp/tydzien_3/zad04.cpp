#include "std_lib_facilities.h"

class Rational {
public:
    Rational(int n, int d)
        : n(n), d(d) {};

    int numerator() { return n; }
    int denominator() { return d; }

    void convertDouble();
private:
    int n; // year
    int d;
    double result;

};

Rational operator+(Rational x, Rational y) { //adding
    if(x.denominator() == 0 || y.denominator() == 0)
    {
        cout << "Denominator equal 0" << endl;
        Rational R(0,0);
        return R;
    }
    else
    {
        int n = (x.numerator() * y.denominator()) + (y.numerator() * x .denominator());
        int d = x.denominator() * y.denominator();
        Rational R(n,d);
        return R;
    }

}

Rational operator-(Rational x, Rational y) { //subtraction
    if(x.denominator() == 0 || y.denominator() == 0)
    {
        cout << "Denominator equal 0" << endl;
        Rational R(0,0);
        return R;
    }
    else
    {
        int n = (x.numerator() * y.denominator()) - (y.numerator() * x .denominator());
        int d = x.denominator() * y.denominator();
        Rational R(n,d);
        return R;
    }
}

Rational operator/(Rational x, Rational y) { //division
    if(x.denominator() == 0 || y.denominator() == 0)
    {
        cout << "Denominator equal 0" << endl;
        Rational R(0,0);
        return R;
    }
    else
    {
        int n = x.numerator() * y.denominator();
        int d = x.denominator() * y.numerator();
        Rational R(n,d);
        return R;
    }
}

Rational operator*(Rational x, Rational y) { //multiplication
    if(x.denominator() == 0 || y.denominator() == 0)
    {
        cout << "Denominator equal 0" << endl;
        Rational R(0,0);
        return R;
    }
    else
    {
        int n = x.numerator() * y.numerator();
        int d = x.denominator() * y.denominator();
        Rational R(n,d);
        return R;
    }
}

// equality operator:
Rational operator==(Rational x, Rational y)
{
    if(x.denominator() == 0 || y.denominator() == 0)
    {
        cout << "Denominator equal 0" << endl;
    }
    else
    {
        if(x.denominator() == y.denominator())
            cout << "Are equal" << endl;
        else
            cout << "Are not equal" << endl;

    }
}

void Rational::convertDouble()
{
    result = double(n) / double(d);
    cout << result << endl;
}

ostream& operator<<(ostream& os, Rational& r)
{
 return os << r.numerator() << "/" << r.denominator();
}

int main()
try{

    Rational firstRational(1, 5);
    cout << "First rational number: " << firstRational << endl;
    Rational secondRational(2,3);
    cout << "Second rational number: " << secondRational;
    cout << endl;

    cout << "Addition result: " << endl;
    Rational result =  firstRational + secondRational;
    cout << result << " = " ;
    result.convertDouble();

    cout << "Subtraction result: " << endl;
    result =  firstRational - secondRational;
    cout << result << " = " ;
    result.convertDouble();

    cout << "Multiplication result: " << endl;
    result =  firstRational * secondRational;
    cout << result << " = " ;
    result.convertDouble();

    cout << "Division result: " << endl;
    result =  firstRational / secondRational;
    cout << result << " = " ;
    result.convertDouble();

    result =  firstRational == secondRational;

    keep_window_open();
}
catch (exception& e) {
    cerr << e.what() << '\n'; // write error message
    keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "exception!\n"; // write error message
    keep_window_open("~~");
    return 2;
}
//Dzieki stworzonym operatorom w latwy sposob mo¿na dokonac obliczen
//na liczbach wymiernych i uzyskac wynik w postaci ulamka zwyk³ego oraz dziesietnego
//Kamil Petk
//18.03.2020
