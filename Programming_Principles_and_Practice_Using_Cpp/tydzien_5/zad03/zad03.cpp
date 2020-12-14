
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.hpp"    // get access to our window library
#include "Graph.hpp"            // get access to our graphics library facilities

//------------------------------------------------------------------------------

// |x/a|^m + |y/b|^n = 1 
//           |y/b|^n = 1 - |x/a|^m
//             |y/b| = (1 - |x/a|^m)^(1/n)
//                 y = b * (1 - |x/a|^m)^(1/n)

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,800,600,"Canvas"); // make a simple window

    Axis ya {Axis::y, Point{300,550}, 500};
    win.attach(ya);
    
    Axis xa {Axis::x, Point{50,300}, 500};
    win.attach(xa);
    
    double y;
    double b = 200;
    double a = 200;
    double m;
    double n = 3.0/2.0;
    m = n;
        
    Closed_polyline poly_superelipse;
    
    for(int x = -200; x < 200; x++)
    {
        y = b * pow(1 - pow(abs(x/a), m), 1/n);
        poly_superelipse.add(Point{(x+300),(y+300)});
    }
        
    for(int x = 200; x > -200; x--)
    {
        y = (-1)*(b * pow(1 - pow(abs(x/a), m), 1/n));
        poly_superelipse.add(Point{(x+300),(y+300)});
    }
    
    win.attach(poly_superelipse);
    
    win.wait_for_button(); // give control to the display engine
}

//------------------------------------------------------------------------------
//Kamil Petk
//30.03.2020
