#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "std_lib_facilities.hpp"
using namespace std;

// accept a pattern and a set of lines from input
// check the pattern and search for lines with that pattern

int main()
{
     regex pattern;
     string pat;
     cout << "enter pattern: ";
     getline(cin,pat); // read gfpattern

     try {
        pattern = pat; // this checks pat
        cout << "pattern: " << pat << '\n';
     }
     catch (regex_error) {
        cout << pat << " is not a valid regular expression\n";
        exit(1);
     }

     string namefile;
     cout << "enter file name:" << endl; //file.txt
     cin >> namefile;
     ifstream in {namefile}; // input file
     if (!in){
        cerr << "no file\n";
        exit(2);
     }

     cout << "now enter lines:\n";
     int lineno = 0;

     for (string line; getline(in,line); ) {
        ++lineno;
        smatch matches;
     if (regex_search(line, matches, pattern)) {
        cout << "line " << lineno << ": " << line << '\n';
        for (int i = 0; i < matches.size(); ++i)
            cout << "\tmatches[" << i << "]: "
                << matches[i] << '\n';
    }
     else
        {}
     }
}
//Kamil Petk
//10.05.2020
