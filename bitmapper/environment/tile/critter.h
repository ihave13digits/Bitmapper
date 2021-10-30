namespace tCritter
{

    //
    // Special
    //

    void Frog(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int dSS = int( (_y+2) * tCell::width + (_x  ) );

        int chance = rand()%1000;
        int direction = rand()%100;

        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::FROG; }
        if (tCell::matrix[dE] == tTile::FROG_LEGS) { tCell::replace[dE] = tTile::AIR; }
        if (tCell::matrix[dW] == tTile::FROG_LEGS) { tCell::replace[dW] = tTile::AIR; }
        if (tCell::matrix[dS] == tTile::FROG_LEGS && tCell::matrix[dN] == tTile::AIR)
        { tCell::replace[index] = tTile::FROG_LEGS; tCell::replace[dN] = tTile::FROG; tCell::replace[dS] = tTile::AIR; }
        else if (tCell::matrix[dSE] == tTile::FROG_LEGS && tCell::matrix[dN] == tTile::AIR)
        { tCell::replace[index] = tTile::FROG_LEGS; tCell::replace[dW] = tTile::FROG; tCell::replace[dSE] = tTile::AIR; }
        else if (tCell::matrix[dSW] == tTile::FROG_LEGS && tCell::matrix[dN] == tTile::AIR)
        { tCell::replace[index] = tTile::FROG_LEGS; tCell::replace[dE] = tTile::FROG; tCell::replace[dSW] = tTile::AIR; }
        if (tCell::matrix[dS] == tTile::FROG_LEGS && tCell::matrix[dSS] == tTile::AIR)
        {
            if (direction < 50 && tCell::matrix[dNE] == tTile::AIR)
            { tCell::replace[index] = tTile::AIR; tCell::replace[dNE] = tTile::FROG; tCell::replace[dN] = tTile::FROG_LEGS; }
            else if (direction > 50 && tCell::matrix[dNW] == tTile::AIR)
            { tCell::replace[index] = tTile::AIR; tCell::replace[dNW] = tTile::FROG; tCell::replace[dN] = tTile::FROG_LEGS; }
        }
        if (chance < 25)
        { if (tCell::matrix[dS] == tTile::GRASS || tCell::matrix[dS] == tTile::FROG)
            { tCell::replace[index] = tTile::FROG_LEGS; tCell::replace[dN] = tTile::FROG;}
        }
    }

    void Toad(int _x, int _y, int index, char season)
    {
        bool can_do;
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int dSS = int( (_y+2) * tCell::width + (_x  ) );

        int chance = rand()%1000;
        int direction = rand()%100;

        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::TOAD; }
        if (tCell::matrix[dE] == tTile::TOAD_LEGS) { tCell::replace[dE] = tTile::AIR; }
        if (tCell::matrix[dW] == tTile::TOAD_LEGS) { tCell::replace[dW] = tTile::AIR; }
        if (tCell::matrix[dS] == tTile::TOAD_LEGS && tCell::matrix[dN] == tTile::AIR)
        { tCell::replace[index] = tTile::TOAD_LEGS; tCell::replace[dN] = tTile::TOAD; tCell::replace[dS] = tTile::AIR; }
        else if (tCell::matrix[dSE] == tTile::TOAD_LEGS && tCell::matrix[dN] == tTile::AIR)
        { tCell::replace[index] = tTile::TOAD_LEGS; tCell::replace[dW] = tTile::TOAD; tCell::replace[dSE] = tTile::AIR; }
        else if (tCell::matrix[dSW] == tTile::TOAD_LEGS && tCell::matrix[dN] == tTile::AIR)
        { tCell::replace[index] = tTile::TOAD_LEGS; tCell::replace[dE] = tTile::TOAD; tCell::replace[dSW] = tTile::AIR; }
        if (tCell::matrix[dS] == tTile::TOAD_LEGS && tCell::matrix[dSS] == tTile::AIR)
        {
            if (direction < 50 && tCell::matrix[dNE] == tTile::AIR)
            { tCell::replace[index] = tTile::AIR; tCell::replace[dNE] = tTile::TOAD; tCell::replace[dN] = tTile::TOAD_LEGS; }
            else if (direction > 50 && tCell::matrix[dNW] == tTile::AIR)
            { tCell::replace[index] = tTile::AIR; tCell::replace[dNW] = tTile::TOAD; tCell::replace[dN] = tTile::TOAD_LEGS; }
        }
        if (chance < 25)
        { if (tCell::matrix[dS] == tTile::GRASS || tCell::matrix[dS] == tTile::TOAD)
            { tCell::replace[index] = tTile::TOAD_LEGS; tCell::replace[dN] = tTile::TOAD;}
        }
    }

    void Mole(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dNNE= int( (_y-2) * tCell::width + (_x+1) );
        int dNNW= int( (_y-2) * tCell::width + (_x-1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        int chance = rand()%1000;
        int direction = rand()%100;
        int DROP = tTile::DIRT;
        int drops = rand()%13;
        switch (drops)
        {
            case  7 : { DROP = tTile::MUD; } break;
            case  8 : { DROP = tTile::MUD; } break;
            case  9 : { DROP = tTile::MUD; } break;
            case 10 : { DROP = tTile::SOIL; } break;
            case 11 : { DROP = tTile::LOOSE_DIRT; } break;
            case 12 : { DROP = tTile::LOOSE_DIRT; } break;
        }
        
        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::MOLE; }
        else if (tCell::matrix[dS] == tTile::GRASS)
        { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::MOLE; }
        else if (tCell::matrix[dE] == tTile::GRASS && tCell::matrix[dW] == tTile::GRASS)
        { tCell::replace[index] = DROP; tCell::replace[dS] = tTile::MOLE; }
        else if (tCell::matrix[dN] != tTile::GRASS && tCell::matrix[dE] == tTile::GRASS || tCell::matrix[dW] == tTile::GRASS)
        { tCell::replace[index] = DROP; tCell::replace[dS] = tTile::MOLE; }
        if (chance < 25)
        {
            if (direction < 50)
            {
                if (tCell::matrix[dSE] == tTile::GRASS && tCell::matrix[dSW] == tTile::GRASS)
                { tCell::replace[index] = DROP; tCell::replace[dS] = tTile::MOLE; }
                else if (tCell::matrix[dN] != tTile::GRASS && tCell::matrix[dNW] == tTile::GRASS)
                { tCell::replace[index] = DROP; tCell::replace[dW] = tTile::MOLE; }
                else if (tCell::matrix[dN] == tTile::GRASS && tCell::matrix[dNW] == tTile::GRASS)
                { tCell::replace[index] = DROP; tCell::replace[dW] = tTile::MOLE; }
                else if (tCell::matrix[dN] == tTile::GRASS && tCell::matrix[dSW] == tTile::GRASS)
                { tCell::replace[index] = DROP; tCell::replace[dSW] = tTile::MOLE; }
                else if (tCell::matrix[dN] == tTile::GRASS && tCell::matrix[dNNW] == tTile::GRASS)
                {
                    int t = tCell::matrix[dNW];
                    if (t == tTile::DIRT || t == tTile::SOIL)
                    { tCell::replace[index] = DROP; tCell::replace[dNW] = tTile::MOLE; }
                }
            }
            else
            {
                if (tCell::matrix[dSE] == tTile::GRASS && tCell::matrix[dSW] == tTile::GRASS)
                { tCell::replace[index] = DROP; tCell::replace[dS] = tTile::MOLE; }
                else if (tCell::matrix[dN] != tTile::GRASS && tCell::matrix[dNE] == tTile::GRASS)
                { tCell::replace[index] = DROP; tCell::replace[dE] = tTile::MOLE; }
                else if (tCell::matrix[dN] == tTile::GRASS && tCell::matrix[dNE] == tTile::GRASS)
                { tCell::replace[index] = DROP; tCell::replace[dE] = tTile::MOLE; }
                else if (tCell::matrix[dN] == tTile::GRASS && tCell::matrix[dE] == tTile::GRASS)
                { tCell::replace[index] = DROP; tCell::replace[dSE] = tTile::MOLE; }
                else if (tCell::matrix[dN] == tTile::GRASS && tCell::matrix[dNNE] == tTile::GRASS)
                {
                    int t = tCell::matrix[dNE];
                    if (t == tTile::DIRT || t == tTile::SOIL)
                    { tCell::replace[index] = DROP; tCell::replace[dNE] = tTile::MOLE; }
                }
            }
        }
    }

    void Hedgehog(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dNNE= int( (_y-2) * tCell::width + (_x+1) );
        int dNNW= int( (_y-2) * tCell::width + (_x-1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSSE= int( (_y+2) * tCell::width + (_x+1) );
        int dSSW= int( (_y+2) * tCell::width + (_x-1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        
        int chance = rand()%1000;
        int direction = rand()%100;

        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::HEDGEHOG; }
        if (chance < 25)
        {
            if (direction < 50)
            {
                if (tCell::matrix[dSW] == tTile::GRASS && tCell::matrix[dW] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dW] = tTile::HEDGEHOG; }
                else if (tCell::matrix[dSSW] == tTile::GRASS && tCell::matrix[dSW] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dSW] = tTile::HEDGEHOG; }
                else if (tCell::matrix[dW] == tTile::GRASS && tCell::matrix[dNW] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dNW] = tTile::HEDGEHOG; }
            }
            else
            {
                if (tCell::matrix[dSE] == tTile::GRASS && tCell::matrix[dE] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dE] = tTile::HEDGEHOG; }
                else if (tCell::matrix[dSSE] == tTile::GRASS && tCell::matrix[dSE] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dSE] = tTile::HEDGEHOG; }
                else if (tCell::matrix[dE] == tTile::GRASS && tCell::matrix[dNE] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dNE] = tTile::HEDGEHOG; }
            }
        }
    }

    void Mouse(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dNNE= int( (_y-2) * tCell::width + (_x+1) );
        int dNNW= int( (_y-2) * tCell::width + (_x-1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSSE= int( (_y+2) * tCell::width + (_x+1) );
        int dSSW= int( (_y+2) * tCell::width + (_x-1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        
        int chance = rand()%1000;
        int direction = rand()%100;

        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::MOUSE; }
        if (chance < 25)
        {
            if (direction < 50)
            {
                if (tCell::matrix[dSW] == tTile::GRASS && tCell::matrix[dW] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dW] = tTile::MOUSE; }
                else if (tCell::matrix[dSSW] == tTile::GRASS && tCell::matrix[dSW] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dSW] = tTile::MOUSE; }
                else if (tCell::matrix[dW] == tTile::GRASS && tCell::matrix[dNW] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dNW] = tTile::MOUSE; }
            }
            else
            {
                if (tCell::matrix[dSE] == tTile::GRASS && tCell::matrix[dE] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dE] = tTile::MOUSE; }
                else if (tCell::matrix[dSSE] == tTile::GRASS && tCell::matrix[dSE] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dSE] = tTile::MOUSE; }
                else if (tCell::matrix[dE] == tTile::GRASS && tCell::matrix[dNE] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dNE] = tTile::MOUSE; }
            }
        }
    }

    void Rat(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dNNE= int( (_y-2) * tCell::width + (_x+1) );
        int dNNW= int( (_y-2) * tCell::width + (_x-1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSSE= int( (_y+2) * tCell::width + (_x+1) );
        int dSSW= int( (_y+2) * tCell::width + (_x-1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        
        int chance = rand()%1000;
        int direction = rand()%100;

        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::RAT; }
        if (chance < 25)
        {
            if (direction < 50)
            {
                if (tCell::matrix[dSW] == tTile::GRASS && tCell::matrix[dW] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dW] = tTile::RAT; }
                else if (tCell::matrix[dSSW] == tTile::GRASS && tCell::matrix[dSW] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dSW] = tTile::RAT; }
                else if (tCell::matrix[dW] == tTile::GRASS && tCell::matrix[dNW] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dNW] = tTile::RAT; }
            }
            else
            {
                if (tCell::matrix[dSE] == tTile::GRASS && tCell::matrix[dE] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dE] = tTile::RAT; }
                else if (tCell::matrix[dSSE] == tTile::GRASS && tCell::matrix[dSE] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dSE] = tTile::RAT; }
                else if (tCell::matrix[dE] == tTile::GRASS && tCell::matrix[dNE] == tTile::AIR)
                { tCell::replace[index] = tTile::AIR; tCell::replace[dNE] = tTile::RAT; }
            }
        }
    }

    /*
    void Snake()
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int chance = rand()%1000;
        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::SNAKE; }
        if (chance < 25)
        {
        }
    }
    */



    //
    // Generic
    //
    
    void Update(int _x, int _y, int index, int current_cell, char season=0)
    {
        switch (current_cell)
        {
            case tTile::TOAD :     {     Toad(_x, _y, index, season); } break;
            case tTile::FROG :     {     Frog(_x, _y, index, season); } break;
            case tTile::RAT :      {      Rat(_x, _y, index, season); } break;
            case tTile::MOLE :     {     Mole(_x, _y, index, season); } break;
            case tTile::MOUSE :    {    Mouse(_x, _y, index, season); } break;
            case tTile::HEDGEHOG : { Hedgehog(_x, _y, index, season); } break;
        }
    }

}
