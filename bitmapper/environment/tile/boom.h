namespace tBoom
{
    //
    // Special
    //
    
    void Bomb(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        if (tTool::GetType(tCell::matrix[dN]) == tTile::PLASMA ||
            tCell::matrix[dN] == tTile::LAVA)
        {
            // Core
            if (tTool::Collision(_x, _y)) { tCell::replace[index] = tTile::EMBER; }

            // Middle
            int dNW = int( (_y-1) * tCell::width + (_x-1) );
            int dNE = int( (_y-1) * tCell::width + (_x+1) );
            int dE  = int( (_y  ) * tCell::width + (_x+1) );
            int dSE = int( (_y+1) * tCell::width + (_x+1) );
            int dS  = int( (_y+1) * tCell::width + (_x  ) );
            int dSW = int( (_y+1) * tCell::width + (_x-1) );
            int dW  = int( (_y  ) * tCell::width + (_x-1) );

            if (tTool::Collision(_x-1, _y-1)) { tCell::replace[dNW] = tTile::EMBER; }
            if (tTool::Collision(_x  , _y-1)) { tCell::replace[dN] = tTile::EMBER; }
            if (tTool::Collision(_x+1, _y-1)) { tCell::replace[dNE] = tTile::EMBER; }
            if (tTool::Collision(_x+1, _y  )) { tCell::replace[dE] = tTile::EMBER; }
            if (tTool::Collision(_x+1, _y+1)) { tCell::replace[dSE] = tTile::EMBER; }
            if (tTool::Collision(_x  , _y+1)) { tCell::replace[dS] = tTile::EMBER; }
            if (tTool::Collision(_x-1, _y+1)) { tCell::replace[dSW] = tTile::EMBER; }
            if (tTool::Collision(_x-1, _y  )) { tCell::replace[dW] = tTile::EMBER; }

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

            if (tTool::Collision(_x-1, _y-2)) { tCell::replace[dNNW] = tTile::EMBER; }
            if (tTool::Collision(_x  , _y-2)) { tCell::replace[dNN] = tTile::EMBER; }
            if (tTool::Collision(_x+1, _y-2)) { tCell::replace[dNNE] = tTile::EMBER; }
            if (tTool::Collision(_x+2, _y-1)) { tCell::replace[dEEN] = tTile::EMBER; }
            if (tTool::Collision(_x+2, _y  )) { tCell::replace[dEE] = tTile::EMBER; }
            if (tTool::Collision(_x+2, _y+1)) { tCell::replace[dEES] = tTile::EMBER; }
            if (tTool::Collision(_x-1, _y+2)) { tCell::replace[dSSW] = tTile::EMBER; }
            if (tTool::Collision(_x  , _y+2)) { tCell::replace[dSS] = tTile::EMBER; }
            if (tTool::Collision(_x+1, _y+2)) { tCell::replace[dSSE] = tTile::EMBER; }
            if (tTool::Collision(_x-2, _y-1)) { tCell::replace[dWWN] = tTile::EMBER; }
            if (tTool::Collision(_x-2, _y  )) { tCell::replace[dWW] = tTile::EMBER; }
            if (tTool::Collision(_x-2, _y+1)) { tCell::replace[dWWS] = tTile::EMBER; }
        }
    }

    void Dynamite(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        if (tTool::GetType(tCell::matrix[dN]) == tTile::PLASMA ||
            tCell::matrix[dN] == tTile::LAVA)
        {
            // Core
            if (tTool::Collision(_x, _y)) { tCell::replace[index] = tTile::EMBER; }

            // Middle
            int dNW = int( (_y-1) * tCell::width + (_x-1) );
            int dNE = int( (_y-1) * tCell::width + (_x+1) );
            int dE  = int( (_y  ) * tCell::width + (_x+1) );
            int dSE = int( (_y+1) * tCell::width + (_x+1) );
            int dS  = int( (_y+1) * tCell::width + (_x  ) );
            int dSW = int( (_y+1) * tCell::width + (_x-1) );
            int dW  = int( (_y  ) * tCell::width + (_x-1) );

            if (tTool::Collision(_x-1, _y-1)) { tCell::replace[dNW] = tTile::EMBER; }
            if (tTool::Collision(_x  , _y-1)) { tCell::replace[dN] = tTile::EMBER; }
            if (tTool::Collision(_x+1, _y-1)) { tCell::replace[dNE] = tTile::EMBER; }
            if (tTool::Collision(_x+1, _y  )) { tCell::replace[dE] = tTile::EMBER; }
            if (tTool::Collision(_x+1, _y+1)) { tCell::replace[dSE] = tTile::EMBER; }
            if (tTool::Collision(_x  , _y+1)) { tCell::replace[dS] = tTile::EMBER; }
            if (tTool::Collision(_x-1, _y+1)) { tCell::replace[dSW] = tTile::EMBER; }
            if (tTool::Collision(_x-1, _y  )) { tCell::replace[dW] = tTile::EMBER; }

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

            if (tTool::Collision(_x-1, _y-2)) { tCell::replace[dNNW] = tTile::EMBER; }
            if (tTool::Collision(_x  , _y-2)) { tCell::replace[dNN] = tTile::EMBER; }
            if (tTool::Collision(_x+1, _y-2)) { tCell::replace[dNNE] = tTile::EMBER; }
            if (tTool::Collision(_x+2, _y-1)) { tCell::replace[dEEN] = tTile::EMBER; }
            if (tTool::Collision(_x+2, _y  )) { tCell::replace[dEE] = tTile::EMBER; }
            if (tTool::Collision(_x+2, _y+1)) { tCell::replace[dEES] = tTile::EMBER; }
            if (tTool::Collision(_x-1, _y+2)) { tCell::replace[dSSW] = tTile::EMBER; }
            if (tTool::Collision(_x  , _y+2)) { tCell::replace[dSS] = tTile::EMBER; }
            if (tTool::Collision(_x+1, _y+2)) { tCell::replace[dSSE] = tTile::EMBER; }
            if (tTool::Collision(_x-2, _y-1)) { tCell::replace[dWWN] = tTile::EMBER; }
            if (tTool::Collision(_x-2, _y  )) { tCell::replace[dWW] = tTile::EMBER; }
            if (tTool::Collision(_x-2, _y+1)) { tCell::replace[dWWS] = tTile::EMBER; }
        }
    }

    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell, char season=0)
    {
        switch (current_cell)
        {
            case tTile::BOMB     : {     Bomb(_x, _y, index); } break;
            case tTile::DYNAMITE : { Dynamite(_x, _y, index); } break;
        }
    }
}
