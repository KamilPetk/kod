#Kamil Petk nr 176648
#Symulacja dla CFB w uzyciu AES

from Crypto import Random
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
import random

class Encryptor:
    def __init__(self, key):
        self.key = key

    @staticmethod
    def padding(text):
        length = AES.block_size - (len(text) % AES.block_size)
        #print(b"\0" * length)
        #print(text + b"\0" * length)
        return text + b"\0" * length  #dopelnienie zerami

    def encrypt(self, textfromfile, key):   #szyfrowanie PyCrypto.org

        textfromfile = self.padding(textfromfile)
        #print(textfromfile)
        iv = Random.new().read(AES.block_size) #16 losowych bajtow - wektor inicjujacy
        cipher = AES.new(key, AES.MODE_CFB, iv)
        msg = iv + cipher.encrypt(textfromfile)
        return msg

    def decrypt(self, ciphertext, key): #odszyfrowanie

        iv = ciphertext[:AES.block_size] #te same 16 bajtow co w encrypt
        cipher = AES.new(key, AES.MODE_CFB, iv)
        plaintext = cipher.decrypt(ciphertext[AES.block_size:])
        #print(plaintext.rstrip(b"\0"))
        return plaintext.rstrip(b"\0")

    def file_crypt(self, fileplaintext, fileencryptedtext):
        with open(fileplaintext, 'rb') as file:
            plaintext = file.read() #odczyt z pliku
        encrypt = self.encrypt(plaintext, self.key)
        #print(encrypt)
        with open(fileencryptedtext, 'wb') as file:
            file.write(encrypt) #zapis do pliku

    def file_decrypt(self, fileencryptedtext, fileedecryptedtext):
        with open(fileencryptedtext, 'rb') as file:
            ciphertext = file.read() #odczyt z pliku zaszyfrowanego tekstu
        file.close()
        decrypt = self.decrypt(ciphertext, self.key)
        #print(decrypt)
        with open(fileedecryptedtext, 'wb') as file:
            file.write(decrypt) #zapis do pliku tekstu odszyfrowanego
        file.close()

########################################
p = 1117
g = 5

#Alicja
#wybiera losyw wykladnik a
a = random.randint(1,p-1) #zgodnie ze slajdem nr 6
print("Alicja oblicza A i wysyla do Boba")
A = (g**a) % p #wysyla do Boba

#Ewa
#odrzuca A
#wybiera losowy wykladnik c
print("Ewa odrzuca A, oblicza C i wysyla je do Boba")
c = random.randint(1,p-1)
C = (g**c) % p #wysyla do Boba

#Bob
#wybiera losowy wykladnik b
b = random.randint(1, p-1)
#uwazajac ze otrzymal C od Alicji oblicza
print("Bob uwazajac ze otrzyma C od Alicji oblicza Key")
Kb = (C**b) % p
print("Bob", Kb)
#ustawia
print("Ustawia B i wysyla do Alicji")
B = (g**b) % p #wysyla do Alicji

#Ewa
#odrzuca B i oblicza
print("Ewa odrzuca B, oblicza oba klucze")
Ke1 = (B**c) % p
print("Ewa", Ke1)
#wybiera losowy wykladnik d
d = random.randint(1,p-1)
Ke2 = (A**d) % p #oblicza
print("Ewa", Ke2)
print("Nastepnie oblicza D i wysyla do Alicji")
D = (g**d) % p #wysyla do Alicji

#Alicja
#oblicza
print("Alicja odbiera D myslac ze otrzymala je od Boba oblicza Key")
Ka = (D**a) % p
print("Alicja", Ka)

#Po ustaleniu kluczy proba szyfrowania i przeslania wiadomosci
#Alicja za pomoca obliczonego klucza szyfruje wiadomosc
print("Po ustaleniu kluczy proba szyfrowania i przeslania wiadomosci:")
KeyAlicja = (Ka).to_bytes(16, byteorder='big')
encrypt = Encryptor(KeyAlicja)
print("Alicja szyfruje wiadomosc z pliku: Alicja.txt")
encrypt.file_crypt("Alicja.txt", "AlicjaZaszyfrowany.txt" ) #szyfrowanie
print("Zapisuje w pliku AlicjaZaszyfrowany.txt i wysyla wiadomosc do Boba")

#Ewa odbiera wiadomosc kierowana do Boba
#znajac klucz odzyfrowuje ja
KeyEwa2 = (Ke2).to_bytes(16, byteorder='big')
encrypt = Encryptor(KeyEwa2)
print("Ewa odbiera wiadomosc od Alicji i odszyfrowuje ja zapisujac wiadomosc w pliku EwaOdszyfrowany.txt")
encrypt.file_decrypt("AlicjaZaszyfrowany.txt", "EwaOdszyfrowany.txt") #odszyfrowanie

#Ewa szyfruje drugim kluczem wiadomosc i wysyla ja do Boba
print("Ewa szyfruje wiadomosc drugim kluczem zgodnym z Boba")
KeyEwa1 = (Ke1).to_bytes(16, byteorder='big')
encrypt = Encryptor(KeyEwa1)
encrypt.file_crypt("EwaOdszyfrowany.txt", "EwaZaszyfrowany.txt" ) #szyfrowanie
print("Wiadomosc zaszyfrowana w pliku EwaZaszyfrowany.txt wysyla do Boba")

#Bob odbiera wiadomosc i odszyfrowuje ja
KeyBob = (Kb).to_bytes(16, byteorder='big')
encrypt = Encryptor(KeyBob)
print("Bob odbiera wiadomosc i odszyfrowuje ja zapisujac w pliku BobOdszyfrowany.txt")
encrypt.file_decrypt("EwaZaszyfrowany.txt", "BobOdszyfrowany.txt") #odszyfrowanie

input()