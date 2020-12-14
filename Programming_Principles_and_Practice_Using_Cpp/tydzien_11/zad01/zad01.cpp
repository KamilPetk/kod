#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>
using namespace Numeric_lib;

using namespace std;

void calculateSqrt()
{
    int value;
    cout << "enter int value (if you want stop press q):" << endl;
    while(cin >> value)
    {
        errno = 0;
        double result = sqrt(value);
        if(errno) cerr << "something went wrong with something somewhere" << endl;
        if(errno == EDOM)
            cerr << "sqrt() not defined for negative argument" << endl;
        else
            cout << "sqrt(" << value << ") = " << result << endl;
    }
}

void floatpointMatrix()
{
    Matrix<double> myMatrix(10);
    double value;
    cout << "Enter 10 double values: " << endl;
    int i = 0;
    for(i; i < 10; ++i)
    {
        cin >> value;
        if( !cin )
        {
            cout << "This is not a number" << endl;
            --i;
            cin.clear();
            cin.sync();
        }
        else
            myMatrix[i] = value;
    }
    cout << myMatrix << endl;
}

void multiplicationTable()
{
    int n = 0;
    int m = 0;
    cout << "Press n (int):" << endl;
    bool good = 1;
    do
    {
        cin >> n;
        if( !cin ){
            cout << "This is not a number" << endl;
            cin.clear();
            cin.sync();
            good = false;
        }
        if( n <= 0 )
        {
            cout << "Enter value >0" << endl;
            cin.clear();
            cin.sync();
            good = false;
        }
        else good = true;

    }while( good == false );

    cout << "Press m (int):" << endl;
    good = 1;
    do
    {
        cin >> m;
        if( !cin ){
            cout << "This is not a number" << endl;
            cin.clear();
            cin.sync();
            good = false;
        }
        if( m <= 0 )
        {
            cout << "Enter value >0" << endl;
            cin.clear();
            cin.sync();
            good = false;
        }
        else good = true;

    }while( good == false );
//book page 900
    Matrix<int,2> myMatrix(n, m);
    for (int i=0; i<myMatrix.dim1(); ++i)
        for (int j = 0; j<myMatrix.dim2(); ++j)
            myMatrix(i,j) = i*j;

    for (int i=0; i<myMatrix.dim1(); ++i) {
        for (int j = 0; j<myMatrix.dim2(); ++j)
            cout << myMatrix(i,j) <<'\t';
        cout << '\n';
    }
}

void complexDouble()
{
    Matrix<complex<double>> myMatrix(10);
    cout << "Enter 10 complex values (Re,Im):" << endl;
    complex<double> value;

    int i = 0;
    complex<double> sum = (0,0);
    for(i; i < 10; ++i)
    {
        cin >> value;
        if( !cin )
        {
            cout << "This is not a number" << endl;
            --i;
            cin.clear();
            cin.sync();
        }
        else
        {
            myMatrix[i] = value;
            sum += myMatrix[i];
        }
    }
    cout << myMatrix << endl;
    cout << "Sum: " << sum << endl;
}
//book page 900
void sixMatrix()
{
    Matrix<int,2> m(2,3);
    int value;
    cout << "Enter 6 int values: " << endl;

    for (int i=0; i<m.dim1(); ++i)
        for (int j = 0; j<m.dim2(); ++j)
        {
            cin >> value;
            m(i,j) = value;
        }

    for (int i=0; i<m.dim1(); ++i) {
        for (int j = 0; j<m.dim2(); ++j)
            cout << m(i,j) <<'\t';
        cout << '\n';
    }
}

int main()
try
{
    //1.
    cout << "char size: " << sizeof(char) << endl;
    cout << "short size: " << sizeof(short) << endl;
    cout << "int size: " << sizeof(int) << endl;
    cout << "long size: " << sizeof(long) << endl;
    cout << "float size: " << sizeof(float) << endl;
    cout << "double size: " << sizeof(double) << endl;
    cout << "int* size: " << sizeof(int*) << endl;
    cout << "double* size: " << sizeof(double*) << endl;

    cout << endl;
    //2.
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);

    cout << "a size: " << sizeof(a) << endl;
    cout << "b size: " << sizeof(b) << endl;
    cout << "c size: " << sizeof(c) << endl;
    cout << "d size: " << sizeof(d) << endl;
    cout << "e size: " << sizeof(e) << endl;

    cout << endl;
    //3.
    cout << "a - number of elements: " << a.size() << endl;
    cout << "b - number of elements: " << b.size() << endl;
    cout << "c - number of elements: " << c.size() << endl;
    cout << "d - number of elements: " << d.size() << endl;
    cout << "e - number of elements: " << e.size() << endl;

    cout << endl;

    //4.
    calculateSqrt();
    cin.clear();
    cin.ignore();

    //5.
    floatpointMatrix();
    cin.clear();
    cin.ignore();

    //6.
    multiplicationTable();
    cin.clear();
    cin.ignore();

    //7.
    complexDouble();
    cin.clear();
    cin.ignore();

    //8.
    sixMatrix();

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
//16.05.2020
