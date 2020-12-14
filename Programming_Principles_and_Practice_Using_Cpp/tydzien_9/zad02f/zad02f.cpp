#include "std_lib_facilities.hpp"

template<typename Iter> // requires Forward_iterator<Iter>
void advance(Iter& p, int n, int sizeV)
{
    if(n > 0)
        while (0<n){++p; --n;}
    else if(n < 0)
    {
        p += sizeV-1;

        while (0>n)
        {
            p--;
            ++n;
        }
    }
}

int main()
{
    vector<char> v = {'a','b','c','d'};
    vector<char>::iterator p = v.begin();
    advance(p,-2, v.size());
    cout << *p << endl;

    return 0;
}
//Kamil Petk
//03.05.2020
