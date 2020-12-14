#include "Graph.hpp" 

using namespace Graph_lib; 

class RightTriangle : public Shape
{
public:
    RightTriangle(Point p, double a, double h, double angle, Fl_Color color)
            : p(p), a(a), h(h), angle(angle), colorTriangle(color)
            {
                angle = angle * 0.01745329; //zamiana na radiany

                a1 = Point(p.x , p.y);
                a2 = Point(p.x+(a*sin(angle)), p.y +(a*cos(angle)));
                
                h1 = Point(p.x, p.y);
                h2 = Point(p.x + (h*cos(angle)), p.y - (h*sin(angle)));
                
                c1 = Point(p.x+(a*sin(angle)), p.y +(a*cos(angle)));
                c2 = Point(p.x + (h*cos(angle)), p.y - (h*sin(angle)));
            }
    
    void draw_lines() const;
    
private:
    Point p;
    double a;
    double h;
    double angle;
    
    Point a1;
    Point a2;
    Point h1;
    Point h2;;
    Point c1;
    Point c2;
    Fl_Color colorTriangle;
};

//Kamil Petk
//31.03.2020