#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <ctime>

#include "class/window.hpp"
#include "class/map.hpp"
#include "class/enemy.hpp"
#include "class/attack.hpp"



using namespace std;



const float FPS = 20.0;
///////////////////////////////////////
int health = 100;
int point = 0;
///////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//KLASA DO OBSLUGI OBRAZKA I MYSZY
class ImageAndKeyboard
{
public:
    ImageAndKeyboard(){}

    enum Direrection {DOWN, LEFT, RIGHT, UP, E, Q, SPACE}; //KOLEJNOSC ZGODNA Z RYSUNKIEM POSTACI

    void mouse();
    void moveImage();
    void color();

private:
ALLEGRO_BITMAP *player;
ALLEGRO_BITMAP *pickPlayer;
ALLEGRO_BITMAP *enemy;
ALLEGRO_BITMAP *background;
ALLEGRO_BITMAP *drawAxe;
ALLEGRO_BITMAP *drawTrap2Close;
ALLEGRO_BITMAP *drawTrap2Open;
ALLEGRO_BITMAP *drawFireBall;
ALLEGRO_TIMER *timer;
ALLEGRO_TIMER *timerPick;
ALLEGRO_EVENT_QUEUE *event_queue;

ALLEGRO_COLOR electricBlue; //"tworzy nowy kolor"
ALLEGRO_COLOR yellow;
ALLEGRO_COLOR playerColor;
};

void ImageAndKeyboard::mouse()
{
    al_install_keyboard();//instaluje sterownik klawiatury
    al_hide_mouse_cursor(display); //ukrywa kursor myszki
}

void ImageAndKeyboard::color()
{
    electricBlue = al_map_rgb(44, 117, 255); //"tworzy nowy kolor"
    yellow = al_map_rgb(255, 255, 0);
    playerColor = electricBlue;
}

void ImageAndKeyboard::moveImage()
{
    al_init_image_addon(); //inicjuje dodatek do obrazu
    al_install_keyboard();
    al_init_font_addon();          // inicjowanie czcionek

    ALLEGRO_FONT *font8 = al_create_builtin_font();  //  wskaznik do czcionki
    player = al_load_bitmap("player.png");
    pickPlayer = al_load_bitmap("pick.png");
    background = al_load_bitmap("background.png");
    enemy = al_load_bitmap("ghost.png");
    drawAxe = al_load_bitmap("axe.png");
    drawTrap2Close = al_load_bitmap("trap2.png");
    drawTrap2Open = al_load_bitmap("trap2open.png");
    drawFireBall = al_load_bitmap("point.png");

    ALLEGRO_KEYBOARD_STATE keyState;
    timer = al_create_timer(1.0/FPS);
    timerPick = al_create_timer(1.0/10);
    event_queue = al_create_event_queue();


    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_timer_event_source(timerPick));
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    std::vector< std::vector <int> > map;

    LoadMap("Map1.txt", map);

    al_start_timer(timer);
    al_start_timer(timerPick);

    float x_player = 0, y_player = 40;
    float moveSpeed = 10;
    bool done = false;
    bool draw = true;
    bool active = false;
    int dir = UP;
    int previousDir = UP; //w celu mozliwosci obrania kierunku lotu topora
    int dirDoor = 0;
    int sourceX = 0;
    int sourceY = 0;
    ////////////////////////////////////////////////////////////////////////


            //PIERWSZY POTWOR
            //////////////////////////////////////////////////////////////////////
            float x_enemy = 350;
            float y_enemy = 350;
            Enemies enemy1('d', x_enemy , y_enemy); //d oznacza ze potwor porusza sie w kierunku gora -> dol -> gora -> dol
            int enemyLife = 1;
            //////////////////////////////////////////////////////////////////////


            ////////////////////////////////////////////////////////////////////////
            //DRUGI POTWOR
            float x_enemy2 = 450;
            float y_enemy2 = 450;
            Enemies enemy2('d', x_enemy2, y_enemy2); //d oznacza ze potwor porusza sie w kierunku gora -> dol -> gora -> dol
            int enemyLife2 = 1;
            ////////////////////////////////////////////////////////////////////////
    //LICZNIK CZASU
    ////////////////////////////////////////////////////////////////////////////////

    //STATYSTYKI ATAKU GRACZA
    Attack attackPlayer(x_player, y_player);//atak kula
    int rotationAxe = 0; //w celu generowania animacji obrotu toporu
    //attackFireBall.moveFireBall(x, y);
    int attack = 0;
    float x_position_ball = 0;
    float y_position_ball = 0;
    int nextAttackPlayer = 0; //zmiena do odmierzenia czasu "lotu" toporu. Kiedy = 0 mozna wykonac ponowny atak
    int dirAttack = 0;
    ////////////////////////////////////////////////////////////////////////
    //KOPANIE
    int numberPickAnimation = 0;
    ////////////////////////////////////////////////////////////////////////
    int gametime = 0;

    while(!done) //done wyzej uzstawione na false, a do poki rozne od false to wykonuje
    {
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        al_get_keyboard_state(&keyState);

        //std::cout << x << ", " << y << std::endl;

        if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }
        else if(events.type == ALLEGRO_EVENT_TIMER)
        {
                active = true;
/*
                if(al_key_down(&keyState, ALLEGRO_KEY_UP))
                {
                    y_player -= moveSpeed;
                    dir = UP;
                    previousDir = UP;
                }
                else if(al_key_down(&keyState, ALLEGRO_KEY_DOWN))
                {
                    y_player += moveSpeed;
                    dir = DOWN;
                    previousDir = DOWN;
                }
*/
                if(al_key_down(&keyState, ALLEGRO_KEY_LEFT))
                {
                    x_player -= moveSpeed;
                    dir = LEFT;
                    previousDir = LEFT;
                }
                else if(al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
                {
                    x_player += moveSpeed;
                    dir = RIGHT;
                    previousDir = RIGHT;
                }
                else if(al_key_down(&keyState, ALLEGRO_KEY_E))//(al_key_down(&keyState, ALLEGRO_KEY_E) && x >= 240 && x <= 280 && y >= 320)
                {
                        dir = E;
                        //point++;
                        //map.clear();
                        //LoadMap("Map2.txt", map);
                        //dirDoor = 0;
                }
                else if(al_key_down(&keyState, ALLEGRO_KEY_Q) && nextAttackPlayer == 0 && dir != SPACE) //NIE MOZNA ATAKOWAC KIEDY WYKONUJE KOPANIE
                {
                    attack = 1;
                    x_position_ball = x_player;
                    y_position_ball = y_player;
                    dirAttack = previousDir;
                }
                else if(!al_key_down(&keyState, ALLEGRO_KEY_SPACE) && dir == SPACE)
                {
                    dir = previousDir;
                }
                else if(al_key_down(&keyState, ALLEGRO_KEY_SPACE))
                {
                    if(events.timer.source == timerPick) //SPECJALNY TIMER DO SPOWOLNIENIA ANIMACJI KOPANIA
                    {
                        //cout << "space" << endl;
                        dir = SPACE;
                        numberPickAnimation++;
                        if(numberPickAnimation == 2)
                            numberPickAnimation = 0;
                    }
                }

                //else if(al_key_down(&keyState, ALLEGRO_KEY_E) && x >= 160 && x <= 200 && y == 160)
               // {
                    //map.clear();
                    //LoadMap("Map3.txt", map);
                   // dirDoor = 0;
               // }

                else
                    active = false;

            if(active)
                sourceX += al_get_bitmap_width(player) / 4; //podzial na 3 kolumny
            else
                sourceX = 31; //szer calego obrazka to 120 pikseli stad 120/3 = 40

            if(sourceX >= al_get_bitmap_width(player))
                sourceX = 0;

            if(dir==4)
            {

            }else
                sourceY = dir; //zaleznie od wykonanego ruchu

            draw = true;
        al_draw_bitmap(background, 0, 0, NULL);



        //cout << sourceX << " " <<sourceY << endl;
        //RYSOWANIE POSTACI GRACZA
        if(sourceY != 0 || sourceY != 1 || sourceY != 2 || sourceY != 3)
            sourceY = previousDir;

            DrawMap(map, dir, x_player, y_player, point, health, moveSpeed); //RYSOWANIE OBIEKTOW NA MAPIE
            //AddCollisionWall addCollisionWall(x_player, y_player, dir, moveSpeed, map, dirDoor); //DODANIE KOLIZJI DO OBIEKTOW

                    //rotationAxe++;
        //////////////////////////////////////////////////////////////////////////////////////////////////
        //KOPANIE
        if(dir == SPACE && (previousDir == LEFT || previousDir == RIGHT))
        {
                if(previousDir == LEFT)
                    al_draw_bitmap_region(pickPlayer, 37*numberPickAnimation, 0, 37, 46, x_player, y_player, NULL); //"rysuje" rysunek
                if(previousDir == RIGHT)
                    al_draw_bitmap_region(pickPlayer, 37*numberPickAnimation, 46, 37, 46, x_player, y_player, NULL); //"rysuje" rysunek
        }
        else
            al_draw_bitmap_region(player, sourceX, sourceY* al_get_bitmap_height(player) / 4, 31, 40, x_player, y_player, NULL); //"rysuje" rysunek

        //ATAK GRACZA//
        if(attack == 1)
        {
            attackPlayer.moveAttack(x_position_ball, y_position_ball, dirAttack);
            nextAttackPlayer++;
                 //cout << nextAttackPlayer << endl;
            rotationAxe++;
            al_draw_bitmap_region(drawAxe, al_get_bitmap_width(drawAxe)/8 * rotationAxe, 0, al_get_bitmap_width(drawAxe)/8, al_get_bitmap_height(drawAxe), x_position_ball, y_position_ball, NULL);
            if(rotationAxe == 9)
                rotationAxe = 0;

            if(nextAttackPlayer==30)//do tego momentu topor bedzie lecial i nie bedzie mozna wykonac ponownego ataku
            {
                attack = 0;
                nextAttackPlayer = 0; //wyzerowanie w celu przygotowania do kolejnego ataku
            }
        }


        //dodaje potworka
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if(enemyLife == 1)
                {
                    enemy1.moveEnemy(health, point, x_enemy, y_enemy, 0, 50, moveSpeed, x_position_ball, y_position_ball, enemyLife, x_player, y_player);
                }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //dodaje potworka 2
                if(enemyLife2 == 1)
                {
                    enemy2.moveEnemy(health, point, x_enemy2, y_enemy2, 0, 50, moveSpeed, x_position_ball, y_position_ball, enemyLife2, x_player, y_player);
                }

        //DRAW STATS
        al_draw_textf(font8, al_map_rgb(255,255,255), 700, 10, 0, "Score: %d", point);
        al_draw_textf(font8, al_map_rgb(255,255,255), 15, 590, 0, "Health: %d", health);
        al_draw_textf(font8, al_map_rgb(255,255,255), 125, 590, 0, "Keys: %d", key);
        gametime+=1;

        al_draw_textf(font8, al_map_rgb(255,255,255), 625, 10, 0, "Time: %d", clock()/1000);
        //cout << x_position_ball << endl;



            //cout << point << endl;


        al_flip_display();


        }
    }
    if(draw)
    {
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_timer(timerPick);
        al_destroy_bitmap(player);
        al_destroy_bitmap(pickPlayer);
        al_destroy_font(font8);
        al_destroy_event_queue(event_queue);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
int main()
 {

    Window myWindow;
    myWindow.newWindow(800,600, 200, 200); //TWORZE NOWE OKNO

    ImageAndKeyboard newImageMouse; //TWORZE NOWY OBIEKT DO OBSLUGI OBRAZKA
    newImageMouse.mouse(); //INSTALUJE MYSZ I UKRYWAM KURSOR
    newImageMouse.moveImage(); //MOGE RUSZAC OBRAZKIEM

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////

//KAMIL PETK
