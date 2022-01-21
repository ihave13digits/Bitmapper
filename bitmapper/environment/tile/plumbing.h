namespace tPlumbing
{

    //
    // Special
    //
    
    void Pipe(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        if (tTool::GetType(tCell::matrix[dE]) == tTile::PIPES)
        {
            if      (tCell::matrix[dW] == tTile::PIPE) { tTool::Set(dW, tCell::matrix[dE]); tTool::Set(dE, tTile::PIPE); }
            else if (tCell::matrix[dN] == tTile::PIPE) { tTool::Set(dW, tCell::matrix[dN]); tTool::Set(dN, tTile::PIPE); }
        }
        else if (tTool::GetType(tCell::matrix[dW]) == tTile::PIPES)
        {
            if      (tCell::matrix[dE] == tTile::PIPE) { tTool::Set(dE, tCell::matrix[dW]); tTool::Set(dW, tTile::PIPE); }
            else if (tCell::matrix[dN] == tTile::PIPE) { tTool::Set(dE, tCell::matrix[dN]); tTool::Set(dN, tTile::PIPE); }
        }
        else if (tTool::GetType(tCell::matrix[dS]) == tTile::PIPES)
        { if (tCell::matrix[dN] == tTile::PIPE) { tTool::Set(dN, tCell::matrix[dS]); tTool::Set(dS, tTile::PIPE); } }
        else if (tTool::GetType(tCell::matrix[dS]) == tTile::FLUID || tTool::GetType(tCell::matrix[dS]) == tTile::GEL)
        {
            switch (tCell::matrix[dS])
            {
                case tTile::MILK        : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_MILK;} break;
                case tTile::MERCURY     : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_MERCURY;} break;
                case tTile::OIL         : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_OIL;} break;
                case tTile::ACID        : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_ACID;} break;
                case tTile::WATER       : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_WATER;} break;
                case tTile::BRINE       : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_BRINE;} break;
                case tTile::WINE        : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_WINE;} break;
                case tTile::GUTS        : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_GUTS;} break;
                case tTile::ALGAE       : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_ALGAE;} break;
                case tTile::SLIME       : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_SLIME;} break;
                case tTile::HONEY       : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_HONEY;} break;
                case tTile::BLOOD       : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_BLOOD;} break;
                case tTile::MAGMA       : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_MAGMA;} break;
                case tTile::LAVA        : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_LAVA;} break;
                case tTile::MUCK        : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_MUCK;} break;
                case tTile::MUD         : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_MUD;} break;
                case tTile::QUICKSAND   : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_QUICKSAND;} break;
                case tTile::MOLTEN_SLAG : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_MOLTEN_SLAG;} break;
            }
        }
    }

    void Pump(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        if (tCell::matrix[dN] == tTile::AIR)
        {
            switch (tCell::matrix[dS])
            {
                case tTile::PIPE :             {tCell::replace[dN] = tTile::HIGHLY_COMPRESSED_AIR;} break;
                case tTile::PIPE_MILK        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::MILK;} break;
                case tTile::PIPE_MERCURY     : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::MERCURY;} break;
                case tTile::PIPE_OIL         : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::OIL;} break;
                case tTile::PIPE_ACID        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::ACID;} break;
                case tTile::PIPE_WATER       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::WATER;} break;
                case tTile::PIPE_BRINE       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::BRINE;} break;
                case tTile::PIPE_WINE        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::WINE;} break;
                case tTile::PIPE_GUTS        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::GUTS;} break;
                case tTile::PIPE_ALGAE       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::ALGAE;} break;
                case tTile::PIPE_SLIME       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::SLIME;} break;
                case tTile::PIPE_HONEY       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::HONEY;} break;
                case tTile::PIPE_BLOOD       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::BLOOD;} break;
                case tTile::PIPE_MAGMA       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::MAGMA;} break;
                case tTile::PIPE_LAVA        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::LAVA;} break;
                case tTile::PIPE_MUCK        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::MUCK;} break;
                case tTile::PIPE_MUD         : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::MUD;} break;
                case tTile::PIPE_QUICKSAND   : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::QUICKSAND;} break;
                case tTile::PIPE_MOLTEN_SLAG : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::MOLTEN_SLAG;} break;
            }
        }
        else
        {
            if (tCell::matrix[dS] == tTile::PIPE)
            {
                switch (tCell::matrix[dN])
                {
                    case tTile::MILDLY_COMPRESSED_AIR :
                    {
                        tCell::replace[dN] = tTile::COMPRESSED_AIR;
                        if      (tCell::matrix[dN-1] == tTile::AIR) {tCell::replace[dN-1] = tTile::MILDLY_COMPRESSED_AIR;}
                        else if (tCell::matrix[dN-1] == tTile::MILDLY_COMPRESSED_AIR) {tCell::replace[dN-1] = tTile::COMPRESSED_AIR;}
                        else if (tCell::matrix[dN-1] == tTile::COMPRESSED_AIR) {tCell::replace[dN-1] = tTile::HIGHLY_COMPRESSED_AIR;}
                        if      (tCell::matrix[dN+1] == tTile::AIR) {tCell::replace[dN+1] = tTile::MILDLY_COMPRESSED_AIR;}
                        else if (tCell::matrix[dN+1] == tTile::MILDLY_COMPRESSED_AIR) {tCell::replace[dN+1] = tTile::COMPRESSED_AIR;}
                        else if (tCell::matrix[dN+1] == tTile::COMPRESSED_AIR) {tCell::replace[dN+1] = tTile::HIGHLY_COMPRESSED_AIR;}
                    } break;
                    case tTile::COMPRESSED_AIR :
                    {
                        tCell::replace[dN] = tTile::HIGHLY_COMPRESSED_AIR;
                        if      (tCell::matrix[dN-1] == tTile::AIR) {tCell::replace[dN-1] = tTile::MILDLY_COMPRESSED_AIR;}
                        else if (tCell::matrix[dN-1] == tTile::MILDLY_COMPRESSED_AIR) {tCell::replace[dN-1] = tTile::COMPRESSED_AIR;}
                        else if (tCell::matrix[dN-1] == tTile::COMPRESSED_AIR) {tCell::replace[dN-1] = tTile::HIGHLY_COMPRESSED_AIR;}
                        if      (tCell::matrix[dN+1] == tTile::AIR) {tCell::replace[dN+1] = tTile::MILDLY_COMPRESSED_AIR;}
                        else if (tCell::matrix[dN+1] == tTile::MILDLY_COMPRESSED_AIR) {tCell::replace[dN+1] = tTile::COMPRESSED_AIR;}
                        else if (tCell::matrix[dN+1] == tTile::COMPRESSED_AIR) {tCell::replace[dN+1] = tTile::HIGHLY_COMPRESSED_AIR;}
                    } break;
                    case tTile::HIGHLY_COMPRESSED_AIR :
                    {
                        if      (tCell::matrix[dN-1] == tTile::AIR) {tCell::replace[dN-1] = tTile::MILDLY_COMPRESSED_AIR;}
                        else if (tCell::matrix[dN-1] == tTile::MILDLY_COMPRESSED_AIR) {tCell::replace[dN-1] = tTile::COMPRESSED_AIR;}
                        else if (tCell::matrix[dN-1] == tTile::COMPRESSED_AIR) {tCell::replace[dN-1] = tTile::HIGHLY_COMPRESSED_AIR;}
                        if      (tCell::matrix[dN+1] == tTile::AIR) {tCell::replace[dN+1] = tTile::MILDLY_COMPRESSED_AIR;}
                        else if (tCell::matrix[dN+1] == tTile::MILDLY_COMPRESSED_AIR) {tCell::replace[dN+1] = tTile::COMPRESSED_AIR;}
                        else if (tCell::matrix[dN+1] == tTile::COMPRESSED_AIR) {tCell::replace[dN+1] = tTile::HIGHLY_COMPRESSED_AIR;}
                    } break;
                }
            }
        }
    }

    void Gutter(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        if (tTool::GetType(tCell::matrix[dE]) == tTile::GUTTERS)
        {
            if      (tCell::matrix[dW] == tTile::GUTTER) { tTool::Set(dW, tCell::matrix[dE]); tTool::Set(dE, tTile::GUTTER); }
            else if (tCell::matrix[dS] == tTile::GUTTER) { tTool::Set(dS, tCell::matrix[dE]); tTool::Set(dE, tTile::GUTTER); }
        }
        else if (tTool::GetType(tCell::matrix[dW]) == tTile::GUTTERS)
        {
            if      (tCell::matrix[dE] == tTile::GUTTER) { tTool::Set(dE, tCell::matrix[dW]); tTool::Set(dW, tTile::GUTTER); }
            else if (tCell::matrix[dS] == tTile::GUTTER) { tTool::Set(dS, tCell::matrix[dW]); tTool::Set(dW, tTile::GUTTER); }
        }
        else if (tTool::GetType(tCell::matrix[dN]) == tTile::GUTTERS)
        { if (tCell::matrix[dS] == tTile::GUTTER) { tTool::Set(dS, tCell::matrix[dN]); tTool::Set(dN, tTile::GUTTER); } }
        else if (tTool::GetType(tCell::matrix[dN]) == tTile::FLUID || tTool::GetType(tCell::matrix[dN]) == tTile::GEL)
        {
            switch (tCell::matrix[dN])
            {
                case tTile::MILK        : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_MILK;} break;
                case tTile::MERCURY     : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_MERCURY;} break;
                case tTile::OIL         : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_OIL;} break;
                case tTile::ACID        : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_ACID;} break;
                case tTile::WATER       : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_WATER;} break;
                case tTile::BRINE       : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_BRINE;} break;
                case tTile::WINE        : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_WINE;} break;
                case tTile::GUTS        : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_GUTS;} break;
                case tTile::ALGAE       : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_ALGAE;} break;
                case tTile::SLIME       : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_SLIME;} break;
                case tTile::HONEY       : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_HONEY;} break;
                case tTile::BLOOD       : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_BLOOD;} break;
                case tTile::MAGMA       : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_MAGMA;} break;
                case tTile::LAVA        : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_LAVA;} break;
                case tTile::MUCK        : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_MUCK;} break;
                case tTile::MUD         : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_MUD;} break;
                case tTile::QUICKSAND   : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_QUICKSAND;} break;
                case tTile::MOLTEN_SLAG : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_MOLTEN_SLAG;} break;
            }
        }
    }

    void Drain(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        if (tCell::matrix[dS] == tTile::AIR)
        {
            switch (tCell::matrix[dN])
            {
                case tTile::GUTTER_MILK        : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::MILK;} break;
                case tTile::GUTTER_MERCURY     : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::MERCURY;} break;
                case tTile::GUTTER_OIL         : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::OIL;} break;
                case tTile::GUTTER_ACID        : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::ACID;} break;
                case tTile::GUTTER_WATER       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::WATER;} break;
                case tTile::GUTTER_BRINE       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::BRINE;} break;
                case tTile::GUTTER_WINE        : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::WINE;} break;
                case tTile::GUTTER_GUTS        : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::GUTS;} break;
                case tTile::GUTTER_ALGAE       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::ALGAE;} break;
                case tTile::GUTTER_SLIME       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::SLIME;} break;
                case tTile::GUTTER_HONEY       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::HONEY;} break;
                case tTile::GUTTER_BLOOD       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::BLOOD;} break;
                case tTile::GUTTER_MAGMA       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::MAGMA;} break;
                case tTile::GUTTER_LAVA        : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::LAVA;} break;
                case tTile::GUTTER_MUCK        : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::MUCK;} break;
                case tTile::GUTTER_MUD         : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::MUD;} break;
                case tTile::GUTTER_QUICKSAND   : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::QUICKSAND;} break;
                case tTile::GUTTER_MOLTEN_SLAG : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::MOLTEN_SLAG;} break;
            }
        }
    }

    void ValveOpen(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        
        if (tTool::GetType(tCell::matrix[dE]) == tTile::PIPES)
        { if (tCell::matrix[dW] == tTile::PIPE) { tTool::Set(dW, tCell::matrix[dE]); tTool::Set(dE, tTile::PIPE); } }
        else if (tTool::GetType(tCell::matrix[dW]) == tTile::PIPES)
        { if (tCell::matrix[dE] == tTile::PIPE) { tTool::Set(dE, tCell::matrix[dW]); tTool::Set(dW, tTile::PIPE); } }
        else if (tTool::GetType(tCell::matrix[dS]) == tTile::PIPES)
        { if (tCell::matrix[dN] == tTile::PIPE) { tTool::Set(dN, tCell::matrix[dS]); tTool::Set(dS, tTile::PIPE); } }
        
        else if (tTool::GetType(tCell::matrix[dE]) == tTile::GUTTERS)
        { if (tCell::matrix[dW] == tTile::GUTTER) { tTool::Set(dW, tCell::matrix[dE]); tTool::Set(dE, tTile::GUTTER); } }
        else if (tTool::GetType(tCell::matrix[dW]) == tTile::GUTTERS)
        { if (tCell::matrix[dE] == tTile::GUTTER) { tTool::Set(dE, tCell::matrix[dW]); tTool::Set(dW, tTile::GUTTER); } }
        else if (tTool::GetType(tCell::matrix[dN]) == tTile::GUTTERS)
        { if (tCell::matrix[dS] == tTile::GUTTER) { tTool::Set(dS, tCell::matrix[dN]); tTool::Set(dN, tTile::GUTTER); } }
    }



    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell)
    {
        switch (current_cell)
        {
            case tTile::PIPE : { Pipe(_x, _y, index); } break;
            case tTile::PUMP : { Pump(_x, _y, index); } break;
            case tTile::GUTTER : { Gutter(_x, _y, index); } break;
            case tTile::DRAIN : { Drain(_x, _y, index); } break;
            case tTile::VALVE_OPEN : { ValveOpen(_x, _y, index); } break;
        }
    }

}
