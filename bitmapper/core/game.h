#define OLC_PGE_APPLICATION
#include "../../lib/olcPixelGameEngine.h"

#include "../included.h"

class Game : public olc::PixelGameEngine
{
public:
	Game()
	{
		sAppName = core::game_title;
	}

public:

    enum ITEM_TYPES
    {
        itNONE,
        itTILE,
        itWAND,
    };

    char selected_hotbar = 0;
    char selected_tile = 0;
    char selected_wand = 0;
    int input_value = 0;
    char save_slot = 0;

    int world_width = 4096;
    int world_height = 2048;

    Icon icon = Icon();

    olc::Pixel hud_color = olc::Pixel(64, 64, 64);
    olc::Pixel hud_select_color = olc::Pixel(255, 255, 255);
    olc::Pixel grid_color = olc::Pixel(0, 0, 0, 64);
    olc::Pixel text_color = olc::Pixel(255, 255, 255);
    olc::Pixel panel_color = olc::Pixel(10, 10, 10);
    olc::Pixel border_color = olc::Pixel(80, 80, 80);
    olc::Pixel button_color = olc::Pixel(32, 32, 32);
    olc::Pixel select_color = olc::Pixel(64, 64, 64);

    void InstallGame()
    {
        tTile::LoadTileData();
        dataTool::GenerateDirectoryTree();
    }



    //
    //
    //

    void DrawButton(Button b)
    {
        DrawStringDecal({ b.TextX(),b.TextY() }, b.text, text_color, {b.font, b.font});
        if (b.IsColliding(GetMouseX(), GetMouseY()))
        { DrawRect(b.x, b.y, b.width, b.height, select_color); return; }
        DrawRect(b.x, b.y, b.width, b.height, button_color);
    }

    void ProgressBar(int x, int y, int minv, int maxv, int W, int R=255, int G=255, int B=255, int r=64, int g=64, int b=64)
    {
        float completed = float(minv)/float(maxv);
        int x2 = W*completed;
        DrawLine(x, y, x+W, y, olc::Pixel(r, g, b));
        DrawLine(x, y, x+x2, y, olc::Pixel(R, G, B));
    }

    void HotbarInput()
    {
        if (GetKey(olc::Key::K1).bPressed) {selected_hotbar = 0;}
        if (GetKey(olc::Key::K2).bPressed) {selected_hotbar = 1;}
        if (GetKey(olc::Key::K3).bPressed) {selected_hotbar = 2;}
        if (GetKey(olc::Key::K4).bPressed) {selected_hotbar = 3;}
        if (GetKey(olc::Key::K5).bPressed) {selected_hotbar = 4;}
        if (GetKey(olc::Key::K6).bPressed) {selected_hotbar = 5;}
        if (GetKey(olc::Key::K7).bPressed) {selected_hotbar = 6;}
        if (GetKey(olc::Key::K8).bPressed) {selected_hotbar = 7;}
        if (GetKey(olc::Key::K9).bPressed) {selected_hotbar = 8;}
    }


    //
    //
    //

    void DrawChunkGrid()
    {
        if (!core::show_grid) return;
        //core::grid_subdivision
        int _x = iSystem::player.x % (iSystem::world.chunk_size/core::grid_subdivision);
        int _y = iSystem::player.y % (iSystem::world.chunk_size/core::grid_subdivision);
        for (int y = 0; y < core::height+iSystem::world.chunk_size; y += iSystem::world.chunk_size/core::grid_subdivision)
        {
            DrawLine({0-_x, y-_y}, {core::width-_x+iSystem::world.chunk_size, y-_y}, olc::Pixel(grid_color));
        }
        for (int x = 0; x < core::width+iSystem::world.chunk_size; x += iSystem::world.chunk_size/core::grid_subdivision)
        {
            DrawLine({x-_x, 0-_y}, {x-_x, core::height-_y+iSystem::world.chunk_size}, olc::Pixel(grid_color));
        }
    }

    void DrawIcon(int x, int y, int tile_type, int tile_value)
    {
        int *img;
        switch (tile_type)
        {
            case tTile::GAS      : { img = icon.gas;      } break;
            case tTile::PLASMA   : { img = icon.plasma;   } break;
            case tTile::FUME     : { img = icon.fume;     } break;
            case tTile::FLUID    : { img = icon.fluid;    } break;
            case tTile::GRAIN    : { img = icon.grain;    } break;
            case tTile::GEL      : { img = icon.gel;      } break;
            case tTile::SOLID    : { img = icon.solid;    } break;
            case tTile::LOOSE    : { img = icon.loose;    } break;
            case tTile::BOOM     : { img = icon.boom;     } break;
            case tTile::LOGIC    : { img = icon.logic;    } break;
            case tTile::GIZMO    : { img = icon.gizmo;    } break;
            case tTile::PLATFORM : { img = icon.platform; } break;
            case tTile::PLUMBING : { img = icon.plumbing; } break;
            case tTile::PLANT    : { img = icon.plant;    } break;
            case tTile::CRITTER  : { img = icon.critter;  } break;
        }
        float R = float(tTile::R[tile_value]);
        float G = float(tTile::G[tile_value]);
        float B = float(tTile::B[tile_value]);
        int A = tTile::A[tile_value];
        for (int iy = 0; iy < icon.size; iy++)
        {
            for (int ix = 0; ix < icon.size; ix++)
            {
                int index_value = *(img+iy*icon.size+ix);//[iy*icon.size+ix];
                float v = (0.125*float(index_value));
                if (index_value > 0) Draw(ix+x, iy+y, olc::Pixel(int(R*v), int(G*v), int(B*v), A));
            }
        }
    }

    void DrawWands()
    {
        int cols = 16;
        int rows = 8;
        int x_margin = 48;
        int y_margin = 32;
        int wand_value = 0;

        Button buttons[cols*rows];

        FillRect({x_margin-3, y_margin-3}, {167, 87}, panel_color);
        DrawRect({x_margin-4, y_margin-4}, {168, 88}, border_color);
        SetPixelMode(olc::Pixel::ALPHA);
        for (int y = 0; y < rows; y++)
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
                }
                wand_value++;
            }
        }
        SetPixelMode(olc::Pixel::NORMAL);

        for (int y = 0; y < rows; y++)
        {
            for (int x = 0; x < cols; x++)
            {
                Button b = buttons[y*cols+x];
                if (b.IsColliding(GetMouseX(), GetMouseY()))
                {
                    DrawRect(b.x, b.y, b.width, b.height, select_color);
                    if (GetMouse(0).bReleased)
                    {
                        iSystem::player.hotbar[selected_hotbar][0] = itWAND;
                        iSystem::player.hotbar[selected_hotbar][1] = std::stoi(b.text);
                    }
                }
            }
        }
    }

    void DrawInventory()
    {
        int cols = 16;
        int rows = 8;
        int x_margin = 48;
        int y_margin = 32;
        int tile_value = 0;

        Button buttons[cols*rows];

        FillRect({x_margin-3, y_margin-3}, {167, 87}, panel_color);
        DrawRect({x_margin-4, y_margin-4}, {168, 88}, border_color);
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
        for (int y = 0; y < rows; y++)
        {
            for (int x = 0; x < cols; x++)
            {
                Button b = buttons[y*cols+x];
                if (b.IsColliding(GetMouseX(), GetMouseY()))
                {
                    DrawRect(b.x, b.y, b.width, b.height, select_color);
                    if (GetMouse(0).bReleased)
                    {
                        iSystem::player.hotbar[selected_hotbar][0] = itTILE;
                        iSystem::player.hotbar[selected_hotbar][1] = std::stoi(b.text);
                    }
                }
            }
        }
    }

    void DrawSky()
    {
        if (iSystem::player.status != iSystem::player.TRIP) Clear(olc::Pixel(iSystem::sky.R, iSystem::sky.G, iSystem::sky.B));
        
        if (iSystem::sky.starlight >= 0)
        {
            SetPixelMode(olc::Pixel::ALPHA);
            for (int i = 0; i < iSystem::sky.starcount; i += 4)
            {
                int value = rand()%220+35;
                Draw(iSystem::sky.stars[i][0], iSystem::sky.stars[i][1], olc::Pixel(value, value, value, 255-iSystem::sky.starlight));
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
            int x = iSystem::sky.clouds[i][0];
            int y = iSystem::sky.clouds[i][1];
            FillCircle(x, y, iSystem::sky.clouds[i][2], olc::Pixel(iSystem::sky.r, iSystem::sky.g, iSystem::sky.b, 4+(8*iSystem::sky.time)));
        }
        if (iSystem::sky.humidity > iSystem::sky.cloudcount/4)
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
        int X = iSystem::player.x - (core::width/2);
        int Y = iSystem::player.y - (core::height/2);
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

                    Draw(x, y, olc::Pixel(
                                int(tTile::R[v1]*s1),
                                int(tTile::G[v1]*s1),
                                int(tTile::B[v1]*s1),
                                tTile::A[v1])
                            );

                    Draw(x+1, y, olc::Pixel(
                                int(tTile::R[v2]*s2),
                                int(tTile::G[v2]*s2),
                                int(tTile::B[v2]*s2),
                                tTile::A[v2])
                            );
                    Draw(x+2, y, olc::Pixel(
                                int(tTile::R[v3]*s3),
                                int(tTile::G[v3]*s3),
                                int(tTile::B[v3]*s3),
                                tTile::A[v3])
                            );
                    Draw(x+3, y, olc::Pixel(
                                int(tTile::R[v4]*s4),
                                int(tTile::G[v4]*s4),
                                int(tTile::B[v4]*s4),
                                tTile::A[v4])
                            );
                }
            }
        }
        DrawChunkGrid();
        SetPixelMode(olc::Pixel::NORMAL);
    }

    bool PlayerVsWorld()
    {
        bool colliding = false;
        int f = iSystem::player.animations[iSystem::player.anim][iSystem::player.frame];
        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                int index = y*8+x;
                if (iSystem::player.image[f][index] > 0)
                {
                    int _x = x+int(core::width/2)-4;
                    int _y = y+int(core::height/2)-7;
                    if ( tTool::IsColliding((iSystem::player.x+iSystem::player.vx)+(x-4), (iSystem::player.y+iSystem::player.vy)+(y-7)) )
                    {
                        Draw(_x, _y, olc::RED);
                        colliding = true;
                    }
                }
            }
        }
        return colliding;
    }

    void DrawPlayer()
    {
        int r = 0;
        int g = 0;
        int b = 0;
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
                    int R = std::min((((v*32)+r)/2), 255);
                    int G = std::min((((v*32)+g)/2), 255);
                    int B = std::min((((v*32)+b)/2), 255);
                    int _x = x+int(core::width/2)-4;
                    int _y = y+int(core::height/2)-7;
                    Draw(_x, _y, olc::Pixel(R, G, B));
                    if ( tTool::IsColliding((iSystem::player.x+iSystem::player.vx)+(x-4), (iSystem::player.y+iSystem::player.vy)+(y-7)) )
                    { Draw(_x+iSystem::player.vx, _y+iSystem::player.vy, olc::YELLOW); }
                    if ( tTool::IsColliding(iSystem::player.x+(x-4), iSystem::player.y+(y-7)) )
                    { Draw(_x, _y, olc::RED); }
                }
            }
        }
    }

    void DrawParticles(float delta)
    {
        for (int p = 0; p < (iSystem::particles.size()); p++)
        {
            float x = iSystem::particles[p].x;
            float y = iSystem::particles[p].y;
            iSystem::UpdateParticle(delta, p, x, y);
            if (iSystem::particles[p].duration > 0.0)
            {
                iSystem::particles[p].duration -= delta;
                Draw(x-(iSystem::player.x-(core::width/2)),
                        y-(iSystem::player.y-(core::height/2)),
                        olc::Pixel(iSystem::particles[p].r, iSystem::particles[p].g, iSystem::particles[p].b, iSystem::particles[p].a));
            }
            else
            {
                iSystem::particles.erase(iSystem::particles.begin()+p);
            }
        }
    }

    void DrawHUD()
    {
        float font = 0.25;

        int lookindex = (iSystem::player.y-(core::height/2)+GetMouseY())*tCell::width+(iSystem::player.x-(core::width/2)+GetMouseX());

        std::string health = std::to_string(iSystem::player.hp)+"/"+std::to_string(iSystem::player.HP);
        std::string lookingat = "Air";
        std::string selectedtile = tTile::NAME[selected_tile];
        std::string selectedcount = "";
        std::string collision_at = std::to_string(tTool::Collision((iSystem::player.x-(core::width/2)+GetMouseX()), (iSystem::player.y-(core::height/2)+GetMouseY())));

        if ( ( (lookindex < tCell::width*tCell::height) && lookindex > 0) && (tCell::matrix[lookindex] < tTile::total_tiles) )
        {
            lookingat = tTile::NAME[tCell::matrix[lookindex]];
        }
        if (iSystem::player.inventory.HasItem(selected_tile))
        {
            selectedcount = std::to_string(iSystem::player.inventory.data[selected_tile]);
        }

        ProgressBar(4, 2, iSystem::player.hp, iSystem::player.HP, 32, 255, 0, 0, 64, 0, 0);
        ProgressBar(4, 4, iSystem::player.jp, iSystem::player.JP, 32, 0, 255, 0, 0, 64, 0);
        ProgressBar(4, 6, iSystem::player.bp, iSystem::player.BP, 32, 0, 0, 255, 0, 0, 64);
        DrawStringDecal({ 4,8  }, "Looking At: " + lookingat, text_color, { font, font });
        //DrawStringDecal({ 4,12 }, "Selected Tile: " + selectedtile + " " + selectedcount, text_color, { font, font });
        DrawStringDecal({ 4,12 }, "Collision: " + collision_at, text_color, { font, font });
        DrawStringDecal({ 4,16 }, "Day: " + std::to_string(iSystem::sky.day), text_color, { font, font });
        DrawStringDecal({ 4,20 }, "Year: " + std::to_string(iSystem::sky.year), text_color, { font, font });
        //
        int hb_size = icon.size+1;
        int hb_offset = (core::width/2) - hb_size*4.5;
        std::string selected_item = "";
        if (iSystem::player.hotbar[selected_hotbar][0] == itWAND) { selected_item = "Wand"; }
        if (iSystem::player.hotbar[selected_hotbar][0] == itTILE) { selected_item = tTile::NAME[iSystem::player.hotbar[selected_hotbar][1]]; }
        float select_x = (core::width/2)-(selected_item.size());
        DrawStringDecal({ select_x,15 }, selected_item, text_color, { 0.25, 0.25 });
        SetPixelMode(olc::Pixel::ALPHA);
        for (int i = 0; i < 9; i++)
        {
            int x = i*hb_size+hb_offset;
            DrawRect(x, 2, hb_size, hb_size, hud_color);
            
            if (iSystem::player.hotbar[i][0] == itWAND)
            {
                int tile_value = iSystem::player.hotbar[i][1];
                float R = float(tTile::R[tile_value]);
                float G = float(tTile::G[tile_value]);
                float B = float(tTile::B[tile_value]);
                for (int iy = 0; iy < icon.size; iy++)
                {
                    for (int ix = 0; ix < icon.size; ix++)
                    {
                        int index_value = icon.wand[iy*icon.size+ix];
                        float v = (0.25*float(index_value));
                        if (index_value > 0) Draw(ix+x+1, iy+3, olc::Pixel(int(R*v), int(G*v), int(B*v)));
                    }
                }
            }
            if (iSystem::player.hotbar[i][0] == itTILE)
            {
                int tile_value = iSystem::player.hotbar[i][1];
                int tile_type = tTool::GetType(tile_value);
                DrawIcon(x+1, 3, tile_type, tile_value);
            }
        }
        SetPixelMode(olc::Pixel::NORMAL);
        DrawRect(selected_hotbar*hb_size+hb_offset, 2, hb_size, hb_size, hud_select_color);
    }

    void DrawTitle()
    {
        Clear(olc::BLACK);

        float Tx = (core::width/2)-((sAppName.size()*16)/2);
        float Ty = (core::height*0.25);

        float Nx = (core::width/2)-50;
        float Lx = (core::width/2)+4;
        float By = (core::height*0.75);

        DrawStringDecal({ Tx,Ty }, sAppName, text_color, { 2.0, 2.0 });
        
        Button bNew = Button();
        bNew.Setup(Nx, By, 48, 16, 1.0, "New");
        Button bLoad = Button();
        bLoad.Setup(Lx, By, 48, 16, 1.0, "Load");

        DrawStringDecal({ bNew.TextX(),bNew.TextY() }, bNew.text, text_color, { 1.0, 1.0 });
        DrawRect(bNew.x, bNew.y, bNew.width, bNew.height, button_color);
        DrawStringDecal({ bLoad.TextX(),bLoad.TextY() }, bLoad.text, text_color, { 1.0, 1.0 });
        DrawRect(bLoad.x, bLoad.y, bLoad.width, bLoad.height, button_color);

        if (bNew.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bNew.x, bNew.y, bNew.width, bNew.height, select_color);
            if (GetMouse(0).bReleased)
            {
                Clear(olc::BLACK);
                core::game_state = core::CUSTOM;
                iSystem::player.Setup();
            }
        }
        if (bLoad.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bLoad.x, bLoad.y, bLoad.width, bLoad.height, select_color);
            if (GetMouse(0).bReleased)
            {
                Clear(olc::BLACK);
                iSystem::player.LoadData();
                //LoadWorldData();
                core::game_state = core::PLAYING;
            }
        }
    }

    void DrawCustom()
    {
        //Clear(olc::BLACK);
        bool can_draw = false;
        std::string info_text = "Hover Over A Button To See Details";
        std::string dtls_text = "";

        // Buttons
        Button bsave     = Button(); bsave.Setup(105, 37, 32, 8, 0.25, "Save");
        Button bload     = Button(); bload.Setup(105, 45, 32, 8, 0.25, "Load");
        Button bclear    = Button(); bclear.Setup(105, 57, 32, 8, 0.25, "Clear");
        Button bconfig   = Button(); bconfig.Setup(105, 65, 32, 8, 0.25, "Preset");
        Button brandom   = Button(); brandom.Setup(105, 73, 32, 8, 0.25, "Random");
        Button bpreview  = Button(); bpreview.Setup(105, 86, 32, 8, 0.25, "Preview");
        Button bgenerate = Button(); bgenerate.Setup(105, 94, 32, 8, 0.25, "Generate");
        Button bminusgs  = Button(); bminusgs.Setup(183, 2, 70, 4, 0.25, "-");
        Button bplusgs   = Button(); bplusgs.Setup(183, 88, 70, 4, 0.25, "+");
        Button bcopy     = Button(); bcopy.Setup(183, 94, 35, 8, 0.25, "Copy");
        Button bpaste    = Button(); bpaste.Setup(218, 94, 35, 8, 0.25, "Paste");
        Button bsave0    = Button(); bsave0.Setup(141, 7, 38, 8, 0.25, "Save 0");
        Button bsave1    = Button(); bsave1.Setup(141, 15, 38, 8, 0.25, "Save 1");
        Button bsave2    = Button(); bsave2.Setup(141, 23, 38, 8, 0.25, "Save 2");
        Button bsave3    = Button(); bsave3.Setup(141, 31, 38, 8, 0.25, "Save 3");
        Button bsave4    = Button(); bsave4.Setup(141, 39, 38, 8, 0.25, "Save 4");
        Button bsave5    = Button(); bsave5.Setup(141, 47, 38, 8, 0.25, "Save 5");
        Button bsave6    = Button(); bsave6.Setup(141, 55, 38, 8, 0.25, "Save 6");
        Button btile     = Button(); btile.Setup(141, 70, 18, 8, 0.25, "Tile");
        Button bmode     = Button(); bmode.Setup(141, 78, 18, 8, 0.25, "Mode");
        Button bdense    = Button(); bdense.Setup(141, 86, 18, 8, 0.25, "Density");
        Button biter     = Button(); biter.Setup(141, 94, 18, 8, 0.25, "Repeat");
        Button bminx     = Button(); bminx.Setup(162, 70, 18, 8, 0.25, "Min X");
        Button bmaxx     = Button(); bmaxx.Setup(162, 78, 18, 8, 0.25, "Max X");
        Button bminy     = Button(); bminy.Setup(162, 86, 18, 8, 0.25, "Min Y");
        Button bmaxy     = Button(); bmaxy.Setup(162, 94, 18, 8, 0.25, "Max Y");
        Button bprobn    = Button(); bprobn.Setup(117, 6, 8, 8, 0.25, "N");
        Button bprobs    = Button(); bprobs.Setup(117, 22, 8, 8, 0.25, "S");
        Button bprobe    = Button(); bprobe.Setup(125, 14, 8, 8, 0.25, "E");
        Button bprobw    = Button(); bprobw.Setup(109, 14, 8, 8, 0.25, "W");

        DrawRect(2, 2, 100, 100, border_color);  // Preview Box
        DrawRect(183, 2, 70, 90, border_color);  // Generation Steps Box
        DrawRect(2, 105, 251, 36, border_color);  // Information Box
        DrawRect(105, 2, 32, 32, border_color);  // Neighbors Box

        DrawButton(bsave); DrawButton(bload);
        DrawButton(bclear); DrawButton(bconfig); DrawButton(brandom);
        DrawButton(bpreview); DrawButton(bgenerate);
        DrawButton(bminusgs); DrawButton(bplusgs);
        DrawButton(bcopy); DrawButton(bpaste);
        DrawButton(bsave0); DrawButton(bsave1); DrawButton(bsave2); DrawButton(bsave3); DrawButton(bsave4); DrawButton(bsave5); DrawButton(bsave6);
        DrawButton(btile); DrawButton(bmode); DrawButton(bdense); DrawButton(biter);
        DrawButton(bminx); DrawButton(bmaxx); DrawButton(bminy); DrawButton(bmaxy);
        DrawButton(bprobn); DrawButton(bprobs); DrawButton(bprobe); DrawButton(bprobw);

        // Numeric Input
        if (GetKey(olc::Key::K0).bPressed)
        { std::string new_value = std::to_string(input_value)+"0"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K1).bPressed)
        { std::string new_value = std::to_string(input_value)+"1"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K2).bPressed)
        { std::string new_value = std::to_string(input_value)+"2"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K3).bPressed)
        { std::string new_value = std::to_string(input_value)+"3"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K4).bPressed)
        { std::string new_value = std::to_string(input_value)+"4"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K5).bPressed)
        { std::string new_value = std::to_string(input_value)+"5"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K6).bPressed)
        { std::string new_value = std::to_string(input_value)+"6"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K7).bPressed)
        { std::string new_value = std::to_string(input_value)+"7"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K8).bPressed)
        { std::string new_value = std::to_string(input_value)+"8"; input_value = std::stoi(new_value); }
        if (GetKey(olc::Key::K9).bPressed)
        { std::string new_value = std::to_string(input_value)+"9"; input_value = std::stoi(new_value); }

        if (GetKey(olc::Key::ENTER).bPressed)
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
        if (GetKey(olc::Key::S).bPressed) { if (new_world::selected_step < new_world::generation_steps-2) new_world::selected_step++; }
        if (GetKey(olc::Key::W).bPressed) { if (new_world::selected_step > 0) new_world::selected_step--; }

        if (GetKey(olc::Key::A).bPressed) { new_world::DecrementParameter(); }
        if (GetKey(olc::Key::D).bPressed) { new_world::IncrementParameter(); }
        // Step Value
        if (bminusgs.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Removes The Selected Generation Step From The List"; //dtls_text = "()";
            if (GetMouse(0).bReleased) { new_world::Remove(); }
        }
        if (bplusgs.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Inserts A Generation Step Into The List"; //dtls_text = "()";
            if (GetMouse(0).bReleased) { new_world::Insert(); }
        }
        // Tile Value
        if (btile.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Material To add To World"; //dtls_text = "()";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pTILE;
        }
        // Density Value
        if (bdense.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability A Material Will Spawn Per Cell"; dtls_text = "(Add Layer, Seed Material)";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pDENSE;
        }
        if (biter.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "How Many Times to Repeat Current Step"; //dtls_text = "()";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pITER;
        }
        // X Values
        if (bminx.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Minimum Width Range Of Effect"; dtls_text = "(0-100 %)";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pMINX;
        }
        if (bmaxx.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Maximum Width Range Of Effect"; dtls_text = "(0-100 %)";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pMAXX;
        }
        // Y values
        if (bminy.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Minimum Height Range Of Effect"; dtls_text = "(0-100 %)";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pMINY;
        }
        if (bmaxy.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Maximum Height Range Of Effect"; dtls_text = "(0-100 %)";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pMAXY;
        }
        // Neighbor Values
        if (bprobn.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That A Northern Neighbor Will Spawn"; //dtls_text = "()";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pPROBN;
        }
        if (bprobs.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That A Southern Neighbor Will Spawn"; //dtls_text = "()";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pPROBS;
        }
        if (bprobe.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That An Eastern Neighbor Will Spawn"; //dtls_text = "()";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pPROBE;
        }
        if (bprobw.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That A Western Neighbor Will Spawn"; //dtls_text = "()";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pPROBW;
        }
        // Mode Value
        if (bmode.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Changes Generation Mode"; //dtls_text = "()";
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pMODE;
        }

        // Clear Values
        if (bclear.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Clears All Generation Data";
            if (GetMouse(0).bReleased) { new_world::ClearData(); }
        }
        // Auto Configure
        if (bconfig.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Standard World Generation"; //dtls_text = "()";
            if (GetMouse(0).bReleased) { new_world::PresetData(); }
        }
        // Randomize Seed
        if (brandom.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Randomizes Game Seed";
            if (GetMouse(0).bReleased) { new_world::RandomizeData(); can_draw = true; }
        }
        // Save
        if (bsave.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Saves Generation Data";
            DrawRect(bsave.x, bsave.y, bsave.width, bsave.height, select_color);
            if (GetMouse(0).bReleased) { new_world::SaveData(std::to_string(save_slot) + ".txt"); }
        }
        // Load
        if (bload.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Loads Generation Data";
            if (GetMouse(0).bReleased) { new_world::LoadData(std::to_string(save_slot) + ".txt"); }
        }
        // Copy
        if (bcopy.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Copies Selected Generation Step";
            if (GetMouse(0).bReleased) { new_world::Copy(); }
        }
        // Paste
        if (bpaste.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Pastes Selected Generation Step";
            if (GetMouse(0).bReleased) { new_world::Paste(); }
        }
        // Generate World
        if (bgenerate.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Generates World And Starts Game";
            if (GetMouse(0).bReleased) { new_world::ReadyWorld(world_width, world_height); }
        }
        // Generate Preview
        if (bpreview.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Updates The Preview Box";
            if (GetMouse(0).bReleased) { new_world::ReadyPreview(); can_draw = true; }
        }
        // Draw Preview
        if (can_draw)
        {
            FillRect(3, 3, 99, 99, olc::Pixel(128, 128, 255));
            SetPixelMode(olc::Pixel::ALPHA);
            for (int y = 0; y < 100; y++)
            {
                for (int x = 0; x < 100; x++)
                {
                    int v = tCell::matrix[y*tCell::width+x];
                    Draw(x+3, y+3, olc::Pixel(
                        tTile::R[v],
                        tTile::G[v],
                        tTile::B[v],
                        tTile::A[v])
                        );
                }
            }
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

    void DrawLoading()
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
                while (!tTool::IsColliding(iSystem::player.x, iSystem::player.y+1)) iSystem::player.Move(0, 1);
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

    void GamePaused()
    {
        if (GetKey(olc::Key::ESCAPE).bPressed) core::game_state = core::PLAYING;
        if (GetKey(olc::Key::TAB).bPressed) core::game_state = core::INVENTORY;
        
        if (GetKey(olc::Key::Q).bPressed) { if (core::grid_subdivision > 1) core::grid_subdivision /= 2; }
        if (GetKey(olc::Key::E).bPressed) { if (core::grid_subdivision < 8) core::grid_subdivision *= 2; }
        if (GetKey(olc::Key::G).bPressed) { core::show_grid = !core::show_grid; }

        if (iSystem::player.state == iSystem::player.DEAD) return;

        if (GetMouse(0).bHeld)
        {
            if (iSystem::player.hotbar[selected_hotbar][0] == itNONE)
            {
            }
            if (iSystem::player.hotbar[selected_hotbar][0] == itWAND)
            {
                if (iSystem::player.wands[selected_wand].can_fire)
                {
                    iSystem::player.wands[selected_wand].Cast();
                    Effect e = iSystem::player.wands[selected_wand].effects[iSystem::player.wands[selected_wand].current_effect];
                    iSystem::SpawnParticle(float(GetMouseX()), float(GetMouseY()), e);
                }
            }
            int index = (GetMouseY()+(iSystem::player.y-(core::height/2)))*tCell::width+(GetMouseX()+(iSystem::player.x-(core::width/2)));
            int tile = tCell::matrix[index];
            int _tile = selected_tile;
            if (iSystem::player.hotbar[selected_hotbar][0] == itTILE)
            {
                int index = (GetMouseY()+(iSystem::player.y-(core::height/2)))*tCell::width+(GetMouseX()+(iSystem::player.x-(core::width/2)));
                int tile = tCell::matrix[index];
                int _tile = iSystem::player.hotbar[selected_hotbar][1];
                if (tile != tTile::MANTLE)
                {
                    if (_tile != tTile::AIR)
                    {
                        if (iSystem::player.inventory.HasItem(_tile) || core::creative_mode)
                        {
                            int amnt = 1;
                            if (tile == tTile::AIR) amnt = 0;
                            iSystem::player.inventory.UseItem(_tile, 1);
                            iSystem::player.inventory.AddItem(tile, amnt);
                            tCell::matrix[index] = _tile;
                        }
                    }
                    else if (_tile == tTile::AIR)
                    {
                        if (tile != tTile::AIR) iSystem::player.inventory.AddItem(tile, 1);
                        tCell::matrix[index] = _tile;
                    }
                }
            }
        }

        if (GetKey(olc::Key::SPACE).bPressed)
        {
            iSystem::world.SettleTiles(iSystem::player.x-(core::width), iSystem::player.y-(core::height), core::width*2, core::height*2);
        }
        DrawSky();
        DrawTerrain();
        DrawPlayer();
        HotbarInput();
        DrawHUD();
    }

    void GameInventory()
    {
        if (GetKey(olc::Key::ESCAPE).bPressed) core::game_state = core::PAUSED;
        if (GetKey(olc::Key::TAB).bPressed) core::game_state = core::PLAYING;

        if (GetKey(olc::Key::Q).bPressed && selected_tile < tTile::total_tiles-1) selected_tile++;
        if (GetKey(olc::Key::E).bPressed && selected_tile > 0) selected_tile--;

        if (GetKey(olc::Key::I).bPressed) core::pause_state = core::psTILES;
        if (GetKey(olc::Key::W).bPressed) core::pause_state = core::psWANDS;
        
        if (core::pause_state == core::psWANDS) DrawWands();
        if (core::pause_state == core::psTILES) DrawInventory();

        HotbarInput();
        DrawHUD();
    }

    void GameLoop(float fElapsedTime)
    {
        if (iSystem::player.state == iSystem::player.DEAD)
        {
            if (GetKey(olc::Key::ESCAPE).bPressed) core::game_state = core::PAUSED;
            return; 
        }

        if (!tTool::IsColliding(iSystem::player.x, iSystem::player.y+1) &&
            !tTool::IsColliding(iSystem::player.x-1, iSystem::player.y+1) &&
            iSystem::player.state != iSystem::player.JUMP)
        {
            iSystem::player.vy = 1;
            iSystem::player.state = iSystem::player.FALL;
        }
        if (tTool::IsColliding(iSystem::player.x, iSystem::player.y+1) || tTool::IsColliding(iSystem::player.x-1, iSystem::player.y+1))
        {
            iSystem::player.state = iSystem::player.IDLE;
        }

        if (GetKey(olc::Key::ESCAPE).bPressed) core::game_state = core::PAUSED;
        if (GetKey(olc::Key::TAB).bPressed) core::game_state = core::INVENTORY;
        //
        HotbarInput();
        
        // Stuff
        if (GetMouse(0).bHeld)
        {
            if (iSystem::player.hotbar[selected_hotbar][0] == itNONE)
            {
            }
            if (iSystem::player.hotbar[selected_hotbar][0] == itWAND)
            {
                if (iSystem::player.wands[selected_wand].can_fire)
                {
                    iSystem::player.wands[selected_wand].Cast();
                    Effect e = iSystem::player.wands[selected_wand].effects[iSystem::player.wands[selected_wand].current_effect];
                    iSystem::SpawnParticle(float(GetMouseX()), float(GetMouseY()), e);
                }
            }
            int index = (GetMouseY()+(iSystem::player.y-(core::height/2)))*tCell::width+(GetMouseX()+(iSystem::player.x-(core::width/2)));
            int tile = tCell::matrix[index];
            int _tile = selected_tile;
            if (iSystem::player.hotbar[selected_hotbar][0] == itTILE)
            {
                int index = (GetMouseY()+(iSystem::player.y-(core::height/2)))*tCell::width+(GetMouseX()+(iSystem::player.x-(core::width/2)));
                int tile = tCell::matrix[index];
                int _tile = iSystem::player.hotbar[selected_hotbar][1];
                if (tile != tTile::MANTLE)
                {
                    if (_tile != tTile::AIR)
                    {
                        if (iSystem::player.inventory.HasItem(_tile) || core::creative_mode)
                        {
                            int amnt = 1;
                            if (tile == tTile::AIR) amnt = 0;
                            iSystem::player.inventory.UseItem(_tile, 1);
                            iSystem::player.inventory.AddItem(tile, amnt);
                            tCell::matrix[index] = _tile;
                        }
                    }
                    else if (_tile == tTile::AIR)
                    {
                        if (tile != tTile::AIR) iSystem::player.inventory.AddItem(tile, 1);
                        tCell::matrix[index] = _tile;
                    }
                }
            }
        }

        // Vertical Movement
        if (GetKey(olc::Key::W).bHeld)
        {
            if ((!tTool::IsColliding(iSystem::player.x, iSystem::player.y-iSystem::player.height)) &&
                (iSystem::player.jp > 0) &&
                (iSystem::player.y > 0) )
            {
                iSystem::player.jp--;
                iSystem::player.vy = -1;
                iSystem::player.state = iSystem::player.JUMP;
            }
            else
            {
                iSystem::player.vy = 1;
            }
        }

        if (GetKey(olc::Key::W).bReleased) { iSystem::player.vy = 0; iSystem::player.state = iSystem::player.IDLE; }

        if (GetKey(olc::Key::S).bPressed)
        {
            int tile = tCell::matrix[(iSystem::player.y+(iSystem::player.height-1))*tCell::width+iSystem::player.x];
            if (tile == tTile::PLANKS) { iSystem::player.Move(0, 1); }
        }

        if (!tTool::IsColliding(iSystem::player.x, iSystem::player.y+1) && iSystem::player.state != iSystem::player.JUMP)
        { iSystem::player.vy = 1; iSystem::player.state = iSystem::player.FALL; }

        // Horizontal Movement
        if (GetKey(olc::Key::A).bHeld && iSystem::player.x > core::width/2)
        {
            if (iSystem::player.state != iSystem::player.FALL && iSystem::player.state != iSystem::player.JUMP) iSystem::player.vy = 0;
            if (!tTool::IsColliding(iSystem::player.x-2, iSystem::player.y) ) { iSystem::player.vx = -1; }
            else if (tTool::IsColliding(iSystem::player.x-2, iSystem::player.y) ||
                    tTool::IsColliding(iSystem::player.x-2, iSystem::player.y-1)
                    )
            { iSystem::player.vx = -1; iSystem::player.Move(0, -1); }
            if (!GetKey(olc::Key::W).bHeld && iSystem::player.state != iSystem::player.FALL) { iSystem::player.state = iSystem::player.WALK; }
            iSystem::player.direction = -1;
        }
        if (GetKey(olc::Key::D).bHeld && iSystem::player.x < tCell::width-(core::width/2))
        {
            if (iSystem::player.state != iSystem::player.FALL && iSystem::player.state != iSystem::player.JUMP) iSystem::player.vy = 0;
            if (!tTool::IsColliding(iSystem::player.x+1, iSystem::player.y) ) { iSystem::player.vx = 1; }
            else if (tTool::IsColliding(iSystem::player.x+1, iSystem::player.y) ||
                    tTool::IsColliding(iSystem::player.x+1, iSystem::player.y-1) )
            { iSystem::player.vx = 1; iSystem::player.Move(0, -1); }
            if (!GetKey(olc::Key::W).bHeld && iSystem::player.state != iSystem::player.FALL) { iSystem::player.state = iSystem::player.WALK; }
            iSystem::player.direction = 1;
        }

        if (GetKey(olc::Key::A).bReleased) { iSystem::player.vx = 0; }
        if (GetKey(olc::Key::D).bReleased) { iSystem::player.vx = 0; }

        if (GetKey(olc::Key::G).bPressed) { core::show_grid = !core::show_grid; }



        // Update World
        iSystem::sky.Update(fElapsedTime);
        if (core::game_tick > core::tick_delay)
        {
            core::game_tick -= core::tick_delay;
            DrawSky();
            iSystem::world.SettleTiles(iSystem::player.x-(core::width), iSystem::player.y-(core::height), core::width*2, core::height*2);
            DrawTerrain();
            DrawHUD();
        }

        // Update Player
        iSystem::player.Update(fElapsedTime);
        if (iSystem::player.hp < 1) iSystem::player.state = iSystem::player.DEAD;
        
        if (!PlayerVsWorld())
        {
            iSystem::player.Move(iSystem::player.vx, iSystem::player.vy);
        }
        DrawPlayer();
        //player.UpdateWands(fElapsedTime);
        DrawParticles(fElapsedTime);
        //DrawHUD();

        // End Frame
        core::game_tick += fElapsedTime;
    }



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
        switch (core::game_state)
        {
            case core::PLAYING : GameLoop(fElapsedTime); break;
            case core::PAUSED : GamePaused(); break;
            case core::INVENTORY : GameInventory(); break;
            case core::LOADING : DrawLoading(); break;
            case core::CUSTOM : DrawCustom(); break;
            case core::TITLE : DrawTitle(); break;
            case core::EXIT :
                {
                    iSystem::player.LoadData();
                    //SaveWorldData();
                    core::running = false;
                }
                break;
        }
        return core::running;
	}
};
