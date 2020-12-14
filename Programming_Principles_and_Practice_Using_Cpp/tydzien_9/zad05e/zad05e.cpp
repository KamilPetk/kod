#include "std_lib_facilities.hpp"
#include <unordered_map>

int main()
try{
     unordered_map<string,double> dow_price = {
     {"AA",34.69},
     {"MO",54.45},
     {"KK",43.12},
     {"INTC",62.45 }
    };

    unordered_map<string, string> dow_name = {
     {"MMM","3M Co."},
     {"AA","Alcoa Inc."},
     {"MO","Altria Group Inc."},
     {"KK","KkKk Inc."},
     {"INTC","Intel Inc."}
    };

    for (const auto& p : dow_price) {
        const string& symbol = p.first; // the “ticker” symbol
                cout << symbol << '\t'
                    << p.second << '\t'
                << dow_name[symbol] << '\n';
    }
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
