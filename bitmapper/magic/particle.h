class Particle
{
public:

    float x = 0;
    float y = 0;

    float vx = 0;
    float vy = 0;

    float speed = 25.0;
    float gravity = 0.3;
    float max_speed = 1.0;

    int r = 255;
    int g = 255;
    int b = 255;
    int a = 255;

    Effect effect;

    float drop_tick = 0.0;
    float drop_rate = 0.25;
    float duration = 5.0;

    void Position(float X, float Y)
    {
        x = X;
        y = Y;
    }

    void Velocity(float X, float Y)
    {
        vx = X;
        vy = Y;
        CheckSpeed();
    }

    bool CanDrop(float delta)
    {
        bool can_drop = false;
        drop_tick += delta;
        if (drop_tick > drop_rate) { drop_tick -= drop_rate; can_drop = true; }
        return can_drop;
    }
    
    void Move(float X, float Y, float delta, bool collision)
    {
        CheckSpeed();
        if (!collision)
        {
            x += X*speed*delta;
            if (!effect.heavy) y += (Y+gravity)*speed*delta;
            if (effect.heavy) y += (Y+(gravity*2))*speed*delta;
        }
        else
        {
            if (effect.bouncy)
            {
                vx = -X;
                vy = -Y;
            }
            if (effect.sticky)
            {
                vx = 0.0;
                vy = 0.0;
            }
        }
    }

    void CheckSpeed()
    {
        if (vx > max_speed) vx = max_speed;
        else if (vx < -max_speed) vx = -max_speed;
        
        if (vy > max_speed) vy = max_speed;
        else if (vy < -max_speed) vy = -max_speed;
    }

    void Duration(float D)
    {
        duration = D;
    }

    void SetEffect(Effect e)
    {
        effect = e;
    }

    void Color(int R, int G, int B, int A)
    {
        r = R;
        g = G;
        b = B;
        a = A;
    }
};
