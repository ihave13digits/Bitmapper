namespace tTool
{

    inline int GetType(int tile_index) { return tTile::TYPE[tile_index]; }
    inline std::string GetName(int tile_index) { return tTile::NAME[tile_index]; }
    inline float GetDurability(int tile_index) { return tTile::POWER[tile_index]; }
    inline float GetDensity(int tile_index) { return tTile::DENSE[tile_index]; }




    //
    // Lighting
    //

    inline float GetLightValue(int x, int y)
    {
        int t = tCell::matrix[y*tCell::width+x];
        float value;
        if (t == tTile::FIRE ||
            t == tTile::FLAME ||
            t == tTile::FLARE ||
            t == tTile::EMBER ||
            t == tTile::MAGMA ||
            t == tTile::LAVA ||
            t == tTile::SPARK ||
            t == tTile::ARC ||
            t == tTile::URANIUM ||
            t == tTile::RADON)
        { value = tTile::LIGHT[t]+(((rand()%100) * tTile::GLOW[t]) * 0.001); }
        else { value = tTile::LIGHT[t]; }
        return value;
    }

    inline float Neighbors(int x, int y)
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



    inline bool IsPowered(int i) { return bool(tCell::matrix[i] == tTile::WIRE_I || tCell::matrix[i] == tTile::GOLD_WIRE_I);}

    //
    // Collisions
    //

    //
    inline bool GasCollision(int x, int y)   { int index = y*tCell::width+x; return (tCell::matrix[index] > tTile::AIR         || tCell::replace[index] > tTile::AIR)        ; }
    inline bool FumeCollision(int x, int y)  { int index = y*tCell::width+x; return (tCell::matrix[index] > tTile::SPARK       || tCell::replace[index] > tTile::SPARK)      ; }
    inline bool FluidCollision(int x, int y) { int index = y*tCell::width+x; return (tCell::matrix[index] > tTile::OIL_FUMES   || tCell::replace[index] > tTile::OIL_FUMES)  ; }
    inline bool GelCollision(int x, int y)   { int index = y*tCell::width+x; return (tCell::matrix[index] > tTile::BLOOD       || tCell::replace[index] > tTile::BLOOD)      ; }
    inline bool GrainCollision(int x, int y) { int index = y*tCell::width+x; return (tCell::matrix[index] > tTile::MOLTEN_SLAG || tCell::replace[index] > tTile::MOLTEN_SLAG); }
    //
    inline bool DualCollision(int x, int y)  { int index = y*tCell::width+x; return bool(tCell::matrix[index]) || bool(tCell::replace[index]); }
    inline bool BodyCollision(int x, int y)    { return (tCell::matrix[y*tCell::width+x] > tTile::MOLTEN_SLAG && tCell::matrix[y*tCell::width+x] != tTile::PLANKS); }
    inline bool FootCollision(int x, int y)    { return tCell::matrix[y*tCell::width+x] > tTile::MOLTEN_SLAG; }
    inline bool Collision(int x, int y)      { return bool(tCell::matrix[y*tCell::width+x]); }



    //
    // Matrix Functions
    //

    inline void Set(int i, uint8_t r)
    {
        tCell::matrix[i] = r; tCell::replace[i] = r;
    }

    inline void Swap(int i, int r)
    {
        tCell::replace[r] = tCell::matrix[i]; tCell::replace[i] = tCell::matrix[r];
        tCell::matrix[r] = tCell::replace[r]; tCell::matrix[i] = tCell::replace[i];
    }

    inline void SoftSwap(int i, int r)
    { tCell::replace[r] = tCell::matrix[i]; tCell::replace[i] = tCell::matrix[r]; }

}
