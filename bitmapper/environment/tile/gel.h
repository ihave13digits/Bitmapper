namespace tGel
{

    //
    // Special
    //

    void Mud(int _x, int _y, int index)
    {
        uint8_t n = 0;
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        if (tCell::matrix[dN] == tTile::AIR || tCell::matrix[dN] == tTile::DIRT) { n++; }
        if (tCell::matrix[dS] == tTile::AIR || tCell::matrix[dS] == tTile::DIRT) { n++; }
        if (tCell::matrix[dE] == tTile::AIR || tCell::matrix[dE] == tTile::DIRT) { n++; }
        if (tCell::matrix[dW] == tTile::AIR || tCell::matrix[dW] == tTile::DIRT) { n++; }

        if (n > 0) { if (rand()%(2500*n) < 5) tCell::replace[index] = tTile::DAMP_DIRT; }
    }

    void Muck(int _x, int _y, int index)
    {
        uint8_t n = 0;
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        if (tCell::matrix[dN] == tTile::AIR || tCell::matrix[dN] == tTile::SOIL) { n++; }
        if (tCell::matrix[dS] == tTile::AIR || tCell::matrix[dS] == tTile::SOIL) { n++; }
        if (tCell::matrix[dE] == tTile::AIR || tCell::matrix[dE] == tTile::SOIL) { n++; }
        if (tCell::matrix[dW] == tTile::AIR || tCell::matrix[dW] == tTile::SOIL) { n++; }

        if (n > 0) { if (rand()%(2500*n) < 5) tCell::replace[index] = tTile::DAMP_SOIL; }
    }

    void Lava(int _x, int _y, int index)
    {
        int dNN = int( (_y-2) * tCell::width + (_x  ) );
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int dSS = int( (_y+2) * tCell::width + (_x  ) );
        int chance = rand()%10000;
        switch (tCell::matrix[dS])
        {
            case tTile::WATER         : { tCell::replace[index] = tTile::OBSIDIAN; tCell::replace[dS] = tTile::STEAM; } break;
            case tTile::CALDERA       : {               if (chance < 25)    tCell::replace[index] = tTile::LAVA_ROCK; } break;
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
            if (tCell::matrix[dN] != tTile::LAVA && tCell::matrix[dN] != tTile::MAGMA) n++;
            if (tCell::matrix[dS] != tTile::LAVA && tCell::matrix[dS] != tTile::MAGMA) n++;
            if (tCell::matrix[dE] != tTile::LAVA && tCell::matrix[dE] != tTile::MAGMA) n++;
            if (tCell::matrix[dW] != tTile::LAVA && tCell::matrix[dW] != tTile::MAGMA) n++;
            { if (n > 2 && rand()%1000 < 15) tCell::replace[index] = tTile::LAVA_ROCK; }
        }
        if (tCell::matrix[dNN] == tTile::MAGMA) { if (rand()%1000 < 5) tCell::replace[index] = tTile::MAGMA; }
    }



    //
    // Generic
    //
    
    void Update(int _x, int _y, int index, int current_cell)
    {

        int direction = rand() % 100;
        if (direction < 50)
        {
            if (!tTool::GelCollision(_x, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x); if (tCell::matrix[index] != tCell::replace[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::GelCollision(_x-1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::replace[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::GelCollision(_x+1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::replace[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::GelCollision(_x-1, _y) && tTool::GelCollision(_x+1, _y))
            { int rplc = (_y)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::replace[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::GelCollision(_x+1, _y) && tTool::GelCollision(_x-1, _y))
            { int rplc = (_y)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::replace[rplc]){ tTool::Swap(index, rplc); } }
        }
        else
        {
            if (!tTool::GelCollision(_x, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x); if (tCell::matrix[index] != tCell::replace[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::GelCollision(_x+1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::replace[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::GelCollision(_x-1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::replace[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::GelCollision(_x+1, _y) && tTool::GelCollision(_x-1, _y))
            { int rplc = (_y)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::replace[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::GelCollision(_x-1, _y) && tTool::GelCollision(_x+1, _y))
            { int rplc = (_y)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::replace[rplc]){ tTool::Swap(index, rplc); } }
        }

        switch(current_cell)
        {
            case tTile::MUD : { Mud(_x, _y, index); } break;
            case tTile::MUCK : { Muck(_x, _y, index); } break;
            case tTile::LAVA : { Lava(_x, _y, index); } break;
        }
    }

}
