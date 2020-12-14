#include "std_lib_facilities.hpp"

class Int
{
public:
    Int(){}
    Int(int variable)
        :variable(variable){}

    Int& operator=(const Int& var);
    int get() const;

private:
    int variable;
};

Int& Int::operator=(const Int& var)
{
    variable = var.variable;
    return *this; //page 676
}

Int::get() const
{
    return variable;
}

ostream& operator<<(ostream& os, Int& i)
{
    return os << i.get();
}

istream& operator>>(istream& is, Int& i)
{
    int myNewVar = 0;
    is >> myNewVar;
    i = myNewVar;

    return is;
}

Int operator+(Int& x, Int& y)
{
    int result = 0;
    result = x.get() + y.get();
    return result;
}

Int operator-(Int& x, Int& y)
{
    int result = 0;
    result = x.get() - y.get();
    return result;
}

Int operator*(Int& x, Int& y)
{
    int result = 0;
    result = x.get() * y.get();
    return result;
}

Int operator/(Int& x, Int& y)
{
    int result = 0;
    result = x.get() / y.get();
    return result;
}

int main()
try
{
    Int var1;
    Int var2 = 2;
    //test assignment
    var1 = var2;
    //test get()
    cout << "test get()" << endl;
    cout << "var1 = " << var1.get() << endl;
    cout << "var2 = " << var2.get() << endl;
    //test operator>>
    cout << "test operator>>" << endl;
    cout << "Enter the value int:" << endl;
    Int var3;
    cin >> var3;
    cout << "var3 = " << var3 << endl;
    ///////////////////////
    cout << "operators test +,-,*,/ (var1 and var2):" << endl;
    //test operator+
    Int var4 = var1 + var2;
    //test operator<<
    cout << "test operator+ \n" << var4 << endl;
    //test operator-
    Int var5 = var1 - var2;
    cout << "test operator- \n" << var5 << endl;
    //test operator*
    Int var6 = var1 * var2;
    cout << "test operator* \n" << var6 << endl;
    //test operator/
    Int var7 = var1 / var2;
    cout << "test operator/ \n" << var7 << endl;

    return 0;
}
catch (exception& e) {
    cerr << e.what() << '\n';
    keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "exception!\n";
    keep_window_open("~~");
    return 2;
}
//Kamil Petk
//25.04.2020
