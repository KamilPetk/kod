#include "std_lib_facilities.hpp"

template<typename T>
void check(const T& t)
{
    string test = "Hello";
    string test2 = "Howdy";
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

    i = 0;
    int what_is_first = 0; //0 test2, 1 p
    for(typename T::const_iterator p = t.begin(); p != t.end(); ++p)
    {
        if(*p < test[i])
        {
            what_is_first = 1;
            break;
        }
        if(*p > test[i])
        {
            what_is_first = 0;
            break;
        }
        else{}
    }
    if(what_is_first = 1)
        cout << "Hello will be first in dictionary" << endl;
    else cout << "Howdy will be first in dictionary" << endl;
}

void check_arr(const char arr[])
{
    char test[] = "Hello";
    cout << "Size = " << strlen(arr) << endl;
    if(strcmp(arr, "Hello") == 0)
        cout << "This is the same" << endl;
    else cout << "This is various" << endl;

    int what_is_first = 0; //0 arr, 1 test
    for(int i = 0; i < strlen(arr); ++i)
    {
        if(arr[i] < test[i])
        {
            what_is_first = 1;
            break;
        }
        if(arr[i] > test[i])
        {
            what_is_first = 0;
            break;
        }
        else{}
    }
    if(what_is_first = 1)
        cout << "Hello will be first in dictionary" << endl;
    else cout << "Howdy will be first in dictionary" << endl;
}

int main()
try{
    char arr[] = "Hello";
    vector<char> vec = {'H','e','l','l','o'};
    list<char> lis = {'H','e','l','l','o'};
    string str = "Hello";
    cout << "array" << endl;
    check_arr(arr);
    cout << endl;
    cout << "vector" << endl;
    check(vec);
    cout << endl;
    cout << "list" << endl;
    check(lis);
    cout << endl;
    cout << "string" << endl;
    check(str);
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
//03.05.2020
