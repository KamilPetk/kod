
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.hpp"    // get access to our window library
#include "Graph.hpp"            // get access to our graphics library facilities
using namespace Graph_lib;   // our graphics facilities are in Graph_lib
//------------------------------------------------------------------------------

class Pseudo_window : public Shape
{
public:
    Pseudo_window(Point xy, int w, int h, string title)
            :xy(xy), w(w), h(h), title(title)
            {
                arc1 = Point(xy.x + w - r, xy.y);
                arc2 = Point(xy.x + w - r, xy.y + h - r);
                arc3 = Point(xy.x - r, xy.y + h - r);
                arc4 = Point(xy.x - r, xy.y + r);
                
                icon1 = Point(xy.x + w - 55, xy.y+10);
                icon2 = Point(xy.x + w - 40, xy.y+10);
                icon3 = Point(xy.x + w - 25, xy.y+10);
            }
    void draw_lines() const;        
    
private:
    Point xy;
    int w;
    int h;
    string title;
    
    int r = 10;
    Point arc1;
    Point arc2;
    Point arc3;
    Point arc4;
    
    Point icon1;
    Point icon2;
    Point icon3;
    
};

void Pseudo_window::draw_lines() const
{

    if(color().visibility())
    {
        fl_draw(title.c_str(), xy.x + 10, xy.y + 25);
        
        fl_line(xy.x,xy.y,xy.x+w,xy.y);
        fl_arc(arc1.x, arc1.y, r+r, r+r, 0, 90);
        fl_line(xy.x - r,xy.y+35,xy.x+w + r,xy.y+35);
        
        fl_line(xy.x + w + r, xy.y + r, xy.x + w + r, xy.y + h);
        fl_arc(arc2.x, arc2.y, r+r, r+r, 270, 360);
        fl_line(xy.x + w + r - 10, xy.y + 35, xy.x + w + r - 10, xy.y + h - 10);
        fl_arc(arc2.x - 10, arc2.y - 10, r+r, r+r, 270, 360);
        
        fl_line(xy.x + w, xy.y + r + h, xy.x, xy.y + r + h);
        fl_arc(arc3.x, arc2.y, r+r, r+r, 180, 270);
        fl_line(xy.x + w - 10, xy.y + r + h - 10, xy.x + 10, xy.y + r + h - 10);
        fl_arc(arc3.x + 10, arc2.y - 10, r+r, r+r, 180, 270);
        
        fl_line(xy.x - r, xy.y + h, xy.x - r, xy.y + r);
        fl_arc(arc4.x, arc4.y - r, r+r, r+r, 90, 180);
        fl_line(xy.x - r + 10, xy.y + h - 10, xy.x - r + 10, xy.y + 35);
        
        //CONTROL ICONS:
        Rectangle iC1(icon1, 15, 15);
        iC1.draw();
            fl_line(icon1.x + 2, icon1.y + 9, icon1.x + 11, icon1.y + 9);
        Rectangle iC2(icon2, 15, 15);
        iC2.draw();
            Point icon21 = Point(icon2.x+2, icon2.y+3);
            Rectangle iC21(icon21, 11, 9);
            iC21.draw();
        Rectangle iC3(icon3, 15, 15);
        iC3.draw();
            string iC31 = "X";
            fl_draw(iC31.c_str(), icon3.x + 3, icon3.y + 13);
         
        //IMAGE:
        Point img = Point(xy.x + 15, xy.y + 50);
        Image ii (img, "image.jpg");
        Point imgMask = Point(xy.x + 850, xy.y + 400);
        ii.set_mask(imgMask, 675, 445);
        ii.draw();
    }    
}


int main()
{
    
    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,800,600,"Canvas");    // make a simple window

    Pseudo_window pw(Point(50,50), 700, 500, "PseudoWin");
    win.attach(pw);
    
        
    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
//Kamil Petk
//08.04.2020
