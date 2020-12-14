
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.hpp"    // get access to our window library
#include "Graph.hpp"            // get access to our graphics library facilities

#include "zad05_Arc.hpp"
#include "zad05_Box.hpp"
#include "zad05_Arrow.hpp"
#include "zad05_RightTriangle.hpp"

#include <cmath>
using namespace Graph_lib;   // our graphics facilities are in Graph_lib
//------------------------------------------------------------------------------




int main()
{
    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,800,600,"Canvas");    // make a simple window

    Arc arc1(Point(50, 50), 45, 75, 15, 175);
    win.attach(arc1);
    
    Box box1(Point(250,50), 100, 95, 15);
    win.attach(box1);
    
    Arrow  arr1(Point(50,300), 100);
    win.attach(arr1);
    
    RightTriangle rTriangle(Point(250, 300), 100.0, 100.0, 0.0, Fl_Color(1));
    rTriangle.set_fill_color(Color::red);
    win.attach(rTriangle);
    
    RightTriangle rTriangle2(Point(320, 230), 100.0, 100.0, -45.0, Fl_Color(2));
    win.attach(rTriangle2);
    
    RightTriangle rTriangle3(Point(420, 230), 100.0, 100.0, -90.0, Fl_Color(3));
    win.attach(rTriangle3);
    
    RightTriangle rTriangle4(Point(491, 300), 100.0, 100.0, -135.0, Fl_Color(4));
    win.attach(rTriangle4);
    
    RightTriangle rTriangle5(Point(491, 400), 100.0, 100.0, -180.0, Fl_Color(5));
    win.attach(rTriangle5);
    
    RightTriangle rTriangle6(Point(422, 471), 100.0, 100.0, -225.0, Fl_Color(6));
    win.attach(rTriangle6);
    
    RightTriangle rTriangle7(Point(322, 473), 100.0, 100.0, -270.0, Fl_Color(7));
    win.attach(rTriangle7);
    
    RightTriangle rTriangle8(Point(250, 401), 100.0, 100.0, -315.0, Fl_Color(8));
    win.attach(rTriangle8);

    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
//Kamil Petk
//31.03.2020
