#include "std_lib_facilities.hpp"

double v_val; // the value to which larger_than_v() compares its argument
bool larger_than_v(double x) { return x>v_val; }
void f(list<double>& v, int x)
{
     v_val = 31; // set v_val to 31 for the next call of larger_than_v
     auto p = find_if(v.begin(), v.end(), larger_than_v);
     if (p!=v.end()) { cout << "FOUND value > 31" << endl; }
     v_val = x; // set v_val to x for the next call of larger_than_v
     auto q = find_if(v.begin(), v.end(), larger_than_v);
     if (q!=v.end()) { cout << "FOUND value > x" << endl; }
     // . . .
}

int main()
try{
    list<double> l {12.1, 29.2, 30.3, 32.4, 31.5};
    int x = 33.5;
    f(l, x);
    //Bledy moze powodowac:
    //1)v_val bedaca zmienna globalna
    //2)brak zainicjowania v_val
    //3)wynik v_val moze zostac zaburzony np. przez uzycie
    //  v_val w innej funkcji
    //3 aplikacje gdzie ten kod bylby szkodliwy:
    //1)aplikacja z duza iloscia funkcji porownujacych dane
    //2)aplikacja posiadajaca zmienne wystepujace tylko w okreslonych zakresach
    //3)aplikacja, ktora z zalozenia nie ma posiadac zmiennych globalnych

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
//05.05.2020
