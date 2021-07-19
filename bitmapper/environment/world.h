class World
{
public:

    // Class Attributes //

    // World Dimensions
    int chunk_size = 32;

    // Update Method
    void SettleTiles(int X, int Y, int W, int H)
    {
        tCell::replace = tCell::matrix;

        if (Y < 2)
        {
            Y = 1;
        }
        if (Y > tCell::height-H-2)
        {
            H = tCell::height-Y;
        }

        for (int y = H; y > 0; y--)
        {
            for (int x = 0; x < W; x++)
            {
                int _x = x+X;
                int _y = y+Y;
                if ( tTool::Collision(_x, _y) )
                {
                    int index = (_y)*tCell::width+(_x);
                    int current_cell = tCell::matrix[index];
                    int cell_type = tTool::GetType(current_cell);

                    switch (cell_type)
                    {
                        case tTile::SOLID    : {    tSolid::Update(_x, _y, index, current_cell); } break;
                        case tTile::LOOSE    : {    tLoose::Update(_x, _y, index, current_cell); } break;
                        case tTile::GRAIN    : {    tGrain::Update(_x, _y, index, current_cell); } break;
                        case tTile::FLUID    : {    tFluid::Update(_x, _y, index, current_cell); } break;
                        case tTile::GEL      : {      tGel::Update(_x, _y, index, current_cell); } break;
                        case tTile::PLASMA   : {   tPlasma::Update(_x, _y, index, current_cell); } break;
                        case tTile::GAS      : {      tGas::Update(_x, _y, index, current_cell); } break;
                        case tTile::FUME     : {     tFume::Update(_x, _y, index, current_cell); } break;
                        case tTile::PLANT    : {    tPlant::Update(_x, _y, index, current_cell); } break;
                        case tTile::CRITTER  : {  tCritter::Update(_x, _y, index, current_cell); } break;
                        case tTile::BOOM     : {     tBoom::Update(_x, _y, index, current_cell); } break;
                        case tTile::LOGIC    : {    tLogic::Update(_x, _y, index, current_cell); } break;
                        case tTile::GIZMO    : {    tGizmo::Update(_x, _y, index, current_cell); } break;
                        case tTile::PLUMBING : { tPlumbing::Update(_x, _y, index, current_cell); } break;
                    }
                }
            }
        }
        tCell::matrix = tCell::replace;
    }

};
