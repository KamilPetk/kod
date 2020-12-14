/* pseudo code

    procedure factorial(x : integer)
    begin
    for(x; x>=1; x--)
        calculate
    write_result
    emd
    procedure permutation(a : integer, b : integer)
    begin
        calculate
    end
    procedure combination(a : integer, b : integer)
    begin
        calculate
    end
    begin
        read(a);
        read(b);
        check the warnings
       Permutation(a,b)
       Combination(a,b)
    end

*/

#include "std_lib_facilities.hpp"

int factorial(int x)
{
    int result = 1;
    for(x; x>=1; x--)
        result *= x;
    return result;
}

double permutation(int a, int b)
{
    double P = factorial(a)/(factorial(a-b));
    return P;
}

double combination(int a, int b)
{
    double C = permutation(a, b)/factorial(b);
    return C;
}

int main()
try
{
    int a;
    int b;
    char ch;
    cout << "Please enter two integral values >0 and the first must be larger than the second: \n";
    cin >> a >> b;
    if(a <= 0 || b <= 0) cout << "Error: you entered values <=0";
    cout << "If you want to calculate permutation press p.\nIf you want to calculate combination press c.\n";
    cin >> ch;
    if(ch == 'p') cout << "Result= " << permutation(a, b);
    else if(ch == 'c') cout << "Result= " << combination(a, b);
    else cout << "You pressed the wrong button.";

    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
	keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
	keep_window_open();
    return 2;
}
//Kamil Petk
//09.03.2020
