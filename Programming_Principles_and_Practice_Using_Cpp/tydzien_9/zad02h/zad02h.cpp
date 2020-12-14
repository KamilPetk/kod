#include "std_lib_facilities.hpp"

template<typename T>
void check(const T& t)
{
    vector<int> test = {1,2,3,4,5};

    bool tf = true;
    int i = 0;

    for(typename T::const_iterator p = t.begin(); p != t.end(); ++p)
    {
        if(*p != test[i])
            tf = false;
        i++;
    }
    cout << "Size = " << i << endl;
    if(tf == true)
        cout << "This is the same" << endl;
    else cout << "This is various" << endl;
}

void check_arr(const int arr[], int sizeA)
{
    int test[] = {1,2,3,4,5};
    bool tf = true;
    int i = 0;
    cout << "Size = " << sizeA << endl;
    for(int i = 0; i < sizeA; ++i)
    {
        if(arr[i] != test[i])
            tf = false;
        i++;
    }
    if(tf == true)
        cout << "This is the same" << endl;
    else cout << "This is various" << endl;
}

int main()
try{

    int arr[] = {1,2,3,4,5};
    vector<int> vec = {1,2,3,4,5};
    list<int> lis = {1,2,3,4,5};

    cout << "array" << endl;
    check_arr(arr, sizeof(arr)/sizeof(int));
    cout << endl;
    cout << "vector" << endl;
    check(vec);
    cout << endl;
    cout << "list" << endl;
    check(lis);
    cout << endl;

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
//04.05.2020
