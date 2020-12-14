#include "std_lib_facilities.hpp"

int main()
try{
    ofstream of("tekst.txt");
    for(int i = 0; i < 200; i++)
    {
        of << "word" << i << endl;
    }
    of.close();

    string from = "tekst.txt";
    string to = "tekst_output.txt";

    ifstream is {from}; // open input stream
    ofstream os {to}; // open output stream

    istream_iterator<string> ii {is}; // make input iterator for stream
    istream_iterator<string> eos; // input sentinel
    ostream_iterator<string> oo {os,"\n"}; // make output iterator for stream

    vector<string> b {ii,eos}; // b is a vector initialized from input
    sort(b.begin() ,b.end()); // sort the buffer
    copy(b.begin() ,b.end() ,oo); // copy buffer to output

    //int max_size = 100;
    //vector<string> b(max_size); // don’t guess about the amount of input!
    //copy(ii,eos,b.begin());
    is.close();
    os.close();
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
