#include "Graph.hpp" 

using namespace Graph_lib; 

class Arrow : public Shape
{
public:
    Arrow(Point p, int w)
        : p(p), w(w)
        {
            x1 = Point(p.x, p.y);
            y1 = Point(p.x + w, p.y); 
            z1 = Point(p.x + 25, p.y - (w/10)); 
            z2 = Point(p.x + 25, p.y + (w/10)); 
        }
        
    void draw_lines() const;
    
private:
    Point p;
    int w;
    Point x1;
    Point y1;
    
    Point z1;
    Point z2;
    
};

//Kamil Petk
//31.03.2020