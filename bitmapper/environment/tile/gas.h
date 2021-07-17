namespace tGas

{

    //
    // Special
    //

    void Steam(int _x, int _y, int index, char season)
    {
    }

    void ThinSmoke(int _x, int _y, int index, char season)
    {
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );

        int chance = rand()%100;
        switch (tCell::matrix[dS])
        {
            case tTile::AIR         : {                            tCell::matrix[index] = tTile::AIR; tCell::replace[index] = tTile::AIR;        } break;
            case tTile::SMOKE       : { if (rand()%10 < 6)  { tCell::replace[dS] = tTile::THIN_SMOKE; tCell::replace[index] = tTile::AIR;        } } break;
            case tTile::THICK_SMOKE : { if (rand()%100 < 4) { tCell::replace[dS] = tTile::THIN_SMOKE; tCell::replace[index] = tTile::THIN_SMOKE; } } break;
        }
        if (chance < 25)
        {
            switch (tCell::matrix[dE])
            {
                case tTile::AIR         : { tCell::replace[dE] = tTile::THIN_SMOKE; tCell::replace[index] = tTile::AIR;         } break;
                case tTile::SMOKE       : { tCell::replace[dE] = tTile::THIN_SMOKE; tCell::replace[index] = tTile::SMOKE;       } break;
                case tTile::THICK_SMOKE : { tCell::replace[dE] = tTile::THIN_SMOKE; tCell::replace[index] = tTile::THICK_SMOKE; } break;
            }
        }
        if (chance > 75)
        {
            switch (tCell::matrix[dW])
            {
                case tTile::AIR         : { tCell::replace[dW] = tTile::THIN_SMOKE; tCell::replace[index] = tTile::AIR;         } break;
                case tTile::SMOKE       : { tCell::replace[dW] = tTile::THIN_SMOKE; tCell::replace[index] = tTile::SMOKE;       } break;
                case tTile::THICK_SMOKE : { tCell::replace[dW] = tTile::THIN_SMOKE; tCell::replace[index] = tTile::THICK_SMOKE; } break;
            }
        }
    }

    void Smoke(int _x, int _y, int index, char season)
    {
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );

        int chance = rand()%100;
        switch (tCell::matrix[dS])
        {
            case tTile::AIR         : {                tCell::matrix[index] = tTile::THIN_SMOKE; tCell::replace[index] = tTile::THIN_SMOKE; } break;
            case tTile::THIN_SMOKE  : { if (rand()%10 < 6)  { tCell::replace[dS] = tTile::SMOKE; tCell::replace[index] = tTile::THIN_SMOKE; } } break;
            case tTile::THICK_SMOKE : { if (rand()%100 < 4) { tCell::replace[dS] = tTile::SMOKE; tCell::replace[index] = tTile::SMOKE;      } } break;
        }
        if (chance < 25)
        {
            switch (tCell::matrix[dE])
            {
                case tTile::AIR         : { tCell::replace[dE] = tTile::SMOKE; tCell::replace[index] = tTile::AIR;         } break;
                case tTile::THIN_SMOKE  : { tCell::replace[dE] = tTile::SMOKE; tCell::replace[index] = tTile::THIN_SMOKE;  } break;
                case tTile::THICK_SMOKE : { tCell::replace[dE] = tTile::SMOKE; tCell::replace[index] = tTile::THICK_SMOKE; } break;
            }
        }
        if (chance > 75)
        {
            switch (tCell::matrix[dW])
            {
                case tTile::AIR         : { tCell::replace[dW] = tTile::SMOKE; tCell::replace[index] = tTile::AIR;         } break;
                case tTile::THIN_SMOKE  : { tCell::replace[dW] = tTile::SMOKE; tCell::replace[index] = tTile::THIN_SMOKE;  } break;
                case tTile::THICK_SMOKE : { tCell::replace[dW] = tTile::SMOKE; tCell::replace[index] = tTile::THICK_SMOKE; } break;
            }
        }
    }

    void ThickSmoke(int _x, int _y, int index, char season)
    {
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );

        int chance = rand()%100;
        switch (tCell::matrix[dS])
        {
            case tTile::AIR        : {                     tCell::matrix[index] = tTile::THIN_SMOKE;  tCell::replace[index] = tTile::THIN_SMOKE; } break;
            case tTile::THIN_SMOKE : { if (rand()%10 < 6)  { tCell::replace[dS] = tTile::THICK_SMOKE; tCell::replace[index] = tTile::THIN_SMOKE; } } break;
            case tTile::SMOKE      : { if (rand()%100 < 4) { tCell::replace[dS] = tTile::THICK_SMOKE; tCell::replace[index] = tTile::SMOKE;      } } break;
        }
        if (chance < 25)
        {
            switch (tCell::matrix[dE])
            {
                case tTile::AIR        : { tCell::replace[dE] = tTile::THICK_SMOKE; tCell::replace[index] = tTile::AIR;        } break;
                case tTile::THIN_SMOKE : { tCell::replace[dE] = tTile::THICK_SMOKE; tCell::replace[index] = tTile::THIN_SMOKE; } break;
                case tTile::SMOKE      : { tCell::replace[dE] = tTile::THICK_SMOKE; tCell::replace[index] = tTile::SMOKE;      } break;
            }
        }
        if (chance > 75)
        {
            switch (tCell::matrix[dW])
            {
                case tTile::AIR        : { tCell::replace[dW] = tTile::THICK_SMOKE; tCell::replace[index] = tTile::AIR;        } break;
                case tTile::THIN_SMOKE : { tCell::replace[dW] = tTile::THICK_SMOKE; tCell::replace[index] = tTile::THIN_SMOKE; } break;
                case tTile::SMOKE      : { tCell::replace[dW] = tTile::THICK_SMOKE; tCell::replace[index] = tTile::SMOKE;      } break;
            }
        }
    }



    //
    // Generic
    //
    
    void Update(int _x, int _y, int index, int current_cell, char season=0)
    {
        int direction = rand() % 100;
        if (direction < 50)
        {
            if (!tTool::DualCollision(_x, _y-1))
            {
                int rplc = (_y-1)*tCell::width+(_x);            // ░░██░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
            else if (!tTool::DualCollision(_x-1, _y-1))
            {
                int rplc = (_y-1)*tCell::width+(_x-1);          // ██░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
            else if (!tTool::DualCollision(_x+1, _y-1))
            {
                int rplc = (_y-1)*tCell::width+(_x+1);          // ░░░░██
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
            else if (!tTool::DualCollision(_x-1, _y) && tTool::DualCollision(_x+1, _y))
            {
                int rplc = (_y)*tCell::width+(_x-1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ██▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
            else if (!tTool::DualCollision(_x+1, _y) && tTool::DualCollision(_x-1, _y))
            {
                int rplc = (_y)*tCell::width+(_x+1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓██
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
        }
        else
        {
            if (!tTool::DualCollision(_x, _y-1))
            {
                int rplc = (_y-1)*tCell::width+(_x);            // ░░██░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
            else if (!tTool::DualCollision(_x+1, _y-1))
            {
                int rplc = (_y-1)*tCell::width+(_x+1);          // ░░░░██
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
            else if (!tTool::DualCollision(_x-1, _y-1))
            {
                int rplc = (_y-1)*tCell::width+(_x-1);          // ██░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
            else if (!tTool::DualCollision(_x+1, _y) && tTool::DualCollision(_x-1, _y))
            {
                int rplc = (_y)*tCell::width+(_x+1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓██
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
            else if (!tTool::DualCollision(_x-1, _y) && tTool::DualCollision(_x+1, _y))
            {
                int rplc = (_y)*tCell::width+(_x-1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ██▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
        }

        switch (current_cell)
            {
                case tTile::STEAM : { Steam(_x, _y, index, season); } break;
                case tTile::THIN_SMOKE : { ThinSmoke(_x, _y, index, season); } break;
                case tTile::SMOKE : { Smoke(_x, _y, index, season); } break;
                case tTile::THICK_SMOKE : { ThickSmoke(_x, _y, index, season); } break;
            }
    }

}
