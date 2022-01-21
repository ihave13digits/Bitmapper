namespace tGeo
{

    //
    // Special
    //

    void Caldera(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dNN = int( (_y-2) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dSS = int( (_y+2) * tCell::width + (_x  ) );
        int dE = int( (_y) * tCell::width + (_x+1) );
        int dW = int( (_y) * tCell::width + (_x-1) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        if (tCell::matrix[dSW] == tTile::CALDERA)
        {
            switch (tCell::matrix[dSE])
            {
                case tTile::LAVA :
                {
                    if (tCell::matrix[dN] == tTile::AIR && rand()%1000 < 25) tCell::replace[dN] = tTile::MAGMA;
                    if (tCell::matrix[dNW] == tTile::AIR && rand()%1000 < 25) tCell::replace[dNW] = tTile::MAGMA;
                } break;
                case tTile::MAGMA :
                {
                    if (tCell::matrix[dN] == tTile::AIR && rand()%1000 < 25) tCell::replace[dN] = tTile::LAVA;
                    if (tCell::matrix[dNW] == tTile::AIR && rand()%1000 < 25) tCell::replace[dNW] = tTile::LAVA;
                } break;
            }
        }
        if (tCell::matrix[dSE] == tTile::CALDERA)
        {
            switch (tCell::matrix[dSW])
            {
                case tTile::LAVA :
                {
                    if (tCell::matrix[dN] == tTile::AIR && rand()%1000 < 25) tCell::replace[dN] = tTile::MAGMA;
                    if (tCell::matrix[dNE] == tTile::AIR && rand()%1000 < 25) tCell::replace[dNE] = tTile::MAGMA;
                } break;
                case tTile::MAGMA :
                {
                    if (tCell::matrix[dN] == tTile::AIR && rand()%1000 < 25) tCell::replace[dN] = tTile::LAVA;
                    if (tCell::matrix[dNE] == tTile::AIR && rand()%1000 < 25) tCell::replace[dNE] = tTile::LAVA;
                } break;
            }
        }
        if (tCell::matrix[dN] == tTile::CALDERA && tCell::matrix[dNN] == tTile::CALDERA &&
            tCell::matrix[dS] == tTile::CALDERA && tCell::matrix[dSS] == tTile::CALDERA)
        {
            if (tCell::matrix[dSS+1] == tTile::CALDERA && tCell::matrix[dSS-1] == tTile::LAVA_ROCK) { tCell::replace[dSS-1] = tTile::VOLCANIC_ROCK; }
            else if (tCell::matrix[dSS+1] == tTile::LAVA_ROCK && tCell::matrix[dSS-1] == tTile::CALDERA) { tCell::replace[dSS+1] = tTile::VOLCANIC_ROCK; }
        }
    }

    void VolcanicRock(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE = int( (_y) * tCell::width + (_x+1) );
        int dW = int( (_y) * tCell::width + (_x-1) );
        if (tCell::matrix[dN] == tTile::VOLCANIC_ROCK && tCell::matrix[dS] == tTile::VOLCANIC_ROCK)
        {
            if (rand()%1000 < 25)
            {
                if (tCell::matrix[dE] == tTile::LAVA_ROCK) { tCell::replace[dE] = tTile::VOLCANIC_ROCK; }
                else if (tCell::matrix[dW] == tTile::LAVA_ROCK) { tCell::replace[dW] = tTile::VOLCANIC_ROCK; }
                else if (tCell::matrix[dS+1] == tTile::LAVA_ROCK) { tCell::replace[dS+1] = tTile::VOLCANIC_ROCK; }
                else if (tCell::matrix[dS-1] == tTile::LAVA_ROCK) { tCell::replace[dS-1] = tTile::VOLCANIC_ROCK; }
            }
        }
    }

    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell)
    {
        switch (current_cell)
        {
            case tTile::CALDERA       : {       Caldera(_x, _y, index); } break;
            case tTile::VOLCANIC_ROCK : {  VolcanicRock(_x, _y, index); } break;
        }
    }

}
