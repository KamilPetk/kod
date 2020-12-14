#include "Graph.hpp" 

using namespace Graph_lib; 

class Arc : public Shape
{
public:
    Arc(Point p, int w, int h, int f, int l)
        : p(p), w(w), h(h), first(f), last(l)
        {
            add(p); //add point
        };
     
    void draw_lines() const;
    
private:
    Point p;
    int w;
    int h;
    int first;
    int last;
};


//Kamil Petk
//31.03.2020