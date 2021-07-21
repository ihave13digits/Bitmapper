namespace dataTool
{
    //std::string path_ = "/bitmapper/";
    std::string path_data = "/data/";
    std::string path_player = path_data+"player/";
    std::string path_world = path_data+"world/";
    std::string path_tile = "/bitmapper/environment/tile/";

    //std::string file_ = "";
    std::string file_tile =     "tile.data";
    std::string file_settings = "settings.data";

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
            std::cout <<"Saving Settings" <<std::endl;
            data_file <<core::selected_hotbar <<std::endl;
            data_file <<core::selected_tile <<std::endl;
            data_file <<core::selected_wand <<std::endl;
            data_file <<core::width <<std::endl;
            data_file <<core::height <<std::endl;
            data_file <<core::resolution <<std::endl;
            data_file <<core::grid_subdivision <<std::endl;
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
            std::cout <<"Loading Settings" <<std::endl;
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
            std::cout <<"Directory Tree Is Valid, Starting Bitmapper" <<std::endl;
            data_file.close();
        }
        else
        {
            std::cout <<"Generating Directory Tree" <<std::endl;
            os::MakeDirectory(path_data);
            SaveSettings();
        }
    }
}
