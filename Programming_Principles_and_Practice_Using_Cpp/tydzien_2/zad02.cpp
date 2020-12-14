#include <iostream>
#include "std_lib_facilities.hpp"

int main()
{
    try{
    int number;
    int value_sum;
    int sum = 0;
    vector<int> numbers;

    cout << "Please enter the number of values you want to sum: \n";
    cin >> value_sum;

    cout << "Please enter some integers (press '|' to stop): \n";
    while(cin >> number)
         numbers.push_back(number);

    for(int i=0; i<value_sum; i++)
        sum += numbers[i];

    cout << "The sum of the firs " << value_sum << " numbers (";
    for(int j = 0; j<value_sum; j++)
        cout << " " << numbers[j] << " ";
    cout << ") is " << sum;
    return 0;
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
}
}
//Kamil Petk
//07.03.2020
