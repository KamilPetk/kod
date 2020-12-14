#include "zad06_Star.hpp"

void Star::star_points()
{
    double angleRot = 0; //zamiana na radiany
    double hh = h;
    double aa = a;
    
    
    for(int i = 0; i < arms; i++)
    {
    add(Point(c2.x + (hh*cos(angleRot)),c2.y - (hh*sin(angleRot))));
    add(Point(a2.x + (hh*cos(angleRot)), a2.y - (hh*sin(angleRot))));
    
    add(Point(b1.x + (aa*sin(angleRot)) , b1.y +(aa*cos(angleRot))));
    add(Point(b2.x + (hh*cos(angleRot)) , b2.y  - (hh*sin(angleRot))));
    
    hh = (-1)*hh; //aby uzyskac drugie ramie
    
    add(Point(d1.x +(aa*sin(angleRot)), d1.y  +(aa*cos(angleRot))));
    add(Point(d2.x  + (hh*cos(angleRot)), d2.y - (hh*sin(angleRot))));
    
    angleRot += ((-360.0/arms)*0.01745329);// o tyle obracam
    hh = (-1)*hh;
    }
}

void Star::draw_lines() const
{
    fl_color(color);
    Closed_polyline::draw_lines();
}

//Kamil Petk
//01.04.2020
