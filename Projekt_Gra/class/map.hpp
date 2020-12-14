#include "block_life.hpp"
#include "collision.hpp"
#include <vector>

struct Map
{
public:
    Map(){}

void LoadMap(const char *filename, std::vector<std::vector <int>> &map);
void DrawMap(std::vector <std::vector <int> >& map, int dir, int x, int y, int &points, int &health, int moveSpeed);
};

int state = NULL;
enum LoadState{  TileSet, Map };
ALLEGRO_BITMAP *tileSet;

void LoadMap(const char *filename, std::vector<std::vector <int>> &map)
{
    std::ifstream openfile(filename);
    if(openfile.is_open())
    {
        std::string line, value;
        int space;

        while(!openfile.eof())
        {
            std::getline(openfile, line);

            if(line.find("[TileSet]") != std::string::npos)
            {
                state = TileSet;
                continue;
            }
            else if(line.find("[Map") != std::string::npos)
            {
                state = Map;
                continue;
            }

        switch(state)
        {
        case TileSet:
            if(line.length() > 0)
                tileSet = al_load_bitmap(line.c_str());
            //std::cout << line.c_str();
            break;
         case Map:
            std::stringstream str(line);
            std::vector<int> tempVector;

            while(!str.eof())
            {
                std::getline(str, value, ' ');

                //std::cout << value << endl;
                if(value.length() > 0)
                    tempVector.push_back(atoi(value.c_str())); //c_str zwraca lancuch znakow tylko do odczytu w standardzie jezyka C
                                     //atoi - Konwertuje wartoc zapisana w 3ancuchu znakow do postaci liczby typu ca3kowitego (int).
                //std::cout << atoi(value.c_str()) << endl;

            }
            //std::cout << tempVector.size() << std::endl;
            map.push_back(tempVector);
            //std::cout << map[0][0];
            break;
        }
        }
    }
    else
    {

    }
}
int cos = 0;

int key = 0;
int keyChest = 0;

std::vector<int> blocksHealth {100,100,100,100,100,100,100,100,100,100,100,100};
void DrawMap(std::vector <std::vector <int> >& map, int dir, float& x, float& y, int &points, int &health, int moveSpeed) //dzieki & moge dokonac trwalej zmiany w wektorze
                                                                //x = x_player, y = y_player
{

    //cout << "first" << map[1][4] << endl;
    //cout << x << ", " << y << endl;
    //std::cout << map[0].size() << std::endl;
    for(int i = 0; i < map.size(); i++)
    {
        int nVertical = 0;
        int nHorizontal = 0;
        //std::cout << map[i].size() << std::endl;
        for(int j = 0; j < map[i].size(); j++)
        {
            if(map[i][j] == 0)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40 , NULL);
            }
            else if(map[i][j] == 1)
            {
                if(j*40 - 10 <= x + 10 && x - 10 <= j*40 + 30 && i*40 <= y + 40 && y - 40 <= i*40 && dir == 4 && key != 0)
                {
                    map[i][j] = 4;
                    key--;
                }
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
                Collision door;
                door.addCollisionBlock(x, y, j * 40, i * 40, moveSpeed);
            }

            else if(map[i][j] == 2)
            {
                if(j*40 <= x + 10 && x - 10 <= j*40 && i*40 == y) //jesli gracz wejdzie w punkt
                {
                    map[i][j] = 3;
                    points++; //dodanie pkt do statystyk
                }
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 3)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);


            }
            else if(map[i][j] == 4)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);

            }
            else if(map[i][j] == 5)
            {
                if(j*40 <= x + 10 && x - 10 <= j*40 && i*40 == y) //jesli gracz wejdzie w kluczyk
                {
                    map[i][j] = 3;
                    key++; //dodanie kluczyka do ekwipunku
                }
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 6)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);

                if(j*40 <= x + 10 && x - 10 <= j*40 && i*40 <= y + 10 && y - 15 <= i*40)
                    health -= 1;
            }
            else if(map[i][j] == 7)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);

                if(j*40 <= x + 10 && x - 10 <= j*40 && i*40 <= y + 10 && y - 15 <= i*40)
                {
                    map[i][j] = 3;
                    if(health > 75)
                        health = 100;
                    else
                        health += 25;
                }
            }
            else if(map[i][j] == 8)
            {
                if(j*40 <= x + 10 && x - 10 <= j*40 && i*40 == y) //jesli gracz wejdzie w punkt
                {
                    map[i][j] = 9;
                    health -= 100;
                }
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 9)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 10)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);

                BlockLife lifeBlock;
                if(dir == 6 && (j*40 - 20 < x && x < j*40+20) && (i*40-50 < y && y < i*40+20) )
                {
                    lifeBlock.destruct_block(blocksHealth[0]);
                    if( blocksHealth[0] == 0)
                    {
                        map[i][j] = 3;
                        y += 80;
                        blocksHealth[0] = 100;
                   }
               }
               else if(dir != 6)
               {
                   blocksHealth[0] = 100;
               }
            }
            else if(map[i][j] == 11)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);

                BlockLife lifeBlock;
                if(dir == 6 && (j*40 - 20 < x && x < j*40+20) && (i*40-50 < y && y < i*40+20) )
                {
                    lifeBlock.destruct_block(blocksHealth[1]);
                    if( blocksHealth[1] == 0)
                    {
                        map[i][j] = 3;
                        y += 80;
                        blocksHealth[1] = 100;
                   }
               }
               else if(dir != 6)
               {
                   blocksHealth[1] = 100;
               }
            }
            else if(map[i][j] == 12)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
                BlockLife lifeBlock;
                if(dir == 6 && (j*40 - 20 < x && x < j*40+20) && (i*40-50 < y && y < i*40+20) )
                {
                    lifeBlock.destruct_block(blocksHealth[2]);
                    if( blocksHealth[2] == 0)
                    {
                        map[i][j] = 3;
                        y += 80;
                        blocksHealth[2] = 100;
                   }
               }
               else if(dir != 6)
               {
                   blocksHealth[2] = 100;
               }
            }
            else if(map[i][j] == 13)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
                //std::cout << x << " " << y;
                //std::cout << std::endl;
                //std::cout << "BLOK" << j*40 << std::endl;
               BlockLife lifeBlock;
               if(dir == 6 && (j*40 - 20 < x && x < j*40+20) && (i*40-50 < y && y < i*40+20) )
               {
                   lifeBlock.destruct_block(blocksHealth[3]);

                   if( blocksHealth[3] == 0)
                   {
                    map[i][j] = 3;
                    y += 80;
                    blocksHealth[3] = 100;
                   }
               }
               else if(dir != 6)
               {
                   blocksHealth[3] = 100;
               }
            }
            else if(map[i][j] == 14)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);

                BlockLife lifeBlock;
                if(dir == 6 && (j*40 - 20 < x && x < j*40+20) && (i*40-50 < y && y < i*40+20) )
                {
                    lifeBlock.destruct_block(blocksHealth[4]);
                    if( blocksHealth[4] == 0)
                    {
                        map[i][j] = 3;
                        y += 80;
                        blocksHealth[4] = 100;
                   }
                   else if(dir != 6)
                   {
                        blocksHealth[4] = 100;
                   }
               }
            }
            else if(map[i][j] == 15)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);

                BlockLife lifeBlock;
                if(dir == 6 && (j*40 - 20 < x && x < j*40+20) && (i*40-50 < y && y < i*40+20) )
                {
                    lifeBlock.destruct_block(blocksHealth[5]);
                    if( blocksHealth[5] == 0)
                    {
                        map[i][j] = 3;
                        y += 80;
                        blocksHealth[5] = 100;
                   }
                   else if(dir != 6)
                   {
                        blocksHealth[5] = 100;
                   }
               }
            }
            else if(map[i][j] == 16)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);

                BlockLife lifeBlock;
                if(dir == 6 && (j*40 - 20 < x && x < j*40+20) && (i*40-50 < y && y < i*40+20) )
                {
                    lifeBlock.destruct_block(blocksHealth[6]);
                    if( blocksHealth[6] == 0)
                    {
                        map[i][j] = 3;
                        y += 80;
                        blocksHealth[6] = 100;
                   }
                   else if(dir != 6)
                   {
                        blocksHealth[6] = 100;
                   }
               }
            }
            else if(map[i][j] == 17)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);

                BlockLife lifeBlock;
                if(dir == 6 && (j*40 - 20 < x && x < j*40+20) && (i*40-50 < y && y < i*40+20) )
                {
                    lifeBlock.destruct_block(blocksHealth[7]);
                    if( blocksHealth[7] == 0)
                    {
                        map[i][j] = 3;
                        y += 80;
                        blocksHealth[7] = 100;
                   }
                   else if(dir != 6)
                   {
                        blocksHealth[7] = 100;
                   }
               }
            }
            else if(map[i][j] == 18)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);

                BlockLife lifeBlock;
                if(dir == 6 && (j*40 - 20 < x && x < j*40+20) && (i*40-50 < y && y < i*40+20) )
                {
                    lifeBlock.destruct_block(blocksHealth[8]);
                    if( blocksHealth[8] == 0)
                    {
                        map[i][j] = 3;
                        y += 80;
                        blocksHealth[8] = 100;
                   }
                   else if(dir != 6)
                   {
                        blocksHealth[8] = 100;
                   }
               }
            }
            else if(map[i][j] == 19)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);

                BlockLife lifeBlock;
                if(dir == 6 && (j*40 - 20 < x && x < j*40+20) && (i*40-50 < y && y < i*40+20) )
                {
                    lifeBlock.destruct_block(blocksHealth[9]);
                    if( blocksHealth[9] == 0)
                    {
                        map[i][j] = 3;
                        y += 80;
                        blocksHealth[9] = 100;
                   }
                   else if(dir != 6)
                   {
                        blocksHealth[9] = 100;
                   }
               }
            }
            else if(map[i][j] == 20)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);

                BlockLife lifeBlock;
                if(dir == 6 && (j*40 - 20 < x && x < j*40+20) && (i*40-50 < y && y < i*40+20) )
                {
                    lifeBlock.destruct_block(blocksHealth[10]);
                    if( blocksHealth[10] == 0)
                    {
                        map[i][j] = 3;
                        y += 80;
                        blocksHealth[10] = 100;
                   }
                   else if(dir != 6)
                   {
                        blocksHealth[10] = 100;
                   }
               }
            }
            else if(map[i][j] == 21)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);

                BlockLife lifeBlock;
                if(dir == 6 && (j*40 - 20 < x && x < j*40+20) && (i*40-50 < y && y < i*40+20) )
                {
                    lifeBlock.destruct_block(blocksHealth[11]);
                    if( blocksHealth[11] == 0)
                    {
                        map[i][j] = 3;
                        y += 80;
                        blocksHealth[11] = 100;
                   }
                   else if(dir != 6)
                   {
                        blocksHealth[11] = 100;
                   }
               }
            }
            else if(map[i][j] == 22)
            {
                if(j*40 <= x + 10 && x - 10 <= j*40 && i*40 == y && keyChest != 0) //jesli gracz wejdzie w punkt
                {
                    map[i][j] = 23;
                    keyChest--;
                }
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 23)
            {
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 24)
            {
                if(j*40 <= x + 10 && x - 10 <= j*40 && i*40 == y) //jesli gracz wejdzie w kluczyk
                {
                    map[i][j] = 3;
                    keyChest--; //dodanie kluczyka do ekwipunku
                }
                al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
        }
    }
}
