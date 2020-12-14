
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.hpp"    // get access to our window library
#include "Graph.hpp"            // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(Point{100,100},800,600,"Canvas");    // make a simple window
    win.wait_for_button();

    Axis xa {Axis::x, Point{20,300}, 280, 5, "x axis"}; 
    win.attach(xa);
    win.set_label("Canvas #2");
    win.wait_for_button();
    
    Axis ya {Axis::y, Point{20,300}, 280, 5, "y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);
    win.set_label("Canvas #3");
    win.wait_for_button();
    
    Function sine {sin, 0, 100, Point{20,250},1000,50,50};
    win.attach(sine);
    win.set_label("Canvas #4");
    win.wait_for_button();       // give control to the display engine
    
    Polygon poly;                // make a shape (a polygon)

    poly.add(Point(300,200));    // add a point
    poly.add(Point(350,100));    // add another point
    poly.add(Point(400,200));    // add a third point 

    poly.set_color(Color::dark_blue);  // adjust properties of poly
    poly.set_style(Line_style::dash);
    win.attach (poly);           // connect poly to the window
    win.set_label("Canvas #5");
    win.wait_for_button();
    
    Rectangle r {Point{200,200}, 200, 100};
    win.attach(r);
    win.set_label("Canvas #6");
    win.wait_for_button();
    
    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,125});
    poly_rect.add(Point{100,125});
    poly_rect.add(Point{50,75});
    win.attach(poly_rect);
    win.set_label("Canvas #6.1");
    win.wait_for_button();
    
    r.set_fill_color(Color::dark_yellow);
    poly.set_style(Line_style(Line_style::dash,4));
    poly_rect.set_style(Line_style(Line_style::dash,2));
    poly_rect.set_fill_color(Color::red);
    win.set_label("Canvas #7");
    win.wait_for_button();
    
    Text t {Point{150,150}, "Hello, graphical world!"};
    win.attach(t);
    win.set_label("Canvas #8");
    win.wait_for_button();
    
    t.set_font(FL_TIMES_BOLD);
    t.set_font_size(40);
    win.set_label("Canvas #9");
    win.wait_for_button();
    
    Image ii {Point{150,75}, "image.jpg"};
    win.attach(ii);
    win.set_label("Canvas #10");
    win.wait_for_button();;
    
    ii.move(150,250);
    win.set_label("Canvas #11");
    win.wait_for_button();
    
    Circle c {Point{100,200},50};
    Ellipse e {Point{100,200},75,25};
    e.set_color(Color::red);
    Mark m {Point{100,200}, 'x'};
    
    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << ";window size: " <<  win.x_max() << "*" << win.y_max();
    Text sizes {Point{200,40},oss.str()};
    
    Image cal {Point{225,225},"snow_cpp.gif"};
    cal.set_mask(Point{60,60},200,150);
    
    win.attach(c);
    win.attach(m);
    win.attach(e);
    
    win.attach(sizes);
    win.attach(cal);
    win.set_label("Canvas #12");
    win.wait_for_button();
}
catch(exception& e){
    cerr << e.what() << '\n';
    
    return 1;
}
catch(...){
    cerr << "excception!\n";
    return 2;
}
//------------------------------------------------------------------------------
//KAMIL PETK
//29.03.2020
