namespace tCritter
{

    //
    // Special
    //

    void Frog(int _x, int _y, int index, char season)
    {
        bool can_do;
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int dSS = int( (_y+2) * tCell::width + (_x  ) );

        int chance = rand()%1000;
        if (tTool::GetType(tCell::matrix[dS]) == tTile::SOLID || tTool::GetType(tCell::matrix[dS]) == tTile::PLANT) can_do = true;
        switch (tCell::matrix[dS])
        {
            case tTile::FROG      : { can_do = true; } break;
            case tTile::TOAD      : { can_do = true; } break;
            case tTile::WATER     : { can_do = true; } break;
            case tTile::AIR       :
            {
                if (tCell::matrix[dNE+1] == tTile::FROG_LEGS) tCell::replace[dNE+1] = tTile::AIR;
                if (tCell::matrix[dSE+1] == tTile::FROG_LEGS) tCell::replace[dSE+1] = tTile::AIR;
                if (tCell::matrix[dNE] == tTile::FROG_LEGS) tCell::replace[dNE] = tTile::AIR;
                if (tCell::matrix[dSE] == tTile::FROG_LEGS) tCell::replace[dSE] = tTile::AIR;
                if (tCell::matrix[dE] == tTile::FROG_LEGS) tCell::replace[dE] = tTile::AIR;
                if (tCell::matrix[dE+1] == tTile::FROG_LEGS) tCell::replace[dE+1] = tTile::AIR;
                if (tCell::matrix[dNW+1] == tTile::FROG_LEGS) tCell::replace[dNW-1] = tTile::AIR;
                if (tCell::matrix[dSW+1] == tTile::FROG_LEGS) tCell::replace[dSW-1] = tTile::AIR;
                if (tCell::matrix[dNW] == tTile::FROG_LEGS) tCell::replace[dNW] = tTile::AIR;
                if (tCell::matrix[dSW] == tTile::FROG_LEGS) tCell::replace[dSW] = tTile::AIR;
                if (tCell::matrix[dW] == tTile::FROG_LEGS) tCell::replace[dW] = tTile::AIR;
                if (tCell::matrix[dW-1] == tTile::FROG_LEGS) tCell::replace[dW-1] = tTile::AIR;
                tCell::replace[index] = tTile::AIR;
                tCell::replace[dS] = tTile::FROG;
                can_do = false;
            } break;
            case tTile::FROG_LEGS :
            {
                if (tCell::matrix[dSS] != tTile::AIR && tCell::matrix[dSS] != tTile::FROG_LEGS)
                {
                    tCell::replace[index] = tTile::FROG_LEGS;
                    tCell::replace[dN] = tTile::FROG;
                }
                else
                {
                    int direction = rand()%1000;
                    tCell::replace[index] = tTile::AIR;

                    if (direction > 500)
                    {
                        if (tCell::matrix[dE+1] == tTile::AIR && tCell::matrix[dE] == tTile::AIR)
                        {
                            tCell::replace[dE+1] = tTile::FROG;
                            if (tCell::matrix[dS] == tTile::FROG_LEGS) tCell::replace[dS] = tTile::AIR;
                            if (tCell::matrix[dS+1] == tTile::AIR) tCell::replace[dS+1] = tTile::FROG_LEGS;
                        }
                        else if (tCell::matrix[dE] == tTile::AIR) tCell::replace[dE] = tTile::FROG;
                    }
                    if (direction < 500)
                    {
                        if (tCell::matrix[dW-1] == tTile::AIR && tCell::matrix[dW] == tTile::AIR)
                        {
                            tCell::replace[dW-1] = tTile::FROG;
                            if (tCell::matrix[dS] == tTile::FROG_LEGS) tCell::replace[dS] = tTile::AIR;
                            if (tCell::matrix[dS-1] == tTile::AIR) tCell::replace[dS-1] = tTile::FROG_LEGS;
                        }
                        else if (tCell::matrix[dW] == tTile::AIR) tCell::replace[dW] = tTile::FROG;
                    }
                }
                can_do = false;
            } break;
        }
        if (tCell::matrix[dSS] == tTile::FROG_LEGS) tCell::replace[dSS] = tTile::AIR;
        if (can_do && chance < 25)
        {
            int direction = rand()%1000;
            if (direction > 25 && direction < 975 && tCell::matrix[dN] == tTile::AIR) { tCell::replace[index] = tTile::FROG_LEGS; tCell::replace[dN] = tTile::FROG; }
            if (direction < 25 && tCell::matrix[dNE] == tTile::AIR) { tCell::replace[index] = tTile::FROG_LEGS; tCell::replace[dNE] = tTile::FROG; }
            if (direction > 975 && tCell::matrix[dNW] == tTile::AIR) { tCell::replace[index] = tTile::FROG_LEGS; tCell::replace[dNW] = tTile::FROG; }
        }
    }

    void Toad(int _x, int _y, int index, char season)
    {
        bool can_do;
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int dSS = int( (_y+2) * tCell::width + (_x  ) );

        int chance = rand()%1000;
        if (tTool::GetType(tCell::matrix[dS]) == tTile::SOLID || tTool::GetType(tCell::matrix[dS]) == tTile::PLANT) can_do = true;
        switch (tCell::matrix[dS])
        {
            case tTile::FROG      : { can_do = true; } break;
            case tTile::TOAD     : { can_do = true; } break;
            case tTile::WATER     : { can_do = true; } break;
            case tTile::AIR       :
            {
                if (tCell::matrix[dNE] == tTile::TOAD_LEGS) tCell::replace[dNE] = tTile::AIR;
                if (tCell::matrix[dSE] == tTile::TOAD_LEGS) tCell::replace[dSE] = tTile::AIR;
                if (tCell::matrix[dE] == tTile::TOAD_LEGS) tCell::replace[dE] = tTile::AIR;
                if (tCell::matrix[dW] == tTile::TOAD_LEGS) tCell::replace[dW] = tTile::AIR;
                if (tCell::matrix[dSW] == tTile::TOAD_LEGS) tCell::replace[dSW] = tTile::AIR;
                if (tCell::matrix[dNW] == tTile::TOAD_LEGS) tCell::replace[dNW] = tTile::AIR;
                tCell::replace[index] = tTile::AIR;
                tCell::replace[dS] = tTile::TOAD;
                can_do = false;
            } break;
            case tTile::TOAD_LEGS :
            {
                if (tCell::matrix[dSS] != tTile::AIR && tCell::matrix[dSS] != tTile::TOAD_LEGS)
                {
                    tCell::replace[index] = tTile::TOAD_LEGS;
                    tCell::replace[dN] = tTile::TOAD;
                }
                else
                {
                    int direction = rand()%1000;
                    tCell::replace[index] = tTile::AIR;
                    if (direction > 500 && tCell::matrix[dE] == tTile::AIR) tCell::replace[dE] = tTile::TOAD;
                    if (direction < 500 && tCell::matrix[dW] == tTile::AIR) tCell::replace[dW] = tTile::TOAD;
                }
                can_do = false;
            } break;
        }
        if (tCell::matrix[dSS] == tTile::TOAD_LEGS) tCell::replace[dSS] = tTile::AIR;
        if (can_do && chance < 25)
        {
            int direction = rand()%1000;
            if (direction > 25 && direction < 975 && tCell::matrix[dN] == tTile::AIR) { tCell::replace[index] = tTile::TOAD_LEGS; tCell::replace[dN] = tTile::TOAD; }
            if (direction < 25 && tCell::matrix[dNE] == tTile::AIR) { tCell::replace[index] = tTile::TOAD_LEGS; tCell::replace[dNE] = tTile::TOAD; }
            if (direction > 975 && tCell::matrix[dNW] == tTile::AIR) { tCell::replace[index] = tTile::TOAD_LEGS; tCell::replace[dNW] = tTile::TOAD; }
        }
    }

    void Mole(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        int chance = rand()%1000;
        int altitude = rand()%100;
        int direction = rand()%100;

        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::MOLE; }
        
        else if (
                (tCell::matrix[dE] == tTile::GRASS || tCell::matrix[dW] == tTile::GRASS) &&
                (tCell::matrix[dS] == tTile::GRASS))
        { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::MOLE; }
        else if (
                (tCell::matrix[dE] == tTile::AIR || tCell::matrix[dW] == tTile::AIR) &&
                (tCell::matrix[dS] == tTile::GRASS))
        { tCell::replace[index] = tTile::DIRT; tCell::replace[dS] = tTile::MOLE; }
        
        if (chance < 25)
        {
            if (direction < 25)
            {
                if (tCell::matrix[dE] == tTile::DIRT) { tCell::replace[index] = tTile::LOOSE_DIRT; tCell::replace[dE] = tTile::MOLE; }
                else if (tCell::matrix[dE] == tTile::SOIL) { tCell::replace[index] = tTile::SOIL; tCell::replace[dE] = tTile::MOLE; }
                else if (tCell::matrix[dE] == tTile::ROOT) { tCell::replace[index] = tTile::LOOSE_DIRT; tCell::replace[dE] = tTile::MOLE; }
                else if (tCell::matrix[dE] == tTile::TAPROOT) { tCell::replace[index] = tTile::LOOSE_DIRT; tCell::replace[dE] = tTile::MOLE; }
            }
            if (direction > 75)
            {
                if (tCell::matrix[dW] == tTile::DIRT) { tCell::replace[index] = tTile::LOOSE_DIRT; tCell::replace[dW] = tTile::MOLE; }
                else if (tCell::matrix[dW] == tTile::SOIL) { tCell::replace[index] = tTile::SOIL; tCell::replace[dW] = tTile::MOLE; }
                else if (tCell::matrix[dW] == tTile::ROOT) { tCell::replace[index] = tTile::LOOSE_DIRT; tCell::replace[dW] = tTile::MOLE; }
                else if (tCell::matrix[dE] == tTile::TAPROOT) { tCell::replace[index] = tTile::LOOSE_DIRT; tCell::replace[dE] = tTile::MOLE; }
            }
        }
        else if (chance < 5)
        {
            if (altitude > 75)
            {
                if (tCell::matrix[dN] == tTile::DIRT) { tCell::replace[index] = tTile::LOOSE_DIRT; tCell::replace[dN] = tTile::MOLE; }
                else if (tCell::matrix[dN] == tTile::SOIL) { tCell::replace[index] = tTile::SOIL; tCell::replace[dN] = tTile::MOLE; }
                else if (tCell::matrix[dN] == tTile::ROOT) { tCell::replace[index] = tTile::LOOSE_DIRT; tCell::replace[dN] = tTile::MOLE; }
                else if (tCell::matrix[dN] == tTile::TAPROOT) { tCell::replace[index] = tTile::LOOSE_DIRT; tCell::replace[dN] = tTile::MOLE; }
            }
            if (altitude < 25)
            {
                if (tCell::matrix[dS] == tTile::DIRT) { tCell::replace[index] = tTile::LOOSE_DIRT; tCell::replace[dS] = tTile::MOLE; }
                else if (tCell::matrix[dS] == tTile::SOIL) { tCell::replace[index] = tTile::SOIL; tCell::replace[dS] = tTile::MOLE; }
                else if (tCell::matrix[dS] == tTile::ROOT) { tCell::replace[index] = tTile::LOOSE_DIRT; tCell::replace[dS] = tTile::MOLE; }
                else if (tCell::matrix[dS] == tTile::TAPROOT) { tCell::replace[index] = tTile::LOOSE_DIRT; tCell::replace[dS] = tTile::MOLE; }
            }
        }

    }



    //
    // Generic
    //
    
    void Update(int _x, int _y, int index, int current_cell, char season=0)
    {
        switch (current_cell)
        {
            case tTile::MOLE : { Mole(_x, _y, index, season); } break;
            case tTile::TOAD : { Toad(_x, _y, index, season); } break;
            case tTile::FROG : { Frog(_x, _y, index, season); } break;
        }
    }

}
