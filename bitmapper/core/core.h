namespace core
{
    // RNG Presets
    int seed = 0;

    // Flags
    bool running = true;
    bool creative_mode = true;
    bool show_grid = false;
    bool loading = false;

    // State Flags
    int game_state = 0;
    int pause_state = 0;

    // Tick Speed
    float game_tick = 0.0;
    float tick_delay = 0.035;

    // Graphics Presets
    int width  = 256;
    int height = 144;
    int resolution = 4;
    int grid_subdivision = 1;

    // Identity
    std::string game_title = "Bitmapper";
    std::string version = "0.0.0";
}
