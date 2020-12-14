class DrawDoor
{ //KLASA RYSUJACA DRZEWI
public:
    DrawDoor(ALLEGRO_BITMAP* bitmap, float ex, float ey)
    {
        createDoor(bitmap, ex, ey);
    }
        void createDoor(ALLEGRO_BITMAP* bitmap, float ex, float ey);

private:
    ALLEGRO_BITMAP* bitmap;
    float ex;
    float ey;
};

void DrawDoor::createDoor(ALLEGRO_BITMAP* bitmap, float ex, float ey)
{
    al_draw_bitmap_region(bitmap, 0, 0, 64, 81, ex, ey, NULL);

}
