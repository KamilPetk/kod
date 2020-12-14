#include "std_lib_facilities.hpp"

template<typename T> struct S
{
    S(T t):
        val(t){};

     T& get(); //zwraca referencje do T
     //T get();//zwraca kopie T

     void set(const T& t);
     S& operator=(const T&);

     const T& get() const;

 private:
    T val;
};

template<typename T>T& S<T>::get()
{
    return val;
}

template<typename T>void S<T>::set(const T& t)
{
    val = t;
}

template<typename T>S<T>& S<T>::operator=(const T& t)
{
    val = t;
    return *this; //19.2.5
}

template<typename T>const T& S<T>::get() const
{
    return val;
}

template<typename T>istream& operator>>(istream& is, vector<T>& t)
{
    char myChar;
    is >> myChar;
    //{val, val, val}
    if(myChar != '{')
    {
        is.unget(); //zwraca z powrotem do stumienia
        return is;
    }
    T value;
    char comma;
    while(cin >> value >> comma)
    {
        t.push_back(value);
        if(comma == '}' || comma != ',')
            break;
    }
    return is;
}

template<typename T> void read_val(T& v)
{
    cin >> v;
}

template<typename T>ostream& operator<<(ostream& os, const vector<T>& t)
{
    for(int i = 0; i < t.size(); i++)
    {
        os << t[i];
        os << ", ";
    }

    return os;
}



int main()
{
    S<int> s1(1);
    S<char> s2('a');
    S<double> s3(2.2);
    S<string> s4("text");
    S<vector<int>> s5(vector<int>{1,2,3});

    /*
    cout << s1.val << endl;
    cout << s2.val << endl;
    cout << s3.val << endl;
    cout << s4.val << endl;
    for(int i = 0; i < s5.val.size(); i++)
        cout << s5.val[i] << ", ";
    */

    cout << s1.get() << endl;
    cout << s2.get() << endl;
    cout << s3.get() << endl;
    cout << s4.get() << endl;
    for(int i = 0; i < s5.get().size(); i++)
        cout << s5.get()[i] << ", ";

    cout << endl;
    cout << endl << "set:" << endl;
    s1.set(2);
    s2.set('b');
    s3.set(3.3);
    s4.set("text2");
    cout << s1.get() << endl;
    cout << s2.get() << endl;
    cout << s3.get() << endl;
    cout << s4.get() << endl;

    cout << endl;
    cout << "operator=" << endl;
    s1 = 3;
    s2 = 'c';
    s3 = 4.4;
    s4 = "text3";
    s5.get()[0] = 4;
    s5.get()[1] = 5;
    s5.get()[2] = 6;
    cout << s1.get() << endl;
    cout << s2.get() << endl;
    cout << s3.get() << endl;
    cout << s4.get() << endl;
    for(int i = 0; i < s5.get().size(); i++)
        cout << s5.get()[i] << ", ";
    cout << endl;

    cout << "get() const:" << endl;
    const S<int> s6(4);
    const S<double> s7(5.5);
    cout << s6.get() << endl;
    cout << s7.get() << endl;
///////////////////////////////////////////
    cout << endl << "read_val():" << endl;
    int s11;
    char s22;
    double s33;
    string s44;

    cout << "int: ";
    read_val(s11);
    cout << "char: ";
    read_val(s22);
    cout << "double: ";
    read_val(s33);
    cout << "string: ";
    read_val(s44);

    S<int> s1new(s11);
    S<char> s2new(s22);
    S<double> s3new(s33);
    S<string> s4new(s44);

    cout << s1new.get() << endl;
    cout << s2new.get() << endl;
    cout << s3new.get() << endl;
    cout << s4new.get() << endl;
///////////////////////////////////////////
    cout << s5.get(); //operator <<
///////////////////////////////////////////
    //operator >>
    cout << endl;
    vector<int> test_operator;
    cout << "Enter: ( {val, val, val} )" << endl;
    read_val(test_operator);
    S<vector<int>> wektor_test{test_operator};
    cout << "Vector: " << wektor_test.get() << '\n';
    return 0;
}
//Kamil Petk
//23.04.2020
