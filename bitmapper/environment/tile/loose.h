namespace tLoose
{

    //
    // Special
    //
    
    void LooseDirt(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        if (tCell::matrix[dN] == tTile::DIRT && rand()%100 < 25)
        {
            tCell::replace[index] = tTile:: DIRT;
            tCell::replace[dN] = tTile::LOOSE_DIRT;
        }
        if (tCell::matrix[dN] == tTile::LOOSE_DIRT && rand()%100 < 5)
        {
            tCell::replace[index] = tTile::LOOSE_DIRT;
            tCell::replace[dN] = tTile::AIR;
        }
    }



    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell, char season=0)
    {
        if (!tTool::FluidCollision(_x, _y+1))
        {
            int rplc = (_y+1)*tCell::width+(_x);            // ░░░░░░
            tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
            tCell::replace[index] = tTile::AIR;             // ░░██░░
        }

        switch (current_cell)
        {
            case tTile::LOOSE_DIRT : { LooseDirt(_x, _y, index, season); } break;
        }
    }

}
