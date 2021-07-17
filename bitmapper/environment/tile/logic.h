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
            case tTile::WIRE_O      : { tCell::replace[dN] = tTile::WIRE;        tCell::replace[index] = tTile::WIRE;   } break;
            case tTile::WIRE_I      : { tCell::replace[dN] = tTile::WIRE_O;      tCell::replace[index] = tTile::WIRE_I; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dN] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::WIRE;   } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dN] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::WIRE_I; } break;
        }
        switch (tCell::matrix[dS])
        {
            case tTile::WIRE_O      : { tCell::replace[dS] = tTile::WIRE;        tCell::replace[index] = tTile::WIRE;   } break;
            case tTile::WIRE_I      : { tCell::replace[dS] = tTile::WIRE_O;      tCell::replace[index] = tTile::WIRE_I; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dS] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::WIRE;   } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dS] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::WIRE_I; } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::WIRE_O      : { tCell::replace[dE] = tTile::WIRE;        tCell::replace[index] = tTile::WIRE;   } break;
            case tTile::WIRE_I      : { tCell::replace[dE] = tTile::WIRE_O;      tCell::replace[index] = tTile::WIRE_I; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dE] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::WIRE;   } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dE] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::WIRE_I; } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::WIRE_O      : { tCell::replace[dW] = tTile::WIRE;        tCell::replace[index] = tTile::WIRE;   } break;
            case tTile::WIRE_I      : { tCell::replace[dW] = tTile::WIRE_O;      tCell::replace[index] = tTile::WIRE_I; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dW] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::WIRE;   } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dW] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::WIRE_I; } break;
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
            case tTile::WIRE_O      : { tCell::replace[dN] = tTile::WIRE;        tCell::replace[index] = tTile::GOLD_WIRE;   } break;
            case tTile::WIRE_I      : { tCell::replace[dN] = tTile::WIRE_O;      tCell::replace[index] = tTile::GOLD_WIRE_I; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dN] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::GOLD_WIRE;   } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dN] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE_I; } break;
        }
        switch (tCell::matrix[dS])
        {
            case tTile::WIRE_O      : { tCell::replace[dS] = tTile::WIRE;        tCell::replace[index] = tTile::WIRE;        } break;
            case tTile::WIRE_I      : { tCell::replace[dS] = tTile::WIRE_O;      tCell::replace[index] = tTile::WIRE_I;      } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dS] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::GOLD_WIRE;   } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dS] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE_I; } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::WIRE_O      : { tCell::replace[dE] = tTile::WIRE;        tCell::replace[index] = tTile::GOLD_WIRE;   } break;
            case tTile::WIRE_I      : { tCell::replace[dE] = tTile::WIRE_O;      tCell::replace[index] = tTile::GOLD_WIRE_I; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dE] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::GOLD_WIRE;   } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dE] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE_I; } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::WIRE_O      : { tCell::replace[dW] = tTile::WIRE;        tCell::replace[index] = tTile::GOLD_WIRE;   } break;
            case tTile::WIRE_I      : { tCell::replace[dW] = tTile::WIRE_O;      tCell::replace[index] = tTile::GOLD_WIRE_I; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dW] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::GOLD_WIRE;   } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dW] = tTile::GOLD_WIRE_O; tCell::replace[index] = tTile::GOLD_WIRE_I; } break;
        }
    }

    void OR(int _x, int _y, int index)
    {
        // a   b   o
        // 0 | 0 | 0
        // 1 | 0 | 1
        // 0 | 1 | 1
        // 1 | 1 | 1
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        bool a;
        bool b;
        bool o = false;

        if      (tCell::matrix[dN] == tTile::WIRE_I || tCell::matrix[dN] == tTile::GOLD_WIRE_I) { a = true;  }
        else if (tCell::matrix[dN] == tTile::WIRE_O || tCell::matrix[dN] == tTile::GOLD_WIRE_O) { a = false; }
        if      (tCell::matrix[dS] == tTile::WIRE_I || tCell::matrix[dS] == tTile::GOLD_WIRE_I) { b = true;  }
        else if (tCell::matrix[dS] == tTile::WIRE_O || tCell::matrix[dS] == tTile::GOLD_WIRE_O) { b = false; }

        if (!a && !b) { o = false; }
        if (a && !b)  { o = true; }
        if (!a && b)  { o = true; }
        if (a && b)   { o = true; }

        if (o == true)
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_I;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_I;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_I; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_I; }
        }
    }

    void XOR(int _x, int _y, int index)
    {
        // a   b   o
        // 0 | 0 | 0
        // 1 | 0 | 1
        // 0 | 1 | 1
        // 1 | 1 | 0
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        bool a;
        bool b;
        bool o;

        if      (tCell::matrix[dN] == tTile::WIRE_I || tCell::matrix[dN] == tTile::GOLD_WIRE_I) { a = true;  }
        else if (tCell::matrix[dN] == tTile::WIRE_O || tCell::matrix[dN] == tTile::GOLD_WIRE_O) { a = false; }
        if      (tCell::matrix[dS] == tTile::WIRE_I || tCell::matrix[dS] == tTile::GOLD_WIRE_I) { b = true;  }
        else if (tCell::matrix[dS] == tTile::WIRE_O || tCell::matrix[dS] == tTile::GOLD_WIRE_O) { b = false; }

        if (!a && !b) { o = false; }
        if (a && !b)  { o = true; }
        if (!a && b)  { o = true; }
        if (a && b)   { o = false; }

        if (o == true)
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_I;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_I;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_I; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_I; }
        }
    }

    void XNOR(int _x, int _y, int index)
    {
        // a   b   o
        // 0 | 0 | 1
        // 1 | 0 | 0
        // 0 | 1 | 0
        // 1 | 1 | 1
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        bool a;
        bool b;
        bool o;

        if      (tCell::matrix[dN] == tTile::WIRE_I || tCell::matrix[dN] == tTile::GOLD_WIRE_I) { a = true;  }
        else if (tCell::matrix[dN] == tTile::WIRE_O || tCell::matrix[dN] == tTile::GOLD_WIRE_O) { a = false; }
        if      (tCell::matrix[dS] == tTile::WIRE_I || tCell::matrix[dS] == tTile::GOLD_WIRE_I) { b = true;  }
        else if (tCell::matrix[dS] == tTile::WIRE_O || tCell::matrix[dS] == tTile::GOLD_WIRE_O) { b = false; }

        if (!a && !b) { o = true; }
        if (a && !b)  { o = false; }
        if (!a && b)  { o = false; }
        if (a && b)   { o = true; }

        if (o == true)
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_I;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_I;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_I; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_I; }
        }
    }
    
    void NOT(int _x, int _y, int index)
    {
        // a   b   o
        // 0 | 0 | 1
        // 1 | 0 | 0
        // 0 | 1 | 0
        // 1 | 1 | 0
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        bool a;
        bool b;
        bool o;

        if      (tCell::matrix[dN] == tTile::WIRE_I || tCell::matrix[dN] == tTile::GOLD_WIRE_I) { a = true;  }
        else if (tCell::matrix[dN] == tTile::WIRE_O || tCell::matrix[dN] == tTile::GOLD_WIRE_O) { a = false; }
        if      (tCell::matrix[dS] == tTile::WIRE_I || tCell::matrix[dS] == tTile::GOLD_WIRE_I) { b = true;  }
        else if (tCell::matrix[dS] == tTile::WIRE_O || tCell::matrix[dS] == tTile::GOLD_WIRE_O) { b = false; }

        if (!a && !b) { o = true; }
        if (a && !b)  { o = false; }
        if (!a && b)  { o = false; }
        if (a && b)   { o = false; }

        if (o == true)
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_I;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_I;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_I; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_I; }
        }
    }
    
    void AND(int _x, int _y, int index)
    {
        // a   b   o
        // 0 | 0 | 0
        // 1 | 0 | 0
        // 0 | 1 | 0
        // 1 | 1 | 1
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        bool a;
        bool b;
        bool o;

        if      (tCell::matrix[dN] == tTile::WIRE_I || tCell::matrix[dN] == tTile::GOLD_WIRE_I) { a = true;  }
        else if (tCell::matrix[dN] == tTile::WIRE_O || tCell::matrix[dN] == tTile::GOLD_WIRE_O) { a = false; }
        if      (tCell::matrix[dS] == tTile::WIRE_I || tCell::matrix[dS] == tTile::GOLD_WIRE_I) { b = true;  }
        else if (tCell::matrix[dS] == tTile::WIRE_O || tCell::matrix[dS] == tTile::GOLD_WIRE_O) { b = false; }

        if (!a && !b) { o = false; }
        if (a && !b)  { o = false; }
        if (!a && b)  { o = false; }
        if (a && b)   { o = true; }

        if (o == true)
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_I;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_I;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_I; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_I; }
        }
    }
    
    void NAND(int _x, int _y, int index)
    {
        // a   b   o
        // 0 | 0 | 1
        // 1 | 0 | 1
        // 0 | 1 | 1
        // 1 | 1 | 0
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        bool a;
        bool b;
        bool o;

        if      (tCell::matrix[dN] == tTile::WIRE_I || tCell::matrix[dN] == tTile::GOLD_WIRE_I) { a = true;  }
        else if (tCell::matrix[dN] == tTile::WIRE_O || tCell::matrix[dN] == tTile::GOLD_WIRE_O) { a = false; }
        if      (tCell::matrix[dS] == tTile::WIRE_I || tCell::matrix[dS] == tTile::GOLD_WIRE_I) { b = true;  }
        else if (tCell::matrix[dS] == tTile::WIRE_O || tCell::matrix[dS] == tTile::GOLD_WIRE_O) { b = false; }

        if (!a && !b) { o = true; }
        if (a && !b)  { o = true; }
        if (!a && b)  { o = true; }
        if (a && b)   { o = false; }

        if (o == true)
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_I;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_I;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_I; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_I; }
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
            case tTile::OR_GATE : { OR(_x, _y, index); } break;
            case tTile::AND_GATE : { AND(_x, _y, index); } break;
            case tTile::NOT_GATE : { NOT(_x, _y, index); } break;
            case tTile::XOR_GATE : { XOR(_x, _y, index); } break;
            case tTile::XNOR_GATE : { XNOR(_x, _y, index); } break;
            case tTile::NAND_GATE : { NAND(_x, _y, index); } break;
        }
    }

}
