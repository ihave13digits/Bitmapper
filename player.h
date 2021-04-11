class Player
{
public:

    enum STATES
    {
    IDLE,
    WALK,
    JUMP,
    FALL,
    HURT,
    TRIP,
    };

    int state = 0;

    int tick = 0;
    int tick_delay = 1;

    int x = 0;
    int y = 0;

    int vx = 0;
    int vy = 0;

    int HP = 100;
    int hp = 100;

    int MP = 100;
    int mp = 100;

    int JP = 100;
    int jp = 100;

    float defense = 0.0;



    void Move(int X, int Y)
    {
        x += X;
        y += Y;
    }

    void TakeDamage(int damage)
    {
        hp -= int(damage-(damage*defense));
    }

};
