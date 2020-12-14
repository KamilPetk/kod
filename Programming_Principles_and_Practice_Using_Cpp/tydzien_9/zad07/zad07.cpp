#include "std_lib_facilities.hpp"

template<typename Vec, typename T>//page 796
bool binary_search_vec(Vec first, Vec last, const T& val)
{
    //zgodnie z wyszukiwaniem binarnym "dziele" ilosc
    //elementow na 2 przedzialy(lewy, prawy)
    if(first == last) //sprawdzenie czy nie jest pusty
            return false;
    else
    {
        Vec p = first + (last - first) / 2;
        if(*p == val)
            return true; //znaleziono
        if(*p < val && p + 1 != last) //wymaga sprawdzenia dodatkowego warunku
            return binary_search_vec(p, last, val); //ponow szukanie
        if(*p > val)
            return binary_search_vec(first, p, val); //ponow szukanie
        else
            return false; //nie znaleziono
    }
}

template<typename Lis>
Lis calculate(Lis first, Lis last)
{
    int x = 0; //zmienna przechowujaca informacje o ilosci elementow
    Lis p = first;
    while( p != last)
    {
        p++;
        x++;
    }
    //cout << x << endl;
    //cout << *first << " " << x << endl;
    x = x/2;
    advance(first, x); //"przeskakuje" z first o 'x' krokow
    //cout << "After" << *first << endl;
    return first;
}

template<typename Lis, typename T>//page 796
bool binary_search_list(Lis first, Lis last, const T& val)
{
    if(first == last)
        return false;
    Lis p = calculate(first, last); //obliczenia musialem przekazac do zewnetrznej funkcji poniewaz
                                    //gdy wykonywalem je w tym miejscu modyfikowalem jednoczesnie first
    //cout << *p << endl;
    //cout << *first << endl;
    if(*p  == val)
        return true; //ZNALEZIONO
    if(*p < val && p++ != last) //warunek analogiczny jak dla vectora
        return binary_search_list(p, last, val);
    if(*p > val)
        return binary_search_list(first, p, val);
    else
        return false;
}
int main()
try{
    cout << "VECTOR" << endl;
    vector<int> v {0,1,2,3,4,5,6,7};
    int x = 2;
    sort(v.begin(), v.end());//sortowanie przed wyszukiwaniem
    auto searchVec = binary_search_vec(v.begin(), v.end(), x);
    if(searchVec == 0)
        cout << "Not fund " << x << endl;
    else
        cout << "Found " << x << endl;

    /////////////////////////////////

    cout << "LIST" << endl;
    list<string> l {"word1", "word2", "word3", "word4"};
    l.sort();//sortowanie przed wyszukiwaniem
    string y = "word3";
    auto searchList = binary_search_list(l.begin(), l.end(), y);
    //cout << searchList << endl;
    if(searchList == 0)
        cout << "Not fund " << y << endl;
    else
        cout << "Found " << y << endl;

    //Roznica polega na sposobie obslugi vectora i listy.
    //Przy list sprawa sie troche komplikuje gdyz trzeba zachowac
    //ostroznosc przed mozliwym niechcianym zmodyfikowaniem parametrow.
    //Dodatkowo w przypadku list nie mozna wykonac operacji tj. / dlatego
    //trzeba skorzystac z innych metod jak przekazanie obliczen
    //do innej funkcji.
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
