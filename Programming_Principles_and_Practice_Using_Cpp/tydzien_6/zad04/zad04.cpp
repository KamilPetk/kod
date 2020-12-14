
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.hpp"    // get access to our window library
#include "Graph.hpp"            // get access to our graphics library facilities
#include <cmath>
//------------------------------------------------------------------------------
double one(double) { return 1; }
double slope(double x) { return x/2; } 
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x)+slope(x/2); }

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,600,600,"Function graphs");    // make a simple window
    win.wait_for_button();  
    constexpr int xmax = 600; // window size
    constexpr int ymax = 600;
    constexpr int x_orig = xmax/2; // position of (0,0) is center of window
    constexpr int y_orig = ymax/2;
    Point orig {x_orig,y_orig};
    
    constexpr int x_scale = 20; // scaling factors
    constexpr int y_scale = 20;
    
    constexpr int xlength = 400; // make the axis a bit smaller than the window
    constexpr int ylength = 400;
    
    Axis x {Axis::x,Point{100,y_orig},
        xlength, xlength/x_scale, "1 == 20"};
    x.set_color(Color::red);
    Axis y {Axis::y,Point{x_orig, ylength+100},
        ylength, ylength/y_scale, "1 == 20"};
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);
    //////////////////////////////////////
    constexpr int r_min = -10; // range [–10:11)
    constexpr int r_max = 11;
    constexpr int n_points = 400; // number of points used in range
    
    Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
    win.attach(s);
    
    Function s2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
    win.attach(s2);
    Text ts2 {Point{100,y_orig+y_orig/2-70},"x/2"};
    win.attach(ts2);
    
    Function s3 {square,r_min,r_max,orig,n_points,x_scale,y_scale};
    win.attach(s3);
    
    //Function cosine {cos,r_min,r_max,orig,n_points,x_scale,y_scale};
    Function cosine {sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale};
    win.attach(cosine);
    cosine.set_color(Color::blue);
    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
//Kamil Petk
//07.04.2020
