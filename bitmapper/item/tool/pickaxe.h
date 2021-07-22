class Pickaxe
{

public:

    bool can_use;
    float tick;
    float speed;
    float power;
    char tile_type[2] = { tTile::SOLID, tTile::LOOSE };

    void Update(float delta)
    {
        tick += delta;
        if (tick > speed)
        {
            tick -= speed;
            can_use = true;
        }
    }

    void Use()
    {
        can_use = false;
    }

};
