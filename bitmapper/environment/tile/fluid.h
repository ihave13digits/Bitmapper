namespace tFluid
{

    // 
    // Special
    //

    void Water(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        switch (tCell::matrix[dS])
        {
            case tTile::GRASS   : { tCell::replace[index] = tTile::AIR;   tCell::replace[dS] = tTile::GRASS;    } break;
            case tTile::DIRT    : { tCell::replace[index] = tTile::AIR;   tCell::replace[dS] = tTile::MUD;      } break;
            case tTile::SOIL    : { tCell::replace[index] = tTile::AIR;   tCell::replace[dS] = tTile::MUCK;     } break;
            case tTile::SNOW    : { tCell::replace[index] = tTile::AIR;   tCell::replace[dS] = tTile::ICE;      } break;
            case tTile::SALT    : { tCell::replace[index] = tTile::AIR;   tCell::replace[dS] = tTile::BRINE;    } break;
            case tTile::LAVA    : { tCell::replace[index] = tTile::STEAM; tCell::replace[dS] = tTile::OBSIDIAN; } break;
            case tTile::CALDERA : { tCell::replace[index] = tTile::STEAM;                                } break;
            case tTile::MANTLE  : { tCell::replace[index] = tTile::STEAM;                                } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::DIRT : { tCell::replace[index] = tTile::AIR;   tCell::replace[dW] = tTile::MUD;      } break;
            case tTile::SOIL : { tCell::replace[index] = tTile::AIR;   tCell::replace[dW] = tTile::MUCK;     } break;
            case tTile::SALT : { tCell::replace[index] = tTile::AIR;   tCell::replace[dS] = tTile::BRINE;    } break;
            case tTile::LAVA : { tCell::replace[index] = tTile::STEAM; tCell::replace[dW] = tTile::OBSIDIAN; } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::DIRT : { tCell::replace[index] = tTile::AIR;   tCell::replace[dE] = tTile::MUD;      } break;
            case tTile::SOIL : { tCell::replace[index] = tTile::AIR;   tCell::replace[dE] = tTile::MUCK;     } break;
            case tTile::SALT : { tCell::replace[index] = tTile::AIR;   tCell::replace[dS] = tTile::BRINE;    } break;
            case tTile::LAVA : { tCell::replace[index] = tTile::STEAM; tCell::replace[dE] = tTile::OBSIDIAN; } break;
        }
        switch (tCell::matrix[dN])
        {
            case tTile::DIRT : { tCell::replace[index] = tTile::AIR;   tCell::replace[dN] = tTile::MUD;      } break;
            case tTile::SOIL : { tCell::replace[index] = tTile::AIR;   tCell::replace[dN] = tTile::MUCK;     } break;
            case tTile::SALT : { tCell::replace[index] = tTile::AIR;   tCell::replace[dS] = tTile::BRINE;    } break;
            case tTile::LAVA : { tCell::replace[index] = tTile::STEAM; tCell::replace[dN] = tTile::OBSIDIAN; } break;
        }
    }

    void Brine(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        if (tCell::matrix[dN] == tTile::AIR) if (rand()%10000 < 5)
        {
            if (tTool::GetType(tCell::matrix[dNW]) == tTile::SOLID) { tCell::replace[index] = tTile::AIR; tCell::replace[dN] = tTile::SALT; }
            else if (tTool::GetType(tCell::matrix[dNE]) == tTile::SOLID) { tCell::replace[index] = tTile::AIR; tCell::replace[dN] = tTile::SALT; }
        }
    }

    void Oil(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE = int( (_y) * tCell::width + (_x+1) );
        int dW = int( (_y) * tCell::width + (_x-1) );
        if (tCell::matrix[dN] == tTile::AIR && tCell::matrix[dS] == tTile::OIL &&
            tCell::matrix[dE] == tTile::OIL && tCell::matrix[dW] == tTile::OIL)
        {
            if (rand()%1000 < 25) tCell::replace[dN] = tTile::OIL_FUMES;
            if (rand()%1000 < 5) tCell::replace[index] = tTile::OIL_FUMES;
        }
    }



    //
    // Generic
    //
    
    void Update(int _x, int _y, int index, int current_cell, char season=0)
    {
        int cell_type = tTool::GetType(current_cell);
        int direction = rand() % 100;

        if (direction < 50)
        {
            if (!tTool::FluidCollision(_x, _y+2) && !tTool::FluidCollision(_x, _y+1))
            {
                int rplc = (_y+2)*tCell::width+(_x);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
                                                                // ░░██░░
            }
            else if (!tTool::FluidCollision(_x, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░██░░
            }
            else if (!tTool::FluidCollision(_x-1, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x-1);          // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ██░░░░
            }
            else if (!tTool::FluidCollision(_x+1, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x+1);          // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░██
            }
            else if (!tTool::FluidCollision(_x-2, _y) && !tTool::FluidCollision(_x-1, _y))
            {
                int rplc = (_y)*tCell::width+(_x-2);            // ░░░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ██░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░░░
            }
            else if (!tTool::FluidCollision(_x+2, _y) && !tTool::FluidCollision(_x+1, _y))
            {
                int rplc = (_y)*tCell::width+(_x+2);            // ░░░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░██
                tCell::replace[index] = tTile::AIR;             // ░░░░░░░░
            }
            else if (!tTool::FluidCollision(_x-1, _y) && tTool::FluidCollision(_x+1, _y))
            {
                int rplc = (_y)*tCell::width+(_x-1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ██▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
            else if (!tTool::FluidCollision(_x+1, _y) && tTool::FluidCollision(_x-1, _y))
            {
                int rplc = (_y)*tCell::width+(_x+1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓██
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
        }
        else
        {
            if (!tTool::FluidCollision(_x, _y+2) && !tTool::FluidCollision(_x, _y+1))
            {
                int rplc = (_y+2)*tCell::width+(_x);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
                                                                // ░░██░░
            }
            else if (!tTool::FluidCollision(_x, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░██░░
            }
            else if (!tTool::FluidCollision(_x+1, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x+1);          // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░██
            }
            else if (!tTool::FluidCollision(_x-1, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x-1);          // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ██░░░░
            }
            else if (!tTool::FluidCollision(_x+2, _y) && !tTool::FluidCollision(_x+1, _y))
            {
                int rplc = (_y)*tCell::width+(_x+2);            // ░░░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░██
                tCell::replace[index] = tTile::AIR;             // ░░░░░░░░
            }
            else if (!tTool::FluidCollision(_x-2, _y) && !tTool::FluidCollision(_x-1, _y))
            {
                int rplc = (_y)*tCell::width+(_x-2);            // ░░░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ██░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░░░
            }
            else if (!tTool::FluidCollision(_x+1, _y) && tTool::FluidCollision(_x-1, _y))
            {
                int rplc = (_y)*tCell::width+(_x+1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓██
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
            else if (!tTool::FluidCollision(_x-1, _y) && tTool::FluidCollision(_x+1, _y))
            {
                int rplc = (_y)*tCell::width+(_x-1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ██▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
        }

        switch(current_cell)
        {
            case tTile::WATER : {Water(_x, _y, index, season);} break;
            case tTile::BRINE : {Brine(_x, _y, index, season);} break;
            case tTile::OIL   : {Oil(_x, _y, index, season);  } break;
        }
    }

}
