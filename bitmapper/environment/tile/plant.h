namespace tPlant
{

    //
    // Special
    //

    void Grass(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dNN = int( (_y-2) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        if (rand()%1000 < 5)
        {
            if (tCell::matrix[dN] == tTile::DEAD_LEAVES)
            {
                if (tCell::matrix[dNN] == tTile::DEAD_LEAVES) { tCell::replace[dN] = tTile::SOIL; tCell::replace[dNN] = tTile::AIR; }
                else { tCell::replace[dN] = tTile::AIR; }
            }
            if (tCell::matrix[dN] == tTile::GRASS) { tCell::replace[index] = tTile::DIRT; }
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

    void Moss(int _x, int _y, int index)
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
   
    void Leaves(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int dNE = int( (_y-1) * tCell::width + (_x+1) );
        int dNW = int( (_y-1) * tCell::width + (_x-1) );
        int dSE = int( (_y+1) * tCell::width + (_x+1) );
        int dSW = int( (_y+1) * tCell::width + (_x-1) );

        int16_t mI = tCell::matrix[index];
        int16_t mN = tCell::matrix[dN];
        int16_t mS = tCell::matrix[dS];
        int16_t mE = tCell::matrix[dE];
        int16_t mW = tCell::matrix[dW];
        int16_t mNE = tCell::matrix[dNE];
        int16_t mNW = tCell::matrix[dNW];
        int16_t mSE = tCell::matrix[dSE];
        int16_t mSW = tCell::matrix[dSW];

        int n;
        int drop = rand()%100;
        int chance = rand()%1000;
        int16_t LEAVES = tTile::LEAVES;
        
        if (tCell::season > seasonID::LATE_SUMMER)
        {
            int despawn;
            switch (tCell::season)
            {
                case seasonID::EARLY_AUTUMN : { LEAVES = tTile::OLD_LEAVES; despawn = 5; } break;
                case seasonID::AUTUMN :       { LEAVES = tTile::DRY_LEAVES; despawn = 10; } break;
                case seasonID::LATE_AUTUMN :  { LEAVES = tTile::DEAD_LEAVES; despawn = 15; } break;
                case seasonID::EARLY_WINTER : { LEAVES = tTile::AIR; despawn = 20; } break;
                case seasonID::WINTER :       { LEAVES = tTile::AIR; despawn = 25; } break;
                case seasonID::LATE_WINTER :  { LEAVES = tTile::AIR; despawn = 30; } break;
            }
            if (rand()%1000 < 5) { tCell::replace[index] = LEAVES; }
            if (tCell::season > seasonID::AUTUMN) { if (rand()%1000 < despawn) tCell::replace[index] = tTile::AIR; }

        }
        int proceed = 0;
        switch (tCell::season)
        {
            case seasonID::EARLY_SPRING : { proceed =  5; } break;
            case seasonID::SPRING       : { proceed = 15; } break;
            case seasonID::LATE_SPRING  : { proceed = 25; } break;
            case seasonID::EARLY_SUMMER : { proceed = 30; } break;
            case seasonID::SUMMER       : { proceed = 25; } break;
            case seasonID::LATE_SUMMER  : { proceed = 20; } break;
            case seasonID::EARLY_AUTUMN : { proceed = 15; } break;
            case seasonID::AUTUMN       : { proceed = 10; } break;
            case seasonID::LATE_AUTUMN  : { proceed =  5; } break;
        }
        if (rand()%1000 < proceed && tCell::season < seasonID::EARLY_AUTUMN)
        {
            n = 0;
            if (mN == tTile::BRANCH || mN == tTile::STICK) n++;
            if (mS == tTile::BRANCH || mS == tTile::STICK) n++;
            if (mE == tTile::BRANCH || mE == tTile::STICK) n++;
            if (mW == tTile::BRANCH || mW == tTile::STICK) n++;
            if (mNE == tTile::BRANCH || mNE == tTile::STICK) n++;
            if (mNW == tTile::BRANCH || mNW == tTile::STICK) n++;
            if (mSE == tTile::BRANCH || mSE == tTile::STICK) n++;
            if (mSW == tTile::BRANCH || mSW == tTile::STICK) n++;
            if (n > 2 && n < 6)
            {
                if (mN == tTile::AIR || mN == tTile::DEAD_LEAVES)
                {
                        if (chance > 250 && chance < 750) {tCell::replace[dN] = LEAVES;}
                        if (drop < 5 || drop > 95) {tCell::replace[dN] = tTile::ACORN;}
                }
                else if (mS == tTile::AIR || mS == tTile::DEAD_LEAVES)
                { if (chance > 100 && chance < 900) {tCell::replace[dS] = LEAVES;} }
                if (mE == tTile::AIR || mE == tTile::DEAD_LEAVES)
                { if (chance > 750) {tCell::replace[dE] = LEAVES;} }
                else if (mW == tTile::AIR || mW == tTile::DEAD_LEAVES)
                { if (chance > 750) {tCell::replace[dW] = LEAVES;} }
                if (mNE == tTile::AIR || mNE == tTile::DEAD_LEAVES)
                { if (chance > 750) {tCell::replace[dNE] = LEAVES;} }
                else if (mNW == tTile::AIR || mNW == tTile::DEAD_LEAVES)
                { if (chance > 750) {tCell::replace[dNW] = LEAVES;} }
                if (mSE == tTile::AIR || mSE == tTile::DEAD_LEAVES)
                { if (chance > 750) {tCell::replace[dSE] = LEAVES;} }
                else if (mSW == tTile::AIR || mSW == tTile::DEAD_LEAVES)
                { if (chance > 750) {tCell::replace[dSW] = LEAVES;} }
            }
        }
    }

    void DeadLeaves(int _x, int _y, int index)
    {
        if (!tTool::DualCollision(_x, _y+1)) { int rplc = (_y+1)*tCell::width+(_x); tTool::Swap(index, rplc); }
        else if (!tTool::DualCollision(_x-1, _y+1)) { int rplc = (_y+1)*tCell::width+(_x-1); tTool::Swap(index, rplc); }
        else if (!tTool::DualCollision(_x+1, _y+1)) { int rplc = (_y+1)*tCell::width+(_x+1); tTool::Swap(index, rplc); }
        else if (tCell::matrix[(_y+1)*tCell::width+(_x)] == tTile::SOIL) { if (rand()%1000 < 25) tCell::replace[index] = tTile::SOIL; }
    }

    void Stick(int _x, int _y, int index)
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
        int proceed = 0;
        switch (tCell::season)
        {
            case seasonID::EARLY_SPRING : { proceed =  5; } break;
            case seasonID::SPRING       : { proceed = 15; } break;
            case seasonID::LATE_SPRING  : { proceed = 25; } break;
            case seasonID::EARLY_SUMMER : { proceed = 30; } break;
            case seasonID::SUMMER       : { proceed = 25; } break;
            case seasonID::LATE_SUMMER  : { proceed = 20; } break;
            case seasonID::EARLY_AUTUMN : { proceed = 15; } break;
            case seasonID::AUTUMN       : { proceed = 10; } break;
            case seasonID::LATE_AUTUMN  : { proceed =  5; } break;
        }
        if (rand()%250 < proceed)
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

    void Branch(int _x, int _y, int index)
    {
        int dM = int( (_y+32) * tCell::width + (_x  ) );
        int dT = int( (_y+64) * tCell::width + (_x  ) );
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int top = tCell::matrix[dT];
        int mid = tCell::matrix[dM];
        int left = tCell::matrix[dW-6];
        int farleft = tCell::matrix[dW-8];
        int shortleft = tCell::matrix[dW-4];
        int right = tCell::matrix[dE+6];
        int farright = tCell::matrix[dE+8];
        int shortright = tCell::matrix[dE+4];
        int direction = rand()%100;
        int proceed = 0;
        switch (tCell::season)
        {
            case seasonID::EARLY_SPRING : { proceed =  5; } break;
            case seasonID::SPRING       : { proceed = 15; } break;
            case seasonID::LATE_SPRING  : { proceed = 25; } break;
            case seasonID::EARLY_SUMMER : { proceed = 30; } break;
            case seasonID::SUMMER       : { proceed = 25; } break;
            case seasonID::LATE_SUMMER  : { proceed = 20; } break;
            case seasonID::EARLY_AUTUMN : { proceed = 15; } break;
            case seasonID::AUTUMN       : { proceed = 10; } break;
            case seasonID::LATE_AUTUMN  : { proceed =  5; } break;
        }
        if (rand()%500 < proceed)
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
            }
            // Extend Branch
            if (top != tTile::AIR)
            {
                if (farleft != tTile::TRUNK)
                {
                    int c1 = tCell::matrix[dW];
                    int c2 = tCell::matrix[dW+1];

                    if ((c1 == tTile::BRANCH || c1 == tTile::LEAVES) &&
                        (c2 == tTile::BRANCH || c2 == tTile::LEAVES))
                    {
                        if (tCell::matrix[dN] == tTile::AIR)// && tCell::matrix[dN+1] == tTile::AIR)
                        { if (tCell::matrix[dE] == tTile::AIR) tCell::replace[dE] = tTile::BRANCH; }
                    }
                }
                if (farright != tTile::TRUNK)
                {
                    int c1 = tCell::matrix[dE];
                    int c2 = tCell::matrix[dE-1];

                    if ((c1 == tTile::BRANCH || c1 == tTile::LEAVES) &&
                        (c2 == tTile::BRANCH || c2 == tTile::LEAVES))
                    {
                        if (tCell::matrix[dN] == tTile::AIR && tCell::matrix[dN-1] == tTile::AIR)
                        { if (tCell::matrix[dW] == tTile::AIR) tCell::replace[dW] = tTile::BRANCH; }
                    }
                }
            }
            else if (mid != tTile::AIR && top == tTile::AIR)
            {
                if (shortleft != tTile::TRUNK)
                {
                    int c1 = tCell::matrix[dW];
                    int c2 = tCell::matrix[dW+1];

                    if ((c1 == tTile::BRANCH || c1 == tTile::LEAVES) &&
                        (c2 == tTile::BRANCH || c2 == tTile::LEAVES))
                    {
                        if (tCell::matrix[dN] == tTile::AIR)// && tCell::matrix[dN+1] == tTile::AIR)
                        { if (tCell::matrix[dE] == tTile::AIR) tCell::replace[dE] = tTile::BRANCH; }
                    }
                }
                if (shortright != tTile::TRUNK)
                {
                    int c1 = tCell::matrix[dE];
                    int c2 = tCell::matrix[dE-1];

                    if ((c1 == tTile::BRANCH || c1 == tTile::LEAVES) &&
                        (c2 == tTile::BRANCH || c2 == tTile::LEAVES))
                    {
                        if (tCell::matrix[dN] == tTile::AIR && tCell::matrix[dN-1] == tTile::AIR)
                        { if (tCell::matrix[dW] == tTile::AIR) tCell::replace[dW] = tTile::BRANCH; }
                    }
                }
            }
        }
    }

    void Trunk(int _x, int _y, int index)
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
        int proceed = 0;
        switch (tCell::season)
        {
            case seasonID::EARLY_SPRING : { proceed =  5; } break;
            case seasonID::SPRING       : { proceed = 15; } break;
            case seasonID::LATE_SPRING  : { proceed = 25; } break;
            case seasonID::EARLY_SUMMER : { proceed = 30; } break;
            case seasonID::SUMMER       : { proceed = 25; } break;
            case seasonID::LATE_SUMMER  : { proceed = 20; } break;
            case seasonID::EARLY_AUTUMN : { proceed = 15; } break;
            case seasonID::AUTUMN       : { proceed = 10; } break;
            case seasonID::LATE_AUTUMN  : { proceed =  5; } break;
        }
        if (rand()%1000 < proceed)
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

    void Taproot(int _x, int _y, int index)
    {
        int dT =  int( (_y-24) * tCell::width + (_x  ) );
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        //if (rand()%1000 < 25 && tCell::matrix[dT] != tTile::TRUNK) { tCell::replace[index] = tTile::MUD; }
        int proceed = 0;
        switch (tCell::season)
        {
            case seasonID::EARLY_SPRING : { proceed =  5; } break;
            case seasonID::SPRING       : { proceed = 15; } break;
            case seasonID::LATE_SPRING  : { proceed = 25; } break;
            case seasonID::EARLY_SUMMER : { proceed = 30; } break;
            case seasonID::SUMMER       : { proceed = 25; } break;
            case seasonID::LATE_SUMMER  : { proceed = 20; } break;
            case seasonID::EARLY_AUTUMN : { proceed = 15; } break;
            case seasonID::AUTUMN       : { proceed = 10; } break;
            case seasonID::LATE_AUTUMN  : { proceed =  5; } break;
        }
        if ((tCell::matrix[dT] == tTile::TRUNK || tCell::matrix[dT] == tTile::BRANCH) && rand()%10000 < proceed)
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

    void Root(int _x, int _y, int index)
    {
        int dT =  int( (_y-12) * tCell::width + (_x  ) );
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int proceed = 0;
        switch (tCell::season)
        {
            case seasonID::EARLY_SPRING : { proceed =  5; } break;
            case seasonID::SPRING       : { proceed = 15; } break;
            case seasonID::LATE_SPRING  : { proceed = 25; } break;
            case seasonID::EARLY_SUMMER : { proceed = 30; } break;
            case seasonID::SUMMER       : { proceed = 25; } break;
            case seasonID::LATE_SUMMER  : { proceed = 20; } break;
            case seasonID::EARLY_AUTUMN : { proceed = 15; } break;
            case seasonID::AUTUMN       : { proceed = 10; } break;
            case seasonID::LATE_AUTUMN  : { proceed =  5; } break;
        }
        if (rand()%1000 < 25 && tCell::matrix[dN] != tTile::TAPROOT) { tCell::replace[index] = tTile::SOIL; }
        if ((tCell::matrix[dT] == tTile::AIR || tCell::matrix[dT] == tTile::TAPROOT) && rand()%10000 < proceed)
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

    void Update(int _x, int _y, int index, int current_cell)
    {
        switch (current_cell)
        {
            case tTile::GRASS : { Grass(_x, _y, index); } break;
            case tTile::MOSS : { Moss(_x, _y, index); } break;
            case tTile::ROOT : { Root(_x, _y, index); } break;
            case tTile::TAPROOT : { Taproot(_x, _y, index); } break;
            case tTile::TRUNK : { Trunk(_x, _y, index); } break;
            case tTile::BRANCH : { Branch(_x, _y, index); } break;
            case tTile::STICK : { Stick(_x, _y, index); } break;
            case tTile::LEAVES : { Leaves(_x, _y, index); } break;
            case tTile::OLD_LEAVES : { Leaves(_x, _y, index); } break;
            case tTile::DRY_LEAVES : { Leaves(_x, _y, index); } break;
            case tTile::DEAD_LEAVES : { DeadLeaves(_x, _y, index); } break;
        }
    }

}
