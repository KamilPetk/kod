
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.hpp"    // get access to our window library
#include "Graph.hpp"            // get access to our graphics library facilities
using namespace Graph_lib;   // our graphics facilities are in Graph_lib
//------------------------------------------------------------------------------
double one(double) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sumSinCos(double x) { return sin(x) + cos(x); }
double squareSinAndCos(double x) { return sin(x)*sin(x)+cos(x)*cos(x); }

struct Fctt : Shape //book page 524...
{
    Fctt(Fct* fct, double r1, double r2, Point orig,
            int count = 100, double xscale = 25, double yscale = 25);

    void fct_fct(Fct* f_c_t) { fct = f_c_t;} 
    void fct_r1(double r) { r1 = r;}
    void fct_r2(double r) { r2 = r;}
    void fct_point(Point p) { orig = p;}
    void fct_count(int c) { count = c;}
    void fct_xscale(double xs) { xscale = xs;}
    void fct_yscale(double ys) { yscale = ys;} 
    
    double fct_r1_get() { 
        cout << r1 << endl;
        return r1;}
    double fct_r2_get() { return r2;}
    Point fct_point_get() { return orig;}
    int fct_c_get() { return count;}
    double fct_xs_get() { return xscale;}
    double fct_ys_get() { return yscale;} 
    
    void reset(Fct* fct, double r1, double r2, Point orig,
            int count = 100, double xscale = 25, double yscale = 25);
  
    int operator()(double r, double scale)
    {
        return int(r*scale);
    }
private:
    Fct* fct;
    double r1;  
    double r2;
    Point orig;
    int count;
    double xscale;
    double yscale;
    
};

//book page 525
Fctt::Fctt(Fct* fct, double r1, double r2, Point xy, int count, double xscale, double yscale)
    :fct(fct), r1(r1), r2(r2), orig(xy), count(count), xscale(xscale), yscale(yscale)
    {
        if (r2-r1<=0) error("bad graphing range");
        if (count <= 0) error("non-positive graphing count");
        double dist = (r2-r1)/count;
        double r = r1;
        for (int i = 0; i<count; ++i) {
            add(Point{xy.x+operator()(r, xscale),xy.y-int(fct(r)*yscale)});
            r += dist;
    }
    }


//OPERACJA RESET
void Fctt::reset(Fct* fct, double r1, double r2, Point orig,
            int count, double xscale, double yscale)
{
    //USTAWIENIE INNYCH WARTOSCI
    fct_fct(fct);
    fct_r1(r1);
    fct_r2(r2);
    fct_point(orig);
    fct_count(count);
    fct_xscale(xscale);
    fct_yscale(yscale);
    
}
    

int main()
{

    constexpr int xmax = 600; // window size
    constexpr int ymax = 600;
    constexpr int x_orig = xmax/2; // position of (0,0) is center of window
    constexpr int y_orig = ymax/2;
    const Point orig{x_orig,y_orig};
    constexpr int r_min = -10; // range [–10:11)
    constexpr int r_max = 11;
    
    Simple_window win {Point{100,100},xmax,ymax,"Fct"};
    
   // TESTOWANIE ZAD 2 SPRAWDZAJAC r_min
   // Fctt s4{cos,r_min,r_max,orig,100,30,40};
   // s4.fct_r1_get(); //zwraca r_min = 10
   // s4.reset(cos,15,r_max,orig,100,30,40);// zmienia wartosc r_min;
   // s4.fct_r1_get(); //zwraca r_min = 15
   //win.attach(s4);
    
    win.wait_for_button();       // give control to the display engine
    
    //ZAD 4
    constexpr int xlength = 400; // make the axis a bit smaller than the window
    constexpr int ylength = 400;
    constexpr int x_scale = 20; // scaling factors
    constexpr int y_scale = 20;
    

    Axis x {Axis::x,Point{100,y_orig},
        xlength, xlength/x_scale, "x"};
    x.set_color(Color::red);
    win.attach(x);
    
    Axis y {Axis::y,Point{x_orig, ylength+100},
        ylength, ylength/y_scale, "y"};
    y.set_color(Color::red);
    win.attach(y);
    
    Fctt f1{sin, r_min, r_max, orig, 100, x_scale, y_scale};
    f1.set_color(Color::blue);
    Text f1t {Point{xmax-105,ymax/2}, "sin"};
    f1t.set_color(Color::blue);
    win.attach(f1);
    win.attach(f1t);
    
    Fctt f2{cos, r_min, r_max, orig, 100, x_scale, y_scale};
    f2.set_color(Color::dark_yellow);
    Text f2t {Point{xmax-105,ymax/2+15}, "cos"};
    f1t.set_color(Color::dark_yellow);
    win.attach(f2);
    win.attach(f2t);
    
    Fctt f3{sumSinCos, r_min, r_max, orig, 100, x_scale, y_scale};
    f3.set_color(Color::dark_green);
    Text f3t {Point{xmax-105,ymax/2+35}, "sin+cos"};
    f3t.set_color(Color::dark_green);
    win.attach(f3);
    win.attach(f3t);
    
    Fctt f4{squareSinAndCos, r_min, r_max, orig, 100, x_scale, y_scale};
    f4.set_color(Color::dark_cyan);
    Text f4t {Point{xmax-95,ymax/2-15}, "sin*sin+cos*cos"};
    f4t.set_color(Color::dark_cyan);
    win.attach(f4);
    win.attach(f4t);

    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
//Kamil Petk
//08.04.2020
