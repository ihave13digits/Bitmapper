namespace tFluid
{

    // 
    // Special
    //

    void Water(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        switch (tCell::matrix[dS])
        {
            case tTile::GRASS   : { tCell::replace[index] = tTile::AIR;                                         } break;
            case tTile::DIRT    : { tCell::replace[index] = tTile::AIR;   tCell::replace[dS] = tTile::MUD;      } break;
            case tTile::SOIL    : { tCell::replace[index] = tTile::AIR;   tCell::replace[dS] = tTile::MUCK;     } break;
            case tTile::SNOW    : { tCell::replace[index] = tTile::AIR;   tCell::replace[dS] = tTile::ICE;      } break;
            case tTile::SALT    : { tCell::replace[index] = tTile::AIR;   tCell::replace[dS] = tTile::BRINE;    } break;
            case tTile::LAVA    : { tCell::replace[index] = tTile::STEAM; tCell::replace[dS] = tTile::OBSIDIAN; } break;
            case tTile::CALDERA : { tCell::replace[index] = tTile::STEAM;                                       } break;
            case tTile::MANTLE  : { tCell::replace[index] = tTile::STEAM;                                       } break;
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

    void Magma(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int dSS = int( (_y+2) * tCell::width + (_x  ) );
        int chance = rand()%10000;
        switch (tCell::matrix[dS])
        {
            case tTile::ICE           : {                                   tCell::replace[dS] = tTile::WATER;        } break;
            case tTile::SNOW          : {                                   tCell::replace[dS] = tTile::WATER;        } break;
            case tTile::VOLCANIC_ROCK : {               if (chance < 25)    tCell::replace[dS] = tTile::LAVA;         } break;
            case tTile::STONE         : {               if (chance < 50)    tCell::replace[dS] = tTile::LAVA;         } break;
            case tTile::GRAVEL        : {               if (chance < 100)   tCell::replace[dS] = tTile::LAVA;         } break;
            case tTile::SAND          : {               if (chance < 500)   tCell::replace[dS] = tTile::LAVA;         } break;
            case tTile::ASH           : {               if (chance < 1000)  tCell::replace[dS] = tTile::SMOKE;        } break;
            case tTile::CHARCOAL      : {               if (chance < 1000)  tCell::replace[dS] = tTile::EMBER;        } break;
            case tTile::CHARRED_WOOD  : {               if (chance < 1000)  tCell::replace[dS] = tTile::CHARCOAL;     } break;
            case tTile::WOOD          : {               if (chance < 500)   tCell::replace[dS] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK         : {               if (chance < 500)   tCell::replace[dS] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH        : {               if (chance < 500)   tCell::replace[dS] = tTile::CHARCOAL;     } break;
            case tTile::STICK         : {               if (chance < 500)   tCell::replace[dS] = tTile::CHARCOAL;     } break;
            case tTile::LEAVES        : {               if (chance < 500)   tCell::replace[dS] = tTile::FIRE;         } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::WATER         : { tCell::replace[index] = tTile::OBSIDIAN; tCell::replace[dW] = tTile::STEAM; } break;
            case tTile::VOLCANIC_ROCK : {         if (chance < 25)   tCell::replace[dW] = tTile::LAVA;         } break;
            case tTile::GRAVEL        : {         if (chance < 50)   tCell::replace[dW] = tTile::LAVA;         } break;
            case tTile::SAND          : {         if (chance < 250)  tCell::replace[dW] = tTile::LAVA;         } break;
            case tTile::ASH           : {         if (chance < 1000) tCell::replace[dW] = tTile::SMOKE;        } break;
            case tTile::CHARCOAL      : {         if (chance < 1000) tCell::replace[dW] = tTile::EMBER;        } break;
            case tTile::CHARRED_WOOD  : {         if (chance < 1000) tCell::replace[dW] = tTile::CHARCOAL;     } break;
            case tTile::WOOD          : {         if (chance < 500)  tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK         : {         if (chance < 500)  tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH        : {         if (chance < 500)  tCell::replace[dW] = tTile::CHARCOAL;     } break;
            case tTile::STICK         : {         if (chance < 500)  tCell::replace[dW] = tTile::CHARCOAL;     } break;
            case tTile::LEAVES        : {         if (chance < 500)  tCell::replace[dW] = tTile::FIRE;         } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::WATER         : { tCell::replace[index] = tTile::OBSIDIAN; tCell::replace[dE] = tTile::STEAM; } break;
            case tTile::VOLCANIC_ROCK : {         if (chance < 25)   tCell::replace[dE] = tTile::LAVA;         } break;
            case tTile::GRAVEL        : {         if (chance < 50)   tCell::replace[dE] = tTile::LAVA;         } break;
            case tTile::SAND          : {         if (chance < 250)  tCell::replace[dE] = tTile::LAVA;         } break;
            case tTile::ASH           : {         if (chance < 1000) tCell::replace[dE] = tTile::SMOKE;        } break;
            case tTile::CHARCOAL      : {         if (chance < 1000) tCell::replace[dE] = tTile::EMBER;        } break;
            case tTile::CHARRED_WOOD  : {         if (chance < 1000) tCell::replace[dE] = tTile::CHARCOAL;     } break;
            case tTile::WOOD          : {         if (chance < 500)  tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK         : {         if (chance < 500)  tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH        : {         if (chance < 500)  tCell::replace[dE] = tTile::CHARCOAL;     } break;
            case tTile::STICK         : {         if (chance < 500)  tCell::replace[dE] = tTile::CHARCOAL;     } break;
            case tTile::LEAVES        : {         if (chance < 500)  tCell::replace[dE] = tTile::FIRE;         } break;
        }
        switch (tCell::matrix[dN])
        {
            case tTile::WATER         : { tCell::replace[index] = tTile::OBSIDIAN; tCell::replace[dN] = tTile::STEAM; } break;
            case tTile::GRAVEL        : {         if (chance < 100)  tCell::replace[dN] = tTile::LAVA;         } break;
            case tTile::SAND          : {         if (chance < 500)  tCell::replace[dN] = tTile::LAVA;         } break;
            case tTile::ASH           : {         if (chance < 1000) tCell::replace[dN] = tTile::SMOKE;        } break;
            case tTile::CHARCOAL      : {         if (chance < 1000) tCell::replace[dN] = tTile::EMBER;        } break;
            case tTile::CHARRED_WOOD  : {         if (chance < 1000) tCell::replace[dN] = tTile::CHARCOAL;     } break;
            case tTile::WOOD          : {         if (chance < 500)  tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK         : {         if (chance < 500)  tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH        : {         if (chance < 500)  tCell::replace[dN] = tTile::CHARCOAL;     } break;
            case tTile::STICK         : {         if (chance < 250)  tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES        : {         if (chance < 500)  tCell::replace[dN] = tTile::FIRE;         } break;
        }
        if (tCell::matrix[dSS] != tTile::LAVA || tCell::matrix[dE+1] != tTile::LAVA || tCell::matrix[dW-1] != tTile::LAVA)
        {
            int n = 0;
            if (tCell::matrix[dN] != tTile::MAGMA) n++;
            if (tCell::matrix[dS] != tTile::MAGMA) n++;
            if (tCell::matrix[dE] != tTile::MAGMA) n++;
            if (tCell::matrix[dW] != tTile::MAGMA) n++;
            { if (n > 2 && rand()%1000 < 15) tCell::replace[index] = tTile::LAVA; }
        }
    }

    void Brine(int _x, int _y, int index)
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

    void Oil(int _x, int _y, int index)
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
    
    void Update(int _x, int _y, int index, int current_cell)
    {
        int cell_type = tTool::GetType(current_cell);
        int direction = rand() % 100;

        if (direction < 50)
        {
            if (!tTool::FluidCollision(_x, _y+2) && !tTool::FluidCollision(_x, _y+1))
            { int rplc = (_y+2)*tCell::width+(_x); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FluidCollision(_x, _y+1) && tTool::FluidCollision(_x, _y+2))
            { int rplc = (_y+1)*tCell::width+(_x); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FluidCollision(_x-1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FluidCollision(_x+1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FluidCollision(_x-2, _y) && !tTool::FluidCollision(_x-1, _y))
            { int rplc = (_y)*tCell::width+(_x-2); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FluidCollision(_x+2, _y) && !tTool::FluidCollision(_x+1, _y))
            { int rplc = (_y)*tCell::width+(_x+2); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FluidCollision(_x-1, _y) && tTool::FluidCollision(_x+1, _y))
            { int rplc = (_y)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FluidCollision(_x+1, _y) && tTool::FluidCollision(_x-1, _y))
            { int rplc = (_y)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
        }
        else
        {
            if (!tTool::FluidCollision(_x, _y+2) && !tTool::FluidCollision(_x, _y+1))
            { int rplc = (_y+2)*tCell::width+(_x); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FluidCollision(_x, _y+1) && tTool::FluidCollision(_x, _y+2))
            { int rplc = (_y+1)*tCell::width+(_x); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FluidCollision(_x+1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FluidCollision(_x-1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FluidCollision(_x+2, _y) && !tTool::FluidCollision(_x+1, _y))
            { int rplc = (_y)*tCell::width+(_x+2); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FluidCollision(_x-2, _y) && !tTool::FluidCollision(_x-1, _y))
            { int rplc = (_y)*tCell::width+(_x-2); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FluidCollision(_x+1, _y) && tTool::FluidCollision(_x-1, _y))
            { int rplc = (_y)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FluidCollision(_x-1, _y) && tTool::FluidCollision(_x+1, _y))
            { int rplc = (_y)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
        }

        switch(current_cell)
        {
            case tTile::WATER : { Water(_x, _y, index); } break;
            case tTile::MAGMA : { Magma(_x, _y, index); } break;
            case tTile::BRINE : { Brine(_x, _y, index); } break;
            case tTile::OIL   : {   Oil(_x, _y, index); } break;
        }
    }

}
