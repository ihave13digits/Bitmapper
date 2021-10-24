namespace tEgg
{

    //
    // Special
    //

    void FrogEgg(int _x, int _y, int index, char season)
    {
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::MOLE; }
        if (rand()%10000 < 5 && season == seasonID::SPRING) { tCell::replace[index] = tTile::FROG; } }

    void ToadEgg(int _x, int _y, int index, char season)
    {
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::MOLE; }
        if (rand()%10000 < 5 && season == seasonID::SPRING) { tCell::replace[index] = tTile::TOAD; } }

    void BirdEgg(int _x, int _y, int index, char season)
    {
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::MOLE; }
        if (rand()%10000 < 5 && season == seasonID::LATE_SPRING) { tCell::replace[index] = tTile::BIRD; } }

    void SnakeEgg(int _x, int _y, int index, char season)
    {
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::MOLE; }
        if (rand()%10000 < 5 && season == seasonID::LATE_SPRING &&
            tCell::matrix[dE] == tTile::AIR && tCell::matrix[dW] == tTile::AIR)
        {
            tCell::replace[dE] = tTile::SNAKE_HEAD;
            tCell::replace[index] = tTile::SNAKE;
            tCell::replace[dW] = tTile::SNAKE_TAIL;
        }
    }


    //
    // Generic
    //

    void Update(int _x, int _y, int index, int current_cell, char season=tCell::season)
    {
        switch (current_cell)
        {
            case tTile::FROG_EGG  : {  FrogEgg(_x, _y, index, season); } break;
            case tTile::TOAD_EGG  : {  ToadEgg(_x, _y, index, season); } break;
            case tTile::BIRD_EGG  : {  BirdEgg(_x, _y, index, season); } break;
            case tTile::SNAKE_EGG : { SnakeEgg(_x, _y, index, season); } break;
        }
    }

}
