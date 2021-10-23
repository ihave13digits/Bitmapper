class Wand
{

public:

    bool shuffle;
    bool can_fire;
    int capacity;
    int current_effect = 0;
    int material;
    float fire_rate;
    float tick = 0.0;
    float mp = 0.0;
    float MP = 0.0;

    std::vector<Effect> effects;

    Effect GenerateSpell()
    {
        Effect e = Effect();
        if (rand()%1000 < 100) e.sticky = true;
        if (rand()%1000 < 100) e.bouncy = true;
        if (rand()%1000 < 100) e.heavy = true;
        if (rand()%1000 < 200) e.destroys = true;
        if (rand()%1000 < 200) e.becomes = true;
        if (rand()%1000 < 200) e.damages = true;
        if (rand()%1000 < 100) e.pierces = true;
        if (rand()%1000 < 100) e.poisons = true;
        if (rand()%1000 < 200) e.trails = true;
        if (rand()%1000 < 200) e.mines = true;
        if (rand()%1000 < 100) e.trips = true;
        if (rand()%1000 < 100) e.stuns = true;
        if (rand()%1000 < 100) e.burns = true;
        
        if (e.trails) e.tile_trail = rand()%tTile::total_tiles-1;
        if (e.becomes) e.tile_value = rand()%tTile::total_tiles-1;
        
        e.damage = 1.0;
        e.drain = 1.0;

        //e.name = "";

        return e;
    }

    void GenerateWand()
    {
        GenerateStats();
        for (int i = 0; i < capacity; i++)
        {
            Effect e = GenerateSpell();
            effects.push_back(e);
        }
    }

    void GenerateStats()
    {
        shuffle = bool(rand()%2);
        capacity = rand()%6 + 2;
        fire_rate = 0.1;
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
