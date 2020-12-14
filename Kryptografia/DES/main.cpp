#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
#include "std_lib_facilities.hpp"

vector<char> char_in_vector;

void read(std::string nameFileRead)
{
    ifstream openFile(nameFileRead);

    if(openFile.is_open())
    {
        char singleCharacter;
        while(openFile >> noskipws >> singleCharacter)
        {
                //std::cout << singleCharacter;
            char_in_vector.push_back(singleCharacter);
        }
        }else std::cout << "Error while reading";
}

std::string charToString(vector<char> charVector)
{
    std::string outputString;
    std::stringstream stringOperation; //w celu operacji na ciagu znakow
    for(int i = 0; i < charVector.size(); i++)
    {
        stringOperation << charVector[i];
        outputString = stringOperation.str();
    }
    return outputString;
}

std::string TextToBinaryString(std::string words) { //pobiera 8 znakow i zamienia je na postac binarna
        //cout << endl << words;
    std::string binaryString = "";

    for (char& character : words) { //pozwala petli zmodyfikowaæ jej argumenty dzieki zastosowaniu odniesienia & -
        binaryString +=bitset<8>(character).to_string(); //zamiana po kolei kazdego znaku na postac binarna
    }
        //cout << endl << binaryString;
    return binaryString;
}

int forInitialPermutation[64] = {64, 55, 41, 61, 25, 59, 58, 57,
                                 56, 63, 54, 53, 52, 51, 34, 49,
                                 28, 47, 22, 29, 44, 43, 42, 62,
                                 40, 39, 38, 37, 36, 35, 50,  9,
                                  5, 31,  1, 45, 48, 17, 26, 60,
                                 24, 23, 46, 21, 20, 19, 18, 27,
                                 16, 15, 14, 13,  4, 11, 10, 33,
                                  8,  7,  6,  32, 12, 3,  2, 30};

int forExplain[48] = { 17,  31,  31,  29,  13,  6,  7, 16,
                        9,  10,  11,  12,   5, 14, 15,  8,
                        1,  18,  19,  20,  21, 22, 23, 32,
                       25,   2,  27,  28,  29, 30, 31, 24,
                        6,  29,   3,  31,  15, 31, 30, 16,
                        1,  31,  26,  31,   7, 31, 1, 6};


int forKeyPermutation[56] = { 55,  2, 11,  9,  5,  6,  7, 16,
                               9, 10,  3, 12, 21, 22, 31,  8,
                              17, 18, 19, 20, 13, 55, 23, 24,
                              25, 26, 27, 28, 29, 30, 15, 32,
                               5, 55, 35, 45, 55, 14, 55, 32,
                              17,  3, 35, 15,  4, 55, 31,  7,
                               9, 55, 25, 55, 11, 14, 56, 18};

int moveKey[56] = { 2,  3,  4,  5,  6,  7,  8, 9,
                   10, 11, 12, 13, 14, 15, 16, 17,
                   18, 19, 20, 21, 22, 23, 24, 25,
                   26, 27, 28, 29, 30, 31, 32, 33,
                   34, 35, 36, 37, 38, 39, 40, 41,
                   42, 43, 44, 45, 46, 47, 48, 49,
                   50, 51, 52, 53, 54, 55, 56, 1 };

int key48[48] = { 11, 13,  4, 25,  6,  7, 18,  9,
                  10,  2, 20, 13, 14, 15, 16, 17,
                  18, 19, 12, 21, 22, 46, 24, 33,
                  26, 27,  4, 10, 44, 31, 32, 24,
                  34, 35, 36, 37, 38, 39, 55, 41,
                  42,  3, 5,  45, 23, 47, 48,  1};

int s_boxes[8][4][16] = {
                        {14,  4,  13, 1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7, //wartosci zaczerpniete z wikipedii
                          0, 15,   7, 4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
                          4,  1,  14, 8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
                         15, 12,   8, 2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13},

						{15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
						  3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
						  0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
						 13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9},

						{10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
						 13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
						 13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
						  1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12},

						{ 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
						 13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
						 10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
						  3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14},

						{ 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
						 14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
						  4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
						 11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3},

						{12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
						 10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
						  9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
						  4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13},

						{ 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
						 13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
						  1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
						  6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12},

						{13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
						  1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
						  7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
						  2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11}
                                                                                       };

int p_box[32] = { 10, 2,   3, 28, 21, 30, 15,  8,
                  25, 1,  27, 12, 31, 14,  7, 16,
                  17, 18, 19, 20,  3, 22, 23, 24,
                   9, 26, 11,  4, 29,  6, 13, 30};

int forFinalPermutation[64] = { 64, 55, 41, 61, 25, 59, 58, 57,
                                56, 63, 54, 53, 52, 51, 34, 49,
                                28, 47, 22, 29, 44, 43, 42, 62,
                                40, 39, 38, 37, 36, 35, 50,  9,
                                60, 26, 17, 48, 45,  1,  31, 5,
                                62, 42, 43, 44, 29, 22, 47, 28,
                                49, 34, 51, 52, 53, 54, 63, 56,
                                57, 58, 59, 25, 61, 41, 55, 64};

std::string returnEncryptedText(std::string encryptedTextBinary)
{
    std::stringstream sstream(encryptedTextBinary);
    std::string output;

        std::bitset<8> bits;
        sstream >> bits;
            //std::cout << "\n bits" << bits;
        char c = char(bits.to_ulong()); //to_ulong - liczba bin jako liczba int
        output += c;

            //std::cout << "\nwyjscie:" << output;
        return output; //zwraca tekst w postaci string
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

void prepareToFile(std::string cryptogramBin)
{
        //std::cout << "\nCryptogramBin:" << cryptogramBin;
    std::string next8bits = "";
    std::string encryptedText = "";
    int n = 0;
    while(n < cryptogramBin.size())
    {
        for(int i = 0; i < 8; i++)
        {
            next8bits += cryptogramBin[i+n];
        }
        encryptedText += returnEncryptedText(next8bits);
            //std::cout << "Text: " << encryptedText << std::endl;
        next8bits.clear();
        n += 8;
    }
        std::cout << encryptedText;

    save(encryptedText);//ZAPIS DO PLIKU KOLEJNEGO BLOKU
}

std::string permutation(std::string k, int* tab, int n) //zamienia bity miejscami
{
   // std::cout << std::endl << k << std::endl;

	std::string per = "";
	for (int i = 0; i < n; i++) {
		per += k[tab[i] - 1];
	}
	return per;
}

std::string xorOperation48(std::string text, std::string key_i){
    int j = 0;
    int bitAsInt;
    std::bitset<48> allBitsEncrypted;
    for(int k = 47; k>=0; k--)
    {
        std::bitset<1> calc_xor = text[j]^key_i[j];
        bitAsInt = (int)(calc_xor.to_ulong()); //postac binarna przedstawiona jako int
        allBitsEncrypted[k] = bitAsInt;
        j++;
    }
    std::string binaryEncryptedText = allBitsEncrypted.to_string();
    return binaryEncryptedText;
}

std::string xorOperation32(std::string right, std::string left){
    int j = 0;
    int bitAsInt;
    std::bitset<32> allBitsEncrypted;
    for(int k = 31; k>=0; k--)
    {
        std::bitset<1> calc_xor = right[j]^left[j];
        bitAsInt = (int)(calc_xor.to_ulong()); //postac binarna przedstawiona jako int
        allBitsEncrypted[k] = bitAsInt;
        j++;
    }
    std::string binaryEncryptedText = allBitsEncrypted.to_string();
    return binaryEncryptedText;
}



void s_box(std::string afterXOR, std::string leftBits, std::string rightBits)
{
        //std::cout << std::endl << afterXOR << std::endl;
    std::string next6chars = "";
    int k = 0;
    std::string new32bits = "";
    for(int n = 0; n < 8; n++) //wykonuje sie 8 razy bo 8 s-boxow
    {
        for(int j = 0; j < 6; j++)//pobiera po 6 znakow
            next6chars += afterXOR[j+k];
            //std::cout << std::endl << "next6chars" << next6chars << std::endl;
        std::string xx[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
                          "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

        std::string yy[4] = {"00", "01", "10", "11"};

        std::string next6chars_x = "";
            for(int i = 1; i < 5; i++)
                next6chars_x += next6chars[i];
            //std::cout << "next6chars x" << next6chars_x << std::endl;

        std::string next6chars_y = "";
            for(int i = 0; i < 6; i+=5)
                next6chars_y += next6chars[i];
            //std::cout << "next6chars y" << next6chars_y << std::endl;

        int x[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        int y[4] = {0, 1, 2, 3};
        int myX;
        for(int i = 0; i < 16; i++)
        {
            if(next6chars_x == xx[i])
                myX = i;
        }

        int myY;
        for(int i = 0; i < 16; i++)
        {
            if(next6chars_y == yy[i])
                myY = i;
        }
                            // 1 - s-box, 2-wiersz, 3-ktora wartosc
            //std::cout << "BOX: " << s_boxes[n][myY][myX] << std::endl;
         std::string binary = std::bitset<4>(s_boxes[n][myY][myX]).to_string();
            //std::cout << "\nAsBin:" << binary;

         new32bits += binary;
            //std::cout << "\nMy32bits: " << new32bits;

         k += 6;
         next6chars.clear();
         next6chars_x.clear();
         next6chars_y.clear();
    }
        //std::cout << "\nMy32bits: " << new32bits;

    //PERMUTATION P-BOX
    std::string new32bitsAfterPermutation = permutation(new32bits, p_box, 32);
        //std::cout << "\nAfterPer: " << new32bitsAfterPermutation; //PO PERMUTACJI

    std::string new32bitsAfterXOR = xorOperation32(new32bitsAfterPermutation, leftBits);
        //std::cout << std::endl << "AfterXOR: " << new32bitsAfterXOR;

        //std::cout << "\nOld right " << rightBits;
   leftBits = rightBits; //NOWA LEWA POLOWA
        //std::cout << "\nNew left: " << leftBits;
   rightBits = new32bitsAfterXOR; //NOWA PRAWA POLOWA
        //std::cout << "\nNew right " << rightBits;

   std::string cryptogramBits = "";
   cryptogramBits += leftBits;
   cryptogramBits += rightBits;
        //std::cout << std::endl << "cryptogram" << cryptogramBits;
   //PERMUTACJA KONCOWA
   std::string cryptogramBin = permutation(cryptogramBits, forFinalPermutation, 64);
        //std::cout << std::endl << "cryptogramAfterPerm:" << cryptogramBin;

   prepareToFile(cryptogramBin);
}

std::string randomKey(std::string randKey)
{
    srand(time(NULL));
    for(int i = 0; i < 64; i++)
    {
        int x = rand()%2;
            //cout << x << endl;
        std::stringstream ss;
        ss << x;
        std::string str = ss.str();
            //cout << "str" << str << endl;
        randKey += str;
    }
    return randKey;
}

int main()
{
    //LOSOWANIE KLUCZA
    std::string randKey = "";
    randKey = randomKey(randKey);
        std::cout << "Key:" << randKey << std::endl;

    std::string fileName = "tekst.txt";
    read(fileName);
        //std::cout << std::endl << char_in_vector[0];

    //JESLI ROZMIAR WEKTORA != 8
        //std::cout << "ROZMIAR WEKTORA: " << char_in_vector.size() << std::endl;
    int vectorSize = char_in_vector.size();
    while(vectorSize %8 != 0)
    {
        char_in_vector.push_back(' ');
        vectorSize++;
    }
        //std::cout << "ROZMIAR WEKTORA: " << char_in_vector.size() << std::endl;
//PIERWSZE 8 ZNAKOW/////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\nText encrypted: ";
    int n = 0;
    while(vectorSize != 0)
    {

    vector<char> blockText;

    for(int i = 0; i < 8; i++) //PIERWSZY ETAP
    {
        char nextChar = char_in_vector[i+n];
        blockText.push_back(nextChar); //WEKTOR Z PIERWSZYMI 8 ZNAKAMI
    }
    std::string stringCharacters;
    stringCharacters = charToString(blockText);//Odczytane 8 znakow
        //std::cout << "\nText:" << stringCharacters;

    std::string plainText = TextToBinaryString(stringCharacters);//Odczytane 8 znakow w postaci binarnej BLOKI PO 64 bity
        //std::cout << "\nPlain Text: " << plainText;

    //std::string plainText = "1111011101101011101110111010111011101111011011101000101111011011";
    //std::cout << plainText.size();

    //std::cout << plainText;

	//WSTEPNA PERMUTACJA
	std::string plainTextAfterPermutation = permutation(plainText, forInitialPermutation, 64);
	//std::cout << plainTextAfterPermutation;

	//PODZIAL
	int sizePlainText = plainTextAfterPermutation.size();
	std::string leftBits = plainTextAfterPermutation.substr( 0, (sizePlainText)/2 );
	std::string rightBits = plainTextAfterPermutation.substr( (sizePlainText)/2, sizePlainText );

        //std::cout << "left: \t" << leftBits << "\nright: \t" << rightBits;

    std::string rightBitsAfterExplain = permutation(rightBits, forExplain, 48);
    //std::cout << std::endl << rightBitsAfterExplain;

    //std::string key = "1010101010100110110101010100110010100101101010011010100101001101";
    std::string key = randKey;
        //std::cout << std::endl << "KLUCZ" << key

	key = permutation(key, forKeyPermutation, 56);//WYBRANIE 56 z 64
        //std::cout << std::endl << "56 key: " << key << std::endl;

	std::string keyAfterMove = permutation(key, moveKey, 56); //przesuniecie o jeden
        //std::cout << "keyAfte:" << keyAfterMove << std::endl;

    std::string key_i = permutation(keyAfterMove, key48, 48);//WYBRANIE 48 Z 56
        //std::cout << "key_i48:" << key_i << std::endl;

    std::string afterXOR = xorOperation48(rightBitsAfterExplain, key_i);
        //std::cout << "AfterXor" << afterXOR << std::endl;

    s_box(afterXOR, leftBits, rightBits);

    blockText.clear();
    n += 8;
    vectorSize -= 8;
    }
    std::cout << std::endl;
    return 0;
}
//KAMIL PETK
//DES
