#include "std_lib_facilities.hpp"

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
 // return an iterator to the element in [first:last) that has the highest value
{
    Iterator high = first;
    for (Iterator p = first; p!=last; ++p)
        if (*high<*p) high = p;
    return high;
}
double* get_from_jack(int* count){} // Jack puts doubles into an array and
 // returns the number of elements in *count
vector<double>* get_from_jill(){}// Jill fills the vector
void fct()
{
     int jack_count = 0;
     double* jack_data = get_from_jack(&jack_count);
     vector<double>* jill_data = get_from_jill();

     double* jack_high = high(jack_data,jack_data+jack_count);
     vector<double>& v = *jill_data;
     double* jill_high = high(&v[0],&v[0]+v.size());
     cout << "Jill's high " << *jill_high << "; Jack's high " << *jack_high;
    // . . .
    delete[] jack_data;
    delete jill_data;
}
int main()
{

    return 0;
}
//Kamil Petk
//03.05.2020
