from Crypto import Random
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

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

    def file_crypt(self, fileplaintext):
        with open(fileplaintext, 'rb') as file:
            plaintext = file.read() #odczyt z pliku
        encrypt = self.encrypt(plaintext, self.key)
        #print(encrypt)
        with open("encrypted.txt", 'wb') as file:
            file.write(encrypt) #zapis do pliku

    def file_decrypt(self, fileencryptedtext):
        with open(fileencryptedtext, 'rb') as file:
            ciphertext = file.read() #odczyt z pliku zaszyfrowanego tekstu
        file.close()
        decrypt = self.decrypt(ciphertext, self.key)
        #print(decrypt)
        with open('decrypted.txt', 'wb') as file:
            file.write(decrypt) #zapis do pliku tekstu odszyfrowanego
        file.close()

key = get_random_bytes(16)

encrypt = Encryptor(key)
plaintextfile = "plaintext.txt"
print("Encrypt the file: ", plaintextfile)
encrypt.file_crypt(plaintextfile) #szyfrowanie
print("The encrypted data was saved to a file: encrypted.txt")

print("The decrypted data was saved to a file: decrypted.txt")
encrypt.file_decrypt('encrypted.txt') #odszyfrowanie

input()
#Kamil Petk