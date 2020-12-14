#include "std_lib_facilities.hpp"

//Static storage
int a_global = 5;
int b_global = 7;

int main()
{
    cout << "Static storage:" << endl;
    cout << "1." << &a_global << endl;
    cout << "2." << &b_global << endl;

    //Free store:
    int* a_free = new int(5);
    int* b_free = new int(7);
    cout << "Free store:" << endl;
    cout << "1." << &a_free[0] << endl;
    cout << "2." << &b_free[1] << endl;
    delete a_free;
    delete b_free;

    //Stack storage
    int a_stack = 5;
    int b_stack = 7;
    cout << "Stack storage:" << endl;
    cout << "1." << &a_stack << endl;
    cout << "2." << &b_stack << endl;

    //Array (free store)
    int* p = new int[10];
    for(int i = 0; i < 10; i++)
    {
        p[0] = i;
    }
    cout << "Array (free store)" << endl;
    for(int i = 0; i < 10; i++)
        cout << i+1 << "." << &p[i] << endl;
    delete[] p;
    return 0;
}
//Kamil Petk
//23.04.2020
