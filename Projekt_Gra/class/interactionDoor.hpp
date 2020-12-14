class InteractionDoor
{ //KLAZA WPROWADZAJACA INTERAKCJE Z DRZWIAMI
public:
    InteractionDoor(float &x, float &y, float ex, float ey, int width, int height, int dir, int moveSpeed){}

    bool ifClose(float &x, float &y, float ex, float ey, int width, int height);

private:
    ALLEGRO_BITMAP* bitmap;
    float x;
    float y;
    float ex;
    float ey;
    int width;
    int height;
    int dir;
    int moveSpeed;
};

bool InteractionDoor::ifClose(float &x, float &y, float ex, float ey, int width, int height)
{

    if(x + width < ex || x > ex + width || y + height < ey || y > ey + height)
    {
        return false;
    }
    return true;
}
