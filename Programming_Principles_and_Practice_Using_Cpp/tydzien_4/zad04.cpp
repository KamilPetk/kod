#include "std_lib_facilities.h"

void table()
{
    cout << "last name"
         << setw(14) << "first name"
         << setw(22) << "telephone number"
         << setw(10) << "email\n";
    cout << "Petk"
        << setw(16) << "Kamil"
        << setw(21) << "123456789"
        << setw(20) << "kamil@mail.com\n";
    cout << "Petk"
        << setw(17) << "Kacper"
        << setw(20) << "134765987"
        << setw(21) << "kacper@mail.com\n";
    cout << "Nowak"
        << setw(18) << "Krzysztof"
        << setw(18) << "984571201"
        << setw(20) << "krzys@mail.com\n";;
    cout << "Kowalska"
        << setw(12) << "Agata"
        << setw(21) << "904542918"
        << setw(19) << "aga@mail.com\n";
    cout << "Polak"
        << setw(16) << "Marcin"
        << setw(20) << "958500312"
        << setw(21) << "marcin@mail.com\n";
    cout << "Nowakowski"
        << setw(9) << "Olaf"
        << setw(22) << "185423088"
        << setw(20) << "olaf@mail.com\n";
}


int main()
try
{
    int birth_year = 1998;
    int age = 20;

    cout << dec << birth_year << "\t(decimal)\n"
        << hex << birth_year << "\t(hexadecimal)\n"
        << oct << birth_year << "\t(octal)\n";

    cout << dec << age << "\t(Age, decimal)\n"
        << hex << age << "\t(Age, hexadecimal)\n"
        << oct << age << "\t(Age, octal)\n";

    int a;
    int b;
    int c;
    int d;
    cout << "Enter four integer values:\n";
    cin >> a >> hex >> b >> oct >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
    //a jest postaci hexadecimal, b postaci octal, c oraz d sa w postaci dziesietnej

    cout << 1234567.89 << "\t(defaultfloat)\n"
        << fixed << 1234567.89 << "\t(fixed)\n"
        << scientific << 1234567.89 << "\t(scientific)\n";
        //najdkladniejszy wynik uzyskano dzieki scientific poniewaz wyswietlanych jest najwiecej miejsc po przecinku

    cout << "Table: \n";
    table();

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
//22.03.2020
