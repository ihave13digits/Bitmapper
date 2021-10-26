class Sky
{
public:

    int inverted = true;

    int duration = 1;
    float hue = -0.5;
    float time = 1.0;
    float move = 1.0;
    float speed = 1.0001; // ~24 Minute Day/Night Cycle

    float tick = 0.0;
    float tick_speed = 0.032;

    int width = 0;
    int height = 0;

    float wind = 0.0;
    float breeze = 0.0;
    float wind_delay = 1.0;

    int day = 0;
    int year = 0;
    int year_length = 360;

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
    int starcount = 256;
    int cloudcount = 1024;
    int humidity = 128;
    int stars[256][2];
    float clouds[1024][3];// x, y, size

    void GenerateSky(int W, int H, int seed=0)
    {
        width = W;
        height = H;
        srand(seed);
        int missed_stars = 0;
        // Distribute Stars
        for (int y = 0; y < 16; y++)
        {
            for (int x = 0; x < 16; x++)
            {
                if (missed_stars > 0)
                {
                    int index = y*16+x;
                    stars[index][0] = rand()%45+(x*45);
                    stars[index][1] = rand()%23+(y*23);
                    missed_stars--;
                }
                if (rand()%100 < 80)
                {
                    int index = y*16+x;
                    stars[index][0] = rand()%45+(x*45);
                    stars[index][1] = rand()%23+(y*23);
                    missed_stars++;
                }
            }
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

    void MoveStars(int x, int y)
    {
        for (int i = 0; i < starcount; i++)
        {
            stars[i][0] += x;
            stars[i][1] += y;

            if (stars[i][0] < 0) stars[i][0] = year_length*2;
            if (stars[i][1] < 0) stars[i][1] = year_length;
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
                wind += 0.01;
                humidity++;
            }
        }
        else
        {
            if (change < 50)
            {
                wind -= 0.01;
                humidity--;
            }
        }

        if (wind > 1.0) wind = 1.0;
        if (wind < -1.0) wind = -1.0;

        if (humidity < 4) humidity = 4;
        if (humidity > cloudcount) humidity = cloudcount-1;

        breeze += 0.01;
        if (breeze > wind_delay) UpdateClouds();
    }

    void UpdateClouds()
    {
        for (int i = 0; i < humidity; i += 4)
        {
            int chance = rand() % 1000;

            clouds[i][0] += wind*.5;
            if (clouds[i][0] <= 0) clouds[i][0] += width;
            else if (clouds[i][0] >= width) clouds[i][0] -= width;
            
            clouds[i+1][0] += wind*.5;
            if (clouds[i+1][0] <= 0) clouds[i+1][0] += width;
            else if (clouds[i+1][0] >= width) clouds[i+1][0] -= width;
            
            clouds[i+2][0] += wind*.5;
            if (clouds[i+2][0] <= 0) clouds[i+2][0] += width;
            else if (clouds[i+2][0] >= width) clouds[i+2][0] -= width;
            
            clouds[i+3][0] += wind*.5;
            if (clouds[i+3][0] <= 0) clouds[i+3][0] += width;
            else if (clouds[i+3][0] >= width) clouds[i+3][0] -= width;

            //
            if (chance < 10)
            {
                int change = rand() % 3-1;
                clouds[i][2] += change;
                if (clouds[i][2] < 1) clouds[i][2] = 1;
                else if (clouds[i][2] > 8) clouds[i][2] = 6;

                clouds[i+1][2] += change;
                if (clouds[i+1][2] < 1) clouds[i+1][2] = 1;
                else if (clouds[i+1][2] > 8) clouds[i+1][2] = 6;

                clouds[i+2][2] += change;
                if (clouds[i+2][2] < 1) clouds[i+2][2] = 1;
                else if (clouds[i+2][2] > 8) clouds[i+2][2] = 6;

                clouds[i+3][2] += change;
                if (clouds[i+3][2] < 1) clouds[i+3][2] = 1;
                else if (clouds[i+3][2] > 8) clouds[i+3][2] = 6;
            }
        }
    }

    void UpdateBodies()
    {
        float PI = 3.14159265358;

        if (move < 0.0) move = duration;

        float value = ((PI/2)+PI)+(move*(PI*2));

        sunx = width*0.5 + (270*cos(value));
        suny = height*0.6 + (80*sin(value));

        moonx = width*0.5 + (260*cos(value));
        moony = height*0.7 + (80*sin(value));
    }

    void UpdateTime(float delta)
    {
        if (!inverted)
        {
            hue -= delta;
            time += delta;
            
            move -= delta;
            if (time > duration)
            {
                MoveStars(-2, -1);
                inverted = true;
                time = duration;
            }
            if (hue < -0.5)
            {
                hue = -0.5;
            }
            UpdateWind();
        }
        else if (inverted)
        {
            hue += delta;
            time -= delta;
            
            move -= delta;
            if (time < 0)
            {
                inverted = false;
                time = 0.0;
                day++;
                if (day > year_length)
                {
                    day = 0;
                    year++;
                }
                tCell::season = day/(year_length/12);
                if (tCell::season > 11) { tCell::season = 11; }
            }
            if (hue > 0.5)
            {
                hue = 0.5;
            }
            UpdateWind();
        }
        if (time < 0.5) starlight = 255*(time*2);
    }

    void UpdateColor()
    {
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

    void Update(float delta)
    {
        UpdateTime(delta*speed);
        UpdateColor();
        tick += delta;
        if (tick >= tick_speed)
        {
            tick -= tick_speed;
            UpdateBodies();
        }
    }

};
