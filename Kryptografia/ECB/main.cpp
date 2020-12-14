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
        while(openFile >> std::noskipws >> singleCharacter)
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

int main()
{

    string fileName = "tekst.txt";
    read(fileName);

    string key = "";
    key = randomKey(key);
        cout << "Key:" << key << endl;
    //string key = "0101011011011010010110101101101000011011101000100101101011010011";

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
    cout << "Text encrypted: " << encryptedText << endl;
    save(encryptedText);
}
//KAMIL PETK
//ECB
