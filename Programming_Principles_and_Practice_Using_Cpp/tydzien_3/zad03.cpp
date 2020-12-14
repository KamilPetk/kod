#include "std_lib_facilities.h"

class Date {
public:
    enum Month {            // note: no “class”
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(int y, Month m, int d) : y(y), m(m), d(d) {};
    bool is_date(int y, Month m, int d);
    // nonmodifying operations:
    int day() const { return d; }
    Month month() const { return m; }
    int year() const { return y; }

    void add_day(int n); // non-const member: can modify the object
    void add_month(int n); // non-const member: can modify the object
    void add_year(int n); // non-const member: can modify the object
private:
    int y; // year
    Month m;
    int d; // day
};

void Date::add_day(int n)
{
    d += n;
}

bool Date::is_date(int y, Month m, int d)
{
     // assume that y is valid
     if (d<=0) return false; // d must be positive
     if (m<Month::jan || Month::dec<m) return false;

     int days_in_month = 31; // most months have 31 days

     switch (m) {
        case Month::apr: case Month::jun: case Month::sep: case Month::nov:
            days_in_month = 30; // the rest have 30 days
            break;
     }

     if (days_in_month<d) return false;

     return true;
}

ostream& operator<<(ostream& os, const Date& d)
{
 return os << '(' << d.year()
            << ',' << d.month()
            << ',' << d.day() << ')' << endl;
}

int main()
try
{
    int day = 25;

    Date today = Date{1978, Date::jun, day};
    bool tf = today.is_date(1978, Date::jun, day);
    if(tf == 0)
    {
        cout << "Error: incorrect data" << endl;
        keep_window_open();
    }

    Date tomorrow = today;

    tomorrow.add_day(1);

    cout << today;

    cout << tomorrow;

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
//18.03.2020
