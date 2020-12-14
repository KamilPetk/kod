//Kamil Petk nr 176648
#include <iostream>
#include <fstream>
#include <bitset>
#include <cstring>
#include <vector>
#include <ctime>
#include <boost/dynamic_bitset.hpp>
#include <string.h>
using namespace std;
#define iloscBajtowDanychPrzesylanych 10

struct header{
    uint8_t id;
    uint8_t package_number;
    uint8_t data_size;
};

struct package{
    header naglowek;
    char data[iloscBajtowDanychPrzesylanych];
    vector<char> checkSum;
};

void readFile(string nazwa_pliku, char* &bufor, unsigned int &length)
{
    ifstream plik(nazwa_pliku, ifstream::binary);
    if(plik.fail()) {cerr << "Blad z plikiem";}
    else{
        plik.seekg(0, plik.end);
        length = plik.tellg();
        plik.seekg(0, plik.beg);
    }

    bufor = new char[length];
    plik.read(bufor, length);
    plik.close();
}

void tworzenieBajtu(bitset<8> &bajt, vector<bitset<1>> bity_danych, int k)
{
    for(int i = 0; i < 8; i++){
        if(bity_danych[i+k] == 0)
                bajt[7-i] = 0;
        else bajt[7-i] = 1;}
}

void utworzPaczke(vector<bitset<1>> bity_danych, int nr_paczki, vector<package*> paczkiPoPrzeslaniu)
{
    bitset<8> bajt;

    tworzenieBajtu(bajt, bity_danych, 0);
    paczkiPoPrzeslaniu[nr_paczki]->naglowek.id = bajt.to_ulong();
    tworzenieBajtu(bajt, bity_danych, 8);
    paczkiPoPrzeslaniu[nr_paczki]->naglowek.package_number = bajt.to_ulong();
    tworzenieBajtu(bajt, bity_danych, 16);
    paczkiPoPrzeslaniu[nr_paczki]->naglowek.data_size = bajt.to_ulong();

    for(int i = 0; i < iloscBajtowDanychPrzesylanych; i++){
            tworzenieBajtu(bajt, bity_danych, 24+(i*8));
            paczkiPoPrzeslaniu[nr_paczki]->data[i] = bajt.to_ulong();
    }
}

void addHeaderAndDataToVector(vector<bitset<1>> &bity_danych, vector<package*> wszystkiePaczki, int nr_paczki)
{
    //dodanie naglowka
    for(int j = 7; j >= 0; j--)
        bity_danych.push_back(bitset<1>((wszystkiePaczki[nr_paczki]->naglowek.id >> j)%2));
    for(int j = 7; j >= 0; j--)
        bity_danych.push_back(bitset<1>((wszystkiePaczki[nr_paczki]->naglowek.package_number >> j)%2));
    for(int j = 7; j >= 0; j--)
        bity_danych.push_back(bitset<1>((wszystkiePaczki[nr_paczki]->naglowek.data_size >> j)%2));
    //dodanie danych
    for(int i = 0; i < iloscBajtowDanychPrzesylanych; i++){
        for(int j = 7; j >= 0; j--)
            bity_danych.push_back(bitset<1>((wszystkiePaczki[nr_paczki]->data[i] >> j)%2));
    }
}

void addHeaderAndData(vector<package*> wszystkiePaczki, char* bufor, unsigned int data_size, int nr_pakietu, int id_pliku, unsigned int ileBajtowTrzebaDodac, unsigned int ilosc_pakietow)
{
    wszystkiePaczki[nr_pakietu]->naglowek.id = id_pliku;
    wszystkiePaczki[nr_pakietu]->naglowek.package_number = nr_pakietu;
    wszystkiePaczki[nr_pakietu]->naglowek.data_size = data_size;

    for(int i = 0; i < data_size; i++){
        if(ileBajtowTrzebaDodac != 0 && nr_pakietu == ilosc_pakietow-1)
        {
            if(i < (data_size - ileBajtowTrzebaDodac))
                wszystkiePaczki[nr_pakietu]->data[i] = bufor[i+(nr_pakietu*data_size)];
            else  wszystkiePaczki[nr_pakietu]->data[i] = 0; //uzupe³nienie bajtami 00000000
        }
        else{
            wszystkiePaczki[nr_pakietu]->data[i] = bufor[i+(nr_pakietu*data_size)];
        }
    }
}

void bit_parzystosci(unsigned int data_size, unsigned int n, vector<package*> wszystkiePaczki, int nr_pakietu)
{
    vector<char> paczka; //vector do ktorego przekazuje naglowek+dane i wyliczam bit parzystosci

    paczka.push_back(wszystkiePaczki[nr_pakietu]->naglowek.id);
    paczka.push_back(wszystkiePaczki[nr_pakietu]->naglowek.package_number);
    paczka.push_back(wszystkiePaczki[nr_pakietu]->naglowek.data_size);
    for(int i = 0; i < iloscBajtowDanychPrzesylanych; i++)
        paczka.push_back(wszystkiePaczki[nr_pakietu]->data[i]);

    long zlicz = 0;
    long wszystkie_bity = 0;
    for(int k = 0; k < paczka.size(); k++){
        for(int i = 7; i >= 0; i--){
            wszystkie_bity++;
            if( ((paczka[k] >> i) % 2) == 0)
                zlicz++;
        }
    }
    //dodanie bitu parzystosci
    if((wszystkie_bity-zlicz) % 2 != 0)
        wszystkiePaczki[nr_pakietu]->checkSum.push_back(1);
    else
        wszystkiePaczki[nr_pakietu]->checkSum.push_back(0);
    paczka.clear();
}

void suma_modulo(unsigned int data_size, unsigned int n, vector<package*> wszystkiePaczki, int nr_paczki)
{
    vector<char> paczka; //vector do ktorego przekazuje naglowek+dane i wyliczam sume modulo

    paczka.push_back(wszystkiePaczki[nr_paczki]->naglowek.id);
    paczka.push_back(wszystkiePaczki[nr_paczki]->naglowek.package_number);
    paczka.push_back(wszystkiePaczki[nr_paczki]->naglowek.data_size);
    for(int i = 0; i < iloscBajtowDanychPrzesylanych; i++)
        paczka.push_back(wszystkiePaczki[nr_paczki]->data[i]);

    long long suma = 0;

    //obliczenie sumy modulo dla danej paczki
    for(int k = 0; k < paczka.size(); k++)
    {
        suma += uint8_t(paczka[k]);
    }

    long long suma_mod = suma%n; //obliczenie sumy modulo

    //obliczenie ilosci bajtow potrzebnych do zapisania sumy modulo
    long long size_suma_mod = 0;
    if(suma_mod < pow(2,7)-1){
        size_suma_mod = 1;
    }
    else{
        while(suma_mod > pow(2, 7+(8*size_suma_mod))){
            size_suma_mod++;
        };
        size_suma_mod++;
    }
    //zapisanie sumy modulo
    boost::dynamic_bitset<> suma_mod_bin(size_suma_mod*8, suma_mod);

    bitset<8> t = 0;
    for(int i = size_suma_mod; i > 0; i--)
    {
        for(int j = 0; j < 8; j++)
            t.set(j,suma_mod_bin[8*i-8+j]);
        wszystkiePaczki[nr_paczki]->checkSum.push_back(t.to_ulong());
        t = 0;
    }
    paczka.clear();
}

void crc_dzielnik(vector<bitset<1>> &dzielnik, unsigned int n)
{
    srand(time(NULL));
    dzielnik.push_back(1); // najstarszy bit = 1
    for(int i = 0; i < n; i++)
        dzielnik.push_back(rand()%2);
}

void crc(vector<bitset<1>> dzielnik, vector<package*> wszystkiePaczki, unsigned int n, int nr_paczki)
{
    vector<bitset<1>> dane_do_wyliczeniaCRC; //vector do ktorego przekazuje naglowek+dane a nastepnie wyliczam crc
    addHeaderAndDataToVector(dane_do_wyliczeniaCRC, wszystkiePaczki, nr_paczki);

    //crc
    for(int i = 0; i < n; i++)
        dane_do_wyliczeniaCRC.push_back(0);
    for(int j = 0; j < dane_do_wyliczeniaCRC.size()-n; j++){
        if(dane_do_wyliczeniaCRC[j] == 1)
        {
            for(int i = 0; i < dzielnik.size(); i++)
                dane_do_wyliczeniaCRC[j+i] = dzielnik[i] ^ dane_do_wyliczeniaCRC[j+i];
        }
    }
    //okreslenie ilosci bajtow potrzebnych do zapisu CRC
    int size_CRC = 0;
    int reszta = 0;
    if(n/8!=0)
        size_CRC = n/8;
    if(n%8!=0)
    {
        size_CRC++;
        reszta = n%8;
    }
    //podzial otrzymanych bitow crc na bajty
    bitset<8> my_crc = 0;
    char bajt_crc;
    int nr_bitu = n;
    for(int j = 0; j < size_CRC; j++){
        for(int i = 0; i < 8; i++){
            if(n%8!=0)
            {
                my_crc[7-i] = 0;
                n++;
            }
            else{
                if(dane_do_wyliczeniaCRC[dane_do_wyliczeniaCRC.size()-nr_bitu]!=0)
                {
                    my_crc[7-i] = 1;
                }
                nr_bitu--;
            }
        }
        bajt_crc = my_crc.to_ulong();
        wszystkiePaczki[nr_paczki]->checkSum.push_back(bajt_crc);
        my_crc = 0;
    }
}

void zaklocenia_z_powtorzeniami(vector<package*> wszystkiePaczki, vector<package*> paczkiPoPrzeslaniu, int ilosc_zaklocen, int nr_paczki)
{
    vector<bitset<1>> bity_danych; //wektor do ktorego przekaze naglowek oraz dane i dokonam zaklocen
    addHeaderAndDataToVector(bity_danych, wszystkiePaczki, nr_paczki);
    //dokonanie zaklocen
    int numer_bitu = 0;

    for(int i = 0; i < ilosc_zaklocen; i++){
        numer_bitu = rand()%(bity_danych.size()-1);

        if(bity_danych[numer_bitu] == bitset<1>(0))
        {
            bity_danych[numer_bitu] = bity_danych[numer_bitu] | bitset<1>(1);
        }
        else if(bity_danych[numer_bitu] == bitset<1>(1))
        {
            bity_danych[numer_bitu] = bity_danych[numer_bitu] ^ bitset<1>(1);
        }
    }
    utworzPaczke(bity_danych, nr_paczki, paczkiPoPrzeslaniu);
    bity_danych.clear();
}

void zaklocenie_danych(vector<bitset<1>> &zaklocenie, int ilosc_zaklocen)
{
    int zlicz_zaklocenia = 0; //do kontroli ilosci ustalonych zaklocen
    int nr_bitu;
    do{
        nr_bitu = rand() % (zaklocenie.size()-1);
        if(zaklocenie[nr_bitu] == 0)
        {
            zaklocenie[nr_bitu] = 1;
            zlicz_zaklocenia++;
        }
    }while(zlicz_zaklocenia < ilosc_zaklocen);
}

void zaklocenia_bez_powtorzen(vector<package*> wszystkiePaczki, vector<package*> paczkiPoPrzeslaniu, int ilosc_zaklocen, int nr_paczki)
{
    vector<bitset<1>> bity_danych; //wektor do ktorego przekaze naglowek oraz dane i dokonam zaklocen
    addHeaderAndDataToVector(bity_danych, wszystkiePaczki, nr_paczki);

    vector<bitset<1>> zaklocenie (bity_danych.size(), 0);
    if(ilosc_zaklocen != 0)
    {
        zaklocenie_danych(zaklocenie, ilosc_zaklocen);

        for(int i = 0; i < zaklocenie.size(); i++){
            bity_danych[i] = bity_danych[i] ^ zaklocenie[i];
        }
    }
    utworzPaczke(bity_danych, nr_paczki, paczkiPoPrzeslaniu);

    bity_danych.clear();
    zaklocenie.clear();
}

void testoweWyswietlenie(vector<package*> wszystkiePaczki, unsigned int data_size)
{
    for(package* x : wszystkiePaczki){
        cout << bitset<8>(x->naglowek.id) << " ";
        cout << bitset<8>(x->naglowek.package_number) << " ";
        cout << bitset<8>(x->naglowek.data_size) << " ";
        for(int i = 0; i < data_size; i++)
            cout << bitset<8>(x->data[i]) << " ";
        for(int i = 0; i < x->checkSum.size(); i++)
            cout << bitset<8>(x->checkSum[i]) << " ";
        cout << endl;
    }
}

int main()
{
    vector<package*> wszystkiePaczki; //wektor do przechowywania kolejnych pakietow

    //string nazwa_pliku = "obraz.jpg";
    string nazwa_pliku = "test.txt";

    char* bufor; //bufor do ktorego odczytuje dane z pliku
    unsigned int length; //rozmiar odczytanych danych
    readFile(nazwa_pliku, bufor, length);

    unsigned int data_size = iloscBajtowDanychPrzesylanych; //ilosc bitow danych
    int id_pliku = 1;
    unsigned int ilosc_pakietow = ceil((double)(length)/data_size); //okreslenie ilosci potrzebnych pakietow do przeslania wszystkich danych
    unsigned int ileBajtowTrzebaDodac = data_size-length%data_size; //sprawdzenie czy ostatnia paczke bedzie trzeba obsluzyc dodajac bajty 00000000

    unsigned int n = 72000; //n do sumy modulo
    vector<bitset<1>> dzielnik; //do wyliczenia crc
    unsigned int n_crc = 8; //n ustalane dla crc
    crc_dzielnik(dzielnik, n_crc); //ustawienie dzielnika

    for(int i = 0; i < ilosc_pakietow; i++)
    {
        wszystkiePaczki.push_back(new package); //nowy pakiet
        addHeaderAndData(wszystkiePaczki, bufor, data_size, i, id_pliku, ileBajtowTrzebaDodac, ilosc_pakietow); //dodanie naglowka i danych do paczki

        //bit_parzystosci(data_size, n, wszystkiePaczki, i); //obliczenie bitu parzystosci i dodanie go do paczki
        //suma_modulo(data_size, n, wszystkiePaczki, i); //obliczenie sumy modulo i dodanie jej do paczki
        crc(dzielnik, wszystkiePaczki, n_crc, i); //obliczenie crc i dodanie go do paczki
    }

    //Testowe wyswietlenie gotowych pakietow przed wyslaniem
    testoweWyswietlenie(wszystkiePaczki, data_size);

    vector<package*> paczkiPoPrzeslaniu; //nowy wektor ktory bedzie przechowywal paczki otrzymane po przeslaniu i zakloceniach
    srand(time(NULL));
    for(int nr_paczki = 0; nr_paczki < wszystkiePaczki.size(); nr_paczki++)
    {
        paczkiPoPrzeslaniu.push_back(new package); //nowy pakiet

        int ilosc_zaklocen = 2;
        //zaklocenia_z_powtorzeniami(wszystkiePaczki, paczkiPoPrzeslaniu, ilosc_zaklocen, nr_paczki);
        zaklocenia_bez_powtorzen(wszystkiePaczki, paczkiPoPrzeslaniu, ilosc_zaklocen, nr_paczki);

        //bit_parzystosci(data_size, n, paczkiPoPrzeslaniu, nr_paczki);
        //suma_modulo(data_size, n, paczkiPoPrzeslaniu, nr_paczki); //obliczenie sumy modulo i dodanie jej do paczki
        crc(dzielnik, paczkiPoPrzeslaniu, n_crc, nr_paczki); //obliczenie crc i dodanie go do paczki
    }

    //Testowe wyswietlenie gotowych pakietow po wyslaniu
    cout << "\nPakiety po przeslaniu z ponownie wyliczona suma kontrolna: \n";
    testoweWyswietlenie(paczkiPoPrzeslaniu, data_size);

    delete [] bufor;
    return 0;
}
