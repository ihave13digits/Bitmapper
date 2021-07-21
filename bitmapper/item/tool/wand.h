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
        //e.sticky = true;
        e.bouncy = true;
        //e.heavy = true;
        //e.destroys = true;
        e.becomes = true;
        //e.damages = true;
        e.pierces = true;
        //e.poisons = true;
        e.trails = true;
        //e.mines = true;
        //e.trips = true;
        //e.stuns = true;
        //e.burns = true;
        
        e.tile_trail = tTile::FIRE;
        e.tile_value = tTile::DYNAMITE;
        //e.damage = 1.0;
        //e.drain = 1.0;

        //e.name = "";

        return e;
    }

    void GenerateWand()
    {
        GenerateStats();
        Effect e = GenerateSpell();
        effects.push_back(e);
    }

    void GenerateStats()
    {
        shuffle = bool(rand()%2);
        capacity = 1;
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
