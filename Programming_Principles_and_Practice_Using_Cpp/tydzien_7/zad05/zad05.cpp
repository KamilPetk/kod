#include "std_lib_facilities.hpp"

ostream& print_array(ostream& os, int* a, int n)
{
    for (int i = 0; i < n; i++)
        os << a[i] << ", ";
    return os;
}

ostream& print_vector(ostream& os, vector<int>& a, int n)
{
    for (int i = 0; i < n; i++)
        os << a[i] << ", ";
    return os;
}

int main()
{
    int seven = 7;
    int* p1 = &seven; //book page 588
    cout << p1; //
    cout << endl;
    cout << *p1;//value
    cout << endl;
    //////////////////
    cout << endl;
    int* arraySeven = new int[7]; //book page 592
    int x = 1;
    for(int i = 0; i < 7; i++)
    {
        arraySeven[i] = x;
        x *= 2;
    }
    int* p2 = arraySeven;
    cout << "value of p2: ";
    print_array(cout, p2, 7);
    cout << endl;
    cout << "value of array: ";
    print_array(cout, arraySeven, 7);
    cout << endl;
    ////////////////////
    cout << endl;
    int* p3 = p2;
    p2 = p1;
    p2 = p3;
    cout << "p1: " << endl;
    cout << p1;
    cout << endl;
    cout << *p1;
    cout << endl;
    cout << "value of p2: ";
    print_array(cout, p2, 7);
    cout << endl;
    cout << *p2;
    ///////////////////
    delete[] arraySeven; //book page 602
    ///////////////////
    cout << endl;
    int* arrayTen = new int[10];
    int y = 1;
    for(int i = 0; i < 10; i++)
    {
        arraySeven[i] = y;
        y *= 2;
    }
    p1 = arrayTen;
    cout << endl;
    cout << "10. " << p1;
    cout << endl;
    ////////////////////
    cout << endl;
    int* arrayNextTen = new int[10];
    p2 = arrayNextTen;
    cout << "11. " << p2;
    cout << endl;
    ////////////////////
    cout << endl;
    cout << "Copy" << endl;
	for (int i = 0; i < 10; i++)
		*p2++ = *p1++; //copy
    print_array(cout, arrayNextTen, 10);
    delete[] arrayTen;
    delete[] arrayNextTen;
    ////////////////////
    cout << endl;
    cout << "VECTOR" << endl;
    vector<int> vectorTen(10);
    int m = 1;
    for(int i = 0; i < 10; i++)
    {
        vectorTen[i] = m;
        m *= 2;
    }

    vector<int>* pp1 = &vectorTen;
    cout << pp1;
    cout << endl;
    cout << "vector pp1: ";
    print_vector(cout, *pp1, 10);
    cout << endl;
    /////////////////////////
    cout << endl;
    vector<int> vectorNextTen(10);

    vector<int>* pp2 = &vectorNextTen;
    cout << "vector pp2: ";
    print_vector(cout, *pp2, 10);
    cout << endl;
    cout << pp2;
    cout << endl;
    /////////////////////////
    cout << endl;
    cout << "Copy" << endl;

    pp2 = pp1; //copy

    cout << "pp2 after copying: ";
    print_vector(cout, *pp2, 10);
    cout << endl;
    return 0;
}
//Kamil Petk
//14.04.2020
