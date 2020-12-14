#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<iostream>
using namespace std;

typedef vector<string>::const_iterator Line_iter;

class Message { // a Message points to the first and the last lines of a message
    Line_iter first;
    Line_iter last;
public:
    Message(Line_iter p1, Line_iter p2) :first{p1}, last{p2} { }
    Line_iter begin() const { return first; }
    Line_iter end() const { return last; }
    // . . .
};

//OPERATOR W CELU SPRAWDZENIA ZAWARTOSCI
ostream& operator<<(ostream& os, const Message& mess)
{
    for (Line_iter p = mess.begin(); p != mess.end(); ++p)
        os << *p << endl;
    return os;
}

using Mess_iter = vector<Message>::const_iterator;

struct Mail_file { // a Mail_file holds all the lines from a file
                    // and simplifies access to messages
    string name; // file name
    vector<string> lines; // the lines in order
    vector<Message> m; // Messages in order

    Mail_file(const string& n); // read file n into lines

    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }
};

Mail_file::Mail_file(const string& n)
 // open file named n
 // read the lines from n into lines
// find the messages in the lines and compose them in m
 // for simplicity assume every message is ended by a –––– line
{
    ifstream in {n}; // open the file
    if (!in) {
        cerr << "no " << n << '\n';
        exit(1); // terminate the program
    }

    for (string s; getline(in,s); ) // build the vector of lines
        lines.push_back(s);

    auto first = lines.begin(); // build the vector of Messages
    for (auto p = lines.begin(); p!=lines.end(); ++p) {
            //cout << *p << endl; //kolejne linie tekstu
        if (*p == "----") { // end of message
                //cout << *first << endl;
                //cout << *p << endl;
                //cout << endl;
                if(p != first)
                {
                    m.push_back(Message(first,p));
                }
            first = p+1; // ---- not part of message
        }
    }

}


int is_prefix(const string& s, const string& p)
 // is p the first part of s?
{
     int n = p.size();
     if (string(s,0,n)==p) return n;
     return 0;
}

bool find_from_addr(const Message* m, string& s)
{
    for (const auto& x : *m)
        if (int n = is_prefix(x, "From: ")) {
            s = string(x,n);
            return true;
        }
    return false;
}
string find_subject(const Message* m)
{
    for (const auto& x : *m)
        if (int n = is_prefix(x, "Subject: ")) return string(x,n);
    return "";
}

int main()
try{
    cout << "\t \tTEST PLIKU email.txt" << endl;
    cout << endl;

    Mail_file mfile {"email.txt"}; // initialize mfile from a file

    // first gather messages from each sender together in a multimap:

    multimap<string, const Message*> sender;

    for (const auto& m : mfile) {
        string s;
        if (find_from_addr(&m,s))
            sender.insert(make_pair(s,&m));
    }
    cout << endl;
    cout << "\t1.Test pobrania wiadomosci przez program" << endl;
    cout << endl;
    for (const auto& m : mfile) {
        cout << m << endl;
    }

    // now iterate through the multimap
    // and extract the subjects of John Doe’s messages:
    cout << "\t2.Sprawdzenie wyszukania dla \"Person2 <person2@machine.example>\"" << endl;
    auto pp = sender.equal_range("Person2 <person2@machine.example>");
    for(auto p = pp.first; p!=pp.second; ++p)
        cout << find_subject(p->second) << '\n';

    cout << "\t3.Sprawdzenie wyszukania dla \"Person1 <person1@machine.example>\"" << endl;
    auto pp2 = sender.equal_range("Person1 <person1@machine.example>");
    for(auto p = pp2.first; p!=pp2.second; ++p)
        cout << find_subject(p->second) << '\n';

    cout << "\t4.Sprawdzenie wyszukania dla \"Person3 <person3@machine.example>\"" << endl;
    auto pp3 = sender.equal_range("Person3 <person3@machine.example>");
    for(auto p = pp3.first; p!=pp3.second; ++p)
        cout << find_subject(p->second) << '\n';
    cout << "Brak wyszukania spowodowany brakiem \"Subject: \" w wiadomosci" << endl;

    cout << endl;
    cout << "\t5.Test ilosci wykrytych wiadomosci" << endl;
    cout << "Ilosc wykrytych wiadomosci: " << mfile.m.size() << endl;



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
