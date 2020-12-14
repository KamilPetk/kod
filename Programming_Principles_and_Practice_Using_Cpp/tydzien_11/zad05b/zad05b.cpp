#include "std_lib_facilities.hpp"

/*
void poor(Shape* p, int sz) // poor interface design
{
    for (int i = 0; i<sz; ++i) p[i].draw();
}

void f(Shape* q, vector<Circle>& s0) // very bad code
{
     Polygon s1[10];
     Shape s2[10];
     // initialize
     Shape* p1 = new Rectangle{Point{0,0},Point{10,20}};
     poor(&s0[0],s0.size()); // #1 (pass the array from the vector)
     poor(s1,10); // #2
     poor(s2,20); // #3
     poor(p1,1); // #4
     delete p1;
     p1 = 0;
     poor(p1,1); // #5
     poor(q,max); // #6
}
*/

int main()
try{
    cout << "Mozliwe problemy:" << endl;
    cout << "1. moze wystawic przekazanie niewlasciwego typu w #1" << endl;
    cout << "2. uzywanie stalych wartosci jak w przypadku #3" << endl;
    cout << "3. po wykonaniu delete p1; w #5 nastapi przekazanie zerowego wskaznika" << endl;
    cout << "4. z #6 gdzie uzywamy max bez jego wczesniejszego okreslenia" << endl;

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
