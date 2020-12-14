#include "std_lib_facilities.hpp"
void copyy(int* f1, int* e1, int* f2)
{
    for(int *p = f1; p != e1; p++)
        *f2++ = *f1++;
}
int main()
try{
    array<int, 5> a1 = {0,1,2,3,4};
    array<int, 5> a2;
    copyy(a1.begin(), a1.end(),a2.begin());
    for(const int& i: a2)
        cout << i << endl;
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
