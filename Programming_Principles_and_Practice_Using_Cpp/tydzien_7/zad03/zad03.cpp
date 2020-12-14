//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.hpp"    // get access to our window library
#include "Graph.hpp"            // get access to our graphics library facilities
#include <cmath>
using namespace Graph_lib;   // our graphics facilities are in Graph_lib
//------------------------------------------------------------------------------
constexpr int xmax = 600; // window size
constexpr int ymax = 600;
constexpr int x_orig = xmax/2; // position of (0,0) is center of window
constexpr int y_orig = ymax/2;
const Point orig{x_orig,y_orig};
constexpr int r_min = -10; // range [–10:11)
constexpr int r_max = 11;

constexpr int xlength = 400; // make the axis a bit smaller than the window
constexpr int ylength = 400;
constexpr int x_scale = 20; // scaling factors
constexpr int y_scale = 20;

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

    void draw();
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
        draw();
    }
    
void Fctt::draw()    
{
if (r2-r1<=0) error("bad graphing range");
        if (count <= 0) error("non-positive graphing count");
        double dist = (r2-r1)/count;
        double r = r1;
        clear_points(); //USUWA POPRZEDNI WYKRES! <-dodane do class Shape
        for (int i = 0; i < count; ++i) {
        add(Point{orig.x+operator()(r, xscale),orig.y-int(fct(r)*yscale)});
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
 
    draw();
}

////////////////////////////////////////////////////////////////////
struct My_window : Graph_lib::Window {
    My_window(Point xy, int w, int h, const string& title);
        
    void drawOne();
    void drawSlope();
    void drawSquare();
    void drawSumSinCos();
    void drawSquareSinAndCos();
private:
    Button selectOne; 
    Button selectSlope; 
    Button selectSquare; 
    Button selectSumSinCos; 
    Button selectSquareSinAndCos; 
     
    Button quit_button; // end program
    
    In_box next_r1;
    In_box next_r2;
    In_box next_count;    
    In_box next_xscale;
    In_box next_yscale;
    
    static void cb_one(Address, Address);
    static void cb_slope(Address, Address);
    static void cb_square(Address, Address);
    static void cb_sumSinCos(Address, Address);
    static void cb_squareSinAndCos(Address, Address);
    
    static void cb_quit(Address, Address);
    
    void fone();
    void fslope(); 
    void fsquare();     
    void fsumSinCos(); 
    void fsquareSinAndCos();
    
    void quit(); 
    
    Axis x;
    Axis y;
    Fctt fun;
}; 

My_window::My_window(Point xy, int w, int h, const string& title)
        :Window{xy,w,h,title}, 
        x{Axis::x,Point{100,y_orig}, xlength, 1, "x"},
        y{Axis::y,Point{x_orig, ylength+100},
        ylength, 1, "y"},
        selectOne{Point{x_max()-140,20}, 100, 20, "One", cb_one},
        selectSlope{Point{x_max()-140,40}, 100, 20, "Slope", cb_slope},
        selectSquare{Point{x_max()-140,60}, 100, 20, "Square", cb_square},
        selectSumSinCos{Point{x_max()-140,80}, 100, 20, "SumSinCos", cb_sumSinCos},
        selectSquareSinAndCos{Point{x_max()-140,100}, 100, 20, "SqiareSinCos", cb_squareSinAndCos},
        next_r1{Point{x_max()-550,0}, 50, 20, "r1:"},
        next_r2{Point{x_max()-450,0}, 50, 20, "r2:"},
        next_count{Point{x_max()-350,0}, 50, 20, "count:"},
        next_xscale{Point{x_max()-250,0}, 50, 20, "xscale:"},
        next_yscale{Point{x_max()-150,0}, 50, 20, "yscale:"},
        quit_button{Point{x_max()-70,0}, 70, 20, "Quit", cb_quit},
        fun(one, r_min, r_max, orig, 100, x_scale, y_scale)
{
    attach(x);
    attach(y);
    attach(selectOne);
    attach(selectSlope);
    attach(selectSquare);
    attach(selectSumSinCos);
    attach(selectSquareSinAndCos);
    attach(quit_button);
    
    attach(next_r1);
    attach(next_r2);
    attach(next_count);
    attach(next_xscale);
    attach(next_yscale);
    fun.set_color(Color::invisible);
    attach(fun);
  
}

void My_window::drawOne()
{
    int newr1 = next_r1.get_int(); //zmienilem get_int() w GUI.cpp
    //poniewaz dla liczb ujemnych zwracalo -99999
    //cout << newr1;
    int newr2 = next_r2.get_int();
    int newcount = next_count.get_int();
    int newxscale = next_xscale.get_int();
    int newyscale = next_yscale.get_int();
    
        fun.reset([](double x) { return one(x)*10; }, newr1, newr2, orig, newcount, newxscale, newyscale); //lambda, page 533
        fun.set_color(Color::visible);
    redraw();
}

void My_window::drawSlope()
{
    int newr1 = next_r1.get_int(); //zmienilem get_int() w GUI.cpp
    //poniewaz dla liczb ujemnych zwracalo -99999
    //cout << newr1;
    int newr2 = next_r2.get_int();
    int newcount = next_count.get_int();
    int newxscale = next_xscale.get_int();
    int newyscale = next_yscale.get_int();
    
        fun.reset([](double x) { return slope(x)*10; }, newr1, newr2, orig, newcount, newxscale, newyscale); //lambda, page 533
        fun.set_color(Color::visible);
    redraw();
}

void My_window::drawSquare()
{
    int newr1 = next_r1.get_int(); //zmienilem get_int() w GUI.cpp
    //poniewaz dla liczb ujemnych zwracalo -99999
    //cout << newr1;
    int newr2 = next_r2.get_int();
    int newcount = next_count.get_int();
    int newxscale = next_xscale.get_int();
    int newyscale = next_yscale.get_int();
    
        fun.reset([](double x) { return sin(x)*10; }, newr1, newr2, orig, newcount, newxscale, newyscale); //lambda, page 533
        fun.set_color(Color::visible);
    redraw();
}

void My_window::drawSumSinCos()
{
    int newr1 = next_r1.get_int(); //zmienilem get_int() w GUI.cpp
    //poniewaz dla liczb ujemnych zwracalo -99999
    //cout << newr1;
    int newr2 = next_r2.get_int();
    int newcount = next_count.get_int();
    int newxscale = next_xscale.get_int();
    int newyscale = next_yscale.get_int();
    
        fun.reset([](double x) { return sumSinCos(x)*10; }, newr1, newr2, orig, newcount, newxscale, newyscale); //lambda, page 533
        fun.set_color(Color::visible);
    redraw();
}

void My_window::drawSquareSinAndCos()
{
    int newr1 = next_r1.get_int(); //zmienilem get_int() w GUI.cpp
    //poniewaz dla liczb ujemnych zwracalo -99999
    //cout << newr1;
    int newr2 = next_r2.get_int();
    int newcount = next_count.get_int();
    int newxscale = next_xscale.get_int();
    int newyscale = next_yscale.get_int();
    
        fun.reset([](double x) { return squareSinAndCos(x)*10; }, newr1, newr2, orig, newcount, newxscale, newyscale); //lambda, page 533
        fun.set_color(Color::visible);
    redraw();
}

void My_window::quit()
{
    hide(); // curious FLTK idiom to delete window
}

void My_window::cb_one(Address, Address pw) //book page 557
// call Lines_window::next() for the window located at pw
{
 reference_to<My_window>(pw).drawOne();
} 

void My_window::cb_slope(Address, Address pw) //book page 557
// call Lines_window::next() for the window located at pw
{
 reference_to<My_window>(pw).drawSlope();
} 

void My_window::cb_square(Address, Address pw) //book page 557
// call Lines_window::next() for the window located at pw
{
 reference_to<My_window>(pw).drawSquare();
} 

void My_window::cb_sumSinCos(Address, Address pw) //book page 557
// call Lines_window::next() for the window located at pw
{
 reference_to<My_window>(pw).drawSumSinCos();
} 

void My_window::cb_squareSinAndCos(Address, Address pw) //book page 557
// call Lines_window::next() for the window located at pw
{
 reference_to<My_window>(pw).drawSquareSinAndCos();
} 


void My_window::cb_quit(Address, Address pw) //book page 557
{
 reference_to<My_window>(pw).quit();
} 

int main()
{
    My_window myWin(Point(100,100), xmax, ymax, "My_window");
    return gui_main(); //page 568
}

//------------------------------------------------------------------------------
//Kamil Petk
//13.04.2020
//Do wykonania tego zadania skorzystaelem z wykonanego wczesniej
//zad06 z poprzedniego tygodnia
