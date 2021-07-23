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
                if (tCell::matrix[dS] == tTile::AIR)
                {
                        if (chance > 100 && chance < 900) {tCell::replace[dS] = tTile::LEAVES;}
                        if (chance > 5 && chance < 995) {tCell::replace[dS] = tTile::ACORN;}
                }
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
                        if (chance > 750) {tCell::replace[dE] = tTile::LEAVES;}
                        if (chance < 50) {tCell::replace[dE] = tTile::ACORN;}
                }
                else if (tCell::matrix[dW] == tTile::AIR)
                {
                        if (chance > 750) {tCell::replace[dW] = tTile::LEAVES;}
                        if (chance < 50) {tCell::replace[dW] = tTile::ACORN;}
                }
            }
        }
    }

    void Stick(int _x, int _y, int index, char season)
    {
        int dNN = int( (_y-2) * tCell::width + (_x  ) );
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dSS = int( (_y+2) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int n;
        int chance = 100;
        if (rand()%250 < 25)
        {
            if (tCell::matrix[dN] == tTile::AIR) n++;
            if (tCell::matrix[dS] == tTile::AIR) n++;
            if (tCell::matrix[dW] == tTile::AIR) n++;
            if (tCell::matrix[dE] == tTile::AIR) n++;
            if (tCell::matrix[dNW] == tTile::AIR) n++;
            if (tCell::matrix[dNE] == tTile::AIR) n++;

            if (n > 1 && n < 6)
            {
                int growth = rand()%250;
                if (tCell::matrix[dN] == tTile::AIR) { if (tCell::matrix[dNN] == tTile::AIR) tCell::replace[dNN] = tTile::LEAVES; }

                if (tCell::matrix[dS] == tTile::AIR) { if (tCell::matrix[dN] == tTile::AIR) tCell::replace[dN] = tTile::LEAVES; }
                
                if (tCell::matrix[dS] == tTile::BRANCH)
                {
                    if (tCell::matrix[dN] == tTile::AIR) tCell::replace[dN] = tTile::STICK;
                    if (tCell::matrix[dNE] == tTile::AIR) tCell::replace[dNE] = tTile::LEAVES;
                    if (tCell::matrix[dNW] == tTile::AIR) tCell::replace[dNW] = tTile::LEAVES;
                }
                if (tCell::matrix[dS] == tTile::STICK)
                {
                    if (growth < 50 && tCell::matrix[dN] == tTile::AIR) tCell::replace[dN] = tTile::STICK;
                    if (growth > 75 && tCell::matrix[dSS] == tTile::AIR) tCell::replace[dSS] = tTile::LEAVES;
                }

                if (tCell::matrix[dS] == tTile::LEAVES) { if (tCell::matrix[dN] == tTile::AIR) tCell::replace[dN] = tTile::LEAVES; }

            }
        }
    }

    void Branch(int _x, int _y, int index, char season)
    {
        int dT = int( (_y+22) * tCell::width + (_x  ) );
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int top = tCell::matrix[dT];
        int left = tCell::matrix[dW-6];
        int farleft = tCell::matrix[dW-8];
        int right = tCell::matrix[dE+6];
        int farright = tCell::matrix[dE+8];
        int direction = rand()%100;
        if (rand()%500 < 25)
        {
            int chance = rand()%100;
            if (top != tTile::AIR)
            {
                int growth = rand()%100;
                // Sprout Sticks/Leaves
                if (right != tTile::TRUNK)
                { if (tCell::matrix[dE] == tTile::BRANCH && tCell::matrix[dE+1] == tTile::BRANCH &&
                    tCell::matrix[dE+2] == tTile::BRANCH && tCell::matrix[dE+3] == tTile::BRANCH)
                    { if (direction < 25) {
                        if (tCell::matrix[dN] == tTile::AIR && tCell::matrix[dN-1] == tTile::AIR)
                            {
                                if (growth > 75 && tCell::matrix[dS] == tTile::AIR) tCell::replace[dS] = tTile::STICK;
                                if (growth < 25 && tCell::matrix[dS] == tTile::AIR) tCell::replace[dS] = tTile::LEAVES;
                            }
                        }
                        if (direction > 75)
                        { if (tCell::matrix[dS] == tTile::AIR && tCell::matrix[dS-1] == tTile::AIR)
                            {
                                if (growth > 75 && tCell::matrix[dN] == tTile::AIR) tCell::replace[dN] = tTile::STICK;
                                if (growth < 25 && tCell::matrix[dN] == tTile::AIR) tCell::replace[dN] = tTile::LEAVES;
                            }
                        }
                    }
                }
                if (left != tTile::TRUNK)
                { if (tCell::matrix[dW] == tTile::BRANCH && tCell::matrix[dW-1] == tTile::BRANCH &&
                    tCell::matrix[dW-2] == tTile::BRANCH && tCell::matrix[dW-3] == tTile::BRANCH)
                    
                    { if (direction < 25) {
                        if (tCell::matrix[dN] == tTile::AIR && tCell::matrix[dN-1] == tTile::AIR)
                            {
                                if (growth > 75 && tCell::matrix[dS] == tTile::AIR) tCell::replace[dS] = tTile::STICK;
                                if (growth < 25 && tCell::matrix[dS] == tTile::AIR) tCell::replace[dS] = tTile::LEAVES;
                            }
                        }
                        if (direction > 75)
                        { if (tCell::matrix[dS] == tTile::AIR && tCell::matrix[dS-1] == tTile::AIR)
                            {
                                if (growth > 75 && tCell::matrix[dN] == tTile::AIR) tCell::replace[dN] = tTile::STICK;
                                if (growth < 25 && tCell::matrix[dN] == tTile::AIR) tCell::replace[dN] = tTile::LEAVES;
                            }
                        }
                    }
                }
                // Extend Branch
                if (farleft != tTile::TRUNK)
                {
                    if ((tCell::matrix[dW] == tTile::BRANCH || tCell::matrix[dW] == tTile::LEAVES) &&
                        (tCell::matrix[dW+1] == tTile::BRANCH || tCell::matrix[dW+1] == tTile::LEAVES))
                    {
                        if (tCell::matrix[dN] == tTile::AIR && tCell::matrix[dN+1] == tTile::AIR)
                        { if (tCell::matrix[dE] == tTile::AIR) tCell::replace[dE] = tTile::BRANCH; }
                    }
                }
                if (farright != tTile::TRUNK)
                {
                    if ((tCell::matrix[dE] == tTile::BRANCH || tCell::matrix[dE] == tTile::LEAVES) &&
                        (tCell::matrix[dE-1] == tTile::BRANCH || tCell::matrix[dE-1] == tTile::LEAVES))
                    {
                        if (tCell::matrix[dN] == tTile::AIR && tCell::matrix[dN-1] == tTile::AIR)
                        { if (tCell::matrix[dW] == tTile::AIR) tCell::replace[dW] = tTile::BRANCH; }
                    }
                }
            }
        }
    }

    void Trunk(int _x, int _y, int index, char season)
    {
        int dB = int( (_y+12) * tCell::width + (_x  ) );
        int dT = int( (_y+64) * tCell::width + (_x  ) );
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS1  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int up = tCell::matrix[dN];
        int down = tCell::matrix[dS1];
        int top = tCell::matrix[dT];
        int bottom = tCell::matrix[dB];
        int direction = rand()%1000;
        if (rand()%1000 < 25)
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
            }
            // Grow Roots
            if (down == tTile::DIRT || down == tTile::SOIL) { tCell::replace[dS1] = tTile::TAPROOT; }
            // Grow Branches
            if (bottom == tTile::TRUNK)
            {
                int dS1  = int( (_y+1) * tCell::width + (_x  ) );
                int dS2  = int( (_y+2) * tCell::width + (_x  ) );
                int dS3  = int( (_y+3) * tCell::width + (_x  ) );
                int dS4  = int( (_y+4) * tCell::width + (_x  ) );
                if (direction < 33 && tTool::GetType(tCell::matrix[dT]) != tTile::PLANT)
                {
                    int dS5  = int( (_y+5) * tCell::width + (_x  ) );
                    int dS6  = int( (_y+6) * tCell::width + (_x  ) );
                    if (tCell::matrix[dS1+1] == tTile::AIR && tCell::matrix[dS2+1] == tTile::AIR &&
                        tCell::matrix[dS3+1] == tTile::AIR && tCell::matrix[dS4+1] == tTile::AIR &&
                        tCell::matrix[dS5+1] == tTile::AIR && tCell::matrix[dS6+1] == tTile::AIR )
                    {
                        if (tCell::matrix[dE] == tTile::AIR) tCell::replace[dE] = tTile::BRANCH;
                    }
                }
                if (direction > 66 && tTool::GetType(tCell::matrix[dT]) != tTile::PLANT)
                {
                    int dS5  = int( (_y+5) * tCell::width + (_x  ) );
                    int dS6  = int( (_y+6) * tCell::width + (_x  ) );
                    if (tCell::matrix[dS1-1] == tTile::AIR && tCell::matrix[dS2-1] == tTile::AIR &&
                        tCell::matrix[dS3-1] == tTile::AIR && tCell::matrix[dS4-1] == tTile::AIR &&
                        tCell::matrix[dS5-1] == tTile::AIR && tCell::matrix[dS6-1] == tTile::AIR )
                    {
                        if (tCell::matrix[dW] == tTile::AIR) tCell::replace[dW] = tTile::BRANCH;
                    }
                }
                if (direction < 20 && tTool::GetType(tCell::matrix[dT]) != tTile::PLANT)
                {
                    if (tCell::matrix[dS1+1] == tTile::AIR && tCell::matrix[dS2+1] == tTile::AIR &&
                        tCell::matrix[dS3+1] == tTile::AIR && tCell::matrix[dS4+1] == tTile::AIR )
                    {
                        if (tCell::matrix[dE] == tTile::AIR) tCell::replace[dE] = tTile::BRANCH;
                        if (tCell::matrix[dE+1] == tTile::AIR) tCell::replace[dE+1] = tTile::BRANCH;
                    }
                }
                if (direction > 80 && tTool::GetType(tCell::matrix[dT]) != tTile::PLANT)
                {
                    if (tCell::matrix[dS1-1] == tTile::AIR && tCell::matrix[dS2-1] == tTile::AIR &&
                        tCell::matrix[dS3-1] == tTile::AIR && tCell::matrix[dS4-1] == tTile::AIR )
                    {
                        if (tCell::matrix[dW] == tTile::AIR) tCell::replace[dW] = tTile::BRANCH;
                        if (tCell::matrix[dW-1] == tTile::AIR) tCell::replace[dW-1] = tTile::BRANCH;
                    }
                }
            }
        }
    }

    void Taproot(int _x, int _y, int index, char season)
    {
        int dT =  int( (_y-24) * tCell::width + (_x  ) );
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        if (rand()%2500 < 25 && tCell::matrix[dN] != tTile::TRUNK) { tCell::replace[index] = tTile::MUD; }
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
        if (rand()%5000 < 25 && tCell::matrix[dN] != tTile::TAPROOT) { tCell::replace[index] = tTile::SOIL; }
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

    void Update(int _x, int _y, int index, int current_cell, char season=tCell::season)
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
