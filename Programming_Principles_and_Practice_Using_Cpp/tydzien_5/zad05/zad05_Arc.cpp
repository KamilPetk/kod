#include "zad05_Arc.hpp"

void Arc::draw_lines() const
{
    if (color().visibility()) {
        fl_arc(point(0).x, point(0).y, w+w, h+h, first, last);
    }
}


//Kamil Petk
//31.03.2020