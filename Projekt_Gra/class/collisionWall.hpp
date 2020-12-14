class CollisionWall
{ //TWORZENIE KOLIZJI DLA BLOKU SCIANY
public:
    CollisionWall(float &x, float &y, float ex, float ey, int width, int height, int dir, int moveSpeed)
    {
        if(ifCollision(x, y, ex, ey, width, height))
        {
            collision(x, y, dir, moveSpeed);
        }
    }

    bool ifCollision(float &x, float &y, float ex, float ey, int width, int height);
    void collision(float &x, float &y, int dir, int moveSpeed);

private:
    float x;
    float y;
    float ex;
    float ey;
    int width;
    int height;
    int dir;
    int moveSpeed;
};

bool CollisionWall::ifCollision(float &x, float &y, float ex, float ey, int width, int height)
{

    if(x + width < ex || x > ex + width || y + height < ey || y > ey + height)
    {
        return false;
    }
    return true;
}

void CollisionWall::collision(float &x, float &y, int dir, int moveSpeed)
{
    if(dir == 0)
        y -= moveSpeed; //jak podchode pod blok to nie poruszam sie poniewaz moje przemieszczenie po wsp. y jest zerowe gdyz¿ y -= moveSpeed itp. w kolejnych przypadkach
                    //std::cout << x << "," << y << std::end
    else if(dir == 1)
        x += moveSpeed;
    else if(dir == 2)
        x -= moveSpeed;
    else if(dir == 3)
        y += moveSpeed;
}
