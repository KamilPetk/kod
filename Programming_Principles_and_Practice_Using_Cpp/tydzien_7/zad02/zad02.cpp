//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
#include "Simple_window.hpp"    // get access to our window library
#include "Graph.hpp"            // get access to our graphics library facilities

using namespace Graph_lib;   // our graphics facilities are in Graph_lib
//------------------------------------------------------------------------------
struct My_window : Graph_lib::Window {
    My_window(Point xy, int w, int h, const string& title);

       void wait_for_button(); // simple event loop
private:
        Open_polyline lines;

        Button quit_button;
        bool button_pushed;
        bool button_quit_pushed;

        Out_box xy_out;

        Button button1;
        bool button1_pushed;
        static void cb_1(Address, Address);
        void b1();

        Button button2;
        bool button2_pushed;
        static void cb_2(Address, Address);
        void b2();

        Button button3;
        bool button3_pushed;
        static void cb_3(Address, Address);
        void b3();

        Button button4;
        bool button4_pushed;
        static void cb_4(Address, Address);
        void b4();

        Button button5;
        bool button5_pushed;
        static void cb_5(Address, Address);
        void b5();

        Button button6;
        bool button6_pushed;
        static void cb_6(Address, Address);
        void b6();

        Button button7;
        bool button7_pushed;
        static void cb_7(Address, Address);
        void b7();

        Button button8;
        bool button8_pushed;
        static void cb_8(Address, Address);
        void b8();

        Button button9;
        bool button9_pushed;
        static void cb_9(Address, Address);
        void b9();

        Button button10;
        bool button10_pushed;
        static void cb_10(Address, Address);
        void b10();

        Button button11;
        bool button11_pushed;
        static void cb_11(Address, Address);
        void b11();

        Button button12;
        bool button12_pushed;
        static void cb_12(Address, Address);
        void b12();

        Button button13;
        bool button13_pushed;
        static void cb_13(Address, Address);
        void b13();

        Button button14;
        bool button14_pushed;
        static void cb_14(Address, Address);
        void b14();

        Button button15;
        bool button15_pushed;
        static void cb_15(Address, Address);
        void b15();

        Button button16;
        bool button16_pushed;
        static void cb_16(Address, Address);
        void b16();

        static void cb_next(Address, Address);
        static void cb_quit(Address, Address);
        void next(int x, int y);
        void quit();
};

My_window::My_window(Point xy, int w, int h, const string& title)
 :Window{xy,w,h,title},
        button_quit_pushed(false),
        quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit),

        xy_out{Point{100,0}, 100, 20, "coordinates (x,y):"},

        button1_pushed(false),
        button1(Point(x_max() - 800, 20), 200, 150, "1", cb_1),

        button2_pushed(false),
        button2(Point(x_max() - 600, 20), 200, 150, "2", cb_2),

        button3_pushed(false),
        button3(Point(x_max() - 400, 20), 200, 150, "3", cb_3),

        button4_pushed(false),
        button4(Point(x_max() - 200, 20), 200, 150, "4", cb_4),

        button5_pushed(false),
        button5(Point(x_max() - 800, 170), 200, 150, "5", cb_5),

        button6_pushed(false),
        button6(Point(x_max() - 600, 170), 200, 150, "6", cb_6),

        button7_pushed(false),
        button7(Point(x_max() - 400, 170), 200, 150, "7", cb_7),

        button8_pushed(false),
        button8(Point(x_max() - 200, 170), 200, 150, "8", cb_8),

        button9_pushed(false),
        button9(Point(x_max() - 800, 320), 200, 150, "9", cb_9),

        button10_pushed(false),
        button10(Point(x_max() - 600, 320), 200, 150, "10", cb_10),

        button11_pushed(false),
        button11(Point(x_max() - 400, 320), 200, 150, "11", cb_11),

        button12_pushed(false),
        button12(Point(x_max() - 200, 320), 200, 150, "12", cb_12),

        button13_pushed(false),
        button13(Point(x_max() - 800, 470), 200, 150, "13", cb_13),

        button14_pushed(false),
        button14(Point(x_max() - 600, 470), 200, 150, "14", cb_14),

        button15_pushed(false),
        button15(Point(x_max() - 400, 470), 200, 150, "15", cb_15),

        button16_pushed(false),
        button16(Point(x_max() - 200, 470), 200, 150, "16", cb_16)
{
 attach(quit_button);

 attach(xy_out);

 attach(button1);
 attach(button2);
 attach(button3);
 attach(button4);
 attach(button5);
 attach(button6);
 attach(button7);
 attach(button8);
 attach(button9);
 attach(button10);
 attach(button11);
 attach(button12);
 attach(button13);
 attach(button14);
 attach(button15);
 attach(button16);
}

void My_window::next(int x, int y)
{
    lines.add(Point{x,y});

    // update current position readout:
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());
    redraw();
}

void My_window::cb_next(Address, Address pw)
// call  My_window::next() for the window located at pw
{
 reference_to<My_window>(pw).next(0, 20);
}

void My_window::cb_quit(Address, Address pw)
// call  My_window::next() for the window located at pw
{
 reference_to<My_window>(pw).quit();
}

void My_window::cb_1(Address, Address pw)
{
    reference_to<My_window>(pw).next(0, 20);
}

void My_window::cb_2(Address, Address pw)
{
    reference_to<My_window>(pw).next(200, 20);
}

void My_window::cb_3(Address, Address pw)
{
    reference_to<My_window>(pw).next(400, 20);
}

void My_window::cb_4(Address, Address pw)
{
    reference_to<My_window>(pw).next(600, 20);
}

void My_window::cb_5(Address, Address pw)
{
    reference_to<My_window>(pw).next(0, 170);
}

void My_window::cb_6(Address, Address pw)
{
    reference_to<My_window>(pw).next(200, 170);
}

void My_window::cb_7(Address, Address pw)
{
    reference_to<My_window>(pw).next(400, 170);
}

void My_window::cb_8(Address, Address pw)
{
    reference_to<My_window>(pw).next(600, 170);
}

void My_window::cb_9(Address, Address pw)
{
    reference_to<My_window>(pw).next(0, 320);
}

void My_window::cb_10(Address, Address pw)
{
    reference_to<My_window>(pw).next(200, 320);
}

void My_window::cb_11(Address, Address pw)
{
    reference_to<My_window>(pw).next(400, 320);
}

void My_window::cb_12(Address, Address pw)
{
    reference_to<My_window>(pw).next(600, 320);
}

void My_window::cb_13(Address, Address pw)
{
    reference_to<My_window>(pw).next(0, 470);
}

void My_window::cb_14(Address, Address pw)
{
    reference_to<My_window>(pw).next(200, 470);
}

void My_window::cb_15(Address, Address pw)
{
    reference_to<My_window>(pw).next(400, 470);
}

void My_window::cb_16(Address, Address pw)
{
    reference_to<My_window>(pw).next(600, 470);
}

void My_window::wait_for_button()
 // modified event loop:
// handle all events (as per default), quit when button_pushed becomes true
 // this allows graphics without control inversion
{
 while (!button_pushed) Fl::wait();
 button_pushed = false;
 Fl::redraw();
}

void My_window::quit()
{
 hide(); // curious FLTK idiom to delete window
}

int main()
{
   My_window my_win(Point(100,100), 800, 620, "My_window");
   return gui_main(); //page 568
}

//------------------------------------------------------------------------------
//Kamil Petk
//13.04.2020
