
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.hpp"    // get access to our window library
#include "Graph.hpp"            // get access to our graphics library facilities
using namespace Graph_lib;   // our graphics facilities are in Graph_lib
//------------------------------------------------------------------------------

class Immobile_Circle : public Circle
{
public: 
    Immobile_Circle(Point p, int rr)
        :Circle(p, rr){}
    void move() { cout << "nie mozna przeniesc" << endl; } //teraz nie mozna przenosic
};

class Striped_rectangle : public Rectangle 
{
public:
    Striped_rectangle(Point xy, int ww, int hh)
        :Rectangle(xy, ww, hh)
        {
            a = Point(xy.x, xy.y);
            b = Point(xy.x+ww-2, xy.y);
            h = hh;
            set_fill_color();
        }
        
    void set_fill_color();
    void draw_lines() const;
    
private:
    Point a;
    Point b;
    int h;
    Lines lines;
};

void Striped_rectangle::set_fill_color()
{
    while(h!=2)
    {
        a.y +=2;
        b.y +=2;
        lines.add(a,b);
    
        h -= 2;
    }
}

void Striped_rectangle::draw_lines() const
{
   lines.draw();
   Rectangle::draw_lines();
}


int main()
{
    

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,600,400,"Canvas");    // make a simple window

    Immobile_Circle test(Point(150,150), 100);
    test.move();
    win.attach(test);
    
    Striped_rectangle test2(Point(300,150), 100, 100);
    //test2.set_fill_color();
    win.attach(test2);

    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
//Kamil Petk
//05.04.2020
