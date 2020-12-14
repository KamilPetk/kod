//KAMIL PETK
//nr 176648
//symulacja dla ECB

#include <iostream>
#include <fstream>
#include <bitset>
#include "std_lib_facilities.hpp"
#include <string>
#include <sstream>

void read(string nameFileRead, vector<char>& char_in_vector)
{
    ifstream openFile(nameFileRead);

    if(openFile.is_open())
    {
        char singleCharacter;
        while(openFile >> std::noskipws >> singleCharacter)
        {
            char_in_vector.push_back(singleCharacter);
        }
        }else cout << "Error while reading";
    openFile.close();
}

void save(string fileSaveName, string textToSave)
{

    fstream openFileToSave;

    openFileToSave.open(fileSaveName, ios::out);
    if(openFileToSave.good() == true)
    {
        openFileToSave << textToSave;
        openFileToSave.close();
    }
}

string TextToBinaryString(string words) { //pobiera 8 znakow i zamienia je na postac binarna
        //cout << endl << words;
    string binaryString = "";

    for (char& character : words) { //pozwala petli zmodyfikowaæ jej argumenty dzieki zastosowaniu odniesienia & -
        binaryString +=bitset<8>(character).to_string(); //zamiana po kolei kazdego znaku na postac binarna
    }
        //cout << endl << binaryString;
    return binaryString;
}

string encryptedTextBits(string eightBin, string key){
    int j = 0;
    int bitAsInt;
    bitset<64> allBitsEncrypted;
    for(int k = 63; k>=0; k--)
    {
        bitset<1> calc_xor = eightBin[j]^key[j];
        bitAsInt = (int)(calc_xor.to_ulong()); //postac binarna przedstawiona jako int
        allBitsEncrypted[k] = bitAsInt;
        j++;
    }
    string binaryEncryptedText = allBitsEncrypted.to_string();
    return binaryEncryptedText;
}

string charToString(vector<char> charVector)
{
    string outputString;
    stringstream stringOperation; //w celu operacji na ciagu znakow
    for(int i = 0; i < charVector.size(); i++)
    {
        stringOperation << charVector[i];
        outputString = stringOperation.str();
    }
    return outputString;
}

string returnEncryptedText(string encryptedTextBinary)
{
    stringstream sstream(encryptedTextBinary);
    string output;
    int i = 0;
        while(i < 8)
        {
            bitset<8> bits;
            sstream >> bits;
            char c = char(bits.to_ulong()); //to_ulong - liczba bin jako liczba int
            output += c;
            i++;
        }
        return output; //zwraca tekst w postaci string
}

string randomKey(string key)
{
    srand(time(NULL));
    for(int i = 0; i < 64; i++)
    {
        int x = rand()%2;
            //cout << x << endl;
        stringstream ss;
        ss << x;
        string str = ss.str();
            //cout << "str" << str << endl;
        key += str;
    }
    return key;
}

void ecb(string fileName, string key, string fileSaveName)
{
    vector<char> char_in_vector;
    read(fileName, char_in_vector);

    string stringCharacters;
    stringCharacters = charToString(char_in_vector);//Odczytanie wszystkich znakow

    int sizeText = stringCharacters.size();
        //cout << "size: " << sizeText << endl;
        while(sizeText%8 != 0)
        {
            stringCharacters+=" ";
            sizeText++;
        }
    int n = 0;
    int k = 0;
    string encryptedText = "";
    while(sizeText>0)
    {
    string inscription = "";
    for(n; n < (8+k); n++)//pobranie po 8 znakow
            inscription += stringCharacters[n];

        //cout << endl <<  inscription;
    string eightBin = TextToBinaryString(inscription);//Odczytane 8 znakow w postaci binarnej BLOKI PO 64 bity

    string encryptedTextBinary = encryptedTextBits(eightBin, key);//zaszyfrowny tekst w postaci binarnej

    encryptedText += returnEncryptedText(encryptedTextBinary);//zaszyfrowny tekst w postaci znakow

    sizeText = sizeText - 8;

    k += 8;
    }
    save(fileSaveName, encryptedText);
    encryptedText = "";
}

long long int calculate(long long int x, long long int y, long long int p)
{
    if(y == 1)
        return x;
    else
        return (((long long int)pow(x,y))%p);
}

int main()
{
    //przy probie zwieksznia liczby p oraz pozostałych zaczely
    //pojawiac sie bledy zwiazane z uzyskiwaniem
    //bardzo duzych liczb
    long long int p = 23;
    long long int g = 9;
    srand(time(NULL));
    //Alicja
    //wybiera losowy wykladnik a z zakresu a < p - 1
    int a = 14;
    cout << "Alicja oblicza A i wysyla do Boba" << endl;
    long long int A = calculate(g,a,p);

    //Ewa
    //odrzuca A
    //wybiera losowy wykladnik c
    cout << "Ewa odrzuca A, oblicza C i wysyla je do Boba" << endl;
    int c = 17;

    long long int C = calculate(g,c,p);

    //Bob
    //wybiera losowy wykladnik b
    int b = 12;

    //uwazajac ze otrzymal C od Alicji oblicza
    cout << "Bob uwazajac ze otrzyma C od Alicji oblicza Key" << endl;
    long long int Kb = calculate(C,b,p);
        printf("%lld", Kb);
        cout << endl;
    //ustawia
    cout << "Ustawia B i wysyla do Alicji" << endl;
    long long int B = calculate(g,b,p); //wysyla do Alicji

    //Ewa
    //odrzuca B i oblicza
    cout << "Ewa odrzuca B, oblicza oba klucze" << endl;
    long long int Ke1 = calculate(B,c,p);
        printf("%lld", Ke1);
        cout << endl;
    //wybiera losowy wykladnik d
    int d = 10;

    long long int Ke2 = calculate(A,d,p);//oblicza
        printf("%lld", Ke2);
        cout << endl;
    cout << "Nastepnie oblicza D i wysyla do Alicji" << endl;
    long long int D = calculate(g,d,p);

    //Alicja
    //oblicza
    cout << "Alicja odbiera D myslac ze otrzymala je od Boba oblicza Key" << endl;
    long long int Ka = calculate(D,a,p);
        printf("%lld", Ka);
        cout << endl;

    //Po ustaleniu kluczy proba szyfrowania i przeslania wiadomosci
    //Alicja za pomoca obliczonego klucza szyfruje wiadomosc
    cout << "Po ustaleniu kluczy proba szyfrowania i przeslania wiadomosci:" << endl;
    bitset<4> keyA(Ka);
    string keyAlicja = keyA.to_string();
    for(int i = 0; i < 15; i++)
           keyAlicja += keyA.to_string();
    ecb("Alicja.txt", keyAlicja, "AlicjaZaszyfrowany.txt");


    //Ewa odbiera wiadomosc kierowana do Boba
    //znajac klucz odszyfrowuje ja
    bitset<4> keyE2(Ke2);
    string keyEwa2 = keyE2.to_string();
    for(int i = 0; i < 15; i++)
           keyEwa2 += keyE2.to_string();
    cout << "Ewa odbiera wiadomosc od Alicji i odszyfrowuje ja zapisujac wiadomosc w pliku EwaOdszyfrowany.txt" << endl;
    ecb("AlicjaZaszyfrowany.txt", keyEwa2, "EwaOdszyfrowany.txt");

    //Ewa szyfruje drugim klucze wiadomosc i wysyla ja do Boba
    cout << "Ewa szyfruje wiadomosc drugim kluczem zgodnym z Boba" << endl;
    bitset<4> keyE1(Ke1);
    string keyEwa1 = keyE1.to_string();
    for(int i = 0; i < 15; i++)
           keyEwa1 += keyE1.to_string();
    ecb("EwaOdszyfrowany.txt", keyEwa1, "EwaZaszyfrowany.txt");

    //Bob odbiera wiadomosc i odszyfrowuje ja
    bitset<4> keyKb(Kb);
    string keyBob = keyKb.to_string();
    for(int i = 0; i < 15; i++)
           keyBob += keyKb.to_string();
    cout << "Bob odbiera wiadomosc i odszyfrowuje ja zapisujac w pliku BobOdszyfrowany.txt" << endl;
    ecb("EwaZaszyfrowany.txt", keyBob, "BobOdszyfrowany.txt");
    getchar();
}
