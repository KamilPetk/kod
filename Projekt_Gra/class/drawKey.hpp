class DrawKey
{ //KLASA RYSUJACA KLUCZ
public:
    DrawKey(ALLEGRO_BITMAP* bitmap, float ex, float ey)
    {
        createKey(bitmap, ex, ey);
    }
        void createKey(ALLEGRO_BITMAP* bitmap, float ex, float ey);

private:
    ALLEGRO_BITMAP* bitmap;
    float ex;
    float ey;
};

void DrawKey::createKey(ALLEGRO_BITMAP* bitmap, float ex, float ey)
{
    al_draw_bitmap_region(bitmap, 0, 0, 64, 81, ex, ey, NULL);
}
