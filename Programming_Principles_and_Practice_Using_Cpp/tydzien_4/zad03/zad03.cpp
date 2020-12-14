#include "std_lib_facilities.h"

vector<double> numbers;

void read_number(vector<double>& numbers, string nameFile)
{
    ifstream ist{nameFile};
    if (!ist) error("can't open input file ", nameFile);

    char nextChar;
    int i = 0;
    double number;
    while(ist >> nextChar)
    {
        if(isdigit(nextChar))
        {
            ist.unget(); //jesli liczba odkladam z powrotem
            ist >> number; //i odczytuje jako double
            numbers.push_back(number);
        }
        i++;
    }
}

void sum(vector<double>& numbers)
{
   double sum = 0;
   for(int k = 0; k < numbers.size(); k++)
        sum += numbers[k];
   cout << "Sum = " << sum;
}

int main()
try
{
    string nameFile = "plik.txt";

    read_number(numbers, nameFile);

    sum(numbers);

    cout << endl;

    keep_window_open();
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
//21.03.2020
