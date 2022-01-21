namespace tMetal
{

    //
    // Special
    //

    void Uranium(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        if (tCell::matrix[dN] == tTile::AIR)
        {
            if (rand()%1000<10) { tCell::replace[dN]=tTile::RADON;
            if (rand()%1000<10) { tCell::replace[index]=tTile::URANIUM_ORE; } }
        }
        if (tCell::matrix[dS] == tTile::AIR)
        {
            if (rand()%1000<10) { tCell::replace[dS]=tTile::RADON;
            if (rand()%1000<10) { tCell::replace[index]=tTile::URANIUM_ORE; } }
        }
        if (tCell::matrix[dE] == tTile::AIR)
        {
            if (rand()%1000<10) { tCell::replace[dE]=tTile::RADON;
            if (rand()%1000<10) { tCell::replace[index]=tTile::URANIUM_ORE; } }
        }
        if (tCell::matrix[dW] == tTile::AIR)
        {
            if (rand()%1000<10) { tCell::replace[dW]=tTile::RADON;
            if (rand()%1000<10) { tCell::replace[index]=tTile::URANIUM_ORE; } }
        }
    }

    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell)
    {
        switch (current_cell)
        {
            case tTile::URANIUM : { Uranium(_x, _y, index); } break;
        }
    }

}
