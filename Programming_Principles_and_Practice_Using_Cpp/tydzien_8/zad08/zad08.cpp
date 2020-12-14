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

////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T, typename A>Number<T> operator+=(Number<T>& x, const Number<A>& y)
{
    T sum = x.get() + y.get();
    Number<T> suma(sum);
    //cout << sum << endl;
    x = suma;
    return x;
}

template<typename T, typename U> T sumVec(const vector<T>& vt, const vector<U>& vu) // function template
{
    if(vt.size() == vu.size())
    {
        T sum = 0.0;
        for (int i = 0; i<vt.size(); ++i)
        {
            sum += vt[i] * vu[i]; //przy pierwszej probie pojawil sie komunikat o braku operatora+= wiec dodalem go powyzej
            //cout << sum << endl;
        }

        return sum;
    }
    else
        return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
try
{
    vector<Number<int>> v1 {1, 2, 3};
    vector<Number<int>> v2 {1, 2, 3};

    Number<int> sum = sumVec(v1, v2);
    cout << "Sum +=v1[i] * v2[i] = " << sum << endl;
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
