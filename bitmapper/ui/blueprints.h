class Blueprints
{

public:

    std::vector<uint8_t> matrix;
    std::vector<std::string> names;
    std::string selected = "";



    void InitializeMatrix() { for (int i = 0; i < 128*128; i++) { matrix.push_back(0); } }
    void ClearMatrix() { for (int i = 0; i < 128*128; i++) { matrix[i] = 0; } }
    bool UpdateNames(std::string n) { for (int i = 0; i < names.size(); i++) { if (names[i] == n) { return true;} } names.push_back(n); return false; }

    void SaveData(std::string data_dir="0")
    {
        if (!UpdateNames(selected))
        {
            std::fstream data_file;
            std::string _dir = os::GetCWD() + dataTool::path_player + "/blueprint.data";
            data_file.open(_dir, std::ios_base::app);
            if (data_file.is_open())
            {
                data_file << selected;
                for (int i = 0; i < 128*128; i++)
                { data_file << "," << std::to_string(matrix[i]); }
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
        std::string _dir = os::GetCWD() + dataTool::path_player + "/blueprint.data";
        data_file.open(_dir);

        if (data_file.is_open())
        {
            bool can_do = false;
            std::string name = "";
            std::string tile = "";
            while (getline(data_file, line))
            {
                int index = 0;
                for (int i = 0; i < line.length(); i++)
                {
                    std::string c = line.substr(i, 1);
                    if (textTool::IsLetter(c)) { name = name + c; }
                    if (c == "," && tile == "")
                    { if (name == selected) can_do = true;}
                    if (can_do)
                    {
                        if (textTool::IsNumber(c)) { tile = tile + c; }
                        if (c == "," && tile != "") { matrix[index] = uint8_t(std::stoi(tile)); tile = ""; index++;}
                    }
                }
                UpdateNames(name); name = ""; can_do = false;
            }
        data_file.close();
        }
    }

};
