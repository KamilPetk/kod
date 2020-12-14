#include "zad05_Box.hpp"

void Box::draw_lines() const
{
    if (color().visibility())
    {
            fl_line(x1.x, x1.y, y1.x, y1.y);
            fl_arc(arc1.x, arc1.y, r+r, r+r, 0, 90); //book page 471
            
            fl_line(x2.x, x2.y, y2.x, y2.y);
            fl_arc(arc2.x, arc2.y, r+r, r+r, 270, 360);
            
            fl_line(x3.x, x3.y, y3.x, y3.y);
            fl_arc(arc3.x, arc3.y, r+r, r+r, 180, 270);
            
            fl_line(x4.x, x4.y, y4.x, y4.y);
            fl_arc(arc4.x, arc4.y, r+r, r+r, 90, 180);
    }
}

//Kamil Petk
//31.03.2020