namespace biome
{
    enum BIOMES
    {
        PLAINS,
        FOREST,
        DESERT,
    };

    std::vector<uint8_t> rock = {
        tTile::STONE,
    };

    std::vector<uint8_t> soil = {
        tTile::DIRT,
    };

    std::vector<uint8_t> plant = {
        tTile::GRASS,
    };

    std::vector<uint8_t> critter = {
        tTile::FROG,
    };
}
