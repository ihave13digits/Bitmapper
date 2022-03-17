namespace core
{
    // RNG Presets
    uint32_t seed = 0;

    // Flags
    bool running = true;
    bool creative_mode = true;
    bool show_mouse = false;
    bool show_grid = false;
    bool loading = false;

    // Selection
    uint8_t selected_hotbar = 0;
    uint8_t selected_tile = 0;
    uint8_t selected_wand = 0;
    
    //
    int mouse_x = 0;
    int mouse_y = 0;

    // State Flags
    uint8_t game_state = 0;
    uint8_t sub_state = 0;

    // Tick Speed
    float game_tick = 0.0;
    float tick_delay = 0.035;

    // Graphics Presets
    int width  = 256;
    int height = 144;
    uint8_t xray = 16;
    uint8_t resolution = 4;
    uint8_t grid_subdivision = 1;

    // Identity
    std::string game_title = "Bitmapper";
    std::string version = "0.24.232.1";

    // Enums

    enum STATES
    {
        TITLE,
        CREDITS,
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

    enum SUB_STATES
    {
        isTILES,
        isWALLS,
        isCRAFT,
        isTOOLS,
        isEFFECTS,
        psCOMMAND,
    };
}
