class Attack
{
public:
    Attack(float x_player_start, float y_player_start)
        :x_position(x_player_start), y_position(y_player_start){}

    void moveAttack(float &x_position, float &y_position, int dirAttack);

private:
    float x_position;
    float y_position;

};

void Attack::moveAttack(float &x_position, float &y_position, int dirAttack)
{
    //okreslenei w ktora strone ma leciec topor
    if(dirAttack == 0)
        y_position+=5;
    if(dirAttack == 1)
        x_position-=5;
    if(dirAttack == 2)
        x_position+=5;
    if(dirAttack == 3)
        y_position-=5;
}
