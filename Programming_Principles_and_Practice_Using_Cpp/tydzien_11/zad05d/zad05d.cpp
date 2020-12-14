#include "std_lib_facilities.hpp"

void infinite()
{
 unsigned char max = 160; // very large
    for (signed char i=0; i<max; ++i)
         cout << int(i) << '\n';
}
int main()
try{
    //Petla ta jest nieskonczona poniewaz za kazdym razem osiagajac wartosc 127
    //nastepuje kolejne odliczanie od -128 do 127
    //jest to spowodowane tym, ze signed char przechowuje maks wartosc 127

    infinite();
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
