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
    vector<char> initializationVector = {'a', '3', 'z', 'q', '2', 'b' , 'w', 'L'};
//INITIALIZATION VECTOR XOR KEY
    string initializationVectorString;
    initializationVectorString = charToString(initializationVector);//Odczytane wszystkich znakow
        //cout << initializationVectorString << endl;

    string initializationVectorBin = TextToBinaryString(initializationVectorString);
        //cout << initializationVectorBin << endl;

    string initializationXORVectorKey = encryptedTextBits(initializationVectorBin, key);
        //cout << initializationXORVectorKey << endl;
///////////////////////////////

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

    //PIERWSZE 8 ZNAKOW/////////////////////////////////////////////////////////////////////////////////////////////////////
    vector<char> firstBlockText;
    int n = 0;//W CELU ZAPISANIA NA KTORYM ZNAKU ZAKONCZE PIERWSZY ODCZYT
    for(int i = 0; i < 8; i++) //PIERWSZY ETAP
    {
        char nextChar = char_in_vector[i];
        firstBlockText.push_back(nextChar); //WEKTOR Z PIERWSZYMI 8 ZNAKAMI TEKSTU
            //cout << firstBlockText[i] << endl;
        n++;
    }

    string firstStringCharacters;
    firstStringCharacters = charToString(firstBlockText);//Odczytane wszystkich znakow
        //cout << firstStringCharacters << endl;

    string firstStringCharactersBin = TextToBinaryString(firstStringCharacters);
        //cout << firstStringCharactersBin << endl;

    string xorFirstTextBin = encryptedTextBits(initializationXORVectorKey, firstStringCharactersBin);
        //cout << xorFirstTextBin << endl;

    string firstEncryptedText;
    firstEncryptedText = returnEncryptedText(xorFirstTextBin);//pierwszy zaszyfrowny tekst w postaci znakow
        cout << "Text encrypted: " << firstEncryptedText;
    save(firstEncryptedText); //ZAPIS DO PLIKU PIERWSZEGO BLOKU

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   vectorSize -= 8;
        //cout << endl << vectorSize;
    while(vectorSize != 0){
    string firstTextXorKey = encryptedTextBits(xorFirstTextBin, key); //zaszyfrowany poprzedni blok tekstu ^ key
        //cout << firstTextXorKey << endl;

    vector<char> nextBlockText;
    for(int k = 0; k < 8; k++)
    {
        char nextChar = char_in_vector[(n+k)];
        nextBlockText.push_back(nextChar);
            //cout << endl << nextBlockText[k];

    }

    string nextStringCharacters;
    nextStringCharacters = charToString(nextBlockText);
       //cout << nextStringCharacters << endl;

    string nextStringCharactersBin = TextToBinaryString(nextStringCharacters);
        //cout << nextStringCharactersBin << endl;

    string nextXOR = encryptedTextBits(firstTextXorKey, nextStringCharactersBin);
        //cout << nextXOR << endl;

    string nextEncryptedText;
    nextEncryptedText = returnEncryptedText(nextXOR);//kolejny zaszyfrowny tekst w postaci znakow
        cout << nextEncryptedText;
    save(nextEncryptedText); //ZAPIS DO PLIKU PIERWSZEGO BLOKU

    //przygotowanie do kolejnego kroku
    xorFirstTextBin = nextXOR;
        //cout << endl << xorFirstTextBin;

    nextBlockText.clear();
        //cout << endl << nextBlockText.size();

    n += 8;
    vectorSize -= 8;
        //cout << endl << vectorSize;
    }

}
//KAMIL PETK
//CFB
