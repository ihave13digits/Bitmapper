namespace tTool
{

    int GetType(int tile_index) { return tTile::TYPE[tile_index]; }
    std::string GetName(int tile_index) { return tTile::NAME[tile_index]; }
    int GetDurability(int x, int y) { int index = tCell::matrix[y*tCell::width+x]; return tTile::POWER[index]; }



    //
    // Lighting
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
        { value = (((rand()%100) * tTile::LIGHT[t]) * 0.01); }
        else { value = tTile::LIGHT[t]; }
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



    //
    // Collisions
    //

    //
    bool GasCollision(int x, int y)   { int index = y*tCell::width+x; return (tCell::matrix[index] > tTile::AIR         || tCell::replace[index] > tTile::AIR)        ; }
    bool FumeCollision(int x, int y)  { int index = y*tCell::width+x; return (tCell::matrix[index] > tTile::SPARK       || tCell::replace[index] > tTile::SPARK)      ; }
    bool FluidCollision(int x, int y) { int index = y*tCell::width+x; return (tCell::matrix[index] > tTile::OIL_FUMES   || tCell::replace[index] > tTile::OIL_FUMES)  ; }
    bool GelCollision(int x, int y)   { int index = y*tCell::width+x; return (tCell::matrix[index] > tTile::BLOOD       || tCell::replace[index] > tTile::BLOOD)      ; }
    bool GrainCollision(int x, int y) { int index = y*tCell::width+x; return (tCell::matrix[index] > tTile::MOLTEN_SLAG || tCell::replace[index] > tTile::MOLTEN_SLAG); }
    //
    bool DualCollision(int x, int y)  { int index = y*tCell::width+x; return bool(tCell::matrix[index]) || bool(tCell::replace[index]); }
    bool Collision(int x, int y)      { return bool(tCell::matrix[y*tCell::width+x]); }
    bool IsColliding(int x, int y)    { return tCell::matrix[y*tCell::width+x] > tTile::MOLTEN_SLAG; }



    //
    // Matrix Functions
    //

    void Swap(int i, int r)
    {
        tCell::replace[r] = tCell::matrix[i]; tCell::replace[i] = tCell::matrix[r];
        tCell::matrix[r] = tCell::replace[r]; tCell::matrix[i] = tCell::replace[i];
    }

}
