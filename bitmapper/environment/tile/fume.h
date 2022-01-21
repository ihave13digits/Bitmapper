namespace tFume
{
    
    //
    // Special
    //
    
    void Fog(int _x, int _y, int index)
    {
        int dS = int( (_y+1) * tCell::width + (_x  ) );
        if (tCell::matrix[dS] == tTile::GRASS && rand()%1000 < 25) { tCell::replace[index] = tTile::AIR; }
    }

    void Radon(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        if (tCell::matrix[dN] == tTile::URANIUM) { if (rand()%1000 < 25 && tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::ARC; } }
        if (tCell::matrix[dS] == tTile::URANIUM) { if (rand()%1000 < 25 && tCell::matrix[dN] == tTile::AIR) { tCell::replace[index] = tTile::ARC; } }
        if (tCell::matrix[dE] == tTile::URANIUM) { if (rand()%1000 < 25 && tCell::matrix[dW] == tTile::AIR) { tCell::replace[index] = tTile::ARC; } }
        if (tCell::matrix[dW] == tTile::URANIUM) { if (rand()%1000 < 25 && tCell::matrix[dE] == tTile::AIR) { tCell::replace[index] = tTile::ARC; } }
    }

    void AcidFumes(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        float durN = tTool::GetDurability(tCell::matrix[dN]);
        float durS = tTool::GetDurability(tCell::matrix[dS]);
        float durE = tTool::GetDurability(tCell::matrix[dE]);
        float durW = tTool::GetDurability(tCell::matrix[dW]);
        if ((tTool::GetType(tCell::matrix[dN]) != tTile::GAS && tTool::GetType(tCell::matrix[dN]) != tTile::FLUID &&
            tTool::GetType(tCell::matrix[dN]) != tTile::GEM) && rand()%10000 < (1+(10.0*durN)))
        { tCell::replace[index] = tTile::AIR; tCell::replace[dN] = tTile::ACID_FUMES; }
        if ((tTool::GetType(tCell::matrix[dS]) != tTile::GAS && tTool::GetType(tCell::matrix[dS]) != tTile::FLUID &&
            tTool::GetType(tCell::matrix[dS]) != tTile::GEM) && rand()%10000 < (1+(10.0*durS)))
        { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::ACID_FUMES; }
        if ((tTool::GetType(tCell::matrix[dE]) != tTile::GAS && tTool::GetType(tCell::matrix[dE]) != tTile::FLUID &&
            tTool::GetType(tCell::matrix[dE]) != tTile::GEM) && rand()%10000 < (1+(10.0*durE)))
        { tCell::replace[index] = tTile::AIR; tCell::replace[dE] = tTile::ACID_FUMES; }
        if ((tTool::GetType(tCell::matrix[dW]) != tTile::GAS && tTool::GetType(tCell::matrix[dW]) != tTile::FLUID &&
            tTool::GetType(tCell::matrix[dW]) != tTile::GEM) && rand()%10000 < (1+(10.0*durW)))
        { tCell::replace[index] = tTile::AIR; tCell::replace[dW] = tTile::ACID_FUMES; }
    }

    void OilFumes(int _x, int _y, int index)
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

    void Update(int _x, int _y, int index, int current_cell)
    {
        int cell_type = tTool::GetType(current_cell);
        int direction = rand() % 100;

        if (direction < 50)
        {
            if (!tTool::FumeCollision(_x, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FumeCollision(_x-1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FumeCollision(_x+1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FumeCollision(_x-2, _y) && !tTool::FumeCollision(_x-1, _y))
            { int rplc = (_y)*tCell::width+(_x-2); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FumeCollision(_x+2, _y) && !tTool::FumeCollision(_x+1, _y))
            { int rplc = (_y)*tCell::width+(_x+2); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FumeCollision(_x-1, _y) && tTool::FumeCollision(_x+1, _y))
            { int rplc = (_y)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FumeCollision(_x+1, _y) && tTool::FumeCollision(_x-1, _y))
            { int rplc = (_y)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
        }
        else
        {
            if (!tTool::FumeCollision(_x, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FumeCollision(_x+1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FumeCollision(_x-1, _y+1))
            { int rplc = (_y+1)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FumeCollision(_x+2, _y) && !tTool::FumeCollision(_x+1, _y))
            { int rplc = (_y)*tCell::width+(_x+2); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FumeCollision(_x-2, _y) && !tTool::FumeCollision(_x-1, _y))
            { int rplc = (_y)*tCell::width+(_x-2); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FumeCollision(_x+1, _y) && tTool::FumeCollision(_x-1, _y))
            { int rplc = (_y)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
            else if (!tTool::FumeCollision(_x-1, _y) && tTool::FumeCollision(_x+1, _y))
            { int rplc = (_y)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::Swap(index, rplc); } }
        }
        


        switch (current_cell)
            {
                case tTile::FOG        : {       Fog(_x, _y, index); } break;
                case tTile::RADON      : {     Radon(_x, _y, index); } break;
                case tTile::ACID_FUMES : { AcidFumes(_x, _y, index); } break;
                case tTile::OIL_FUMES  : {  OilFumes(_x, _y, index); } break;
            }

    }

}
