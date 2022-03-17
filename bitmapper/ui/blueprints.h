class Blueprints
{

public:

    uint8_t size = 128;
    std::vector<uint8_t> matrix;
    std::vector<std::string> names;
    std::string selected = "";



    void InitializeMatrix() { for (int i = 0; i < size*size; i++) { matrix.push_back(0); } }
    void ClearMatrix() { for (int i = 0; i < size*size; i++) { matrix[i] = 0; } }
    bool UpdateNames(std::string n) { for (int i = 0; i < names.size(); i++) { if (names[i] == n) { return true;} } names.push_back(n); return false; }

    void FloodFill(uint8_t X, uint8_t Y, uint8_t t)
    {
        struct Pair { public: int x; int y;};
        std::vector<Pair> check;
        uint8_t r = matrix[Y*size+X];
        { Pair first = Pair(); first.x = X; first.y = Y; check.push_back(first); }
        if (r == t) return;
        while (check.size() > 0)
        {
            int x = check[0].x; int y = check[0].y; int current = matrix[y*size+x];
            if (current = t)
            {
                int dN =  ((y-1)*size+(x));   if (matrix[dN] == r && y > 0) { Pair v = Pair();   v.x=x; v.y=y-1; check.push_back(v); matrix[dN] = t; }
                int dS =  ((y+1)*size+(x));   if (matrix[dS] == r && y  < size-1) { Pair v = Pair();   v.x=x; v.y=y+1; check.push_back(v); matrix[dS] = t; }
                int dE =  ((y)*size+(x+1));   if (matrix[dE] == r && x < size-1) { Pair v = Pair(); v.x=x+1;   v.y=y; check.push_back(v); matrix[dE] = t; }
                int dW =  ((y)*size+(x-1));   if (matrix[dW] == r && x > 0) { Pair v = Pair(); v.x=x-1;   v.y=y; check.push_back(v); matrix[dW] = t; }
            }
            check.erase(check.begin());
        }
    }

    void SaveData(std::string data_dir="0")
    {
        struct Packet { int tile; int count; };
        std::vector<Packet> to_save;
        if (!UpdateNames(selected))
        {
            std::fstream data_file;
            std::string _dir = os::GetCWD() + dataTool::path_player + "/blueprints.data";
            data_file.open(_dir, std::ios_base::app);
            if (data_file.is_open())
            {
                Packet packet = Packet();
                int current_tile = matrix[0];
                int tile_count = 0;
                data_file << selected;
                for (int i = 0; i < size*size; i++)
                {
                    std::string packet_text = "[";
                    if (current_tile != matrix[i])
                    {
                        packet_text = packet_text + std::to_string(current_tile) + "," + std::to_string(tile_count) + "]";
                        data_file << packet_text;
                        current_tile = matrix[i]; tile_count = 0;
                    }
                    tile_count++;
                }
                data_file << "[" + std::to_string(current_tile) + "," + std::to_string(tile_count) + "]";
                data_file << "\n";
                data_file.close();
            }
            else
            { std::ofstream new_file (_dir); SaveData(data_dir); }
        }
    }
    void LoadData(std::string data_dir="0")
    {
        std::string line;
        std::fstream data_file;
        std::string _dir = os::GetCWD() + dataTool::path_player + "/blueprints.data";
        data_file.open(_dir);

        if (data_file.is_open())
        {
            uint8_t state = 0;
            bool can_do = false;
            std::string name = "";
            std::string tile = "";
            std::string iter = "";
            while (getline(data_file, line))
            {
                int index = 0;
                for (int i = 0; i < line.length(); i++)
                {
                    std::string c = line.substr(i, 1);
                    if (textTool::IsValidSave(c)) { name = name + c; }
                    
                    if (c == "[" && tile == "")
                    { if (name == selected) can_do = true;}
                    
                    if (can_do)
                    {
                        if (textTool::IsNumber(c)) { if (state == 0) { tile = tile + c; } else if (state == 1) { iter = iter + c; } }
                        if (c == ",") { state = 1; }
                        if (c == "]")
                        {
                            uint8_t current_tile = std::stoi(tile);
                            for (int i = 0; i < std::stoi(iter); i++) { matrix[index] = current_tile; index++; }
                            tile = ""; iter = ""; state = 0;
                        }
                    }
                }
                UpdateNames(name); name = ""; can_do = false;
            }
        data_file.close();
        }
    }

};
