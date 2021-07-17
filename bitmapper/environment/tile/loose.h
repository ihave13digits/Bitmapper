namespace tLoose
{

    //
    // Special
    //
    
    void LooseDirt(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        if (tCell::matrix[dN] == tTile::DIRT)
        {
            tCell::replace[index] = tTile:: DIRT;
            tCell::replace[dN] = tTile:: LOOSE_DIRT;
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
