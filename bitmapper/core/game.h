#define OLC_PGE_APPLICATION
#include "../../lib/olcPixelGameEngine.h"

#include "../included.h"

        // Key Reference
        //NONE,
		//A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		//K0, K1, K2, K3, K4, K5, K6, K7, K8, K9,
		//F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
		//UP, DOWN, LEFT, RIGHT,
		//SPACE, TAB, SHIFT, CTRL, INS, DEL, HOME, END, PGUP, PGDN,
		//BACK, ESCAPE, RETURN, ENTER, PAUSE, SCROLL,
		//NP0, NP1, NP2, NP3, NP4, NP5, NP6, NP7, NP8, NP9,
		//NP_MUL, NP_DIV, NP_ADD, NP_SUB, NP_DECIMAL, PERIOD,
		//EQUALS, COMMA, MINUS,
		//OEM_1, OEM_2, OEM_3, OEM_4, OEM_5, OEM_6, OEM_7, OEM_8,
		//CAPS_LOCK, ENUM_END

class Game : public olc::PixelGameEngine
{

public:

    Game()
    {
        sAppName = core::game_title;
    }

public:

    int input_value = 0;
    std::string input_string = "";
    char save_slot = 0;
    char tile_y = 0;
    char wall_y = 0;
    char tool_y = 0;
    char effect_y = 0;
    char blueprint_y = 0;
    int world_width = 4096;
    int world_height = 2048;
    Icon icon = Icon();
    // Control Presets
    olc::Key player_up = olc::Key::W;
    olc::Key player_down = olc::Key::S;
    olc::Key player_left = olc::Key::A;
    olc::Key player_right = olc::Key::D;
    olc::Key player_min = olc::Key::Q;
    olc::Key player_max = olc::Key::E;
    olc::Key ui_xray = olc::Key::SHIFT;
    olc::Key ui_up = olc::Key::UP;
    olc::Key ui_down = olc::Key::DOWN;
    olc::Key ui_left = olc::Key::LEFT;
    olc::Key ui_right = olc::Key::RIGHT;
    olc::Key ui_select = olc::Key::ENTER;
    olc::Key toggle_grid = olc::Key::G;
    olc::Key menu_main = olc::Key::HOME;
    olc::Key menu_inventory = olc::Key::TAB;
    olc::Key menu_blueprint = olc::Key::B;
    olc::Key menu_pause = olc::Key::ESCAPE;
    olc::Key menu_command = olc::Key::C;
    // Color Presets
    olc::Pixel hud_color        = olc::Pixel( 64,  64,  64, 255);
    olc::Pixel hud_select_color = olc::Pixel(255, 255, 255, 255);
    olc::Pixel grid_color       = olc::Pixel(  0,   0,   0,  64);
    olc::Pixel mouse_color      = olc::Pixel(255, 255, 255,  64);
    olc::Pixel text_color       = olc::Pixel(250, 250, 250, 255);
    olc::Pixel cursor_color     = olc::Pixel(124, 124, 128, 255);
    olc::Pixel panel_color      = olc::Pixel( 10,  10,  10, 255);
    olc::Pixel border_color     = olc::Pixel( 80,  80,  80, 255);
    olc::Pixel button_color     = olc::Pixel( 32,  32,  32, 255);
    olc::Pixel select_color     = olc::Pixel( 64,  64,  64, 255);
    olc::Pixel blueprint_color  = olc::Pixel(  6,  13,  29, 255);

    //
    ///
    //
    
    void InitializeGame()
    {
        tCell::width = world_width; tCell::height = world_height;
        // Filesystem
        dataTool::GenerateDirectoryTree();
        // Load Tiles
        tTile::LoadTileData();
        // Init World Gen
        new_world::InitializeGenerationSteps();
        // Init Instances
        iSystem::InitializeSystem();
    }



    //
    /// UI Stuff
    //


    bool ShiftKey() { return GetKey(olc::Key::SHIFT).bHeld; }
    bool CtrlKey() { return GetKey(olc::Key::CTRL).bHeld; }

    std::string GetCharacter()
    {
        std::string c;
        if (!ShiftKey())
        {
            if (GetKey(olc::Key::A).bPressed) { c = "a"; }
            else if (GetKey(olc::Key::B).bPressed) { c = "b"; }
            else if (GetKey(olc::Key::C).bPressed) { c = "c"; }
            else if (GetKey(olc::Key::D).bPressed) { c = "d"; }
            else if (GetKey(olc::Key::E).bPressed) { c = "e"; }
            else if (GetKey(olc::Key::F).bPressed) { c = "f"; }
            else if (GetKey(olc::Key::G).bPressed) { c = "g"; }
            else if (GetKey(olc::Key::H).bPressed) { c = "h"; }
            else if (GetKey(olc::Key::I).bPressed) { c = "i"; }
            else if (GetKey(olc::Key::J).bPressed) { c = "j"; }
            else if (GetKey(olc::Key::K).bPressed) { c = "k"; }
            else if (GetKey(olc::Key::L).bPressed) { c = "l"; }
            else if (GetKey(olc::Key::M).bPressed) { c = "m"; }
            else if (GetKey(olc::Key::N).bPressed) { c = "n"; }
            else if (GetKey(olc::Key::O).bPressed) { c = "o"; }
            else if (GetKey(olc::Key::P).bPressed) { c = "p"; }
            else if (GetKey(olc::Key::Q).bPressed) { c = "q"; }
            else if (GetKey(olc::Key::R).bPressed) { c = "r"; }
            else if (GetKey(olc::Key::S).bPressed) { c = "s"; }
            else if (GetKey(olc::Key::T).bPressed) { c = "t"; }
            else if (GetKey(olc::Key::U).bPressed) { c = "u"; }
            else if (GetKey(olc::Key::V).bPressed) { c = "v"; }
            else if (GetKey(olc::Key::W).bPressed) { c = "w"; }
            else if (GetKey(olc::Key::X).bPressed) { c = "x"; }
            else if (GetKey(olc::Key::Y).bPressed) { c = "y"; }
            else if (GetKey(olc::Key::Z).bPressed) { c = "z"; }
            else if (GetKey(olc::Key::K0).bPressed) { c = "0"; }
            else if (GetKey(olc::Key::K1).bPressed) { c = "1"; }
            else if (GetKey(olc::Key::K2).bPressed) { c = "2"; }
            else if (GetKey(olc::Key::K3).bPressed) { c = "3"; }
            else if (GetKey(olc::Key::K4).bPressed) { c = "4"; }
            else if (GetKey(olc::Key::K5).bPressed) { c = "5"; }
            else if (GetKey(olc::Key::K6).bPressed) { c = "6"; }
            else if (GetKey(olc::Key::K7).bPressed) { c = "7"; }
            else if (GetKey(olc::Key::K8).bPressed) { c = "8"; }
            else if (GetKey(olc::Key::K9).bPressed) { c = "9"; }
            else if (GetKey(olc::Key::EQUALS).bPressed) { c = "="; }
            else if (GetKey(olc::Key::COMMA).bPressed) { c = ","; }
            else if (GetKey(olc::Key::MINUS).bPressed) { c = "-"; }
            else if (GetKey(olc::Key::PERIOD).bPressed) { c = "."; }
            else if (GetKey(olc::Key::OEM_1).bPressed) { c = ";"; }
            else if (GetKey(olc::Key::OEM_2).bPressed) { c = "/"; }
            else if (GetKey(olc::Key::OEM_4).bPressed) { c = "["; }
            else if (GetKey(olc::Key::OEM_5).bPressed) { c = "\\"; }
            else if (GetKey(olc::Key::OEM_7).bPressed) { c = "'"; }
            else if (GetKey(olc::Key::SPACE).bPressed) { c = " "; }
            else if (GetKey(olc::Key::DEL).bPressed) { c = "DEL"; }
            else if (GetKey(olc::Key::BACK).bPressed) { c = "BACK"; }
            else if (GetKey(olc::Key::LEFT).bPressed) { c = "LEFT"; }
            else if (GetKey(olc::Key::RIGHT).bPressed) { c = "RIGHT"; }
        }
        else if (ShiftKey())
        {
            if (GetKey(olc::Key::A).bPressed) { c = "A"; }
            else if (GetKey(olc::Key::B).bPressed) { c = "B"; }
            else if (GetKey(olc::Key::C).bPressed) { c = "C"; }
            else if (GetKey(olc::Key::D).bPressed) { c = "D"; }
            else if (GetKey(olc::Key::E).bPressed) { c = "E"; }
            else if (GetKey(olc::Key::F).bPressed) { c = "F"; }
            else if (GetKey(olc::Key::G).bPressed) { c = "G"; }
            else if (GetKey(olc::Key::H).bPressed) { c = "H"; }
            else if (GetKey(olc::Key::I).bPressed) { c = "I"; }
            else if (GetKey(olc::Key::J).bPressed) { c = "J"; }
            else if (GetKey(olc::Key::K).bPressed) { c = "K"; }
            else if (GetKey(olc::Key::L).bPressed) { c = "L"; }
            else if (GetKey(olc::Key::M).bPressed) { c = "M"; }
            else if (GetKey(olc::Key::N).bPressed) { c = "N"; }
            else if (GetKey(olc::Key::O).bPressed) { c = "O"; }
            else if (GetKey(olc::Key::P).bPressed) { c = "P"; }
            else if (GetKey(olc::Key::Q).bPressed) { c = "Q"; }
            else if (GetKey(olc::Key::R).bPressed) { c = "R"; }
            else if (GetKey(olc::Key::S).bPressed) { c = "S"; }
            else if (GetKey(olc::Key::T).bPressed) { c = "T"; }
            else if (GetKey(olc::Key::U).bPressed) { c = "U"; }
            else if (GetKey(olc::Key::V).bPressed) { c = "V"; }
            else if (GetKey(olc::Key::W).bPressed) { c = "W"; }
            else if (GetKey(olc::Key::X).bPressed) { c = "X"; }
            else if (GetKey(olc::Key::Y).bPressed) { c = "Y"; }
            else if (GetKey(olc::Key::Z).bPressed) { c = "Z"; }
            else if (GetKey(olc::Key::K0).bPressed) { c = ")"; }
            else if (GetKey(olc::Key::K1).bPressed) { c = "!"; }
            else if (GetKey(olc::Key::K2).bPressed) { c = "@"; }
            else if (GetKey(olc::Key::K3).bPressed) { c = "#"; }
            else if (GetKey(olc::Key::K4).bPressed) { c = "$"; }
            else if (GetKey(olc::Key::K5).bPressed) { c = "%"; }
            else if (GetKey(olc::Key::K6).bPressed) { c = "^"; }
            else if (GetKey(olc::Key::K7).bPressed) { c = "&"; }
            else if (GetKey(olc::Key::K8).bPressed) { c = "*"; }
            else if (GetKey(olc::Key::K9).bPressed) { c = "("; }
            else if (GetKey(olc::Key::OEM_1).bPressed) { c = ":"; }
            else if (GetKey(olc::Key::OEM_2).bPressed) { c = "?"; }
            else if (GetKey(olc::Key::OEM_4).bPressed) { c = "{"; }
            else if (GetKey(olc::Key::OEM_5).bPressed) { c = "|"; }
            else if (GetKey(olc::Key::OEM_7).bPressed) { c = '"'; }
            else if (GetKey(olc::Key::EQUALS).bPressed) { c = "+"; }
            else if (GetKey(olc::Key::COMMA).bPressed) { c = "<"; }
            else if (GetKey(olc::Key::MINUS).bPressed) { c = "_"; }
            else if (GetKey(olc::Key::PERIOD).bPressed) { c = ">"; }
        }
        else
        {
            if (GetKey(olc::Key::BACK).bPressed) { c = "BACK"; }
            if (GetKey(olc::Key::LEFT).bPressed) { c = "LEFT"; }
            if (GetKey(olc::Key::RIGHT).bPressed) { c = "RIGHT"; }
        }
        //if (GetKey(olc::Key::BACK).bPressed) { input_string = input_string.substr(0, input_string.length()-1); }
        return c;
    }

    void HotbarInput()
    {
        if (GetKey(olc::Key::K1).bPressed) { core::selected_hotbar = 0; }
        if (GetKey(olc::Key::K2).bPressed) { core::selected_hotbar = 1; }
        if (GetKey(olc::Key::K3).bPressed) { core::selected_hotbar = 2; }
        if (GetKey(olc::Key::K4).bPressed) { core::selected_hotbar = 3; }
        if (GetKey(olc::Key::K5).bPressed) { core::selected_hotbar = 4; }
        if (GetKey(olc::Key::K6).bPressed) { core::selected_hotbar = 5; }
        if (GetKey(olc::Key::K7).bPressed) { core::selected_hotbar = 6; }
        if (GetKey(olc::Key::K8).bPressed) { core::selected_hotbar = 7; }
        if (GetKey(olc::Key::K9).bPressed) { core::selected_hotbar = 8; }
    }

    void HotbarScroll()
    {
        if (GetMouseWheel() < 0) { if (core::selected_hotbar < 8) core::selected_hotbar++; }
        if (GetMouseWheel() > 0) { if (core::selected_hotbar > 0) core::selected_hotbar--;}
    }

    int GetOffsetX() { return (core::mouse_x+((iSystem::player.x-(iSystem::player.height/2))-(core::width/2))); }
    int GetOffsetY() { return (core::mouse_y+((iSystem::player.y-(iSystem::player.height-1))-(core::height/2))); }

    void UpdateMouse()
    {
        int old_x = core::mouse_x; int old_y = core::mouse_y;
        core::mouse_x = GetMouseX(); core::mouse_y = GetMouseY();
        if (GetKey(olc::Key::CTRL).bHeld)
        {
            if (GetKey(olc::Key::X).bHeld) { core::mouse_x = old_x; }
            if (GetKey(olc::Key::Y).bHeld) { core::mouse_y = old_y; }
        }
        if (core::show_mouse) { DrawMouse(); }
    }

    //
    /// Helper Functions
    //

    bool PlayerVsWorldRefactoredAway()
    {
        bool colliding = false;
        int f = iSystem::player.animations[iSystem::player.anim][iSystem::player.frame];
        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                int index = y*8+x;
                if (iSystem::player.image[f][index] > 0)
                { if ( tTool::BodyCollision((iSystem::player.x+iSystem::player.vx)+(x-4), (iSystem::player.y+iSystem::player.vy)+(y-7)) ) { colliding = true; break; } }
            }
        }
        return colliding;
    }

    void UseHotbar()
    {
        if (GetMouse(0).bHeld)
        {
            //if (iSystem::player.hotbar[core::selected_hotbar][0] == itNONE) {}
            if (iSystem::player.hotbar[core::selected_hotbar][0] == itemID::WAND)
            {
                if (iSystem::player.wands[core::selected_wand].can_fire)
                {
                    iSystem::player.wands[core::selected_wand].Cast();
                    Effect e = iSystem::player.wands[core::selected_wand].effects[iSystem::player.wands[core::selected_wand].current_effect];
                    iSystem::SpawnParticle(float(core::mouse_x), float(core::mouse_y), e);
                }
            }
            // Handle Range
            int limit = iSystem::player.reach;
            if (GetMouseX() < core::width/2-limit || GetMouseX() > core::width/2+limit ||
                GetMouseY() < core::height/2-limit || GetMouseY() > core::height/2+limit)
            { return; }
            // Replace Tile
            int offset_x = GetOffsetX();
            int offset_y = GetOffsetY();
            int index = offset_y*tCell::width+offset_x;
            int tile = tCell::matrix[index];
            int _tile = core::selected_tile;
            if (iSystem::player.hotbar[core::selected_hotbar][0] == itemID::TILE)
            {
                int tile = tCell::matrix[index];
                int _tile = iSystem::player.hotbar[core::selected_hotbar][1];
                if (tile != tTile::MANTLE)
                {
                    if (_tile != tTile::AIR)
                    {
                        if (iSystem::player.inventory.HasItem(_tile) || core::creative_mode)
                        {
                            int amnt = 1;
                            if (tile == tTile::AIR) { amnt = 0; }
                            iSystem::player.inventory.UseItem(_tile, 1); iSystem::player.inventory.AddItem(tile, amnt);
                            tCell::matrix[index] = _tile;
                        }
                    }
                    else if (_tile == tTile::AIR)
                    { if (tile != tTile::AIR) { iSystem::player.inventory.AddItem(tile, 1); } tCell::matrix[index] = _tile; }
                }
            }
        }
    }

    //
    /// Drawing Routines
    //

    void DrawTileName(float x, float y, int tile)
    { std::string text = tTile::NAME[tile]; DrawStringDecal({ x,y }, text, text_color, {0.25, 0.25}); }

    void DrawEffectName(float x, float y, int efct)
    { std::string text = effectID::NAME[efct]; DrawStringDecal({ x,y }, text, text_color, {0.25, 0.25}); }

    void DrawPanel(int x, int y, int w, int h)
    { FillRect({x+1, y+1}, {w-1, h-1}, panel_color); DrawRect({x, y}, {w, h}, border_color); }

    void DrawMouse()
    { SetPixelMode(olc::Pixel::ALPHA); Draw(core::mouse_x, core::mouse_y, mouse_color); SetPixelMode(olc::Pixel::NORMAL); }

    void DrawButton(Button b)
    {
        DrawStringDecal({ b.TextX(),b.TextY() }, b.text, text_color, {b.font, b.font});
        if (b.IsColliding())
        { DrawRect(b.x, b.y, b.width, b.height, select_color); return; }
        DrawRect(b.x, b.y, b.width, b.height, button_color);
    }

    void DrawLabel(Label l)
    {
        float x = l.x+(float(l.cursor)*(8.0*l.font));
        float y = l.y-(l.font*4.0);
        DrawStringDecal({ l.x,l.y }, l.text, text_color, {l.font, l.font});
        FillRect(x, y, l.font*8.0, l.font*16.0, cursor_color);
    }

    void ProgressBar(int x, int y, int minv, int maxv, int W, int R=255, int G=255, int B=255, int r=64, int g=64, int b=64)
    { float completed = float(minv)/float(maxv); int x2 = W*completed; DrawLine(x, y, x+W, y, olc::Pixel(r, g, b)); DrawLine(x, y, x+x2, y, olc::Pixel(R, G, B)); }
    
    void DrawChunkGrid()
    {
        if (!core::show_grid) return;
        const int size = iSystem::world.chunk_size; int sub = size/core::grid_subdivision;
        int _x = iSystem::player.x % (sub); int _y = iSystem::player.y % (sub);
        for (int y = 0; y < core::height+size; y += sub) { DrawLine({0-_x, y-_y}, {core::width-_x+size, y-_y}, olc::Pixel(grid_color)); }
        for (int x = 0; x < core::width+size; x += sub) { DrawLine({x-_x, 0-_y}, {x-_x, core::height-_y+size}, olc::Pixel(grid_color)); }
    }

    void DrawIcon(int x, int y, int tile_type, int tile_value)
    {
        int *img = nullptr;
        switch (tile_type)
        {
            case tTile::GAS           : { img = icon.gas;      } break;
            case tTile::PLASMA        : { img = icon.plasma;   } break;
            case tTile::FUME          : { img = icon.fume;     } break;
            case tTile::FLUID         : { img = icon.fluid;    } break;
            case tTile::GRAIN         : { img = icon.grain;    } break;
            case tTile::GEL           : { img = icon.gel;      } break;
            case tTile::GEM           : { img = icon.gem;      } break;
            case tTile::GEO           : { img = icon.geo;      } break;
            case tTile::ORE           : { img = icon.ore;      } break;
            case tTile::METAL         : { img = icon.metal;    } break;
            case tTile::SOLID         : { img = icon.solid;    } break;
            case tTile::LOOSE         : { img = icon.loose;    } break;
            case tTile::BOOM          : { img = icon.boom;     } break;
            case tTile::LOGIC         : { img = icon.logic;    } break;
            case tTile::GIZMO         : { img = icon.gizmo;    } break;
            case tTile::PLATFORM      : { img = icon.platform; } break;
            case tTile::PLUMBING      : { img = icon.plumbing; } break;
            case tTile::PIPES         : { img = icon.pipes;    } break;
            case tTile::GUTTERS       : { img = icon.gutters;  } break;
            case tTile::PLANT         : { img = icon.plant;    } break;
            case tTile::PLANT_PRODUCT : { img = icon.solid;    } break;
            case tTile::CRITTER       : { img = icon.critter;  } break;
            case tTile::EGG           : { img = icon.egg;      } break;
            case tTile::WALL          : { img = icon.wall;     } break;
        }
        float R = float(tTile::R[tile_value]);
        float G = float(tTile::G[tile_value]);
        float B = float(tTile::B[tile_value]);
        int A = tTile::A[tile_value];
        for (int iy = 0; iy < icon.size; iy++)
        {
            for (int ix = 0; ix < icon.size; ix++)
            {
                int index_value = *(img+iy*icon.size+ix);
                float v = (0.125*float(index_value));
                if (index_value > 0) Draw(ix+x, iy+y, olc::Pixel(int(R*v), int(G*v), int(B*v), A));
            }
        }
    }

    void DrawEffect(int x, int y, int e)
    {
        int tile_value;
        int *img;
        switch (e)
        {
            case effectID::STICKY   : { img = icon.sticky;   tile_value = tTile::FROG; } break;
            case effectID::BOUNCY   : { img = icon.bouncy;   tile_value = tTile::FROG; } break;
            case effectID::HEAVY    : { img = icon.heavy;    tile_value = tTile::LEAD; } break;
            case effectID::DESTROYS : { img = icon.destroys; tile_value = tTile::MILK; } break;
            case effectID::BECOMES  : { img = icon.becomes;  tile_value = tTile::SMOKE; } break;
            case effectID::DAMAGES  : { img = icon.damages;  tile_value = tTile::DYNAMITE; } break;
            case effectID::PIERCES  : { img = icon.pierces;  tile_value = tTile::HONEY; } break;
            case effectID::POISONS  : { img = icon.poisons;  tile_value = tTile::MOSS; } break;
            case effectID::TRAILS   : { img = icon.trails;   tile_value = tTile::THICK_SMOKE; } break;
            case effectID::MINES    : { img = icon.mines;    tile_value = tTile::STONE; } break;
            case effectID::TRIPS    : { img = icon.trips;    tile_value = tTile::SPIDERWORT; } break;
            case effectID::STUNS    : { img = icon.stuns;    tile_value = tTile::HONEY; } break;
            case effectID::BURNS    : { img = icon.burns;    tile_value = tTile::LAVA; } break;
        }
        float R = float(tTile::R[tile_value]);
        float G = float(tTile::G[tile_value]);
        float B = float(tTile::B[tile_value]);
        int A = tTile::A[tile_value];
        for (int iy = 0; iy < icon.size; iy++)
        {
            for (int ix = 0; ix < icon.size; ix++)
            {
                int index_value = *(img+iy*icon.size+ix);
                float v = (0.125*float(index_value));
                if (index_value > 0) Draw(ix+x, iy+y, olc::Pixel(int(R*v), int(G*v), int(B*v), A));
            }
        }
    }

    void DrawTools()
    {
        const int cols = 16; const int rows = 8;
        int x_margin = 48; int y_margin = 40;
        int wand_value = tool_y*cols;
        Button buttons[cols*rows];
        SetPixelMode(olc::Pixel::ALPHA);
        for (int y = tool_y; y < rows; y++)
        {
            for (int x = 0; x < cols; x++)
            {
                if (wand_value < iSystem::player.wands.size())
                {
                    int wand_color = iSystem::player.wands[wand_value].material;
                    float R = float(tTile::R[wand_color]);
                    float G = float(tTile::G[wand_color]);
                    float B = float(tTile::B[wand_color]);
                    int A = tTile::A[wand_color];
                    for (int iy = 0; iy < icon.size; iy++)
                    {
                        for (int ix = 0; ix < icon.size; ix++)
                        {
                            Button b = Button();
                            b.Setup((x*10)+x_margin, (y*10)+y_margin, 9, 9, 1.0, std::to_string(wand_value));
                            buttons[y*cols+x] = b;
                            int index_value = icon.wand[iy*icon.size+ix];
                            float v = (0.25*float(index_value));
                            if (index_value > 0) Draw(ix+(x*10)+x_margin, iy+(y*10)+y_margin, olc::Pixel(int(R*v), int(G*v), int(B*v), A));
                        }
                    }
                    wand_value++;
                }
            }
        }
        SetPixelMode(olc::Pixel::NORMAL);
        for (int y = 0; y < rows; y++)
        {
            for (int x = 0; x < cols; x++)
            {
                Button b = buttons[y*cols+x];
                if (b.IsColliding())
                {
                    DrawRect(b.x, b.y, b.width, b.height, select_color);
                    if (GetMouse(0).bReleased)
                    {
                        iSystem::player.hotbar[core::selected_hotbar][0] = itemID::WAND;
                        iSystem::player.hotbar[core::selected_hotbar][1] = std::stoi(b.text);
                    }
                }
            }
        }
    }

    void DrawEffects()
    {
        const int cols = 16; const int rows = 8;
        const int x_margin = 48; const int y_margin = 40;
        int tile_value = effect_y*cols;
        Button buttons[cols*rows];
        SetPixelMode(olc::Pixel::ALPHA);
        for (int y = 0; y < rows; y++)
        {
            for (int x = 0; x < cols; x++)
            {
                if (tile_value < effectID::total_effects)
                {
                    Button b = Button();
                    b.Setup((x*10)+x_margin, (y*10)+y_margin, 9, 9, 1.0, "");
                    buttons[y*cols+x] = b;
                    DrawEffect((x*10)+x_margin+1, (y*10)+y_margin+1, tile_value);
                }
                tile_value++;
            }
        }
        SetPixelMode(olc::Pixel::NORMAL);
        int hovered_value = -1;
        for (int y = 0; y < rows; y++)
        {
            for (int x = 0; x < cols; x++)
            {
                Button b = buttons[y*cols+x];
                if (b.IsColliding())
                {
                    hovered_value = y*cols+x+(tile_y*cols);
                    DrawRect(b.x, b.y, b.width, b.height, select_color);
                    if (GetMouse(0).bReleased)
                    {
                    }
                }
            }
        }
        if (hovered_value >= 0 && hovered_value < effectID::total_effects) DrawEffectName(GetMouseX()+4, GetMouseY(), hovered_value);
    }

    void DrawTiles()
    {
        const int cols = 16; const int rows = 8;
        const int x_margin = 48; const int y_margin = 40;
        if (tile_y > tTile::total_tiles/cols) { tile_y = tTile::total_tiles/cols; }
        int tile_value = tile_y*cols;
        Button buttons[cols*rows];
        SetPixelMode(olc::Pixel::ALPHA);
        for (int y = 0; y < rows; y++)
        {
            for (int x = 0; x < cols; x++)
            {
                int tile_type = tTool::GetType(tile_value);
                if (tile_value < tTile::total_tiles)
                {
                    Button b = Button();
                    b.Setup((x*10)+x_margin, (y*10)+y_margin, 9, 9, 1.0, std::to_string(tile_value));
                    buttons[y*cols+x] = b;
                    DrawIcon((x*10)+x_margin+1, (y*10)+y_margin+1, tile_type, tile_value);
                }
                tile_value++;
            }
        }
        SetPixelMode(olc::Pixel::NORMAL);
        int hovered_value = -1;
        for (int y = 0; y < rows; y++)
        {
            for (int x = 0; x < cols; x++)
            {
                Button b = buttons[y*cols+x];
                if (b.IsColliding())
                {
                    hovered_value = y*cols+x+(tile_y*cols);
                    DrawRect(b.x, b.y, b.width, b.height, select_color);
                    if (GetMouse(0).bReleased)
                    { iSystem::player.hotbar[core::selected_hotbar][0] = itemID::TILE; iSystem::player.hotbar[core::selected_hotbar][1] = std::stoi(b.text); }
                }
            }
        }
        if (hovered_value >= 0 && hovered_value < tTile::total_tiles) DrawTileName(GetMouseX()+4, GetMouseY(), hovered_value);
    }

    void DrawWalls()
    {
    }

    void DrawCrafting()
    {
    }

    void DrawSky()
    {
        if (iSystem::player.status != iSystem::player.TRIP) Clear(olc::Pixel(iSystem::sky.R, iSystem::sky.G, iSystem::sky.B));
        if (iSystem::sky.starlight >= 0)
        {
            SetPixelMode(olc::Pixel::ALPHA);
            for (int i = 0; i < iSystem::sky.starcount; i += 4)
            {
                uint8_t value = rand()%220+35;
                Draw(iSystem::sky.stars[i][0],   iSystem::sky.stars[i][1], olc::Pixel(value, value, value, 255-iSystem::sky.starlight));
                Draw(iSystem::sky.stars[i+1][0], iSystem::sky.stars[i][1], olc::Pixel(value, value, value, 255-iSystem::sky.starlight));
                Draw(iSystem::sky.stars[i+2][0], iSystem::sky.stars[i][1], olc::Pixel(value, value, value, 255-iSystem::sky.starlight));
                Draw(iSystem::sky.stars[i+3][0], iSystem::sky.stars[i][1], olc::Pixel(value, value, value, 255-iSystem::sky.starlight));
            }
        }

        if (iSystem::sky.time > 0.5)
        {
            FillCircle(iSystem::sky.sunx, iSystem::sky.suny, iSystem::sky.sun, olc::WHITE);
            FillCircle(iSystem::sky.sunx, iSystem::sky.suny, iSystem::sky.sun*1.2, olc::Pixel(255, 255, 255, 24));
            FillCircle(iSystem::sky.sunx, iSystem::sky.suny, iSystem::sky.sun*1.3, olc::Pixel(255, 255, 255, 20));
            FillCircle(iSystem::sky.sunx, iSystem::sky.suny, iSystem::sky.sun*1.4, olc::Pixel(255, 255, 255, 16));
            FillCircle(iSystem::sky.sunx, iSystem::sky.suny, iSystem::sky.sun*1.5, olc::Pixel(255, 255, 255, 12));
        }
        else if (iSystem::sky.time < 0.5)
        {
            FillCircle(iSystem::sky.moonx, iSystem::sky.moony, iSystem::sky.moon, olc::WHITE);
            FillCircle(iSystem::sky.moonx, iSystem::sky.moony, iSystem::sky.moon*1.2, olc::Pixel(255, 255, 255, 24));
            FillCircle(iSystem::sky.moonx, iSystem::sky.moony, iSystem::sky.moon*1.3, olc::Pixel(255, 255, 255, 20));
            FillCircle(iSystem::sky.moonx, iSystem::sky.moony, iSystem::sky.moon*1.4, olc::Pixel(255, 255, 255, 16));
            FillCircle(iSystem::sky.moonx, iSystem::sky.moony, iSystem::sky.moon*1.5, olc::Pixel(255, 255, 255, 12));
            //
            FillCircle(iSystem::sky.moonx, iSystem::sky.moony, iSystem::sky.moon*0.95, olc::Pixel(220, 220, 220));
            FillCircle(iSystem::sky.moonx-2, iSystem::sky.moony+1, iSystem::sky.moon/2, olc::Pixel(195, 195, 195));
            FillCircle(iSystem::sky.moonx+3, iSystem::sky.moony+3, iSystem::sky.moon/2, olc::Pixel(195, 195, 195));
            FillCircle(iSystem::sky.moonx+2, iSystem::sky.moony-1, iSystem::sky.moon/3, olc::Pixel(170, 170, 170));
            FillCircle(iSystem::sky.moonx-3, iSystem::sky.moony-4, iSystem::sky.moon/3, olc::Pixel(170, 170, 170));
            FillCircle(iSystem::sky.moonx-2, iSystem::sky.moony+3, iSystem::sky.moon/4, olc::Pixel(145, 145, 145));
            FillCircle(iSystem::sky.moonx+3, iSystem::sky.moony+4, iSystem::sky.moon/4, olc::Pixel(145, 145, 145));
            FillCircle(iSystem::sky.moonx+3, iSystem::sky.moony-2, iSystem::sky.moon/5, olc::Pixel(120, 120, 120));
            FillCircle(iSystem::sky.moonx-4, iSystem::sky.moony-3, iSystem::sky.moon/5, olc::Pixel(120, 120, 120));
        }
        for (int i = 0; i < iSystem::sky.humidity; i++)
        {
            int x = iSystem::sky.clouds[i][0]; int y = iSystem::sky.clouds[i][1];
            FillCircle(x, y, iSystem::sky.clouds[i][2], olc::Pixel(iSystem::sky.r, iSystem::sky.g, iSystem::sky.b, int(8.0+(24.0*iSystem::sky.time))));
        }
        if (iSystem::sky.humidity > iSystem::sky.cloudcount/4 && core::game_state == core::PLAYING)
        {
            if (rand()%iSystem::sky.cloudcount < iSystem::sky.humidity)
            {
                if (iSystem::sky.day < iSystem::sky.year_length*0.75)
                { tCell::matrix[256*tCell::width+((rand()%core::width)+iSystem::player.x-(core::width/2))] = tTile::WATER; }
                else if (iSystem::sky.day >= iSystem::sky.year_length*0.75)
                { tCell::matrix[256*tCell::width+((rand()%core::width)+iSystem::player.x-(core::width/2))] = tTile::SNOW; }
            }
        }
        SetPixelMode(olc::Pixel::NORMAL);
    }

    void DrawTerrain()
    {
        int X = iSystem::camera.x - (core::width/2);
        int Y = iSystem::camera.y - (core::height/2);
        SetPixelMode(olc::Pixel::ALPHA);
        for (int y = 0; y < core::height; y++)
        {
            for (int x = 0; x < core::width; x += 4)
            {
                if ( (x+X > 0 && x+X < tCell::width-1) && (y+Y > 1 && y+Y < tCell::height-1) )
                {
                    int v1 = tCell::matrix[(y+Y)*tCell::width+(x+X)];
                    int v2 = tCell::matrix[(y+Y)*tCell::width+(x+X+1)];
                    int v3 = tCell::matrix[(y+Y)*tCell::width+(x+X)+2];
                    int v4 = tCell::matrix[(y+Y)*tCell::width+(x+X)+3];
                    float s1 = 1.0f-std::min(std::max(tTool::Neighbors(x+X, y+Y), 0.0f), 1.0f);
                    float s2 = 1.0f-std::min(std::max(tTool::Neighbors(x+X+1, y+Y), 0.0f), 1.0f);
                    float s3 = 1.0f-std::min(std::max(tTool::Neighbors(x+X+2, y+Y), 0.0f), 1.0f);
                    float s4 = 1.0f-std::min(std::max(tTool::Neighbors(x+X+3, y+Y), 0.0f), 1.0f);
                    Draw(x, y,   olc::Pixel(uint8_t(tTile::R[v1]*s1), uint8_t(tTile::G[v1]*s1), uint8_t(tTile::B[v1]*s1), tTile::A[v1]));
                    Draw(x+1, y, olc::Pixel(uint8_t(tTile::R[v2]*s2), uint8_t(tTile::G[v2]*s2), uint8_t(tTile::B[v2]*s2), tTile::A[v2]));
                    Draw(x+2, y, olc::Pixel(uint8_t(tTile::R[v3]*s3), uint8_t(tTile::G[v3]*s3), uint8_t(tTile::B[v3]*s3), tTile::A[v3]));
                    Draw(x+3, y, olc::Pixel(uint8_t(tTile::R[v4]*s4), uint8_t(tTile::G[v4]*s4), uint8_t(tTile::B[v4]*s4), tTile::A[v4]));
                }
            }
        }
        DrawChunkGrid();
        SetPixelMode(olc::Pixel::NORMAL);
    }

    void DrawXRay()
    {
        int X = iSystem::camera.x - (core::width/2) + core::mouse_x;
        int Y = iSystem::camera.y - (core::height/2) + core::mouse_y;
        SetPixelMode(olc::Pixel::ALPHA);
        for (int y = -core::xray; y < core::xray; y++)
        {
            for (int x = -core::xray; x < core::xray; x += 4)
            {
                if ( (x+X >= 0 && x+X < tCell::width-1) && (y+Y >= 0 && y+Y < tCell::height-1) )
                {
                    int v1 = tCell::matrix[(y+Y)*tCell::width+(x+X)];
                    int v2 = tCell::matrix[(y+Y)*tCell::width+(x+X+1)];
                    int v3 = tCell::matrix[(y+Y)*tCell::width+(x+X)+2];
                    int v4 = tCell::matrix[(y+Y)*tCell::width+(x+X)+3];
                    int dx = x+core::width-int(core::xray);
                    int dy = y+core::height-int(core::xray);
                    Draw(dx, dy, olc::Pixel(uint8_t(tTile::R[v1]), uint8_t(tTile::G[v1]), uint8_t(tTile::B[v1]), tTile::A[v1]));
                    Draw(dx+1, dy, olc::Pixel(uint8_t(tTile::R[v2]), uint8_t(tTile::G[v2]), uint8_t(tTile::B[v2]), tTile::A[v2]));
                    Draw(dx+2, dy, olc::Pixel(uint8_t(tTile::R[v3]), uint8_t(tTile::G[v3]), uint8_t(tTile::B[v3]), tTile::A[v3]));
                    Draw(dx+3, dy, olc::Pixel(uint8_t(tTile::R[v4]), uint8_t(tTile::G[v4]), uint8_t(tTile::B[v4]), tTile::A[v4]));
                }
            }
        }
        SetPixelMode(olc::Pixel::NORMAL);
    }

    void DrawPlayer()
    {
        int r; int g; int b;
        switch (iSystem::player.status)
        {
            case iSystem::player.FINE :     {r=255; g=255; b=255;} break;
            case iSystem::player.HURT :     {r=255; g=128; b=0  ;} break;
            case iSystem::player.BURN :     {r=255; g=0  ; b=0  ;} break;
            case iSystem::player.COLD :     {r=128; g=128; b=255;} break;
            case iSystem::player.STUN :     {r=255; g=255; b=0  ;} break;
            case iSystem::player.TRIP :     {r=0;   g=255; b=255;} break;
            case iSystem::player.POISON :   {r=0;   g=255; b=0  ;} break;
            case iSystem::player.CONFUSED : {r=128; g=128; b=128;} break;
        }
        int f = iSystem::player.animations[iSystem::player.anim][iSystem::player.frame];
        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                int index = y*8+x;
                if (iSystem::player.image[f][index] > 0)
                {
                    int v = iSystem::player.image[f][index];
                    uint8_t R = std::min((((v*32)+r)/2), 255);
                    uint8_t G = std::min((((v*32)+g)/2), 255);
                    uint8_t B = std::min((((v*32)+b)/2), 255);
                    int _x = x+iSystem::camera.offset_x;
                    int _y = y+iSystem::camera.offset_y;
                    Draw(_x, _y, olc::Pixel(R, G, B));
                }
            }
        }
    }

    void DrawParticles(float delta)
    {
        for (int p = 0; p < (iSystem::particles.size()); p++)
        {
            float x = iSystem::particles[p].x; float y = iSystem::particles[p].y;
            iSystem::UpdateParticle(delta, p, x, y);
            if (iSystem::particles[p].duration > 0.0)
            {
                iSystem::particles[p].duration -= delta;
                Draw(x-(iSystem::camera.x-(core::width/2)), y-(iSystem::camera.y-(core::height/2)),
                    olc::Pixel(iSystem::particles[p].r, iSystem::particles[p].g, iSystem::particles[p].b, iSystem::particles[p].a));
            }
            else { iSystem::particles.erase(iSystem::particles.begin()+p); }
        }
    }

    void DrawHUD()
    {
        float font = 0.25;
        int offset_x = GetOffsetX();
        int offset_y = GetOffsetY();
        int lookindex = offset_y*tCell::width+offset_x;
        std::string health = std::to_string(iSystem::player.hp)+"/"+std::to_string(iSystem::player.HP);
        std::string lookingat = "Air";
        std::string selectedtile = tTile::NAME[core::selected_tile];
        std::string selectedcount = "";
        std::string collision_at = std::to_string(tTool::Collision(offset_x, offset_y));
        std::string chunk_pos = std::to_string(iSystem::PlayerChunkX())+", "+std::to_string(iSystem::PlayerChunkY());
        if ( ( (lookindex < tCell::width*tCell::height) && lookindex > 0) && (tCell::matrix[lookindex] < tTile::total_tiles) )
        { lookingat = tTile::NAME[tCell::matrix[lookindex]]; }
        if (iSystem::player.inventory.HasItem(core::selected_tile))
        { selectedcount = std::to_string(iSystem::player.inventory.data[core::selected_tile]); }
        ProgressBar(4, 2, iSystem::player.hp, iSystem::player.HP, 32, 255, 0, 0, 64, 0, 0);
        ProgressBar(4, 4, iSystem::player.jp, iSystem::player.JP, 32, 0, 255, 0, 0, 64, 0);
        ProgressBar(4, 6, iSystem::player.bp, iSystem::player.BP, 32, 0, 0, 255, 0, 0, 64);
        DrawStringDecal({ 4,8  }, "Looking At: " + lookingat, text_color, { font, font });
        DrawStringDecal({ 4,12 }, "Collision: " + collision_at, text_color, { font, font });
        DrawStringDecal({ 4,16 }, "Day: " + std::to_string(iSystem::sky.day), text_color, { font, font });
        DrawStringDecal({ 4,20 }, "Year: " + std::to_string(iSystem::sky.year), text_color, { font, font });
        DrawStringDecal({ 4,24 }, "Season: " + seasonID::seasons[tCell::season], text_color, { font, font });
        DrawStringDecal({ 4,28 }, "Chunk: " + chunk_pos, text_color, { font, font });
        //
        int hb_size = icon.size+1; int hb_offset = (core::width/2) - hb_size*4.5; std::string selected_item = "";
        if (iSystem::player.hotbar[core::selected_hotbar][0] == itemID::WAND) { selected_item = "Wand"; }
        if (iSystem::player.hotbar[core::selected_hotbar][0] == itemID::TILE) { selected_item = tTile::NAME[iSystem::player.hotbar[core::selected_hotbar][1]]; }
        float select_x = (core::width/2)-(selected_item.size());
        DrawStringDecal({ select_x,15 }, selected_item, text_color, { 0.25, 0.25 });
        SetPixelMode(olc::Pixel::ALPHA);
        for (int i = 0; i < 9; i++)
        {
            int x = i*hb_size+hb_offset;
            DrawRect(x, 2, hb_size, hb_size, hud_color);
            if (iSystem::player.hotbar[i][0] == itemID::WAND)
            {
                int tile_value = iSystem::player.hotbar[i][1];
                float R = float(tTile::R[tile_value]); float G = float(tTile::G[tile_value]); float B = float(tTile::B[tile_value]);
                for (int iy = 0; iy < icon.size; iy++)
                {
                    for (int ix = 0; ix < icon.size; ix++)
                    {
                        int index_value = icon.wand[iy*icon.size+ix]; float v = (0.25*float(index_value));
                        if (index_value > 0) Draw(ix+x+1, iy+3, olc::Pixel(int(R*v), int(G*v), int(B*v)));
                    }
                }
            }
            if (iSystem::player.hotbar[i][0] == itemID::TILE)
            {
                int tile_value = iSystem::player.hotbar[i][1];
                int tile_type = tTool::GetType(tile_value);
                DrawIcon(x+1, 3, tile_type, tile_value);
            }
        }
        SetPixelMode(olc::Pixel::NORMAL); DrawRect(core::selected_hotbar*hb_size+hb_offset, 2, hb_size, hb_size, hud_select_color);
    }

    //
    /// Game States
    //
    
    void StateTitle()
    {
        Clear(olc::BLACK);
        float Tx = (core::width/2)-((sAppName.size()*16)/2);
        float Ty = (core::height*0.25);
        float Nx = (core::width/2)-50;
        float Lx = (core::width/2)+4;
        float By = (core::height*0.75);
        DrawStringDecal({ Tx,Ty }, sAppName, text_color, { 2.0, 2.0 });
        Button bNew = Button(); bNew.Setup(Nx, By, 48, 16, 1.0, "New"); DrawButton(bNew);
        Button bLoad = Button(); bLoad.Setup(Lx, By, 48, 16, 1.0, "Load"); DrawButton(bLoad);
        if (bNew.IsColliding())
        {
            DrawRect(bNew.x, bNew.y, bNew.width, bNew.height, select_color);
            if (GetMouse(0).bReleased) { Clear(olc::BLACK); core::game_state = core::CUSTOM; iSystem::player.Setup(); }
        }
        if (bLoad.IsColliding())
        {
            DrawRect(bLoad.x, bLoad.y, bLoad.width, bLoad.height, select_color);
            if (GetMouse(0).bReleased)
            { Clear(olc::BLACK); tCell::width = world_width; tCell::height = world_height; iSystem::PrepareGame(); core::game_state = core::LOAD_WORLD; }
        }
    }

    void StateCredits()
    {}

    void StateSettings()
    {}

    void StateCustom()
    {
        //Clear(olc::BLACK);
        bool can_draw = false;
        std::string info_text = "Hover Over A Button To See Details";
        std::string dtls_text = "";
        // Buttons
        Button bsave     = Button();     bsave.Setup(105, 37, 32, 8, 0.25,     "Save"); DrawButton(bsave);
        Button bload     = Button();     bload.Setup(105, 45, 32, 8, 0.25,     "Load"); DrawButton(bload);
        Button bclear    = Button();    bclear.Setup(105, 57, 32, 8, 0.25,    "Clear"); DrawButton(bclear);
        Button bconfig   = Button();   bconfig.Setup(105, 65, 32, 8, 0.25,   "Preset"); DrawButton(bconfig);
        Button brandom   = Button();   brandom.Setup(105, 73, 32, 8, 0.25,   "Random"); DrawButton(brandom);
        Button bpreview  = Button();  bpreview.Setup(105, 86, 32, 8, 0.25,  "Preview"); DrawButton(bpreview);
        Button bgenerate = Button(); bgenerate.Setup(105, 94, 32, 8, 0.25, "Generate"); DrawButton(bgenerate);
        Button bminusgs  = Button();  bminusgs.Setup(183,  2, 70, 4, 0.25,        "-"); DrawButton(bminusgs);
        Button bplusgs   = Button();   bplusgs.Setup(183, 88, 70, 4, 0.25,        "+"); DrawButton(bplusgs);
        Button bcopy     = Button();     bcopy.Setup(183, 94, 35, 8, 0.25,     "Copy"); DrawButton(bcopy);
        Button bpaste    = Button();    bpaste.Setup(218, 94, 35, 8, 0.25,    "Paste"); DrawButton(bpaste);
        Button bsave0    = Button();    bsave0.Setup(141,  7, 38, 8, 0.25,   "Save 0"); DrawButton(bsave0);
        Button bsave1    = Button();    bsave1.Setup(141, 15, 38, 8, 0.25,   "Save 1"); DrawButton(bsave1);
        Button bsave2    = Button();    bsave2.Setup(141, 23, 38, 8, 0.25,   "Save 2"); DrawButton(bsave2);
        Button bsave3    = Button();    bsave3.Setup(141, 31, 38, 8, 0.25,   "Save 3"); DrawButton(bsave3);
        Button bsave4    = Button();    bsave4.Setup(141, 39, 38, 8, 0.25,   "Save 4"); DrawButton(bsave4);
        Button bsave5    = Button();    bsave5.Setup(141, 47, 38, 8, 0.25,   "Save 5"); DrawButton(bsave5);
        Button bsave6    = Button();    bsave6.Setup(141, 55, 38, 8, 0.25,   "Save 6"); DrawButton(bsave6);
        Button btile     = Button();     btile.Setup(141, 70, 18, 8, 0.25,     "Tile"); DrawButton(btile);
        Button bmode     = Button();     bmode.Setup(141, 78, 18, 8, 0.25,     "Mode"); DrawButton(bmode);
        Button bdense    = Button();    bdense.Setup(141, 86, 18, 8, 0.25,  "Density"); DrawButton(bdense);
        Button biter     = Button();     biter.Setup(141, 94, 18, 8, 0.25,   "Repeat"); DrawButton(biter);
        Button bminx     = Button();     bminx.Setup(162, 70, 18, 8, 0.25,    "Min X"); DrawButton(bminx);
        Button bmaxx     = Button();     bmaxx.Setup(162, 78, 18, 8, 0.25,    "Max X"); DrawButton(bmaxx);
        Button bminy     = Button();     bminy.Setup(162, 86, 18, 8, 0.25,    "Min Y"); DrawButton(bminy);
        Button bmaxy     = Button();     bmaxy.Setup(162, 94, 18, 8, 0.25,    "Max Y"); DrawButton(bmaxy);
        Button bprobn    = Button();    bprobn.Setup(117,  6,  8, 8, 0.25,        "N"); DrawButton(bprobn);
        Button bprobs    = Button();    bprobs.Setup(117, 22,  8, 8, 0.25,        "S"); DrawButton(bprobs);
        Button bprobe    = Button();    bprobe.Setup(125, 14,  8, 8, 0.25,        "E"); DrawButton(bprobe);
        Button bprobw    = Button();    bprobw.Setup(109, 14,  8, 8, 0.25,        "W"); DrawButton(bprobw);
        DrawRect(2, 2, 100, 100, border_color);  // Preview Box
        DrawRect(183, 2, 70, 90, border_color);  // Generation Steps Box
        DrawRect(2, 105, 251, 36, border_color);  // Information Box
        DrawRect(105, 2, 32, 32, border_color);  // Neighbors Box
        // Numeric Input
        if (GetKey(olc::Key::K0).bPressed) { std::string new_value = std::to_string(input_value)+"0"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K1).bPressed) { std::string new_value = std::to_string(input_value)+"1"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K2).bPressed) { std::string new_value = std::to_string(input_value)+"2"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K3).bPressed) { std::string new_value = std::to_string(input_value)+"3"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K4).bPressed) { std::string new_value = std::to_string(input_value)+"4"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K5).bPressed) { std::string new_value = std::to_string(input_value)+"5"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K6).bPressed) { std::string new_value = std::to_string(input_value)+"6"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K7).bPressed) { std::string new_value = std::to_string(input_value)+"7"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K8).bPressed) { std::string new_value = std::to_string(input_value)+"8"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K9).bPressed) { std::string new_value = std::to_string(input_value)+"9"; input_value = std::stoi(new_value); }
        if (GetKey(ui_select).bPressed)
        {
            switch (new_world::selected_param)
            {
                case new_world::pTILE : if (input_value > tTile::total_tiles-1) input_value = tTile::total_tiles-1; break;
                case new_world::pMODE : if (input_value > 3) input_value = 3; break;
                case new_world::pITER : if (input_value > 64) input_value = 64; break;
                default : if (input_value > 100) input_value = 100; break;
            }
            new_world::generation_param[new_world::selected_step][new_world::selected_param] = input_value;
            input_value = 0;
        }
        // Update Parameters
        if (GetKey(ui_down).bPressed || GetMouseWheel() < 0) { if (new_world::selected_step < new_world::generation_steps-2) new_world::selected_step++; }
        if (GetKey(ui_up).bPressed || GetMouseWheel() > 0) { if (new_world::selected_step > 0) new_world::selected_step--; }
        if (GetKey(ui_left).bPressed) { new_world::DecrementParameter(); }
        if (GetKey(ui_right).bPressed) { new_world::IncrementParameter(); }
        // Step Value
        if (bminusgs.IsColliding()){
            info_text = "Removes The Selected Generation Step From The List"; //dtls_text = "()";
            if (GetMouse(0).bReleased) { new_world::Remove(); } }
        if (bplusgs.IsColliding()){
            info_text = "Inserts A Generation Step Into The List"; //dtls_text = "()";
            if (GetMouse(0).bReleased) { new_world::Insert(); } }
        // Tile Value
        if (btile.IsColliding()){
            info_text = "Material To add To World"; //dtls_text = "()";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pTILE; }
        // Density Value
        if (bdense.IsColliding()){
            info_text = "Probability A Material Will Spawn Per Cell"; dtls_text = "(Add Layer, Seed Material)";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pDENSE; }
        if (biter.IsColliding()){
            info_text = "How Many Times to Repeat Current Step"; //dtls_text = "()";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pITER; }
        // X Values
        if (bminx.IsColliding()){
            info_text = "Minimum Width Range Of Effect"; dtls_text = "(0-100 %)";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pMINX; }
        if (bmaxx.IsColliding()){
            info_text = "Maximum Width Range Of Effect"; dtls_text = "(0-100 %)";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pMAXX; }
        // Y values
        if (bminy.IsColliding()){
            info_text = "Minimum Height Range Of Effect"; dtls_text = "(0-100 %)";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pMINY; }
        if (bmaxy.IsColliding()){
            info_text = "Maximum Height Range Of Effect"; dtls_text = "(0-100 %)";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pMAXY; }
        // Neighbor Values
        if (bprobn.IsColliding()){
            info_text = "Probability That A Northern Neighbor Will Spawn"; //dtls_text = "()";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pPROBN; }
        if (bprobs.IsColliding()){
            info_text = "Probability That A Southern Neighbor Will Spawn"; //dtls_text = "()";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pPROBS; }
        if (bprobe.IsColliding()){
            info_text = "Probability That An Eastern Neighbor Will Spawn"; //dtls_text = "()";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pPROBE; }
        if (bprobw.IsColliding()){
            info_text = "Probability That A Western Neighbor Will Spawn"; //dtls_text = "()";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pPROBW; }
        // Mode Value
        if (bmode.IsColliding()){
            info_text = "Changes Generation Mode"; //dtls_text = "()";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pMODE; }
        // Clear Values
        if (bclear.IsColliding()){
            info_text = "Clears All Generation Data";
            if (GetMouse(0).bReleased) { new_world::ClearData(); } }
        // Auto Configure
        if (bconfig.IsColliding()){
            info_text = "Standard World Generation"; //dtls_text = "()";
            if (GetMouse(0).bReleased) { new_world::PresetData(); } }
        // Randomize Seed
        if (brandom.IsColliding()){
            info_text = "Randomizes Game Seed";
            if (GetMouse(0).bReleased) { new_world::RandomizeData(); can_draw = true; } }
        // Save
        if (bsave.IsColliding()){
            info_text = "Saves Generation Data";
            DrawRect(bsave.x, bsave.y, bsave.width, bsave.height, select_color);
            if (GetMouse(0).bReleased) { new_world::SaveData(std::to_string(save_slot) + ".txt"); } }
        // Load
        if (bload.IsColliding()){
            info_text = "Loads Generation Data";
            if (GetMouse(0).bReleased) { new_world::LoadData(std::to_string(save_slot) + ".txt"); } }
        // Copy
        if (bcopy.IsColliding()){
            info_text = "Copies Selected Generation Step";
            if (GetMouse(0).bReleased) { new_world::Copy(); } }
        // Paste
        if (bpaste.IsColliding()){
            info_text = "Pastes Selected Generation Step";
            if (GetMouse(0).bReleased) { new_world::Paste(); } }
        // Generate World
        if (bgenerate.IsColliding()){
            info_text = "Generates World And Starts Game";
            if (GetMouse(0).bReleased) { new_world::ReadyWorld(world_width, world_height); iSystem::camera.SetLimits(); } }
        // Generate Preview
        if (bpreview.IsColliding()){
            info_text = "Updates The Preview Box";
            if (GetMouse(0).bReleased) { new_world::ReadyPreview(); can_draw = true; } }
        // Draw Preview
        if (can_draw)
        {
            FillRect(3, 3, 99, 99, olc::Pixel(128, 128, 255));
            SetPixelMode(olc::Pixel::ALPHA);
            for (int y = 0; y < 100; y++) {
                for (int x = 0; x < 100; x++) {
                    int v = tCell::matrix[y*tCell::width+x];
                    Draw(x+3, y+3, olc::Pixel(tTile::R[v], tTile::G[v], tTile::B[v], tTile::A[v])); } }
            SetPixelMode(olc::Pixel::NORMAL);
        }
        // Draw Generation Steps
        int list_height = 0;
        int stop_list = std::min(new_world::selected_step+9, new_world::generation_steps);
        int start_list = std::max(stop_list-9, 0);
        for (int i = start_list; i < stop_list; i++)
        {
            std::string vlue_text;
            std::string mode_text;
            std::string tile_text;
            try { if (new_world::generation_param[i][new_world::selected_param] < new_world::total_modes)
                {mode_text = new_world::modes[new_world::generation_param[i][new_world::selected_param]]; } }
            catch (std::bad_alloc & ba) { mode_text = "Error"; }
            try { tile_text = tTile::NAME[new_world::generation_param[i][new_world::selected_param]]; }
            catch (std::bad_alloc & ba) { tile_text = "Error"; }
            try { vlue_text = std::to_string(new_world::generation_param[i][new_world::selected_param]); }
            catch (std::bad_alloc & ba) { vlue_text = "Error"; }
            if (i == new_world::selected_step)
            {
                tile_text = ">" + tile_text;
                switch (new_world::selected_param)
                {
                    case new_world::pTILE : DrawStringDecal({ float(186),float((list_height*9)+10) }, tile_text, text_color, { 0.5, 0.5 }); break;
                    case new_world::pMODE : DrawStringDecal({ float(186),float((list_height*9)+10) }, mode_text, text_color, { 0.5, 0.5 }); break;
                    default : DrawStringDecal({ float(186),float((list_height*9)+10) }, vlue_text, text_color, { 0.5, 0.5 }); break;
                }
            }
            else
            {
                switch (new_world::selected_param)
                {
                    case new_world::pTILE : DrawStringDecal({ float(186),float((list_height*9)+10) }, tile_text, button_color, { 0.5, 0.5 }); break;
                    case new_world::pMODE : DrawStringDecal({ float(186),float((list_height*9)+10) }, mode_text, button_color, { 0.5, 0.5 }); break;
                    default : DrawStringDecal({ float(186),float((list_height*9)+10) }, vlue_text, button_color, { 0.5, 0.5 }); break;
                }
            }
            list_height++;
        }
        // Draw Info
        DrawStringDecal({ 5,109 }, info_text, text_color, { 0.5, 0.5 });
        DrawStringDecal({ 5,115 }, dtls_text, text_color, { 0.5, 0.5 });

    }

    void StateSaving()
    {
    }

    void StateLoadWorld()
    {
        Clear(olc::BLACK);
        if (core::loading)
        {
            if (core::map_index >= (tCell::width*tCell::height)-1)
            {
                core::loading = false;
                core::game_state = core::PLAYING;
            }
            else { iSystem::world.LoadWorldData(); }
        }
        if (!core::loading) core::loading = true;
        int prog_x = (core::width/2)-(core::width/4);
        int prog_y = (core::height/2)+4;
        ProgressBar(prog_x, prog_y, core::map_index, tCell::width*tCell::height, core::width/2);
    }

    void StateMakeWorld()
    {
        Clear(olc::BLACK);
        std::string message = "Generating World, Please Wait.";
        if (core::loading)
        {
            message = new_world::GenerateWorld();
            if (new_world::generation_step > new_world::generation_steps)
            {
                iSystem::sky.GenerateSky(core::width, core::height, core::seed);
                iSystem::player.x = int(tCell::width/2);
                iSystem::player.y = iSystem::player.height+2;
                while (!tTool::BodyCollision(iSystem::player.x, iSystem::player.y+1)) { iSystem::player.Move(0, 1); iSystem::player.can_move = true;}
                core::loading = false;
                core::game_state = core::PLAYING;
            }
        }
        if (!core::loading) core::loading = true;
        int prog_x = (core::width/2)-(core::width/4);
        int prog_y = (core::height/2)+4;
        float msg_x = core::width/2-((message.size()/2)*4);
        float msg_y = (core::height/2)-4;
        DrawStringDecal({ msg_x, msg_y }, message, text_color, { 0.5, 0.5 });
        ProgressBar(prog_x, prog_y, new_world::generation_step-1, new_world::generation_steps, core::width/2);
    }

    void StatePaused()//float fElapsedTime)
    {
        bool xrays= false, needs_update = (core::show_mouse && (GetMouseX() != core::mouse_x || GetMouseY() != core::mouse_y));
        if (core::sub_state != core::psCOMMAND)
        {
            if (GetMouse(0).bHeld) { needs_update = true; }
            if (GetKey(menu_pause).bPressed) core::game_state = core::PLAYING;
            if (GetKey(menu_inventory).bPressed) core::game_state = core::INVENTORY;
            if (GetKey(menu_blueprint).bPressed) core::game_state = core::BLUEPRINT;
            if (GetKey(ui_left).bPressed || GetKey(player_left).bPressed) { if (core::grid_subdivision > 1) core::grid_subdivision /= 2; needs_update = true; }
            if (GetKey(ui_right).bPressed || GetKey(player_right).bPressed) { if (core::grid_subdivision < 8) core::grid_subdivision *= 2; needs_update = true; }
            if (GetKey(toggle_grid).bPressed) { core::show_grid = !core::show_grid; needs_update = true; }
            if (iSystem::player.state == iSystem::player.DEAD) return;
            if (CtrlKey() && GetKey(olc::Key::V).bPressed) { iSystem::PasteBlueprints(GetOffsetX(), GetOffsetY()); needs_update = true; }
            if (GetKey(ui_select).bPressed)
            { iSystem::world.SettleTiles(iSystem::player.x-(core::width), iSystem::player.y-(core::height), core::width*2, core::height*2); needs_update = true; }
            if (GetKey(menu_command).bReleased)
            { core::sub_state = core::psCOMMAND; iSystem::command_label.text = ""; iSystem::command_label.cursor = 0; }
            olc::Pixel test0 = GetDrawTarget()->GetPixel(0, 0); olc::Pixel test1 = GetDrawTarget()->GetPixel(core::width/2, core::height/2);
            if (test0 == blueprint_color || test1 == panel_color) { needs_update = true; }
            if (GetKey(ui_xray).bHeld) { xrays = true; }
            if (GetKey(ui_xray).bReleased) { needs_update = true; }
            HotbarInput(); HotbarScroll(); UseHotbar();
        }
        if (core::sub_state == core::psCOMMAND)
        {
            std::string c = GetCharacter();
            if (GetKey(ui_up).bPressed)
            { if (script::cmd_index > 0) { script::cmd_index--; iSystem::command_label.text = script::cmds[script::cmd_index]; } }
            if (GetKey(ui_down).bPressed)
            { if (script::cmd_index < script::max_cmds-1) { script::cmd_index++; iSystem::command_label.text = script::cmds[script::cmd_index]; } }
            
            if (c != "") { iSystem::command_label.Update(c); needs_update = true; }
            if (GetKey(ui_select).bPressed)
            {
                script::EvaluateCommand(iSystem::command_label.text);
                script::cmd_index=8; iSystem::command_label.text=""; iSystem::command_label.cursor=0; needs_update=true;
            }
            if (GetKey(menu_pause).bPressed)
            { core::sub_state = core::isTILES; iSystem::command_label.text = ""; iSystem::command_label.cursor = 0; needs_update = true; }
            HotbarScroll(); UseHotbar();
        }
        if (needs_update) { DrawSky(); DrawTerrain(); DrawPlayer(); }
        if (core::sub_state == core::psCOMMAND)
        {
            DrawLine(0, core::height-4, core::width, core::height-4, border_color);
            FillRect(0, core::height-3, core::width, 3, panel_color); DrawLabel(iSystem::command_label);
        }
        if (xrays) { DrawXRay(); }
        DrawHUD();
    }

    void StateBlueprint()
    {
        const int cols = 11; const int rows = 11;
        const int x_margin = 6; const int y_margin = 26;
        if (tile_y > tTile::total_tiles/cols) { tile_y = tTile::total_tiles/cols; }
        int tile_value = tile_y*cols;
        // Background
        Clear(blueprint_color);
        DrawPanel(x_margin-2, y_margin-6, 114, 120);
        // Buttons
        Button clear_print = Button(); clear_print.Setup(124, 134, 32, 6, 0.5, "Clear"); DrawButton(clear_print);
        Button name_print = Button();   name_print.Setup(156, 134, 32, 6, 0.5, "Name"); DrawButton(name_print);
        Button save_print = Button();   save_print.Setup(188, 134, 32, 6, 0.5, "Save"); DrawButton(save_print);
        Button load_print = Button();   load_print.Setup(220, 134, 32, 6, 0.5, "Load"); DrawButton(load_print);
        // Tiles
        Button buttons[cols*rows];
        SetPixelMode(olc::Pixel::ALPHA);
        for (int y = 0; y < rows; y++)
        {
            for (int x = 0; x < cols; x++)
            {
                int tile_type = tTool::GetType(tile_value);
                if (tile_value < tTile::total_tiles)
                {
                    Button b = Button();
                    b.Setup((x*10)+x_margin, (y*10)+y_margin, 9, 9, 1.0, std::to_string(tile_value));
                    buttons[y*cols+x] = b;
                    DrawIcon((x*10)+x_margin+1, (y*10)+y_margin+1, tile_type, tile_value);
                }
                tile_value++;
            }
        }
        SetPixelMode(olc::Pixel::NORMAL);
        // Select Tile
        int hovered_value = -1;
        for (int y = 0; y < rows; y++)
        {
            for (int x = 0; x < cols; x++)
            {
                Button b = buttons[y*cols+x];
                if (b.IsColliding())
                {
                    hovered_value = y*cols+x+(tile_y*11);
                    DrawRect(b.x, b.y, b.width, b.height, select_color);
                    if (GetMouse(0).bReleased)
                    {
                        iSystem::player.hotbar[core::selected_hotbar][0] = itemID::TILE;
                        iSystem::player.hotbar[core::selected_hotbar][1] = std::stoi(b.text);
                    }
                }
            }
        }
        // Hotbar
        SetPixelMode(olc::Pixel::ALPHA);
        int icon_size = icon.size+2;
        for (int i = 0; i < 9; i++)
        {
            int x = i*(icon_size+3)+4;
            DrawRect(x, 4, icon_size, icon_size, hud_color);
            if (iSystem::player.hotbar[i][0] == itemID::TILE)
            { int tile_value = iSystem::player.hotbar[i][1]; int tile_type = tTool::GetType(tile_value); DrawIcon(x+1, 5, tile_type, tile_value); }
            if (i == core::selected_hotbar) { DrawRect(x, 4, icon_size, icon_size, hud_select_color); }
        }
        SetPixelMode(olc::Pixel::NORMAL);
        //
        if (hovered_value >= 0 && hovered_value < tTile::total_tiles) DrawTileName(GetMouseX()+4, GetMouseY(), hovered_value);
        if (GetKey(menu_pause).bReleased) { core::game_state = core::PAUSED; }
        if (GetKey(player_up).bReleased || GetMouseWheel() > 0) { if (tile_y > 0) tile_y--; }
        if (GetKey(player_down).bReleased || GetMouseWheel() < 0) { if (tile_y < tTile::total_tiles/cols) tile_y++; }
        if (GetKey(ui_left).bPressed || GetKey(player_left).bPressed) { if (core::grid_subdivision > 1) core::grid_subdivision /= 2; }
        if (GetKey(ui_right).bPressed || GetKey(player_right).bPressed) { if (core::grid_subdivision < 8) core::grid_subdivision *= 2; }
        if (GetKey(toggle_grid).bPressed) { core::show_grid = !core::show_grid; }
        // Flood Fill
        if (ShiftKey() && GetMouse(0).bPressed)
        {
            int _x = GetMouseX() - 125; int _y = GetMouseY() - 4;
            if (GetMouseX() > 124 && GetMouseX() < 253 && GetMouseY() > 3 && GetMouseY() < 132)
            { iSystem::blueprints.FloodFill(_x, _y, iSystem::player.hotbar[core::selected_hotbar][1]);}
        }
        // Place Tiles
        else if (GetMouse(0).bHeld && !ShiftKey())
        {
            if (GetMouseX() > 124 && GetMouseX() < 253 && GetMouseY() > 3 && GetMouseY() < 132)
            { int _x = core::mouse_x - 125; int _y = core::mouse_y - 4; iSystem::blueprints.matrix[_y*128+_x] = iSystem::player.hotbar[core::selected_hotbar][1]; }
            if (clear_print.IsColliding()) { iSystem::blueprints.ClearMatrix(); }
            if (name_print.IsColliding()) { core::game_state = core::NAME_BLUEPRINT; }
            if (save_print.IsColliding()) { iSystem::blueprints.SaveData(); }
            if (load_print.IsColliding()) { core::game_state = core::LOAD_BLUEPRINT; }
        }
        // Draw Blueprint
        SetPixelMode(olc::Pixel::ALPHA);
        for (int y = 0; y < 128; y++)
        {
            for (int x = 0; x < 128; x += 4)
            {
                    int v1 = iSystem::blueprints.matrix[y*128+x];
                    int v2 = iSystem::blueprints.matrix[y*128+(x+1)];
                    int v3 = iSystem::blueprints.matrix[y*128+(x+2)];
                    int v4 = iSystem::blueprints.matrix[y*128+(x+3)];
                    Draw(x+125, y+4,   olc::Pixel(uint8_t(tTile::R[v1]), uint8_t(tTile::G[v1]), uint8_t(tTile::B[v1]), tTile::A[v1]));
                    Draw(x+126, y+4, olc::Pixel(uint8_t(tTile::R[v2]), uint8_t(tTile::G[v2]), uint8_t(tTile::B[v2]), tTile::A[v2]));
                    Draw(x+127, y+4, olc::Pixel(uint8_t(tTile::R[v3]), uint8_t(tTile::G[v3]), uint8_t(tTile::B[v3]), tTile::A[v3]));
                    Draw(x+128, y+4, olc::Pixel(uint8_t(tTile::R[v4]), uint8_t(tTile::G[v4]), uint8_t(tTile::B[v4]), tTile::A[v4]));
            }
        }
        // Grid
        if (core::show_grid)
        {
            int size = iSystem::world.chunk_size; int sub = size/core::grid_subdivision;
            for (int y = 0; y < 128; y += sub) { DrawLine({125, y+4}, {252, y+4}, olc::Pixel(grid_color)); }
            for (int x = 0; x < 128; x += sub) { DrawLine({x+125, 4}, {x+125, 131}, olc::Pixel(grid_color)); }
        }
        SetPixelMode(olc::Pixel::NORMAL); HotbarInput();
    }

    void StateLoadBlueprint()
    {
        std::vector<Button> buttons;
        int _y = core::height/2-64;
        int name_size = iSystem::blueprints.names.size();
        int limit = std::min(name_size, 8);
        DrawPanel(core::width/2-34, _y-2, 68, 132);
        for (int i = 0; i < limit; i++)
        { Button b = Button(); b.Setup(core::width/2-32, i*16+_y, 64, 16, 0.5, iSystem::blueprints.names[i+blueprint_y]); buttons.push_back(b); }
        for (int i = 0; i < limit; i++)
        {
            DrawButton(buttons[i]);
            if (buttons[i].IsColliding())
            { if (GetMouse(0).bPressed) { iSystem::blueprints.selected = buttons[i].text; iSystem::blueprints.LoadData(); core::game_state = core::BLUEPRINT; } }
        }
        if (GetKey(player_up).bReleased) { if (blueprint_y > 0) blueprint_y--; }
        if (GetKey(player_down).bReleased) { if (blueprint_y < std::max(name_size-8, 0)) blueprint_y++; }
        if (GetKey(menu_pause).bReleased) { core::game_state = core::BLUEPRINT; }
    }

    void StateNameBlueprint()
    {
        int lx = iSystem::blueprint_label.x;
        int ly = iSystem::blueprint_label.y;
        int text_size = iSystem::blueprint_label.Size();
        Button label = Button(); label.Setup(lx, ly, 64, 16, 0.5, iSystem::blueprint_label.text); DrawButton(label);
        int cx = ((lx + ((label.width/2.0))-(float(text_size)*(4.0*iSystem::blueprint_label.font)))) + (4.0*iSystem::blueprint_label.cursor);
        iSystem::blueprint_label.Update(GetCharacter());
        DrawPanel(core::width/2-36, core::height/2-10, 72, 20);
        DrawLine(cx, ly+10, cx+4, ly+10);
        if (GetKey(ui_select).bPressed)
        {
            iSystem::blueprints.selected = iSystem::blueprint_label.text; iSystem::blueprint_label.text = "";
            iSystem::blueprint_label.cursor = 0; core::game_state = core::BLUEPRINT;
        }
        if (GetKey(menu_pause).bReleased) { core::game_state = core::BLUEPRINT; }
    }

    void StateCrafting()
    {
        if (GetKey(menu_pause).bPressed) core::game_state = core::PAUSED;
        if (GetKey(menu_inventory).bPressed) core::game_state = core::PLAYING;
        HotbarInput(); DrawHUD();
    }

    void StateInventory()
    {
        DrawPanel(44, 20, 168, 104);
        DrawLine(45, 36, 211, 36, button_color);
        if (GetKey(menu_pause).bPressed) core::game_state = core::PAUSED;
        if (GetKey(menu_inventory).bPressed) core::game_state = core::PLAYING;
        if      (core::sub_state == core::isTILES)   { DrawTiles();      DrawLine(48,  34, 76,  34, button_color); }
        else if (core::sub_state == core::isWALLS)   { DrawWalls();      DrawLine(81,  34, 109, 34, button_color); }
        else if (core::sub_state == core::isCRAFT)   { DrawCrafting();   DrawLine(114, 34, 142, 34, button_color); }
        else if (core::sub_state == core::isTOOLS)   { DrawTools();      DrawLine(147, 34, 175, 34, button_color); }
        else if (core::sub_state == core::isEFFECTS) { DrawEffects();    DrawLine(180, 34, 208, 34, button_color); }
        if (GetKey(player_up).bReleased || GetMouseWheel() > 0)
        { if (core::sub_state == core::isTILES && tile_y > 0) tile_y--; }
        if (GetKey(player_down).bReleased || GetMouseWheel() < 0)
        { if (core::sub_state == core::isTILES && tile_y < tTile::total_tiles/16) tile_y++; }
        Button btiles = Button();     btiles.Setup(48, 24, 28, 8, 0.25, "Tiles");
        Button bwalls = Button();     bwalls.Setup(81, 24, 28, 8, 0.25, "Walls");
        Button bcraft = Button();     bcraft.Setup(114, 24, 28, 8, 0.25, "Craft");
        Button bwands = Button();     bwands.Setup(147, 24, 28, 8, 0.25, "Tools");
        Button beffects = Button(); beffects.Setup(180, 24, 28, 8, 0.25, "Effects");
        DrawButton(btiles); DrawButton(bwalls); DrawButton(bwands); DrawButton(beffects); DrawButton(bcraft);
        if (bwands.IsColliding())   { if (GetMouse(0).bReleased) core::sub_state = core::isTOOLS;   }
        if (beffects.IsColliding()) { if (GetMouse(0).bReleased) core::sub_state = core::isEFFECTS; }
        if (btiles.IsColliding())   { if (GetMouse(0).bReleased) core::sub_state = core::isTILES;   }
        if (bwalls.IsColliding())   { if (GetMouse(0).bReleased) core::sub_state = core::isWALLS;   }
        if (bcraft.IsColliding())   { if (GetMouse(0).bReleased) core::sub_state = core::isCRAFT;   }
        HotbarInput(); DrawHUD();
    }

    void StateGameLoop(float fElapsedTime)
    {

        if (GetKey(menu_pause).bPressed) core::game_state = core::PAUSED;
        if (GetKey(menu_inventory).bPressed) core::game_state = core::INVENTORY;
        if (CtrlKey() && GetKey(olc::Key::V).bPressed) { iSystem::PasteBlueprints(GetOffsetX(), GetOffsetY()); }
        // Vertical Movement
        if (GetKey(player_up).bHeld)
        {
            int x = iSystem::player.x; int y = iSystem::player.y;
            if ((!tTool::BodyCollision(x, y-iSystem::player.height-1) && !tTool::BodyCollision(x-1, y-iSystem::player.height-1)) &&
                (iSystem::player.jp > 0) && (iSystem::player.y > iSystem::player.height) )
            {
                iSystem::player.jp--;
                iSystem::player.vy = -1;
                iSystem::player.state = iSystem::player.JUMP;
                iSystem::player.can_move = true;
            }
            else { iSystem::player.vy = 0; }
        }
        if (GetKey(player_up).bReleased) { iSystem::player.vy = 0; iSystem::player.state = iSystem::player.IDLE; }
        if (GetKey(player_down).bHeld) { iSystem::player.AutoDrop(); }
        // Horizontal Movement
        if (GetKey(player_left).bHeld && iSystem::player.x > core::width/2)
        {
            int _x = core::width/2+4;  int _y = core::height/2+8;
            int x = iSystem::player.x; int y = iSystem::player.y;
            if (iSystem::player.state != iSystem::player.FALL && iSystem::player.state != iSystem::player.JUMP) iSystem::player.vy = 0;
            if (!tTool::FootCollision(x-3, y) ) { iSystem::player.vx = -1; }
            if (iSystem::player.AutoJump(-1)) { iSystem::player.Move(-1, -1); }//{ iSystem::player.vx = -1; iSystem::player.Move(0, -1); }
            if (!GetKey(player_up).bHeld && iSystem::player.state != iSystem::player.FALL) { iSystem::player.state = iSystem::player.WALK; }
            iSystem::player.direction = -1;
        }
        if (GetKey(player_right).bHeld && iSystem::player.x < tCell::width-(core::width/2))
        {
            int _x = core::width/2+4;  int _y = core::height/2+8;
            int x = iSystem::player.x; int y = iSystem::player.y;
            if (iSystem::player.state != iSystem::player.FALL && iSystem::player.state != iSystem::player.JUMP) iSystem::player.vy = 0;
            if (!tTool::FootCollision(x+1, y) ) { iSystem::player.vx = 1; }
            if (iSystem::player.AutoJump(1)) { iSystem::player.Move(1, -1); }//{ iSystem::player.vx = 1; iSystem::player.Move(0, -1); }
            if (!GetKey(player_up).bHeld && iSystem::player.state != iSystem::player.FALL) { iSystem::player.state = iSystem::player.WALK; }
            iSystem::player.direction = 1;
        }
        if (GetKey(player_left).bReleased) { iSystem::player.vx = 0; }
        if (GetKey(player_right).bReleased) { iSystem::player.vx = 0; }
        if (GetKey(toggle_grid).bPressed) { core::show_grid = !core::show_grid; }
        // Hotbar Stuff
        HotbarInput(); HotbarScroll(); UseHotbar();
        // Update World
        if (core::game_tick > core::tick_delay)
        {
            core::game_tick -= core::tick_delay;
            iSystem::UpdateDimension();
            DrawSky(); DrawTerrain();
        }
        iSystem::Update(fElapsedTime);
        // Update Player
        if (iSystem::player.state == iSystem::player.DEAD) { if (GetKey(menu_pause).bPressed) core::game_state = core::PAUSED; return; }
        if (!iSystem::player.IsColliding()) { iSystem::player.Move(iSystem::player.vx, iSystem::player.vy); }

        DrawPlayer(); DrawParticles(fElapsedTime); DrawHUD();
        // Update Camera
        iSystem::camera.Update( iSystem::player.x-(iSystem::player.height/2), iSystem::player.y-(iSystem::player.height-1));
        // End Frame
        core::game_tick += fElapsedTime;
    }

    void StateExit()
    { iSystem::player.SaveData(); iSystem::world.SaveWorldData(); core::running = false; }

    //
    /// PGE Hooks
    //

    bool OnUserCreate() override
    { InitializeGame(); return true; }

    bool OnUserUpdate(float fElapsedTime) override
    {
        switch (core::game_state)
        {
            case core::PLAYING        : { StateGameLoop(fElapsedTime); } break;
            case core::PAUSED         : {               StatePaused(); } break;
            case core::BLUEPRINT      : {            StateBlueprint(); } break;
            case core::NAME_BLUEPRINT : {        StateNameBlueprint(); } break;
            case core::LOAD_BLUEPRINT : {        StateLoadBlueprint(); } break;
            case core::CRAFTING       : {             StateCrafting(); } break;
            case core::INVENTORY      : {            StateInventory(); } break;
            case core::SAVING         : {               StateSaving(); } break;
            case core::MAKE_WORLD     : {            StateMakeWorld(); } break;
            case core::LOAD_WORLD     : {            StateLoadWorld(); } break;
            case core::CUSTOM         : {               StateCustom(); } break;
            case core::SETTINGS       : {             StateSettings(); } break;
            case core::TITLE          : {                StateTitle(); } break;
            case core::CREDITS        : {              StateCredits(); } break;
            case core::EXIT           : {                 StateExit(); } break;
        }
        UpdateMouse();
        return core::running;
    }
};
