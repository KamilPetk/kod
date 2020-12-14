#include "std_lib_facilities.hpp"

int main()
try{
    //1.
    int v = 1; for (int i = 0; i<sizeof(v)*8; ++i) { cout << v << ' '; v <<=1; }

    cout << endl;
    cout << endl;

    //2.
    unsigned int v1 = 1; for (int i = 0; i<sizeof(v1)*8; ++i) { cout << v1 << ' '; v1 <<=1; }

    cout << endl;
    cout << endl;

    //3.
    //oraz do 4.
    vector<short unsigned int> valueVec;
    short unsigned int value;
    //a
    value = 0xffff;
    cout << "TEST: " << bitset<16>(value) << endl;
    valueVec.push_back(value);

    //b
    value = 0x0001;
    cout << "TEST: " << bitset<16>(value) << endl;
    valueVec.push_back(value);

    //c
    value = 0x8000;
    cout << "TEST: " << bitset<16>(value) << endl;
    valueVec.push_back(value);

    //d
    value = 0x00ff;
    cout << "TEST: " << bitset<16>(value) << endl;
    valueVec.push_back(value);

    //e
    value = 0xff00;
    cout << "TEST: " << bitset<16>(value) << endl;
    valueVec.push_back(value);

    //f
    value = 0x5555;
    cout << "TEST: " << bitset<16>(value) << endl;
    valueVec.push_back(value);

    //g
    value = 0xaaaa;
    cout << "TEST: " << bitset<16>(value) << endl;
    valueVec.push_back(value);

    //4.
    for(int i : valueVec)
        cout << "Dec:\t" << dec << i
            <<"\tHex:\t" << hex << i << endl;

    cout << endl;

    //5. | & <<
    short unsigned int valueOperations;
     vector<short unsigned int> valueVecOperations;
    //a
    valueOperations = ~0;//~0x0000;
    cout << "TEST: " << bitset<16>(valueOperations) << endl;
    valueVecOperations.push_back(valueOperations);

    //b
    valueOperations = 1;
    cout << "TEST: " << bitset<16>(valueOperations) << endl;
    short unsigned int valueOperations2 = valueOperations;
    valueVecOperations.push_back(valueOperations);

    //c
    valueOperations = valueOperations << 15;
    cout << "TEST: " << bitset<16>(valueOperations) << endl;
    valueVecOperations.push_back(valueOperations);

    //d
    valueOperations = valueOperations >> 15;
    for(int i = 0; i < 7; ++i)
        valueOperations = valueOperations << 1 | valueOperations;
    cout << "TEST: " << bitset<16>(valueOperations) << endl;
    valueVecOperations.push_back(valueOperations);

    //e
    valueOperations = valueOperations << 8;
    cout << "TEST: " << bitset<16>(valueOperations) << endl;
    valueVecOperations.push_back(valueOperations);

    //f
    valueOperations = valueOperations2;
    for(int i = 1; i < 8; ++i)
        valueOperations ^= valueOperations2 << i*2;
    cout << "TEST: " << bitset<16>(valueOperations) << endl;
    valueVecOperations.push_back(valueOperations);

    //g
        valueOperations = ~valueOperations;
    cout << "TEST: " << bitset<16>(valueOperations) << endl;
    valueVecOperations.push_back(valueOperations);

    for(int i : valueVecOperations)
        cout << "Dec:\t" << dec << i
            <<"\tHex:\t" << hex << i << endl;

    return 0;
}
catch (exception& e) {
    cerr << e.what() << '\n'; // write error message
    return 1;
}
catch (...) {
    cerr << "exception!\n"; // write error message
    return 2;
}
//Kamil Petk
//17.05.2020
