struct AddCollisionWall
{ //STRUKTURA DODAJACA KOLIZJE DO ELEMENTOW
    AddCollisionWall(float &x, float &y, int dir, int moveSpeed, std::vector <std::vector <int> > map, int dirDoor)
    {
        addCollisionWall(x, y, dir, moveSpeed, map, dirDoor);
    }

    void addCollisionWall(float &x, float &y, int dir, int moveSpeed, std::vector <std::vector <int> > map, int dirDoor);
private:
    //std::vector <std::vector <int> > map;
    float x;
    float y;
    int dir;
    int moveSpeed;
};

void AddCollisionWall::addCollisionWall(float &x, float &y, int dir, int moveSpeed, std::vector <std::vector <int> > map, int dirDoor)
{
    //std::cout << dirDoor << std::endl;

    int yy = 0;// wspolrzedna y srodku obiektu
    for(int i = 0; i < map.size(); i++)
    {
        int xx = 0; // wspolrzedna x srodku obiektu

        int nVertical = 0;
        int nHorizontal = 0;

        yy++;
        //std::cout << yy << std::endl;
        for(int j = 0; j < map[i].size(); j++)
        {
            if(map[i][j] == 0)
            {//IF NO GRAPHICS
                //xx +=2;
                //std::cout << map[i][j] << std::endl;
            }
            else if(map[i][j] == 1)
            {//IF NO GRAPHICS
                //xx +=2;
                //std::cout << map[i][j] << std::endl;
            }
            else if(map[i][j] == 2)
            {//IF NO GRAPHICS
                //xx +=2;
                //std::cout << map[i][j] << std::endl;
            }
            else if(map[i][j] == 3)
            {//IF NO GRAPHICS
                //xx +=2;
                //std::cout << map[i][j] << std::endl;
            }
            else if(map[i][j] == 4)
            {//IF NO GRAPHICS
                //xx +=2;
                //std::cout << map[i][j] << std::endl;
            }
            else if(map[i][j] == 5)
            {//IF NO GRAPHICS
               // xx +=2;
                //std::cout << map[i][j] << std::endl;
            }
            else if(map[i][j] == 6)
            {//IF NO GRAPHICS
                //xx +=2;
                //std::cout << map[i][j] << std::endl;
            }
            else if(map[i][j] == 7)
            {//IF NO GRAPHICS
                //xx +=2;
                //std::cout << map[i][j] << std::endl;
            }
            else if(map[i][j] == 8)
            {//IF NO GRAPHICS
                //xx +=2;
                //std::cout << map[i][j] << std::endl;
            }
            else if(map[i][j] == 9)
            {//IF NO GRAPHICS
                //xx +=2;
                //std::cout << map[i][j] << std::endl;
            }
            else if(map[i][j] == 10)
            {//CLOSE DOOR
                //std::cout << map[i][j] << std::endl;
                //xx +=2;
            }
            else if(map[i][j] == 11)
            {//IF NO GRAPHICS
                //xx +=2;
                //std::cout << map[i][j] << std::endl;
            }
            else if(map[i][j] == 12)
            {
               // al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 13)
            {
                //al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 14)
            {
                //al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 15)
            {
                //al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 16)
            {
                //al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 17)
            {
                //al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 18)
            {
               // al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 19)
            {
               // al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 20)
            {
               // al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 21)
            {
                //al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 22)
            {

            }
            else if(map[i][j] == 23)
            {
                //al_draw_bitmap_region(tileSet, map[i][j] * 40, 0, 40, 40, j * 40, i * 40, NULL);
            }
            else if(map[i][j] == 24)
            {

            }
        }

    }
}
