namespace tTile
{
    enum TYPES
    {
        GAS,
        PLASMA,
        FUME,
        FLUID,
        GRAIN,
        GEM,
        GEL,
        GEO,
        ORE,
        METAL,
        SOLID,
        LOOSE,
        BOOM,
        LOGIC,
        GIZMO,
        PLATFORM,
        PLUMBING,
        PLANT,
        PLANT_PRODUCT,
        CRITTER,
        EGG,
        WALL,
    };
    enum TILES
    {
        // Gas
        AIR,
        STEAM,
        THIN_SMOKE,
        SMOKE,
        THICK_SMOKE,
        // Plasma
        FLARE,
        FLAME,
        FIRE,
        ARC,
        SPARK,
        // Fume
        FOG,
        OIL_FUMES,
        // Fluid
        MILK,
        MERCURY,
        OIL,
        ACID,
        WATER,
        BRINE,
        WINE,
        BLOOD,
        // Gel
        GUTS,
        ALGAE,
        HONEY,
        MAGMA,
        LAVA,
        MUD,
        MUCK,
        SLAG,
        // Grain
        BROKEN_GLASS,
        ASH,
        EMBER,
        SAND,
        SNOW,
        SLEET,
        SALT,
        SILT,
        GRAVEL,
        ACORN,
        CHARCOAL,
        // Gem
        JADE,
        RUBY,
        AMBER,
        LAPIS,
        TOPAZ,
        DIAMOND,
        EMERALD,
        AMETHYST,
        SAPPHIRE,
        GLASS,
        // Loose
        LOOSE_DIRT,
        // Plant Product
        WOOD,
        // Solid
        CHARRED_WOOD,
        ICE,
        DIRT,
        SOIL,
        CLAY,
        BONE,
        FOSSIL,
        SLATE,
        ASBESTOS,
        OBSIDIAN,
        STONE,
        GRANITE,
        LIMESTONE,
        MARBLE,
        SANDSTONE,
        // Ore
        PLATINUM_ORE,
        GOLD_ORE,
        SILVER_ORE,
        COPPER_ORE,
        LEAD_ORE,
        TIN_ORE,
        IRON_ORE,
        COBALT_ORE,
        NICKEL_ORE,
        TITANIUM_ORE,
        TUNGSTEN_ORE,
        // Metal
        PLATINUM,
        GOLD,
        SILVER,
        COPPER,
        LEAD,
        TIN,
        IRON,
        COBALT,
        NICKEL,
        TITANIUM,
        TUNGSTEN,
        // Geological
        VOLCANIC_ROCK,
        CALDERA,
        MANTLE,
        // Explosive
        BOMB,
        DYNAMITE,
        // Platform
        PLANKS,
        // Plumbing
        VALVE_CLOSED,
        VALVE_OPEN,
        PUMP,
        PIPE,
        PIPE_WATER,
        PIPE_BRINE,
        PIPE_HONEY,
        PIPE_BLOOD,
        PIPE_LAVA,
        PIPE_MUCK,
        PIPE_MUD,
        DRAIN,
        GUTTER,
        GUTTER_WATER,
        GUTTER_BRINE,
        GUTTER_HONEY,
        GUTTER_BLOOD,
        GUTTER_LAVA,
        GUTTER_MUCK,
        GUTTER_MUD,
        // Gizmo
        AXLE_LEFT,
        AXLE_RIGHT,
        CONVEYOR_LEFT,
        CONVEYOR_RIGHT,
        PISTON_UP,
        PISTON_DOWN,
        PISTON_LEFT,
        PISTON_RIGHT,
        // Logic
        WIRE,
        WIRE_,
        WIRE_I,
        WIRE_O,
        GOLD_WIRE,
        GOLD_WIRE_,
        GOLD_WIRE_I,
        GOLD_WIRE_O,
        SENSOR,
        OR_GATE,
        XOR_GATE,
        XNOR_GATE,
        NOT_GATE,
        AND_GATE,
        NAND_GATE,
        // Plant
        ROOT,
        TAPROOT,
        TRUNK,
        BRANCH,
        STICK,
        LEAVES,
        OLD_LEAVES,
        DRY_LEAVES,
        DEAD_LEAVES,
        GRASS,
        MOSS,
        SPIDERWORT,
        // Critter
        FROG,
        FROG_LEGS,
        TOAD,
        TOAD_LEGS,
        MOLE,
        HEDGEHOG,
        MOUSE,
        RAT,
        SNAKE_HEAD,
        SNAKE,
        SNAKE_TAIL,
        BIRD_WING,
        BIRD,
        BAT_WING,
        BAT,
        // Egg
        FROG_EGG,
        TOAD_EGG,
        SNAKE_EGG,
        BIRD_EGG,
        // Wall
        ICE_WALL,
        DIRT_WALL,
        SOIL_WALL,
        CLAY_WALL,
        BONE_WALL,
        FOSSIL_WALL,
        SLATE_WALL,
        ASBESTOS_WALL,
        OBSIDIAN_WALL,
        STONE_WALL,
        GRANITE_WALL,
        LIMESTONE_WALL,
        SANDSTONE_WALL,
        WOOD_WALL,
    };
    // Tile Count
    int total_tiles;
    // Color Values
    std::vector<uint8_t> R;
    std::vector<uint8_t> G;
    std::vector<uint8_t> B;
    std::vector<uint8_t> A;
    // Durability Values
    std::vector<float> POWER;
    // Light Values
    std::vector<float> LIGHT;
    // Type Values
    std::vector<int> TYPE;
    // Name Values
    std::vector<std::string> NAME;



    //
    //
    //
 
    void LoadTileData(std::string data_dir="tile.data")
    {
        int tile_count = 0;
        int state = 0;
        std::string line;
        std::fstream data_file;
        std::string _dir = os::GetCWD() + "/bitmapper/environment/tile/" + data_dir;
        data_file.open(_dir);
        if (data_file.is_open())
        {
            while (getline(data_file, line))
            {
                std::string string_data = "";
                for (int i = 0; i < line.length(); i++)
                {
                    std::string c = line.substr(i, 1);

                    if ( textTool::IsLetter(c) || textTool::IsNumber(c) ) { string_data = string_data + c; }
                    if (c == "_") { string_data = string_data + " "; }

                    if (c=="," || c=="\n")
                    {
                        switch (state)
                        {
                            case 1 : {             int value = std::stoi(string_data);     R.push_back(value); } break;
                            case 2 : {             int value = std::stoi(string_data);     G.push_back(value); } break;
                            case 3 : {             int value = std::stoi(string_data);     B.push_back(value); } break;
                            case 4 : {             int value = std::stoi(string_data);     A.push_back(value); } break;
                            case 5 : {           float value = std::stof(string_data); LIGHT.push_back(value); } break;
                            case 6 : {           float value = std::stof(string_data); POWER.push_back(value); } break;
                            case 7 :
                            {
                                int value;
                                if (string_data == "gas")          { value = GAS;           }
                                if (string_data == "plasma")       { value = PLASMA;        }
                                if (string_data == "fume")         { value = FUME;          }
                                if (string_data == "fluid")        { value = FLUID;         }
                                if (string_data == "grain")        { value = GRAIN;         }
                                if (string_data == "gem")          { value = GEM;           }
                                if (string_data == "gel")          { value = GEL;           }
                                if (string_data == "geo")          { value = GEO;           }
                                if (string_data == "ore")          { value = ORE;           }
                                if (string_data == "metal")        { value = METAL;         }
                                if (string_data == "solid")        { value = SOLID;         }
                                if (string_data == "loose")        { value = LOOSE;         }
                                if (string_data == "boom")         { value = BOOM;          }
                                if (string_data == "logic")        { value = LOGIC;         }
                                if (string_data == "gizmo")        { value = GIZMO;         }
                                if (string_data == "platform")     { value = PLATFORM;      }
                                if (string_data == "plumbing")     { value = PLUMBING;      }
                                if (string_data == "plant")        { value = PLANT;         }
                                if (string_data == "plantproduct") { value = PLANT_PRODUCT; }
                                if (string_data == "critter")      { value = CRITTER;       }
                                if (string_data == "wall")         { value = WALL;          }
                                if (string_data == "egg")          { value = EGG;           }
                                TYPE.push_back(value);
                            }
                            break;
                            case 8 : { NAME.push_back(string_data); } break;
                            case 9 : { state = 0; tile_count++;     } break;
                        }
                        string_data = "";
                        state++;
                    }
                }
            }
            data_file.close();
        }
        total_tiles = NAME.size();
    }



    //
    //
    //

}
