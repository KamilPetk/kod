#include "std_lib_facilities.hpp"

void infinite_loop()
{
    for(short i = 0; i < 32768; ++i)
        cout << i << endl;
}

int main()
try{
    infinite_loop();
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
