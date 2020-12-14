#include "std_lib_facilities.hpp"

template<typename T> void print(T i) { cout << i << '\t'; }

void print(char i) { cout << int(i) << '\t'; }

void print(signed char i) { cout << int(i) << '\t'; }

void print(unsigned char i) { cout << int(i) << '\t'; }

int main()
try{
    int si = 128;
    char c = si; // implicit conversion to char
    unsigned char uc = si;
    signed char sc = si;
    print(si); print(c); print(uc); print(sc); cout << '\n';

    return 0;
}
catch (exception& e) {
    cerr << e.what() << '\n'; // write error message
    return 1;
}
catch (...) {
    cerr << "exception!\n"; // write error message
    return 2;
}
//Kamil Petk
//17.05.2020
