class Player
{
public:

    enum STATUS
    {
        FINE,
        HURT,
        BURN,
        COLD,
        STUN,
        TRIP,
        DROWN,
        POISON,
        CONFUSED,
    };

    enum STATES
    {
        IDLE,
        WALK,
        JUMP,
        FALL,
        SWIM,
    };

    int state = 0;
    int status = 0;

    int tick = 0;
    int tick_delay = 1;

    int damage_tick = 0;
    int damage_delay = 10;

    int burn_tick = 0;
    int toxic_tick = 0;

    int x = 0;
    int y = 0;

    int vx = 0;
    int vy = 0;

    int height = 2;

    int HP = 100;
    int hp = 100;

    int MP = 100;
    int mp = 100;

    int JP = 100;
    int jp = 100;

    int bp = 100;
    int BP = 100;

    float defense = 0.0;

    int hotbar[9][2] =
    {
        {1, 0},
        {2, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
    };



    void Move(int X, int Y)
    {
        x += X;
        y += Y;
    }

    void TakeDamage(int damage)
    {
        hp -= int(damage-(damage*defense));
        state = HURT;
    }

    void Update()
    {
        tick = 0;
        
        // Update Counters
        if (jp < JP && state != JUMP) jp++;
        if (bp < BP && state != DROWN) bp++;
        // Update Tick Damage
        if (status != FINE) damage_tick++;
        
        if (damage_tick > damage_delay)
        {
            damage_tick = 0;
            switch (status)
            {
                case DROWN :
                {
                    TakeDamage(1);
                }
                break;

                case BURN :
                {
                    TakeDamage(1);
                    burn_tick++;
                    if (burn_tick > 25)
                    {
                        burn_tick = 0;
                        status = FINE;
                    }
                }
                break;
            }
        }
    }

};
