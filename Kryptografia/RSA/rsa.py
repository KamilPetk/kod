# RSA
# przy wykorzystaniu informacji z:
# pycryptodome.readthedocs.io
# PyCrypto.org

from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
import binascii #do wyswietlenia zaszyfrowanego tekstu w postaci liczb szesnastkowych

class Encryptor:
    def __init__(self, keySize):
        self.keySize = keySize

    def encrypt(self, plaintext, keySize):
        self.keys = RSA.generate(keySize) #generowanie pary kluczy
        publickey = self.keys.publickey() #klucz publiczny
        #SZYFROWANIE:
        encryption = PKCS1_OAEP.new(publickey)
        encryptedtext = encryption.encrypt(plaintext)
       #print("Encrypted:", binascii.hexlify(encryptedtext))
        return encryptedtext

    def decrypt(self, keys, ciphertext):
        #ODSZYFROWANIE
        decryption = PKCS1_OAEP.new(keys)
        decryptedtext = decryption.decrypt(ciphertext)
        return decryptedtext

    def file_crypt(self, fileplaintext):
        with open(fileplaintext, 'rb') as file:
            plaintext = file.read() #odczyt z pliku
        encrypt = self.encrypt(plaintext, self.keySize)
        #print(binascii.hexlify(encrypt))
        with open("encrypted.txt", 'wb') as file:
           file.write(encrypt) #zapis do pliku

    def file_decrypt(self, fileencryptedtext):
        with open(fileencryptedtext, 'rb') as file:
            ciphertext = file.read()  # odczyt z pliku zaszyfrowanego tekstu
        file.close()
        decrypt = self.decrypt(self.keys, ciphertext)
        with open('decrypted.txt', 'wb') as file:
            file.write(decrypt) #zapis do pliku tekstu odszyfrowanego
        file.close()

newencrypt = Encryptor(1024) #ustawienie dlugosci klucza

plaintextfile = "plaintext.txt"
newencrypt.file_crypt(plaintextfile) #szyfrowanie
print("Encrypt the file: ", plaintextfile)
print("The encrypted data was saved to a file: encrypted.txt")
newencrypt.file_decrypt("encrypted.txt") #odszyfrowanie
print("The decrypted data was saved to a file: decrypted.txt")

input()
#Kamil Petk
#Opis:
#Generowanie pary kluczy(czyli prywatnego i publicznego) odbywa sie w nastepujacy sposob:
#-wybieramy p i q bedace losowymi duzymi liczbami pierwszymi
#-obliczamy n = pq
#-obliczamy phi = (p-1)(q-1)
#-wybieramy liczbe wzglednie pierwsza z obliczonym phi (dla RSA.generate domyslnie jest to 65537)
#-znajdujemy d:
#d*e=1( mod phi(n) )
#Klucz publiczny - jest definiowany jako para liczb (n,e)
#Klucz prywatny - jest definiowany jako para liczb (n,d)
#Szyfrowanie odbywa sie przez podzielenie danych na bloki m o wartosci nie wiekszej niz n
#Nastepnie szfrowanie c = m^e (mod n) i otrzymujemy szyfrogram
#Deszyfrowanie: m = c^d (mod n) i otrzymujemy tekst jawny