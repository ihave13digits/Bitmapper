namespace tPlasma
{

    //
    // Special
    //

    void Fire(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int chance = rand()%1000;
        switch (tCell::matrix[dN])
        {
            case tTile::WATER : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR: { tCell::replace[dN] = tTile::FLAME; } break;
            case tTile::ASH : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::FIRE : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::CHARCOAL : { if (chance < 250) tCell::replace[dN] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 250) tCell::replace[dN] = tTile::CHARCOAL; } break;
            case tTile::WOOD: { if (chance < 100) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 100) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 500) tCell::replace[dN] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dS])
        {
            case tTile::CHARCOAL : { if (chance < 50) tCell::replace[dS] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 50) tCell::replace[dS] = tTile::CHARCOAL; } break;
            case tTile::WOOD: { if (chance < 25) tCell::replace[dS] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 25) tCell::replace[dS] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 50) tCell::replace[dS] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 50) tCell::replace[dS] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 100) tCell::replace[dS] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::WATER : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR: { tCell::replace[index] = tTile::FLAME; } break;
            case tTile::ASH : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::CHARCOAL : { if (chance < 50) tCell::replace[dE] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 50) tCell::replace[dE] = tTile::CHARCOAL; } break;
            case tTile::WOOD: { if (chance < 25) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 25) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 50) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 50) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 100) tCell::replace[dE] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::WATER : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR: { tCell::replace[index] = tTile::FLAME; } break;
            case tTile::ASH : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::CHARCOAL : { if (chance < 50) tCell::replace[dW] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 50) tCell::replace[dW] = tTile::CHARCOAL; } break;
            case tTile::WOOD: { if (chance < 25) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 25) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 50) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 50) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 100) tCell::replace[dW] = tTile::FIRE; } break;
        }
    }

    void Flame(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int chance = rand()%1000;
        switch (tCell::matrix[dN])
        {
            case tTile::WATER : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR:
                {
                    if (chance < 100) tCell::replace[dN] = tTile::FLARE;
                    if (chance < 2) tCell::replace[index] = tTile::THICK_SMOKE;
                    if (chance > 500) tCell::replace[index] = tTile::AIR;
                } break;
            case tTile::ASH : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::CHARCOAL: { if (chance < 250) tCell::replace[dN] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 250) tCell::replace[dN] = tTile::CHARCOAL; } break;
            case tTile::WOOD: { if (chance < 100) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 100) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 50) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 100) tCell::replace[dN] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::WATER : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR:
                {
                    if (chance < 100) tCell::replace[dE] = tTile::FLARE;
                    if (chance < 5) tCell::replace[index] = tTile::SMOKE;
                    if (chance < 3) tCell::replace[index] = tTile::ASH;
                    if (chance > 500) tCell::replace[index] = tTile::AIR;
                } break;
            case tTile::ASH : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::CHARCOAL: { if (chance < 50) tCell::replace[dE] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 50) tCell::replace[dE] = tTile::CHARCOAL; } break;
            case tTile::WOOD: { if (chance < 25) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 25) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 50) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 50) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 100) tCell::replace[dE] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::WATER : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR:
                {
                    if (chance < 100) tCell::replace[dW] = tTile::FLARE;
                    if (chance < 5) tCell::replace[index] = tTile::SMOKE;
                    if (chance < 3) tCell::replace[index] = tTile::ASH;
                    if (chance > 500) tCell::replace[index] = tTile::AIR;
                } break;
            case tTile::ASH : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::CHARCOAL: { if (chance < 50) tCell::replace[dW] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 50) tCell::replace[dW] = tTile::CHARCOAL; } break;
            case tTile::WOOD: { if (chance < 25) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 25) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 50) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 50) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 100) tCell::replace[dW] = tTile::FIRE; } break;
        }
    }

    void Flare(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int chance = rand()%1000;
        switch (tCell::matrix[dN])
        {
            case tTile::WATER : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR: { tCell::replace[dN] = tTile::FIRE; } break;
            case tTile::ASH : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::CHARCOAL : { if (chance < 500) tCell::replace[dN] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 250) tCell::replace[dN] = tTile::CHARCOAL; } break;
            case tTile::WOOD: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 500) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 500) tCell::replace[dN] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::WATER : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR: { tCell::replace[index] = tTile::FIRE; } break;
            case tTile::ASH : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::CHARCOAL : { if (chance < 250) tCell::replace[dE] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 250) tCell::replace[dE] = tTile::CHARCOAL; } break;
            case tTile::WOOD: { if (chance < 100) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 100) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 250) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 500) tCell::replace[dE] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::WATER : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR: { tCell::replace[index] = tTile::FIRE; } break;
            case tTile::ASH : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::CHARCOAL : { if (chance < 250) tCell::replace[dW] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 250) tCell::replace[dW] = tTile::CHARCOAL; } break;
            case tTile::WOOD: { if (chance < 100) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 100) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 250) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 500) tCell::replace[dW] = tTile::FIRE; } break;
        }
    }



    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell, char season=0)
    {
        switch (current_cell)
            {
                case tTile::FIRE : { Fire(_x, _y, index, season); } break;
                case tTile::FLAME : { Flame(_x, _y, index, season); } break;
                case tTile::FLARE : { Flare(_x, _y, index, season); } break;
            }
    }

}
