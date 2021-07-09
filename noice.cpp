#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif



#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

//#include <fstream>

#include "sky.h"
#include "world.h"
#include "effect.h"
#include "particle.h"
#include "wand.h"
#include "inventory.h"
#include "player.h"

#include "button.h"
#include "icon.h"



class Noice : public olc::PixelGameEngine
{
public:
	Noice()
	{
		sAppName = "Noice";
	}

public:

    enum PAUSE_STATES
    {
        psTILES,
        psWANDS
    };
    enum ITEM_TYPES
    {
        itNONE,
        itTILE,
        itWAND
    };

    enum STATES
    {
        TITLE,
        CUSTOM,
        LOADING,
        PLAYING,
        PAUSED,
        EXIT
    };

    bool running = true;
    bool creative_mode = true;
    bool loading = false;

    int game_seed = 0;

    int game_tick = 0;
    int tick_delay = 2;

    int game_state = 0;
    int pause_state = 0;

    char selected_hotbar = 0;
    char selected_tile = 0;
    char selected_wand = 0;
    int input_value = 0;
    char save_slot = 0;

    int width = 256;
    int height = 144;
    int pixel_size = 4;

    int world_width = 4096;//8192;
    int world_height = 2048;//4096;

    std::vector<Particle> particles;



    Icon icon = Icon();
    Sky sky = Sky();
    World world = World();
    Player player = Player();

    olc::Pixel hud_color = olc::Pixel(64, 64, 64);
    olc::Pixel hud_select_color = olc::Pixel(255, 255, 255);
    olc::Pixel text_color = olc::Pixel(255, 255, 255);
    olc::Pixel panel_color = olc::Pixel(10, 10, 10);
    olc::Pixel border_color = olc::Pixel(80, 80, 80);
    olc::Pixel button_color = olc::Pixel(32, 32, 32);
    olc::Pixel select_color = olc::Pixel(64, 64, 64);



    std::string GetCWD()
    {
        char buff[FILENAME_MAX];
        GetCurrentDir(buff, FILENAME_MAX);
        std::string _dir(buff);
        return _dir;
    }

    void GenerateData()
    {
        std::string _dir = GetCWD() + "/Data";
        std::string _cmd = "mkdir " + _dir;
        const char* mkdir_cmd = _cmd.c_str();
        system(mkdir_cmd);
    }

    void SaveWorldData()
    {
    }
    
    void LoadWorldData()
    {
    }

    void SaveChunkData(int X, int Y, std::string data_dir = "")
    {
        std::fstream data_file;
        data_dir = std::to_string(X) + "-" + std::to_string(Y);
        std::string _dir = GetCWD() + "/Data/" + data_dir;
        data_file.open(_dir);

        int x_ = X*world.chunk_size;
        int y_ = Y*world.chunk_size;

        if (data_file.is_open())
        {
            for (int y = 0; y < world.chunk_size; y++)
            {
                for (int x = 0; x < world.chunk_size; x++)
                {
                    int index = (y_+y)*world.width+(x_+x);
                    int tile = world.matrix[index];
                    data_file << tile << ",\t";
                }
                data_file << std::endl;
            }
            data_file.close();
        }
        else
        {
            std::ofstream new_file (_dir);
            SaveChunkData(X, Y, data_dir);
        }
    }

    void LoadChunkData(int X, int Y, std::string data_dir = "")
    {
        std::string line;
        data_dir = std::to_string(X) + "-" + std::to_string(Y);
        std::fstream data_file;
        std::string _dir = GetCWD() + "/Data/" + data_dir;
        data_file.open(_dir);

        int x = 0;
        int y = 0;
        int x_ = X*world.chunk_size;
        int y_ = Y*world.chunk_size;

        if (data_file.is_open())
        {
            std::string v = "";
            while (getline(data_file, line))
            {
                for (int i = 0; i < line.length(); i++)
                {
                    std::string c = line.substr(i, 1);
                    if (c == ",") {x++;}
                    if (
                            c == "1" || c == "2" || c == "3" || c == "4" || c == "5" ||
                            c == "6" || c == "7" || c == "8" || c == "9" || c == "0"
                            )
                    {
                        v = v + c;
                    }
                }
                int value = std::stoi(v);
                int index = (y_+y)*world.width+(x_+x);
                world.matrix[index] = value;
                v = "";
                y++;
                x = 0;
            }
            data_file.close();
        }
    }

    void SavePlayerData(std::string data_dir = "player_data")
    {
        std::fstream data_file;
        std::string _dir = GetCWD() + "/Data/" + data_dir;
        data_file.open(_dir);

        if (data_file.is_open())
        {
            data_file << "#blocks" << std::endl;
            for (int i = 0; i < player.inventory.data.size(); i++)
            {
                data_file << i << "=" << player.inventory.data[i] << std::endl;
            }
            data_file.close();
        }
        else
        {
            std::ofstream new_file (_dir);
            SavePlayerData(data_dir);
        }
    }

    void LoadPlayerData(std::string data_dir = "player_data")
    {
        std::string line;
        std::fstream data_file;
        std::string _dir = GetCWD() + "/Data/" + data_dir;
        data_file.open(_dir);

        if (data_file.is_open())
        {
            std::string read_state = "";

            while (getline(data_file, line))
            {
                if (line == "#blocks")
                {
                    read_state = "#blocks";
                }

                if (read_state == "#blocks")
                {
                    bool next = false;
                    std::string itm = "";
                    std::string amnt = "";

                    for (int i = 0; i < line.length(); i++)
                    {
                        std::string c = line.substr(i, 1);
                        if (c == "=")
                        {
                            next = true;
                        }
                        if (
                                c == "1" || c == "2" || c == "3" || c == "4" || c == "5" ||
                                c == "6" || c == "7" || c == "8" || c == "9" || c == "0"
                                )
                        {
                            if (!next) {itm = itm + c;}
                            if (next) {amnt = amnt + c;}
                        }
                    }
                    if (line.substr(0, 1) != "#")
                    {
                        int item = std::stoi(itm);
                        int amount = std::stoi(amnt);
                        player.inventory.AddItem(item, amount);
                    }
                }
            }
        data_file.close();
        }
    }

    void SaveGenerationData(std::string data_dir)
    {
        std::string line;
        std::fstream data_file;
        std::string _dir = GetCWD() + "/Data/" + data_dir;
        data_file.open(_dir);
        
        if (data_file.is_open())
        {
            for (int i = 0; i < world.generation_steps; i++)
            {
                for (int j = 0; j < world.total_parameters; j++)
                {
                    data_file << world.generation_param[i][j] << std::endl;
                }
            }
            data_file.close();
        }
        else
        {
            std::ofstream new_file (_dir);
            SaveGenerationData(data_dir);
        }
    }

    void LoadGenerationData(std::string data_dir)
    {
        std::string line;
        std::fstream data_file;
        std::string _dir = GetCWD() + "/Data/" + data_dir;
        data_file.open(_dir);

        if (data_file.is_open())
        {
            int i = 0;
            int j = 0;
            while (getline(data_file, line))
            {
                if (i <= world.maximum_generation_steps && line != "")
                {
                    world.generation_param[i][j] = std::stoi(line);
                    j++;
                    if (j % world.total_parameters == 0)
                    {
                        i++;
                        j = 0;
                    }
                }
            }
            world.generation_steps = i;
            data_file.close();
        }
    }

    void SpawnParticle(float X, float Y, Effect e)
    {
        float W = width/2;
        float H = height/2;
        Particle p = Particle();
        p.SetEffect(e);
        p.Position(player.x, player.y);
        p.Velocity(float((X-W)*0.1), float((Y-H)*0.1));
        particles.push_back(p);
    }

    void ProgressBar(int x, int y, int minv, int maxv, int W, int R=255, int G=255, int B=255, int r=64, int g=64, int b=64)
    {
        float completed = float(minv)/float(maxv);
        int x2 = W*completed;
        DrawLine(x, y, x+W, y, olc::Pixel(r, g, b));
        DrawLine(x, y, x+x2, y, olc::Pixel(R, G, B));
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
                if (wand_value < player.wands.size())
                {
                    int wand_color = player.wands[wand_value].material;
                    float R = float(world.tileset[wand_color][0][0]);
                    float G = float(world.tileset[wand_color][0][1]);
                    float B = float(world.tileset[wand_color][0][2]);
                    int A = world.tileset[wand_color][0][3];
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
                        player.hotbar[selected_hotbar][0] = itWAND;
                        player.hotbar[selected_hotbar][1] = std::stoi(b.text);
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
                float R = float(world.tileset[tile_value][0][0]);
                float G = float(world.tileset[tile_value][0][1]);
                float B = float(world.tileset[tile_value][0][2]);
                int A = world.tileset[tile_value][0][3];
                int tile_type = world.GetType(tile_value);
                for (int iy = 0; iy < icon.size; iy++)
                {
                    for (int ix = 0; ix < icon.size; ix++)
                    {
                        if (tile_value < world.total_tiles)
                        {
                            Button b = Button();
                            b.Setup((x*10)+x_margin, (y*10)+y_margin, 9, 9, 1.0, std::to_string(tile_value));
                            buttons[y*cols+x] = b;
                            int index_value = icon.solid[iy*icon.size+ix];
                            if (tile_type == world.GRAIN) index_value = icon.grain[iy*icon.size+ix];
                            if (tile_type == world.GEL) index_value = icon.gel[iy*icon.size+ix];
                            if (tile_type == world.FLUID) index_value = icon.fluid[iy*icon.size+ix];
                            if (tile_type == world.GAS) index_value = icon.gas[iy*icon.size+ix];
                            if (tile_type == world.GIZMO) index_value = icon.gizmo[iy*icon.size+ix];
                            if (tile_type == world.PLUMBING) index_value = icon.plumbing[iy*icon.size+ix];
                            float v = (0.25*float(index_value));
                            if (index_value > 0) Draw(ix+(x*10)+x_margin, iy+(y*10)+y_margin, olc::Pixel(int(R*v), int(G*v), int(B*v), A));
                        }
                    }
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
                        player.hotbar[selected_hotbar][0] = itTILE;
                        player.hotbar[selected_hotbar][1] = std::stoi(b.text);
                    }
                }
            }
        }
    }

    void DrawSky()
    {
        if (player.status != player.TRIP) Clear(olc::Pixel(sky.R, sky.G, sky.B));
        
        if (sky.starlight >= 0)
        {
            SetPixelMode(olc::Pixel::ALPHA);
            for (int i = 0; i < sky.starcount; i += 4)
            {
                int value = rand()%220+35;
                Draw(sky.stars[i][0], sky.stars[i][1], olc::Pixel(value, value, value, 255-sky.starlight));
                Draw(sky.stars[i+1][0], sky.stars[i][1], olc::Pixel(value, value, value, 255-sky.starlight));
                Draw(sky.stars[i+2][0], sky.stars[i][1], olc::Pixel(value, value, value, 255-sky.starlight));
                Draw(sky.stars[i+3][0], sky.stars[i][1], olc::Pixel(value, value, value, 255-sky.starlight));
            }
        }

        if (sky.time > 0.5)
        {
            FillCircle(sky.sunx, sky.suny, sky.sun, olc::WHITE);
            FillCircle(sky.sunx, sky.suny, sky.sun*1.2, olc::Pixel(255, 255, 255, 24));
            FillCircle(sky.sunx, sky.suny, sky.sun*1.3, olc::Pixel(255, 255, 255, 20));
            FillCircle(sky.sunx, sky.suny, sky.sun*1.4, olc::Pixel(255, 255, 255, 16));
            FillCircle(sky.sunx, sky.suny, sky.sun*1.5, olc::Pixel(255, 255, 255, 12));
        }
        else if (sky.time < 0.5)
        {
            FillCircle(sky.moonx, sky.moony, sky.moon, olc::WHITE);
            FillCircle(sky.moonx, sky.moony, sky.moon*1.2, olc::Pixel(255, 255, 255, 24));
            FillCircle(sky.moonx, sky.moony, sky.moon*1.3, olc::Pixel(255, 255, 255, 20));
            FillCircle(sky.moonx, sky.moony, sky.moon*1.4, olc::Pixel(255, 255, 255, 16));
            FillCircle(sky.moonx, sky.moony, sky.moon*1.5, olc::Pixel(255, 255, 255, 12));

            FillCircle(sky.moonx, sky.moony, sky.moon*0.95, olc::Pixel(220, 220, 220));
            FillCircle(sky.moonx-2, sky.moony+1, sky.moon/2, olc::Pixel(195, 195, 195));
            FillCircle(sky.moonx+3, sky.moony+3, sky.moon/2, olc::Pixel(195, 195, 195));
            FillCircle(sky.moonx+2, sky.moony-1, sky.moon/3, olc::Pixel(170, 170, 170));
            FillCircle(sky.moonx-3, sky.moony-4, sky.moon/3, olc::Pixel(170, 170, 170));
            FillCircle(sky.moonx-2, sky.moony+3, sky.moon/4, olc::Pixel(145, 145, 145));
            FillCircle(sky.moonx+3, sky.moony+4, sky.moon/4, olc::Pixel(145, 145, 145));
            FillCircle(sky.moonx+3, sky.moony-2, sky.moon/5, olc::Pixel(120, 120, 120));
            FillCircle(sky.moonx-4, sky.moony-3, sky.moon/5, olc::Pixel(120, 120, 120));
        }
        for (int i = 0; i < sky.humidity; i++)
        {
            int x = sky.clouds[i][0];
            int y = sky.clouds[i][1];
            FillCircle(x, y, sky.clouds[i][2], olc::Pixel(sky.r, sky.g, sky.b, 4+(8*sky.time)));
        }
        if (sky.humidity > sky.cloudcount/4)
        {
            if (rand()%sky.cloudcount < sky.humidity)
            {
                if (sky.day < sky.year_length*0.75) world.matrix[256*world.width+((rand()%width)+player.x-(width/2))] = world.WATER;
                else if (sky.day >= sky.year_length*0.75) world.matrix[256*world.width+((rand()%width)+player.x-(width/2))] = world.SNOW;
            }
        }
        SetPixelMode(olc::Pixel::NORMAL);
    }

    void DrawTerrain()
    {
        int X = player.x - (width/2);
        int Y = player.y - (height/2);
        SetPixelMode(olc::Pixel::ALPHA);
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x += 4)
            {
                if ( (x+X > 0 && x+X < world.width-1) && (y+Y > 1 && y+Y < world.height-1) )
                {
                    int v1 = world.matrix[(y+Y)*world.width+(x+X)];
                    int v2 = world.matrix[(y+Y)*world.width+(x+X+1)];
                    int v3 = world.matrix[(y+Y)*world.width+(x+X)+2];
                    int v4 = world.matrix[(y+Y)*world.width+(x+X)+3];

                    float n1 = world.Neighbors(x+X, y+Y);
                    float n2 = world.Neighbors(x+X+1, y+Y);
                    float n3 = world.Neighbors(x+X+2, y+Y);
                    float n4 = world.Neighbors(x+X+3, y+Y);

                    float s1 = 1.0;
                    float s2 = 1.0;
                    float s3 = 1.0;
                    float s4 = 1.0;

                    if (n1 > 2) s1 = 1.0/(n1-2);
                    if (n2 > 2) s2 = 1.0/(n2-2);
                    if (n3 > 2) s3 = 1.0/(n3-2);
                    if (n4 > 2) s4 = 1.0/(n4-2);

                    Draw(x, y, olc::Pixel(
                                int(world.tileset[v1][0][0]*s1),// + rand() % world.tileset[v1][1][0],
                                int(world.tileset[v1][0][1]*s1),// + rand() % world.tileset[v1][1][1],
                                int(world.tileset[v1][0][2]*s1),// + rand() % world.tileset[v1][1][2],
                                world.tileset[v1][0][3])
                            );

                    Draw(x+1, y, olc::Pixel(
                                int(world.tileset[v2][0][0]*s2),// + rand() % world.tileset[v2][1][0],
                                int(world.tileset[v2][0][1]*s2),// + rand() % world.tileset[v2][1][1],
                                int(world.tileset[v2][0][2]*s2),// + rand() % world.tileset[v2][1][2],
                                world.tileset[v2][0][3])
                            );
                    Draw(x+2, y, olc::Pixel(
                                int(world.tileset[v3][0][0]*s3),// + rand() % world.tileset[v3][1][0],
                                int(world.tileset[v3][0][1]*s3),// + rand() % world.tileset[v3][1][1],
                                int(world.tileset[v3][0][2]*s3),// + rand() % world.tileset[v3][1][2],
                                world.tileset[v3][0][3])
                            );
                    Draw(x+3, y, olc::Pixel(
                                int(world.tileset[v4][0][0]*s4),// + rand() % world.tileset[v4][1][0],
                                int(world.tileset[v4][0][1]*s4),// + rand() % world.tileset[v4][1][1],
                                int(world.tileset[v4][0][2]*s4),// + rand() % world.tileset[v4][1][2],
                                world.tileset[v4][0][3])
                            );
                }
            }
        }
        SetPixelMode(olc::Pixel::NORMAL);
    }

    void DrawPlayer()
    {
        int r = 0;
        int g = 0;
        int b = 0;
        switch (player.status)
        {
            case player.FINE :     {r=255; g=255; b=255;} break;
            case player.HURT :     {r=255; g=128; b=0  ;} break;
            case player.BURN :     {r=255; g=0  ; b=0  ;} break;
            case player.COLD :     {r=128; g=128; b=255;} break;
            case player.STUN :     {r=255; g=255; b=0  ;} break;
            case player.TRIP :     {r=0;   g=255; b=255;} break;
            case player.POISON :   {r=0;   g=255; b=0  ;} break;
            case player.CONFUSED : {r=128; g=128; b=128;} break;

        }
        DrawLine(int(width/2), int(height/2), int(width/2), int(height/2)-player.height, olc::Pixel(r, g, b));
    }

    void DrawParticles(float delta)
    {
        for (int p = 0; p < (particles.size()); p++)
        {
            float x = particles[p].x;
            float y = particles[p].y;
            float vx = particles[p].vx;
            float vy = particles[p].vy;

            particles[p].Move(vx, vy, delta, world.IsColliding(int(x+vx), int(y+vy)));
            if ( particles[p].effect.destroys && world.IsColliding(int(x+(vx*1.5)), int(y+(vy*1.5))) )
            {
                world.matrix[int(y+(vy*1.5))*world.width+int(x+(vx*1.5))] = world.AIR;
            }
            if ( particles[p].effect.mines && world.IsColliding(int(x+(vx*1.5)), int(y+(vy*1.5))) )
            {
                player.inventory.AddItem(world.matrix[int(y+(vy*1.5))*world.width+int(x+(vx*1.5))], 1);
                world.matrix[int(y+(vy*1.5))*world.width+int(x+(vx*1.5))] = world.AIR;
            }
            if (particles[p].duration > 0.0)
            {
                particles[p].duration -= delta;
                Draw(x-(player.x-(width/2)), y-(player.y-(height/2)), olc::Pixel(particles[p].r, particles[p].g, particles[p].b, particles[p].a));
            }
            else
            {
                particles.erase(particles.begin()+p);
            }
        }
    }

    void DrawHUD()
    {
        float font = 0.25;

        int lookindex = (player.y-(height/2)+GetMouseY())*world.width+(player.x-(width/2)+GetMouseX());

        std::string health = std::to_string(player.hp)+"/"+std::to_string(player.HP);
        std::string lookingat = "Air";
        std::string selectedtile = world.tiles[selected_tile];
        std::string selectedcount = "";
        std::string collision_at = std::to_string(world.Collision((player.x-(width/2)+GetMouseX()), (player.y-(height/2)+GetMouseY())));

        if ( ( (lookindex < world.width*world.height) && lookindex > 0) && (world.matrix[lookindex] < world.total_tiles) )
        {
            lookingat = world.tiles[world.matrix[lookindex]];
        }
        if (player.inventory.HasItem(selected_tile))
        {
            selectedcount = std::to_string(player.inventory.data[selected_tile]);
        }

        ProgressBar(4, 2, player.hp, player.HP, 32, 255, 0, 0, 64, 0, 0);
        ProgressBar(4, 4, player.jp, player.JP, 32, 0, 255, 0, 0, 64, 0);
        ProgressBar(4, 6, player.bp, player.BP, 32, 0, 0, 255, 0, 0, 64);
        DrawStringDecal({ 4,8  }, "Looking At: " + lookingat, text_color, { font, font });
        //DrawStringDecal({ 4,12 }, "Selected Tile: " + selectedtile + " " + selectedcount, text_color, { font, font });
        DrawStringDecal({ 4,12 }, "Collision: " + collision_at, text_color, { font, font });
        DrawStringDecal({ 4,16 }, "Day: " + std::to_string(sky.day), text_color, { font, font });
        DrawStringDecal({ 4,20 }, "Year: " + std::to_string(sky.year), text_color, { font, font });
        //
        int hb_size = icon.size+1;
        int hb_offset = (width/2) - hb_size*4.5;
        std::string selected_item = "";
        if (player.hotbar[selected_hotbar][0] == itWAND) { selected_item = "Wand"; }
        if (player.hotbar[selected_hotbar][0] == itTILE) { selected_item = world.tiles[player.hotbar[selected_hotbar][1]]; }
        float select_x = (width/2)-(selected_item.size());
        DrawStringDecal({ select_x,15 }, selected_item, text_color, { 0.25, 0.25 });
        SetPixelMode(olc::Pixel::ALPHA);
        for (int i = 0; i < 9; i++)
        {
            int x = i*hb_size+hb_offset;
            //FillRect(x, 2, hb_size, hb_size, olc::Pixel(0, 0, 0, 128));
            DrawRect(x, 2, hb_size, hb_size, hud_color);
            
            if (player.hotbar[i][0] == itWAND)
            {
                int tile_value = player.hotbar[i][1];
                float R = float(world.tileset[tile_value][0][0]);
                float G = float(world.tileset[tile_value][0][1]);
                float B = float(world.tileset[tile_value][0][2]);
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
            if (player.hotbar[i][0] == itTILE)
            {
                int tile_value = player.hotbar[i][1];
                float R = float(world.tileset[tile_value][0][0]);
                float G = float(world.tileset[tile_value][0][1]);
                float B = float(world.tileset[tile_value][0][2]);
                int A = world.tileset[tile_value][0][3];
                int tile_type = world.GetType(tile_value);
                for (int iy = 0; iy < icon.size; iy++)
                {
                    for (int ix = 0; ix < icon.size; ix++)
                    {
                        int index_value = icon.solid[iy*icon.size+ix];
                        if (tile_type == world.GRAIN) index_value = icon.grain[iy*icon.size+ix];
                        if (tile_type == world.GEL) index_value = icon.gel[iy*icon.size+ix];
                        if (tile_type == world.FLUID) index_value = icon.fluid[iy*icon.size+ix];
                        if (tile_type == world.GAS) index_value = icon.gas[iy*icon.size+ix];
                        if (tile_type == world.GIZMO) index_value = icon.gizmo[iy*icon.size+ix];
                        if (tile_type == world.PLUMBING) index_value = icon.plumbing[iy*icon.size+ix];
                        float v = (0.25*float(index_value));
                        if (index_value > 0) Draw(ix+x+1, iy+3, olc::Pixel(int(R*v), int(G*v), int(B*v), A));
                    }
                }
            }
        }
        SetPixelMode(olc::Pixel::NORMAL);
        DrawRect(selected_hotbar*hb_size+hb_offset, 2, hb_size, hb_size, hud_select_color);
    }

    void DrawTitle()
    {
        Clear(olc::BLACK);

        float Tx = (width/2)-((sAppName.size()*16)/2);
        float Ty = (height*0.25);

        float Nx = (width/2)-50;
        float Lx = (width/2)+4;
        float By = (height*0.75);

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
                game_state = CUSTOM;
                player.Setup();
            }
        }
        if (bLoad.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bLoad.x, bLoad.y, bLoad.width, bLoad.height, select_color);
            if (GetMouse(0).bReleased)
            {
                Clear(olc::BLACK);
                LoadPlayerData();
                //LoadWorldData();
                game_state = PLAYING;
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
        Button bsave = Button();
        bsave.Setup(105, 37, 32, 8, 0.25, "Save");
        Button bload = Button();
        bload.Setup(105, 45, 32, 8, 0.25, "Load");

        Button bclear = Button();
        bclear.Setup(105, 57, 32, 8, 0.25, "Clear");
        Button bconfig = Button();
        bconfig.Setup(105, 65, 32, 8, 0.25, "Preset");
        Button brandom = Button();
        brandom.Setup(105, 73, 32, 8, 0.25, "Random");
        
        Button bpreview = Button();
        bpreview.Setup(105, 86, 32, 8, 0.25, "Preview");
        Button bgenerate = Button();
        bgenerate.Setup(105, 94, 32, 8, 0.25, "Generate");

        Button bminusgs = Button();
        bminusgs.Setup(183, 2, 70, 4, 0.25, "-");
        Button bplusgs = Button();
        bplusgs.Setup(183, 88, 70, 4, 0.25, "+");

        Button bcopy = Button();
        bcopy.Setup(183, 94, 35, 8, 0.25, "Copy");
        Button bpaste = Button();
        bpaste.Setup(218, 94, 35, 8, 0.25, "Paste");

        Button bsave0 = Button();
        bsave0.Setup(141, 7, 38, 8, 0.25, "Save 0");
        Button bsave1 = Button();
        bsave1.Setup(141, 15, 38, 8, 0.25, "Save 1");
        Button bsave2 = Button();
        bsave2.Setup(141, 23, 38, 8, 0.25, "Save 2");
        Button bsave3 = Button();
        bsave3.Setup(141, 31, 38, 8, 0.25, "Save 3");
        Button bsave4 = Button();
        bsave4.Setup(141, 39, 38, 8, 0.25, "Save 4");
        Button bsave5 = Button();
        bsave5.Setup(141, 47, 38, 8, 0.25, "Save 5");
        Button bsave6 = Button();
        bsave6.Setup(141, 55, 38, 8, 0.25, "Save 6");

        Button btile = Button();
        btile.Setup(141, 70, 18, 8, 0.25, "Tile");
        Button bmode = Button();
        bmode.Setup(141, 78, 18, 8, 0.25, "Mode");
        Button bdense = Button();
        bdense.Setup(141, 86, 18, 8, 0.25, "Density");
        Button biter = Button();
        biter.Setup(141, 94, 18, 8, 0.25, "Repeat");

        Button bminx = Button();
        bminx.Setup(162, 70, 18, 8, 0.25, "Min X");
        Button bmaxx = Button();
        bmaxx.Setup(162, 78, 18, 8, 0.25, "Max X");
        Button bminy = Button();
        bminy.Setup(162, 86, 18, 8, 0.25, "Min Y");
        Button bmaxy = Button();
        bmaxy.Setup(162, 94, 18, 8, 0.25, "Max Y");

        Button bprobn = Button();
        bprobn.Setup(117, 6, 8, 8, 0.25, "N");
        Button bprobs = Button();
        bprobs.Setup(117, 22, 8, 8, 0.25, "S");
        Button bprobe = Button();
        bprobe.Setup(125, 14, 8, 8, 0.25, "E");
        Button bprobw = Button();
        bprobw.Setup(109, 14, 8, 8, 0.25, "W");

        DrawRect(2, 2, 100, 100, border_color);  // Preview Box
        DrawRect(183, 2, 70, 90, border_color);  // Generation Steps Box
        DrawRect(2, 105, 251, 36, border_color);  // Information Box
        DrawRect(105, 2, 32, 32, border_color);  // Neighbors Box

        DrawRect(bsave.x, bsave.y, bsave.width, bsave.height, button_color);
        DrawStringDecal({ bsave.TextX(),bsave.TextY() }, bsave.text, text_color, { bsave.font, bsave.font });
        DrawRect(bload.x, bload.y, bload.width, bload.height, button_color);
        DrawStringDecal({ bload.TextX(),bload.TextY() }, bload.text, text_color, { bload.font, bload.font });
        
        DrawRect(bcopy.x, bcopy.y, bcopy.width, bcopy.height, button_color);
        DrawStringDecal({ bcopy.TextX(),bcopy.TextY() }, bcopy.text, text_color, { bcopy.font, bcopy.font });
        DrawRect(bpaste.x, bpaste.y, bpaste.width, bpaste.height, button_color);
        DrawStringDecal({ bpaste.TextX(),bpaste.TextY() }, bpaste.text, text_color, { bpaste.font, bpaste.font });
        
        DrawRect(bclear.x, bclear.y, bclear.width, bclear.height, button_color);
        DrawStringDecal({ bclear.TextX(),bclear.TextY() }, bclear.text, text_color, { bclear.font, bclear.font });
        DrawRect(bconfig.x, bconfig.y, bconfig.width, bconfig.height, button_color);
        DrawStringDecal({ bconfig.TextX(),bconfig.TextY() }, bconfig.text, text_color, { bconfig.font, bconfig.font });
        DrawRect(brandom.x, brandom.y, brandom.width, brandom.height, button_color);
        DrawStringDecal({ brandom.TextX(),brandom.TextY() }, brandom.text, text_color, { brandom.font, brandom.font });

        DrawRect(bpreview.x, bpreview.y, bpreview.width, bpreview.height, button_color);
        DrawStringDecal({ bpreview.TextX(),bpreview.TextY() }, bpreview.text, text_color, { bpreview.font, bpreview.font });
        DrawRect(bgenerate.x, bgenerate.y, bgenerate.width, bgenerate.height, button_color);
        DrawStringDecal({ bgenerate.TextX(),bgenerate.TextY() }, bgenerate.text, text_color, { bgenerate.font, bgenerate.font });

        DrawRect(bminusgs.x, bminusgs.y, bminusgs.width, bminusgs.height, button_color);
        DrawStringDecal({ bminusgs.TextX(),bminusgs.TextY() }, bminusgs.text, text_color, { btile.font, bminusgs.font });
        DrawRect(bplusgs.x, bplusgs.y, bplusgs.width, bplusgs.height, button_color);
        DrawStringDecal({ bplusgs.TextX(),bplusgs.TextY() }, bplusgs.text, text_color, { bplusgs.font, bplusgs.font });

        DrawRect(bsave0.x, bsave0.y, bsave0.width, bsave0.height, button_color);
        DrawStringDecal({ bsave0.TextX(),bsave0.TextY() }, bsave0.text, text_color, { bsave0.font, bsave0.font });
        DrawRect(bsave1.x, bsave1.y, bsave1.width, bsave1.height, button_color);
        DrawStringDecal({ bsave1.TextX(),bsave1.TextY() }, bsave1.text, text_color, { bsave1.font, bsave1.font });
        DrawRect(bsave2.x, bsave2.y, bsave2.width, bsave2.height, button_color);
        DrawStringDecal({ bsave2.TextX(),bsave2.TextY() }, bsave2.text, text_color, { bsave2.font, bsave2.font });
        DrawRect(bsave3.x, bsave3.y, bsave3.width, bsave3.height, button_color);
        DrawStringDecal({ bsave3.TextX(),bsave3.TextY() }, bsave3.text, text_color, { bsave3.font, bsave3.font });
        DrawRect(bsave4.x, bsave4.y, bsave4.width, bsave4.height, button_color);
        DrawStringDecal({ bsave4.TextX(),bsave4.TextY() }, bsave4.text, text_color, { bsave4.font, bsave4.font });
        DrawRect(bsave5.x, bsave5.y, bsave5.width, bsave5.height, button_color);
        DrawStringDecal({ bsave5.TextX(),bsave5.TextY() }, bsave5.text, text_color, { bsave5.font, bsave5.font });
        DrawRect(bsave6.x, bsave6.y, bsave6.width, bsave6.height, button_color);
        DrawStringDecal({ bsave6.TextX(),bsave6.TextY() }, bsave6.text, text_color, { bsave6.font, bsave6.font });

        DrawRect(btile.x, btile.y, btile.width, btile.height, button_color);
        DrawStringDecal({ btile.TextX(),btile.TextY() }, btile.text, text_color, { btile.font, btile.font });
        DrawRect(bmode.x, bmode.y, bmode.width, bmode.height, button_color);
        DrawStringDecal({ bmode.TextX(),bmode.TextY() }, bmode.text, text_color, { bmode.font, bmode.font });
        DrawRect(bdense.x, bdense.y, bdense.width, bdense.height, button_color);
        DrawStringDecal({ bdense.TextX(),bdense.TextY() }, bdense.text, text_color, { bdense.font, bdense.font });
        DrawRect(biter.x, biter.y, biter.width, biter.height, button_color);
        DrawStringDecal({ biter.TextX(),biter.TextY() }, biter.text, text_color, { biter.font, biter.font });

        DrawRect(bminx.x, bminx.y, bminx.width, bminx.height, button_color);
        DrawStringDecal({ bminx.TextX(),bminx.TextY() }, bminx.text, text_color, { bminx.font, bminx.font });
        DrawRect(bmaxx.x, bmaxx.y, bmaxx.width, bmaxx.height, button_color);
        DrawStringDecal({ bmaxx.TextX(),bmaxx.TextY() }, bmaxx.text, text_color, { bmaxx.font, bmaxx.font });
        DrawRect(bminy.x, bminy.y, bminy.width, bminy.height, button_color);
        DrawStringDecal({ bminy.TextX(),bminy.TextY() }, bminy.text, text_color, { bminy.font, bminy.font });
        DrawRect(bmaxy.x, bmaxy.y, bmaxy.width, bmaxy.height, button_color);
        DrawStringDecal({ bmaxy.TextX(),bmaxy.TextY() }, bmaxy.text, text_color, { bmaxy.font, bmaxy.font });

        DrawRect(bprobn.x, bprobn.y, bprobn.width, bprobn.height, button_color);
        DrawStringDecal({ bprobn.TextX(),bprobn.TextY() }, bprobn.text, text_color, { bprobn.font, bprobn.font });
        DrawRect(bprobs.x, bprobs.y, bprobs.width, bprobs.height, button_color);
        DrawStringDecal({ bprobs.TextX(),bprobs.TextY() }, bprobs.text, text_color, { bprobs.font, bprobs.font });
        DrawRect(bprobe.x, bprobe.y, bprobe.width, bprobe.height, button_color);
        DrawStringDecal({ bprobe.TextX(),bprobe.TextY() }, bprobe.text, text_color, { bprobe.font, bprobe.font });
        DrawRect(bprobw.x, bprobw.y, bprobw.width, bprobw.height, button_color);
        DrawStringDecal({ bprobw.TextX(),bprobw.TextY() }, bprobw.text, text_color, { bprobw.font, bprobw.font });

        // Numeric Input
        if (GetKey(olc::Key::K0).bPressed)
        {
            std::string new_value = std::to_string(input_value)+"0";
            input_value = std::stoi(new_value);
        }
        if (GetKey(olc::Key::K1).bPressed)
        {
            std::string new_value = std::to_string(input_value)+"1";
            input_value = std::stoi(new_value);
        }
        if (GetKey(olc::Key::K2).bPressed)
        {
            std::string new_value = std::to_string(input_value)+"2";
            input_value = std::stoi(new_value);
        }
        if (GetKey(olc::Key::K3).bPressed)
        {
            std::string new_value = std::to_string(input_value)+"3";
            input_value = std::stoi(new_value);
        }
        if (GetKey(olc::Key::K4).bPressed)
        {
            std::string new_value = std::to_string(input_value)+"4";
            input_value = std::stoi(new_value);
        }
        if (GetKey(olc::Key::K5).bPressed)
        {
            std::string new_value = std::to_string(input_value)+"5";
            input_value = std::stoi(new_value);
        }
        if (GetKey(olc::Key::K6).bPressed)
        {
            std::string new_value = std::to_string(input_value)+"6";
            input_value = std::stoi(new_value);
        }
        if (GetKey(olc::Key::K7).bPressed)
        {
            std::string new_value = std::to_string(input_value)+"7";
            input_value = std::stoi(new_value);
        }
        if (GetKey(olc::Key::K8).bPressed)
        {
            std::string new_value = std::to_string(input_value)+"8";
            input_value = std::stoi(new_value);
        }
        if (GetKey(olc::Key::K9).bPressed)
        {
            std::string new_value = std::to_string(input_value)+"9";
            input_value = std::stoi(new_value);
        }

        if (GetKey(olc::Key::ENTER).bPressed)
        {
            switch (world.selected_param)
            {
                case world.pTILE : if (input_value > world.total_tiles-1) input_value = world.total_tiles-1; break;
                case world.pMODE : if (input_value > 3) input_value = 3; break;
                case world.pITER : if (input_value > 64) input_value = 64; break;
                default : if (input_value > 100) input_value = 100; break;
            }
            world.generation_param[world.selected_step][world.selected_param] = input_value;
            input_value = 0;
        }
        // Update Parameters
        if (GetKey(olc::Key::S).bPressed)
        {
            if (world.selected_step < world.generation_steps-2) world.selected_step++;
        }
        if (GetKey(olc::Key::W).bPressed)
        {
            if (world.selected_step > 0) world.selected_step--;
        }

        if (GetKey(olc::Key::A).bPressed)
        {
            if (world.generation_param[world.selected_step][world.selected_param] > 0)
            {
                world.generation_param[world.selected_step][world.selected_param]--;
            }
        }
        if (GetKey(olc::Key::D).bPressed)
        {
            switch (world.selected_param)
            {
                case world.pTILE :
                {
                    if (world.generation_param[world.selected_step][world.selected_param] < world.total_tiles-1)
                    {
                        world.generation_param[world.selected_step][world.selected_param]++;
                    }
                }
                break;
                case  world.pMODE :
                {
                    if (world.generation_param[world.selected_step][world.selected_param] < world.total_modes-1)
                    {
                        world.generation_param[world.selected_step][world.selected_param]++;
                    }
                }
                break;
                default :
                {
                    if (world.generation_param[world.selected_step][world.selected_param] < 100)
                    {
                        world.generation_param[world.selected_step][world.selected_param]++;
                    }
                }
                break;
            }
        }
        // Step Value
        if (bminusgs.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Removes The Selected Generation Step From The List";
            //dtls_text = "()";
            DrawRect(bminusgs.x, bminusgs.y, bminusgs.width, bminusgs.height, select_color);
            if (GetMouse(0).bReleased && world.generation_steps > 1)
            {
                world.generation_steps--;
                for (int i = world.selected_step; i < world.generation_steps; i++)
                {
                    for (int p = 0; p < world.total_parameters; p++)
                    {
                        world.generation_param[i][p] = world.generation_param[i+1][p];
                    }
                }
                if (world.selected_step > 0) world.selected_step--;
            }
        }
        if (bplusgs.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Inserts A Generation Step Into The List";
            //dtls_text = "()";
            DrawRect(bplusgs.x, bplusgs.y, bplusgs.width, bplusgs.height, select_color);
            if (GetMouse(0).bReleased && world.generation_steps < world.maximum_generation_steps)
            {
                world.generation_steps++;
                for (int i = world.generation_steps-1; i > world.selected_step+1; i--)
                {
                    for (int p = 0; p < world.total_parameters; p++)
                    {
                        world.generation_param[i-1][p] = world.generation_param[i-2][p];
                    }
                }
                for (int p = 0; p < world.total_parameters; p++)
                {
                    world.generation_param[world.selected_step][p] = 0;
                }
                if (world.selected_step > 0) world.selected_step--;
            }
        }
        // Tile Value
        if (btile.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Material To add To World";
            //dtls_text = "()";
            DrawRect(btile.x, btile.y, btile.width, btile.height, select_color);
            if (GetMouse(0).bReleased) world.selected_param = world.pTILE;
        }
        // Density Value
        if (bdense.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability A Material Will Spawn Per Cell";
            dtls_text = "(Add Layer, Seed Material)";
            DrawRect(bdense.x, bdense.y, bdense.width, bdense.height, select_color);
            if (GetMouse(0).bReleased) world.selected_param = world.pDENSE;
        }
        if (biter.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "How Many Times to Repeat Current Step";
            //dtls_text = "()";
            DrawRect(biter.x, biter.y, biter.width, biter.height, select_color);
            if (GetMouse(0).bReleased) world.selected_param = world.pITER;
        }
        // X Values
        if (bminx.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Minimum Width Range Of Effect";
            dtls_text = "(0-100 %)";
            DrawRect(bminx.x, bminx.y, bminx.width, bminx.height, select_color);
            if (GetMouse(0).bReleased) world.selected_param = world.pMINX;
        }
        if (bmaxx.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Maximum Width Range Of Effect";
            dtls_text = "(0-100 %)";
            DrawRect(bmaxx.x, bmaxx.y, bmaxx.width, bmaxx.height, select_color);
            if (GetMouse(0).bReleased) world.selected_param = world.pMAXX;
        }
        // Y values
        if (bminy.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Minimum Height Range Of Effect";
            dtls_text = "(0-100 %)";
            DrawRect(bminy.x, bminy.y, bminy.width, bminy.height, select_color);
            if (GetMouse(0).bReleased) world.selected_param = world.pMINY;
        }
        if (bmaxy.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Maximum Height Range Of Effect";
            dtls_text = "(0-100 %)";
            DrawRect(bmaxy.x, bmaxy.y, bmaxy.width, bmaxy.height, select_color);
            if (GetMouse(0).bReleased) world.selected_param = world.pMAXY;
        }
        // Neighbor Values
        if (bprobn.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That A Northern Neighbor Will Spawn";
            //dtls_text = "()";
            DrawRect(bprobn.x, bprobn.y, bprobn.width, bprobn.height, select_color);
            if (GetMouse(0).bReleased) world.selected_param = world.pPROBN;
        }
        if (bprobs.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That A Southern Neighbor Will Spawn";
            //dtls_text = "()";
            DrawRect(bprobs.x, bprobs.y, bprobs.width, bprobs.height, select_color);
            if (GetMouse(0).bReleased) world.selected_param = world.pPROBS;
        }
        if (bprobe.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That An Eastern Neighbor Will Spawn";
            //dtls_text = "()";
            DrawRect(bprobe.x, bprobe.y, bprobe.width, bprobe.height, select_color);
            if (GetMouse(0).bReleased) world.selected_param = world.pPROBE;
        }
        if (bprobw.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That A Western Neighbor Will Spawn";
            //dtls_text = "()";
            DrawRect(bprobw.x, bprobw.y, bprobw.width, bprobw.height, select_color);
            if (GetMouse(0).bReleased) world.selected_param = world.pPROBW;
        }
        // Mode Value
        if (bmode.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Changes Generation Mode";
            //dtls_text = "()";
            DrawRect(bmode.x, bmode.y, bmode.width, bmode.height, select_color);
            if (GetMouse(0).bReleased) world.selected_param = world.pMODE;
        }

        // Clear Values
        if (bclear.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Clears All Generation Data";
            DrawRect(bclear.x, bclear.y, bclear.width, bclear.height, select_color);
            if (GetMouse(0).bReleased)
            {
                world.ClearData();
            }
        }
        // Auto Configure
        if (bconfig.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Standard World Generation";
            //dtls_text = "()";
            DrawRect(bconfig.x, bconfig.y, bconfig.width, bconfig.height, select_color);
            if (GetMouse(0).bReleased)
            {
                world.PresetData();
            }
        }
        // Randomize Seed
        if (brandom.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Randomizes Game Seed";
            DrawRect(brandom.x, brandom.y, brandom.width, brandom.height, select_color);
            if (GetMouse(0).bReleased)
            {
                game_seed = rand() % 9999999999;
                srand(game_seed);
                world.ClearMatrix();
                world.InitializeMatrix(100, 100);
                for (int i = 0; i < world.generation_steps; i++)
                {
                    world.GeneratePreview();
                }
                world.generation_step = 1;
                can_draw = true;
            }
        }
        // Save
        if (bsave.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Saves Generation Data";
            DrawRect(bsave.x, bsave.y, bsave.width, bsave.height, select_color);
            if (GetMouse(0).bReleased)
            {
                std::string data_dir = std::to_string(save_slot) + ".txt";
                SaveGenerationData(data_dir);
            }
        }
        // Load
        if (bload.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Loads Generation Data";
            DrawRect(bload.x, bload.y, bload.width, bload.height, select_color);
            if (GetMouse(0).bReleased)
            {
                std::string data_dir = std::to_string(save_slot) + ".txt";
                LoadGenerationData(data_dir);
            }
        }
        // Copy
        if (bcopy.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Copies Selected Generation Step";
            DrawRect(bcopy.x, bcopy.y, bcopy.width, bcopy.height, select_color);
            if (GetMouse(0).bReleased)
            {
                for (int p = 0; p < world.total_parameters; p++)
                {
                    world.clipboard_param[p] = world.generation_param[world.selected_step][p];
                }
            }
        }
        // Paste
        if (bpaste.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Pastes Selected Generation Step";
            DrawRect(bpaste.x, bpaste.y, bpaste.width, bpaste.height, select_color);
            if (GetMouse(0).bReleased)
            {
                 world.generation_steps++;
                for (int i = world.generation_steps-1; i > world.selected_step; i--)
                {
                    for (int p = 0; p < world.total_parameters; p++)
                    {
                        world.generation_param[i-1][p] = world.generation_param[i-2][p];
                    }
                }
                for (int p = 0; p < world.total_parameters; p++)
                {
                    world.generation_param[world.selected_step][p] = world.clipboard_param[p];
                }
                if (world.selected_step > 0) world.selected_step--;
            }
        }
        // Generate World
        if (bgenerate.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Generates World And Starts Game";
            DrawRect(bgenerate.x, bgenerate.y, bgenerate.width, bgenerate.height, select_color);
            if (GetMouse(0).bReleased)
            {
                bool is_data_valid = false;
                for (int i = 0; i < world.generation_steps; i++)
                {
                    if (world.generation_param[i][0] != world.AIR) is_data_valid = true;
                }
                if (!is_data_valid) world.PresetData();
                world.InitializeMatrix(world_width, world_height);
                srand(game_seed);
                game_state = LOADING;
            }
        }
        // Generate Preview
        if (bpreview.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Updates The Preview Box";
            DrawRect(bpreview.x, bpreview.y, bpreview.width, bpreview.height, select_color);
            if (GetMouse(0).bReleased)
            {
                srand(game_seed);
                world.ClearMatrix();
                world.InitializeMatrix(100, 100);
                for (int i = 0; i < world.generation_steps; i++)
                {
                    world.GeneratePreview();
                }
                world.generation_step = 1;
                can_draw = true;
            }
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
                    int v = world.matrix[y*world.width+x];
                    Draw(x+3, y+3, olc::Pixel(
                        world.tileset[v][0][0],
                        world.tileset[v][0][1],
                        world.tileset[v][0][2],
                        world.tileset[v][0][3])
                        );
                }
            }
            SetPixelMode(olc::Pixel::NORMAL);
        }
        // Draw Generation Steps
        int list_height = 0;
        int start_list = world.selected_step-9;
        int stop_list = world.selected_step+9;
        if (start_list < 0) start_list = 0;
        if (stop_list > world.generation_steps-1) stop_list = world.generation_steps-1;
        if (stop_list-start_list > 9) start_list = stop_list-9;
        for (int i = start_list; i < stop_list; i++)
        {
            std::string vlue_text = "Error";
            std::string mode_text = "Error";
            std::string tile_text = "Error";
            try
            {
                mode_text = world.modes[world.generation_param[i][world.selected_param]];
                tile_text = world.tiles[world.generation_param[i][world.selected_param]];
                vlue_text = std::to_string(world.generation_param[i][world.selected_param]);
            }
            catch (std::bad_alloc & ba) {}
            if (i == world.selected_step)
            {
                tile_text = ">" + tile_text;
                switch (world.selected_param)
                {
                    case world.pTILE : DrawStringDecal({ float(186),float((list_height*9)+10) }, tile_text, text_color, { 0.5, 0.5 }); break;
                    case world.pMODE : DrawStringDecal({ float(186),float((list_height*9)+10) }, mode_text, text_color, { 0.5, 0.5 }); break;
                    default : DrawStringDecal({ float(186),float((list_height*9)+10) }, vlue_text, text_color, { 0.5, 0.5 }); break;
                }
            }
            else
            {
                switch (world.selected_param)
                {
                    case world.pTILE : DrawStringDecal({ float(186),float((list_height*9)+10) }, tile_text, button_color, { 0.5, 0.5 }); break;
                    case world.pMODE : DrawStringDecal({ float(186),float((list_height*9)+10) }, mode_text, button_color, { 0.5, 0.5 }); break;
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
        
        if (loading)
        {
            message = world.GenerateWorld();
            
            if (world.generation_step > world.generation_steps)
            {
                sky.GenerateSky(width, height, game_seed);
                player.x = int(world.width/2);
                player.y = player.height+2;
                while (!world.IsColliding(player.x, player.y+1)) player.Move(0, 1);
                loading = false;
                game_state = PLAYING;
            }
        }
        if (!loading) loading = true;

        int prog_x = (width/2)-(width/4);
        int prog_y = (height/2)+4;

        float msg_x = width/2-((message.size()/2)*4);
        float msg_y = (height/2)-4;

        DrawStringDecal({ msg_x, msg_y }, message, text_color, { 0.5, 0.5 });
        ProgressBar(prog_x, prog_y, world.generation_step-1, world.generation_steps, width/2);

    }

    void GamePaused()
    {
        if (GetKey(olc::Key::ESCAPE).bPressed) game_state = PLAYING;
     
        if (GetKey(olc::Key::K1).bPressed) {selected_hotbar = 0;}
        if (GetKey(olc::Key::K2).bPressed) {selected_hotbar = 1;}
        if (GetKey(olc::Key::K3).bPressed) {selected_hotbar = 2;}
        if (GetKey(olc::Key::K4).bPressed) {selected_hotbar = 3;}
        if (GetKey(olc::Key::K5).bPressed) {selected_hotbar = 4;}
        if (GetKey(olc::Key::K6).bPressed) {selected_hotbar = 5;}
        if (GetKey(olc::Key::K7).bPressed) {selected_hotbar = 6;}
        if (GetKey(olc::Key::K8).bPressed) {selected_hotbar = 7;}
        if (GetKey(olc::Key::K9).bPressed) {selected_hotbar = 8;}

        if (GetKey(olc::Key::Q).bPressed && selected_tile < world.total_tiles-1) selected_tile++;
        if (GetKey(olc::Key::E).bPressed && selected_tile > 0) selected_tile--;

        if (GetKey(olc::Key::SPACE).bPressed)
        {
            world.SettleTiles(player.x-(width), player.y-(height), width*2, height*2);
            DrawSky();
            DrawTerrain();
            DrawPlayer();
        }

        if (GetKey(olc::Key::I).bPressed) pause_state = psTILES;
        if (GetKey(olc::Key::W).bPressed) pause_state = psWANDS;
        
        if (pause_state == psWANDS) DrawWands();
        if (pause_state == psTILES) DrawInventory();
        
        //if (GetKey(olc::Key::I).bReleased)
        //{
        //    DrawSky();
        //    DrawTerrain();
        //    DrawPlayer();
        //}
        DrawHUD();
    }

    void GameLoop(float fElapsedTime)
    {
        if (GetKey(olc::Key::ESCAPE).bPressed) game_state = PAUSED;
        //
        //if (GetKey(olc::Key::K0).bPressed) {selected_hotbar = 9;}
        if (GetKey(olc::Key::K1).bPressed) {selected_hotbar = 0;}
        if (GetKey(olc::Key::K2).bPressed) {selected_hotbar = 1;}
        if (GetKey(olc::Key::K3).bPressed) {selected_hotbar = 2;}
        if (GetKey(olc::Key::K4).bPressed) {selected_hotbar = 3;}
        if (GetKey(olc::Key::K5).bPressed) {selected_hotbar = 4;}
        if (GetKey(olc::Key::K6).bPressed) {selected_hotbar = 5;}
        if (GetKey(olc::Key::K7).bPressed) {selected_hotbar = 6;}
        if (GetKey(olc::Key::K8).bPressed) {selected_hotbar = 7;}
        if (GetKey(olc::Key::K9).bPressed) {selected_hotbar = 8;}
        
        // Stuff
        if (GetMouse(0).bHeld)
        {
            if (player.hotbar[selected_hotbar][0] == itNONE)
            {
            }
            if (player.hotbar[selected_hotbar][0] == itWAND)
            {
                if (player.wands[selected_wand].can_fire)
                {
                    player.wands[selected_wand].Cast();
                    Effect e = player.wands[selected_wand].effects[player.wands[selected_wand].current_effect];
                    SpawnParticle(float(GetMouseX()), float(GetMouseY()), e);
                }
            }
            int index = (GetMouseY()+(player.y-(height/2)))*world.width+(GetMouseX()+(player.x-(width/2)));
            int tile = world.matrix[index];
            int _tile = selected_tile;
            if (player.hotbar[selected_hotbar][0] == itTILE)
            {
                int index = (GetMouseY()+(player.y-(height/2)))*world.width+(GetMouseX()+(player.x-(width/2)));
                int tile = world.matrix[index];
                int _tile = player.hotbar[selected_hotbar][1];
                if (tile != world.MANTLE)
                {
                    if (_tile != world.AIR)
                    {
                        if (player.inventory.HasItem(_tile) || creative_mode)
                        {
                            int amnt = 1;
                            if (tile == world.AIR) amnt = 0;
                            player.inventory.UseItem(_tile, 1);
                            player.inventory.AddItem(tile, amnt);
                            world.matrix[index] = _tile;
                        }
                    }
                    else if (_tile == world.AIR)
                    {
                        if (tile != world.AIR) player.inventory.AddItem(tile, 1);
                        world.matrix[index] = _tile;
                    }
                }
            }
        }

        //if (GetKey(olc::Key::Q).bPressed && selected_tile < world.total_tiles-1) selected_tile++;
        //if (GetKey(olc::Key::E).bPressed && selected_tile > 0) selected_tile--;

        // Vertical Movement
        if (GetKey(olc::Key::W).bHeld)
        {
            if ((!world.IsColliding(player.x, player.y-player.height)) &&
                (player.jp > 0) &&
                (player.y > 0) )
            {
                player.jp--;
                player.vy = -1;
                player.state = player.JUMP;
            }
            else
            {
                player.vy = 1;
            }
        }

        if (GetKey(olc::Key::W).bReleased)
        {
            player.vy = 0;
            player.state = player.IDLE;
        }

        if (GetKey(olc::Key::S).bPressed)
        {
            int tile = world.matrix[(player.y+(player.height-1))*world.width+player.x];
            if (tile == world.PLANKS)
            {
                player.Move(0, 1);
            }
        }

        if (!world.IsColliding(player.x, player.y+1) && player.state != player.JUMP)
        {
            player.vy = 1;
            player.state = player.FALL;
        }

        // Horizontal Movement
        if (GetKey(olc::Key::A).bHeld && player.x > width/2)
        {
            if (player.state != player.FALL && player.state != player.JUMP) player.vy = 0;
            if (!world.IsColliding(player.x-1, player.y))
            {
                player.state = player.WALK;
                player.vx = -1;
            }
            else if (world.IsColliding(player.x-1, player.y) && !world.IsColliding(player.x-1, player.y-1))
            {
                player.state = player.WALK;
                player.vx = -1;
                player.Move(0, -1);
            }
        }
        if (GetKey(olc::Key::D).bHeld && player.x < world.width-(width/2))
        {
            if (player.state != player.FALL && player.state != player.JUMP) player.vy = 0;
            if (!world.IsColliding(player.x+1, player.y))
            {
                player.state = player.WALK;
                player.vx = 1;

            }
            else if (world.IsColliding(player.x+1, player.y) && !world.IsColliding(player.x+1, player.y-1))
            {
                player.state = player.WALK;
                player.vx = 1;
                player.Move(0, -1);
            }
        }

        if (GetKey(olc::Key::A).bReleased)
        {
            player.vx = 0;
            player.state = player.IDLE;
        }
        if (GetKey(olc::Key::D).bReleased)
        {
            player.vx = 0;
            player.state = player.IDLE;
        }

        // For Fun
        //if (GetKey(olc::Key::T).bHeld) player.status = player.TRIP;

        //if (GetKey(olc::Key::ENTER).bPressed)
        //{
        //    player.hotbar[selected_hotbar][0] = itTILE;
        //    player.hotbar[selected_hotbar][1] = selected_tile;
        //}

        // Update World
        sky.Update(fElapsedTime);
        if (game_tick == tick_delay)
        {
            game_tick = 0;
            DrawSky();
            world.SettleTiles(player.x-(width), player.y-(height), width*2, height*2);
            DrawTerrain();
        }

        // Update Player
        if (player.tick == player.tick_delay)
        {
            player.Update();
            if (player.hp < 1) player.hp = player.HP;
            // Tile Effects
            switch (world.matrix[(player.y+1)*world.width+player.x])
            {
                case world.LAVA:
                {
                    player.status = player.BURN;
                }
                break;
            }
            switch (world.matrix[(player.y-player.height)*world.width+player.x])
            {
                case world.AIR:
                {
                    if (player.status == player.DROWN) player.status = player.FINE;
                }
                break;
                case world.WATER:
                {
                    if (player.bp > 0) player.bp--;
                    else if (player.bp <= 0) player.status = player.DROWN;
                }
                break;
                case world.BRINE:
                {
                    if (player.bp > 0) player.bp--;
                    else if (player.bp <= 0) player.status = player.DROWN;
                }
                break;
                case world.HONEY:
                {
                    if (player.bp > 0) player.bp--;
                    else if (player.bp <= 0) player.status = player.DROWN;
                }
                break;
                case world.BLOOD:
                {
                    if (player.bp > 0) player.bp--;
                    else if (player.bp <= 0) player.status = player.DROWN;
                }
                break;
                case world.MUCK:
                {
                    if (player.bp > 0) player.bp--;
                    else if (player.bp <= 0) player.status = player.DROWN;
                }
                break;
                case world.MUD:
                {
                    if (player.bp > 0) player.bp--;
                    else if (player.bp <= 0) player.status = player.DROWN;
                }
                break;
                case world.LAVA:
                {
                    player.status = player.BURN;
                }
                break;
            }
            if (!world.IsColliding(player.x+player.vx, player.y+player.vy))
            {
                player.Move(player.vx, player.vy);
            }
        }
        DrawPlayer();
        player.UpdateWands(fElapsedTime);
        DrawParticles(fElapsedTime);
        DrawHUD();

        // End Frame
        game_tick++;
        player.tick++;
    }



	bool OnUserCreate() override
	{
        GenerateData();
        for (int i = 0; i < world.generation_steps; i++)
        {
            world.generation_param[i][world.pITER] = 1;
        }
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
        switch (game_state)
        {
            case PLAYING : GameLoop(fElapsedTime); break;
            case PAUSED : GamePaused(); break;
            case LOADING : DrawLoading(); break;
            case CUSTOM : DrawCustom(); break;
            case TITLE : DrawTitle(); break;
            case EXIT : {SavePlayerData(); SaveWorldData();running = false;} break;
        }
        return running;
        //return !GetKey(olc::Key::ESCAPE).bPressed;
	}
};


int main()
{
	Noice demo;
	//if (demo.Construct(256, 144, 4, 4, false, false, false))
    if (demo.Construct(256, 144, 4, 4))
		demo.Start();

	return 0;
}
