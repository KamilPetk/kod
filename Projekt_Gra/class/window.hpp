#include <allegro5/allegro.h>


ALLEGRO_DISPLAY *display;
class Window{ //KLASA TWORZACA NOWE OKNO
public:
    Window(){}

void newWindow(int ScreenWidth, int ScreenHeight, int x, int y);

private:

};

void Window::newWindow(int ScreenWidth, int ScreenHeight, int x, int y)
{
    if(!al_init())
    al_show_native_message_box(NULL, "Error", NULL, "Could not initialize Allegro", NULL, NULL);

    display = al_create_display(ScreenWidth, ScreenHeight);

    if(!display)
        al_show_native_message_box(display, "Error" , NULL, "Could not create Allegro Display" ,NULL, NULL);

    al_set_window_position(display, x, y); //ustawienie miejsca gdzie ma sie wysiwetlic okienko
}
