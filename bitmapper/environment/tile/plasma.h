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
            case tTile::ASH : { tCell::replace[index] = tTile::SMOKE; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::THICK_SMOKE; } break;
            case tTile::FIRE : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::CHARCOAL : { if (chance < 250) tCell::replace[dN] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 250) tCell::replace[dN] = tTile::CHARCOAL; } break;
            case tTile::OIL_FUMES: { if (chance < 250) tCell::replace[dN] = tTile::FIRE; } break;
            case tTile::WOOD: { if (chance < 100) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 100) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 500) tCell::replace[dN] = tTile::FIRE; } break;
            case tTile::DRY_LEAVES: { if (chance < 600) tCell::replace[dN] = tTile::FIRE; } break;
            case tTile::OLD_LEAVES: { if (chance < 700) tCell::replace[dN] = tTile::FIRE; } break;
            case tTile::DEAD_LEAVES: { if (chance < 750) tCell::replace[dN] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dS])
        {
            case tTile::CHARCOAL : { if (chance < 50) tCell::replace[dS] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 50) tCell::replace[dS] = tTile::CHARCOAL; } break;
            case tTile::OIL_FUMES: { if (chance < 250) tCell::replace[dS] = tTile::FIRE; } break;
            case tTile::WOOD: { if (chance < 25) tCell::replace[dS] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 25) tCell::replace[dS] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 50) tCell::replace[dS] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 50) tCell::replace[dS] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 100) tCell::replace[dS] = tTile::FIRE; } break;
            case tTile::DRY_LEAVES: { if (chance < 130) tCell::replace[dS] = tTile::FIRE; } break;
            case tTile::OLD_LEAVES: { if (chance < 160) tCell::replace[dS] = tTile::FIRE; } break;
            case tTile::DEAD_LEAVES: { if (chance < 200) tCell::replace[dS] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::WATER : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR: { tCell::replace[index] = tTile::FLAME; } break;
            case tTile::ASH : { tCell::replace[index] = tTile::SMOKE; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::THICK_SMOKE; } break;
            case tTile::CHARCOAL : { if (chance < 50) tCell::replace[dE] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 50) tCell::replace[dE] = tTile::CHARCOAL; } break;
            case tTile::OIL_FUMES: { if (chance < 250) tCell::replace[dE] = tTile::FIRE; } break;
            case tTile::WOOD: { if (chance < 25) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 25) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 50) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 50) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 100) tCell::replace[dE] = tTile::FIRE; } break;
            case tTile::DRY_LEAVES: { if (chance < 130) tCell::replace[dE] = tTile::FIRE; } break;
            case tTile::OLD_LEAVES: { if (chance < 160) tCell::replace[dE] = tTile::FIRE; } break;
            case tTile::DEAD_LEAVES: { if (chance < 200) tCell::replace[dE] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::WATER : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR: { tCell::replace[index] = tTile::FLAME; } break;
            case tTile::ASH : { tCell::replace[index] = tTile::SMOKE; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::THICK_SMOKE; } break;
            case tTile::CHARCOAL : { if (chance < 50) tCell::replace[dW] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 50) tCell::replace[dW] = tTile::CHARCOAL; } break;
            case tTile::OIL_FUMES: { if (chance < 250) tCell::replace[dW] = tTile::FIRE; } break;
            case tTile::WOOD: { if (chance < 25) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 25) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 50) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 50) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 100) tCell::replace[dW] = tTile::FIRE; } break;
            case tTile::DRY_LEAVES: { if (chance < 130) tCell::replace[dW] = tTile::FIRE; } break;
            case tTile::OLD_LEAVES: { if (chance < 160) tCell::replace[dW] = tTile::FIRE; } break;
            case tTile::DEAD_LEAVES: { if (chance < 200) tCell::replace[dW] = tTile::FIRE; } break;
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
                    if (chance < 5) tCell::replace[index] = tTile::THICK_SMOKE;
                    if (chance > 500) tCell::replace[index] = tTile::SMOKE;
                } break;
            case tTile::ASH : { tCell::replace[index] = tTile::THICK_SMOKE; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::THIN_SMOKE; } break;
            case tTile::CHARCOAL: { if (chance < 250) tCell::replace[dN] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 250) tCell::replace[dN] = tTile::CHARCOAL; } break;
            case tTile::OIL_FUMES: { if (chance < 250) tCell::replace[dN] = tTile::FIRE; } break;
            case tTile::WOOD: { if (chance < 100) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 100) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 50) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 100) tCell::replace[dN] = tTile::FIRE; } break;
            case tTile::DRY_LEAVES: { if (chance < 130) tCell::replace[dN] = tTile::FIRE; } break;
            case tTile::OLD_LEAVES: { if (chance < 160) tCell::replace[dN] = tTile::FIRE; } break;
            case tTile::DEAD_LEAVES: { if (chance < 200) tCell::replace[dN] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::WATER : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR:
                {
                    if (chance < 100) tCell::replace[dE] = tTile::FLARE;
                    if (chance < 5) tCell::replace[index] = tTile::SMOKE;
                    if (chance < 3) tCell::replace[index] = tTile::SPARK;
                    if (chance > 500) tCell::replace[index] = tTile::THIN_SMOKE;
                } break;
            case tTile::ASH : { tCell::replace[index] = tTile::THICK_SMOKE; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::THIN_SMOKE; } break;
            case tTile::CHARCOAL: { if (chance < 50) tCell::replace[dE] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 50) tCell::replace[dE] = tTile::CHARCOAL; } break;
            case tTile::OIL_FUMES: { if (chance < 250) tCell::replace[dE] = tTile::FIRE; } break;
            case tTile::WOOD: { if (chance < 25) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 25) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 50) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 50) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 100) tCell::replace[dE] = tTile::FIRE; } break;
            case tTile::DRY_LEAVES: { if (chance < 130) tCell::replace[dE] = tTile::FIRE; } break;
            case tTile::OLD_LEAVES: { if (chance < 160) tCell::replace[dE] = tTile::FIRE; } break;
            case tTile::DEAD_LEAVES: { if (chance < 200) tCell::replace[dE] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::WATER : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR:
                {
                    if (chance < 100) tCell::replace[dW] = tTile::FLARE;
                    if (chance < 5) tCell::replace[index] = tTile::SMOKE;
                    if (chance < 3) tCell::replace[index] = tTile::SPARK;
                    if (chance > 500) tCell::replace[index] = tTile::THIN_SMOKE;
                } break;
            case tTile::ASH : { tCell::replace[index] = tTile::THICK_SMOKE; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::THIN_SMOKE; } break;
            case tTile::CHARCOAL: { if (chance < 50) tCell::replace[dW] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 50) tCell::replace[dW] = tTile::CHARCOAL; } break;
            case tTile::OIL_FUMES: { if (chance < 250) tCell::replace[dW] = tTile::FIRE; } break;
            case tTile::WOOD: { if (chance < 25) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 25) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 50) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 50) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 100) tCell::replace[dW] = tTile::FIRE; } break;
            case tTile::DRY_LEAVES: { if (chance < 130) tCell::replace[dW] = tTile::FIRE; } break;
            case tTile::OLD_LEAVES: { if (chance < 160) tCell::replace[dW] = tTile::FIRE; } break;
            case tTile::DEAD_LEAVES: { if (chance < 200) tCell::replace[dW] = tTile::FIRE; } break;
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
            case tTile::ASH : { tCell::replace[index] = tTile::THICK_SMOKE; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::THIN_SMOKE; } break;
            case tTile::CHARCOAL : { if (chance < 500) tCell::replace[dN] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 250) tCell::replace[dN] = tTile::CHARCOAL; } break;
            case tTile::OIL_FUMES: { if (chance < 250) tCell::replace[dN] = tTile::FIRE; } break;
            case tTile::WOOD: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 500) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 500) tCell::replace[dN] = tTile::FIRE; } break;
            case tTile::DRY_LEAVES: { if (chance < 600) tCell::replace[dN] = tTile::FIRE; } break;
            case tTile::OLD_LEAVES: { if (chance < 700) tCell::replace[dN] = tTile::FIRE; } break;
            case tTile::DEAD_LEAVES: { if (chance < 750) tCell::replace[dN] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::WATER : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR: { tCell::replace[index] = tTile::FIRE; } break;
            case tTile::ASH : { tCell::replace[index] = tTile::THICK_SMOKE; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::THIN_SMOKE; } break;
            case tTile::CHARCOAL : { if (chance < 250) tCell::replace[dE] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 250) tCell::replace[dE] = tTile::CHARCOAL; } break;
            case tTile::OIL_FUMES: { if (chance < 250) tCell::replace[dE] = tTile::FIRE; } break;
            case tTile::WOOD: { if (chance < 100) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 100) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 250) tCell::replace[dE] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 500) tCell::replace[dE] = tTile::FIRE; } break;
            case tTile::DRY_LEAVES: { if (chance < 600) tCell::replace[dE] = tTile::FIRE; } break;
            case tTile::OLD_LEAVES: { if (chance < 700) tCell::replace[dE] = tTile::FIRE; } break;
            case tTile::DEAD_LEAVES: { if (chance < 750) tCell::replace[dE] = tTile::FIRE; } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::WATER : { tCell::replace[index] = tTile::AIR; } break;
            case tTile::AIR: { tCell::replace[index] = tTile::FIRE; } break;
            case tTile::ASH : { tCell::replace[index] = tTile::THICK_SMOKE; } break;
            case tTile::SMOKE : { tCell::replace[index] = tTile::THIN_SMOKE; } break;
            case tTile::CHARCOAL : { if (chance < 250) tCell::replace[dW] = tTile::EMBER; } break;
            case tTile::CHARRED_WOOD: { if (chance < 250) tCell::replace[dW] = tTile::CHARCOAL; } break;
            case tTile::OIL_FUMES: { if (chance < 250) tCell::replace[dW] = tTile::FIRE; } break;
            case tTile::WOOD: { if (chance < 100) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::TRUNK: { if (chance < 100) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::BRANCH: { if (chance < 250) tCell::replace[dW] = tTile::CHARRED_WOOD; } break;
            case tTile::STICK: { if (chance < 250) tCell::replace[dN] = tTile::CHARRED_WOOD; } break;
            case tTile::LEAVES: { if (chance < 500) tCell::replace[dW] = tTile::FIRE; } break;
            case tTile::DRY_LEAVES: { if (chance < 600) tCell::replace[dW] = tTile::FIRE; } break;
            case tTile::OLD_LEAVES: { if (chance < 700) tCell::replace[dW] = tTile::FIRE; } break;
            case tTile::DEAD_LEAVES: { if (chance < 750) tCell::replace[dW] = tTile::FIRE; } break;
        }
    }

    void Spark(int _x, int _y, int index, char season)
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
        else { if (rand() % 100 < 25) tCell::replace[index] = tTile::AIR; }
    }

    void Arc(int _x, int _y, int index, char season)
    {
        int dN   = int( (_y-1) * tCell::width + (_x  ) );
        int dS   = int( (_y+1) * tCell::width + (_x  ) );
        int dE   = int( (_y  ) * tCell::width + (_x+1) );
        int dW   = int( (_y  ) * tCell::width + (_x-1) );
        int dNN  = int( (_y-2) * tCell::width + (_x  ) );
        int dSS  = int( (_y+2) * tCell::width + (_x  ) );
        int dEE  = int( (_y  ) * tCell::width + (_x+2) );
        int dWW  = int( (_y  ) * tCell::width + (_x-2) );
        switch (tCell::matrix[dN])
        {
            case tTile::AIR : { if (rand()%10 < 1) tCell::replace[dN] = tTile::ARC; } break;
        }
        switch (tCell::matrix[dS])
        {
            case tTile::AIR : { if (rand()%10 < 1) tCell::replace[dS] = tTile::ARC; } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::AIR : { if (rand()%10 < 2) tCell::replace[dE] = tTile::ARC; } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::AIR : { if (rand()%10 < 2) tCell::replace[dW] = tTile::ARC; } break;
        }
        if (rand()%1000 < 750) { tCell::replace[index] = tTile::AIR; }
        if (tCell::matrix[dS] == tTile::AIR && rand()%1000 < 25) { tCell::replace[dS] = tTile::SPARK; }
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
                case tTile::SPARK : { Spark(_x, _y, index, season); } break;
                case tTile::ARC : { Arc(_x, _y, index, season); } break;
            }
    }

}
