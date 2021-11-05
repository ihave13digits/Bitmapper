namespace core
{
    // RNG Presets
    int seed = 0;

    // Flags
    bool running = true;
    bool creative_mode = true;
    bool show_grid = false;
    bool loading = false;

    // Selection
    char selected_hotbar = 0;
    char selected_tile = 0;
    char selected_wand = 0;
    
    //
    int mouse_x;
    int mouse_y;

    // State Flags
    char game_state = 0;
    char pause_state = 0;

    // Tick Speed
    float game_tick = 0.0;
    float tick_delay = 0.035;

    // Graphics Presets
    int width  = 256;
    int height = 144;
    char resolution = 4;
    char grid_subdivision = 1;

    // Identity
    std::string game_title = "Bitmapper";
    std::string version = "0.0.0";

    // Enums

    enum STATES
    {
        TITLE,
        SETTINGS,
        CUSTOM,
        SAVING,
        MAKE_WORLD,
        LOAD_WORLD,
        PLAYING,
        CRAFTING,
        INVENTORY,
        BLUEPRINT,
        NAME_BLUEPRINT,
        LOAD_BLUEPRINT,
        PAUSED,
        EXIT,
    };

    enum PAUSE_STATES
    {
        psTILES,
        psWALLS,
        psCRAFT,
        psTOOLS,
        psEFFECTS,
    };
}
