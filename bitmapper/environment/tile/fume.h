namespace tFume
{
    
    //
    // Special
    //
    
    
    
    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell, char season=0)
    {
        int cell_type = tTool::GetType(current_cell);
        int direction = rand() % 100;

        if (direction < 50)
        {
            if (!tTool::Collision(_x, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░██░░
            }
            else if (!tTool::Collision(_x-1, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x-1);          // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ██░░░░
            }
            else if (!tTool::Collision(_x+1, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x+1);          // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░██
            }
            else if (!tTool::Collision(_x-2, _y) && !tTool::Collision(_x-1, _y))
            {
                int rplc = (_y)*tCell::width+(_x-2);            // ░░░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ██░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░░░
            }
            else if (!tTool::Collision(_x+2, _y) && !tTool::Collision(_x+1, _y))
            {
                int rplc = (_y)*tCell::width+(_x+2);            // ░░░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░██
                tCell::replace[index] = tTile::AIR;             // ░░░░░░░░
            }
            else if (!tTool::Collision(_x-1, _y) && tTool::Collision(_x+1, _y))
            {
                int rplc = (_y)*tCell::width+(_x-1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ██▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
            else if (!tTool::Collision(_x+1, _y) && tTool::Collision(_x-1, _y))
            {
                int rplc = (_y)*tCell::width+(_x+1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓██
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
        }
        else
        {
            if (!tTool::Collision(_x, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░██░░
            }
            else if (!tTool::Collision(_x+1, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x+1);          // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░██
            }
            else if (!tTool::Collision(_x-1, _y+1))
            {
                int rplc = (_y+1)*tCell::width+(_x-1);          // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ██░░░░
            }
            else if (!tTool::Collision(_x+2, _y) && !tTool::Collision(_x+1, _y))
            {
                int rplc = (_y)*tCell::width+(_x+2);            // ░░░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓░░██
                tCell::replace[index] = tTile::AIR;             // ░░░░░░░░
            }
            else if (!tTool::Collision(_x-2, _y) && !tTool::Collision(_x-1, _y))
            {
                int rplc = (_y)*tCell::width+(_x-2);            // ░░░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ██░░▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░░░
            }
            else if (!tTool::Collision(_x+1, _y) && tTool::Collision(_x-1, _y))
            {
                int rplc = (_y)*tCell::width+(_x+1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ░░▓▓██
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
            else if (!tTool::Collision(_x-1, _y) && tTool::Collision(_x+1, _y))
            {
                int rplc = (_y)*tCell::width+(_x-1);            // ░░░░░░
                tCell::replace[rplc] = tCell::matrix[index];    // ██▓▓░░
                tCell::replace[index] = tTile::AIR;             // ░░░░░░
            }
        }
    }

}
