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
        if (rand()%1000 < 5) { tCell::replace[index] = tTile::WATER; }
    }



    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell, char season=0)
    {
        switch (current_cell)
        {
            case tTile::ICE : { Ice(_x, _y, index, season); } break;
        }
    }

}
