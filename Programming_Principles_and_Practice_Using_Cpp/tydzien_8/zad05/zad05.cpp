#include "std_lib_facilities.hpp"

template<typename T, typename U> T sumVec(const vector<T>& vt, const vector<U>& vu) // function template
{
    if(vt.size() == vu.size())
    {
    T sum = 0.0;
    for (int i = 0; i < vt.size(); i++)
        sum += vt[i] * vu[i];
    return sum;
    }
    else
        return 0;
}

int main()
{
    vector<int> v1{1, 2, 3};
    vector<int> v2{1, 2, 3};
    double sum = sumVec(v1, v2);
    cout << "Sum +=v1[i] * v2[i] = " << sum << endl;

    return 0;
}
//Kamil Petk
//24.04.2020
