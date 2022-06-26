class World
{
public:

    // Class Attributes //
    std::string name;
    std::string data;
    // World Dimensions
    int chunk_size = 32;

    // Update Method
    void SettleTiles(int X, int Y, int W, int H)
    {
        tCell::replace = tCell::matrix;

        if (Y < 2) { Y = 1; }
        if (Y > tCell::height-H-2) { H = tCell::height-Y; }

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
                        case tTile::SOLID         : {        tSolid::Update(_x, _y, index, current_cell); } break;
                        case tTile::METAL         : {        tMetal::Update(_x, _y, index, current_cell); } break;
                        case tTile::LOOSE         : {        tLoose::Update(_x, _y, index, current_cell); } break;
                        case tTile::GRAIN         : {        tGrain::Update(_x, _y, index, current_cell); } break;
                        case tTile::FLUID         : {        tFluid::Update(_x, _y, index, current_cell); } break;
                        case tTile::GEL           : {          tGel::Update(_x, _y, index, current_cell); } break;
                        case tTile::GEM           : {          tGem::Update(_x, _y, index, current_cell); } break;
                        case tTile::GEO           : {          tGeo::Update(_x, _y, index, current_cell); } break;
                        case tTile::EGG           : {          tEgg::Update(_x, _y, index, current_cell); } break;
                        case tTile::PLASMA        : {       tPlasma::Update(_x, _y, index, current_cell); } break;
                        case tTile::GAS           : {          tGas::Update(_x, _y, index, current_cell); } break;
                        case tTile::FUME          : {         tFume::Update(_x, _y, index, current_cell); } break;
                        case tTile::PLANT         : {        tPlant::Update(_x, _y, index, current_cell); } break;
                        case tTile::PLANT_PRODUCT : { tPlantProduct::Update(_x, _y, index, current_cell); } break;
                        case tTile::CRITTER       : {      tCritter::Update(_x, _y, index, current_cell); } break;
                        case tTile::BOOM          : {         tBoom::Update(_x, _y, index, current_cell); } break;
                        case tTile::LOGIC         : {        tLogic::Update(_x, _y, index, current_cell); } break;
                        case tTile::GIZMO         : {        tGizmo::Update(_x, _y, index, current_cell); } break;
                        case tTile::PLUMBING      : {     tPlumbing::Update(_x, _y, index, current_cell); } break;
                    }
                }
            }
        }
        tCell::matrix = tCell::replace;
    }

    void SaveData1(std::string data_dir = "")
    {
        int X = tCell::width/chunk_size; int Y = tCell::height/chunk_size;
        for (int x = 0; x < X; x++) { for (int y = 0; y < Y; y++) { SaveChunkData(x, y, data_dir); } }
    }

    void LoadData1(std::string data_dir = "")
    {
        int X = tCell::width/chunk_size; int Y = tCell::height/chunk_size;
        for (int x = 0; x < X; x++) { for (int y = 0; y < Y; y++) { std::cout << "Loading Chunk " << x << "," << y << std::endl; LoadChunkData(x, y, data_dir); } }
    }

    void SaveChunkData(int X, int Y, std::string data_dir = "")
    {
        std::fstream data_file;
        data_dir = std::to_string(X) + "-" + std::to_string(Y);
        std::string _dir = os::GetCWD() + dataTool::path_world + data_dir;
        data_file.open(_dir);

        int x_ = X*chunk_size;
        int y_ = Y*chunk_size;

        if (data_file.is_open())
        {
            for (int y = 0; y < chunk_size; y++)
            {
                for (int x = 0; x < chunk_size; x++)
                {
                    int index = (y_+y)*tCell::width+(x_+x);
                    int tile = tCell::matrix[index];
                    data_file << tile << ",";
                }
                data_file << std::endl;
            }
            data_file.close();
        }
        else
        {
            std::ofstream new_file (_dir);
            SaveChunkData(X, Y, data_dir);
        }
    }

    void LoadChunkData(int X, int Y, std::string data_dir = "")
    {
        std::string line;
        data_dir = std::to_string(X) + "-" + std::to_string(Y);
        std::fstream data_file;
        std::string _dir = os::GetCWD() + dataTool::path_world + data_dir;
        data_file.open(_dir);

        int x = 0;
        int y = 0;
        int x_ = X*chunk_size;
        int y_ = Y*chunk_size;

        if (data_file.is_open())
        {
            std::string v = "";
            while (getline(data_file, line))
            {
                for (int i = 0; i < line.length(); i++)
                {
                    std::string c = line.substr(i, 1);
                    if ( c == "1" || c == "2" || c == "3" || c == "4" || c == "5" || c == "6" || c == "7" || c == "8" || c == "9" || c == "0" ) { v = v + c; }
                    if (c == ",")
                    {
                        int value = std::stoi(v);
                        int index = (y_+y)*tCell::width+(x_+x);
                        tCell::matrix[index] = value;
                        x++;
                        v = "";
                    }
                }
                y++; if (y >= chunk_size) { break; }
                x = 0;
            }
            data_file.close();
        }
    }

    void SaveWorldData(std::string data_dir="0")
    {
        std::fstream data_file;
        std::string _dir = os::GetCWD() + dataTool::path_world + "/world.data";
        data_file.open(_dir, std::ios_base::out);
        if (data_file.is_open())
        {
            int packet_count = 0;
            int packet_limit = 1024;
            int current_tile = tCell::matrix[0];
            int tile_count = 0;
            for (int i = 0; i < tCell::width*tCell::height; i++)
            {
                if (current_tile != tCell::matrix[i])
                {
                    data_file << "[" + std::to_string(current_tile) + "," + std::to_string(tile_count) + "]";
                    current_tile = tCell::matrix[i]; tile_count = 0; packet_count++;
                }
                if (packet_count >= packet_limit) { packet_count -= packet_limit; data_file << "\n"; }
                tile_count++;
            }
            data_file << "[" + std::to_string(current_tile) + "," + std::to_string(tile_count) + "]";
            data_file << "\n";
            data_file.close();
        }
        else
        { std::ofstream new_file (_dir); SaveWorldData(data_dir); }
    }

    void LoadWorldData(std::string data_dir="0")
    {
        if (core::loading)
        {
            std::string line;
            std::fstream data_file;
            std::string _dir = os::GetCWD() + dataTool::path_world + "/world.data";
            data_file.open(_dir);
            int row_count = 0;

            if (data_file.is_open())
            {
                while (getline(data_file, line))
                {
                    if (row_count == core::map_row+1) { LoadLine(line); core::map_row++; std::cout << core::map_row << std::endl; break; }
                    row_count++;
                }
                data_file.close();
            }
        }
    }

    void LoadLine(std::string line)
    {
        bool state = false;
        std::string tile = "", iter = "";
        for (int l = 0; l < line.length(); l++)
        {
            std::string c = line.substr(l, 1);
            if (c == "[") { state = false; }
            if (textTool::IsNumber(c)) { if (!state) { tile=tile+c; } else if (state) { iter=iter+c; } }
            if (c == ",") { state = true; }
            if (c == "]")
            {
                uint8_t current_tile = std::stoi(tile);
                for (int i = 0; i < std::stoi(iter); i++) { tCell::matrix[core::map_index] = current_tile; core::map_index++; }
                tile = ""; iter = "";
            }
        }
    }

};
