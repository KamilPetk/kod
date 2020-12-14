struct Collision
{
public:
    Collision(){}
    ~Collision(){}
    void addCollisionBlock(float& x_player, float& y_player, int x_block, int y_block, int moveSpeed);
private:
};

void Collision::addCollisionBlock(float& x_player, float& y_player, int x_block, int y_block, int moveSpeed)
{
    if(x_block - 10 == x_player && (y_block-20 < y_player && y_player < y_block+20))
        x_player -= moveSpeed;
    else if(x_block + 30 == x_player && (y_block-20 < y_player && y_player < y_block+20))
        x_player += moveSpeed;
}
