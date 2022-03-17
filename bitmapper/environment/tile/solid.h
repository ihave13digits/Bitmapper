namespace tSolid
{

    //
    // Special
    //

    void Ice(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        if ((tCell::matrix[dN] == tTile::LAVA) ||
            (tCell::matrix[dS] == tTile::LAVA) ||
            (tCell::matrix[dE] == tTile::LAVA) ||
            (tCell::matrix[dW] == tTile::LAVA) ||
            (tCell::matrix[dN] == tTile::EMBER) ||
            (tCell::matrix[dS] == tTile::EMBER) ||
            (tCell::matrix[dE] == tTile::EMBER) ||
            (tCell::matrix[dW] == tTile::EMBER) ||
            (tCell::matrix[dN] == tTile::FIRE) ||
            (tCell::matrix[dS] == tTile::FIRE) ||
            (tCell::matrix[dE] == tTile::FIRE) ||
            (tCell::matrix[dW] == tTile::FIRE) ||
            (tCell::matrix[dN] == tTile::FLAME) ||
            (tCell::matrix[dS] == tTile::FLAME) ||
            (tCell::matrix[dE] == tTile::FLAME) ||
            (tCell::matrix[dW] == tTile::FLAME)) { tCell::replace[index] = tTile::WATER; }
        else if (tCell::matrix[dS] == tTile::GRASS) { tCell::replace[index] = tTile::WATER; }
        else if (tCell::matrix[dN] != tTile::ICE ||
            tCell::matrix[dS] != tTile::ICE ||
            tCell::matrix[dE] != tTile::ICE ||
            tCell::matrix[dW] != tTile::ICE)
        {
            int melt = 0;
            switch (tCell::season)
            {
                case seasonID::EARLY_SPRING : { melt = 10; } break;
                case seasonID::SPRING       : { melt = 20; } break;
                case seasonID::LATE_SPRING  : { melt = 30; } break;
                case seasonID::EARLY_SUMMER : { melt = 40; } break;
                case seasonID::SUMMER       : { melt = 50; } break;
                case seasonID::LATE_SUMMER  : { melt = 40; } break;
                case seasonID::EARLY_AUTUMN : { melt = 30; } break;
                case seasonID::AUTUMN       : { melt = 20; } break;
                case seasonID::LATE_AUTUMN  : { melt = 10; } break;
            }
            if (rand()%1000 < melt) tCell::replace[index] = tTile::WATER;
        }
    }

    void DampDirt(int _x, int _y, int index)
    {
        uint8_t n = 0;
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        if (tCell::matrix[dN] == tTile::AIR) { n++; }
        if (tCell::matrix[dS] == tTile::AIR) { n++; }
        if (tCell::matrix[dE] == tTile::AIR) { n++; }
        if (tCell::matrix[dW] == tTile::AIR) { n++; }

        if (n > 0) { if (rand()%(2000*n) < 5) tCell::replace[index] = tTile::DIRT; }
    }

    void DampSoil(int _x, int _y, int index)
    {
        uint8_t n = 0;
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        if (tCell::matrix[dN] == tTile::AIR) { n++; }
        if (tCell::matrix[dS] == tTile::AIR) { n++; }
        if (tCell::matrix[dE] == tTile::AIR) { n++; }
        if (tCell::matrix[dW] == tTile::AIR) { n++; }

        if (n > 0) { if (rand()%(2000*n) < 5) tCell::replace[index] = tTile::SOIL; }
    }

    void LavaRock(int _x, int _y, int index)
    {
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::LAVA_ROCK; }
        if (tCell::matrix[dS] == tTile::CALDERA) { if (rand()%1000 <   5) tCell::replace[index] = tTile::CALDERA; }
        if (tCell::matrix[dE] == tTile::CALDERA) { if (rand()%10000 < 25) tCell::replace[index] = tTile::LAVA; }
        if (tCell::matrix[dW] == tTile::CALDERA) { if (rand()%10000 < 25) tCell::replace[index] = tTile::LAVA; }
        if (tCell::matrix[dS] == tTile::LAVA && tCell::matrix[dE] == tTile::LAVA && tCell::matrix[dW] == tTile::LAVA)
        { if (rand()%10000 < 25) tCell::replace[index] = tTile::LAVA; }
        if (tCell::matrix[dS] == tTile::MAGMA) { if (rand()%10000 < 50) tCell::replace[index] = tTile::LAVA; }
    }



    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell)
    {
        switch (current_cell)
        {
            case tTile::DAMP_DIRT : { DampDirt(_x, _y, index); } break;
            case tTile::DAMP_SOIL : { DampSoil(_x, _y, index); } break;
            case tTile::ICE       : {      Ice(_x, _y, index); } break;
            case tTile::LAVA_ROCK : { LavaRock(_x, _y, index); } break;
        }
    }

}
