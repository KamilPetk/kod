#include "std_lib_facilities.hpp"

template<typename T>
void printThis(T test)
{
    cout << bitset<32>(test) << " = " << test << endl;
}

int main()
try{
    cout << "signed integer:" << endl;
    signed int test1 = 0x0;
    printThis(test1);
    test1 = ~test1;
    printThis(test1);
    test1 = 0xaaaaaaaa;
    printThis(test1);
    test1 = ~test1;
    printThis(test1);
    //110011001100
    test1 = 0xcccccccc;
    printThis(test1);
    //001100110011
    test1 = 0x33333333;
    printThis(test1);
    test1 = 0x0f0f0f0f;
    printThis(test1);
    test1 = 0xf0f0f0f0;
    printThis(test1);

    cout << "unsigned integer:" << endl;
    unsigned int test2 = 0x0;
    printThis(test2);
    test2 = ~test2;
    printThis(test2);
    test2 = 0xaaaaaaaa;
    printThis(test2);
    test2 = ~test2;
    printThis(test2);
    //110011001100
    test2 = 0xcccccccc;
    printThis(test2);
    //001100110011
    test2 = 0x33333333;
    printThis(test2);
    test2= 0x0f0f0f0f;
    printThis(test2);
    test2 = 0xf0f0f0f0;
    printThis(test2);
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
