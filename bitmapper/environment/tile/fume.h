namespace tFume
{
    
    //
    // Special
    //
    
    void Fog(int _x, int _y, int index, int current_cell, char season=0)
    {
        int dS = int( (_y+1) * tCell::width + (_x  ) );
        if (tCell::matrix[dS] == tTile::GRASS && rand()%1000 < 25) { tCell::replace[index] = tTile::AIR; }
    }

    void OilFumes(int _x, int _y, int index, char season)
    {
        int dO  = int( (_y+3) * tCell::width + (_x  ) );
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE = int( (_y) * tCell::width + (_x+1) );
        int dW = int( (_y) * tCell::width + (_x-1) );
        if (tCell::matrix[dN] == tTile::AIR && tCell::matrix[dO] == tTile::OIL &&
            (tCell::matrix[dE] == tTile::OIL_FUMES || tCell::matrix[dW] == tTile::OIL_FUMES))
        { if (rand()%1000 < 25) tCell::replace[dN] = tTile::OIL_FUMES; }
    }
    
    
    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell, char season=0)
    {
        int cell_type = tTool::GetType(current_cell);
        int direction = rand() % 100;

        if (direction < 50)
        {
            if (!tTool::Collision(_x, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░██░░
            }
            else if (!tTool::Collision(_x-1, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x-1);          // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ██░░░░
            }
            else if (!tTool::Collision(_x+1, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x+1);          // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░██
            }
            else if (!tTool::Collision(_x-2, _y) && !tTool::Collision(_x-1, _y))
            {
                int rplc = (_y)*tCell::width+(_x-2);            // ░░░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ██░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░░░
            }
            else if (!tTool::Collision(_x+2, _y) && !tTool::Collision(_x+1, _y))
            {
                int rplc = (_y)*tCell::width+(_x+2);            // ░░░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░██
                tCell::replace[index] = tTile::AIR;             // ░░░░░░░░
            }
            else if (!tTool::Collision(_x-1, _y) && tTool::Collision(_x+1, _y))
            {
                int rplc = (_y)*tCell::width+(_x-1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ██▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
            else if (!tTool::Collision(_x+1, _y) && tTool::Collision(_x-1, _y))
            {
                int rplc = (_y)*tCell::width+(_x+1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓██
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
        }
        else
        {
            if (!tTool::Collision(_x, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░██░░
            }
            else if (!tTool::Collision(_x+1, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x+1);          // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░██
            }
            else if (!tTool::Collision(_x-1, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x-1);          // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ██░░░░
            }
            else if (!tTool::Collision(_x+2, _y) && !tTool::Collision(_x+1, _y))
            {
                int rplc = (_y)*tCell::width+(_x+2);            // ░░░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░██
                tCell::replace[index] = tTile::AIR;             // ░░░░░░░░
            }
            else if (!tTool::Collision(_x-2, _y) && !tTool::Collision(_x-1, _y))
            {
                int rplc = (_y)*tCell::width+(_x-2);            // ░░░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ██░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░░░
            }
            else if (!tTool::Collision(_x+1, _y) && tTool::Collision(_x-1, _y))
            {
                int rplc = (_y)*tCell::width+(_x+1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓██
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
            else if (!tTool::Collision(_x-1, _y) && tTool::Collision(_x+1, _y))
            {
                int rplc = (_y)*tCell::width+(_x-1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ██▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
        }
        


        switch (current_cell)
            {
                case tTile::FOG       : {      Fog(_x, _y, index, season); } break;
                case tTile::OIL_FUMES : { OilFumes(_x, _y, index, season); } break;
            }

    }

}
