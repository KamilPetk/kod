#include "std_lib_facilities.h"

struct Token
{
    char kind;
    Token(char ch)
        :kind(ch){}
};

class Token_stream {

public:
	Token_stream(){ }
	Token get();
};

const char quit = 'q';
const char nextValue = ';';
bool tf = true;

Token Token_stream::get()
{
 char ch;
 cin >> ch;
 switch(ch)
 {
    case 'x':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
        return Token(ch);
    case ';':
        return Token(ch);
    case 'q':
        return Token(ch);
    default:
        return tf = false;
 }
}

Token_stream ts;
vector<string> numbers;
void check_input()
{
    //sprawdzenie wejscia:
    cout << "Please enter several integers (octal, decimal, hexadecimal)\n"
        << "(If you want enter next number press ';'\n"
        << "for example: 0x43);\n"
        << "(If you want stop press 'q'):\n";

    string number = "";
    while (cin)
    {
        Token t = ts.get();

        if(t.kind == nextValue)
        {
            if(tf == true)
            {
                numbers.push_back(number);
                number.clear();
            }
            else
            {
                cout << "Bad value\n";
                number.clear();
                tf = true;
            }
        }
        if(t.kind == quit)
        {
            break;
        }
        else
        {
            if(t.kind != nextValue)
                number += t.kind;
        }
    }
}

void convert(vector<string> numbersToConvert)
{
    int n = 0;
    string valuesFromVec;

    for(n; n < numbersToConvert.size(); n++)
    {
        valuesFromVec = numbersToConvert[n];

        if(valuesFromVec[0] == '0')
        {
            if(valuesFromVec[1] == 'x')
            {
                stringstream ss(valuesFromVec);
                int num = 0;
                ss >> hex >> num;
                cout << valuesFromVec << "\t hexadecimal " << setw(15) << "converts to " << dec <<  num << "\t decimal" << endl;
            }
            else
            {
                stringstream ss(valuesFromVec);
                int num = 0;
                ss >> oct >> num;
                cout << valuesFromVec << "\t octal " << setw(21) << "converts to " << dec << num << "\t decimal" << endl;
            }
        }
        else
        {
            stringstream ss(valuesFromVec);
            int num = 0;
            ss >> dec >> num;
            cout << valuesFromVec << "\t decimal " << setw(19) << "converts to " << dec << num << "\t decimal" << endl;
        }
    }
}

int main()
try{
    check_input();
    convert(numbers);

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
//22.03.2020
