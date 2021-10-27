namespace tTool
{

    int GetType(int tile_index) { return tTile::TYPE[tile_index]; }



    //
    //
    //

    float GetLightValue(int x, int y)
    {
        int t = tCell::matrix[y*tCell::width+x];
        float value;
        if (t == tTile::FIRE ||
            t == tTile::FLAME ||
            t == tTile::FLARE ||
            t == tTile::MAGMA ||
            t == tTile::LAVA ||
            t == tTile::SPARK ||
            t == tTile::ARC)
        {
            value = (((rand()%100) * tTile::LIGHT[t]) * 0.01);
        }
        else
        {
            value = tTile::LIGHT[t];
        }
        return value;
    }

    float Neighbors(int x, int y)
    {
        float value = 0.0;

        value += GetLightValue(  x, y-3);
        value += GetLightValue(  x, y-2);
        value += GetLightValue(x-1, y-1);
        value += GetLightValue(x+1, y-1);
        value += GetLightValue(x-2,   y);
        value += GetLightValue(x+2,   y);

        return value;
    }

    int GetDurability(int x, int y)
    {
        int index = tCell::matrix[y*tCell::width+x];
        return tTile::POWER[index];
    }



    //
    //
    //

    bool FluidCollision(int x, int y)
    {
        return (tCell::replace[y*tCell::width+x] > tTile::OIL_FUMES);
    }

    bool DualCollision(int x, int y)
    {
        int index = y*tCell::width+x;
        return bool(tCell::matrix[index]) || bool(tCell::replace[index]);
    }

    bool Collision(int x, int y)
    {
        return bool(tCell::matrix[y*tCell::width+x]);
    }

    bool IsColliding(int x, int y)
    {
        return tCell::matrix[y*tCell::width+x] > tTile::MOLTEN_SLAG;
    }



    //
    //
    //

}
