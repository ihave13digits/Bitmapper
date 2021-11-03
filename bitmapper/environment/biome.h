namespace biome
{
    enum BIOMES
    {
        OCEAN,
        PLAINS,
        FOREST,
        SAVANNAH,
        DESERT,
    };

    void GenerateBiomeData()
    {
        uint8_t height[6] = { 98, 95, 90, 50, 25, 10 };

        uint8_t underworld[4] = { tTile::MANTLE, tTile::MAGMA, tTile::VOLCANIC_ROCK, tTile::STONE };

        uint8_t dynamic[2][5] = {
        //    Ocean                 Plains                Forest                Savannah              Desert
            { tTile::BRINE,         tTile::WATER,         tTile::MUD,           tTile::WATER,         tTile::QUICKSAND,     },
            { tTile::BRINE,         tTile::SILT,          tTile::MUCK,          tTile::GRAVEL,        tTile::QUICKSAND,     },
        };

        uint8_t layers[2][5] = {
        //    Ocean                 Plains                Forest                Savannah              Desert
            { tTile::SANDSTONE,     tTile::MARBLE,        tTile::LIMESTONE,     tTile::GRANITE,       tTile::SANDSTONE,     },
            { tTile::SAND,          tTile::DIRT,          tTile::SOIL,          tTile::DIRT,          tTile::SAND,          },
        };

        uint8_t ores[4][5] = {
        //    Ocean                 Plains                Forest                Savannah              Desert
            { tTile::OIL,           tTile::IRON_ORE,      tTile::IRON_ORE,      tTile::IRON_ORE,      tTile::OIL,           },
            { tTile::OIL,           tTile::COBALT_ORE,    tTile::TIN_ORE,       tTile::NICKEL_ORE,    tTile::IRON_ORE,      },
            { tTile::OIL,           tTile::TITANIUM_ORE,  tTile::TUNGSTEN_ORE,  tTile::COPPER_ORE,    tTile::COPPER_ORE,    },
            { tTile::OIL,           tTile::LEAD_ORE,      tTile::PLATINUM_ORE,  tTile::SILVER_ORE,    tTile::GOLD_ORE,      },
        };

        uint8_t gems[5][5] = {
        //    Ocean                 Plains                Forest                Savannah              Desert
            { tTile::AMBER,         tTile::AMBER,         tTile::SAPPHIRE,      tTile::AMBER,         tTile::LAPIS,         },
            { tTile::LAPIS,         tTile::LAPIS,         tTile::EMERALD,       tTile::LAPIS,         tTile::AMBER,         },
            { tTile::SAPPHIRE,      tTile::EMERALD,       tTile::EMERALD,       tTile::EMERALD,       tTile::TOPAZ,         },
            { tTile::RUBY,          tTile::DIAMOND,       tTile::RUBY,          tTile::DIAMOND,       tTile::RUBY,          },
            { tTile::DIAMOND,       tTile::SAPPHIRE,      tTile::TOPAZ,         tTile::SAPPHIRE,      tTile::DIAMOND,       },
        };

        uint8_t plants[2][5] = {
        //    Ocean                 Plains                Forest                Savannah              Desert
            { tTile::SEAWEED,       tTile::GRASS,         tTile::GRASS,         tTile::GRASS,         tTile::AIR,           },
            { tTile::SEAWEED,       tTile::GRASS,         tTile::ACORN,         tTile::GRASS,         tTile::PRICKLY_PEAR,  },
        };

        uint8_t critters[4][5] = {
        //    Ocean                 Plains                Forest                Savannah              Desert
            { tTile::FISH,          tTile::FROG,          tTile::FROG,          tTile::TOAD,          tTile::TOAD,          },
            { tTile::FISH,          tTile::MOLE,          tTile::BIRD,          tTile::SNAKE,         tTile::TOAD,          },
            { tTile::FISH,          tTile::TOAD,          tTile::BIRD,          tTile::SNAKE,         tTile::SNAKE,         },
            { tTile::FISH,          tTile::MOUSE,         tTile::MOUSE,         tTile::MOUSE,         tTile::MOUSE,         },
        };
    }
}
