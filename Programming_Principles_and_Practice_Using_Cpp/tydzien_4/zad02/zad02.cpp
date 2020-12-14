#include "std_lib_facilities.h"

vector<string> words;

void read_words(vector<string>& words, string firstNameFile, string secondNameFile)
{
    ifstream firstIst{firstNameFile};
    if (!firstIst) error("can't open input file ", firstNameFile);

    string word;

    while(firstIst >> word)
    {
        words.push_back(word);
    }

    ifstream secondIst{secondNameFile};
    if (!secondIst) error("can't open input file ", secondNameFile);

    while(secondIst >> word)
    {
        words.push_back(word);
    }
}

void save_words(vector<string> vec, string nameFile)
{
    ofstream ost{nameFile};
    if (!ost) error("can't open output file ", nameFile);
        for(string w: vec)
            ost << w << " ";
    ost.close();
}


int main()
try
{
    string firstNameFile = "plik1.txt";
    string secondNameFile = "plik2.txt";
    read_words(words, firstNameFile, secondNameFile);
    string outputFile = "plik3.txt";
    save_words(words, outputFile);

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
