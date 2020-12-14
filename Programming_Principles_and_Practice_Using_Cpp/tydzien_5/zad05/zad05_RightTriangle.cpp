#include "zad05_RightTriangle.hpp"

void RightTriangle::draw_lines() const
{
        if(color().visibility())
        {
            fl_color(colorTriangle);
            fl_line(a1.x, a1.y, a2.x, a2.y);
            fl_line(h1.x, h1.y, h2.x, h2.y);
            fl_line(c1.x, c1.y, c2.x, c2.y);
        }
}

//Kamil Petk
//31.03.2020