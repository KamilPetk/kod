#include "std_lib_facilities.hpp"

double weighted_value(
     const pair<string,double>& a,
     const pair<string,double>& b
     ) // extract values and multiply
{
 return a.second * b.second;
}

int main()
try{
    map<string,double> dow_price = { // Dow Jones Industrial index (symbol,price);
                                    // for up-to-date quotes see
                                    // www.djindexes.com
     {"MMM",81.86},
     {"AA",34.69},
     {"MO",54.45},
     {"KK",43.12},
     {"INTC",62.45 }
    };
    map<string,double> dow_weight = { // Dow (symbol,weight)
     {"MMM",5.8549},
     {"AA",2.4808},
     {"MO",3.8940},
     {"KK",1.2312},
     {"INTC",4.3443}
    };

   map<string, string> dow_name = {
     {"MMM","3M Co."},
     {"AA","Alcoa Inc."},
     {"MO","Altria Group Inc."},
     {"KK","KkKk Inc."},
     {"INTC","Intel Inc."}
    };

    double alcoa_price = dow_price ["AAA"]; // read values from a map
    double boeing_price = dow_price ["BA"];
        if (dow_price.find("INTC") != dow_price.end()) // find an entry in a map
            cout << "Intel is in the Dow\n";

    cout << endl;
    // write price for each company in the Dow index:
    for(const auto& p : dow_price)
    {
        const string& symbol = p.first; // the “ticker” symbol
        cout << symbol << '\t'
            << p.second << '\t'
            << dow_name[symbol] << '\n';
    }
    cout << endl;

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
