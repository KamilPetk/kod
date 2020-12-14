#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>
using namespace Numeric_lib;

using namespace std;

//book page 903
void firsttriple(int &d)
{
      d = d * 3;
}
//book page 903
int secondtriple(int d)
{
     return d*3;
}

int thirdtriple(int &d)
{
    return d*3;
}

int main()
try
{
    Matrix<int> a(5);

    for(int i = 0; i < 5; ++i)
        a[i] = i+1;
    cout << "Elements: " << endl;
    for(int i = 0; i < 5; ++i)
        cout << a[i] << endl;
    ////////////////////////////////
    a.apply(firsttriple);
    cout << "a.apply(firsttriple)" << endl;
        for(int i = 0; i < 5; ++i)
            cout << a[i] << endl;
    ////////////////////////////////
    Matrix<int> b = apply(secondtriple,a);
    cout << "b = apply(secondtriple,a)" << endl;
        for(int i = 0; i < 5; ++i)
            cout << b[i] << endl;
    ////////////////////////////////
    a.apply(thirdtriple);
    cout << "a.apply(thirdtriple)" << endl;
        for(int i = 0; i < 5; ++i)
            cout << a[i] << endl;
    ////////////////////////////////
    Matrix<int> c = apply(thirdtriple,a);
    cout << "c = apply(thirdtriple,a)" << endl;
        for(int i = 0; i < 5; ++i)
            cout << c[i] << endl;

    //Uzywanie apply do kazdej funkcji moze byc zlym pomyslem poniewaz istnieja rowniez
    //bardziej uzyteczne funkcje dostarczane przez biblioteke takie jak np. scale_and_add
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
