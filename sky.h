class Sky
{
public:

    int inverted = true;

    int duration = 1;
    int tick_delay = 1;
    int tick = 0;
    float hue = -0.5;
    float time = 1.0;
    float move = 1.0;
    float delta = 0.001;

    int width = 0;
    int height = 0;

    float wind = 0.0;
    float breeze = 0.0;
    float wind_delay = 1.0;

    int R = 0;
    int G = 0;
    int B = 0;

    int r = 0;
    int g = 0;
    int b = 0;

    int sun = 8;
    int sunx = 128;
    int suny = 16;
    int moon = 7;
    int moonx = 128;
    int moony = 16;

    int starlight = 255;
    int starcount = 32;
    int cloudcount = 1024;
    int humidity = 512;
    int stars[32][2];
    int clouds[1024][3];

    void GenerateSky(int W, int H, int seed=0, int spd=1)
    {
        width = W;
        height = H;
        tick_delay = spd;
        srand(seed);
        for (int i = 0; i < starcount; i++)
        {
            stars[i][0] = rand() % W;
            stars[i][1] = rand() % H;
        }

        int C = cloudcount/4;
        for (int i = 0; i < C; i++)
        {
            clouds[i][0] = rand() % W;
            clouds[i][1] = rand() % 64;
            clouds[i][2] = rand() % 6 + 1;
        }
        for (int i = C; i < C*2; i++)
        {
            clouds[i][0] = rand() % W;
            clouds[i][1] = rand() % 48;
            clouds[i][2] = rand() % 4 + 1;
        }
        for (int i = C*2; i < C*3; i++)
        {
            clouds[i][0] = rand() % W;
            clouds[i][1] = rand() % 24;
            clouds[i][2] = rand() % 2 + 1;
        }
        for (int i = C*3; i < C*4; i++)
        {
            clouds[i][0] = rand() % W;
            clouds[i][1] = rand() % 16;
            clouds[i][2] = rand() % 1 + 1;
        }
    }

    void UpdateWind()
    {
        int chance = rand() % 100;
        int change = rand() % 100;
        if (chance < 50)
        {
            if (change < 50)
            {
                wind += 0.05;
                humidity++;
            }
        }
        else
        {
            if (change < 50)
            {
                wind -= 0.05;
                humidity--;
            }
        }

        if (wind > 4.0) wind = 4.0;
        if (wind < -4.0) wind = -4.0;

        if (humidity < 4) humidity = 4;
        if (humidity > cloudcount) humidity = cloudcount-1;

        breeze += 0.01;
        if (breeze > wind_delay) UpdateClouds();
    }

    void UpdateClouds()
    {
        int C = humidity/4;

        for (int i = 0; i < C; i++)
        {
            clouds[i][0] += wind*.5;
            if (clouds[i][0] <= 0) clouds[i][0] += width;
            else if (clouds[i][0] >= width) clouds[i][0] -= width;
        }
        for (int i = C; i < C*2; i++)
        {
            clouds[i][0] += wind*.75;
            if (clouds[i][0] <= 0) clouds[i][0] += width;
            else if (clouds[i][0] >= width) clouds[i][0] -= width;
        }
        for (int i = C*2; i < C*3; i++)
        {
            clouds[i][0] += wind;
            if (clouds[i][0] <= 0) clouds[i][0] += width;
            else if (clouds[i][0] >= width) clouds[i][0] -= width;
        }
        for (int i = C*3; i < C*4; i++)
        {
            clouds[i][0] += wind*1.25;
            if (clouds[i][0] <= 0) clouds[i][0] += width;
            else if (clouds[i][0] >= width) clouds[i][0] -= width;
        }
    }

    void UpdateBodies()
    {
        float PI = 3.14159265358;

        if (move < 0.0) move = duration;

        float value = ((PI/2)+PI)+(move*(PI*4));

        sunx = width*0.5 + (270*cos(value));
        suny = height*0.6 + (80*sin(value));

        moonx = width*0.5 + (260*cos(value));
        moony = height*0.7 + (80*sin(value));
    }

    void UpdateTime()
    {
        if (!inverted)
        {
            if (tick > tick_delay)
            {
                tick = 0;
                hue -= delta;
                time += delta;
                move -= delta/2;
                UpdateWind();
                if (time > duration)
                {
                    inverted = true;
                    time = duration;
                }
                if (hue < -0.5)
                {
                    hue = -0.5;
                }
            }
        }
        else if (inverted)
        {
            if (tick > tick_delay)
            {
                tick = 0;
                hue += delta;
                time -= delta;
                move -= delta/2;
                UpdateWind();
                if (time < 0)
                {
                    inverted = false;
                    time = 0.0;
                }
                if (hue > 0.5)
                {
                    hue = 0.5;
                }
            }
        }
        if (time < 0.5) starlight = 255*(time*2);
    }

    void Update()
    {
        UpdateTime();
        UpdateBodies();

        float H = 1.0 - hue;
        if (hue < 0.0)
            H = 1.0 + hue;

        R = int(time*0.5*255);
        G = int(time*0.5*255);
        B = time*255;

        r = int(H*255);
        g = int(((H+time)/2)*255);
        b = int(H*255);
    }

};
