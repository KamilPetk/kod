
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.hpp"    // get access to our window library
#include "Graph.hpp"            // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,800,1000,"Canvas");    // make a simple window

    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;
    
    Lines grid;
    for (int x = x_grid; x < x_size; x+=x_grid)
        grid.add(Point{x,0},Point{x,y_size});
    for (int y = y_grid; y < y_size; y+=y_grid)
        grid.add(Point{0,y},Point{x_size,y});
   win.attach(grid);
   
   Vector_ref<Rectangle> red;
   int x_start = 0;
   int y_start = 0;

   for(int i = 0; i < 8; i++)
   {
        red.push_back(new Rectangle(Point(x_start, y_start), x_grid, y_grid));
        x_start += 100;
        y_start += 100;
        red[i].set_fill_color(Color::red);
        win.attach(red[i]);
   }  
    
    Image myImage {Point{0,200}, "cplusplus.jpeg"};
    win.attach(myImage);
    
    Image myImage2 {Point{0,400}, "cplusplus.jpeg"};
    win.attach(myImage2);
    
    Image myImage3 {Point{0,600}, "cplusplus.jpeg"};
    win.attach(myImage3);
    
    
    Vector_ref<Point> imagePoints; 
    
    int first_x = 0;
    int first_y = 0;
    for(int i = 0; i <64; i++)
    {
        imagePoints.push_back(new Point{first_x, first_y});
        first_x += 100;
        
        if(first_x == 800)
        {
            first_y += 100;
            first_x = 0;
        }
        Image ii {imagePoints[i], "cplusplus.jpeg"};
        ii.set_mask(Point{0,0}, 100, 100);
        win.attach(ii);
        win.wait_for_button();
    }    
    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
//Kamil Petk
//30.03.2020
