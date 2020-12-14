#include "std_lib_facilities.hpp"

using namespace std;

vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(vector<int> myVector)
{
    vector<int> lv(10);
    lv = myVector;

    cout << "lv:" << endl;
    for(int i = 0; i < lv.size(); i++)
        cout << lv[i] << ", ";
    cout << endl << "lv2:" << endl;
    vector<int> lv2(myVector);
    for(int i = 0; i < lv2.size(); i++)
        cout << lv2[i] << ", ";
}

int main()
{
    f(gv);
    vector<int> vv(10);
    vv[0] = 1;

    for(int i = 1; i < 10; i++)
    {
        vv[i] = vv[i-1]*(i+1);
        if(i != 9)
            vv[i+1] = vv[i];
    }
    cout << endl << "f(vv):" << endl;
    f(vv);
    return 0;
}
//Kamil Petk
//21.04.2020
