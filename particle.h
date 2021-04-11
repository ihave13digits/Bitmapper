class Particle
{
public:

    int x = 0;
    int y = 0;

    int vx = 0;
    int vy = 0;

    int r = 255;
    int g = 255;
    int b = 255;
    int a = 255;

    float duration = 1.0;

    bool destroys = false;
    bool damages = false;
    bool poisons = false;

    void Position(int X, int Y)
    {
        x = X;
        y = Y;
    }

    void Velocity(int X, int Y)
    {
        if (X > 0) vx = 1;
        if (X < 0) vx = -1;
        if (Y > 0) vy = 1;
        if (Y < 0) vy = -1;
    }

    void Duration(float D)
    {
        duration = D;
    }

    void Color(int R, int G, int B, int A)
    {
        r = R;
        g = G;
        b = B;
        a = A;
    }

    void Move(int X, int Y)
    {
        x += X;
        y += Y;
    }

};
