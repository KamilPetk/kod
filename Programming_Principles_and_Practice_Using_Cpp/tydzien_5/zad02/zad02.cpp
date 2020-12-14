
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.hpp"    // get access to our window library
#include "Graph.hpp"            // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,800,600,"Zad. 1");    // make a simple window
    
    Rectangle rectangle  {Point{10,10},200,100};
    rectangle.set_color(Color::blue);
    win.attach(rectangle);
    
    Polygon rectangle2;
    rectangle2.add(Point{420,10});
    rectangle2.add(Point{220,10});
    rectangle2.add(Point{220,110});
    rectangle2.add(Point{420,110});
    rectangle2.set_color(Color::red);
    win.attach(rectangle2);
    win.wait_for_button();
    /////////////////////////////////////////////////////
    Rectangle rectangle3 {Point{10,120},100,30};
    win.attach(rectangle3);
    
    Text t {Point{33,140}, "Howdy!"};
    win.attach(t);
    win.set_label("Zad. 1,2");
    win.wait_for_button();
    /////////////////////////////////////////////////////
    Text k(Point(175,300), "K");
    k.set_color(Color::green);
    k.set_font(FL_HELVETICA_BOLD);
    k.set_font_size(150);
    win.attach(k);
    
    Text p(Point(260,300), "P");
    p.set_color(Color::dark_yellow);
    p.set_font(FL_HELVETICA_BOLD);
    p.set_font_size(150);
    win.attach(p);
    win.set_label("Zad. 1,2,3");
    win.wait_for_button();
    /////////////////////////////////////////////////////
    Rectangle white11{Point{10,320},50,50};
    white11.set_fill_color(Color::white);
    win.attach(white11);
    
    Rectangle red12{Point{60,320},50,50};
    red12.set_fill_color(Color::red);
    win.attach(red12);
    
    Rectangle white13{Point{110,320},50,50};
    white13.set_fill_color(Color::white);
    win.attach(white13);

    Rectangle red21{Point{10,370},50,50};
    red21.set_fill_color(Color::red);
    win.attach(red21);
    
    Rectangle white22{Point{60,370},50,50};
    white22.set_fill_color(Color::white);
    win.attach(white22);
    
    Rectangle red23{Point{110,370},50,50};
    red23.set_fill_color(Color::red);
    win.attach(red23);
    
    Rectangle white31{Point{10,420},50,50};
    white31.set_fill_color(Color::white);
    win.attach(white31);
    
    Rectangle red32{Point{60,420},50,50};
    red32.set_fill_color(Color::red);
    win.attach(red32);
    
    Rectangle white33{Point{110,420},50,50};
    white33.set_fill_color(Color::white);
    win.attach(white33);
    
    win.set_label("Zad. 1,2,3,4");
    win.wait_for_button();
    /////////////////////////////////////////////////////
    Circle c0 {Point{215,440},5};
    Circle c1 {Point{230,440},10};
    Circle c2 {Point{290,440},50};
    
    Circle c3 {Point{290,385},5};
    Circle c4 {Point{290,495},5};
    
    Circle c5 {Point{250,400},8};
    Circle c6 {Point{250,480},8};
    
    Circle c7 {Point{405,390},75};
    Circle c8 {Point{405,490},75};
    Circle c9 {Point{405,300},15};
    Circle c10 {Point{405,580},15};
    Circle c11 {Point{358,320},10};
    Circle c12 {Point{358,560},10};
    Circle c13 {Point{450,560},10};
    Circle c14 {Point{450,320},10};

    win.attach(c0);
    win.attach(c1);
    win.attach(c2);
    win.attach(c3);
    win.attach(c4);
    win.attach(c5);
    win.attach(c6);
    win.attach(c7);
    win.attach(c8);
    win.attach(c9);
    win.attach(c10);
    win.attach(c11);
    win.attach(c12);
    win.attach(c13);
    win.attach(c14);
    
    win.set_label("My window");
    win.wait_for_button();
}

//------------------------------------------------------------------------------
//Kamil Petk
//29.03.2020
