#include "std_lib_facilities.hpp"

double* high(double* first, double* last)
// return a pointer to the element in [first,last) that has the highest value
{
     double h = -1;
     double* high;
     for(double* p = first; p!=last; ++p)
     if (h<*p) { high = p; h = *p; }
     return high;
}

double* get_from_jack(int* count){} // Jack puts doubles into an array and
 // returns the number of elements in *count
vector<double>* get_from_jill(){} // Jill fills the vector
void fct()
{
     int jack_count = 0;
     double* jack_data = get_from_jack(&jack_count);

     vector<double>* jill_data = get_from_jill();

     // . . .
    double h = -1;
    double* jack_high = high(jack_data,jack_data+jack_count); // jack_high will point to the element with the highest value
    vector<double>& v = *jill_data;
    double* jill_high = high(&v[0],&v[0]+v.size()); // jill_high will point to the element with the highest value
    for (int i=0; i<jack_count; ++i)
        if (h<jack_data[i]) {
            jack_high = &jack_data[i]; // save address of largest element
            h = jack_data[i]; // update “largest element”
        }
    h = -1;
    for (int i=0; i< v.size(); ++i)
        if (h<v[i]) {
            jill_high = &v[i]; // save address of largest element
            h = v[i]; // update “largest element”
        }
    cout << "Jill's max: " << *jill_high
        << "; Jack's max: " << *jack_high;
    // . .
     delete[] jack_data;
     delete jill_data;
}


int main()
{
    //Ustawienie h=-1 moze powodowac bledy w przypadku wartosci ujemnych.
    //Nalezaloby uwzglednic rozpatrywanie wartosci ujemnych.
    //Moze takze wystawic problem z niezdefiniowanym wskaznikiem.
    //Rozwiazac ten problem mozna zapisujac double* high = 0;
    return 0;
}
//Kamil Petk
//03.05.2020
