#define OLC_PGE_APPLICATION
#include "../../lib/olcPixelGameEngine.h"

class Game : public olc::PixelGameEngine
{
public:
    
    Game()
    {
        sAppName = core::game_title;
    }

public:

    bool OnUserCreate() override
    {
        InstallGame();
        for (int i = 0; i < new_world::generation_steps; i++)
        {
            new_world::generation_param[i][new_world::pITER] = 1;
        }
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
        switch (game_state)
        {
            case PLAYING : GameLoop(fElapsedTime); break;
            case PAUSED : GamePaused(); break;
            case INVENTORY : GameInventory(); break;
            case LOADING : DrawLoading(); break;
            case CUSTOM : DrawCustom(); break;
            case TITLE : DrawTitle(); break;
            case EXIT : {SavePlayerData(); SaveWorldData();running = false;} break;
        }
        return running;
    }
};

namespace engine
{
    Game bitmapper;

    bool Start()
    {
        if (bitmapper.Construct(core::width, core::height, core::resolution, core::resolution))
        {
            bitmapper.Start();
        }

        return 0;
    }

    int GetMouseX() { return bitmapper.GetMouseX(); }
    int GetMouseY() { return bitmapper.GetMouseY(); }

    void Draw(x, y, olc::Pixel c)       { bitmapper.Draw(x, y, c); }
    
    void DrawLine(x, y, olc::Pixel c)   { bitmapper.DrawLine(x, y, c); }
    
    void DrawRect(x, y, olc::Pixel c)   { bitmapper.DrawRect(x, y, c); }
    void FillRect(x, y, olc::Pixel c)   { bitmapper.FillRect(x, y, c); }
    
    void DrawCircle(x, y, olc::Pixel c) { bitmapper.DrawCircle(x, y, c); }
    void FillCircle(x, y, olc::Pixel c) { bitmapper.FillCircle(x, y, c); }
    
    void DrawText(x, y, olc::pixel c)   { bitmapper.DrawStringDecal(x, y, text, c); }

}
