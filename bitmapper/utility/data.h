namespace dataTool
{
    //std::string path_ = "/bitmapper/";
    std::string path_data = "/data/";
    std::string path_player = path_data+"player/";
    std::string path_world = path_data+"world/";
    std::string path_preset = path_data+"preset/";
    std::string path_tile = "/bitmapper/environment/tile/";

    //std::string file_ = "";
    std::string file_tile =     "tile.data";
    std::string file_settings = "settings.data";
    std::string file_blueprints = "blueprints.data";

    std::string GetPath(std::string extension)
    {
        return os::GetCWD() + extension;
    }

    void SaveSettings()
    {
        std::fstream data_file;
        std::string _dir = os::GetCWD() + path_data + file_settings;
        data_file.open(_dir);

        if (data_file.is_open())
        {
            data_file <<core::selected_hotbar <<",";
            data_file <<core::selected_tile <<",";
            data_file <<core::selected_wand <<",";
            data_file <<core::width <<",";
            data_file <<core::height <<",";
            data_file <<core::resolution <<",";
            data_file <<core::grid_subdivision <<",";
            data_file.close();
        }
        else
        {
            std::ofstream new_file (_dir);
            SaveSettings();
        }
    }
    void LoadSettings()
    {
        std::fstream data_file;
        std::string _dir = os::GetCWD() + path_data + file_settings;
        data_file.open(_dir);
        
        if (data_file.is_open())
        {
            data_file.close();
        }
    }

    void GenerateDirectoryTree()
    {
        std::fstream data_file;
        std::string _dir = os::GetCWD() + path_data + file_settings;
        data_file.open(_dir);

        if (data_file.is_open())
        {
            data_file.close();
        }
        else
        {
            os::MakeDirectory(path_data);
            os::MakeDirectory(path_player);
            os::MakeDirectory(path_preset);
            os::MakeDirectory(path_world);
            SaveSettings();
        }
    }
}
