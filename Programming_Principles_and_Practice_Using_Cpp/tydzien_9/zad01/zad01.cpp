#include "std_lib_facilities.hpp"

template<typename Iter1, typename Iter2> //page 728
 // requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 new_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for(Iter1 p = f1; p != e1; ++p)
    {
        *f2++ = *f1++;
    }
    return f2;
}

int main()
try{
    array<int,10> ten = {0,1,2,3,4,5,6,7,8,9};

    vector<int> vten;
    for(int i = 0; i < sizeof(ten)/sizeof(int); i++)
        vten.push_back(ten[i]);

    /*
    for(int i = 0; i < vten.size();++i)
            cout << vten[i] << endl;
    */

    list<int> lten;

    for(int i = 0; i < sizeof(ten)/sizeof(int); i++)
        lten.push_back(ten[i]);

    /*
    for(list<int>::iterator p = lten.begin(); p != lten.end(); p++)
            cout << *p << endl;
    */
    array<int,10> ten2 = ten;
    vector<int> vten2 = vten;
    list<int> lten2 = lten;

    /* for(auto p = f1.begin(); p != f1.end(); ++p)
    {
        cout << *p << endl;
    }
    for(int i = 0; i < sizeof(ten2)/sizeof(int); i++)
        cout << ten2[i] << endl;
    */
    /*
    for(int i = 0; i < vten2.size();++i)
            cout << vten2[i] << endl;
    */
    /*
    for(list<int>::iterator p = lten2.begin(); p != lten2.end(); p++)
            cout << *p << endl;
    */
    for(array<int,10>::iterator p = ten2.begin(); p != ten2.end(); p++)
        *p += 2;
    /*
    for(int i = 0; i < sizeof(ten2)/sizeof(int); i++)
        cout << ten2[i] << endl;
    */
    for(vector<int>::iterator p = vten2.begin(); p != vten2.end(); p++)
        *p += 3;
    /*
    for(int i = 0; i < vten2.size();++i)
            cout << vten2[i] << endl;
    */
    for(list<int>::iterator p = lten2.begin(); p != lten2.end(); p++)
        *p += 5;
    /*
    for(list<int>::iterator p = lten2.begin(); p != lten2.end(); p++)
        cout << *p << endl;
    */

    new_copy(ten2.begin(), ten2.end(), vten2.begin());
    for(int i = 0; i < vten2.size();++i)
            cout << vten2[i] << endl;
        cout << endl;
    new_copy(lten2.begin(), lten2.end(), ten2.begin());
    for(int i = 0; i < sizeof(ten2)/sizeof(int); i++)
        cout << ten2[i] << endl;
        ////////////////////////////////////////////////////////
    vector<int>::iterator p = find(vten2.begin(), vten2.end(), 3);
    if(*p == 3)
    {
        int n = 0;
        for(auto p2 = vten2.begin(); p != p2; ++p2){n++;}
        cout << "Found 3. Position = " << n << endl;
    }else
        cout << "Not found 3" << endl;

    list<int>::iterator pl = find(lten2.begin(), lten2.end(), 27);
    if(*pl == 27)
    {
        int n = 0;
        for(auto p2 = lten2.begin(); pl != p2; ++p2){n++;}
        cout << "Found 27. Position = " << n << endl;
    }else
        cout << "Not found 27" << endl;

    return 0;
}
catch (exception& e) {
    cerr << e.what() << '\n'; // write error message
    keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "exception!\n"; // write error message
    keep_window_open("~~");
    return 2;
}
//Kamil Petk
//03.05.2020
