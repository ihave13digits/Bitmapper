namespace tTile
{

    enum TYPES
    {
        GAS,
        PLASMA,
        FUME,
        FLUID,
        GRAIN,
        GEL,
        SOLID,
        LOOSE,
        LOGIC,
        GIZMO,
        PLATFORM,
        PLUMBING,
        PLANT,
        CRITTER,
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
        // Fume
        FOG,
        // Fluid
        MILK,
        SLAG,
        OIL,
        WATER,
        BRINE,
        BLOOD,
        HONEY,
        LAVA,
        MUCK,
        MUD,
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
        // Loose
        LOOSE_DIRT,
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
        SANDSTONE,
        WOOD,
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
        MANTLE,
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
        WIRE_I,
        WIRE_O,
        GOLD_WIRE,
        GOLD_WIRE_I,
        GOLD_WIRE_O,
        OR_GATE_I,
        OR_GATE_O,
        XOR_GATE_I,
        XOR_GATE_O,
        XNOR_GATE_I,
        XNOR_GATE_O,
        NOT_GATE_I,
        NOT_GATE_O,
        AND_GATE_I,
        AND_GATE_O,
        NAND_GATE_I,
        NAND_GATE_O,
        // Plant
        ROOT,
        TAPROOT,
        TRUNK,
        BRANCH,
        STICK,
        LEAVES,
        GRASS,
        MOSS,
        SPIDERWORT,
        // Critter
        FROG,
        TOAD,
        MOUSE,
        MOLE,
        RAT,
        HEDGEHOG,
        SNAKE_HEAD,
        SNAKE,
        SNAKE_TAIL,
        BIRD_WING,
        BIRD,
        BAT_WING,
        BAT,
    };

    // Tile Count
    int total_tiles;

    // Color Values
    std::vector<int> R;
    std::vector<int> G;
    std::vector<int> B;
    std::vector<int> A;
    
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
                                if (string_data == "gas")      { value = GAS;      }
                                if (string_data == "plasma")   { value = PLASMA;   }
                                if (string_data == "fume")     { value = FUME;     }
                                if (string_data == "fluid")    { value = FLUID;    }
                                if (string_data == "grain")    { value = GRAIN;    }
                                if (string_data == "gel")      { value = GEL;      }
                                if (string_data == "solid")    { value = SOLID;    }
                                if (string_data == "loose")    { value = LOOSE;    }
                                if (string_data == "logic")    { value = LOGIC;    }
                                if (string_data == "gizmo")    { value = GIZMO;    }
                                if (string_data == "platform") { value = PLATFORM; }
                                if (string_data == "plumbing") { value = PLUMBING; }
                                if (string_data == "plant")    { value = PLANT;    }
                                if (string_data == "critter")  { value = CRITTER;  }
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

        /*
        for (int i = 0; i < total_tiles; i++)
        {
            std::cout <<R[i] <<", ";
            std::cout <<G[i] <<", ";
            std::cout <<B[i] <<", ";
            std::cout <<A[i] <<", ";
            std::cout <<POWER[i] <<"; ";
            std::cout <<LIGHT[i] <<"; ";
            std::cout <<TYPE[i] <<"; ";
            std::cout <<NAME[i] <<"; ";
            std::cout <<std::endl;
        }

        std::cout <<"R: " <<R.size() <<"/" <<total_tiles <<std::endl;
        std::cout <<"G: " <<G.size() <<"/" <<total_tiles <<std::endl;
        std::cout <<"B: " <<B.size() <<"/" <<total_tiles <<std::endl;
        std::cout <<"A: " <<A.size() <<"/" <<total_tiles <<std::endl;
        std::cout <<"P: " <<POWER.size() <<"/" <<total_tiles <<std::endl;
        std::cout <<"L: " <<LIGHT.size() <<"/" <<total_tiles <<std::endl;
        std::cout <<"T: " <<TYPE.size() <<"/" <<total_tiles <<std::endl;
        std::cout <<"N: " <<NAME.size() <<"/" <<total_tiles <<std::endl;
        */
    }



    //
    //
    //

}
