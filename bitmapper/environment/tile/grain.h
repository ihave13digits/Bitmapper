namespace tGrain
{

    //
    // Special
    //

    void Snow(int _x, int _y, int index)
    {
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        switch (tCell::matrix[dS])
        {
            case tTile::GRASS : { if (rand()%1000 < 5) tCell::replace[index] = tTile::AIR; } break;
            case tTile::LAVA : { tCell::replace[index] = tTile::WATER; } break;
        }
    }

    void Ember(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int chance = rand()%10000;
        switch (tCell::matrix[dN])
        {
            case tTile::WATER        : { tCell::replace[index] = tTile::CHARCOAL; } break;
            case tTile::AIR          : { tCell::replace[dN] = tTile::FIRE; } break;
            case tTile::ASH          : { tCell::replace[index] = tTile::CHARCOAL; } break;
            case tTile::THIN_SMOKE   : { if (chance < 10) tCell::replace[index] = tTile::ASH; } break;
            case tTile::SMOKE        : { if (chance < 50) tCell::replace[index] = tTile::ASH; } break;
            case tTile::THICK_SMOKE  : { if (chance < 250) tCell::replace[index] = tTile::ASH; } break;
            case tTile::CHARCOAL     : { if (chance < 1000) tCell::replace[dN] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD : { if (chance < 1000) tCell::replace[dN] = tTile::CHARCOAL; } break;
            case tTile::WOOD         : { if (chance < 500) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK        : { if (chance < 500) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH       : { if (chance < 500) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES       : { if (chance < 500) tCell::replace[dN] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dS])
        {
            case tTile::SMOKE        : { tCell::replace[dS] = tTile::EMBER; } break;
            case tTile::WATER        : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::CHARCOAL     : { if (chance < 500) tCell::replace[dS] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD : { if (chance < 500) tCell::replace[dS] = tTile::CHARCOAL; } break;
            case tTile::WOOD         : { if (chance < 250) tCell::replace[dS] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK        : { if (chance < 250) tCell::replace[dS] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH       : { if (chance < 250) tCell::replace[dS] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES       : { if (chance < 500) tCell::replace[dS] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::WATER        : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR          : { tCell::replace[dE] = tTile::FIRE; } break;
            case tTile::CHARCOAL     : { if (chance < 500) tCell::replace[dE] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD : { if (chance < 500) tCell::replace[dE] = tTile::CHARCOAL; } break;
            case tTile::WOOD         : { if (chance < 250) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK        : { if (chance < 250) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH       : { if (chance < 250) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES       : { if (chance < 500) tCell::replace[dE] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::WATER        : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR          : { tCell::replace[dW] = tTile::FIRE; } break;
            case tTile::CHARCOAL     : { if (chance < 500) tCell::replace[dW] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD : { if (chance < 500) tCell::replace[dW] = tTile::CHARCOAL; } break;
            case tTile::WOOD         : { if (chance < 250) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK        : { if (chance < 250) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH       : { if (chance < 250) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES       : { if (chance < 500) tCell::replace[dW] = tTile::FIRE; } break;
        }

        if (chance < 50) tCell::replace[index] = tTile::FIRE;
    }

    void Acorn(int _x, int _y, int index)
    {
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dS = int( (_y+1) * tCell::width + (_x) );
        int dN = int( (_y-1) * tCell::width + (_x) );
        int dE = int( (_y) * tCell::width + (_x+1) );
        int dW = int( (_y) * tCell::width + (_x-1) );
        int chance = rand()%10000;
        if (chance < 25)
        {
            if (tCell::matrix[dS] == tTile::GRASS) { tCell::replace[dS] = tTile::TRUNK; tCell::replace[index] = tTile::TRUNK; }
            if (tCell::matrix[dSE] == tTile::GRASS)
            {
                tCell::replace[dSE] = tTile::TRUNK;
                tCell::replace[dE] = tTile::TRUNK;
                if (tCell::matrix[dS] == tTile::GRASS) {tCell::replace[dN] = tTile::TRUNK; tCell::replace[index] = tTile::TRUNK; }
            }
            if (tCell::matrix[dSW] == tTile::GRASS)
            {
                tCell::replace[dSW] = tTile::TRUNK;
                tCell::replace[dW] = tTile::TRUNK;
                if (tCell::matrix[dS] == tTile::GRASS) {tCell::replace[dN] = tTile::TRUNK; tCell::replace[index] = tTile::TRUNK; }
            }
            if (tCell::matrix[dN] == tTile::FIRE) { tCell::replace[index] = tTile::BOMB; }
        }
    }



    //
    // Generic
    //
    
    void Update(int _x, int _y, int index, int current_cell)
    {

        int direction = rand() % 100;
        if (direction < 50)
        {
            if (!tTool::GrainCollision(_x, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::GrainCollision(_x-1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::GrainCollision(_x+1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
        }
        else
        {
            if (!tTool::GrainCollision(_x, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::GrainCollision(_x+1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::GrainCollision(_x-1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
        }

        switch (current_cell)
        {
            case tTile::ACORN : { Acorn(_x, _y, index); } break;
            case tTile::EMBER : { Ember(_x, _y, index); } break;
            case tTile::SNOW : { Snow(_x, _y, index); } break;
        }

    }

}
