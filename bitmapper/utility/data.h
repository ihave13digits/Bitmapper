namespace dataTool
{
    //std::string path_ = "/bitmapper/";
    std::string path_player = "/data/player/";
    std::string path_world = "/data/world/";
    std::string path_tile = "/bitmapper/environment/tile/";

    //std::string file_ = "";
    std::string file_tile = "tile.data";

    std::string GetPath(std::string extension)
    {
        return os::GetCWD() + extension;
    }

    void GenerateDirectoryTree()
    {
        std::string _dir = os::GetCWD() + "/data";
        std::string _cmd = "mkdir " + _dir;
        const char* mkdir_cmd = _cmd.c_str();
        system(mkdir_cmd);
    }
}
