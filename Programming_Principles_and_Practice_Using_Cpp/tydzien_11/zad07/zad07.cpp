/*
Statement:
    Expression
    Print
    Quit
 Print:
    ;
 Quit:
    q
 Expression:
    Term
    Expression + Term
    Expression – Term
    Expression & Term
    Expression | Term
    Expression ^ Term
 Term:
    Primary
    Term * Primary
    Term / Primary
    Term % Primary
 Primary:
    Number
    ( Expression )
    root(sqrt(Expression)
    exponentiation(pow(Expression)
    – Primary
    + Primary
    ~ Primary
 Number:
    floating-point-literal

 Input comes from cin through the Token_stream called ts.
*/


#include "std_lib_facilities.hpp"

struct Token{
    char kind;        // what kind of token
    int value;     // for numbers: a value
    string name;
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, int val)     // make a Token from a char and a int
        :kind(ch), value(val) { }
    Token(char ch, string n) :kind{ch}, name{n} { } // initialize kind and name

};

class Token_stream {
   //implementation details
	bool full;
	Token buffer;
public: //user interface
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer=t; full=true; }

	void ignore(char);
};

const char let = '#'; // declaration token
const string declkey = "exit";
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a'; // name token
const char root = 'R';
const char exponentiation = 'P';
const char change = 'C';

Token Token_stream::get()
    // read characters from cin and compose a Token
{
    if (full) // check if we already have a Token ready
    {
        full=false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
    case ',':
    case ';':
    case '&':
    case '|':
    case '^':
    case '~':
        return Token(ch);  // let each character represent itself
     case '#':
        return Token(let);
    case '.':              // a floating-point-literal can start with a dot
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9': // numeric literal
        {
            cin.unget();
            double val;
            cin >> val; // read a floating-point number
            int val_narrow = narrow_cast<double>(val);
            return Token(number, val);
        }
    default:
        if (isalpha(ch) || ch == '_') { //isalpha(ch) checks whether a character is an alphabet or not
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
			cin.unget();
			if (s == declkey) return Token(quit);
			if (s == "sqrt") return Token(root);
			if (s == "pow") return Token(exponentiation);
			if (s == "change") return Token(change);
			return Token(name,s);
		}
        error("Bad token");
    }
}

void Token_stream::ignore(char c)
    // c represents the kind of Token
{
    // first look in buffer:
    if(full && c == buffer.kind)
    {
        full = false;
        return;
    }
    full = false;

    // now search input:
    char ch;
    while(cin >> ch)
        if(ch == c) return;
}

struct Variable {
        string name;
        int value;
        Variable(string n, int v) :name(n), value(v) { }
};

vector<Variable> names;


int get_value(string s)
    // return the value of the Variable named s
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ",s);
}

void set_value(string s, int d)
 // set the Variable named s to d
{
    for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

bool is_declared(string s)
 // is s already in var_table?
{
    for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

int define_name(string s, int val)
 // add (s,val) to var_table
{
 if (is_declared(s)) error(s," declared twice");
    names.push_back(Variable(s,val));
 return val;
}

Token_stream ts;

int expression();    // declaration so that primary() can call expression()

// deal with numbers and parentheses
int primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':
    {
            int d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
    }
    case '-':
        return - primary();
    case '+':
        return primary();
    case '~':
        return ~primary();
    case number:
        return t.value;
   	case name:
		return get_value(t.name);
    case root:
        {
            int x;
            t = ts.get();
            if (t.kind = '(')
            {
            int d = expression();
            if( d >= 0)
            {
                x = sqrt(d);
            } else error("Negative values in the root");
            } else error("')' expected");
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return x;
        }
    case exponentiation:
        {
            int d;
            int i;
            t = ts.get();
            if (t.kind == '(')
            {
            d = expression();

            t=ts.get();
            if (t.kind == ',')
            {
                t = ts.get();
                i = t.value;
            } else error("missing ',' ");
            } else error("'(' expected");
            t=ts.get();
            if (t.kind != ')') error("')' expected");
            return pow(d,i);
        }
    default:
        error("primary expected");
    }
}

// deal with *, /, and %
int term()
{
    int left = primary();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {
                int d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
        case '%':
            {
                int d = primary();
                if (d == 0) error("divide by zero");
                left %=d;
                t = ts.get();
                break;
            }
        default:
            ts.unget(t);
            return left;
        }
    }
}

// deal with + and -
int expression()
{
    int left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        case '&':
            left &= term();
            t = ts.get();
            break;
        case '|':
            left |= term();
            t = ts.get();
            break;
        case '^':
            left ^= term();
            t = ts.get();
            break;
        default:
            ts.unget(t);
            return left;       // finally: no more + or -: return the answer
        }
    }
}

int declaration(char choice)
 // declare a variable called "name” with the initial value "expression”
{
    Token t = ts.get();
    if(choice==let){
    if (t.kind != 'a') error ("name expected in declaration");
    string name = t.name;
    if (is_declared(name)) error(name, " declared twice");
    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", name);
    int d = expression();
    names.push_back(Variable(name,d));
    return d;
    }
    if(choice==change) //change variable value
    {
       string name = t.name;
       if (!is_declared(name)) error("error: you havent declared");
       Token t2 = ts.get();
       int d = expression();
       if(is_declared(name)) set_value(name, d);
       return d;
    }
}

int statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration(let);
    case change:
        return declaration(change);
    default:
        ts.unget(t);
        return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

const string prompt = "> ";
const string result = "= "; //

void calculate() //expression evaluation loop
{
    while (cin)
    try{
        cout << prompt;
        Token t = ts.get();

        while (t.kind == print) t=ts.get(); // first discard all “prints”
        if(t.kind == quit) return;

        ts.unget(t);
        cout << result << statement() << '\n';
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n'; // write error message
        clean_up_mess();
    }
}

int main()
try
{
    define_name("pi",3.1415926535);
    define_name("e",2.7182818284);

    cout << "root -> sqrt(x), exponentiation -> pow(x,y)\n";
    cout << "If you want a declared variable first '#' (e.g. # var1=3).\nIf you want change your variable enter 'change' (e.g. change var1=4)\n";
    cout << "You can only use integer values\n";
    define_name("k", 1000);

    calculate();
    keep_window_open();
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
//17.05.2020
