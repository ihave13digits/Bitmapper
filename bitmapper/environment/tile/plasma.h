namespace tPlasma
{

    //
    // Special
    //

    void Fire(int _x, int _y, int index)
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

    void Flame(int _x, int _y, int index)
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

    void Flare(int _x, int _y, int index)
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

    void Spark(int _x, int _y, int index)
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

    void Arc(int _x, int _y, int index)
    {
        int dN   = int( (_y-1) * tCell::width + (_x  ) );
        int dS   = int( (_y+1) * tCell::width + (_x  ) );
        int dE   = int( (_y  ) * tCell::width + (_x+1) );
        int dW   = int( (_y  ) * tCell::width + (_x-1) );
        int dNN  = int( (_y-2) * tCell::width + (_x  ) );
        int dSS  = int( (_y+2) * tCell::width + (_x  ) );
        int dEE  = int( (_y  ) * tCell::width + (_x+2) );
        int dWW  = int( (_y  ) * tCell::width + (_x-2) );
        uint8_t n = 0;
        if      (tCell::matrix[dNN] == tTile::AIR && tCell::matrix[dN] == tTile::AIR && tCell::matrix[dS] == tTile::ARC)
        { if (rand()%1000 < 300) { tCell::replace[dN] = tTile::ARC; if (rand()%100 < 80) tCell::replace[dNN] = tTile::ARC; } }
        else if      (tCell::matrix[dN] == tTile::AIR && tCell::matrix[dS] == tTile::ARC)
        { if (rand()%1000 < 400) tCell::replace[dN] = tTile::ARC; }

        if (tCell::matrix[dSS] == tTile::AIR && tCell::matrix[dS] == tTile::AIR && tCell::matrix[dN] == tTile::ARC)
        { if (rand()%1000 < 300) { tCell::replace[dS] = tTile::ARC; if (rand()%100 < 80) tCell::replace[dSS] = tTile::ARC; } }
        else if      (tCell::matrix[dS] == tTile::AIR && tCell::matrix[dN] == tTile::ARC)
        { if (rand()%1000 < 400) tCell::replace[dS] = tTile::ARC; }

        if (tCell::matrix[dEE] == tTile::AIR && tCell::matrix[dE] == tTile::AIR && tCell::matrix[dW] == tTile::ARC)
        { if (rand()%1000 < 300) { tCell::replace[dE] = tTile::ARC; if (rand()%100 < 80) tCell::replace[dEE] = tTile::ARC; } }
        else if      (tCell::matrix[dE] == tTile::AIR && tCell::matrix[dW] == tTile::ARC)
        { if (rand()%1000 < 400) tCell::replace[dE] = tTile::ARC; }

        if (tCell::matrix[dWW] == tTile::AIR && tCell::matrix[dW] == tTile::AIR && tCell::matrix[dE] == tTile::ARC)
        { if (rand()%1000 < 300) { tCell::replace[dW] = tTile::ARC; if (rand()%100 < 80) tCell::replace[dWW] = tTile::ARC; } }
        else if      (tCell::matrix[dW] == tTile::AIR && tCell::matrix[dE] == tTile::ARC)
        { if (rand()%1000 < 400) tCell::replace[dW] = tTile::ARC; }

        if      (tTool::GetType(tCell::matrix[dN]) != tTile::GAS && tTool::GetType(tCell::matrix[dN]) != tTile::PLASMA)
        { tCell::replace[index] = tTile::SPARK; }
        else if (tTool::GetType(tCell::matrix[dS]) != tTile::GAS && tTool::GetType(tCell::matrix[dS]) != tTile::PLASMA)
        { tCell::replace[index] = tTile::SPARK; }
        else if (tTool::GetType(tCell::matrix[dE]) != tTile::GAS && tTool::GetType(tCell::matrix[dE]) != tTile::PLASMA)
        { tCell::replace[index] = tTile::SPARK; }
        else if (tTool::GetType(tCell::matrix[dW]) != tTile::GAS && tTool::GetType(tCell::matrix[dW]) != tTile::PLASMA)
        { tCell::replace[index] = tTile::SPARK; }
        
        if (rand()%1000 < 500) { tCell::replace[index] = tTile::AIR; }
    }



    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell)
    {
        switch (current_cell)
            {
                case tTile::FIRE : { Fire(_x, _y, index); } break;
                case tTile::FLAME : { Flame(_x, _y, index); } break;
                case tTile::FLARE : { Flare(_x, _y, index); } break;
                case tTile::SPARK : { Spark(_x, _y, index); } break;
                case tTile::ARC : { Arc(_x, _y, index); } break;
            }
    }

}
