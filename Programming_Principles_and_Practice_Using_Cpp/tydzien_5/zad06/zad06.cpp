
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.hpp"    // get access to our window library
#include "Graph.hpp"            // get access to our graphics library facilities
#include "zad06_Star.hpp"
 using namespace Graph_lib;   // our graphics facilities are in Graph_lib
//------------------------------------------------------------------------------

int main()
{
    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,800,600,"Star");    // make a simple window

    Star star1(Point(175, 175), 155.0, 55.0, 15, FL_RED);
    star1.set_fill_color(Color::red);
    win.attach(star1);
    
    Star star2(Point(475, 175), 50.0, 15.0, 8, FL_BLUE);
    star2.set_fill_color(Color::blue);
    win.attach(star2);
    
    Star star3(Point(405, 375), 120.0, 25.0, 21, FL_YELLOW);
    star3.set_fill_color(Color::dark_yellow);
    win.attach(star3);
  
    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
//Kamil Petk
//01.04.2020
