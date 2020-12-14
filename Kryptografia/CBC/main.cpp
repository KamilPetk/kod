#include <iostream>
#include <fstream>
#include <bitset>
#include "std_lib_facilities.hpp"
#include <string>
#include <sstream>

vector<char> char_in_vector;

void read(string nameFileRead)
{
    ifstream openFile(nameFileRead);

    if(openFile.is_open())
    {
        char singleCharacter;
        while(openFile >> noskipws >> singleCharacter)
        {
            char_in_vector.push_back(singleCharacter);
        }
        }else cout << "Error while reading";
}

void save(string textToSave)
{

    fstream openFileToSave;

    openFileToSave.open("plik.txt", ios::out | ios::app);
    if(openFileToSave.good() == true)
    {
        openFileToSave << textToSave;
        openFileToSave.close();
    }
}

string TextToBinaryString(string words) { //pobiera 8 znakow i zamienia je na postac binarna
        //cout << endl << words;
    string binaryString = "";

    for (char& character : words) { //pozwala petli zmodyfikowaæ jej argumenty dziêki zastosowaniu odniesienia & -
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
        //cout << "\n" << encryptedTextBinary;
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

int main()
{
    string key = "";
    key = randomKey(key);
        cout << "Key:" << key << endl;

    //string key = "0101011011011010010110101101101000011011101000100101101011010011";
    vector<char> intializationVector = {'a', '3', 'z', 'q', '2', 'b' , '.', 'L'};

    string fileName = "tekst.txt";
    read(fileName);

//JESLI ROZMIAR WEKTORA != 8
        //cout << "ROZMIAR WEKTORA: " << char_in_vector.size() << endl;
    int vectorSize = char_in_vector.size();
    while(vectorSize %8 != 0)
    {
        char_in_vector.push_back(' ');
        vectorSize++;
    }
        //cout << "ROZMIAR WEKTORA: " << char_in_vector.size() << endl;
//FIRST 8 CHARS/////////////////////////////////////////////////////////////////////////////////////////////////////
    vector<char> firstBlockText;
    int n = 0;//W CELU ZAPISANIA NA KTORYM ZNAKU ZAKONCZE PIERWSZY ODCZYT
    for(int i = 0; i < 8; i++) //PIERWSZY ETAP
    {
        char nextChar = intializationVector[i] ^ char_in_vector[i];
        firstBlockText.push_back(nextChar); //WEKTOR Z PIERWSZYMI 8 ZNAKAMI PO XOR
        n++;
    }
    string firstStringCharacters;
    firstStringCharacters = charToString(firstBlockText);//Odczytane wszystkich znakow

    string firstEightBin = TextToBinaryString(firstStringCharacters);//Odczytane pierwszych 8 znakow w postaci binarnej BLOKI PO 64 bity

    string firstEncryptedTextBinary = encryptedTextBits(firstEightBin, key);//zaszyfrowny pierwszy tekst w postaci binarnej
    string firstEncryptedText = "";
    firstEncryptedText = returnEncryptedText(firstEncryptedTextBinary);//pierwszy zaszyfrowny tekst w postaci znakow
        cout << "Text encrypted: " << firstEncryptedText;
    save(firstEncryptedText); //ZAPIS DO PLIKU PIERWSZEGO BLOKU


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    vectorSize -= 8;
    while(vectorSize != 0){
    vector<char> firstBlockTextEncrypted;
    for(int j = 0; j < 8; j++)
        firstBlockTextEncrypted.push_back(firstEncryptedText[j]);
    //cout << endl << firstBlockTextEncrypted[0];

    vector<char> nextBlockText;
    for(int p = 0; p < 8; p++) //PIERWSZY ETAP
    {
            //cout << char_in_vector[(p+n)];
            //cout << firstBlockTextEncrypted[p];
        char nextChar = firstBlockTextEncrypted[p] ^ char_in_vector[(p+n)];
        nextBlockText.push_back(nextChar); //WEKTOR Z KOLEJNYMI 8 ZNAKAMI PO XOR
            //cout << nextBlockText[p];
    }

    string nextStringCharacters;
    nextStringCharacters = charToString(nextBlockText);//Odczytane wszystkich znakow
        //cout << nextStringCharacters;
    string nextEightBin = TextToBinaryString(nextStringCharacters);//Odczytane pierwszych 8 znakow w postaci binarnej BLOKI PO 64 bity
        //cout << nextEightBin;
    string nextEncryptedTextBinary = encryptedTextBits(nextEightBin, key);//zaszyfrowny pierwszy tekst w postaci binarnej
        //cout << nextEncryptedTextBinary;
    string nextEncryptedText = "";
    nextEncryptedText = returnEncryptedText(nextEncryptedTextBinary);//pierwszy zaszyfrowny tekst w postaci znakow
       //cout << nextEncryptedText << endl;

    save(nextEncryptedText);//ZAPIS DO PLIKU KOLEJNEGO BLOKU
        //cout << firstBlockTextEncrypted.size() << endl;

    firstBlockTextEncrypted.clear(); //WYCZYSZCZENIE ZAWARTOSCI WEKTORA
        //cout << firstBlockTextEncrypted.size();
    nextBlockText.clear();

    firstEncryptedText = nextEncryptedText;
        cout << firstEncryptedText;


    n += 8;
    vectorSize -= 8;

        //cout << endl << vectorSize;
    }
    cout << endl;
}
//KAMIL PETK
//CBC
