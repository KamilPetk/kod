#include "Graph.hpp" 

using namespace Graph_lib; 

class Star : public Closed_polyline
{
public:
    Star(Point p, double a, double h, int arms, Fl_Color color)
            : p(p), a(a), h(h), arms(arms), color(color)
            {
                a1 = Point(p.x, p.y);
                a2 = Point(p.x, p.y);
                
                b1 = Point(p.x, p.y);
                b2 = Point(p.x , p.y);
                
                ///////////////
               
                c1 = Point(p.x, p.y);
                c2 = Point(p.x, p.y);
                
                d1 = Point(p.x, p.y);
                d2 = Point(p.x ,p.y);
                
                star_points();
            }
    void star_points(); //dodanie kolejnych pkt. gwiazdy
    void draw_lines() const;
    
private:
    Point p;
    double a;
    double h;
    int arms;
    
    Point a1;
    Point a2;
    Point b1;
    Point b2;
    Point c1;
    Point c2;
    Point d1;
    Point d2;
    Fl_Color color;
};

//Kamil Petk
//01.04.2020
