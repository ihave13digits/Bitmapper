namespace tGizmo
{

    //
    // Special
    //

    void AxleLeft(int _x, int _y, int index, char season)
    {
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dN =  int( (_y-1) * tCell::width + (_x) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dW =  int( (_y) * tCell::width + (_x-1) );
        int dE =  int( (_y) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dS =  int( (_y+1) * tCell::width + (_x) );

        int v1 = tCell::matrix[dNW];
        int v2 = tCell::matrix[dN];
        int v3 = tCell::matrix[dNE];
        int v4 = tCell::matrix[dE];
        int v5 = tCell::matrix[dSE];
        int v6 = tCell::matrix[dS];
        int v7 = tCell::matrix[dSW];
        int v8 = tCell::matrix[dW];

        if (
           (tTool::GetType(v1) == tTile::GAS || tTool::GetType(v1) == tTile::SOLID || tTool::GetType(v1) == tTile::GIZMO) &&
           (tTool::GetType(v2) == tTile::GAS || tTool::GetType(v2) == tTile::SOLID || tTool::GetType(v2) == tTile::GIZMO) &&
           (tTool::GetType(v3) == tTile::GAS || tTool::GetType(v3) == tTile::SOLID || tTool::GetType(v3) == tTile::GIZMO) &&
           (tTool::GetType(v4) == tTile::GAS || tTool::GetType(v4) == tTile::SOLID || tTool::GetType(v4) == tTile::GIZMO) &&
           (tTool::GetType(v5) == tTile::GAS || tTool::GetType(v5) == tTile::SOLID || tTool::GetType(v5) == tTile::GIZMO) &&
           (tTool::GetType(v6) == tTile::GAS || tTool::GetType(v6) == tTile::SOLID || tTool::GetType(v6) == tTile::GIZMO) &&
           (tTool::GetType(v7) == tTile::GAS || tTool::GetType(v7) == tTile::SOLID || tTool::GetType(v7) == tTile::GIZMO) &&
           (tTool::GetType(v8) == tTile::GAS || tTool::GetType(v8) == tTile::SOLID || tTool::GetType(v8) == tTile::GIZMO) )
        {
            tCell::replace[dNW] = v2; tCell::matrix[dNW] = v2;
            tCell::replace[dN] = v3; tCell::matrix[dN] = v3;
            tCell::replace[dNE] = v4; tCell::matrix[dNE] = v4;
            tCell::replace[dE] = v5; tCell::matrix[dE] = v5;
            tCell::replace[dSE] = v6; tCell::matrix[dSE] = v6;
            tCell::replace[dS] = v7; tCell::matrix[dS] = v7;
            tCell::replace[dSW] = v8; tCell::matrix[dSW] = v8;
            tCell::replace[dW] = v1; tCell::matrix[dW] = v1;
        }
    }

    void AxleRight(int _x, int _y, int index, char season)
    {
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dN =  int( (_y-1) * tCell::width + (_x) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dW =  int( (_y) * tCell::width + (_x-1) );
        int dE =  int( (_y) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dS =  int( (_y+1) * tCell::width + (_x) );

        int v1 = tCell::matrix[dNW];
        int v2 = tCell::matrix[dN];
        int v3 = tCell::matrix[dNE];
        int v4 = tCell::matrix[dE];
        int v5 = tCell::matrix[dSE];
        int v6 = tCell::matrix[dS];
        int v7 = tCell::matrix[dSW];
        int v8 = tCell::matrix[dW];

        if (
            (tTool::GetType(v1) == tTile::GAS || tTool::GetType(v1) == tTile::SOLID || tTool::GetType(v1) == tTile::GIZMO) &&
            (tTool::GetType(v1) == tTile::GAS || tTool::GetType(v2) == tTile::SOLID || tTool::GetType(v2) == tTile::GIZMO) &&
            (tTool::GetType(v1) == tTile::GAS || tTool::GetType(v3) == tTile::SOLID || tTool::GetType(v3) == tTile::GIZMO) &&
            (tTool::GetType(v1) == tTile::GAS || tTool::GetType(v4) == tTile::SOLID || tTool::GetType(v4) == tTile::GIZMO) &&
            (tTool::GetType(v1) == tTile::GAS || tTool::GetType(v5) == tTile::SOLID || tTool::GetType(v5) == tTile::GIZMO) &&
            (tTool::GetType(v1) == tTile::GAS || tTool::GetType(v6) == tTile::SOLID || tTool::GetType(v6) == tTile::GIZMO) &&
            (tTool::GetType(v1) == tTile::GAS || tTool::GetType(v7) == tTile::SOLID || tTool::GetType(v7) == tTile::GIZMO) &&
            (tTool::GetType(v1) == tTile::GAS || tTool::GetType(v8) == tTile::SOLID || tTool::GetType(v8) == tTile::GIZMO) )
        {
            tCell::replace[dNW] = v8; tCell::matrix[dNW] = v8;
            tCell::replace[dN] = v1; tCell::matrix[dN] = v1;
            tCell::replace[dNE] = v2; tCell::matrix[dNE] = v2;
            tCell::replace[dE] = v3; tCell::matrix[dE] = v3;
            tCell::replace[dSE] = v4; tCell::matrix[dSE] = v4;
            tCell::replace[dS] = v5; tCell::matrix[dS] = v5;
            tCell::replace[dSW] = v6; tCell::matrix[dSW] = v6;
            tCell::replace[dW] = v7; tCell::matrix[dW] = v7;
        }
    }

    void ConveyorLeft(int _x, int _y, int index, char season)
    {
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dN = int( (_y-1) * tCell::width + (_x) );
        int v1 = tCell::matrix[dNW];
        int v2 = tCell::matrix[dN];
        int v3 = tCell::matrix[dNE];
        if ( v1<tTile::VALVE_CLOSED && v2<tTile::VALVE_CLOSED && v3<tTile::VALVE_CLOSED)
        {
            if (v2 > tTile::MUD && v1 == tTile::AIR)
            {
                tCell::replace[dNW] = v2; v1 = tTile::AIR;
                if (tTool::GetType(v3) != tTile::SOLID) tCell::replace[dN] = v3; tCell::matrix[dN] = v1;
                if (tTool::GetType(v3) == tTile::SOLID) tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR;
            }
        }
    }

    void ConveyorRight(int _x, int _y, int index, char season)
    {
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dN = int( (_y-1) * tCell::width + (_x) );
        int v1 = tCell::matrix[dNE];
        int v2 = tCell::matrix[dN];
        int v3 = tCell::matrix[dNW];
        if ( v1<tTile::VALVE_CLOSED && v2<tTile::VALVE_CLOSED && v3<tTile::VALVE_CLOSED)
        {
            if (v2 > tTile::MUD && v1 == tTile::AIR)
            {
                tCell::replace[dNE] = v2; tCell::matrix[dNW] = tTile::AIR;
                if (tTool::GetType(v3) != tTile::SOLID) tCell::replace[dN] = v1; tCell::matrix[dN] = v3;
                if (tTool::GetType(v3) == tTile::SOLID) tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR;
            }
        }
    }

    void PistonUp(int _x, int _y, int index, char season)
    {
        int dN = int( (_y-1) * tCell::width + (_x) );
        int dNN = int( (_y-2) * tCell::width + (_x) );
        int v = tCell::matrix[dN];
        if (tCell::matrix[dNN] == tTile::AIR)
        {
            tCell::replace[dNN] = v; tCell::replace[dN] = tTile::AIR;
            tCell::matrix[dNN]  = v; tCell::matrix[dN]  = tTile::AIR;
        }
    }

    void PistonDown(int _x, int _y, int index, char season)
    {
        int dS = int( (_y+1) * tCell::width + (_x) );
        int dSS = int( (_y+2) * tCell::width + (_x) );
        int v = tCell::matrix[dS];
        if (tCell::matrix[dSS] == tTile::AIR)
        {
            tCell::replace[dSS] = v; tCell::replace[dS] = tTile::AIR;
            tCell::matrix[dSS]  = v; tCell::matrix[dS]  = tTile::AIR;
        }
    }

    void PistonLeft(int _x, int _y, int index, char season)
    {
        int dW = int( (_y) * tCell::width + (_x-1) );
        int dWW = int( (_y) * tCell::width + (_x-2) );
        int v = tCell::matrix[dW];
        if (tCell::matrix[dWW] == tTile::AIR)
        {
            tCell::replace[dWW] = v; tCell::replace[dW] = tTile::AIR;
            tCell::matrix[dWW]  = v; tCell::matrix[dW]  = tTile::AIR;
        }
    }

    void PistonRight(int _x, int _y, int index, char season)
    {
        int dE = int( (_y) * tCell::width + (_x+1) );
        int dEE = int( (_y) * tCell::width + (_x+2) );
        int v = tCell::matrix[dE];
        if (tCell::matrix[dEE] == tTile::AIR)
        {
            tCell::replace[dEE] = v; tCell::replace[dE] = tTile::AIR;
            tCell::matrix[dEE]  = v; tCell::matrix[dE]  = tTile::AIR;
        }
    }



    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell, char season=0)
    {
        if (current_cell == tTile::AXLE_LEFT) { AxleLeft(_x, _y, index, season); }
        if (current_cell == tTile::AXLE_RIGHT) { AxleRight(_x, _y, index, season); }
        if (current_cell == tTile::CONVEYOR_LEFT) { ConveyorLeft(_x, _y, index, season); }
        if (current_cell == tTile::CONVEYOR_RIGHT) { ConveyorRight(_x, _y, index, season); }
        if (current_cell == tTile::PISTON_UP) { PistonUp(_x, _y, index, season); }
        if (current_cell == tTile::PISTON_DOWN) { PistonDown(_x, _y, index, season); }
        if (current_cell == tTile::PISTON_LEFT) { PistonLeft(_x, _y, index, season); }
        if (current_cell == tTile::PISTON_RIGHT) { PistonRight(_x, _y, index, season); }
    }

}
