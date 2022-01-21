namespace tGas

{

    //
    // Special
    //

    void Steam(int _x, int _y, int index)
    {
        int dN  = int( (_y-1) * tCell::width + (_x  ) );
        int dS  = int( (_y+1) * tCell::width + (_x  ) );

        if (tTile::TYPE[tCell::matrix[dN]] == tTile::SOLID && tCell::matrix[dS] == tTile::STEAM)
        { if (rand()%1000 < 10) tCell::replace[index] = tTile::WATER; }
    }

    void ThinSmoke(int _x, int _y, int index)
    {
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int chance = rand()%100;
        if (chance < 20) { tCell::replace[index] = tTile::AIR; }
        else if (chance < 40) { if (tCell::matrix[dE] == tTile::AIR) tTool::Swap(index, dE); }
        else if (chance > 60) { if (tCell::matrix[dW] == tTile::AIR) tTool::Swap(index, dW); }
        else if (chance > 80) { tCell::replace[index] = tTile::AIR; }
    }

    void Smoke(int _x, int _y, int index)
    {
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int chance = rand()%100;
        if (chance < 20) { tCell::replace[index] = tTile::THIN_SMOKE; }
        else if (chance < 40) { if (tCell::matrix[dE] == tTile::AIR) tTool::Swap(index, dE); }
        else if (chance > 60) { if (tCell::matrix[dW] == tTile::AIR) tTool::Swap(index, dW); }
        else if (chance > 80) { tCell::replace[index] = tTile::THIN_SMOKE; }
    }

    void ThickSmoke(int _x, int _y, int index)
    {
        int dE  = int( (_y  ) * tCell::width + (_x+1) );
        int dW  = int( (_y  ) * tCell::width + (_x-1) );
        int chance = rand()%100;
        if (chance < 20) { tCell::replace[index] = tTile::SMOKE; }
        else if (chance < 40) { if (tCell::matrix[dE] == tTile::AIR) tTool::Swap(index, dE); }
        else if (chance > 60) { if (tCell::matrix[dW] == tTile::AIR) tTool::Swap(index, dW); }
        else if (chance > 80) { tCell::replace[index] = tTile::SMOKE; }
    }

    void MildlyCompressedAir(int _x, int _y, int index)
    {
        int dN1 = int( (_y-1) * tCell::width + (_x) ), dN2 = int( (_y-2) * tCell::width + (_x) );
        int dS1 = int( (_y+1) * tCell::width + (_x) ), dS2 = int( (_y+2) * tCell::width + (_x) );
        int dE1 = int( (_y) * tCell::width + (_x+1) ), dE2 = int( (_y) * tCell::width + (_x+2) );
        int dW1 = int( (_y) * tCell::width + (_x-1) ), dW2 = int( (_y) * tCell::width + (_x-2) );
        uint8_t vN = tCell::matrix[dN1], vS = tCell::matrix[dS1], vE = tCell::matrix[dE1], vW = tCell::matrix[dW1];
        if      ((tTool::GetType(vN) == tTile::GAS || tTool::GetType(vN) == tTile::GRAIN) &&
                (tCell::matrix[dN1] > tTile::AIR && tCell::matrix[dN2] == tTile::AIR))
        { tCell::replace[dN2] = vN;  tCell::replace[dN1] = tTile::AIR; tCell::replace[index] = tTile::AIR; }
        else if (tTool::GetType(vS) == tTile::GAS && tCell::matrix[dS1] > tTile::AIR && tCell::matrix[dS2] == tTile::AIR)
        { tCell::replace[dS2] = vS;  tCell::replace[dS1] = tTile::AIR; tCell::replace[index] = tTile::AIR; }
        else if (tTool::GetType(vE) == tTile::GAS && tCell::matrix[dE1] > tTile::AIR && tCell::matrix[dE2] == tTile::AIR)
        { tCell::replace[dE2] = vE;  tCell::replace[dE1] = tTile::AIR; tCell::replace[index] = tTile::AIR; }
        else if (tTool::GetType(vW) == tTile::GAS && tCell::matrix[dW1] > tTile::AIR && tCell::matrix[dW2] == tTile::AIR)
        { tCell::replace[dW2] = vW;  tCell::replace[dW1] = tTile::AIR; tCell::replace[index] = tTile::AIR; }
        if (tCell::matrix[dN1] == tTile::AIR || tCell::matrix[dS1] == tTile::AIR || tCell::matrix[dE1] == tTile::AIR || tCell::matrix[dW1] == tTile::AIR)
        { if (rand()%1000 < 5) tCell::replace[index] = tTile::AIR; }
        /*
        uint8_t N = uint8_t(tCell::matrix[dN1] != tTile::AIR) + uint8_t(tCell::matrix[dN2] != tTile::AIR);
        uint8_t S = uint8_t(tCell::matrix[dS1] != tTile::AIR) + uint8_t(tCell::matrix[dS2] != tTile::AIR);
        uint8_t E = uint8_t(tCell::matrix[dE1] != tTile::AIR) + uint8_t(tCell::matrix[dE2] != tTile::AIR);
        uint8_t W = uint8_t(tCell::matrix[dW1] != tTile::AIR) + uint8_t(tCell::matrix[dW2] != tTile::AIR);
        if      (tCell::matrix[dN1] >= tTile::AIR && tCell::matrix[dN2] == tTile::AIR)
        {
            if (S >= 0)
            { uint8_t v=tCell::matrix[dN1]; tCell::replace[dN2]=v; tCell::replace[dN1]=tTile::AIR;
            tCell::matrix[index]=tTile::AIR; tCell::replace[index]=tTile::AIR; }
        }
        else if (tCell::matrix[dS1] >= tTile::AIR && tCell::matrix[dS2] == tTile::AIR)
        {
            if (N >= 0)
            { uint8_t v=tCell::matrix[dS1]; tCell::replace[dS2]=v; tCell::replace[dS1]=tTile::AIR;
            tCell::matrix[index]=tTile::AIR; tCell::replace[index]=tTile::AIR; }
        }
        else if (tCell::matrix[dE1] >= tTile::AIR && tCell::matrix[dE2] == tTile::AIR)
        {
            if (W >= 0)
            { uint8_t v=tCell::matrix[dE1]; tCell::replace[dE2]=v; tCell::replace[dE1]=tTile::AIR;
            tCell::matrix[index]=tTile::AIR; tCell::replace[index]=tTile::AIR; }
        }
        else if (tCell::matrix[dW1] >= tTile::AIR && tCell::matrix[dW2] == tTile::AIR)
        {
            if (E >= 0)
            { uint8_t v=tCell::matrix[dW1]; tCell::replace[dW2]=v; tCell::replace[dW1]=tTile::AIR;
            tCell::matrix[index]=tTile::AIR; tCell::replace[index]=tTile::AIR; }
        }
        if (tCell::matrix[dN1] == tTile::AIR && tCell::matrix[dS1] == tTile::AIR && tCell::matrix[dE1] == tTile::AIR && tCell::matrix[dW1] == tTile::AIR)
        { tCell::matrix[index]=tTile::AIR; tCell::replace[index]=tTile::AIR; }
        */
    }

    void CompressedAir(int _x, int _y, int index)
    {
        int dN1 = int( (_y-1) * tCell::width + (_x) ), dN2 = int( (_y-2) * tCell::width + (_x) );
        int dS1 = int( (_y+1) * tCell::width + (_x) ), dS2 = int( (_y+2) * tCell::width + (_x) );
        int dE1 = int( (_y) * tCell::width + (_x+1) ), dE2 = int( (_y) * tCell::width + (_x+2) );
        int dW1 = int( (_y) * tCell::width + (_x-1) ), dW2 = int( (_y) * tCell::width + (_x-2) );
        uint8_t vN = tCell::matrix[dN1], vS = tCell::matrix[dS1], vE = tCell::matrix[dE1], vW = tCell::matrix[dW1];
        if (tCell::matrix[dN1] > tTile::AIR && tCell::matrix[dN2] == tTile::AIR)
        { tCell::replace[dN2] = vN;  tCell::replace[dN1] = tTile::MILDLY_COMPRESSED_AIR; tCell::replace[index] = tTile::MILDLY_COMPRESSED_AIR; }
        else if (tCell::matrix[dS1] > tTile::AIR && tCell::matrix[dS2] == tTile::AIR)
        { tCell::replace[dS2] = vS;  tCell::replace[dS1] = tTile::MILDLY_COMPRESSED_AIR; tCell::replace[index] = tTile::MILDLY_COMPRESSED_AIR; }
        else if (tCell::matrix[dE1] > tTile::AIR && tCell::matrix[dE2] == tTile::AIR)
        { tCell::replace[dE2] = vE;  tCell::replace[dE1] = tTile::MILDLY_COMPRESSED_AIR; tCell::replace[index] = tTile::MILDLY_COMPRESSED_AIR; }
        else if (tCell::matrix[dW1] > tTile::AIR && tCell::matrix[dW2] == tTile::AIR)
        { tCell::replace[dW2] = vW;  tCell::replace[dW1] = tTile::MILDLY_COMPRESSED_AIR; tCell::replace[index] = tTile::MILDLY_COMPRESSED_AIR; }
        //if (rand()%1000 < 5) { tCell::replace[index] = tTile::MILDLY_COMPRESSED_AIR; }
        /*
        uint8_t N = uint8_t(tCell::matrix[dN1] != tTile::AIR) + uint8_t(tCell::matrix[dN2] != tTile::AIR);
        uint8_t S = uint8_t(tCell::matrix[dS1] != tTile::AIR) + uint8_t(tCell::matrix[dS2] != tTile::AIR);
        uint8_t E = uint8_t(tCell::matrix[dE1] != tTile::AIR) + uint8_t(tCell::matrix[dE2] != tTile::AIR);
        uint8_t W = uint8_t(tCell::matrix[dW1] != tTile::AIR) + uint8_t(tCell::matrix[dW2] != tTile::AIR);
        if      (tCell::matrix[dN1] > tTile::MILDLY_COMPRESSED_AIR && tCell::matrix[dN2] == tTile::AIR)
        {
            if (S >= 0)
            { uint8_t v=tCell::matrix[dN1]; tCell::replace[dN2]=v; tCell::replace[dN1]=tTile::MILDLY_COMPRESSED_AIR;
            tCell::matrix[index]=tTile::MILDLY_COMPRESSED_AIR; tCell::replace[index]=tTile::MILDLY_COMPRESSED_AIR; }
        }
        else if (tCell::matrix[dS1] > tTile::MILDLY_COMPRESSED_AIR && tCell::matrix[dS2] == tTile::AIR)
        {
            if (N >= 0)
            { uint8_t v=tCell::matrix[dS1]; tCell::replace[dS2]=v; tCell::replace[dS1]=tTile::MILDLY_COMPRESSED_AIR;
            tCell::matrix[index]=tTile::MILDLY_COMPRESSED_AIR; tCell::replace[index]=tTile::MILDLY_COMPRESSED_AIR; }
        }
        else if (tCell::matrix[dE1] > tTile::MILDLY_COMPRESSED_AIR && tCell::matrix[dE2] == tTile::AIR)
        {
            if (W >= 0)
            { uint8_t v=tCell::matrix[dE1]; tCell::replace[dE2]=v; tCell::replace[dE1]=tTile::MILDLY_COMPRESSED_AIR;
            tCell::matrix[index]=tTile::MILDLY_COMPRESSED_AIR; tCell::replace[index]=tTile::MILDLY_COMPRESSED_AIR; }
        }
        else if (tCell::matrix[dW1] > tTile::MILDLY_COMPRESSED_AIR && tCell::matrix[dW2] == tTile::AIR)
        {
            if (E >= 0)
            { uint8_t v=tCell::matrix[dW1]; tCell::replace[dW2]=v; tCell::replace[dW1]=tTile::MILDLY_COMPRESSED_AIR;
            tCell::matrix[index]=tTile::MILDLY_COMPRESSED_AIR; tCell::replace[index]=tTile::MILDLY_COMPRESSED_AIR; }
        }
        if (tCell::matrix[dN1] == tTile::AIR && tCell::matrix[dS1] == tTile::AIR && tCell::matrix[dE1] == tTile::AIR && tCell::matrix[dW1] == tTile::AIR)
        { tCell::matrix[index]=tTile::MILDLY_COMPRESSED_AIR; tCell::replace[index]=tTile::MILDLY_COMPRESSED_AIR; }
        */
    }

    void HighlyCompressedAir(int _x, int _y, int index)
    {
        int dN1 = int( (_y-1) * tCell::width + (_x) ), dN2 = int( (_y-2) * tCell::width + (_x) ), dN3 = int( (_y-3) * tCell::width + (_x) );
        int dS1 = int( (_y+1) * tCell::width + (_x) ), dS2 = int( (_y+2) * tCell::width + (_x) ), dS3 = int( (_y+3) * tCell::width + (_x) );
        int dE1 = int( (_y) * tCell::width + (_x+1) ), dE2 = int( (_y) * tCell::width + (_x+2) ), dE3 = int( (_y) * tCell::width + (_x+3) );
        int dW1 = int( (_y) * tCell::width + (_x-1) ), dW2 = int( (_y) * tCell::width + (_x-2) ), dW3 = int( (_y) * tCell::width + (_x-3) );
        uint8_t vN = tCell::matrix[dN1], vS = tCell::matrix[dS1], vE = tCell::matrix[dE1], vW = tCell::matrix[dW1];
        if (tCell::matrix[dN1] > tTile::AIR && tCell::matrix[dN2] == tTile::AIR)
        { tCell::replace[dN2] = vN;  tCell::replace[dN1] = tTile::COMPRESSED_AIR; tCell::replace[index] = tTile::COMPRESSED_AIR; }
        else if (tCell::matrix[dS1] > tTile::AIR && tCell::matrix[dS2] == tTile::AIR)
        { tCell::replace[dS2] = vS;  tCell::replace[dS1] = tTile::COMPRESSED_AIR; tCell::replace[index] = tTile::COMPRESSED_AIR; }
        else if (tCell::matrix[dE1] > tTile::AIR && tCell::matrix[dE2] == tTile::AIR)
        { tCell::replace[dE2] = vE;  tCell::replace[dE1] = tTile::COMPRESSED_AIR; tCell::replace[index] = tTile::COMPRESSED_AIR; }
        else if (tCell::matrix[dW1] > tTile::AIR && tCell::matrix[dW2] == tTile::AIR)
        { tCell::replace[dW2] = vW;  tCell::replace[dW1] = tTile::COMPRESSED_AIR; tCell::replace[index] = tTile::COMPRESSED_AIR; }
        //if (rand()%1000 < 1) { tCell::replace[index] = tTile::COMPRESSED_AIR; }
        /*
        uint8_t N = uint8_t(tCell::matrix[dN1] != tTile::AIR) + uint8_t(tCell::matrix[dN2] != tTile::AIR) + uint8_t(tCell::matrix[dN3] != tTile::AIR);
        uint8_t S = uint8_t(tCell::matrix[dS1] != tTile::AIR) + uint8_t(tCell::matrix[dS2] != tTile::AIR) + uint8_t(tCell::matrix[dS3] != tTile::AIR);
        uint8_t E = uint8_t(tCell::matrix[dE1] != tTile::AIR) + uint8_t(tCell::matrix[dE2] != tTile::AIR) + uint8_t(tCell::matrix[dE3] != tTile::AIR);
        uint8_t W = uint8_t(tCell::matrix[dW1] != tTile::AIR) + uint8_t(tCell::matrix[dW2] != tTile::AIR) + uint8_t(tCell::matrix[dW3] != tTile::AIR);
        if      (tCell::matrix[dN1] >= tTile::COMPRESSED_AIR && tCell::matrix[dN2] == tTile::AIR)
        {
            if (S >= 0)
            { uint8_t v=tCell::matrix[dN1]; tCell::replace[dN2]=v; tCell::replace[dN1]=tTile::COMPRESSED_AIR;
            tCell::matrix[index]=tTile::COMPRESSED_AIR; tCell::replace[index]=tTile::COMPRESSED_AIR; }
        }
        else if (tCell::matrix[dS1] >= tTile::COMPRESSED_AIR && tCell::matrix[dS2] == tTile::AIR)
        {
            if (N >= 0)
            { uint8_t v=tCell::matrix[dS1]; tCell::replace[dS2]=v; tCell::replace[dS1]=tTile::COMPRESSED_AIR;
            tCell::matrix[index]=tTile::COMPRESSED_AIR; tCell::replace[index]=tTile::COMPRESSED_AIR; }
        }
        else if (tCell::matrix[dE1] >= tTile::COMPRESSED_AIR && tCell::matrix[dE2] == tTile::AIR)
        {
            if (W >= 0)
            { uint8_t v=tCell::matrix[dE1]; tCell::replace[dE2]=v; tCell::replace[dE1]=tTile::COMPRESSED_AIR;
            tCell::matrix[index]=tTile::COMPRESSED_AIR; tCell::replace[index]=tTile::COMPRESSED_AIR; }
        }
        else if (tCell::matrix[dW1] >= tTile::COMPRESSED_AIR && tCell::matrix[dW2] == tTile::AIR)
        {
            if (E > 0)
            { uint8_t v=tCell::matrix[dW1]; tCell::replace[dW2]=v; tCell::replace[dW1]=tTile::COMPRESSED_AIR;
            tCell::matrix[index]=tTile::COMPRESSED_AIR; tCell::replace[index]=tTile::COMPRESSED_AIR; }
        }
        if (tCell::matrix[dN1] == tTile::AIR || tCell::matrix[dS1] == tTile::AIR || tCell::matrix[dE1] == tTile::AIR || tCell::matrix[dW1] == tTile::AIR)
        { tCell::matrix[index]=tTile::COMPRESSED_AIR; tCell::replace[index]=tTile::COMPRESSED_AIR; }
        */
    }



    //
    // Generic
    //
    
    void Update(int _x, int _y, int index, int current_cell)
    {
        if      (current_cell == tTile::MILDLY_COMPRESSED_AIR) { MildlyCompressedAir(_x, _y, index); return; }
        else if (current_cell == tTile::COMPRESSED_AIR)        {       CompressedAir(_x, _y, index); return; }
        else if (current_cell == tTile::HIGHLY_COMPRESSED_AIR) { HighlyCompressedAir(_x, _y, index); return; }
        int direction = rand() % 100;
        if (direction < 50)
        {
            if (!tTool::GasCollision(_x, _y-1))
            { int rplc = (_y-1)*tCell::width+(_x); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x-1, _y-1))
            { int rplc = (_y-1)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x+1, _y-1))
            { int rplc = (_y-1)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x-1, _y) && tTool::GasCollision(_x+1, _y))
            { int rplc = (_y)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x+1, _y) && tTool::GasCollision(_x-1, _y))
            { int rplc = (_y)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
        }
        else
        {
            if (!tTool::GasCollision(_x, _y-1))
            { int rplc = (_y-1)*tCell::width+(_x); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x+1, _y-1))
            { int rplc = (_y-1)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x-1, _y-1))
            { int rplc = (_y-1)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x+1, _y) && tTool::GasCollision(_x-1, _y))
            { int rplc = (_y)*tCell::width+(_x+1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
            else if (!tTool::GasCollision(_x-1, _y) && tTool::GasCollision(_x+1, _y))
            { int rplc = (_y)*tCell::width+(_x-1); if (tCell::matrix[index] != tCell::matrix[rplc]){ tTool::SoftSwap(index, rplc); } }
        }

        switch (current_cell)
            {
                case tTile::STEAM          : {         Steam(_x, _y, index); } break;
                case tTile::THIN_SMOKE     : {     ThinSmoke(_x, _y, index); } break;
                case tTile::SMOKE          : {         Smoke(_x, _y, index); } break;
                case tTile::THICK_SMOKE    : {    ThickSmoke(_x, _y, index); } break;
                //case tTile::COMPRESSED_AIR : { CompressedAir(_x, _y, index); } break;
            }
    }

}
