#include "../included.h"

namespace core
{
    // RNG Presets
    int seed   = 0;

    // Graphics Presets
    int width  = 256;
    int height = 144;
    int resolution = 4;

    // Identity
    std::string game_title = "Bitmapper";
    std::string version = "0.0.0";

    void out(std::string text="", std::string end="now")
    {
        std::cout << text;
        if (end == "now")
        {
            std::cout << std::endl;
        }
        else {std::cout << end;}
    }

    void InstallGame()
    {
        out("Installing game");
    }

}
