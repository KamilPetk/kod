#include "zad05_Arrow.hpp"

void Arrow::draw_lines() const
{
    if(color().visibility())
    {
        fl_line(x1.x, x1.y, y1.x, y1.y);
        fl_line(x1.x, x1.y, z1.x, z1.y);
        fl_line(x1.x, x1.y, z2.x, z2.y);
    }
}

//Kamil Petk
//31.03.2020