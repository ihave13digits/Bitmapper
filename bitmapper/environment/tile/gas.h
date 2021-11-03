namespace tGas

{

    //
    // Special
    //

    void Steam(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );

        if (tTile::TYPE[tCell::matrix[dN]] == tTile::SOLID && tCell::matrix[dS] == tTile::STEAM)
        { if (rand()%1000 < 10) tCell::replace[index] = tTile::WATER; }
    }

    void ThinSmoke(int _x, int _y, int index, char season)
    {
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int chance = rand()%100;
        if (chance < 20) { tCell::replace[index] = tTile::AIR; }
        else if (chance < 40) { if (tCell::matrix[dE] == tTile::AIR) tTool::Swap(index, dE); }
        else if (chance > 60) { if (tCell::matrix[dW] == tTile::AIR) tTool::Swap(index, dW); }
        else if (chance > 80) { tCell::replace[index] = tTile::AIR; }
    }

    void Smoke(int _x, int _y, int index, char season)
    {
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int chance = rand()%100;
        if (chance < 20) { tCell::replace[index] = tTile::THIN_SMOKE; }
        else if (chance < 40) { if (tCell::matrix[dE] == tTile::AIR) tTool::Swap(index, dE); }
        else if (chance > 60) { if (tCell::matrix[dW] == tTile::AIR) tTool::Swap(index, dW); }
        else if (chance > 80) { tCell::replace[index] = tTile::THIN_SMOKE; }
    }

    void ThickSmoke(int _x, int _y, int index, char season)
    {
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int chance = rand()%100;
        if (chance < 20) { tCell::replace[index] = tTile::SMOKE; }
        else if (chance < 40) { if (tCell::matrix[dE] == tTile::AIR) tTool::Swap(index, dE); }
        else if (chance > 60) { if (tCell::matrix[dW] == tTile::AIR) tTool::Swap(index, dW); }
        else if (chance > 80) { tCell::replace[index] = tTile::SMOKE; }
    }



    //
    // Generic
    //
    
    void Update(int _x, int _y, int index, int current_cell, char season=0)
    {
        int direction = rand() % 100;
        if (direction < 50)
        {
            if (!tTool::GasCollision(_x, _y-1))
            { int rplc = (_y-1)*tCell::width+(_x); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x-1, _y-1))
            { int rplc = (_y-1)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x+1, _y-1))
            { int rplc = (_y-1)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x-1, _y) && tTool::GasCollision(_x+1, _y))
            { int rplc = (_y)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x+1, _y) && tTool::GasCollision(_x-1, _y))
            { int rplc = (_y)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
        }
        else
        {
            if (!tTool::GasCollision(_x, _y-1))
            { int rplc = (_y-1)*tCell::width+(_x); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x+1, _y-1))
            { int rplc = (_y-1)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x-1, _y-1))
            { int rplc = (_y-1)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x+1, _y) && tTool::GasCollision(_x-1, _y))
            { int rplc = (_y)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x-1, _y) && tTool::GasCollision(_x+1, _y))
            { int rplc = (_y)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
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
