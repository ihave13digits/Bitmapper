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
            case tTile::WIRE_       : { tCell::replace[dN] = tTile::WIRE;       tCell::replace[index] = tTile::WIRE  ; } break;
            case tTile::WIRE_O      : { tCell::replace[dN] = tTile::WIRE_;      tCell::replace[index] = tTile::WIRE_O; } break;
            case tTile::WIRE_I      : { tCell::replace[dN] = tTile::WIRE_;      tCell::replace[index] = tTile::WIRE_I; } break;
            case tTile::GOLD_WIRE_  : { tCell::replace[dW] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::WIRE ; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dN] = tTile::GOLD_WIRE_; tCell::replace[index] = tTile::WIRE_O; } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dN] = tTile::GOLD_WIRE_; tCell::replace[index] = tTile::WIRE_I; } break;
        }
        switch (tCell::matrix[dS])
        {
            case tTile::WIRE_       : { tCell::replace[dS] = tTile::WIRE;       tCell::replace[index] = tTile::WIRE  ; } break;
            case tTile::WIRE_O      : { tCell::replace[dS] = tTile::WIRE_;      tCell::replace[index] = tTile::WIRE_O; } break;
            case tTile::WIRE_I      : { tCell::replace[dS] = tTile::WIRE_;      tCell::replace[index] = tTile::WIRE_I; } break;
            case tTile::GOLD_WIRE_  : { tCell::replace[dW] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::WIRE ; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dS] = tTile::GOLD_WIRE_; tCell::replace[index] = tTile::WIRE_O; } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dS] = tTile::GOLD_WIRE_; tCell::replace[index] = tTile::WIRE_I; } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::WIRE_       : { tCell::replace[dE] = tTile::WIRE;       tCell::replace[index] = tTile::WIRE  ; } break;
            case tTile::WIRE_O      : { tCell::replace[dE] = tTile::WIRE_;      tCell::replace[index] = tTile::WIRE_O; } break;
            case tTile::WIRE_I      : { tCell::replace[dE] = tTile::WIRE_;      tCell::replace[index] = tTile::WIRE_I; } break;
            case tTile::GOLD_WIRE_  : { tCell::replace[dW] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::WIRE ; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dE] = tTile::GOLD_WIRE_; tCell::replace[index] = tTile::WIRE_O; } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dE] = tTile::GOLD_WIRE_; tCell::replace[index] = tTile::WIRE_I; } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::WIRE_       : { tCell::replace[dW] = tTile::WIRE;       tCell::replace[index] = tTile::WIRE  ; } break;
            case tTile::WIRE_O      : { tCell::replace[dW] = tTile::WIRE_;      tCell::replace[index] = tTile::WIRE_O; } break;
            case tTile::WIRE_I      : { tCell::replace[dW] = tTile::WIRE_;      tCell::replace[index] = tTile::WIRE_I; } break;
            case tTile::GOLD_WIRE_  : { tCell::replace[dW] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::WIRE ; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dW] = tTile::GOLD_WIRE_; tCell::replace[index] = tTile::WIRE_O; } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dW] = tTile::GOLD_WIRE_; tCell::replace[index] = tTile::WIRE_I; } break;
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
            case tTile::WIRE_       : { tCell::replace[dN] = tTile::WIRE;       tCell::replace[index] = tTile::GOLD_WIRE    ; } break;
            case tTile::WIRE_O      : { tCell::replace[dN] = tTile::WIRE_;        tCell::replace[index] = tTile::GOLD_WIRE_O; } break;
            case tTile::WIRE_I      : { tCell::replace[dN] = tTile::WIRE_;      tCell::replace[index] = tTile::GOLD_WIRE_I  ; } break;
            case tTile::GOLD_WIRE_  : { tCell::replace[dW] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::GOLD_WIRE   ; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dN] = tTile::GOLD_WIRE_;   tCell::replace[index] = tTile::GOLD_WIRE_O; } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dN] = tTile::GOLD_WIRE_; tCell::replace[index] = tTile::GOLD_WIRE_I  ; } break;
        }
        switch (tCell::matrix[dS])
        {
            case tTile::WIRE_       : { tCell::replace[dN] = tTile::WIRE;       tCell::replace[index] = tTile::GOLD_WIRE    ; } break;
            case tTile::WIRE_O      : { tCell::replace[dS] = tTile::WIRE_;        tCell::replace[index] = tTile::WIRE_O     ; } break;
            case tTile::WIRE_I      : { tCell::replace[dS] = tTile::WIRE_;      tCell::replace[index] = tTile::WIRE_I       ; } break;
            case tTile::GOLD_WIRE_  : { tCell::replace[dW] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::GOLD_WIRE   ; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dS] = tTile::GOLD_WIRE_;   tCell::replace[index] = tTile::GOLD_WIRE_O; } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dS] = tTile::GOLD_WIRE_; tCell::replace[index] = tTile::GOLD_WIRE_I  ; } break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::WIRE_       : { tCell::replace[dN] = tTile::WIRE;       tCell::replace[index] = tTile::GOLD_WIRE    ; } break;
            case tTile::WIRE_O      : { tCell::replace[dE] = tTile::WIRE_;        tCell::replace[index] = tTile::GOLD_WIRE_O; } break;
            case tTile::WIRE_I      : { tCell::replace[dE] = tTile::WIRE_;      tCell::replace[index] = tTile::GOLD_WIRE_I  ; } break;
            case tTile::GOLD_WIRE_  : { tCell::replace[dW] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::GOLD_WIRE   ; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dE] = tTile::GOLD_WIRE_;   tCell::replace[index] = tTile::GOLD_WIRE_O; } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dE] = tTile::GOLD_WIRE_; tCell::replace[index] = tTile::GOLD_WIRE_I  ; } break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::WIRE_       : { tCell::replace[dN] = tTile::WIRE;       tCell::replace[index] = tTile::GOLD_WIRE    ; } break;
            case tTile::WIRE_O      : { tCell::replace[dW] = tTile::WIRE_;        tCell::replace[index] = tTile::GOLD_WIRE_O; } break;
            case tTile::WIRE_I      : { tCell::replace[dW] = tTile::WIRE_;      tCell::replace[index] = tTile::GOLD_WIRE_I  ; } break;
            case tTile::GOLD_WIRE_  : { tCell::replace[dW] = tTile::GOLD_WIRE;   tCell::replace[index] = tTile::GOLD_WIRE   ; } break;
            case tTile::GOLD_WIRE_O : { tCell::replace[dW] = tTile::GOLD_WIRE_;   tCell::replace[index] = tTile::GOLD_WIRE_O; } break;
            case tTile::GOLD_WIRE_I : { tCell::replace[dW] = tTile::GOLD_WIRE_; tCell::replace[index] = tTile::GOLD_WIRE_I  ; } break;
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

        bool a = false;
        bool b = false;
        bool o = false;

        if      (tCell::matrix[dN] == tTile::WIRE_O || tCell::matrix[dN] == tTile::GOLD_WIRE_O) { a = false; }
        if      (tCell::matrix[dN] == tTile::WIRE_I || tCell::matrix[dN] == tTile::GOLD_WIRE_I) { a = true;  }

        if      (tCell::matrix[dS] == tTile::WIRE_O || tCell::matrix[dS] == tTile::GOLD_WIRE_O) { b = false; }
        if      (tCell::matrix[dS] == tTile::WIRE_I || tCell::matrix[dS] == tTile::GOLD_WIRE_I) { b = true;  }

        if (a==false && b==false) { o = false; }
        if (a==true  && b==false) { o = true;  }
        if (a==false && b==true ) { o = true;  }
        if (a==true  && b==true ) { o = true;  }

        if (o == true)
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_I;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_I;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_I; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_I; }
        }
        else
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_O;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_O;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_O; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_O; }
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

        bool a = false;
        bool b = false;
        bool o = false;

        if      (tCell::matrix[dN] == tTile::WIRE_O || tCell::matrix[dN] == tTile::GOLD_WIRE_O) { a = false; }
        if      (tCell::matrix[dN] == tTile::WIRE_I || tCell::matrix[dN] == tTile::GOLD_WIRE_I) { a = true;  }

        if      (tCell::matrix[dS] == tTile::WIRE_O || tCell::matrix[dS] == tTile::GOLD_WIRE_O) { b = false; }
        if      (tCell::matrix[dS] == tTile::WIRE_I || tCell::matrix[dS] == tTile::GOLD_WIRE_I) { b = true;  }

        if (a==false && b==false) { o = false; }
        if (a==true  && b==false) { o = true;  }
        if (a==false && b==true ) { o = true;  }
        if (a==true  && b==true ) { o = false; }

        if (o == true)
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_I;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_I;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_I; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_I; }
        }
        else
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_O;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_O;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_O; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_O; }
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

        bool a = false;
        bool b = false;
        bool o = false;

        if      (tCell::matrix[dN] == tTile::WIRE_O || tCell::matrix[dN] == tTile::GOLD_WIRE_O) { a = false; }
        if      (tCell::matrix[dN] == tTile::WIRE_I || tCell::matrix[dN] == tTile::GOLD_WIRE_I) { a = true;  }

        if      (tCell::matrix[dS] == tTile::WIRE_O || tCell::matrix[dS] == tTile::GOLD_WIRE_O) { b = false; }
        if      (tCell::matrix[dS] == tTile::WIRE_I || tCell::matrix[dS] == tTile::GOLD_WIRE_I) { b = true;  }

        if (a==false && b==false) { o = true;  }
        if (a==true  && b==false) { o = false; }
        if (a==false && b==true ) { o = false; }
        if (a==true  && b==true ) { o = true;  }

        if (o == true)
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_I;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_I;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_I; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_I; }
        }
        else
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_O;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_O;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_O; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_O; }
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

        bool a = false;
        bool b = false;
        bool o = false;

        if      (tCell::matrix[dN] == tTile::WIRE_O || tCell::matrix[dN] == tTile::GOLD_WIRE_O) { a = false; }
        if      (tCell::matrix[dN] == tTile::WIRE_I || tCell::matrix[dN] == tTile::GOLD_WIRE_I) { a = true;  }

        if      (tCell::matrix[dS] == tTile::WIRE_O || tCell::matrix[dS] == tTile::GOLD_WIRE_O) { b = false; }
        if      (tCell::matrix[dS] == tTile::WIRE_I || tCell::matrix[dS] == tTile::GOLD_WIRE_I) { b = true;  }

        if (a==false && b==false) { o = true;  }
        if (a==true  && b==false) { o = false; }
        if (a==false && b==true ) { o = false; }
        if (a==true  && b==true ) { o = false; }

        if (o == true)
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_I;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_I;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_I; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_I; }
        }
        else
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_O;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_O;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_O; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_O; }
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

        bool a = false;
        bool b = false;
        bool o = false;

        if      (tCell::matrix[dN] == tTile::WIRE_O || tCell::matrix[dN] == tTile::GOLD_WIRE_O) { a = false; }
        if      (tCell::matrix[dN] == tTile::WIRE_I || tCell::matrix[dN] == tTile::GOLD_WIRE_I) { a = true;  }

        if      (tCell::matrix[dS] == tTile::WIRE_O || tCell::matrix[dS] == tTile::GOLD_WIRE_O) { b = false; }
        if      (tCell::matrix[dS] == tTile::WIRE_I || tCell::matrix[dS] == tTile::GOLD_WIRE_I) { b = true;  }

        if (a==false && b==false) { o = false; }
        if (a==true  && b==false) { o = false; }
        if (a==false && b==true ) { o = false; }
        if (a==true  && b==true ) { o = true;  }

        if (o == true)
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_I;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_I;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_I; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_I; }
        }
        else
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_O;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_O;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_O; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_O; }
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

        bool a = false;
        bool b = false;
        bool o = false;

        if      (tCell::matrix[dN] == tTile::WIRE_O || tCell::matrix[dN] == tTile::GOLD_WIRE_O) { a = false; }
        if      (tCell::matrix[dN] == tTile::WIRE_I || tCell::matrix[dN] == tTile::GOLD_WIRE_I) { a = true;  }

        if      (tCell::matrix[dS] == tTile::WIRE_O || tCell::matrix[dS] == tTile::GOLD_WIRE_O) { b = false; }
        if      (tCell::matrix[dS] == tTile::WIRE_I || tCell::matrix[dS] == tTile::GOLD_WIRE_I) { b = true;  }

        if (a==false && b==false) { o = true;  }
        if (a==true  && b==false) { o = true;  }
        if (a==false && b==true ) { o = true;  }
        if (a==true  && b==true ) { o = false; }

        if (o == true)
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_I;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_I;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_I; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_I; }
        }
        else
        {
            if      (tCell::matrix[dE] == tTile::WIRE)      { tCell::replace[dE] = tTile::WIRE_O;      }
            else if (tCell::matrix[dW] == tTile::WIRE)      { tCell::replace[dW] = tTile::WIRE_O;      }
            else if (tCell::matrix[dE] == tTile::GOLD_WIRE) { tCell::replace[dE] = tTile::GOLD_WIRE_O; }
            else if (tCell::matrix[dW] == tTile::GOLD_WIRE) { tCell::replace[dW] = tTile::GOLD_WIRE_O; }
        }
    }



    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell)
    {
        switch (current_cell)
        {
            case tTile::WIRE        : { Wire(_x, _y, index);     } break;
            case tTile::WIRE_       : { Wire(_x, _y, index);     } break;
            case tTile::WIRE_O      : { Wire(_x, _y, index);     } break;
            case tTile::WIRE_I      : { Wire(_x, _y, index);     } break;
            case tTile::GOLD_WIRE   : { GoldWire(_x, _y, index); } break;
            case tTile::GOLD_WIRE_  : { GoldWire(_x, _y, index); } break;
            case tTile::GOLD_WIRE_O : { GoldWire(_x, _y, index); } break;
            case tTile::GOLD_WIRE_I : { GoldWire(_x, _y, index); } break;
            case tTile::OR_GATE     : { OR(_x, _y, index);       } break;
            case tTile::AND_GATE    : { AND(_x, _y, index);      } break;
            case tTile::NOT_GATE    : { NOT(_x, _y, index);      } break;
            case tTile::XOR_GATE    : { XOR(_x, _y, index);      } break;
            case tTile::XNOR_GATE   : { XNOR(_x, _y, index);     } break;
            case tTile::NAND_GATE   : { NAND(_x, _y, index);     } break;
        }
    }

}
