namespace tPlumbing
{

    //
    // Special
    //
    
    void Pipe(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        switch (tCell::matrix[dE])
        {
            case tTile::PIPE_MILK        : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MILK;} break;
            case tTile::PIPE_MERCURY     : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MERCURY;} break;
            case tTile::PIPE_OIL         : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_OIL;} break;
            case tTile::PIPE_ACID        : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_ACID;} break;
            case tTile::PIPE_WATER       : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_WATER;} break;
            case tTile::PIPE_BRINE       : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_BRINE;} break;
            case tTile::PIPE_WINE        : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_WINE;} break;
            case tTile::PIPE_GUTS        : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_GUTS;} break;
            case tTile::PIPE_ALGAE       : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_ALGAE;} break;
            case tTile::PIPE_HONEY       : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_HONEY;} break;
            case tTile::PIPE_BLOOD       : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_BLOOD;} break;
            case tTile::PIPE_MAGMA       : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MAGMA;} break;
            case tTile::PIPE_LAVA        : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_LAVA;} break;
            case tTile::PIPE_MUCK        : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MUCK;} break;
            case tTile::PIPE_MUD         : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MUD;} break;
            case tTile::PIPE_MOLTEN_SLAG : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MOLTEN_SLAG;} break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::PIPE_MILK        : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MILK;} break;
            case tTile::PIPE_MERCURY     : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MERCURY;} break;
            case tTile::PIPE_OIL         : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_OIL;} break;
            case tTile::PIPE_ACID        : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_ACID;} break;
            case tTile::PIPE_WATER       : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_WATER;} break;
            case tTile::PIPE_BRINE       : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_BRINE;} break;
            case tTile::PIPE_WINE        : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_WINE;} break;
            case tTile::PIPE_GUTS        : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_GUTS;} break;
            case tTile::PIPE_ALGAE       : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_ALGAE;} break;
            case tTile::PIPE_HONEY       : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_HONEY;} break;
            case tTile::PIPE_BLOOD       : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_BLOOD;} break;
            case tTile::PIPE_MAGMA       : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MAGMA;} break;
            case tTile::PIPE_LAVA        : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_LAVA;} break;
            case tTile::PIPE_MUCK        : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MUCK;} break;
            case tTile::PIPE_MUD         : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MUD;} break;
            case tTile::PIPE_MOLTEN_SLAG : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MOLTEN_SLAG;} break;
        }
        switch (tCell::matrix[dS])
        {
            case tTile::PIPE_MILK        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MILK;} break;
            case tTile::PIPE_MERCURY     : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MERCURY;} break;
            case tTile::PIPE_OIL         : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_OIL;} break;
            case tTile::PIPE_ACID        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_ACID;} break;
            case tTile::PIPE_WATER       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_WATER;} break;
            case tTile::PIPE_BRINE       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_BRINE;} break;
            case tTile::PIPE_WINE        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_WINE;} break;
            case tTile::PIPE_GUTS        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_GUTS;} break;
            case tTile::PIPE_ALGAE       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_ALGAE;} break;
            case tTile::PIPE_HONEY       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_HONEY;} break;
            case tTile::PIPE_BLOOD       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_BLOOD;} break;
            case tTile::PIPE_MAGMA       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MAGMA;} break;
            case tTile::PIPE_LAVA        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_LAVA;} break;
            case tTile::PIPE_MUCK        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MUCK;} break;
            case tTile::PIPE_MUD         : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MUD;} break;
            case tTile::PIPE_MOLTEN_SLAG : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MOLTEN_SLAG;} break;
            case tTile::MILK             : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_MILK;} break;
            case tTile::MERCURY          : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_MERCURY;} break;
            case tTile::OIL              : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_OIL;} break;
            case tTile::ACID             : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_ACID;} break;
            case tTile::WATER            : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_WATER;} break;
            case tTile::BRINE            : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_BRINE;} break;
            case tTile::WINE             : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_WINE;} break;
            case tTile::GUTS             : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_GUTS;} break;
            case tTile::ALGAE            : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_ALGAE;} break;
            case tTile::HONEY            : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_HONEY;} break;
            case tTile::BLOOD            : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_BLOOD;} break;
            case tTile::MAGMA            : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_MAGMA;} break;
            case tTile::LAVA             : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_LAVA;} break;
            case tTile::MUCK             : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_MUCK;} break;
            case tTile::MUD              : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_MUD;} break;
            case tTile::MOLTEN_SLAG      : {tCell::replace[dS] = tTile::AIR; tCell::matrix[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_MOLTEN_SLAG;} break;
        }
    }

    void Pump(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        if (tCell::matrix[dN] == tTile::AIR)
        {
            switch (tCell::matrix[dS])
            {
                case tTile::PIPE_MILK        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::MILK;} break;
                case tTile::PIPE_MERCURY     : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::MERCURY;} break;
                case tTile::PIPE_OIL         : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::OIL;} break;
                case tTile::PIPE_ACID        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::ACID;} break;
                case tTile::PIPE_WATER       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::WATER;} break;
                case tTile::PIPE_BRINE       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::BRINE;} break;
                case tTile::PIPE_WINE        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::WINE;} break;
                case tTile::PIPE_GUTS        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::GUTS;} break;
                case tTile::PIPE_ALGAE       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::ALGAE;} break;
                case tTile::PIPE_HONEY       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::HONEY;} break;
                case tTile::PIPE_BLOOD       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::BLOOD;} break;
                case tTile::PIPE_MAGMA       : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::MAGMA;} break;
                case tTile::PIPE_LAVA        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::LAVA;} break;
                case tTile::PIPE_MUCK        : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::MUCK;} break;
                case tTile::PIPE_MUD         : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::MUD;} break;
                case tTile::PIPE_MOLTEN_SLAG : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::MOLTEN_SLAG;} break;
            }
        }
    }

    void Gutter(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        switch (tCell::matrix[dE])
        {
            case tTile::GUTTER_MILK        : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MILK;} break;
            case tTile::GUTTER_MERCURY     : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MERCURY;} break;
            case tTile::GUTTER_OIL         : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_OIL;} break;
            case tTile::GUTTER_ACID        : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_ACID;} break;
            case tTile::GUTTER_WATER       : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_WATER;} break;
            case tTile::GUTTER_BRINE       : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_BRINE;} break;
            case tTile::GUTTER_WINE        : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_WINE;} break;
            case tTile::GUTTER_GUTS        : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_GUTS;} break;
            case tTile::GUTTER_ALGAE       : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_ALGAE;} break;
            case tTile::GUTTER_HONEY       : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_HONEY;} break;
            case tTile::GUTTER_BLOOD       : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_BLOOD;} break;
            case tTile::GUTTER_MAGMA       : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MAGMA;} break;
            case tTile::GUTTER_LAVA        : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_LAVA;} break;
            case tTile::GUTTER_MUCK        : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MUCK;} break;
            case tTile::GUTTER_MUD         : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MUD;} break;
            case tTile::GUTTER_MOLTEN_SLAG : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MOLTEN_SLAG;} break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::GUTTER_MILK        : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MILK;} break;
            case tTile::GUTTER_MERCURY     : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MERCURY;} break;
            case tTile::GUTTER_OIL         : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_OIL;} break;
            case tTile::GUTTER_ACID        : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_ACID;} break;
            case tTile::GUTTER_WATER       : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_WATER;} break;
            case tTile::GUTTER_BRINE       : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_BRINE;} break;
            case tTile::GUTTER_WINE        : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_WINE;} break;
            case tTile::GUTTER_GUTS        : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_GUTS;} break;
            case tTile::GUTTER_ALGAE       : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_ALGAE;} break;
            case tTile::GUTTER_HONEY       : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_HONEY;} break;
            case tTile::GUTTER_BLOOD       : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_BLOOD;} break;
            case tTile::GUTTER_MAGMA       : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MAGMA;} break;
            case tTile::GUTTER_LAVA        : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_LAVA;} break;
            case tTile::GUTTER_MUCK        : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MUCK;} break;
            case tTile::GUTTER_MUD         : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MUD;} break;
            case tTile::GUTTER_MOLTEN_SLAG : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MOLTEN_SLAG;} break;
        }
        switch (tCell::matrix[dN])
        {
            case tTile::GUTTER_MILK        : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MILK;} break;
            case tTile::GUTTER_MERCURY     : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MERCURY;} break;
            case tTile::GUTTER_OIL         : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_OIL;} break;
            case tTile::GUTTER_ACID        : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_ACID;} break;
            case tTile::GUTTER_WATER       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_WATER;} break;
            case tTile::GUTTER_BRINE       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_BRINE;} break;
            case tTile::GUTTER_WINE        : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_WINE;} break;
            case tTile::GUTTER_GUTS        : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_GUTS;} break;
            case tTile::GUTTER_ALGAE       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_ALGAE;} break;
            case tTile::GUTTER_HONEY       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_HONEY;} break;
            case tTile::GUTTER_BLOOD       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_BLOOD;} break;
            case tTile::GUTTER_MAGMA       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MAGMA;} break;
            case tTile::GUTTER_LAVA        : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_LAVA;} break;
            case tTile::GUTTER_MUCK        : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MUCK;} break;
            case tTile::GUTTER_MUD         : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MUD;} break;
            case tTile::GUTTER_MOLTEN_SLAG : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MOLTEN_SLAG;} break;
            case tTile::MILK        : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_MILK;} break;
            case tTile::MERCURY     : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_MERCURY;} break;
            case tTile::OIL         : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_OIL;} break;
            case tTile::ACID        : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_ACID;} break;
            case tTile::WATER       : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_WATER;} break;
            case tTile::BRINE       : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_BRINE;} break;
            case tTile::WINE        : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_WINE;} break;
            case tTile::GUTS        : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_GUTS;} break;
            case tTile::ALGAE       : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_ALGAE;} break;
            case tTile::HONEY       : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_HONEY;} break;
            case tTile::BLOOD       : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_BLOOD;} break;
            case tTile::MAGMA       : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_MAGMA;} break;
            case tTile::LAVA        : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_LAVA;} break;
            case tTile::MUCK        : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_MUCK;} break;
            case tTile::MUD         : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_MUD;} break;
            case tTile::MOLTEN_SLAG : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_MOLTEN_SLAG;} break;
        }
    }

    void Drain(int _x, int _y, int index, char season)
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
                case tTile::GUTTER_HONEY       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::HONEY;} break;
                case tTile::GUTTER_BLOOD       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::BLOOD;} break;
                case tTile::GUTTER_MAGMA       : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::MAGMA;} break;
                case tTile::GUTTER_LAVA        : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::LAVA;} break;
                case tTile::GUTTER_MUCK        : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::MUCK;} break;
                case tTile::GUTTER_MUD         : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::MUD;} break;
                case tTile::GUTTER_MOLTEN_SLAG : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::MOLTEN_SLAG;} break;
            }
        }
    }

    void ValveOpen(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        switch (tCell::matrix[dN])
        {
            case tTile::GUTTER_MILK        : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER; tCell::replace[dS]=tTile::GUTTER_MILK;} break;
            case tTile::GUTTER_MERCURY     : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER; tCell::replace[dS]=tTile::GUTTER_MERCURY;} break;
            case tTile::GUTTER_OIL         : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER; tCell::replace[dS]=tTile::GUTTER_OIL;} break;
            case tTile::GUTTER_ACID        : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER; tCell::replace[dS]=tTile::GUTTER_ACID;} break;
            case tTile::GUTTER_WATER       : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER; tCell::replace[dS]=tTile::GUTTER_WATER;} break;
            case tTile::GUTTER_BRINE       : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER; tCell::replace[dS]=tTile::GUTTER_BRINE;} break;
            case tTile::GUTTER_WINE        : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER; tCell::replace[dS]=tTile::GUTTER_WINE;} break;
            case tTile::GUTTER_GUTS        : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER; tCell::replace[dS]=tTile::GUTTER_GUTS;} break;
            case tTile::GUTTER_ALGAE       : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER; tCell::replace[dS]=tTile::GUTTER_ALGAE;} break;
            case tTile::GUTTER_HONEY       : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER; tCell::replace[dS]=tTile::GUTTER_HONEY;} break;
            case tTile::GUTTER_BLOOD       : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER; tCell::replace[dS]=tTile::GUTTER_BLOOD;} break;
            case tTile::GUTTER_MAGMA       : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER; tCell::replace[dS]=tTile::GUTTER_MAGMA;} break;
            case tTile::GUTTER_LAVA        : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER; tCell::replace[dS]=tTile::GUTTER_LAVA;} break;
            case tTile::GUTTER_MUCK        : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER; tCell::replace[dS]=tTile::GUTTER_MUCK;} break;
            case tTile::GUTTER_MUD         : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER; tCell::replace[dS]=tTile::GUTTER_MUD;} break;
            case tTile::GUTTER_MOLTEN_SLAG : {if(tCell::matrix[dS]==tTile::GUTTER) tCell::replace[dN]=tTile::GUTTER;tCell::replace[dS]=tTile::GUTTER_MOLTEN_SLAG;} break;
        }
        switch (tCell::matrix[dS])
        {
            case tTile::PIPE_MILK        : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::GUTTER_MILK;} break;
            case tTile::PIPE_MERCURY     : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::GUTTER_MERCURY;} break;
            case tTile::PIPE_OIL         : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::GUTTER_OIL;} break;
            case tTile::PIPE_ACID        : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::GUTTER_ACID;} break;
            case tTile::PIPE_WATER       : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::PIPE_WATER;} break;
            case tTile::PIPE_BRINE       : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::PIPE_BRINE;} break;
            case tTile::PIPE_WINE        : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::GUTTER_WINE;} break;
            case tTile::PIPE_GUTS        : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::GUTTER_GUTS;} break;
            case tTile::PIPE_ALGAE       : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::GUTTER_ALGAE;} break;
            case tTile::PIPE_HONEY       : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::PIPE_HONEY;} break;
            case tTile::PIPE_BLOOD       : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::PIPE_BLOOD;} break;
            case tTile::PIPE_MAGMA       : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::GUTTER_MAGMA;} break;
            case tTile::PIPE_LAVA        : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::PIPE_LAVA;} break;
            case tTile::PIPE_MUCK        : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::PIPE_MUCK;} break;
            case tTile::PIPE_MUD         : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::PIPE_MUD;} break;
            case tTile::PIPE_MOLTEN_SLAG : {if(tCell::matrix[dN]==tTile::GUTTER) tCell::replace[dS]=tTile::GUTTER; tCell::replace[dN]=tTile::GUTTER_MOLTEN_SLAG;} break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::PIPE_MILK          : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_MILK;} break;
            case tTile::PIPE_MERCURY       : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_MERCURY;} break;
            case tTile::PIPE_OIL           : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_OIL;} break;
            case tTile::PIPE_ACID          : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_ACID;} break;
            case tTile::PIPE_WATER         : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_WATER;} break;
            case tTile::PIPE_BRINE         : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_BRINE;} break;
            case tTile::PIPE_WINE          : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_WINE;} break;
            case tTile::PIPE_GUTS          : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_GUTS;} break;
            case tTile::PIPE_ALGAE         : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_ALGAE;} break;
            case tTile::PIPE_HONEY         : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_HONEY;} break;
            case tTile::PIPE_BLOOD         : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_BLOOD;} break;
            case tTile::PIPE_MAGMA         : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_MAGMA;} break;
            case tTile::PIPE_LAVA          : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_LAVA;} break;
            case tTile::PIPE_MUCK          : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_MUCK;} break;
            case tTile::PIPE_MUD           : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_MUD;} break;
            case tTile::PIPE_MOLTEN_SLAG   : {if(tCell::matrix[dW]==tTile::PIPE) tCell::replace[dE]=tTile::PIPE; tCell::replace[dW]=tTile::PIPE_MOLTEN_SLAG;} break;
            case tTile::GUTTER_MILK        : {if(tCell::matrix[dW]==tTile::GUTTER) tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_MILK;} break;
            case tTile::GUTTER_MERCURY     : {if(tCell::matrix[dW]==tTile::GUTTER) tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_MERCURY;} break;
            case tTile::GUTTER_OIL         : {if(tCell::matrix[dW]==tTile::GUTTER) tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_OIL;} break;
            case tTile::GUTTER_ACID        : {if(tCell::matrix[dW]==tTile::GUTTER) tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_ACID;} break;
            case tTile::GUTTER_WATER       : {if(tCell::matrix[dW]==tTile::GUTTER) tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_WATER;} break;
            case tTile::GUTTER_BRINE       : {if(tCell::matrix[dW]==tTile::GUTTER) tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_BRINE;} break;
            case tTile::GUTTER_WINE        : {if(tCell::matrix[dW]==tTile::GUTTER) tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_WINE;} break;
            case tTile::GUTTER_GUTS        : {if(tCell::matrix[dW]==tTile::GUTTER) tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_GUTS;} break;
            case tTile::GUTTER_ALGAE       : {if(tCell::matrix[dW]==tTile::GUTTER) tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_ALGAE;} break;
            case tTile::GUTTER_HONEY       : {if(tCell::matrix[dW]==tTile::GUTTER) tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_HONEY;} break;
            case tTile::GUTTER_BLOOD       : {if(tCell::matrix[dW]==tTile::GUTTER) tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_BLOOD;} break;
            case tTile::GUTTER_MAGMA       : {if(tCell::matrix[dW]==tTile::GUTTER) tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_MAGMA;} break;
            case tTile::GUTTER_LAVA        : {if(tCell::matrix[dW]==tTile::GUTTER) tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_LAVA;} break;
            case tTile::GUTTER_MUCK        : {if(tCell::matrix[dW]==tTile::GUTTER) tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_MUCK;} break;
            case tTile::GUTTER_MUD         : {if(tCell::matrix[dW]==tTile::GUTTER) tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_MUD;} break;
            case tTile::GUTTER_MOLTEN_SLAG : {if(tCell::matrix[dW]==tTile::GUTTER)tCell::replace[dE]=tTile::GUTTER; tCell::replace[dW]=tTile::GUTTER_MOLTEN_SLAG;} break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::PIPE_MILK          : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_MILK;} break;
            case tTile::PIPE_MERCURY       : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_MERCURY;} break;
            case tTile::PIPE_OIL           : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_OIL;} break;
            case tTile::PIPE_ACID          : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_ACID;} break;
            case tTile::PIPE_WATER         : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_WATER;} break;
            case tTile::PIPE_BRINE         : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_BRINE;} break;
            case tTile::PIPE_WINE          : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_WINE;} break;
            case tTile::PIPE_GUTS          : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_GUTS;} break;
            case tTile::PIPE_ALGAE         : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_ALGAE;} break;
            case tTile::PIPE_HONEY         : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_HONEY;} break;
            case tTile::PIPE_BLOOD         : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_BLOOD;} break;
            case tTile::PIPE_MAGMA         : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_MAGMA;} break;
            case tTile::PIPE_LAVA          : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_LAVA;} break;
            case tTile::PIPE_MUCK          : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_MUCK;} break;
            case tTile::PIPE_MUD           : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_MUD;} break;
            case tTile::PIPE_MOLTEN_SLAG   : {if(tCell::matrix[dE]==tTile::PIPE) tCell::replace[dW]=tTile::PIPE; tCell::replace[dE]=tTile::PIPE_MOLTEN_SLAG;} break;
            case tTile::GUTTER_MILK        : {if(tCell::matrix[dE]==tTile::GUTTER) tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_MILK;} break;
            case tTile::GUTTER_MERCURY     : {if(tCell::matrix[dE]==tTile::GUTTER) tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_MERCURY;} break;
            case tTile::GUTTER_OIL         : {if(tCell::matrix[dE]==tTile::GUTTER) tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_OIL;} break;
            case tTile::GUTTER_ACID        : {if(tCell::matrix[dE]==tTile::GUTTER) tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_ACID;} break;
            case tTile::GUTTER_WATER       : {if(tCell::matrix[dE]==tTile::GUTTER) tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_WATER;} break;
            case tTile::GUTTER_BRINE       : {if(tCell::matrix[dE]==tTile::GUTTER) tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_BRINE;} break;
            case tTile::GUTTER_WINE        : {if(tCell::matrix[dE]==tTile::GUTTER) tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_WINE;} break;
            case tTile::GUTTER_GUTS        : {if(tCell::matrix[dE]==tTile::GUTTER) tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_GUTS;} break;
            case tTile::GUTTER_ALGAE       : {if(tCell::matrix[dE]==tTile::GUTTER) tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_ALGAE;} break;
            case tTile::GUTTER_HONEY       : {if(tCell::matrix[dE]==tTile::GUTTER) tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_HONEY;} break;
            case tTile::GUTTER_BLOOD       : {if(tCell::matrix[dE]==tTile::GUTTER) tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_BLOOD;} break;
            case tTile::GUTTER_MAGMA       : {if(tCell::matrix[dE]==tTile::GUTTER) tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_MAGMA;} break;
            case tTile::GUTTER_LAVA        : {if(tCell::matrix[dE]==tTile::GUTTER) tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_LAVA;} break;
            case tTile::GUTTER_MUCK        : {if(tCell::matrix[dE]==tTile::GUTTER) tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_MUCK;} break;
            case tTile::GUTTER_MUD         : {if(tCell::matrix[dE]==tTile::GUTTER) tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_MUD;} break;
            case tTile::GUTTER_MOLTEN_SLAG : {if(tCell::matrix[dE]==tTile::GUTTER)tCell::replace[dW]=tTile::GUTTER; tCell::replace[dE]=tTile::GUTTER_MOLTEN_SLAG;} break;
        }
    }



    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell, char season=0)
    {
        switch (current_cell)
        {
            case tTile::PIPE : { Pipe(_x, _y, index, season); } break;
            case tTile::PUMP : { Pump(_x, _y, index, season); } break;
            case tTile::GUTTER : { Gutter(_x, _y, index, season); } break;
            case tTile::DRAIN : { Drain(_x, _y, index, season); } break;
            case tTile::VALVE_OPEN : { ValveOpen(_x, _y, index, season); } break;
        }
    }

}
