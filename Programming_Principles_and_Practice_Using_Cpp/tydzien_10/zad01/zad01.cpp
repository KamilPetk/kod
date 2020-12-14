#include "std_lib_facilities.hpp"
#include <regex>
#include <iostream>
#include <string>
#include <fstream>

int main()
try{
    //std::regex jest dostarczone przez standardowa biblioteke
    //tr1::regex wymaga <regex>

    ifstream in {"file.txt"}; // input file
    if (!in) cerr << "no file\n";

    regex pat {R"(\w{2}\s*\d{5}(-\d{4})?)"}; // postal code pattern
    int lineno = 0;
    for (string line; getline(in,line); ) { // read input line into input buffer
        ++lineno;
        smatch matches; // matched strings go here
        if (regex_search(line, matches, pat))
            cout << lineno << ": " << matches[0] << '\n'; // whole match
            if (1<matches.size() && matches[1].matched)
                cout << "\t: " << matches[1] << '\n'; // sub-match
    }

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
//09.05.2020
