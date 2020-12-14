#include "my.h"
#include <iostream>

int foo;

namespace X
{
    int var = 7;

    void print()
    {
        std::cout << var << std::endl;
    }

}

namespace Y
{
    int var = 7;

    void print()
    {
        std::cout << var << std::endl;
    }

}

namespace Z
{
    int var = 7;

    void print()
    {
        std::cout << var << std::endl;
    }

}


int main()
{
    foo = 7;

    print_foo();

    print(99);



    //int x = 7;
    //int y = 9;

    /*
    swap_v(x,y); //compiled and no swapped
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    swap_v(7,9);//compiled and no swapped
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    */

    /*
    swap_r(x,y); //compiled and swapped
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    swap_r(7,9);//no compiled, error: invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    */

    /*
    swap_cr(x,y); //no compiled
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    swap_cr(7,9);//no compiled
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    */


    //const int cx = 7;
    //const int cy = 9;
    /*
    swap_v(cx,cy); //compiled and no swapped
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    swap_v(7.7,9.9);//compiled and no swapped
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    */

    /*
    swap_r(cx,cy); //no compiled, error: binding 'const int' to reference of type 'int&' discards qualifiers
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    swap_r(7.7,9.9);//no compiled, error: invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    */

    /*
    swap_cr(cx,cy); //no compiled
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    swap_cr(7.7,9.9);//no compiled
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    */


    //double dx = 7.7;
    //double dy = 9.9;

    /*
    swap_v(dx,dy); //compiled and no swapped
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    swap_v(7.7,9.9);//compiled and no swapped
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    */

    /*
    swap_r(dx,dy); //no compiled, error: invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    swap_r(7.7,9.9);//no compiled, error: invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    */

    /*
    swap_cr(x,y); //no compiled
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    swap_cr(7.7,9.9);//no compiled
    std::cout << std::endl << "x: " << x << " y: " << y << std::endl;
    */

    std::cout << std::endl;

    X::var = 7;
    X::print(); // print X’s var
    using namespace Y;
    var = 9;
    print(); // print Y’s var
    {
        using Z::var;
        using Z::print;
        var = 11;
        print(); // print Z’s var
    }

    print(); // print Y’s var
    X::print(); // print X’s var


    char cc;
    std::cin >> cc;

    return 0;
}
//Kamil Petk
//17.03.2020
