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
            case tTile::PIPE_WATER : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_WATER;} break;
            case tTile::PIPE_BRINE : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_BRINE;} break;
            case tTile::PIPE_HONEY : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_HONEY;} break;
            case tTile::PIPE_BLOOD : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_BLOOD;} break;
            case tTile::PIPE_LAVA : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_LAVA;} break;
            case tTile::PIPE_MUCK : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MUCK;} break;
            case tTile::PIPE_MUD : {tCell::replace[dE] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MUD;} break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::PIPE_WATER : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_WATER;} break;
            case tTile::PIPE_BRINE : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_BRINE;} break;
            case tTile::PIPE_HONEY : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_HONEY;} break;
            case tTile::PIPE_BLOOD : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_BLOOD;} break;
            case tTile::PIPE_LAVA : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_LAVA;} break;
            case tTile::PIPE_MUCK : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MUCK;} break;
            case tTile::PIPE_MUD : {tCell::replace[dW] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MUD;} break;
        }
        switch (tCell::matrix[dS])
        {
            case tTile::PIPE_WATER : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_WATER;} break;
            case tTile::PIPE_BRINE : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_BRINE;} break;
            case tTile::PIPE_HONEY : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_HONEY;} break;
            case tTile::PIPE_BLOOD : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_BLOOD;} break;
            case tTile::PIPE_LAVA : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_LAVA;} break;
            case tTile::PIPE_MUCK : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MUCK;} break;
            case tTile::PIPE_MUD : {tCell::replace[dS] = tTile::PIPE; tCell::replace[index] = tTile::PIPE_MUD;} break;
            case tTile::WATER : {tCell::replace[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_WATER;} break;
            case tTile::BRINE : {tCell::replace[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_BRINE;} break;
            case tTile::HONEY : {tCell::replace[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_HONEY;} break;
            case tTile::BLOOD : {tCell::replace[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_BLOOD;} break;
            case tTile::LAVA : {tCell::replace[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_LAVA;} break;
            case tTile::MUCK : {tCell::replace[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_MUCK;} break;
            case tTile::MUD : {tCell::replace[dS] = tTile::AIR; tCell::replace[index] = tTile::PIPE_MUD;} break;
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
                case tTile::PIPE_WATER : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::WATER;} break;
                case tTile::PIPE_BRINE : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::BRINE;} break;
                case tTile::PIPE_HONEY : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::HONEY;} break;
                case tTile::PIPE_BLOOD : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::BLOOD;} break;
                case tTile::PIPE_LAVA : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::LAVA;} break;
                case tTile::PIPE_MUCK : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::MUCK;} break;
                case tTile::PIPE_MUD : {tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::MUD;} break;
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
            case tTile::GUTTER_WATER : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_WATER;} break;
            case tTile::GUTTER_BRINE : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_BRINE;} break;
            case tTile::GUTTER_HONEY : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_HONEY;} break;
            case tTile::GUTTER_BLOOD : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_BLOOD;} break;
            case tTile::GUTTER_LAVA : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_LAVA;} break;
            case tTile::GUTTER_MUCK : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MUCK;} break;
            case tTile::GUTTER_MUD : {tCell::replace[dE] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MUD;} break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::GUTTER_WATER : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_WATER;} break;
            case tTile::GUTTER_BRINE : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_BRINE;} break;
            case tTile::GUTTER_HONEY : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_HONEY;} break;
            case tTile::GUTTER_BLOOD : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_BLOOD;} break;
            case tTile::GUTTER_LAVA : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_LAVA;} break;
            case tTile::GUTTER_MUCK : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MUCK;} break;
            case tTile::GUTTER_MUD : {tCell::replace[dW] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MUD;} break;
        }
        switch (tCell::matrix[dN])
        {
            case tTile::GUTTER_WATER : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_WATER;} break;
            case tTile::GUTTER_BRINE : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_BRINE;} break;
            case tTile::GUTTER_HONEY : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_HONEY;} break;
            case tTile::GUTTER_BLOOD : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_BLOOD;} break;
            case tTile::GUTTER_LAVA : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_LAVA;} break;
            case tTile::GUTTER_MUCK : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MUCK;} break;
            case tTile::GUTTER_MUD : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[index] = tTile::GUTTER_MUD;} break;
            case tTile::WATER : {tCell::replace[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_WATER;} break;
            case tTile::BRINE : {tCell::replace[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_BRINE;} break;
            case tTile::HONEY : {tCell::replace[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_HONEY;} break;
            case tTile::BLOOD : {tCell::replace[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_BLOOD;} break;
            case tTile::LAVA : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_LAVA;} break;
            case tTile::MUCK : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_MUCK;} break;
            case tTile::MUD : {tCell::replace[dN] = tTile::AIR; tCell::matrix[dN] = tTile::AIR; tCell::replace[index] = tTile::GUTTER_MUD;} break;
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
                case tTile::GUTTER_WATER : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::WATER;} break;
                case tTile::GUTTER_BRINE : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::BRINE;} break;
                case tTile::GUTTER_HONEY : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::HONEY;} break;
                case tTile::GUTTER_BLOOD : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::BLOOD;} break;
                case tTile::GUTTER_LAVA : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::LAVA;} break;
                case tTile::GUTTER_MUCK : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::MUCK;} break;
                case tTile::GUTTER_MUD : {tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::MUD;} break;
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
            case tTile::GUTTER_WATER : {if (tCell::matrix[dS] == tTile::GUTTER) tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::GUTTER_WATER;} break;
            case tTile::GUTTER_BRINE : {if (tCell::matrix[dS] == tTile::GUTTER) tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::GUTTER_BRINE;} break;
            case tTile::GUTTER_HONEY : {if (tCell::matrix[dS] == tTile::GUTTER) tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::GUTTER_HONEY;} break;
            case tTile::GUTTER_BLOOD : {if (tCell::matrix[dS] == tTile::GUTTER) tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::GUTTER_BLOOD;} break;
            case tTile::GUTTER_LAVA : {if (tCell::matrix[dS] == tTile::GUTTER) tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::GUTTER_LAVA;} break;
            case tTile::GUTTER_MUCK : {if (tCell::matrix[dS] == tTile::GUTTER) tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::GUTTER_MUCK;} break;
            case tTile::GUTTER_MUD : {if (tCell::matrix[dS] == tTile::GUTTER) tCell::replace[dN] = tTile::GUTTER; tCell::replace[dS] = tTile::GUTTER_MUD;} break;
        }
        switch (tCell::matrix[dS])
        {
            case tTile::PIPE_WATER : {if (tCell::matrix[dN] == tTile::PIPE) tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::PIPE_WATER;} break;
            case tTile::PIPE_BRINE : {if (tCell::matrix[dN] == tTile::PIPE) tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::PIPE_BRINE;} break;
            case tTile::PIPE_HONEY : {if (tCell::matrix[dN] == tTile::PIPE) tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::PIPE_HONEY;} break;
            case tTile::PIPE_BLOOD : {if (tCell::matrix[dN] == tTile::PIPE) tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::PIPE_BLOOD;} break;
            case tTile::PIPE_LAVA : {if (tCell::matrix[dN] == tTile::PIPE) tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::PIPE_LAVA;} break;
            case tTile::PIPE_MUCK : {if (tCell::matrix[dN] == tTile::PIPE) tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::PIPE_MUCK;} break;
            case tTile::PIPE_MUD : {if (tCell::matrix[dN] == tTile::PIPE) tCell::replace[dS] = tTile::PIPE; tCell::replace[dN] = tTile::PIPE_MUD;} break;
        }
        switch (tCell::matrix[dE])
        {
            case tTile::PIPE_WATER : {if (tCell::matrix[dW] == tTile::PIPE) tCell::replace[dE] = tTile::PIPE; tCell::replace[dW] = tTile::PIPE_WATER;} break;
            case tTile::PIPE_BRINE : {if (tCell::matrix[dW] == tTile::PIPE) tCell::replace[dE] = tTile::PIPE; tCell::replace[dW] = tTile::PIPE_BRINE;} break;
            case tTile::PIPE_HONEY : {if (tCell::matrix[dW] == tTile::PIPE) tCell::replace[dE] = tTile::PIPE; tCell::replace[dW] = tTile::PIPE_HONEY;} break;
            case tTile::PIPE_BLOOD : {if (tCell::matrix[dW] == tTile::PIPE) tCell::replace[dE] = tTile::PIPE; tCell::replace[dW] = tTile::PIPE_BLOOD;} break;
            case tTile::PIPE_LAVA : {if (tCell::matrix[dW] == tTile::PIPE) tCell::replace[dE] = tTile::PIPE; tCell::replace[dW] = tTile::PIPE_LAVA;} break;
            case tTile::PIPE_MUCK : {if (tCell::matrix[dW] == tTile::PIPE) tCell::replace[dE] = tTile::PIPE; tCell::replace[dW] = tTile::PIPE_MUCK;} break;
            case tTile::PIPE_MUD : {if (tCell::matrix[dW] == tTile::PIPE) tCell::replace[dE] = tTile::PIPE; tCell::replace[dW] = tTile::PIPE_MUD;} break;
            case tTile::GUTTER_WATER : {if (tCell::matrix[dW] == tTile::GUTTER) tCell::replace[dE] = tTile::GUTTER; tCell::replace[dW] = tTile::GUTTER_WATER;} break;
            case tTile::GUTTER_BRINE : {if (tCell::matrix[dW] == tTile::GUTTER) tCell::replace[dE] = tTile::GUTTER; tCell::replace[dW] = tTile::GUTTER_BRINE;} break;
            case tTile::GUTTER_HONEY : {if (tCell::matrix[dW] == tTile::GUTTER) tCell::replace[dE] = tTile::GUTTER; tCell::replace[dW] = tTile::GUTTER_HONEY;} break;
            case tTile::GUTTER_BLOOD : {if (tCell::matrix[dW] == tTile::GUTTER) tCell::replace[dE] = tTile::GUTTER; tCell::replace[dW] = tTile::GUTTER_BLOOD;} break;
            case tTile::GUTTER_LAVA : {if (tCell::matrix[dW] == tTile::GUTTER) tCell::replace[dE] = tTile::GUTTER; tCell::replace[dW] = tTile::GUTTER_LAVA;} break;
            case tTile::GUTTER_MUCK : {if (tCell::matrix[dW] == tTile::GUTTER) tCell::replace[dE] = tTile::GUTTER; tCell::replace[dW] = tTile::GUTTER_MUCK;} break;
            case tTile::GUTTER_MUD : {if (tCell::matrix[dW] == tTile::GUTTER) tCell::replace[dE] = tTile::GUTTER; tCell::replace[dW] = tTile::GUTTER_MUD;} break;
        }
        switch (tCell::matrix[dW])
        {
            case tTile::PIPE_WATER : {if (tCell::matrix[dE] == tTile::PIPE) tCell::replace[dW] = tTile::PIPE; tCell::replace[dE] = tTile::PIPE_WATER;} break;
            case tTile::PIPE_BRINE : {if (tCell::matrix[dE] == tTile::PIPE) tCell::replace[dW] = tTile::PIPE; tCell::replace[dE] = tTile::PIPE_BRINE;} break;
            case tTile::PIPE_HONEY : {if (tCell::matrix[dE] == tTile::PIPE) tCell::replace[dW] = tTile::PIPE; tCell::replace[dE] = tTile::PIPE_HONEY;} break;
            case tTile::PIPE_BLOOD : {if (tCell::matrix[dE] == tTile::PIPE) tCell::replace[dW] = tTile::PIPE; tCell::replace[dE] = tTile::PIPE_BLOOD;} break;
            case tTile::PIPE_LAVA : {if (tCell::matrix[dE] == tTile::PIPE) tCell::replace[dW] = tTile::PIPE; tCell::replace[dE] = tTile::PIPE_LAVA;} break;
            case tTile::PIPE_MUCK : {if (tCell::matrix[dE] == tTile::PIPE) tCell::replace[dW] = tTile::PIPE; tCell::replace[dE] = tTile::PIPE_MUCK;} break;
            case tTile::PIPE_MUD : {if (tCell::matrix[dE] == tTile::PIPE) tCell::replace[dW] = tTile::PIPE; tCell::replace[dE] = tTile::PIPE_MUD;} break;
            case tTile::GUTTER_WATER : {if (tCell::matrix[dE] == tTile::GUTTER) tCell::replace[dW] = tTile::GUTTER; tCell::replace[dE] = tTile::GUTTER_WATER;} break;
            case tTile::GUTTER_BRINE : {if (tCell::matrix[dE] == tTile::GUTTER) tCell::replace[dW] = tTile::GUTTER; tCell::replace[dE] = tTile::GUTTER_BRINE;} break;
            case tTile::GUTTER_HONEY : {if (tCell::matrix[dE] == tTile::GUTTER) tCell::replace[dW] = tTile::GUTTER; tCell::replace[dE] = tTile::GUTTER_HONEY;} break;
            case tTile::GUTTER_BLOOD : {if (tCell::matrix[dE] == tTile::GUTTER) tCell::replace[dW] = tTile::GUTTER; tCell::replace[dE] = tTile::GUTTER_BLOOD;} break;
            case tTile::GUTTER_LAVA : {if (tCell::matrix[dE] == tTile::GUTTER) tCell::replace[dW] = tTile::GUTTER; tCell::replace[dE] = tTile::GUTTER_LAVA;} break;
            case tTile::GUTTER_MUCK : {if (tCell::matrix[dE] == tTile::GUTTER) tCell::replace[dW] = tTile::GUTTER; tCell::replace[dE] = tTile::GUTTER_MUCK;} break;
            case tTile::GUTTER_MUD : {if (tCell::matrix[dE] == tTile::GUTTER) tCell::replace[dW] = tTile::GUTTER; tCell::replace[dE] = tTile::GUTTER_MUD;} break;
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
