class DrawVerticalWall
{ //KLASA RYSUJACA BLOK PIONOWY SCIANY
public:
    DrawVerticalWall(ALLEGRO_BITMAP* bitmap, float ex, float ey)
    {
        createVerticalWall(bitmap, ex, ey);
    }
        void createVerticalWall(ALLEGRO_BITMAP* bitmap, float ex, float ey);
private:
    ALLEGRO_BITMAP* bitmap;
    float ex;
    float ey;
};

void DrawVerticalWall::createVerticalWall(ALLEGRO_BITMAP* bitmap, float ex, float ey)
{
    al_draw_bitmap_region(bitmap, 0, 0, 22, 141, ex+15, ey-50, NULL);
}
