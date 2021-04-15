class World
{
public:

    // Class Attributes //

    // World Dimensions

    int width;
    int height;

    // Terrain Tiles

    int total_tiles = 45;

    int generation_step = 1;
    int generation_steps = 12;

    enum TYPES
    {
        SOLID,
        FLUID,
        GRAIN,
        GAS,
    };

    enum TILES
    {
        //
        AIR,
        STEAM,
        SMOKE,
        //
        WATER,
        BLOOD,
        LAVA,
        //
        ICE,
        MUD,
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
        GLASS,
        //
        SAND,
        SNOW,
        GRAVEL,
        //
        WOOD,
        GRASS,
        MOSS,
        //
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
        //
        RUBY,
        TOPAZ,
        DIAMOND,
        EMERALD,
        AMETHYST,
        SAPPHIRE,
        //
        MANTLE
    };

    std::string tiles[45] = {
        //
        "Air",
        "Steam",
        "Smoke",
        //
        "Water",
        "Blood",
        "Lava",
        //
        "Ice",
        "Mud",
        "Dirt",
        "Soil",
        "Clay",
        "Bone",
        "Fossil",
        "Slate",
        "Asbestos",
        "Obsidian",
        "Stone",
        "Granite",
        "Limestone",
        "Sandstone",
        "Glass",
        //
        "Sand",
        "Snow",
        "Gravel",
        //
        "Wood",
        "Grass",
        "Moss",
        //
        "Platinum",
        "Gold",
        "Silver",
        "Copper",
        "Lead",
        "Tin",
        "Iron",
        "Cobalt",
        "Nickel",
        "Titanium",
        "Tungsten",
        //
        "Ruby",
        "Topaz",
        "Diamond",
        "Emerald",
        "Amethyst",
        "Sapphire",
        //
        "Mantle"
    };

    int tileset[45][2][4] = {
        // |Base Color        |     |Variation       |
        // Gases
        {  {200, 200, 230, 5  },    {1,   1,   25,  0}  },// Air
        {  {220, 220, 230, 25 },    {5,   5,   25,  0}  },// Steam
        {  {128, 128, 128, 50 },    {5,   5,   5,   0}  },// Smoke
        // Fluids
        {  {0,   0,   128, 128},    {1,   1,   25,  0}  },// Water
        {  {128, 0,   0,   255},    {25,  1,   1,   0}  },// Blood
        {  {255, 225, 0,   255},    {1,  -55,  1,   0}  },// Lava
        // Solid Materials
        {  {180, 180, 200, 128},    {1,   1,   55,  0}  },// Ice
        {  {40,  32,  16,  255},    {8,   4,   2,   0}  },// Mud
        {  {80,  64,  32,  255},    {8,   4,   2,   0}  },// Dirt
        {  {32,  24,  16,  255},    {8,   4,   2,   0}  },// Soil
        {  {160, 80,  20,  255},    {8,   4,   1,   0}  },// Clay
        {  {240, 240, 200, 255},    {15,  15,  1,   0}  },// Bone
        {  {20,  15,  10,  255},    {10,  5,   1,   0}  },// Fossil
        {  {120, 100, 80,  255},    {25,  20,  10,  0}  },// Slate
        {  {64,  132, 148, 255},    {1,   15,  25,  0}  },// Asbestos
        {  {32,  16,  8,   255},    {15,  1,   1,   0}  },// Obsidian
        {  {64,  64,  64,  255},    {5,   5,   10,  0}  },// Stone
        {  {80,  80,  80,  255},    {5,   15,  25,  0}  },// Granite
        {  {128, 128, 128, 255},    {5,   5,   10,  0}  },// Limestone
        {  {200, 200, 100, 255},    {5,   5,   10,  0}  },// Sandstone
        {  {220, 220, 245,  64},    {5,   15,  10,  0}  },// Glass
        // Granular Materials
        {  {230, 230, 128, 255},    {15,  15,  5,   0}  },// Sand
        {  {230, 230, 230, 255},    {1,   1,   25,  0}  },// Snow
        {  {130, 125, 120, 255},    {10,  10,  10,  0}  },// Gravel
        // Plant Materials
        {  {80,  64,  32,  255},    {25,  20,  10,  0}  },// Wood
        {  {0,   128, 0,   255},    {5,   20,  1,   0}  },// Grass
        {  {20,   80, 0,   255},    {5,   20,  1,   0}  },// Moss
        // Metals
        {  {190, 190, 230, 255},    {10,  10,  25,  0}  },// Platinum
        {  {245, 230, 0,   255},    {10,  5,   1,   0}  },// Gold
        {  {180, 180, 220, 255},    {10,  10,  15,  0}  },// Silver
        {  {128, 60,  0,   255},    {10,  5,   1,   0}  },// Copper
        {  {16,  32,  48,  255},    {2,   4,   8,   0}  },// Lead
        {  {180, 200, 100, 255},    {15,  15,  10,  0}  },// Tin
        {  {140, 100, 100, 255},    {15,  10,  10,  0}  },// Iron
        {  {80,  100, 140, 255},    {4,   8,   10,  0}  },// Cobalt
        {  {100, 100, 100, 255},    {4,   8,   10,  0}  },// Nickel
        {  {100, 110, 120, 255},    {6,   8,   12,  0}  },// Titanium
        {  {50,  55,  60,  255},    {6,   8,   12,  0}  },// Tungsten
        // Gemstones
        {  {230, 0,   0,   200},    {25,  1,   1,   0}  },// Ruby
        {  {230, 230, 0,   200},    {25,  25,  1,   0}  },// Topaz
        {  {250, 250, 250, 200},    {5,   5,   5,   0}  },// Diamond
        {  {0,   230, 0,   200},    {1,   25,  1,   0}  },// Emerald
        {  {230, 0,   230, 200},    {25,  1,   25,  0}  },// Amethyst
        {  {0,   0,   230, 200},    {1,   1,   25,  0}  },// Sapphire
        // Unbreakable
        {  {25,  20,  20,  255},    {25,  1,   1,   0}  },// Mantle
    };

    std::vector<short> matrix;
    std::vector<short> replace;



    // Generation Method
    void GenerateWorld(int w, int h, int seed)
    {
        srand(seed);

        width = w;
        height = h;

        if (generation_step == 1)
        {
            for (int x = 0; x < width; x++)
            {
                for (int y = 0; y < height; y++)
                {
                    matrix.push_back(AIR);
                    replace.push_back(AIR);
                }
            }
        }

        int H = int(height/100);

        if (generation_step == 2)
        {
            AddLayer(STONE, 2,  H*25,  H*90);
            AddLayer(LAVA, 100,  H*95,  height);
        }
        if (generation_step == 3)
        {
            for (int i = 0; i < 8; i++) Expand(STONE, H*10, H*90, 10, 1, 25, 25);
            for (int i = 0; i < 8; i++) Expand(STONE, H*25, H*90, 10, 1, 25, 25);
            for (int i = 0; i < 8; i++) Expand(STONE, H*50, H*90, 10, 1, 50, 50);
            for (int i = 0; i < 8; i++) Expand(STONE, H*75, H*90, 10, 1, 75, 75);
        }

        if (generation_step == 4)
        {
            for (int i = 0; i < 4; i++) Expand(SOIL, H*15, H*50, 25, 100, 75, 75);
            for (int i = 0; i < 4; i++) Expand(SOIL, H*24, H*40, 25, 50, 75, 75);
            for (int i = 0; i < 4; i++) Expand(DIRT, H*35, H*90, 25, 25, 25, 25);
            for (int i = 0; i < 4; i++) Expand(DIRT, H*70, H*90, 25, 5, 25, 25);
        }

        if (generation_step == 5)
        {
            for (int i = 0; i < 12; i++) Expand(DIRT, H*8, H*50, 25, 100, 75, 75);
            for (int i = 0; i < 12; i++) Expand(DIRT, H*16, H*40, 25, 50, 75, 75);
            for (int i = 0; i < 12; i++) Expand(MUD, H*32, H*90, 25, 25, 25, 25);
            for (int i = 0; i < 12; i++) Expand(MUD, H*64, H*90, 25, 5, 25, 25);
        }
            if (generation_step == 6)
        {
            for (int i = 0; i < 8; i++) Expand(GRAVEL, H*33, H*90, 10, 1, 50, 50);
            for (int i = 0; i < 8; i++) Expand(GRAVEL, H*66, H*90, 10, 1, 50, 50);
            for (int i = 0; i < 8; i++) Expand(GRAVEL, H*80, H*90, 10, 1, 50, 50);
        }

        if (generation_step == 7)
        {
            Expand(GRASS, 0, H*32, 100, 0, 25, 25);
        }

        if (generation_step == 8)
        {
            SeedLayer(PLATINUM, 1, H*70, H*90);
            SeedLayer(GOLD, 1, H*60, H*80);
            SeedLayer(SILVER, 1, H*50, H*75);
            SeedLayer(COPPER, 1, H*25, H*50);
            SeedLayer(LEAD, 1, H*50, H*75);
            SeedLayer(TIN, 1, H*33, H*66);
            SeedLayer(IRON, 1, H*20, H*60);
            SeedLayer(COBALT, 1, H*30, H*60);
            SeedLayer(NICKEL, 1, H*40, H*70);
            SeedLayer(TITANIUM, 1, H*50, H*70);
            SeedLayer(TUNGSTEN, 1, H*60, H*80);
        }

        if (generation_step == 9)
        {
            SeedLayer(RUBY, 1, H*40, H*50);
            SeedLayer(TOPAZ, 1, H*40, H*50);
            SeedLayer(DIAMOND, 1, H*45, H*55);
            SeedLayer(EMERALD, 1, H*45, H*55);
            SeedLayer(AMETHYST, 1, H*50, H*60);
            SeedLayer(SAPPHIRE, 1, H*50, H*60);
        }

        if (generation_step == 10)
        {
            for (int i = 0; i < 4; i++) Deposit(PLATINUM, H*80, height, 25, 25, 25, 25);
            for (int i = 0; i < 6; i++) Deposit(GOLD, H*75, H*90, 25, 25, 25, 25);
            for (int i = 0; i < 8; i++) Deposit(SILVER, H*40, H*60, 25, 25, 25, 25);
            for (int i = 0; i < 14; i++) Deposit(COPPER, H*25, H*50, 25, 25, 25, 25);
            for (int i = 0; i < 12; i++) Deposit(LEAD, H*50, H*80, 25, 25, 25, 25);
            for (int i = 0; i < 10; i++) Deposit(TIN, H*33, H*66, 25, 25, 25, 25);
            for (int i = 0; i < 16; i++) Deposit(IRON, H*20, H*60, 25, 25, 25, 25);
            for (int i = 0; i < 12; i++) Deposit(COBALT, H*30, H*60, 25, 25, 25, 25);
            for (int i = 0; i < 12; i++) Deposit(NICKEL, H*40, H*70, 25, 25, 25, 25);
            for (int i = 0; i < 10; i++) Deposit(TITANIUM, H*50, H*70, 25, 25, 25, 25);
            for (int i = 0; i < 8; i++) Deposit(TUNGSTEN, H*60, H*80, 25, 25, 25, 25);
        }
        if (generation_step == 11)
        {
            for (int i = 0; i < 2; i++) Deposit(LAVA, H*95, height, 1, 100, 100, 100);
        }
        if (generation_step == 12)
        {
            SeedLayer(MANTLE, 100, H*92, height);
            for (int i = 0; i < 8; i++) Deposit(MANTLE, H*85, height, 1, 5, 75, 75);
            for (int i = 0; i < 8; i++) Deposit(MANTLE, H*90, height, 5, 15, 50, 50);
            for (int i = 0; i < 8; i++) Deposit(MANTLE, H*95, height, 10, 25, 25, 25);
            for (int i = 0; i < 8; i++) Deposit(MANTLE, H*97, height, 10, 50, 50, 50);
            for (int i = 0; i < 8; i++) Deposit(MANTLE, H*99, height, 10, 75, 100, 100);
        }
        generation_step++;
    }

    // Seed Methods
    void AddLayer(int t, int density, int ymin, int ymax)
    {
        for (int y = ymin; y < ymax; y++)
        {
            for (int x = 0; x < width; x++)
            {
                if (rand()%1000 < density) matrix[y*width+x] = t;
            }
        }
    }

    void SeedLayer(int t, int density, int ymin, int ymax)
    {
        for (int y = ymin; y < ymax; y++)
        {
            for (int x = 0; x < width; x++)
            {
                int index = y*width+x;
                if (matrix[index] != AIR && rand()%10000 < density) matrix[index] = t;
            }
        }
    }

    // Deposition Methods
    void Expand(int t, int miny, int maxy, int dn=5, int ds=5, int de=25, int dw=25)
    {
        replace = matrix;

        for (int y = miny; y < maxy; y++)
        {
            for (int x = 0; x < width; x++)
            {
                if (matrix[y*width+x] != AIR &&
                        ( (x > 0) && (x < width-1) ) &&
                        ( (y > 0) && (y < height-1) ))
                {
                    int n = (y-1)*width+x;
                    int s = (y+1)*width+x;
                    int e = y*width+(x+1);
                    int w = y*width+(x-1);

                    if (matrix[n] == AIR && rand()%100 < dn) replace[n] = t;
                    if (matrix[s] == AIR && rand()%100 < ds) replace[s] = t;
                    if (matrix[e] == AIR && rand()%100 < de) replace[e] = t;
                    if (matrix[w] == AIR && rand()%100 < dw) replace[w] = t;
                }
            }
        }
        matrix = replace;
    }

    void Spread(int t, int dn=5, int ds=5, int de=25, int dw=25)
    {
        replace = matrix;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                if (matrix[y*width+x] == t &&
                        ( (x > 0) && (x < width-1) ) &&
                        ( (y > 0) && (y < height-1) )
                        )
                {
                    int n = (y-1)*width+x;
                    int s = (y+1)*width+x;
                    int e = y*width+(x+1);
                    int w = y*width+(x-1);

                    if (rand()%100 < dn) replace[n] = t;
                    if (rand()%100 < ds) replace[s] = t;
                    if (rand()%100 < de) replace[e] = t;
                    if (rand()%100 < dw) replace[w] = t;
                }
            }
        }
        matrix = replace;
    }

    void Deposit(int t, int miny, int maxy, int dn=5, int ds=5, int de=25, int dw=25)
    {
        replace = matrix;

        for (int y = miny; y < maxy; y++)
        {
            for (int x = 0; x < width; x++)
            {
                if (matrix[y*width+x] == t &&
                        ( (x > 0) && (x < width-1) ) &&
                        ( (y > 0) && (y < height-1) )
                        )
                {
                    int n = (y-1)*width+x;
                    int s = (y+1)*width+x;
                    int e = y*width+(x+1);
                    int w = y*width+(x-1);

                    if (rand()%100 < dn) replace[n] = t;
                    if (rand()%100 < ds) replace[s] = t;
                    if (rand()%100 < de) replace[e] = t;
                    if (rand()%100 < dw) replace[w] = t;
                }
            }
        }
        matrix = replace;
    }

    // Update Method
    void SettleTiles(int X, int Y, int W, int H)
    {
        replace = matrix;

        for (int y = H; y > 0; y--)
        {
            for (int x = 0; x < W; x++)
            {
                // Spread Grass
                int index = (y+Y)*width+(x+X);
                if (matrix[index] == GRASS)
                {
                    if (rand()%100 < 5)
                    {
                        int dNE = int( (y+Y-1)*width+(x+X+1) );
                        int dNW = int( (y+Y-1)*width+(x+X-1) );
                        int dE = int( (y+Y)*width+(x+X+1) );
                        int dW = int( (y+Y)*width+(x+X-1) );
                        int dSE = int( (y+Y+1)*width+(x+X+1) );
                        int dSW = int( (y+Y+1)*width+(x+X-1) );
                        
                        if ((matrix[dE] == DIRT || matrix[dE] == SOIL)&& !Collision(x+X+1, y+Y-1)) replace[dE] = GRASS;
                        else if ((matrix[dW] == DIRT || matrix[dW] == SOIL) && !Collision(x+X-1, y+Y-1)) replace[dW] = GRASS;

                        else if ((matrix[dNE] == DIRT || matrix[dNE] == SOIL) && !Collision(x+X+1, y+Y-2)) replace[dNE] = GRASS;
                        else if ((matrix[dNW] == DIRT || matrix[dNE] == SOIL) && !Collision(x+X-1, y+Y-2)) replace[dNW] = GRASS;
                        
                        else if ((matrix[dSE] == DIRT || matrix[dSE] == SOIL) && !Collision(x+X+1, y+Y)) replace[dSE] = GRASS;
                        else if ((matrix[dSW] == DIRT || matrix[dSE] == SOIL) && !Collision(x+X-1, y+Y)) replace[dSW] = GRASS;
                    }
                }

                if (matrix[index] == MOSS)
                {
                    if (rand()%1000 < 5)
                    {
                        int dNE = int( (y+Y-1)*width+(x+X+1) );
                        int dNW = int( (y+Y-1)*width+(x+X-1) );
                        int dE = int( (y+Y)*width+(x+X+1) );
                        int dW = int( (y+Y)*width+(x+X-1) );
                        int dSE = int( (y+Y+1)*width+(x+X+1) );
                        int dSW = int( (y+Y+1)*width+(x+X-1) );

                        if ((matrix[dE] == STONE) && !Collision(x+X+1, y+Y-1)) replace[dE] = MOSS;
                        else if ((matrix[dW] == STONE) && !Collision(x+X-1, y+Y-1)) replace[dW] = MOSS;

                        else if ((matrix[dNE] == STONE) && !Collision(x+X+1, y+Y-2)) replace[dNE] = MOSS;
                        else if ((matrix[dNW] == STONE) && !Collision(x+X-1, y+Y-2)) replace[dNW] = MOSS;

                        else if ((matrix[dSE] == STONE) && !Collision(x+X+1, y+Y)) replace[dSE] = MOSS;
                        else if ((matrix[dSW] == STONE) && !Collision(x+X-1, y+Y)) replace[dSW] = MOSS;
                    }
                }

                // Update Moving Tiles
                int cell_type = SOLID;
                if ( (y+Y > 0 && y+Y < height-1) && Collision(x+X, y+Y) )
                {
                    switch (matrix[index])
                    {
                        case LAVA : cell_type = FLUID; break;
                        case BLOOD : cell_type = FLUID; break;
                        case WATER : cell_type = FLUID; break;
                        
                        case SAND : cell_type = GRAIN; break;
                        case SNOW : cell_type = GRAIN; break;
                        case GRAVEL : cell_type = GRAIN; break;
                        
                        case STEAM : cell_type = GAS; break;
                        case SMOKE : cell_type = GAS; break;
                    }

                    switch (cell_type)
                    {
                        case FLUID :
                        {
                            if (!FluidCollision(x+X, y+Y+1))
                            {
                                int rplc = (y+Y+1)*width+(x+X);   // ░░░░░░
                                replace[rplc] = matrix[index];    // ░░▓▓░░
                                replace[index] = AIR;             // ░░██░░
                            }
                            else if (!FluidCollision(x+X-1, y+Y+1))
                            {
                                int rplc = (y+Y+1)*width+(x+X-1); // ░░░░░░
                                replace[rplc] = matrix[index];    // ░░▓▓░░
                                replace[index] = AIR;             // ██░░░░
                            }
                            else if (!FluidCollision(x+X+1, y+Y+1))
                            {
                                int rplc = (y+Y+1)*width+(x+X+1); // ░░░░░░
                                replace[rplc] = matrix[index];    // ░░▓▓░░
                                replace[index] = AIR;             // ░░░░██
                            }
                            else if (!FluidCollision(x+X-1, y+Y) && FluidCollision(x+X+1, y+Y))
                            {
                                int rplc = (y+Y)*width+(x+X-1);   // ░░░░░░
                                replace[rplc] = matrix[index];    // ██▓▓░░
                                replace[index] = AIR;             // ░░░░░░
                            }
                            else if (!FluidCollision(x+X+1, y+Y) && FluidCollision(x+X-1, y+Y))
                            {
                                int rplc = (y+Y)*width+(x+X+1);   // ░░░░░░
                                replace[rplc] = matrix[index];    // ░░▓▓██
                                replace[index] = AIR;             // ░░░░░░
                            }
                        };
                        break;
                    case GRAIN :
                        {
                            if (!DualCollision(x+X, y+Y+1))
                            {
                                int rplc = (y+Y+1)*width+(x+X);   // ░░░░░░
                                replace[rplc] = matrix[index];    // ░░▓▓░░
                                replace[index] = AIR;             // ░░██░░
                            }
                            else if (!DualCollision(x+X-1, y+Y+1))
                            {
                                int rplc = (y+Y+1)*width+(x+X-1); // ░░░░░░
                                replace[rplc] = matrix[index];    // ░░▓▓░░
                                replace[index] = AIR;             // ██░░░░
                            }
                            else if (!DualCollision(x+X+1, y+Y+1))
                            {
                                int rplc = (y+Y+1)*width+(x+X+1); // ░░░░░░
                                replace[rplc] = matrix[index];    // ░░▓▓░░
                                replace[index] = AIR;             // ░░░░██
                            }
                        };
                        break;
                    case GAS :
                        {
                            if (!DualCollision(x+X, y+Y-1))
                            {
                                int rplc = (y+Y-1)*width+(x+X);   // ░░██░░
                                replace[rplc] = matrix[index];    // ░░▓▓░░
                                replace[index] = AIR;             // ░░░░░░
                            }
                            else if (!DualCollision(x+X-1, y+Y-1))
                            {
                                int rplc = (y+Y-1)*width+(x+X-1); // ██░░░░
                                replace[rplc] = matrix[index];    // ░░▓▓░░
                                replace[index] = AIR;             // ░░░░░░
                            }
                            else if (!DualCollision(x+X+1, y+Y-1))
                            {
                                int rplc = (y+Y-1)*width+(x+X+1); // ░░░░██
                                replace[rplc] = matrix[index];    // ░░▓▓░░
                                replace[index] = AIR;             // ░░░░░░
                            }
                            else if (!DualCollision(x+X-1, y+Y))
                            {
                                int rplc = (y+Y)*width+(x+X-1);   // ░░░░░░
                                replace[rplc] = matrix[index];    // ██▓▓░░
                                replace[index] = AIR;             // ░░░░░░
                            }
                            else if (!DualCollision(x+X+1, y+Y))
                            {
                                int rplc = (y+Y)*width+(x+X+1);   // ░░░░░░
                                replace[rplc] = matrix[index];    // ░░▓▓██
                                replace[index] = AIR;             // ░░░░░░
                            }
                        };
                        break;
                    }
                }
            }
        }
        matrix = replace;
    }

    // Return Methods
    int Neighbors(int x, int y)
    {
        int value = 0;
        value += bool(matrix[(y-2)*width+(x)]);
        value += bool(matrix[(y-1)*width+(x)]);
        value += bool(matrix[(y)*width+(x-1)]);
        value += bool(matrix[(y)*width+(x+1)]);

        return value;
    }

    bool FluidCollision(int x, int y)
    {
        return bool(replace[y*width+x]);
    }

    bool DualCollision(int x, int y)
    {
        return bool(matrix[y*width+x]) || bool(replace[y*width+x]);
    }

    bool Collision(int x, int y)
    {
        return bool(matrix[y*width+x]);
    }

};
