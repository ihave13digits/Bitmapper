namespace tSolid
{

    //
    // Special
    //

    void Ice(int _x, int _y, int index, char season)
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
        if (tCell::matrix[dS] == tTile::GRASS) { tCell::replace[index] = tTile::WATER; }
        if (tCell::matrix[dN] == tTile::AIR ||
            tCell::matrix[dS] == tTile::AIR ||
            tCell::matrix[dE] == tTile::AIR ||
            tCell::matrix[dW] == tTile::AIR)
        {
            switch (season)
            {
                case seasonID::SPRING : { if (rand()%10000 < 5) tCell::replace[index] = tTile::WATER; } break;
                case seasonID::SUMMER : { if (rand()%1000 < 5) tCell::replace[index] = tTile::WATER; } break;
                case seasonID::AUTUMN : { if (rand()%100000 < 5) tCell::replace[index] = tTile::WATER; } break;
            }
        }
    }



    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell, char season=tCell::season)
    {
        switch (current_cell)
        {
            case tTile::ICE : { Ice(_x, _y, index, season); } break;
        }
    }

}
