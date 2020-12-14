#include "std_lib_facilities.hpp"

int main()
{
    constexpr double cm_per_m = 0.01;
    constexpr double in_per_cm = 2.54;
    constexpr double ft_per_in = 12;
    string unit;

    double sum = 0;
    int number_of_values = 0;

    double number;
    double smallest = 0;
    double largest = 0;

    cout << "Enter value and unit (ft, in, m, cm): \n";
    while(cin >> number >> unit){

        if(unit == "m")
        {
            number_of_values++;
            number = number;
        }
        else if(unit == "cm")
         {
            number_of_values++;
            number = number * cm_per_m;
         }
        else if(unit == "in")
         {
            number_of_values++;
            number = number * in_per_cm * cm_per_m;
         }
        else if(unit == "ft")
         {
            number_of_values++;
            number = number * ft_per_in * in_per_cm * cm_per_m;
          }
        else
        {
        cout << "illegal unit \n";
        }
        sum = sum + number;


        if(smallest == 0 && largest == 0)
        {
            smallest = number;
            largest = number;
        }
        else if(number < smallest)
        {
            smallest = number;
        }
        else if(number > largest){
            largest = number;
        }

    }

    cout << "smallest = " << smallest << "m\n";
    cout << "largest = " << largest << "m\n";
    cout << "Sum = " << sum << "m \n";
    cout << "number of values = " << number_of_values << "\n";

    vector<double> values;
    values.push_back(smallest);
    values.push_back(largest);
    values.push_back(sum);
    values.push_back(number_of_values);

    sort(values);
    for(int i=0; i<values.size(); i++)
        cout << values[i] << "\n";

    return 0;
}
//01.03.2020
//Kamil Petk
