namespace tEgg
{

    //
    // Special
    //

    void FrogEgg(int _x, int _y, int index, char season)
    {
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::FROG_EGG; }
        if (season > seasonID::EARLY_SPRING && season < seasonID::LATE_SUMMER)
        { if (rand()%10000 < 5) { tCell::replace[index] = tTile::FROG; } }
    }
    void ToadEgg(int _x, int _y, int index, char season)
    {
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::TOAD_EGG; }
        if (season > seasonID::LATE_SPRING && season < seasonID::EARLY_AUTUMN)
        { if (rand()%10000 < 5) { tCell::replace[index] = tTile::TOAD; } }
    }
    void FishEgg(int _x, int _y, int index, char season)
    {
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::FISH_EGG; }
        if (tCell::matrix[dS] == tTile::WATER) { tCell::replace[index] = tTile::WATER; tCell::replace[dS] = tTile::FISH_EGG; }
        if (tCell::matrix[dS] == tTile::FISH_TAIL) { tCell::replace[index] = tTile::FISH_TAIL; tCell::replace[dS] = tTile::FISH_EGG; }
        if (tCell::matrix[dS] == tTile::FISH) { tCell::replace[index] = tTile::FISH; tCell::replace[dS] = tTile::FISH_EGG; }
        if (season > seasonID::EARLY_SPRING && season < seasonID::LATE_SUMMER)
        { if (rand()%10000 < 5)
            { if (tCell::matrix[dE] == tTile::WATER) { tCell::replace[index] = tTile::FISH; tCell::replace[dE] = tTile::FISH_TAIL; }
                else if (tCell::matrix[dW] == tTile::WATER) { tCell::replace[index] = tTile::FISH; tCell::replace[dW] = tTile::FISH_TAIL; } } }
    }
    void BirdEgg(int _x, int _y, int index, char season)
    {
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::BIRD_EGG; }
        if (season > seasonID::EARLY_SPRING && season < seasonID::LATE_SUMMER)
        { if (rand()%10000 < 5) { tCell::replace[index] = tTile::BIRD; } }
    }
    void SnakeEgg(int _x, int _y, int index, char season)
    {
        int dS  = int( (_y+1) * tCell::width + (_x  ) );
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        if (tCell::matrix[dS] == tTile::AIR) { tCell::replace[index] = tTile::AIR; tCell::replace[dS] = tTile::SNAKE_EGG; }
        if (season > seasonID::SPRING && season < seasonID::SUMMER)
        {if (rand()%10000 < 5 &&
            tCell::matrix[dE] == tTile::AIR && tCell::matrix[dW] == tTile::AIR)
        { tCell::replace[dE] = tTile::SNAKE_HEAD; tCell::replace[index] = tTile::SNAKE; tCell::replace[dW] = tTile::SNAKE_TAIL; } }
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
            case tTile::FISH_EGG  : {  FishEgg(_x, _y, index, season); } break;
            case tTile::SNAKE_EGG : { SnakeEgg(_x, _y, index, season); } break;
        }
    }

}
