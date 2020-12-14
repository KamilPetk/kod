#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void porownaj(vector<char> &odczytane_znaki_z_pliku, char znak)
{
    bool czy_taki_znak_juz_jest = 0; // 0 - nie ma, 1 - jest
    for(char x : odczytane_znaki_z_pliku)
    {
        if( x == znak )
        {
            czy_taki_znak_juz_jest = 1;
        }
    }
    if(czy_taki_znak_juz_jest == 0)
        odczytane_znaki_z_pliku.push_back(znak);
    else{}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void odczyt_z_pliku(const char* nazwa_pliku, vector<char> &odczytane_znaki_z_pliku, string &caly_tekst_do_testu)
{
    FILE* szyfrogram;

    szyfrogram = fopen(nazwa_pliku, "rb");

    char znak;
    vector<char> znaki;

    while(fread(&znak, sizeof(char), 1, szyfrogram))
    {
        caly_tekst_do_testu += znak;
        if( odczytane_znaki_z_pliku.size() == 0)
        {
            odczytane_znaki_z_pliku.push_back(znak);
        }
        else
        {
            porownaj(odczytane_znaki_z_pliku, znak);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double oblicz_ilosc_danego_znaku(vector<char> znaki, int i, string caly_tekst, vector<double> &prawdopodobienstwa)
{
    double ilosc_znaku = 0;
    for(char x : caly_tekst)
    {
        if( x == znaki[i])
        {
            ilosc_znaku++;
        }
    }
    prawdopodobienstwa.push_back( ilosc_znaku / caly_tekst.size() );
    return ( ilosc_znaku / caly_tekst.size() ) * 100; //przedstawienie wyniku jako procenty
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void zapis_do_pliku(string nazwa_pliku, string caly_tekst_do_testu, vector<char> odczytane_znaki_z_pliku, vector<double> &prawdopodobienstwa)
{
    ofstream zapisz_do_pliku(nazwa_pliku, ios_base::binary);
    zapisz_do_pliku << caly_tekst_do_testu << endl;
    zapisz_do_pliku.close();

    ofstream zapis_do_pliku_wynikow(nazwa_pliku, ios_base::app);
    zapis_do_pliku_wynikow << endl;
    for(int i = 0; i < odczytane_znaki_z_pliku.size(); ++i)
    {
        zapis_do_pliku_wynikow << odczytane_znaki_z_pliku[i] << " --> " << oblicz_ilosc_danego_znaku(odczytane_znaki_z_pliku, i, caly_tekst_do_testu, prawdopodobienstwa) << "%" << endl;
    }
    zapis_do_pliku_wynikow.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void entropia(string nazwa_pliku, vector<double> prawdopodobienstwa)
{
    ofstream zapisz_do_pliku(nazwa_pliku, ios_base::app);
    double sum = 0;
    for(double xi : prawdopodobienstwa)
    {
        sum += xi*log2(xi); //logarytm o podstawie 2
    }
    sum = sum * (-1.0);

    zapisz_do_pliku << "\n Entropia = " << sum;
    zapisz_do_pliku << " (wyrazana w bitach - we wzorze uzyty log o podstawie 2)\n";
    zapisz_do_pliku.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    vector<char> odczytane_znaki_z_pliku;
    string caly_tekst_do_testu;
    vector<double> prawdopodobienstwa;
    const char* plik_encrypted = "encrypted.txt";
    string plik_statystyka = "statystyka.txt";

    //1.
    odczyt_z_pliku(plik_encrypted, odczytane_znaki_z_pliku, caly_tekst_do_testu); //odczytanie znakow szyfrogramu oraz wykrycie powtorzen
    //2.
    zapis_do_pliku(plik_statystyka, caly_tekst_do_testu, odczytane_znaki_z_pliku, prawdopodobienstwa); //zliczenie ilosci wystapien kazdego znaku i w postaci
                                                                                                //procentow wystapien danego znaku zapis wyniku do pliku tekstowego
    //3.
    entropia(plik_statystyka, prawdopodobienstwa); //obliczenie entropii i dopisanie wyniku do pliku tekstowego

    cout << "\tSzyfrogram zostal pobrany z pliku: " << plik_encrypted << endl;
    cout << "\tWynik dzialania programu zostal zapisany w pliku: " << plik_statystyka << endl;

    system("PAUSE");

    return 0;
}
