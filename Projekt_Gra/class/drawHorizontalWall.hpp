class DrawHorizontalWall
{ //KLASA RYSUJACA BLOK POZIOMY SCIANY
public:
    DrawHorizontalWall(ALLEGRO_BITMAP* bitmap, float ex, float ey)
    {
        createHorizontalWall(bitmap, ex, ey);
    }
        void createHorizontalWall(ALLEGRO_BITMAP* bitmap, float ex, float ey);
private:
    ALLEGRO_BITMAP* bitmap;
    float ex;
    float ey;
};

void DrawHorizontalWall::createHorizontalWall(ALLEGRO_BITMAP* bitmap, float ex, float ey)
{
    al_draw_bitmap_region(bitmap, 0, 0, 141, 22, ex-50, ey+15, NULL);
}
