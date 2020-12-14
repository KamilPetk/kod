#include "std_lib_facilities.hpp"

template<typename In, typename T>
 // requires Input_iterator<In>()
 // && Equality_comparable<Value_type<T>>() (§19.3.3)
In find_1(In first, In last, const T& val)
 // find the first element in [first,last) that equals val
{
    while (first!=last && *first != val) ++first;
    return first;
}

template<typename In, typename T>
 // requires Input_iterator<In>()
 // && Equality_comparable<Value_type<T>>() (§19.3.3)
In find_2(In first, In last, const T& val)
 // find the first element in [first,last) that equals val
{
    for (In p = first; p!=last; ++p)
    if (*p == val) return p;
    return last;
}

int main()
try{
    //TEST
    cout << "TEST VECTOR" << endl;
    vector<int> v;
    for(int i = 0; i < 10; ++i)
        v.push_back(i);
    int x = 5;

    auto f_1 = find_1(v.begin(), v.end(), x);
    cout << "f_1: " << *f_1 << endl;

    auto f_2 = find_2(v.begin(), v.end(), x);
    cout << "f_2: " << *f_2 << endl;

    if(f_1 == f_2)
        cout << "f_1 and f_2 are the same" << endl;
    else
        cout << "f_1 and f_2 are different" << endl;

    cout << endl;;
    cout << "TEST LIST" << endl;

    list<double> l {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8};

    double y = 0.2;

    auto ff_1 = find_1(l.begin(), l.end(), y);
    cout << "f_1: " << *ff_1 << endl;

    auto ff_2 = find_2(l.begin(), l.end(), y);
    cout << "f_2: " << *ff_2 << endl;

    if(ff_1 == ff_2)
        cout << "f_1 and f_2 are the same" << endl;
    else
        cout << "f_1 and f_2 are different" << endl;

    return 0;
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
//Kamil Petk
//05.05.2020
