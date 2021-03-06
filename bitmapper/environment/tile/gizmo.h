namespace tGizmo
{

    //
    // Special
    //

    void AxleLeft(int _x, int _y, int index)
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
            tCell::replace[dN]  = v3; tCell::matrix[dN]  = v3;
            tCell::replace[dNE] = v4; tCell::matrix[dNE] = v4;
            tCell::replace[dE]  = v5; tCell::matrix[dE]  = v5;
            tCell::replace[dSE] = v6; tCell::matrix[dSE] = v6;
            tCell::replace[dS]  = v7; tCell::matrix[dS]  = v7;
            tCell::replace[dSW] = v8; tCell::matrix[dSW] = v8;
            tCell::replace[dW]  = v1; tCell::matrix[dW]  = v1;
        }
    }

    void AxleRight(int _x, int _y, int index)
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
            tCell::replace[dNW] = v8; tCell::matrix[dNW] = v8;
            tCell::replace[dN]  = v1; tCell::matrix[dN]  = v1;
            tCell::replace[dNE] = v2; tCell::matrix[dNE] = v2;
            tCell::replace[dE]  = v3; tCell::matrix[dE]  = v3;
            tCell::replace[dSE] = v4; tCell::matrix[dSE] = v4;
            tCell::replace[dS]  = v5; tCell::matrix[dS]  = v5;
            tCell::replace[dSW] = v6; tCell::matrix[dSW] = v6;
            tCell::replace[dW]  = v7; tCell::matrix[dW]  = v7;
        }
    }

    void ConveyorLeft(int _x, int _y, int index)
    {
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dN = int( (_y-1) * tCell::width + (_x) );
        int vW = tCell::matrix[dNW];
        int vN = tCell::matrix[dN];
        int vE = tCell::matrix[dNE];
        if ((tTool::GetType(vN) == tTile::GRAIN || tTool::GetType(vN) == tTile::SOLID || tTool::GetType(vN) == tTile::GIZMO) &&
            (tTool::GetType(vE) == tTile::GRAIN || tTool::GetType(vE) == tTile::GIZMO) &&
            vW == tTile::AIR && tCell::matrix[index+1] == tTile::CONVEYOR_LEFT)
        {
            //tCell::matrix[dNW] = vN;  tCell::matrix[dN] = vE;  tCell::matrix[dNE] = tTile::AIR;
            tCell::replace[dNW] = vN; tCell::replace[dN] = vE; tCell::replace[dNE] = tTile::AIR;
        }
        else if ((tTool::GetType(vN) == tTile::GRAIN || tTool::GetType(vN) == tTile::SOLID || tTool::GetType(vN) == tTile::GIZMO) &&
            (tTool::GetType(vE) != tTile::GRAIN && tTool::GetType(vE) != tTile::GIZMO) &&
            vW == tTile::AIR && tCell::matrix[index+1] == tTile::CONVEYOR_LEFT)
        {
            tCell::matrix[dNW] = vN;  tCell::matrix[dN] = tTile::AIR;
            tCell::replace[dNW] = vN; tCell::replace[dN] = tTile::AIR;
        }
        else if ((tTool::GetType(vN) == tTile::GRAIN || tTool::GetType(vN) == tTile::SOLID || tTool::GetType(vN) == tTile::GIZMO) &&
            (tTool::GetType(vE) != tTile::GRAIN && tTool::GetType(vE) != tTile::GIZMO) &&
            vW == tTile::AIR && tCell::matrix[index+1] == tTile::AIR)
        {
            tCell::matrix[dNW] = vN;  tCell::matrix[dN] = tTile::AIR;
            tCell::replace[dNW] = vN; tCell::replace[dN] = tTile::AIR;
        }
    }

    void ConveyorRight(int _x, int _y, int index)
    {
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dN = int( (_y-1) * tCell::width + (_x) );
        int vE = tCell::matrix[dNE];
        int vN = tCell::matrix[dN];
        int vW = tCell::matrix[dNW];
        if ((tTool::GetType(vN) == tTile::GRAIN || tTool::GetType(vN) == tTile::SOLID || tTool::GetType(vN) == tTile::GIZMO) &&
            (tTool::GetType(vW) == tTile::GRAIN || tTool::GetType(vW) == tTile::GIZMO) &&
            vE == tTile::AIR && tCell::matrix[index-1] == tTile::CONVEYOR_RIGHT)
        {
            //tCell::matrix[dNE] = vN;  tCell::matrix[dN] = vW;  tCell::matrix[dNW] = tTile::AIR;
            tCell::replace[dNE] = vN; tCell::replace[dN] = vW; tCell::replace[dNW] = tTile::AIR;
        }
        else if ((tTool::GetType(vN) == tTile::GRAIN || tTool::GetType(vN) == tTile::SOLID || tTool::GetType(vN) == tTile::GIZMO) &&
            (tTool::GetType(vW) != tTile::GRAIN && tTool::GetType(vW) != tTile::GIZMO) &&
            vE == tTile::AIR && tCell::matrix[index-1] == tTile::CONVEYOR_RIGHT)
        {
            //tCell::matrix[dNE] = vN;  tCell::matrix[dN] = tTile::AIR;
            tCell::replace[dNE] = vN; tCell::replace[dN] = tTile::AIR;
        }
        else if ((tTool::GetType(vN) == tTile::GRAIN || tTool::GetType(vN) == tTile::SOLID || tTool::GetType(vN) == tTile::GIZMO) &&
            (tTool::GetType(vW) != tTile::GRAIN && tTool::GetType(vW) != tTile::GIZMO) &&
            vE == tTile::AIR && tCell::matrix[index-1] == tTile::AIR)
        {
            tCell::matrix[dNE] = vN;  tCell::matrix[dN] = tTile::AIR;
            tCell::replace[dNE] = vN; tCell::replace[dN] = tTile::AIR;
        }
    }

    void Piston(int _x, int _y, int index)
    {
        int dN1 = int( (_y-1) * tCell::width + (_x) );
        int dN2 = int( (_y-2) * tCell::width + (_x) );
        int dN3 = int( (_y-3) * tCell::width + (_x) );
        int dN4 = int( (_y-4) * tCell::width + (_x) );
        int dS1 = int( (_y+1) * tCell::width + (_x) );
        int dS2 = int( (_y+2) * tCell::width + (_x) );
        int dS3 = int( (_y+3) * tCell::width + (_x) );
        int dS4 = int( (_y+4) * tCell::width + (_x) );
        int dE1 = int( (_y) * tCell::width + (_x+1) );
        int dE2 = int( (_y) * tCell::width + (_x+2) );
        int dE3 = int( (_y) * tCell::width + (_x+3) );
        int dE4 = int( (_y) * tCell::width + (_x+4) );
        int dW1 = int( (_y) * tCell::width + (_x-1) );
        int dW2 = int( (_y) * tCell::width + (_x-2) );
        int dW3 = int( (_y) * tCell::width + (_x-3) );
        int dW4 = int( (_y) * tCell::width + (_x-4) );
        // North
        if (tCell::matrix[dN2] == tTile::AIR && tTool::IsPowered(dS1))
        { int v = tCell::matrix[dN1]; tCell::replace[dN2] = v; tCell::replace[dN1] = tTile::AIR; }//tCell::matrix[dN2]  = v; tCell::matrix[dN1]  = tTile::AIR; }
        else if (tCell::matrix[dN3] == tTile::AIR && tTool::IsPowered(dS2))
        {
            if (tCell::matrix[dN2] != tTile::AIR && tCell::matrix[dN1] != tTile::AIR)
            {int v = tCell::matrix[dN2]; tCell::replace[dN3] = v; tCell::replace[dN2] = tTile::AIR; }}//tCell::matrix[dN3]  = v; tCell::matrix[dN2]  = tTile::AIR; }}
        else if (tCell::matrix[dN4] == tTile::AIR && tTool::IsPowered(dS3))
        {
            if (tCell::matrix[dN3] != tTile::AIR && tCell::matrix[dN2] != tTile::AIR && tCell::matrix[dN1] != tTile::AIR)
            {int v = tCell::matrix[dN3]; tCell::replace[dN4] = v; tCell::replace[dN3] = tTile::AIR; }}//tCell::matrix[dN4]  = v; tCell::matrix[dN3]  = tTile::AIR; }}
        // South
        if (tCell::matrix[dS2] == tTile::AIR && tTool::IsPowered(dN1))
        { int v = tCell::matrix[dS1]; tCell::replace[dS2] = v; tCell::replace[dS1] = tTile::AIR; }//tCell::matrix[dS2]  = v; tCell::matrix[dS1]  = tTile::AIR; }
        else if (tCell::matrix[dS3] == tTile::AIR && tTool::IsPowered(dN2))
        {
            if (tCell::matrix[dS2] != tTile::AIR && tCell::matrix[dS1] != tTile::AIR)
            { int v = tCell::matrix[dS2]; tCell::replace[dS3] = v; tCell::replace[dS2] = tTile::AIR; }}//tCell::matrix[dS3]  = v; tCell::matrix[dS2]  = tTile::AIR; }}
        else if (tCell::matrix[dS4] == tTile::AIR && tTool::IsPowered(dN3))
        {
            if (tCell::matrix[dS3] != tTile::AIR && tCell::matrix[dS2] != tTile::AIR && tCell::matrix[dS1] != tTile::AIR)
            { int v = tCell::matrix[dS3]; tCell::replace[dS4] = v; tCell::replace[dS3] = tTile::AIR; }}//tCell::matrix[dS4]  = v; tCell::matrix[dS3]  = tTile::AIR; }}
        // East
        if (tCell::matrix[dE2] == tTile::AIR && tTool::IsPowered(dW1))
        { int v = tCell::matrix[dE1]; tCell::replace[dE2] = v; tCell::replace[dE1] = tTile::AIR; }//tCell::matrix[dE2]  = v; tCell::matrix[dE1]  = tTile::AIR; }
        else if (tCell::matrix[dE3] == tTile::AIR && tTool::IsPowered(dW2))
        {
            if (tCell::matrix[dE2] != tTile::AIR && tCell::matrix[dE1] != tTile::AIR)
            { int v = tCell::matrix[dE2]; tCell::replace[dE3] = v; tCell::replace[dE2] = tTile::AIR; }}//tCell::matrix[dE3]  = v; tCell::matrix[dE2]  = tTile::AIR; }}
        else if (tCell::matrix[dE4] == tTile::AIR && tTool::IsPowered(dW3))
        {
            if (tCell::matrix[dE3] != tTile::AIR && tCell::matrix[dE2] != tTile::AIR && tCell::matrix[dE1] != tTile::AIR)
            { int v = tCell::matrix[dE3]; tCell::replace[dE4] = v; tCell::replace[dE3] = tTile::AIR; }}//tCell::matrix[dE4]  = v; tCell::matrix[dE3]  = tTile::AIR; }}
        // West
        if (tCell::matrix[dW2] == tTile::AIR && tTool::IsPowered(dE1))
        { int v = tCell::matrix[dW1]; tCell::replace[dW2] = v; tCell::replace[dW1] = tTile::AIR; }//tCell::matrix[dW2]  = v; tCell::matrix[dW1]  = tTile::AIR; }
        else if (tCell::matrix[dW3] == tTile::AIR && tTool::IsPowered(dE2))
        {
            if (tCell::matrix[dW2] != tTile::AIR && tCell::matrix[dW1] != tTile::AIR)
            {int v = tCell::matrix[dW2]; tCell::replace[dW3] = v; tCell::replace[dW2] = tTile::AIR; }}//tCell::matrix[dW3]  = v; tCell::matrix[dW2]  = tTile::AIR; }}
        else if (tCell::matrix[dW4] == tTile::AIR && tTool::IsPowered(dE3))
        {
            if (tCell::matrix[dW3] != tTile::AIR && tCell::matrix[dW2] != tTile::AIR && tCell::matrix[dW1] != tTile::AIR)
            { int v = tCell::matrix[dW3]; tCell::replace[dW4] = v; tCell::replace[dW3] = tTile::AIR; }}//tCell::matrix[dW4]  = v; tCell::matrix[dW3]  = tTile::AIR; }}
    }



    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell)
    {
        if (current_cell == tTile::AXLE_LEFT) { AxleLeft(_x, _y, index); }
        if (current_cell == tTile::AXLE_RIGHT) { AxleRight(_x, _y, index); }
        if (current_cell == tTile::CONVEYOR_LEFT) { ConveyorLeft(_x, _y, index); }
        if (current_cell == tTile::CONVEYOR_RIGHT) { ConveyorRight(_x, _y, index); }
        if (current_cell == tTile::PISTON) { Piston(_x, _y, index); }
    }

}
