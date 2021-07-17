namespace tLogic
{
    
    //
    // Special
    //
    
    void Wire(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        switch (tCell::matrix[dN])
        {
            case tTile::WIRE_O : {tCell::replace[dN] = tTile::WIRE; tCell::replace[index] = tTile::WIRE;} break;
            case tTile::WIRE_I : {tCell::replace[dN] = tTile::WIRE_O; tCell::replace[index] = tTile::WIRE_I;} break;
            case tTile::GOLD_WIRE_O : {tCell::replace[dN] = tTile::GOLD_WIRE; tCell::replace[index] = tTile::WIRE;} break;
            case tTile::GOLD_WIRE_I : {tCell::replace[dN] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::WIRE_I;} break;
        }
        switch (tCell::matrix[dS])
        {
            case tTile::WIRE_O : {tCell::replace[dS] = tTile::WIRE; tCell::replace[index] = tTile::WIRE;} break;
            case tTile::WIRE_I : {tCell::replace[dS] = tTile::WIRE_O; tCell::replace[index] = tTile::WIRE_I;} break;
            case tTile::GOLD_WIRE_O : {tCell::replace[dS] = tTile::GOLD_WIRE; tCell::replace[index] = tTile::WIRE;} break;
            case tTile::GOLD_WIRE_I : {tCell::replace[dS] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::WIRE_I;} break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::WIRE_O : {tCell::replace[dE] = tTile::WIRE; tCell::replace[index] = tTile::WIRE;} break;
            case tTile::WIRE_I : {tCell::replace[dE] = tTile::WIRE_O; tCell::replace[index] = tTile::WIRE_I;} break;
            case tTile::GOLD_WIRE_O : {tCell::replace[dE] = tTile::GOLD_WIRE; tCell::replace[index] = tTile::WIRE;} break;
            case tTile::GOLD_WIRE_I : {tCell::replace[dE] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::WIRE_I;} break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::WIRE_O : {tCell::replace[dW] = tTile::WIRE; tCell::replace[index] = tTile::WIRE;} break;
            case tTile::WIRE_I : {tCell::replace[dW] = tTile::WIRE_O; tCell::replace[index] = tTile::WIRE_I;} break;
            case tTile::GOLD_WIRE_O : {tCell::replace[dW] = tTile::GOLD_WIRE; tCell::replace[index] = tTile::WIRE;} break;
            case tTile::GOLD_WIRE_I : {tCell::replace[dW] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::WIRE_I;} break;
        }
    }

    void GoldWire(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        switch (tCell::matrix[dN])
        {
            case tTile::WIRE_O : { tCell::replace[dN] = tTile::WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE; } break;
            case tTile::WIRE_I : { tCell::replace[dN] = tTile::WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE_I; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dN] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE; } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dN] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE_I; } break;
        }
        switch (tCell::matrix[dS])
        {
            case tTile::WIRE_O : { tCell::replace[dS] = tTile::WIRE_O; tCell::replace[index] = tTile::WIRE; } break;
            case tTile::WIRE_I : { tCell::replace[dS] = tTile::WIRE_O; tCell::replace[index] = tTile::WIRE_I; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dS] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE; } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dS] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE_I; } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::WIRE_O : { tCell::replace[dE] = tTile::WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE; } break;
            case tTile::WIRE_I : { tCell::replace[dE] = tTile::WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE_I; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dE] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE; } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dE] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE_I; } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::WIRE_O : { tCell::replace[dW] = tTile::WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE; } break;
            case tTile::WIRE_I : { tCell::replace[dW] = tTile::WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE_I; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dW] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE; } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dW] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE_I; } break;
        }
    }



    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell)
    {
        switch (current_cell)
        {
            case tTile::WIRE : { Wire(_x, _y, index); } break;
            case tTile::WIRE_O : { Wire(_x, _y, index); } break;
            case tTile::WIRE_I : { Wire(_x, _y, index); } break;
            case tTile::GOLD_WIRE : { GoldWire(_x, _y, index); } break;
            case tTile::GOLD_WIRE_O : { GoldWire(_x, _y, index); } break;
            case tTile::GOLD_WIRE_I : { GoldWire(_x, _y, index); } break;
        }
    }

}
