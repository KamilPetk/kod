#include "std_lib_facilities.hpp"

struct Record {
 double unit_price;
 int units; // number of units sold
 Record()
    {}
 Record(double unit_price, int units)
    :unit_price(unit_price), units(units)
    {}
};

double price(double v, const Record& r)
{
 return v + r.unit_price * r.units; // calculate price and accumulate
}
void f(const vector<Record>& vr)
{
 double total = accumulate(vr.begin(), vr.end(), 0.0, price);
 cout << total;
}

int main()
try{
    vector<Record> v;
    Record r1 = Record(125.3,2);
    Record r2 = Record(125.2,2);
    Record r3 = Record(125.5,2);
    v.push_back(r1);
    v.push_back(r2);
    v.push_back(r3);
    f(v);
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
