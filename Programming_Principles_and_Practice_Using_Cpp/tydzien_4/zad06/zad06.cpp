#include "std_lib_facilities.hpp"

int main()
{
    // open an istream for binary input from a file:
    string iname = "zad09.input.txt";

    ifstream ifs {iname,ios_base::binary}; // note: stream mode
    // binary tells the stream not to try anything clever with the bytes
    if (!ifs) error("can't open input file ",  iname);

    // open an ostream for binary output to a file:
    string binaryFile = "zad09.binary";
    ofstream ofsBin {binaryFile}; // note: stream mode
    // binary tells the stream not to try anything clever with the bytes
    if (!ofsBin ) error("can't open output file ", binaryFile);

    vector<int> v;
    // read from binary file:
    for(int x; ifs.read(as_bytes(x),sizeof(int)); ) // note: reading bytes
        v.push_back(x);
    // . . . do something with v . . .
    // write to binary file:
    for(int x : v)
       ofsBin << x << " "; // note: writing bytes

    ifs.close();
    ofsBin.close();
    ////////////////////////////////////////////
    //READ FROM zad09.binary

    string inameBinary = "zad09.binary";
    ifstream ifsBin {inameBinary};

    if (!ifsBin) error("can't open input file ",  inameBinary);

    string onameBinary = "zad09.output.txt";
    ofstream ofs {onameBinary};

    vector<int> vBin;
    for(int x; ifsBin >> x; )
        vBin.push_back(x);

    for(int x : v)
        ofs.write(as_bytes(x),sizeof(int));

    ifsBin.close();
    ofs.close();

    return 0;
}
//Teksty roznia sie od siebie. Tekst wyjsciowy nie zawiera ostatnich liter,
//np. dla tekstu wejsciowego "Tekst testowy" na wyjsciu otrzymujemy "Tekst testow".
//Kamil Petk
//25.03.2020
