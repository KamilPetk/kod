#include <regex>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    regex patternDot {R"(.)"};
    string tekst_do_testu = "\n";
    //string tekst_do_testu2 = "\.n";
    if(regex_search(tekst_do_testu, patternDot))
       cout << "matches" << endl;
    else
        cout << "no matches" << endl;
    return 0;
}
//Kamil Petk
//10.05.2020
