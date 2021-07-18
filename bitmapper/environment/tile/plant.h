namespace tPlant
{

    //
    // Special
    //

    void Grass(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        if (rand()%1000 < 5)
        {
            if ((tCell::matrix[dE] == tTile::DIRT || tCell::matrix[dE] == tTile::SOIL) && !tTool::Collision(_x+1, _y-1)) tCell::replace[dE] = tTile::GRASS;
            else if ((tCell::matrix[dW] == tTile::DIRT || tCell::matrix[dW] == tTile::SOIL) && !tTool::Collision(_x-1, _y-1)) tCell::replace[dW] = tTile::GRASS;
            else if ((tCell::matrix[dNE] == tTile::DIRT || tCell::matrix[dNE] == tTile::SOIL) && !tTool::Collision(_x+1, _y-2)) tCell::replace[dNE] = tTile::GRASS;
            else if ((tCell::matrix[dNW] == tTile::DIRT || tCell::matrix[dNE] == tTile::SOIL) && !tTool::Collision(_x-1, _y-2)) tCell::replace[dNW] = tTile::GRASS;
            else if ((tCell::matrix[dSE] == tTile::DIRT || tCell::matrix[dSE] == tTile::SOIL) && !tTool::Collision(_x+1, _y)) tCell::replace[dSE] = tTile::GRASS;
            else if ((tCell::matrix[dSW] == tTile::DIRT || tCell::matrix[dSE] == tTile::SOIL) && !tTool::Collision(_x-1, _y)) tCell::replace[dSW] = tTile::GRASS;
        }
        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[dS] = tTile::GRASS; tCell::replace[index] = tTile::AIR; }
        else if (tCell::matrix[dN] == tTile::DIRT || tCell::matrix[dN] == tTile::LAVA) { tCell::replace[index] = tTile::DIRT; }
    }

    void Moss(int _x, int _y, int index, char season)
    {
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        if (rand()%1000 < 5)
        {
            if ((tCell::matrix[dE] == tTile::STONE) && !tTool::Collision(_x+1, _y-1)) tCell::replace[dE] = tTile::MOSS;
            else if ((tCell::matrix[dW] == tTile::STONE) && !tTool::Collision(_x-1, _y-1)) tCell::replace[dW] = tTile::MOSS;
            else if ((tCell::matrix[dNE] == tTile::STONE) && !tTool::Collision(_x+1, _y-2)) tCell::replace[dNE] = tTile::MOSS;
            else if ((tCell::matrix[dNW] == tTile::STONE) && !tTool::Collision(_x-1, _y-2)) tCell::replace[dNW] = tTile::MOSS;
            else if ((tCell::matrix[dSE] == tTile::STONE) && !tTool::Collision(_x+1, _y)) tCell::replace[dSE] = tTile::MOSS;
            else if ((tCell::matrix[dSW] == tTile::STONE) && !tTool::Collision(_x-1, _y)) tCell::replace[dSW] = tTile::MOSS;
        }
        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[dS] = tTile::MOSS; tCell::replace[index] = tTile::AIR; }
        else if (tCell::matrix[dN] == tTile::DIRT || tCell::matrix[dN] == tTile::LAVA) { tCell::replace[index] = tTile::DIRT; }
    }
   
    void Leaves(int _x, int _y, int index, char season)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int n;
        int chance = 1000;
        if (rand()%1000 < 25)
        {
            n = 0;
            if (tCell::matrix[dN] == tTile::BRANCH || tCell::matrix[dN] == tTile::STICK) n++;
            if (tCell::matrix[dS] == tTile::BRANCH || tCell::matrix[dS] == tTile::STICK) n++;
            if (tCell::matrix[dE] == tTile::BRANCH || tCell::matrix[dE] == tTile::STICK) n++;
            if (tCell::matrix[dW] == tTile::BRANCH || tCell::matrix[dW] == tTile::STICK) n++;
            if (tCell::matrix[dNE] == tTile::BRANCH || tCell::matrix[dNE] == tTile::STICK) n++;
            if (tCell::matrix[dNW] == tTile::BRANCH || tCell::matrix[dNW] == tTile::STICK) n++;

            if (n > 0 && n < 6)
            {
                if (tCell::matrix[dN] == tTile::AIR)
                {
                        if (chance > 250 && chance < 750) {tCell::replace[dN] = tTile::LEAVES;}
                        if (chance > 5 && chance < 995) {tCell::replace[dN] = tTile::ACORN;}
                }
                else if (tCell::matrix[dNE] == tTile::AIR)
                {
                        if (chance > 750) {tCell::replace[dNE] = tTile::LEAVES;}
                        if (chance < 250) {tCell::replace[dNE] = tTile::ACORN;}
                }
                else if (tCell::matrix[dNW] == tTile::AIR)
                {
                        if (chance > 750) {tCell::replace[dNW] = tTile::LEAVES;}
                        if (chance < 250) {tCell::replace[dNW] = tTile::ACORN;}
                }
                else if (tCell::matrix[dE] == tTile::AIR)
                {
                        if (chance > 995) {tCell::replace[dE] = tTile::LEAVES;}
                        if (chance < 5) {tCell::replace[dE] = tTile::ACORN;}
                }
                else if (tCell::matrix[dW] == tTile::AIR)
                {
                        if (chance > 995) {tCell::replace[dW] = tTile::LEAVES;}
                        if (chance < 5) {tCell::replace[dW] = tTile::ACORN;}
                }
            }
        }
    }

    void Stick(int _x, int _y, int index, char season)
    {
        int dNN = int( (_y-2) * tCell::width + (_x  ) );
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int n;
        int chance = 100;
        if (rand()%1000 < 25)
        {
            if (tCell::matrix[dN] == tTile::AIR) n++;
            if (tCell::matrix[dW] == tTile::AIR) n++;
            if (tCell::matrix[dE] == tTile::AIR) n++;
            if (tCell::matrix[dNW] == tTile::AIR) n++;
            if (tCell::matrix[dNE] == tTile::AIR) n++;

            if (tCell::matrix[dN] == tTile::TRUNK) n = 10;
            if (tCell::matrix[dW] == tTile::TRUNK) n = 10;
            if (tCell::matrix[dE] == tTile::TRUNK) n = 10;
            if (tCell::matrix[dNW] == tTile::TRUNK) n = 10;
            if (tCell::matrix[dNE] == tTile::TRUNK) n = 10;

            if ((n > 1 && n < 5) || n == 10)
            {
                if (tCell::matrix[dN] == tTile::AIR) { if (tCell::matrix[dNN] == tTile::AIR) tCell::replace[dNN] = tTile::LEAVES; }

                if (tCell::matrix[dS] == tTile::AIR) { if (tCell::matrix[dN] == tTile::AIR) tCell::replace[dN] = tTile::LEAVES; }
                if (tCell::matrix[dS] == tTile::BRANCH) { if (tCell::matrix[dN] == tTile::AIR) tCell::replace[dN] = tTile::STICK; }
                if (tCell::matrix[dS] == tTile::STICK) { if (tCell::matrix[dN] == tTile::AIR) tCell::replace[dN] = tTile::LEAVES; }
                if (tCell::matrix[dS] == tTile::LEAVES) { if (tCell::matrix[dN] == tTile::AIR) tCell::replace[dN] = tTile::LEAVES; }

            }
        }
    }

    void Branch(int _x, int _y, int index, char season)
    {
        int dL = int( (_y+10) * tCell::width + (_x  ) );
        int dM = int( (_y+14) * tCell::width + (_x  ) );
        int dT = int( (_y+22) * tCell::width + (_x  ) );
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int top = tCell::matrix[dT];
        int middle = tCell::matrix[dM];
        int bottom = tCell::matrix[dL];
        int left = tCell::matrix[dW-8];
        int farleft = tCell::matrix[dW-12];
        int right = tCell::matrix[dE+8];
        int farright = tCell::matrix[dE+12];
        if (rand()%100 < 5)
        {
            int chance = rand()%100;
            if (top != tTile::AIR)
            {
                if (right != tTile::TRUNK)
                { if (tCell::matrix[dW] == tTile::BRANCH || tCell::matrix[dW] == tTile::LEAVES)
                    { if (tCell::matrix[dS-1] == tTile::AIR || tCell::matrix[dS-1] == tTile::LEAVES)
                        { tCell::replace[dS-1] = tTile::STICK; } } }
                if (left != tTile::TRUNK)
                { if (tCell::matrix[dE] == tTile::BRANCH || tCell::matrix[dE] == tTile::LEAVES)
                    { if (tCell::matrix[dS+1] == tTile::AIR && tCell::matrix[dS+1] == tTile::LEAVES)
                        { tCell::replace[dS+1] = tTile::STICK; } } }
                if (right != tTile::TRUNK)
                {
                    if ((tCell::matrix[dW] == tTile::BRANCH || tCell::matrix[dW] == tTile::LEAVES) &&
                        (tCell::matrix[dW+1] == tTile::BRANCH || tCell::matrix[dW+1] == tTile::LEAVES))// || matrix[dW+2] == BRANCH)
                    {
                        if (tCell::matrix[dN] == tTile::AIR && tCell::matrix[dN-1] == tTile::AIR && tCell::matrix[dN-2] == tTile::AIR)
                        { tCell::replace[dN-2] = tTile::STICK; }
                    }
                }
                if (left != tTile::TRUNK)
                {
                    if ((tCell::matrix[dE] == tTile::BRANCH || tCell::matrix[dE] == tTile::LEAVES) &&
                        (tCell::matrix[dE+1] == tTile::BRANCH || tCell::matrix[dE+1] == tTile::LEAVES))// || matrix[dE+2] == BRANCH)
                    {
                        if (tCell::matrix[dN] == tTile::AIR && tCell::matrix[dN+1] == tTile::AIR && tCell::matrix[dN+2] == tTile::AIR)
                        { tCell::replace[dN+2] = tTile::STICK; }
                    }
                }
            }
            else if (middle != tTile::AIR)
            {
                int direction = rand()%100;
                if (left != tTile::TRUNK)
                {
                    if (tCell::matrix[dW] == tTile::BRANCH || tCell::matrix[dW] == tTile::LEAVES)
                    { if (tCell::matrix[dS-1] == tTile::AIR || tCell::matrix[dS-1] == tTile::LEAVES)
                        { tCell::replace[dS-1] = tTile::STICK; }}
                }
                if (left != tTile::TRUNK)
                {
                    if (tCell::matrix[dE] == tTile::BRANCH || tCell::matrix[dE] == tTile::LEAVES)
                    { if (tCell::matrix[dS+1] == tTile::AIR || tCell::matrix[dS+1] == tTile::LEAVES)
                        { tCell::replace[dS+1] = tTile::STICK; } }
                }
                if (farright != tTile::TRUNK)
                {
                    if ((tCell::matrix[dW] == tTile::BRANCH || tCell::matrix[dW] == tTile::LEAVES) &&
                        (tCell::matrix[dW-1] == tTile::BRANCH || tCell::matrix[dW-1] == tTile::LEAVES) &&
                        (tCell::matrix[dW-2] == tTile::BRANCH || tCell::matrix[dW-2] == tTile::LEAVES))
                    {
                        if (direction < 25)
                        {
                            if (tCell::matrix[dN-1] == tTile::AIR && tCell::matrix[dN-2] == tTile::AIR && tCell::matrix[dN-3] == tTile::AIR)
                            { tCell::replace[dN-2] = tTile::STICK; }
                            if (tCell::matrix[dS-1] == tTile::AIR && tCell::matrix[dS-2] == tTile::AIR && tCell::matrix[dS-3] == tTile::AIR)
                            { tCell::replace[dS-2] = tTile::LEAVES; }
                        }
                        if (direction > 25 && direction < 50)
                        {
                            if (tCell::matrix[dN] == tTile::AIR && tCell::matrix[dN+1] == tTile::AIR) { tCell::replace[dN+1] = tTile::STICK; }
                            if (tCell::matrix[dS] == tTile::AIR && tCell::matrix[dS+1] == tTile::AIR) { tCell::replace[dS+1] = tTile::LEAVES; }
                        }
                        if (direction > 50 && direction < 75)
                        {
                            if (tCell::matrix[dN] == tTile::AIR && tCell::matrix[dN-1] == tTile::AIR) { tCell::replace[dN-1] = tTile::STICK; }
                            if (tCell::matrix[dS] == tTile::AIR && tCell::matrix[dS-1] == tTile::AIR) { tCell::replace[dS-1] = tTile::LEAVES; }
                        }
                        if (direction > 75)
                        {
                            if (tCell::matrix[dN+1] == tTile::AIR && tCell::matrix[dN+2] == tTile::AIR && tCell::matrix[dN+3] == tTile::AIR)
                            { tCell::replace[dN+2] = tTile::STICK; }
                            if (tCell::matrix[dS+1] == tTile::AIR && tCell::matrix[dS+2] == tTile::AIR && tCell::matrix[dS+3] == tTile::AIR)
                            { tCell::replace[dS+2] = tTile::LEAVES; }
                        }
                    }
                }
                if (farleft != tTile::TRUNK)
                {
                    if ((tCell::matrix[dE] == tTile::BRANCH || tCell::matrix[dE] == tTile::LEAVES) &&
                        (tCell::matrix[dE+1] == tTile::BRANCH || tCell::matrix[dE+1] == tTile::LEAVES) &&
                        (tCell::matrix[dE+2] == tTile::BRANCH || tCell::matrix[dE+2] == tTile::LEAVES))
                    {
                        if (direction < 25)
                        {
                            if (tCell::matrix[dN-1] == tTile::AIR && tCell::matrix[dN-2] == tTile::AIR && tCell::matrix[dN-3] == tTile::AIR)
                            { tCell::replace[dN-2] = tTile::LEAVES; }
                            if (tCell::matrix[dS-1] == tTile::AIR && tCell::matrix[dS-2] == tTile::AIR && tCell::matrix[dS-3] == tTile::AIR)
                            { tCell::replace[dS-2] = tTile::STICK; }
                        }
                        if (direction > 25 && direction < 50)
                        {
                            if (tCell::matrix[dN+1] == tTile::AIR && tCell::matrix[dN+2] == tTile::AIR) { tCell::replace[dN+1] = tTile::LEAVES; }
                            if (tCell::matrix[dS+1] == tTile::AIR && tCell::matrix[dS+2] == tTile::AIR) { tCell::replace[dS+1] = tTile::STICK; }
                        }
                        if (direction > 50 && direction < 75)
                        {
                            if (tCell::matrix[dN-1] == tTile::AIR && tCell::matrix[dN-2] == tTile::AIR) { tCell::replace[dN-1] = tTile::STICK; }
                            if (tCell::matrix[dS-1] == tTile::AIR && tCell::matrix[dS-2] == tTile::AIR) { tCell::replace[dS-1] = tTile::LEAVES; }
                        }
                        if (direction > 75)
                        {
                            if (tCell::matrix[dN+1] == tTile::AIR && tCell::matrix[dN+2] == tTile::AIR && tCell::matrix[dN+3] == tTile::AIR)
                            { tCell::replace[dN+2] = tTile::STICK; }
                            if (tCell::matrix[dS+1] == tTile::AIR && tCell::matrix[dS+2] == tTile::AIR && tCell::matrix[dS+3] == tTile::AIR)
                            { tCell::replace[dS+2] = tTile::LEAVES; }
                        }
                    }
                }
            }
            else if (bottom != tTile::AIR)
            {
                if (left != tTile::TRUNK)
                {
                    if (tCell::matrix[dW] == tTile::BRANCH)
                    { if (tCell::matrix[dS-1] == tTile::AIR && tCell::matrix[dS-2] == tTile::AIR) { tCell::replace[dS-2] = tTile::STICK; }}
                }
                if (left != tTile::TRUNK)
                {
                    if (tCell::matrix[dE] == tTile::BRANCH)
                    { if (tCell::matrix[dS+1] == tTile::AIR && tCell::matrix[dS+2] == tTile::AIR) { tCell::replace[dS+2] = tTile::STICK; } }
                }
            }
        }
    }

    void Trunk(int _x, int _y, int index, char season)
    {
        int dStart = int( (_y+12) * tCell::width + (_x  ) );
        int dB = int( (_y+8) * tCell::width + (_x  ) );
        int dL = int( (_y+16) * tCell::width + (_x  ) );
        int dM = int( (_y+20) * tCell::width + (_x  ) );
        int dT = int( (_y+24) * tCell::width + (_x  ) );
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS1  = int( (_y+1) * tCell::width + (_x  ) );
        int dS2  = int( (_y+2) * tCell::width + (_x  ) );
        int dS3  = int( (_y+3) * tCell::width + (_x  ) );
        int dS4  = int( (_y+4) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int up = tCell::matrix[dN];
        int down = tCell::matrix[dS1];
        int top = tCell::matrix[dT];
        int middle = tCell::matrix[dM];
        int bottom = tCell::matrix[dL];
        int start = tCell::matrix[dStart];
        int direction = rand()%1000;
        if (rand()%1000 < 5)
        {
            // Grow Trunk
            if (tTool::GetType(tCell::matrix[dT-1]) != tTile::PLANT &&
                tTool::GetType(tCell::matrix[dT+1]) != tTile::PLANT &&
                tCell::matrix[dT-1] != tTile::AIR &&
                tCell::matrix[dT+1] != tTile::AIR )
            {
                if (up == tTile::AIR || up == tTile::ACORN || up == tTile::WATER)
                {
                    if (tCell::matrix[dS1] == tTile::TRUNK) {tCell::replace[dN] = tTile::TRUNK; }
                }
                else if (up == tTile::BRANCH || up == tTile::STICK)
                {
                    if (direction < 25)
                    {
                        if ((bottom == tTile::TRUNK &&
                            tCell::matrix[dB-1] == tTile::TRUNK &&
                            tCell::matrix[dS1-1] == tTile::TRUNK &&
                            tCell::matrix[dL-2] == tTile::TRUNK))
                        { tCell::replace[dE] = tTile::TRUNK; tCell::replace[dB+1] = tTile::TRUNK; tCell::replace[dS1-1] = tTile::BRANCH; }
                        if ((bottom == tTile::TRUNK &&
                            tCell::matrix[dB+1] == tTile::TRUNK &&
                            tCell::matrix[dS1+1] == tTile::TRUNK &&
                            tCell::matrix[dL+2] == tTile::TRUNK))
                        { tCell::replace[dW] = tTile::TRUNK; tCell::replace[dB-1] = tTile::TRUNK; tCell::replace[dS1-1] = tTile::BRANCH; }
                    }
                }
                else
                    {
                    if (direction < 5)
                    {
                        if ((bottom == tTile::TRUNK &&
                            tCell::matrix[dB-1] == tTile::TRUNK &&
                            tCell::matrix[dS1-1] == tTile::TRUNK &&
                            tCell::matrix[dL-2] == tTile::TRUNK))
                        { tCell::replace[dE] = tTile::TRUNK; tCell::replace[dB+1] = tTile::TRUNK; tCell::replace[dS1-1] = tTile::BRANCH; }
                        if ((bottom == tTile::TRUNK &&
                            tCell::matrix[dB+1] == tTile::TRUNK &&
                            tCell::matrix[dS1+1] == tTile::TRUNK &&
                            tCell::matrix[dL+2] == tTile::TRUNK))
                        { tCell::replace[dW] = tTile::TRUNK; tCell::replace[dB-1] = tTile::TRUNK; tCell::replace[dS1-1] = tTile::BRANCH; }
                    }
                }
            }
            if (tCell::matrix[dS1] == tTile::TRUNK && middle == tTile::TRUNK)
            {
                if (up == tTile::AIR || up == tTile::ACORN || up == tTile::WATER || up == tTile::BRANCH)
                {
                    if ((tCell::matrix[dE] != tTile::TRUNK && tCell::matrix[dW] == tTile::TRUNK) ||
                        (tCell::matrix[dE] == tTile::TRUNK && tCell::matrix[dW] != tTile::TRUNK)) {tCell::replace[dN] = tTile::TRUNK;}
                }
                else if (up == tTile::BRANCH || up == tTile::STICK)
                {
                    if (direction < 25)
                    {
                        if ((bottom == tTile::TRUNK &&
                            tCell::matrix[dB-1] == tTile::TRUNK &&
                            tCell::matrix[dS1-1] == tTile::TRUNK &&
                            tCell::matrix[dL-2] == tTile::TRUNK))
                        { tCell::replace[dE] = tTile::TRUNK; tCell::replace[dB+1] = tTile::TRUNK; tCell::replace[dS1-1] = tTile::BRANCH; }
                        if ((bottom == tTile::TRUNK &&
                            tCell::matrix[dB+1] == tTile::TRUNK &&
                            tCell::matrix[dS1+1] == tTile::TRUNK &&
                            tCell::matrix[dL+2] == tTile::TRUNK))
                        { tCell::replace[dW] = tTile::TRUNK; tCell::replace[dB-1] = tTile::TRUNK; tCell::replace[dS1-1] = tTile::BRANCH; }
                    }
                }
                else
                    {
                    if (direction < 5)
                    {
                        if ((bottom == tTile::TRUNK &&
                            tCell::matrix[dB-1] == tTile::TRUNK &&
                            tCell::matrix[dS1-1] == tTile::TRUNK &&
                            tCell::matrix[dL-2] == tTile::TRUNK))
                        { tCell::replace[dE] = tTile::TRUNK; tCell::replace[dB+1] = tTile::TRUNK; tCell::replace[dS1-1] = tTile::BRANCH; }
                        if ((bottom == tTile::TRUNK &&
                            tCell::matrix[dB+1] == tTile::TRUNK &&
                            tCell::matrix[dS1+1] == tTile::TRUNK &&
                            tCell::matrix[dL+2] == tTile::TRUNK))
                        { tCell::replace[dW] = tTile::TRUNK; tCell::replace[dB-1] = tTile::TRUNK; tCell::replace[dS1-1] = tTile::BRANCH; }
                    }
                }
            }
            if (tCell::matrix[dS1] == tTile::TRUNK && bottom == tTile::TRUNK)
            {
                if (up == tTile::AIR || up == tTile::ACORN || up == tTile::WATER || up == tTile::BRANCH || up == tTile::STICK)
                {
                    if (tCell::matrix[dE] != tTile::TRUNK &&
                        tCell::matrix[dW] != tTile::TRUNK)
                    {tCell::replace[dN] = tTile::TRUNK;}
                }
                else if (up == tTile::STICK)
                {
                    if (direction < 25)
                    {
                        if ((bottom == tTile::TRUNK &&
                            tCell::matrix[dB-1] == tTile::TRUNK &&
                            tCell::matrix[dS1-2] == tTile::TRUNK &&
                            tCell::matrix[dL-2] == tTile::TRUNK))
                        { tCell::replace[dE] = tTile::TRUNK; tCell::replace[dB+1] = tTile::TRUNK; tCell::replace[dS1-1] = tTile::BRANCH; }
                        if ((bottom == tTile::TRUNK &&
                            tCell::matrix[dB+1] == tTile::TRUNK &&
                            tCell::matrix[dS1+2] == tTile::TRUNK &&
                            tCell::matrix[dL+2] == tTile::TRUNK))
                        { tCell::replace[dW] = tTile::TRUNK; tCell::replace[dB-1] = tTile::TRUNK; tCell::replace[dS1-1] = tTile::BRANCH; }
                    }
                }
                else
                    {
                    if (direction < 5)
                    {
                        if ((bottom == tTile::TRUNK &&
                            tCell::matrix[dB-1] == tTile::TRUNK &&
                            tCell::matrix[dS1-2] == tTile::TRUNK &&
                            tCell::matrix[dL-2] == tTile::TRUNK))
                        { tCell::replace[dE] = tTile::TRUNK; tCell::replace[dB+1] = tTile::TRUNK; tCell::replace[dS1-1] = tTile::BRANCH; }
                        if ((bottom == tTile::TRUNK &&
                            tCell::matrix[dB+1] == tTile::TRUNK &&
                            tCell::matrix[dS1+2] == tTile::TRUNK &&
                            tCell::matrix[dL+2] == tTile::TRUNK))
                        { tCell::replace[dW] = tTile::TRUNK; tCell::replace[dB-1] = tTile::TRUNK; tCell::replace[dS1-1] = tTile::BRANCH; }
                    }
                }
            }
            // Grow Roots
            if (down == tTile::DIRT || down == tTile::SOIL) { tCell::replace[dS1] = tTile::TAPROOT; }
            // Grow Branches
            if (start == tTile::TRUNK)
            {
                int direction = rand()%100;
                if (bottom == tTile::TRUNK)
                {
                    if (tCell::matrix[dS1+1] == tTile::AIR &&
                        tCell::matrix[dS2+1] == tTile::AIR &&
                        tCell::matrix[dS3+1] == tTile::AIR)
                    {
                        if (tCell::matrix[dE] == tTile::AIR && tCell::matrix[dE+1] == tTile::AIR && direction > 95)
                        { if (tCell::matrix[dE] == tTile::AIR) {tCell::replace[dE] = tTile::BRANCH; tCell::replace[dE+1] = tTile::BRANCH;}}
                    }
                    if (tCell::matrix[dS1-1] == tTile::AIR &&
                            tCell::matrix[dS2-1] == tTile::AIR &&
                            tCell::matrix[dS3-1] == tTile::AIR)
                    {
                        if (tCell::matrix[dW] == tTile::AIR && tCell::matrix[dW-1] == tTile::AIR && direction < 5)
                        { if (tCell::matrix[dW] == tTile::AIR) {tCell::replace[dW] = tTile::BRANCH; tCell::replace[dW-1] = tTile::BRANCH;}}
                    }
                }
                else if (middle == tTile::TRUNK)
                {
                    if (tCell::matrix[dS1+1] == tTile::AIR &&
                        tCell::matrix[dS2+1] == tTile::AIR &&
                        tCell::matrix[dS3+1] == tTile::AIR &&
                        tCell::matrix[dS4+1] == tTile::AIR)
                    {
                        if (tCell::matrix[dE] == tTile::AIR && tCell::matrix[dE+1] == tTile::AIR && direction > 75)
                        {
                            tCell::replace[dE] = tTile::BRANCH;
                            tCell::replace[dE+1] = tTile::BRANCH;
                            tCell::replace[dE+2] = tTile::BRANCH;
                            tCell::replace[dE+3] = tTile::BRANCH;
                        }
                    }
                    if (tCell::matrix[dS1-1] == tTile::AIR && tCell::matrix[dS2-1] == tTile::AIR &&
                        tCell::matrix[dS3-2] == tTile::AIR && tCell::matrix[dS4-1] == tTile::AIR)
                    {
                        if (tCell::matrix[dW] == tTile::AIR && tCell::matrix[dW-1] == tTile::AIR && direction < 25)
                        {
                            tCell::replace[dW] = tTile::BRANCH;
                            tCell::replace[dW-1] = tTile::BRANCH;
                            tCell::replace[dW-2] = tTile::BRANCH;
                            tCell::replace[dW-3] = tTile::BRANCH;
                        }
                    }
                }
                else if (top == tTile::TRUNK)
                {
                    if ((tCell::matrix[dS1+1] == tTile::AIR) || tCell::matrix[dS1+1] == tTile::LEAVES)
                    {
                        if (tCell::matrix[dE] == tTile::AIR && tCell::matrix[dE+1] == tTile::AIR && direction > 97)
                        { if (tCell::matrix[dW] == tTile::AIR) tCell::replace[dW] = tTile::BRANCH; tCell::replace[dE+1] = tTile::BRANCH;}
                    }
                    if (tCell::matrix[dS1-1] == tTile::AIR && tCell::matrix[dS2-1])
                    {
                        if (tCell::matrix[dW] == tTile::AIR && tCell::matrix[dW-1] == tTile::AIR && direction < 3)
                        { if (tCell::matrix[dE] == tTile::AIR) tCell::replace[dW] = tTile::BRANCH; tCell::replace[dW-1] = tTile::BRANCH;}
                    }
                }
            }
        }
    }

    void Taproot(int _x, int _y, int index, char season)
    {
        int dT =  int( (_y-24) * tCell::width + (_x  ) );
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        if (rand()%50000 < 2 && tCell::matrix[dN] != tTile::TRUNK) { tCell::replace[index] = tTile::MUD; }
        if ((tCell::matrix[dT] == tTile::TRUNK || tCell::matrix[dT] == tTile::BRANCH) && rand()%10000 < 25)
        {
            int dS  = int( (_y+1) * tCell::width + (_x  ) );
            int dSW = int( (_y+1  ) * tCell::width + (_x-1) );
            int dSE = int( (_y+1  ) * tCell::width + (_x+1) );
            int dW =  int( (_y  ) * tCell::width + (_x-1) );
            int dE =  int( (_y  ) * tCell::width + (_x+1) );
            int direction = rand()%1000;
            if (direction > 50 && direction < 950 && (tCell::matrix[dS] == tTile::DIRT || tCell::matrix[dS] == tTile::SOIL || tCell::matrix[dS] == tTile::MUD))
                { if (tCell::matrix[dE] != tTile::ROOT && tCell::matrix[dW] != tTile::ROOT) tCell::replace[dS] = tTile::TAPROOT; }

            if ((tCell::matrix[dSW] == tTile::DIRT || tCell::matrix[dSW] == tTile::SOIL || tCell::matrix[dS] == tTile::MUD) &&
                    tCell::matrix[dS] != tTile::TAPROOT && tCell::matrix[dN+1] != tTile::TAPROOT)
            {
                if (direction < 50) { tCell::replace[dSW] = tTile::TAPROOT; }
                if (direction < 25) { tCell::replace[dSW] = tTile::TAPROOT; }
            }
            if ((tCell::matrix[dSE] == tTile::DIRT || tCell::matrix[dSE] == tTile::SOIL || tCell::matrix[dS] == tTile::MUD) &&
                    tCell::matrix[dS] != tTile::TAPROOT && tCell::matrix[dN-1] != tTile::TAPROOT)
            {
                if (direction > 950) { tCell::replace[dSW] = tTile::TAPROOT; }
                if (direction > 975) { tCell::replace[dSW] = tTile::TAPROOT; }
            }
        }
    }

    void Root(int _x, int _y, int index, char season)
    {
        int dT =  int( (_y-12) * tCell::width + (_x  ) );
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        if (rand()%50000 < 10 && tCell::matrix[dN] != tTile::TAPROOT) { tCell::replace[index] = tTile::SOIL; }
        if ((tCell::matrix[dT] == tTile::AIR || tCell::matrix[dT] == tTile::TAPROOT) && rand()%10000 < 25)
        {
            int dS  = int( (_y+1) * tCell::width + (_x  ) );
            int dSW = int( (_y+1  ) * tCell::width + (_x-1) );
            int dSE = int( (_y+1  ) * tCell::width + (_x+1) );
            int dW =  int( (_y  ) * tCell::width + (_x-1) );
            int dE =  int( (_y  ) * tCell::width + (_x+1) );
            int direction = rand()%100;
            if (direction > 25 && direction < 75 && (tCell::matrix[dS] == tTile::DIRT || tCell::matrix[dS] == tTile::SOIL))
                { if (tCell::matrix[dE] != tTile::ROOT && tCell::matrix[dW] != tTile::ROOT) tCell::replace[dS] = tTile::ROOT; }
            if (direction < 25)
            {
                if ((tCell::matrix[dSW] == tTile::DIRT || tCell::matrix[dSW] == tTile::SOIL) &&
                    (tCell::matrix[dS] != tTile::ROOT && tCell::matrix[dE-2] != tTile::TAPROOT) &&
                    (tCell::matrix[dS] != tTile::ROOT && tCell::matrix[dE-2] != tTile::ROOT))
                { tCell::replace[dSW] = tTile::ROOT; }
            }
            if (direction > 75)
            {
                if ((tCell::matrix[dSE] == tTile::DIRT || tCell::matrix[dSE] == tTile::SOIL) &&
                    (tCell::matrix[dS] != tTile::ROOT && tCell::matrix[dW+2] != tTile::TAPROOT) &&
                    (tCell::matrix[dS] != tTile::ROOT && tCell::matrix[dW+2] != tTile::ROOT))
                { tCell::replace[dSE] = tTile::ROOT; }
            }
        }
    }



    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell, char season=0)
    {
        switch (current_cell)
        {
            case tTile::GRASS : { Grass(_x, _y, index, season); } break;
            case tTile::MOSS : { Moss(_x, _y, index, season); } break;
            case tTile::ROOT : { Root(_x, _y, index, season); } break;
            case tTile::TAPROOT : { Taproot(_x, _y, index, season); } break;
            case tTile::TRUNK : { Trunk(_x, _y, index, season); } break;
            case tTile::BRANCH : { Branch(_x, _y, index, season); } break;
            case tTile::STICK : { Stick(_x, _y, index, season); } break;
            case tTile::LEAVES : { Leaves(_x, _y, index, season); } break;
        }
    }

}
