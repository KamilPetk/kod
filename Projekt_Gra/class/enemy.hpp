#include <iostream>
using namespace std;

class Enemies
{
public:
    Enemies(char rl, float x_start, float y_start)
        :rl(rl), x_start(x_start), y_start(y_start)
        {}
    ~Enemies(){}
    void moveEnemy(int &health, int &points, float &x, float &y, float x_distance, float y_distance, int moveSpeed, float x_position_ball, float y_position_ball, int &enemyLife, float x_player, float y_player);
    void atack(int &health, int x_enemy, int y_enemy, float x_player, float y_player);
    void attackFireBallEnemy(int &health, float &x, float &y, int &shotTime, int &nextShotTime, int x_enemy, int y_enemy, int &ifAttackEnemy, float x_player, float y_player);
private:
    ALLEGRO_BITMAP *enemy = al_load_bitmap("ghost.png");
    ALLEGRO_BITMAP *drawFireBall = al_load_bitmap("point.png");

    char rl;
    float x_start;
    float y_start;
    int healthEnemie = 100;
    float x_fireBall_position_enemy = 0; //dwie wspolrzedne do okreslenia miejsca wystrzylu przez potworka
    float y_fireBall_position_enemy = 0;
    int shotTime = 0; //licznik czasu trwania strzalu
    int nextShotTime = 0; // licznik do kolejnego strzalu
    int ifAttackEnemy = 1; //czy strzelac? 0 - nie, 1 - tak

};

void Enemies::moveEnemy(int &health, int &points, float &x, float &y, float x_distance, float y_distance, int moveSpeed, float x_position_ball, float y_position_ball, int &enemyLife, float x_player, float y_player)
{

    if(rl == 'r')
    {
        x++;
        if(x  == x_start+x_distance) //gdy dojdzie na max w prawo to rl = 'l' czyli zmienai kierunek na lewo
            rl = 'l';
    }
    else if(rl == 'l')
    {
        x--;
        if(x == x_start) //analogicznie jak wyzej
            rl = 'r';
    }
    else if(rl == 'd')
    {
        y++;
        if(y == y_start+y_distance)
            rl = 'u';
    }
    else if(rl = 'u')
    {
        y--;
        if(y == y_start)
            rl = 'd';
    }

    if(x - 10 <= x_position_ball && x + 10 >= x_position_ball && y - 10 <= y_position_ball && y+10 >= y_position_ball)
        healthEnemie-=10;
    if(healthEnemie <= 0)
    {
        enemyLife = 0;
        points += 10;
    }

    //cout << x << ", " << y << endl;
    //cout << x_position_ball << ", " << y_position_ball << endl;
    //cout << healthEnemie << endl;
    al_draw_bitmap(enemy, x, y, NULL); //rysuj potworka
    atack(health, x, y, x_player, y_player); //zadawanie obrazen przy zetknieciu z graczem
                //cout << attackEnemy1 << endl;
    if(ifAttackEnemy == 1)
    {
        attackFireBallEnemy(health, x_fireBall_position_enemy, y_fireBall_position_enemy, shotTime, nextShotTime, x, y, ifAttackEnemy, x_player, y_player);
        nextShotTime++;
    }

}
void Enemies::atack(int &health, int x_enemy, int y_enemy, float x_player, float y_player)
{
    if(x_enemy - 25 <= x_player && x_enemy + 25 >= x_player && y_enemy - 25 <= y_player && y_enemy + 25 >= y_player)
        health -= 1;
    //cout << health << endl;
}
void Enemies::attackFireBallEnemy(int &health, float &x, float &y, int &shotTime, int &nextShotTime, int x_enemy, int y_enemy, int &ifAttackEnemy, float x_player, float y_player)
{
    //cout << x << " " << y << endl;
    shotTime++;
    nextShotTime++;
    //cout << nextShotTime << endl;
    x--;
    if(shotTime > 100 && nextShotTime == 101)//odliczanie czasu lecenia kulki
    {
        shotTime = 0; //wyzerowanie do ponownego odliczania
        ifAttackEnemy = 0;

    }
    if(nextShotTime > 101)
    {
        x = x_enemy;
        y = y_enemy;
        nextShotTime = 0;
        ifAttackEnemy = 1;
    }
    if(x - 18 <= x_player && x + 18 >= x_player && y - 40 <= y_player && y + 10 >= y_player)
        health -= 1;
    //cout << health << endl;
    al_draw_bitmap(drawFireBall, x, y, NULL);
}
