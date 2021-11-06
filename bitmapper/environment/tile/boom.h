namespace tBoom
{
    //
    // Special
    //
    
    void ExplodeArea(int _x, int _y, int index, int tile)
    {
        // Core
        if (tTool::Collision(_x, _y)) { tCell::replace[index] = tile; }

        // Middle
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        if (tTool::Collision(_x-1, _y-1)) { tCell::replace[dNW] = tile; }
        if (tTool::Collision(_x  , _y-1)) { tCell::replace[dN] = tile; }
        if (tTool::Collision(_x+1, _y-1)) { tCell::replace[dNE] = tile; }
        if (tTool::Collision(_x+1, _y  )) { tCell::replace[dE] = tile; }
        if (tTool::Collision(_x+1, _y+1)) { tCell::replace[dSE] = tile; }
        if (tTool::Collision(_x  , _y+1)) { tCell::replace[dS] = tile; }
        if (tTool::Collision(_x-1, _y+1)) { tCell::replace[dSW] = tile; }
        if (tTool::Collision(_x-1, _y  )) { tCell::replace[dW] = tile; }
        
        // Outer
        int dNNW = int( (_y-2) * tCell::width + (_x-1) );
        int dNN  = int( (_y-2) * tCell::width + (_x  ) );
        int dNNE = int( (_y-2) * tCell::width + (_x+1) );
        int dEEN = int( (_y-1) * tCell::width + (_x+2) );
        int dEE  = int( (_y  ) * tCell::width + (_x+2) );
        int dEES = int( (_y+1) * tCell::width + (_x+2) );
        int dSSW = int( (_y+2) * tCell::width + (_x-1) );
        int dSS  = int( (_y+2) * tCell::width + (_x  ) );
        int dSSE = int( (_y+2) * tCell::width + (_x+1) );
        int dWWN = int( (_y-1) * tCell::width + (_x-2) );
        int dWW  = int( (_y  ) * tCell::width + (_x-2) );
        int dWWS = int( (_y+1) * tCell::width + (_x-2) );

        if (tTool::Collision(_x-1, _y-2)) { tCell::replace[dNNW] = tile; }
        if (tTool::Collision(_x  , _y-2)) { tCell::replace[dNN] = tile; }
        if (tTool::Collision(_x+1, _y-2)) { tCell::replace[dNNE] = tile; }
        if (tTool::Collision(_x+2, _y-1)) { tCell::replace[dEEN] = tile; }
        if (tTool::Collision(_x+2, _y  )) { tCell::replace[dEE] = tile; }
        if (tTool::Collision(_x+2, _y+1)) { tCell::replace[dEES] = tile; }
        if (tTool::Collision(_x-1, _y+2)) { tCell::replace[dSSW] = tile; }
        if (tTool::Collision(_x  , _y+2)) { tCell::replace[dSS] = tile; }
        if (tTool::Collision(_x+1, _y+2)) { tCell::replace[dSSE] = tile; }
        if (tTool::Collision(_x-2, _y-1)) { tCell::replace[dWWN] = tile; }
        if (tTool::Collision(_x-2, _y  )) { tCell::replace[dWW] = tile; }
        if (tTool::Collision(_x-2, _y+1)) { tCell::replace[dWWS] = tile; }
    }

    void Bomb(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        if (tCell::matrix[dS] == tTile::AIR)
        {
            tCell::replace[dS] = tTile::BOMB;
            tCell::replace[index] = tTile::AIR;
        }
        if (tTool::GetType(tCell::matrix[dN]) == tTile::PLASMA ||
            tCell::matrix[dN] == tTile::LAVA)
        {
            ExplodeArea(_x, _y, index, tTile::AIR);
        }
    }

    void Dynamite(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        if (tCell::matrix[dS] == tTile::AIR)
        {
            tCell::replace[dS] = tTile::DYNAMITE;
            tCell::replace[index] = tTile::AIR;
        }
        if (tTool::GetType(tCell::matrix[dN]) == tTile::PLASMA ||
            tCell::matrix[dN] == tTile::LAVA)
        {
            ExplodeArea(_x-4, _y-2, index, tTile::FIRE);
            ExplodeArea(_x-2, _y-4, index, tTile::FIRE);
            ExplodeArea(_x-2, _y+4, index, tTile::FIRE);
            ExplodeArea(_x-4, _y+2, index, tTile::FIRE);
            ExplodeArea(_x+4, _y-2, index, tTile::FIRE);
            ExplodeArea(_x+2, _y-4, index, tTile::FIRE);
            ExplodeArea(_x+2, _y+4, index, tTile::FIRE);
            ExplodeArea(_x+4, _y+2, index, tTile::FIRE);

            ExplodeArea(_x  , _y-2, index, tTile::FIRE);
            ExplodeArea(_x  , _y+2, index, tTile::FIRE);
            ExplodeArea(_x-2, _y  , index, tTile::FIRE);
            ExplodeArea(_x+2, _y  , index, tTile::FIRE);
            ExplodeArea(_x  , _y  , index, tTile::AIR);
        }
    }

    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell)
    {
        switch (current_cell)
        {
            case tTile::BOMB     : {     Bomb(_x, _y, index); } break;
            case tTile::DYNAMITE : { Dynamite(_x, _y, index); } break;
        }
    }
}
