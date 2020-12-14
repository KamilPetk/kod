#include "std_lib_facilities.hpp"

void check(const list<int> lis, vector<double> vec)
{
    bool tf = 0; //0 same, 1 different
    //SIZE
    if(lis.size() == vec.size()){
        cout << "The size is the same" << endl;
        //ELEMENTS
        int i = 0;
        for(list<int>::const_iterator p = lis.begin(); p != lis.end(); p++)
        {
            if(*p == vec[i])
            {}else{
                cout << *p <<" and " << vec[i] << " are different" << endl;
                tf = 1;
            }
            i++;
        }
    }else
        cout << "The Size is different" << endl;
    if(tf == 0)
        cout << "Elements are the same" << endl;
    else{}

}

void myCopy(const list<int>& lis)
{
    vector<double> vec;
    for(list<int>::const_iterator p = lis.begin(); p != lis.end(); p++)
        vec.push_back(*p);
    /*
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << endl;
    */
    check(lis, vec);
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << endl;
}

int main()
{
    list<int> lis {5,1,2,4,8,3,7};
    /*
    for(list<int>::iterator p = lis.begin(); p != lis.end(); p++)
            cout << *p << endl;
    */
    myCopy(lis);

    return 0;
}
//Kamil Petk
//04.05.2020
