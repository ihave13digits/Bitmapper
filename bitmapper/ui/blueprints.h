class Blueprints
{

public:

    std::vector<uint8_t> matrix;
    std::vector<std::string> names;
    std::string selected = "";

    void InitializeMatrix() { for (int i = 0; i < 128*128; i++) { matrix.push_back(0); } }
    void ClearMatrix() { for (int i = 0; i < 128*128; i++) { matrix[i] = 0; } }

    void SaveData(std::string data_dir="0")
    {
        std::fstream data_file;
        std::string _dir = os::GetCWD() + dataTool::path_player + "/blueprint.data";
        data_file.open(_dir);

        if (data_file.is_open())
        {
            data_file << selected;
            for (int i = 0; i < 128*128; i++)
            { data_file << "," << std::to_string(matrix[i]); }
            data_file << std::endl;
            data_file.close();
        }
        else
        { std::ofstream new_file (_dir); SaveData(data_dir); }
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
            while (getline(data_file, line))
            {
                int index = -1;
                std::string name = "";
                std::string tile = "";
                
                for (int i = 0; i < line.length(); i++)
                {
                    std::string c = line.substr(i, 1);
                    if (textTool::IsLetter(c)) { name = name + c; }
                    if (c == "," && tile == "") { if (name == selected) std::cout<< name <<std::endl; can_do = true;}
                    if (can_do)
                    {
                        if (textTool::IsNumber(c)) { tile = tile + c; }
                        if (c == "," && tile != "") { index++; matrix[index] = uint8_t(std::stoi(tile)); tile = ""; }
                    }
                }
                can_do = false;
            }
        data_file.close();
        }
    }

};
