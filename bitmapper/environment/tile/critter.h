namespace tCritter
{

    //
    // Movement
    //

    void Burrow(int _x, int _y, int index, char season, uint8_t target, uint8_t ground, uint8_t background, uint8_t drop, int activity)
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

        if (tCell::matrix[dS] == background) { tCell::replace[index] = background; tCell::replace[dS] = target; }
        else if (tCell::matrix[dS] == ground)
        { tCell::replace[index] = background; tCell::replace[dS] = target; }
        else if (tCell::matrix[dE] == ground && tCell::matrix[dW] == ground)
        { tCell::replace[index] = drop; tCell::replace[dS] = target; }
        else if (tCell::matrix[dN] != ground && tCell::matrix[dE] == ground || tCell::matrix[dW] == ground)
        { tCell::replace[index] = drop; tCell::replace[dS] = target; }
        if (chance < activity)
        {
            if (direction < 50)
            {
                if (tCell::matrix[dSE] == ground && tCell::matrix[dSW] == ground)
                { tCell::replace[index] = drop; tCell::replace[dS] = target; }
                else if (tCell::matrix[dN] != ground && tCell::matrix[dNW] == ground)
                { tCell::replace[index] = drop; tCell::replace[dW] = target; }
                else if (tCell::matrix[dN] == ground && tCell::matrix[dNW] == ground)
                { tCell::replace[index] = drop; tCell::replace[dW] = target; }
                else if (tCell::matrix[dN] == ground && tCell::matrix[dSW] == ground)
                { tCell::replace[index] = drop; tCell::replace[dSW] = target; }
                else if (tCell::matrix[dN] == ground && tCell::matrix[dNNW] == ground)
                {
                    int t = tCell::matrix[dNW];
                    if (t == tTile::DIRT || t == tTile::SOIL)
                    { tCell::replace[index] = drop; tCell::replace[dNW] = tTile::MOLE; }
                }
            }
            else
            {
                if (tCell::matrix[dSE] == ground && tCell::matrix[dSW] == ground)
                { tCell::replace[index] = drop; tCell::replace[dS] = target; }
                else if (tCell::matrix[dN] != ground && tCell::matrix[dNE] == ground)
                { tCell::replace[index] = drop; tCell::replace[dE] = target; }
                else if (tCell::matrix[dN] == ground && tCell::matrix[dNE] == ground)
                { tCell::replace[index] = drop; tCell::replace[dE] = target; }
                else if (tCell::matrix[dN] == ground && tCell::matrix[dE] == ground)
                { tCell::replace[index] = drop; tCell::replace[dSE] = target; }
                else if (tCell::matrix[dN] == ground && tCell::matrix[dNNE] == ground)
                {
                    int t = tCell::matrix[dNE];
                    if (t == tTile::DIRT || t == tTile::SOIL)
                    { tCell::replace[index] = drop; tCell::replace[dNE] = target; }
                }
            }
        }
    }

    void Crawl(int _x, int _y, int index, char season, uint8_t target, uint8_t ground, uint8_t background, int activity)
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

        if (tCell::matrix[dS] == tTile::AIR || tCell::matrix[dS] == background) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = target; }
        if (chance < activity)
        {
            if (direction < 50)
            {
                if (tCell::matrix[dSW] == ground && tCell::matrix[dW] == background)
                { tCell::replace[index] = background; tCell::replace[dW] = target; }
                else if (tCell::matrix[dSSW] == ground && tCell::matrix[dSW] == background)
                { tCell::replace[index] = background; tCell::replace[dSW] = target; }
                else if (tCell::matrix[dW] == ground && tCell::matrix[dNW] == background)
                { tCell::replace[index] = background; tCell::replace[dNW] = target; }
            }
            else
            {
                if (tCell::matrix[dSE] == ground && tCell::matrix[dE] == background)
                { tCell::replace[index] = background; tCell::replace[dE] = target; }
                else if (tCell::matrix[dSSE] == ground && tCell::matrix[dSE] == background)
                { tCell::replace[index] = background; tCell::replace[dSE] = target; }
                else if (tCell::matrix[dE] == ground && tCell::matrix[dNE] == background)
                { tCell::replace[index] = background; tCell::replace[dNE] = target; }
            }
        }
    }

    void Hop(int _x, int _y, int index, char season, uint8_t target, uint8_t legs, uint8_t ground, uint8_t background, int activity)
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

        if (tCell::matrix[dS] == background) { tTool::Swap(dS, index); }
        if (tCell::matrix[dE] == legs) { tTool::Set(dE, background); }
        if (tCell::matrix[dW] == legs) { tTool::Set(dW, background); }
        if (tCell::matrix[dS] == legs)
        {
            if (direction < 50 && tCell::matrix[dNE] == background)
            { tTool::Set(index, background); tTool::Set(dNE, target); tTool::Set(dN, legs); tTool::Set(dS, background); }
            else if (direction > 50 && tCell::matrix[dNW] == background)
            { tTool::Set(index, background); tTool::Set(dNW, target); tTool::Set(dN, legs); tTool::Set(dS, background); }
        }
        else if (tCell::matrix[dSE] == legs && tCell::matrix[dW] == background)
        { tTool::Set(index, legs); tTool::Set(dW, target); tTool::Set(dSE, background); }
        else if (tCell::matrix[dSW] == legs && tCell::matrix[dE] == background)
        { tTool::Set(index, legs); tTool::Set(dE, target); tTool::Set(dSW, background); }
        if (chance < 25)
        { if (tCell::matrix[dS] == ground && tCell::matrix[dN] == background)
            { tCell::replace[index] = legs; tCell::replace[dN] = target;}
        }
    }

    void Jump(int _x, int _y, int index, char season, uint8_t target, uint8_t legs, uint8_t ground, uint8_t background, int activity)
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

        if (tCell::matrix[dS] == background) { tCell::replace[index] = background; tCell::replace[dS] = target; }
        if (tCell::matrix[dE] == legs) { tCell::replace[dE] = background; }
        if (tCell::matrix[dW] == legs) { tCell::replace[dW] = background; }
        if (tCell::matrix[dS] == legs && tCell::matrix[dN] == background)
        { tCell::replace[index] = legs; tCell::replace[dN] = target; tCell::replace[dS] = background; }
        else if (tCell::matrix[dSE] == legs && tCell::matrix[dN] == background)
        { tCell::replace[index] = legs; tCell::replace[dW] = target; tCell::replace[dSE] = background; }
        else if (tCell::matrix[dSW] == legs && tCell::matrix[dN] == background)
        { tCell::replace[index] = legs; tCell::replace[dE] = target; tCell::replace[dSW] = background; }
        if (tCell::matrix[dS] == legs && tCell::matrix[dSS] == background)
        {
            if (direction < 50 && tCell::matrix[dNE] == background)
            { tCell::replace[index] = background; tCell::replace[dNE] = target; tCell::replace[dN] = legs; }
            else if (direction > 50 && tCell::matrix[dNW] == background)
            { tCell::replace[index] = background; tCell::replace[dNW] = target; tCell::replace[dN] = legs; }
        }
        if (chance < 25)
        { if (tCell::matrix[dS] == ground || tCell::matrix[dS] == target)
            { tCell::replace[index] = legs; tCell::replace[dN] = target;}
        }
    }

    void Swim(int _x, int _y, int index, char season, uint8_t target, uint8_t tail, uint8_t egg, uint8_t background, int activity)
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

        if (tCell::matrix[dS] == tTile::AIR)
        {
            tCell::replace[index] = tTile::AIR; tCell::replace[dS] = target;
            if (tCell::matrix[dE] == tail) { tCell::replace[dE] = tTile::AIR; tCell::replace[dSE] = tail; }
            if (tCell::matrix[dW] == tail) { tCell::replace[dW] = tTile::AIR; tCell::replace[dSW] = tail; }
        }
        if (chance < activity)
        {
            if (direction < 50)
            {
                if (rand()%1000 < 25 && tCell::matrix[dE] == tail && tCell::matrix[dW] == background)
                { if (tCell::matrix[dE+1] != target && tCell::matrix[dE+1] != tail) tTool::Swap(index, dW); tTool::Swap(index, dE); }
                else if (tCell::matrix[dE] == tail && tCell::matrix[dW] != background)
                {
                    if (tCell::matrix[dNE] == background) tTool::Swap(index, dNE);
                    else if (tCell::matrix[dSE] == background) tTool::Swap(index, dSE);
                }
                else if (tCell::matrix[dS] == tail && tCell::matrix[dE] == background)
                { if (tCell::matrix[dE+1] != target && tCell::matrix[dE+1] != tail) tTool::Swap(index, dE); }
                else if (tCell::matrix[dN] == tail && tCell::matrix[dE] == background)
                { if (tCell::matrix[dE+1] != target && tCell::matrix[dE+1] != tail) tTool::Swap(index, dE); }
                else if (tCell::matrix[dE] == tail && tCell::matrix[dSW] == background && rand()%1000 < 500)
                { if (tCell::matrix[dSW-1] != target && tCell::matrix[dSW-1] != tail) tTool::Swap(index, dSW); tTool::Swap(index, dE); }
                else if (tCell::matrix[dE] == tail && tCell::matrix[dNW] == background)
                { if (tCell::matrix[dNW-1] != target && tCell::matrix[dNW-1] != tail) tTool::Swap(index, dNW); tTool::Swap(index, dE); }
                else if (tCell::matrix[dNE] == tail && tCell::matrix[dE] == background)
                { if (tCell::matrix[dE+1] != target && tCell::matrix[dNE+1] != target) tTool::Swap(dE, dNE); }
                else if (tCell::matrix[dSE] == tail && tCell::matrix[dE] == background)
                { if (tCell::matrix[dE+1] != target && tCell::matrix[dSE+1] != target) tTool::Swap(dE, dSE); }
                if (tCell::matrix[dW] == tTile::GUTS || tCell::matrix[dW] == tTile:: BLOOD) { tTool::Set(dW, egg); }
                if (tCell::matrix[dNW] == tTile::GUTS || tCell::matrix[dNW] == tTile:: BLOOD) { tTool::Set(dNW, egg); }
                if (tCell::matrix[dSW] == tTile::GUTS || tCell::matrix[dSW] == tTile:: BLOOD) { tTool::Set(dSW, egg); }
            }
            else
            {
                if (rand()%1000 < 25 && tCell::matrix[dW] == tail && tCell::matrix[dE] == background)
                { if (tCell::matrix[dW-1] != target && tCell::matrix[dW-1] != tail) tTool::Swap(index, dE); tTool::Swap(index, dW); }
                else if (tCell::matrix[dW] == tail && tCell::matrix[dE] != background)
                {
                    if (tCell::matrix[dNW] == background) tTool::Swap(index, dNW);
                    else if (tCell::matrix[dSW] == background) tTool::Swap(index, dSW);
                }
                else if (tCell::matrix[dS] == tail && tCell::matrix[dW] == background)
                { if (tCell::matrix[dW-1] != target && tCell::matrix[dW-1] != tail) tTool::Swap(index, dW); }
                else if (tCell::matrix[dN] == tail && tCell::matrix[dW] == background)
                { if (tCell::matrix[dW-1] != target && tCell::matrix[dW-1] != tail) tTool::Swap(index, dW); }
                else if (tCell::matrix[dW] == tail && tCell::matrix[dSE] == background && rand()%1000 < 500)
                { if (tCell::matrix[dSE+1] != target && tCell::matrix[dSE+1] != tail) tTool::Swap(index, dSE); tTool::Swap(index, dW); }
                else if (tCell::matrix[dW] == tail && tCell::matrix[dNE] == background)
                { if (tCell::matrix[dNE+1] != target && tCell::matrix[dNE+1] != tail) tTool::Swap(index, dNE); tTool::Swap(index, dW); }
                else if (tCell::matrix[dNW] == tail && tCell::matrix[dW] == background)
                { if (tCell::matrix[dW-1] != target && tCell::matrix[dNW-1] != target) tTool::Swap(dW, dNW); }
                else if (tCell::matrix[dSW] == tail && tCell::matrix[dW] == background)
                { if (tCell::matrix[dW-1] != target && tCell::matrix[dSW-1] != target) tTool::Swap(dW, dSW); }
                if (tCell::matrix[dE] == tTile::GUTS || tCell::matrix[dE] == tTile:: BLOOD) { tTool::Set(dE, egg); }
                if (tCell::matrix[dNE] == tTile::GUTS || tCell::matrix[dNE] == tTile:: BLOOD) { tTool::Set(dNE, egg); }
                if (tCell::matrix[dSE] == tTile::GUTS || tCell::matrix[dSE] == tTile:: BLOOD) { tTool::Set(dSE, egg); }
            }
        }
    }

    void Fly(int _x, int _y, int index, char season, uint8_t target, uint8_t wing, uint8_t background, int activity)
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

        if (chance < activity)
        {
            if (direction < 50)
            {
                if (rand()%1000 < 25 && tCell::matrix[dE] == wing && tCell::matrix[dW] == background)
                { if (tCell::matrix[dE+1] != target && tCell::matrix[dE+1] != wing) tTool::Swap(index, dW); tTool::Swap(index, dE); }
                else if (tCell::matrix[dE] == wing && tCell::matrix[dW] != background)
                {
                    if (tCell::matrix[dNE] == background) tTool::Swap(index, dNE);
                    else if (tCell::matrix[dSE] == background) tTool::Swap(index, dSE);
                }
                else if (tCell::matrix[dS] == wing && tCell::matrix[dE] == background)
                { if (tCell::matrix[dE+1] != target && tCell::matrix[dE+1] != wing) tTool::Swap(index, dE); }
                else if (tCell::matrix[dN] == wing && tCell::matrix[dE] == background)
                { if (tCell::matrix[dE+1] != target && tCell::matrix[dE+1] != wing) tTool::Swap(index, dE); }
                else if (tCell::matrix[dE] == wing && tCell::matrix[dSW] == background && rand()%1000 < 500)
                { if (tCell::matrix[dSW-1] != target && tCell::matrix[dSW-1] != wing) tTool::Swap(index, dSW); tTool::Swap(index, dE); }
                else if (tCell::matrix[dE] == wing && tCell::matrix[dNW] == background)
                { if (tCell::matrix[dNW-1] != target && tCell::matrix[dNW-1] != wing) tTool::Swap(index, dNW); tTool::Swap(index, dE); }
                else if (tCell::matrix[dNE] == wing && tCell::matrix[dE] == background)
                { if (tCell::matrix[dE+1] != target && tCell::matrix[dNE+1] != target) tTool::Swap(dE, dNE); }
                else if (tCell::matrix[dSE] == wing && tCell::matrix[dE] == background)
                { if (tCell::matrix[dE+1] != target && tCell::matrix[dSE+1] != target) tTool::Swap(dE, dSE); }
            }
            else
            {
                if (rand()%1000 < 25 && tCell::matrix[dW] == wing && tCell::matrix[dE] == background)
                { if (tCell::matrix[dW-1] != target && tCell::matrix[dW-1] != wing) tTool::Swap(index, dE); tTool::Swap(index, dW); }
                else if (tCell::matrix[dW] == wing && tCell::matrix[dE] != background)
                {
                    if (tCell::matrix[dNW] == background) tTool::Swap(index, dNW);
                    else if (tCell::matrix[dSW] == background) tTool::Swap(index, dSW);
                }
                else if (tCell::matrix[dS] == wing && tCell::matrix[dW] == background)
                { if (tCell::matrix[dW-1] != target && tCell::matrix[dW-1] != wing) tTool::Swap(index, dW); }
                else if (tCell::matrix[dN] == wing && tCell::matrix[dW] == background)
                { if (tCell::matrix[dW-1] != target && tCell::matrix[dW-1] != wing) tTool::Swap(index, dW); }
                else if (tCell::matrix[dW] == wing && tCell::matrix[dSE] == background && rand()%1000 < 500)
                { if (tCell::matrix[dSE+1] != target && tCell::matrix[dSE+1] != wing) tTool::Swap(index, dSE); tTool::Swap(index, dW); }
                else if (tCell::matrix[dW] == wing && tCell::matrix[dNE] == background)
                { if (tCell::matrix[dNE+1] != target && tCell::matrix[dNE+1] != wing) tTool::Swap(index, dNE); tTool::Swap(index, dW); }
                else if (tCell::matrix[dNW] == wing && tCell::matrix[dW] == background)
                { if (tCell::matrix[dW-1] != target && tCell::matrix[dNW-1] != target) tTool::Swap(dW, dNW); }
                else if (tCell::matrix[dSW] == wing && tCell::matrix[dW] == background)
                { if (tCell::matrix[dW-1] != target && tCell::matrix[dSW-1] != target) tTool::Swap(dW, dSW); }
            }
        }
    }

    //
    // Special
    //

    void Frog(int _x, int _y, int index, char season)
    {
        uint8_t tile = tCell::matrix[(_y+1)*tCell::width+(_x)]; if (tile == tTile::AIR) tile = tTile::GRASS;
        if (rand()%100 < 75) Jump(_x, _y, index, season, tTile::FROG, tTile::FROG_LEGS, tile, tTile::AIR, 25);
        else Hop(_x, _y, index, season, tTile::FROG, tTile::FROG_LEGS, tile, tTile::AIR, 50);
    }

    void Toad(int _x, int _y, int index, char season)
    {
        uint8_t tile = tCell::matrix[(_y+1)*tCell::width+(_x)]; if (tile == tTile::AIR) tile = tTile::GRASS;
        if (rand()%100 < 25) Jump(_x, _y, index, season, tTile::TOAD, tTile::TOAD_LEGS, tile, tTile::AIR, 25);
        else Hop(_x, _y, index, season, tTile::TOAD, tTile::TOAD_LEGS, tile, tTile::AIR, 50); }

    void Mole(int _x, int _y, int index, char season)
    {
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
        Burrow(_x, _y, index, season, tTile::MOLE, tTile::GRASS, tTile::AIR, DROP, 25);
    }

    void Squirrel(int _x, int _y, int index, char season)
    {
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        uint8_t tile = tCell::matrix[(_y+1)*tCell::width+(_x)];  if (tile == tTile::AIR) tile = tTile::GRASS;
        if (tCell::matrix[dSE] != tile) { Hop(_x, _y, index, season, tTile::SQUIRREL, tTile::SQUIRREL_TAIL, tile, tTile::AIR, 500); }
        else if (tCell::matrix[dSW] != tile) { Hop(_x, _y, index, season, tTile::SQUIRREL, tTile::SQUIRREL_TAIL, tile, tTile::AIR, 500); }
        else { Crawl(_x, _y, index, season, tTile::SQUIRREL, tile, tTile::AIR, 50); }
    }

    void Rabbit(int _x, int _y, int index, char season)
    {
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        uint8_t tile = tCell::matrix[(_y+1)*tCell::width+(_x)];  if (tile == tTile::AIR) tile = tTile::GRASS;
        if (tCell::matrix[dSE] != tile) { Hop(_x, _y, index, season, tTile::RABBIT, tTile::RABBIT_LEGS, tile, tTile::AIR, 500); }
        else if (tCell::matrix[dSW] != tile) { Hop(_x, _y, index, season, tTile::RABBIT, tTile::RABBIT_LEGS, tile, tTile::AIR, 500); }
        else { Crawl(_x, _y, index, season, tTile::RABBIT, tile, tTile::AIR, 50); }
    }

    void Hedgehog(int _x, int _y, int index, char season)
    { Crawl(_x, _y, index, season, tTile::HEDGEHOG, tTile::GRASS, tTile::AIR, 25); }

    void Mouse(int _x, int _y, int index, char season)
    {
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        uint8_t tile = tCell::matrix[(_y+1)*tCell::width+(_x)];  if (tile == tTile::AIR) tile = tTile::GRASS;
        if (tCell::matrix[dSE] != tile) { Hop(_x, _y, index, season, tTile::MOUSE, tTile::MOUSE_TAIL, tile, tTile::AIR, 500); }
        else if (tCell::matrix[dSW] != tile) { Hop(_x, _y, index, season, tTile::MOUSE, tTile::MOUSE_TAIL, tile, tTile::AIR, 500); }
        else { Crawl(_x, _y, index, season, tTile::MOUSE, tile, tTile::AIR, 50); }
    }

    void Rat(int _x, int _y, int index, char season)
    {
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        uint8_t tile = tCell::matrix[(_y+1)*tCell::width+(_x)]; if (tile == tTile::AIR) tile = tTile::GRASS;
        if (tCell::matrix[dSE] != tile) { Hop(_x, _y, index, season, tTile::RAT, tTile::RAT_TAIL, tile, tTile::AIR, 500); }
        else if (tCell::matrix[dSW] != tile) { Hop(_x, _y, index, season, tTile::RAT, tTile::RAT_TAIL, tile, tTile::AIR, 500); }
        else { Crawl(_x, _y, index, season, tTile::RAT, tile, tTile::AIR, 50); }
    }

    void Crab(int _x, int _y, int index, char season)
    { Crawl(_x, _y, index, season, tTile::CRAB, tTile::SAND, tTile::WATER, 25); }

    void Bird(int _x, int _y, int index, char season)
    { Fly(_x, _y, index, season, tTile::BIRD, tTile::BIRD_WING, tTile::AIR, 750); }

    void Bat(int _x, int _y, int index, char season)
    { Fly(_x, _y, index, season, tTile::BAT, tTile::BAT_WING, tTile::AIR, 850); }

    void Fish(int _x, int _y, int index, char season)
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
        Swim(_x, _y, index, season, tTile::FISH, tTile::FISH_TAIL, tTile::FISH_EGG, tTile::WATER, 750);
        if (tCell::matrix[dN] == tTile::WATER && tCell::matrix[dS] == tTile::WATER &&
            tCell::matrix[dE] == tTile::WATER && tCell::matrix[dW] == tTile::WATER &&
            tCell::matrix[dNE] == tTile::WATER && tCell::matrix[dNW] == tTile::WATER &&
            tCell::matrix[dSE] == tTile::WATER && tCell::matrix[dSW] == tTile::WATER)
        { tTool::Set(index, tTile::GUTS); }
    }

    void FishTail(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );

        if (tCell::matrix[dN] == tTile::WATER && tCell::matrix[dS] == tTile::WATER &&
            tCell::matrix[dE] == tTile::WATER && tCell::matrix[dW] == tTile::WATER &&
            tCell::matrix[dNE] == tTile::WATER && tCell::matrix[dNW] == tTile::WATER &&
            tCell::matrix[dSE] == tTile::WATER && tCell::matrix[dSW] == tTile::WATER)
        { tTool::Set(index, tTile::BLOOD); }
    }

    /*
    void Snake(int _x, int _y, int index, char season)
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
            case tTile::CRAB      : {     Crab(_x, _y, index, season); } break;
            case tTile::TOAD      : {     Toad(_x, _y, index, season); } break;
            case tTile::FROG      : {     Frog(_x, _y, index, season); } break;
            case tTile::FISH      : {     Fish(_x, _y, index, season); } break;
            case tTile::FISH_TAIL : { FishTail(_x, _y, index, season); } break;
            case tTile::BIRD      : {     Bird(_x, _y, index, season); } break;
            case tTile::BAT       : {      Bat(_x, _y, index, season); } break;
            case tTile::RAT       : {      Rat(_x, _y, index, season); } break;
            case tTile::MOLE      : {     Mole(_x, _y, index, season); } break;
            case tTile::MOUSE     : {    Mouse(_x, _y, index, season); } break;
            case tTile::HEDGEHOG  : { Hedgehog(_x, _y, index, season); } break;
            case tTile::SQUIRREL  : { Squirrel(_x, _y, index, season); } break;
            case tTile::RABBIT    : {   Rabbit(_x, _y, index, season); } break;
        }
    }

}
