namespace tGel
{

    //
    // Special
    //

    void Mud(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        if (tCell::matrix[dN] == tTile::AIR)  { if (rand()%10000 < 5) tCell::replace[index] = tTile::DIRT; }
        if (tCell::matrix[dN] == tTile::ROOT) { if (rand()%10000 < 5) tCell::replace[index] = tTile::SOIL; }
    }

    void Muck(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        if (tCell::matrix[dN] == tTile::AIR) { if (rand()%10000 < 5) tCell::replace[index] = tTile::SOIL; }
    }

    void Lava(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int chance = rand()%10000;
        switch (tCell::matrix[dS])
        {
            case tTile::WATER        : { tCell::replace[index] = tTile::OBSIDIAN; tCell::replace[dS] = tTile::STEAM;        } break;
            case tTile::ICE          : {                                   tCell::replace[dS] = tTile::WATER;        } break;
            case tTile::SNOW         : {                                   tCell::replace[dS] = tTile::WATER;        } break;
            case tTile::STONE        : {               if (chance < 100)   tCell::replace[dS] = tTile::LAVA;         } break;
            case tTile::GRAVEL       : {               if (chance < 100)   tCell::replace[dS] = tTile::LAVA;         } break;
            case tTile::SAND         : {               if (chance < 500)   tCell::replace[dS] = tTile::LAVA;         } break;
            case tTile::ASH          : {               if (chance < 1000)  tCell::replace[dS] = tTile::SMOKE;        } break;
            case tTile::CHARCOAL     : {               if (chance < 1000)  tCell::replace[dS] = tTile::EMBER;        } break;
            case tTile::CHARRED_WOOD : {               if (chance < 1000)  tCell::replace[dS] = tTile::CHARCOAL;     } break;
            case tTile::WOOD         : {               if (chance < 500)   tCell::replace[dS] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK        : {               if (chance < 500)   tCell::replace[dS] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH       : {               if (chance < 500)   tCell::replace[dS] = tTile::CHARCOAL;     } break;
            case tTile::LEAVES       : {               if (chance < 500)   tCell::replace[dS] = tTile::FIRE;         } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::WATER        : { tCell::replace[index] = tTile::OBSIDIAN; tCell::replace[dW] = tTile::STEAM;        } break;
            case tTile::GRAVEL       : {         if (chance < 100)  tCell::replace[dW] = tTile::LAVA;         } break;
            case tTile::SAND         : {         if (chance < 500)  tCell::replace[dW] = tTile::LAVA;         } break;
            case tTile::ASH          : {         if (chance < 1000) tCell::replace[dW] = tTile::SMOKE;        } break;
            case tTile::CHARCOAL     : {         if (chance < 1000) tCell::replace[dW] = tTile::EMBER;        } break;
            case tTile::CHARRED_WOOD : {         if (chance < 1000) tCell::replace[dW] = tTile::CHARCOAL;     } break;
            case tTile::WOOD         : {         if (chance < 500)  tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK        : {         if (chance < 500)  tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH       : {         if (chance < 500)  tCell::replace[dW] = tTile::CHARCOAL;     } break;
            case tTile::LEAVES       : {         if (chance < 500)  tCell::replace[dW] = tTile::FIRE;         } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::WATER        : { tCell::replace[index] = tTile::OBSIDIAN; tCell::replace[dE] = tTile::STEAM;        } break;
            case tTile::GRAVEL       : {         if (chance < 100)  tCell::replace[dE] = tTile::LAVA;         } break;
            case tTile::SAND         : {         if (chance < 500)  tCell::replace[dE] = tTile::LAVA;         } break;
            case tTile::ASH          : {         if (chance < 1000) tCell::replace[dE] = tTile::SMOKE;        } break;
            case tTile::CHARCOAL     : {         if (chance < 1000) tCell::replace[dE] = tTile::EMBER;        } break;
            case tTile::CHARRED_WOOD : {         if (chance < 1000) tCell::replace[dE] = tTile::CHARCOAL;     } break;
            case tTile::WOOD         : {         if (chance < 500)  tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK        : {         if (chance < 500)  tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH       : {         if (chance < 500)  tCell::replace[dE] = tTile::CHARCOAL;     } break;
            case tTile::LEAVES       : {         if (chance < 500)  tCell::replace[dE] = tTile::FIRE;         } break;
        }
        switch (tCell::matrix[dN])
        {
            case tTile::WATER        : { tCell::replace[index] = tTile::OBSIDIAN; tCell::replace[dN] = tTile::STEAM;        } break;
            case tTile::GRAVEL       : {         if (chance < 100)  tCell::replace[dN] = tTile::LAVA;         } break;
            case tTile::SAND         : {         if (chance < 500)  tCell::replace[dN] = tTile::LAVA;         } break;
            case tTile::ASH          : {         if (chance < 1000) tCell::replace[dN] = tTile::SMOKE;        } break;
            case tTile::CHARCOAL     : {         if (chance < 1000) tCell::replace[dN] = tTile::EMBER;        } break;
            case tTile::CHARRED_WOOD : {         if (chance < 1000) tCell::replace[dN] = tTile::CHARCOAL;     } break;
            case tTile::WOOD         : {         if (chance < 500)  tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK        : {         if (chance < 500)  tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH       : {         if (chance < 500)  tCell::replace[dN] = tTile::CHARCOAL;     } break;
            case tTile::LEAVES       : {         if (chance < 500)  tCell::replace[dN] = tTile::FIRE;         } break;
        }
    }



    //
    // Generic
    //
    
    void Update(int _x, int _y, int index, int current_cell, char season=0)
    {

        int direction = rand() % 100;
        if (direction < 50)
        {
            if (!tTool::FluidCollision(_x, _y+1))
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
            if (!tTool::FluidCollision(_x, _y+1))
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
            case tTile::MUD : { Mud(_x, _y, index, season); } break;
            case tTile::MUCK : { Muck(_x, _y, index, season); } break;
            case tTile::LAVA : { Lava(_x, _y, index, season); } break;
        }
    }

}