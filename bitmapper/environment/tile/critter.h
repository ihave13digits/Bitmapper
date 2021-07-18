namespace tCritter
{

    //
    // Special
    //

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

        int chance = rand()%100;
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
        
        if (chance < 50)
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
        }
    }

}
