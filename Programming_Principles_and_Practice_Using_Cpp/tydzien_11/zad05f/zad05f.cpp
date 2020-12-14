#include "std_lib_facilities.hpp"

void encipher(
     const unsigned long *const v,
     unsigned long *const w,
     const unsigned long * const k)
{
     static_assert(sizeof(long)==4,"size of long wrong for TEA");
     unsigned long y = v[0];
     unsigned long z = v[1];
     unsigned long sum = 0;
     const unsigned long delta = 0x9E3779B9;
     for (unsigned long n = 32; n-->0; ) {
     y += (z<<4 ^ z>>5) + z^sum + k[sum&3];
     sum += delta;
     z += (y<<4 ^ y>>5) + y^sum + k[sum>>11 & 3];
     }
     w[0]=y;
     w[1]=z;
}

void decipher(
     const unsigned long *const v,
     unsigned long *const w,
     const unsigned long * const k)
{
     static_assert(sizeof(long)==4,"size of long wrong for TEA");
     unsigned long y = v[0];
     unsigned long z = v[1];
     unsigned long sum = 0xC6EF3720;
     const unsigned long delta = 0x9E3779B9;
    // sum = delta<<5, in general sum = delta * n
     for (unsigned long n = 32; n-- > 0; ) {
     z -= (y << 4 ^ y >> 5) + y ^ sum + k[sum>>11 & 3];
     sum -= delta;
     y -= (z << 4 ^ z >> 5) + z ^ sum + k[sum&3];
     }
     w[0]=y;
     w[1]=z;
}

int main() // sender
{
     const int nchar = 2*sizeof(long); // 64 bits
     const int kchar = 2*nchar; // 128 bits
     string op;
     string key = "bs";
     string infile = "tekst.txt";
     string outfile = "tekst_na_wyjsciu.txt";
     //cout << "please enter input file name, output file name, and key:\n";
     cout << "The results were saved in tekst_na_wyjsciu.txt";
     //cin >> infile >> outfile >> key;
     while (key.size()<kchar) key += '0'; // pad key
     ifstream inf(infile);
     ofstream outf(outfile);
     if (!inf || !outf) error("bad file name");

     const unsigned long* k =
        reinterpret_cast<const unsigned long*>(key.data());

    unsigned long inptr[2];
    char outbuf[nchar+1];
    outbuf[nchar]=0; // terminator
    unsigned long* outptr = reinterpret_cast<unsigned long*>(outbuf);
    inf.setf(ios_base::hex ,ios_base::basefield); // use hexadecimal input

    while (inf>>inptr[0]>>inptr[1]) {
         decipher(inptr,outptr,k);
         outf<<outbuf;
    }
}
//Kamil Petk
//17.05.2020
