#include "std_lib_facilities.hpp"

using namespace std;

const int array_size = 10;
int ga[10] = {1, 2 , 4, 8, 16, 32, 64, 128, 256, 512};


void f(int myArray[], int n)
{
    int la[10];
    //copy
    for(int i = 0; i < n; i++)
        la[i] = myArray[i];
    //print la
    cout << "la:" << endl;
    for(int i = 0; i < n; i++)
        cout << la[i] << endl;
    cout << endl;
    //////////////
    int* p = new int[n]; //page 657
    //copy
    for(int i = 0; i < n; i++)
        p[i] = myArray[i];
    //print p
    cout << "p:" << endl;
    for(int i = 0; i < n; i++)
        cout << p[i] << endl;
    //Deallocate
    delete[] p;
}



int main()
{
    f(ga, array_size);
    int aa[10];
    aa[0] = 1;
    for(int i = 1; i < 10; i++)
    {
        aa[i] = aa[i-1]*(i+1);
        aa[i+1] = aa[i];
    }
    ///////////
    cout << endl;
    cout << "4.c:" << endl;
    f(aa, 10);
    return 0;
}
//Kamil Petk
//21.04.2020
