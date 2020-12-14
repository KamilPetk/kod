#include "std_lib_facilities.hpp"

ostream& print_array(ostream& os, int* a, int n)
{
    for (int i = 0; i < n; i++)
        os << a[i] << ", ";
    return os;
}

ostream& print_vector(ostream& os, vector<int>& a, int n)
{
    for (int i = 0; i < n; i++)
        os << a[i] << ", ";
    return os;
}

int main()
{
    int* ten = new int[10];
    int m = 100;
        for(int i = 0; i < 10; i++)
        {
            ten[i] = m;
            m++;
        }
        for(int i = 0; i < 10; i++)
        {
            cout << ten[i] << ",";
        }
        cout << endl;
        print_array(cout, ten, 10);
        delete[] ten;

        int* eleven = new int[11];
        int k = 100;
        for(int i = 0; i < 11; i++)
        {
            eleven[i] = k;
            k++;
        }
        cout << endl;
        print_array(cout, eleven, 11);
        delete[] eleven;

        int* twenty = new int[20];
        int z = 100;
        for(int i = 0; i < 20; i++)
        {
            twenty[i] = z;
            z++;
        }
        cout << endl;
        print_array(cout, twenty, 20);
        delete[] twenty;

        cout << endl;
        vector<int> tenV(10);
        int w = 100;
        for(int i = 0 ; i < 10; i++)
        {
            tenV[i] = w;
            w++;
        }
        print_vector(cout, tenV, 10);

        cout << endl;
        vector<int> elevenV(11);
        int q = 100;
        for(int i = 0 ; i < 11; i++)
        {
            elevenV[i] = q;
            q++;
        }
        print_vector(cout, elevenV, 11);

        cout << endl;
        vector<int> twentyV(20);
        int o = 100;
        for(int i = 0 ; i < 20; i++)
        {
            twentyV[i] = o;
            o++;
        }
        print_vector(cout, twentyV, 20);

    return 0;
}
//Kamil Petk
//14.04.2020
