#include "std_lib_facilities.hpp"
template<typename T> class Number
{
    T variable;

public:
    Number():
        variable(T()){}
    Number(T t):
        variable(t){};

    T get() const
    {
        return variable;
    }

     Number& operator=(const T&);
};

template<typename T>Number<T>& Number<T>::operator=(const T& t)
{
    variable = t;
    return *this;
}

template<typename T>ostream& operator<<(ostream& os, const Number<T>& n)
{
    return os << n.get();
}

template<typename T>istream& operator>>(istream& is, Number<T>& n)
{
    T myNewVar = 0;
    is >> myNewVar;
    n = myNewVar;

    return is;
}

template<typename T, typename A>Number<T> operator+(const Number<T>& x, const Number<A>& y)
{
    return x.get() + y.get();
}

template<typename T, typename A>Number<T> operator-(const Number<T>& x, const Number<A>& y)
{
    return x.get() - y.get();
}

template<typename T, typename A>Number<T> operator*(const Number<T>& x, const Number<A>& y)
{
    return x.get() * y.get();
}

template<typename T, typename A>Number<T> operator/(const Number<T>& x, const Number<A>& y)
{
    return x.get() / y.get();
}

template<typename T, typename A>Number<T> operator%(const Number<T>& x, const Number<A>& y)
{
    return int(x.get()) % int(y.get());
}

int main()
try
{
    //test
    Number<double> n1(12.2);
    cout << "n1 = " << n1 << endl;
    Number<int> n2;
    //cout << "n2 = " << n2 << endl;
    n2 = 5;
    cout << "n2 = " << n2 << endl;

    cout << "operator+ " << "n1+n2=" << n1+n2 << endl;
    cout << "operator- " << "n1-n2=" << n1-n2 << endl;
    cout << "operator* " << "n1*n2=" << n1*n2 << endl;
    cout << "operator/ " << "n1/n2=" << n1/n2 << endl;

    cout << "TEST operator>> Enter value:" << endl;
    Number<double> n5;
    cin >> n5;
    cout << n5 << endl;
    cout << "operator % (int) " <<  "n1%n2=" << n1%n2 << endl;

    Number<double> try1(13.2);
    Number<int> try2(5);
    cout << "operator % (double) and (int) " << try1.get() << " % " << try2.get() << " = " << try1%try2 << endl;
    //Wymusilem int w operatorze % poniewaz w innym wypadku zwracany by³ komunikat: "error: invalid operands of types 'int' and 'double' to binary 'operator%'
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
//26.04.2020
