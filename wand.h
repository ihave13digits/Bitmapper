class Wand
{

public:

    bool shuffle;
    bool can_fire;
    int capacity;
    int current_effect = 0;
    float fire_rate;
    float tick = 0.0;

    std::vector<Effect> effects;

    void GenerateWand()
    {
        GenerateStats();
    }

    void GenerateStats()
    {
        shuffle = bool(rand()%2);
        capacity = 5;
        fire_rate = 0.5;
    }

    void Update(float delta)
    {
        tick += delta;
        if (tick >= fire_rate)
        {
            tick -= fire_rate;
            can_fire = true;
        }
    }

    void Cast()
    {
        can_fire = false;
        current_effect++;
        if (current_effect >= effects.size())
        {
            current_effect = 0;
        }
    }

};
