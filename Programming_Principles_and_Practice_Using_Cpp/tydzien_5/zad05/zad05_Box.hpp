#include "Graph.hpp" 

using namespace Graph_lib; 

class Box : public Shape
{
public:
    Box(Point p, int h, int w, int r)
        : p(p), h(h), w(w), r(r)
        { 
            //1 LINE
            x1 = Point(p.x, p.y);
            y1 = Point(p.x + w, p.y);  
            
            //1 ARC
            arc1 = Point(p.x + w - r, p.y);
            
            //2 LINE
            x2 = Point(p.x + w + r, p.y + r);
            y2 = Point(p.x + w + r, p.y + r + h);
            
            //2 ARC
            arc2 = Point(p.x + w - r, p.y + h);
            
            //3 LINE
            x3 = Point(p.x + w, p.y + r + h + r);
            y3 = Point(p.x , p.y + r + h + r);
            
            //3 ARC
            arc3 = Point(p.x - r, p.y + h);
            
            //4 LINE
            x4 = Point(p.x - r, p.y + r + h);
            y4 = Point(p.x - r , p.y + r);
            
            //4 ARC
            arc4 = Point(p.x - r, p.y);
            
        }
    
    void draw_lines() const;
    
    
private:
   Point p;
   Point x1;
   Point y1;
   Point arc1;
   
   Point x2;
   Point y2;
   Point arc2;
   
   Point x3;
   Point y3;
   Point arc3;
   
   Point x4;
   Point y4;
   Point arc4;
   
   int w;
   int h;
   int r;

};

//Kamil Petk
//31.03.2020