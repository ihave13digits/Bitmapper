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
        using namespace tTile;
        uint8_t height[6] = { 98, 95, 90, 50, 25, 10 };

        uint8_t underworld[4] = { MANTLE, MAGMA, VOLCANIC_ROCK, STONE };

        uint8_t dynamic[2][5] = {
        //    Ocean          Plains         Forest         Savannah       Desert
            { BRINE,         WATER,         MUD,           WATER,         QUICKSAND,     },
            { BRINE,         SILT,          MUCK,          GRAVEL,        QUICKSAND,     },
        };

        uint8_t layers[2][5] = {
        //    Ocean          Plains         Forest         Savannah       Desert
            { SANDSTONE,     MARBLE,        LIMESTONE,     GRANITE,       SANDSTONE,     },
            { SAND,          DIRT,          SOIL,          DIRT,          SAND,          },
        };

        uint8_t ores[4][5] = {
        //    Ocean          Plains         Forest         Savannah       Desert
            { OIL,           IRON_ORE,      IRON_ORE,      IRON_ORE,      OIL,           },
            { OIL,           COBALT_ORE,    TIN_ORE,       NICKEL_ORE,    IRON_ORE,      },
            { OIL,           TITANIUM_ORE,  TUNGSTEN_ORE,  COPPER_ORE,    COPPER_ORE,    },
            { OIL,           LEAD_ORE,      PLATINUM_ORE,  SILVER_ORE,    GOLD_ORE,      },
        };

        uint8_t gems[5][5] = {
        //    Ocean          Plains         Forest         Savannah       Desert
            { AMBER,         AMBER,         SAPPHIRE,      AMBER,         LAPIS,         },
            { LAPIS,         LAPIS,         EMERALD,       LAPIS,         AMBER,         },
            { SAPPHIRE,      EMERALD,       EMERALD,       EMERALD,       TOPAZ,         },
            { RUBY,          DIAMOND,       RUBY,          DIAMOND,       RUBY,          },
            { DIAMOND,       SAPPHIRE,      TOPAZ,         SAPPHIRE,      DIAMOND,       },
        };

        uint8_t plants[2][5] = {
        //    Ocean          Plains         Forest         Savannah       Desert
            { SEAWEED,       GRASS,         GRASS,         GRASS,         AIR,           },
            { SEAWEED,       GRASS,         ACORN,         GRASS,         PRICKLY_PEAR,  },
        };

        uint8_t critters[4][5] = {
        //    Ocean          Plains         Forest         Savannah       Desert
            { FISH,          FROG,          FROG,          TOAD,          TOAD,          },
            { FISH,          MOLE,          BIRD,          SNAKE,         TOAD,          },
            { FISH,          TOAD,          BIRD,          SNAKE,         SNAKE,         },
            { FISH,          MOUSE,         MOUSE,         MOUSE,         MOUSE,         },
        };
    }
}
