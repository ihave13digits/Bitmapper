class World
{
public:

    // Class Attributes //

    // World Dimensions
    int chunk_size = 32;

    // Terrain Tiles
    int total_parameters = 12;
    int total_modes = 4;

    // Procedural Generation
    int selected_step = 0;
    int selected_param = 0;
    int generation_step = 1;
    int generation_steps = 1;
    int maximum_generation_steps = 128;

    int clipboard_param[12];
    int generation_param[128][12];

    enum MODES
    {
        mADD,
        mSEED,
        mEXPAND,
        mDEPOSIT,
    };

    std::string modes[4] = {
        "Add Layer",
        "Seed Layer",
        "Expand Material",
        "Deposit Material",
    };

    enum PARAM
    {
        pTILE,
        pMODE,
        pDENSE,
        pITER,
        pMINX,
        pMAXX,
        pMINY,
        pMAXY,
        pPROBN,
        pPROBS,
        pPROBE,
        pPROBW
    };



    // Matrix
    void ClearMatrix()
    {
        tCell::matrix.clear();
    }

    void InitializeMatrix(int w, int h)
    {
        tCell::width = w;
        tCell::height = h;
        for (int y = 0; y < tCell::height; y++)
        {
            for (int x = 0; x < tCell::width; x++)
            {
                tCell::matrix.push_back(tTile::AIR); tCell::replace.push_back(tTile::AIR);
            }
        }
        std::cout << tCell::matrix.size();
    }

    void ClearData()
    {
        for (int i = 0; i < maximum_generation_steps; i++)
        {
            for (int p = 0; p < total_parameters; p++)
            {
                generation_param[i][p] = 0;
            }
        }
    }

    void PresetData()
    {
        generation_steps = 62;
        int preset_data[62][12] = {
            { tTile::STONE,      mADD,     8,   1,  0,   100, 20,  75,  0,   0,   0,   0   },
            { tTile::STONE,      mADD,     4,   1,  0,   100, 30,  76,  0,   0,   0,   0   },
            { tTile::STONE,      mADD,     2,   1,  0,   100, 40,  77,  0,   0,   0,   0   },
            { tTile::STONE,      mADD,     1,   1,  0,   100, 50,  78,  0,   0,   0,   0   },
            { tTile::STONE,      mADD,     1,   1,  0,   100, 60,  79,  0,   0,   0,   0   },
            { tTile::MANTLE,     mADD,     8,   1,  0,   100, 95,  100, 0,   0,   0,   0   },
            { tTile::MANTLE,     mADD,     16,  1,  0,   100, 97,  100, 0,   0,   0,   0   },

            { tTile::STONE,      mEXPAND,  0,   1,  0,   100, 15,  85,  25,  50,  100, 100 },
            { tTile::STONE,      mEXPAND,  0,   1,  0,   100, 25,  85,  25,  50,  100, 100 },
            { tTile::STONE,      mEXPAND,  0,   1,  0,   100, 35,  85,  50,  25,  100, 100 },
            { tTile::STONE,      mEXPAND,  0,   2,  0,   100, 45,  85,  25,  5,   100, 100 },
            { tTile::STONE,      mEXPAND,  0,   1,  0,   100, 55,  85,  25,  50,  100, 100 },
            { tTile::STONE,      mEXPAND,  0,   4,  0,   100, 65,  85,  25,  50,  100, 100 },
            { tTile::STONE,      mEXPAND,  0,   2,  0,   100, 75,  85,  50,  25,  100, 100 },
            { tTile::STONE,      mEXPAND,  0,   1,  0,   100, 80,  85,  25,  5,   100, 100 },
            
            { tTile::SOIL,       mEXPAND,  0,   4,  0,   100, 8,   30,  50,  25,  90,  90  },
            { tTile::MUD,        mEXPAND,  0,   1,  0,   100, 10,  40,  50,  25,  75,  75  },
            { tTile::SOIL,       mEXPAND,  0,   1,  0,   100, 8,   30,  50,  25,  90,  90  },
            { tTile::MUD,        mEXPAND,  0,   2,  0,   100, 10,  40,  50,  25,  75,  75  },
            { tTile::DIRT,       mEXPAND,  0,   1,  0,   100, 10,  40,  50,  25,  90,  90  },
            { tTile::MUD,        mEXPAND,  0,   1,  0,   100, 15,  50,  25,  12,  37,  37  },
            { tTile::DIRT,       mEXPAND,  0,   2,  0,   100, 15,  60,  50,  25,  90,  90  },
            { tTile::MUD,        mEXPAND,  0,   1,  0,   100, 15,  70,  25,  12,  37,  37  },
            { tTile::DIRT,       mEXPAND,  0,   4,  0,   100, 12,  80,  50,  25,  90,  90  },
            { tTile::DIRT,       mEXPAND,  0,   4,  0,   100, 6,   20,  50,  25,  100, 100 },

            { tTile::GRAVEL,     mEXPAND,  0,   4,  0,   100, 30,  80,  50,  0,   0,   0   },
            { tTile::GRAVEL,     mEXPAND,  0,   4,  0,   100, 50,  60,  50,  0,   0,   0   },
            { tTile::GRASS,      mEXPAND,  0,   1,  0,   100, 8,   25,  100, 0,   5,   5   },
            { tTile::MANTLE,     mEXPAND,  0,   16, 0,   100, 85,  100, 10,  10,  100, 100 },
            { tTile::LAVA,       mEXPAND,  0,   16, 0,   100, 90,  100, 100, 100, 100, 100 },

            { tTile::PLATINUM,   mSEED,    2,   1,  0,   100, 50,  70,  0,   0,   0,   0   },
            { tTile::GOLD,       mSEED,    2,   1,  0,   100, 60,  80,  0,   0,   0,   0   },
            { tTile::SILVER,     mSEED,    3,   1,  0,   100, 50,  70,  0,   0,   0,   0   },
            { tTile::COPPER,     mSEED,    4,   1,  0,   100, 30,  50,  0,   0,   0,   0   },
            { tTile::LEAD,       mSEED,    3,   1,  0,   100, 70,  80,  0,   0,   0,   0   },
            { tTile::TIN,        mSEED,    3,   1,  0,   100, 50,  70,  0,   0,   0,   0   },
            { tTile::IRON,       mSEED,    4,   1,  0,   100, 25,  50,  0,   0,   0,   0   },
            { tTile::COBALT,     mSEED,    3,   1,  0,   100, 25,  40,  0,   0,   0,   0   },
            { tTile::NICKEL,     mSEED,    3,   1,  0,   100, 25,  30,  0,   0,   0,   0   },
            { tTile::TITANIUM,   mSEED,    2,   1,  0,   100, 40,  60,  0,   0,   0,   0   },
            { tTile::TUNGSTEN,   mSEED,    2,   1,  0,   100, 70,  80,  0,   0,   0,   0   },

            { tTile::PLATINUM,   mDEPOSIT, 0,   4,  0,   100, 60,  80,  25,  25,  25,  25  },
            { tTile::GOLD,       mDEPOSIT, 0,   4,  0,   100, 60,  80,  25,  25,  25,  25  },
            { tTile::SILVER,     mDEPOSIT, 0,   6,  0,   100, 50,  70,  25,  25,  25,  25  },
            { tTile::COPPER,     mDEPOSIT, 0,   8,  0,   100, 30,  50,  25,  25,  25,  25  },
            { tTile::LEAD,       mDEPOSIT, 0,   8,  0,   100, 70,  80,  25,  25,  25,  25  },
            { tTile::TIN,        mDEPOSIT, 0,   8,  0,   100, 50,  70,  25,  25,  25,  25  },
            { tTile::IRON,       mDEPOSIT, 0,   8,  0,   100, 25,  50,  25,  25,  25,  25  },
            { tTile::COBALT,     mDEPOSIT, 0,   6,  0,   100, 25,  40,  25,  25,  25,  25  },
            { tTile::NICKEL,     mDEPOSIT, 0,   6,  0,   100, 25,  30,  25,  25,  25,  25  },
            { tTile::TITANIUM,   mDEPOSIT, 0,   6,  0,   100, 40,  60,  25,  25,  25,  25  },
            { tTile::TUNGSTEN,   mDEPOSIT, 0,   4,  0,   100, 70,  80,  25,  25,  25,  25  },

            { tTile::JADE,       mSEED,    2,   1,  0,   100, 40,  60,  0,   0,   0,   0   },
            { tTile::RUBY,       mSEED,    2,   1,  0,   100, 40,  60,  0,   0,   0,   0   },
            { tTile::AMBER,      mSEED,    2,   1,  0,   100, 40,  60,  0,   0,   0,   0   },
            { tTile::LAPIS,      mSEED,    2,   1,  0,   100, 50,  70,  0,   0,   0,   0   },
            { tTile::TOPAZ,      mSEED,    2,   1,  0,   100, 50,  70,  0,   0,   0,   0   },
            { tTile::DIAMOND,    mSEED,    2,   1,  0,   100, 70,  90,  0,   0,   0,   0   },
            { tTile::EMERALD,    mSEED,    2,   1,  0,   100, 70,  90,  0,   0,   0,   0   },
            { tTile::AMETHYST,   mSEED,    2,   1,  0,   100, 60,  80,  0,   0,   0,   0   },
            { tTile::SAPPHIRE,   mSEED,    2,   1,  0,   100, 60,  80,  0,   0,   0,   0   },
        };
        
        for (int i = 0; i < generation_steps; i++)
        {
            for (int p = 0; p < total_parameters; p++)
            {
                generation_param[i][p] = preset_data[i][p];
            }
        }
    }

    void GeneratePreview()
    {
        int index = generation_step-1;
        switch (generation_param[index][pMODE])
        {
            case mADD :
                {
                    for (int i = 0; i < generation_param[index][pITER]; i++) AddLayer(
                            generation_param[index][pTILE],
                            generation_param[index][pDENSE],
                            generation_param[index][pMINX],
                            generation_param[index][pMAXX],
                            generation_param[index][pMINY],
                            generation_param[index][pMAXY]
                            );
                }
                break;
            case mSEED :
                {
                    for (int i = 0; i < generation_param[index][pITER]; i++) SeedLayer(
                            generation_param[index][pTILE],
                            generation_param[index][pDENSE],
                            generation_param[index][pMINX],
                            generation_param[index][pMAXX],
                            generation_param[index][pMINY],
                            generation_param[index][pMAXY]
                            );
                }
                break;
            case mEXPAND :
                {
                    for (int i = 0; i < generation_param[index][pITER]; i++) Expand(
                            generation_param[index][pTILE],
                            generation_param[index][pMINX],
                            generation_param[index][pMAXX],
                            generation_param[index][pMINY],
                            generation_param[index][pMAXY],
                            generation_param[index][pPROBN],
                            generation_param[index][pPROBS],
                            generation_param[index][pPROBE],
                            generation_param[index][pPROBW]
                            );
                }
                break;
            case mDEPOSIT :
                {
                    for (int i = 0; i < generation_param[index][pITER]; i++) Deposit(
                            generation_param[index][pTILE],
                            generation_param[index][pMINX],
                            generation_param[index][pMAXX],
                            generation_param[index][pMINY],
                            generation_param[index][pMAXY],
                            generation_param[index][pPROBN],
                            generation_param[index][pPROBS],
                            generation_param[index][pPROBE],
                            generation_param[index][pPROBW]
                            );
                }
                break;
        }
        generation_step++;
    }

    // Generation
    std::string GenerateWorld()
    {
        std::string message = "";
        int index = generation_step-1;

        float W = float(float(tCell::width)/100.0);
        float H = float(float(tCell::height)/100.0);

        switch (generation_param[index][pMODE])
        {
            case mADD :
                {
                    message = "Adding " + tTile::NAME[generation_param[index][pTILE]] + " Layer";
                    for (int i = 0; i < generation_param[index][pITER]; i++) AddLayer(
                            generation_param[index][pTILE],
                            generation_param[index][pDENSE],
                            std::round(float(generation_param[index][pMINX])*W),
                            std::round(float(generation_param[index][pMAXX])*W),
                            std::round(float(generation_param[index][pMINY])*H),
                            std::round(float(generation_param[index][pMAXY])*H)
                            );
                }
                break;
            case mSEED :
                {
                    message = "Seeding " + tTile::NAME[generation_param[index][pTILE]] + " Layer";
                    for (int i = 0; i < generation_param[index][pITER]; i++) SeedLayer(
                            generation_param[index][pTILE],
                            generation_param[index][pDENSE],
                            std::round(float(generation_param[index][pMINX])*W),
                            std::round(float(generation_param[index][pMAXX])*W),
                            std::round(float(generation_param[index][pMINY])*H),
                            std::round(float(generation_param[index][pMAXY])*H)
                            );
                }
                break;
            case mEXPAND :
                {
                    message = "Expanding " + tTile::NAME[generation_param[index][pTILE]] + " Layer";
                    for (int i = 0; i < generation_param[index][pITER]; i++) Expand(
                            generation_param[index][pTILE],
                            std::round(float(generation_param[index][pMINX])*W),
                            std::round(float(generation_param[index][pMAXX])*W),
                            std::round(float(generation_param[index][pMINY])*H),
                            std::round(float(generation_param[index][pMAXY])*H),
                            generation_param[index][pPROBN],
                            generation_param[index][pPROBS],
                            generation_param[index][pPROBE],
                            generation_param[index][pPROBW]
                            );
                }
                break;
            case mDEPOSIT :
                {
                    message = "Depositing " + tTile::NAME[generation_param[index][pTILE]] + " Layer";
                    for (int i = 0; i < generation_param[index][pITER]; i++) Deposit(
                            generation_param[index][pTILE],
                            std::round(float(generation_param[index][pMINX])*W),
                            std::round(float(generation_param[index][pMAXX])*W),
                            std::round(float(generation_param[index][pMINY])*H),
                            std::round(float(generation_param[index][pMAXY])*H),
                            generation_param[index][pPROBN],
                            generation_param[index][pPROBS],
                            generation_param[index][pPROBE],
                            generation_param[index][pPROBW]
                            );
        
                }
                break;
        }
        

        generation_step++;

        return message;
    }

    // Seed Methods
    void AddLayer(int t, int density, int xmin, int xmax, int ymin, int ymax)
    {
        for (int y = ymin; y < ymax; y++)
        {
            for (int x = xmin; x < xmax; x++)
            {
                if (rand()%1000 < density) tCell::matrix[y*tCell::width+x] = t;
            }
        }
    }

    void SeedLayer(int t, int density, int xmin, int xmax, int ymin, int ymax)
    {
        for (int y = ymin; y < ymax; y++)
        {
            for (int x = xmin; x < xmax; x++)
            {
                int index = y*tCell::width+x;
                if (tCell::matrix[index] != tTile::AIR && rand()%10000 < density) tCell::matrix[index] = t;
            }
        }
    }

    // Deposition Methods
    void Expand(int t, int minx, int maxx, int miny, int maxy, int dn=5, int ds=5, int de=25, int dw=25)
    {
        tCell::replace = tCell::matrix;

        minx = std::max(minx, 1);
        maxx = std::min(maxx, tCell::width-2);
        miny = std::max(miny, 1);
        maxy = std::min(maxy, tCell::height-2);

        for (int y = miny; y < maxy; y++)
        {
            for (int x = minx; x < maxx; x++)
            {
                if (tCell::matrix[y*tCell::width+x] != tTile::AIR)
                {
                    int n = (y-1)*tCell::width+x;
                    int s = (y+1)*tCell::width+x;
                    int e = y*tCell::width+(x+1);
                    int w = y*tCell::width+(x-1);

                    if (tCell::matrix[n] == tTile::AIR && rand()%100 < dn) tCell::replace[n] = t;
                    if (tCell::matrix[s] == tTile::AIR && rand()%100 < ds) tCell::replace[s] = t;
                    if (tCell::matrix[e] == tTile::AIR && rand()%100 < de) tCell::replace[e] = t;
                    if (tCell::matrix[w] == tTile::AIR && rand()%100 < dw) tCell::replace[w] = t;
                }
            }
        }
        tCell::matrix = tCell::replace;
    }

    void Deposit(int t, int minx, int maxx, int miny, int maxy, int dn=5, int ds=5, int de=25, int dw=25)
    {
        tCell::replace = tCell::matrix;

        minx = std::max(minx, 1);
        maxx = std::min(maxx, tCell::width-2);
        miny = std::max(miny, 1);
        maxy = std::min(maxy, tCell::height-2);
        
        for (int y = miny; y < maxy; y++)
        {
            for (int x = minx; x < maxx; x++)
            {
                if (tCell::matrix[y*tCell::width+x] == t)
                {
                    int n = (y-1)*tCell::width+x;
                    int s = (y+1)*tCell::width+x;
                    int e = y*tCell::width+(x+1);
                    int w = y*tCell::width+(x-1);

                    if (rand()%100 < dn) tCell::replace[n] = t;
                    if (rand()%100 < ds) tCell::replace[s] = t;
                    if (rand()%100 < de) tCell::replace[e] = t;
                    if (rand()%100 < dw) tCell::replace[w] = t;
                }
            }
        }
        tCell::matrix = tCell::replace;
    }

    // Update Method
    void SettleTiles(int X, int Y, int W, int H)
    {
        tCell::replace = tCell::matrix;

        if (Y < 2)
        {
            Y = 1;
        }
        if (Y > tCell::height-H-2)
        {
            H = tCell::height-Y;
        }

        for (int y = H; y > 0; y--)
        {
            for (int x = 0; x < W; x++)
            {
                int _x = x+X;
                int _y = y+Y;
                if ( tTool::Collision(_x, _y) )
                {
                    int index = (_y)*tCell::width+(_x);
                    int current_cell = tCell::matrix[index];
                    int cell_type = tTool::GetType(current_cell);

                    switch (cell_type)
                    {
                        case tTile::SOLID    : {    tSolid::Update(_x, _y, index, current_cell); } break;
                        case tTile::LOOSE    : {    tLoose::Update(_x, _y, index, current_cell); } break;
                        case tTile::GRAIN    : {    tGrain::Update(_x, _y, index, current_cell); } break;
                        case tTile::FLUID    : {    tFluid::Update(_x, _y, index, current_cell); } break;
                        case tTile::GEL      : {      tGel::Update(_x, _y, index, current_cell); } break;
                        case tTile::PLASMA   : {   tPlasma::Update(_x, _y, index, current_cell); } break;
                        case tTile::GAS      : {      tGas::Update(_x, _y, index, current_cell); } break;
                        case tTile::FUME     : {     tFume::Update(_x, _y, index, current_cell); } break;
                        case tTile::PLANT    : {    tPlant::Update(_x, _y, index, current_cell); } break;
                        case tTile::CRITTER  : {  tCritter::Update(_x, _y, index, current_cell); } break;
                        case tTile::LOGIC    : {    tLogic::Update(_x, _y, index, current_cell); } break;
                        case tTile::GIZMO    : {    tGizmo::Update(_x, _y, index, current_cell); } break;
                        case tTile::PLUMBING : { tPlumbing::Update(_x, _y, index, current_cell); } break;
                    }
                }
            }
        }
        tCell::matrix = tCell::replace;
    }

};