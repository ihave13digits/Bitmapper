namespace tLoose
{

    //
    // Special
    //
    
    void LooseDirt(int _x, int _y, int index)
    {
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        if (tCell::matrix[dS] == tTile::DIRT && rand()%100 < 25)
        {
            tCell::replace[index] = tTile:: DIRT;
            tCell::replace[dS] = tTile::LOOSE_DIRT;
        }
        else if (tCell::matrix[dS] == tTile::DIRT && rand()%1000 < 5)
        {
            tCell::replace[index] = tTile:: AIR;
            tCell::replace[dS] = tTile::LOOSE_DIRT;
        }
    }



    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell)
    {
        if (!tTool::FluidCollision(_x, _y+1))
        {
            int rplc = (_y+1)*tCell::width+(_x);            // ░░░░░░
            tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
            tCell::replace[index] = tTile::AIR;             // ░░██░░
        }

        switch (current_cell)
        {
            case tTile::LOOSE_DIRT : { LooseDirt(_x, _y, index); } break;
        }
    }

}
