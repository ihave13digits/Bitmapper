#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif



#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include <fstream>

#include "sky.h"
#include "world.h"
#include "player.h"
#include "particle.h"
#include "inventory.h"

#include "button.h"



class Noice : public olc::PixelGameEngine
{
public:
	Noice()
	{
		sAppName = "Noice";
	}

public:

    enum STATES
    {
        TITLE,
        CUSTOM,
        LOADING,
        PLAYING
    };

    bool loading = false;

    int game_seed = 0;

    int game_tick = 0;
    int tick_delay = 2;

    int game_state = 0;

    char selected_tile = 0;
    char selected_tool = 0;
    int input_value = 0;
    char save_slot = 0;

    int width = 256;
    int height = 144;
    int world_width = 4096;
    int world_height = 2048;

    std::vector<Particle> particles;

    Sky sky = Sky();
    World world = World();
    Player player = Player();
    Inventory player_inv = Inventory();

    // Temporary

    //World preview_world = World();



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

    void SaveChunkData()
    {
    }

    void LoadChunkData()
    {
    }

    void SavePlayerData()
    {
    }

    void LoadPlayerData()
    {
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

    void SpawnParticle(float X, float Y)
    {
        float W = width/2;
        float H = height/2;
        Particle p = Particle();
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

                    int n1 = world.Neighbors(x+X, y+Y);
                    int n2 = world.Neighbors(x+X+1, y+Y);
                    int n3 = world.Neighbors(x+X+2, y+Y);
                    int n4 = world.Neighbors(x+X+3, y+Y);

                    float s1 = 1.0;
                    float s2 = 1.0;
                    float s3 = 1.0;
                    float s4 = 1.0;

                    if (n1 > 2) s1 = 1.0/(n1-2);
                    if (n2 > 2) s2 = 1.0/(n2-2);
                    if (n3 > 2) s3 = 1.0/(n3-2);
                    if (n4 > 2) s4 = 1.0/(n4-2);

                    Draw(x, y, olc::Pixel(
                                int(world.tileset[v1][0][0]*s1) + rand() % world.tileset[v1][1][0],
                                int(world.tileset[v1][0][1]*s1) + rand() % world.tileset[v1][1][1],
                                int(world.tileset[v1][0][2]*s1) + rand() % world.tileset[v1][1][2],
                                world.tileset[v1][0][3])
                            );
                    
                    Draw(x+1, y, olc::Pixel(
                                int(world.tileset[v2][0][0]*s2) + rand() % world.tileset[v2][1][0],
                                int(world.tileset[v2][0][1]*s2) + rand() % world.tileset[v2][1][1],
                                int(world.tileset[v2][0][2]*s2) + rand() % world.tileset[v2][1][2],
                                world.tileset[v2][0][3])
                            );
                    Draw(x+2, y, olc::Pixel(
                                int(world.tileset[v3][0][0]*s3) + rand() % world.tileset[v3][1][0],
                                int(world.tileset[v3][0][1]*s3) + rand() % world.tileset[v3][1][1],
                                int(world.tileset[v3][0][2]*s3) + rand() % world.tileset[v3][1][2],
                                world.tileset[v3][0][3])
                            );
                    Draw(x+3, y, olc::Pixel(
                                int(world.tileset[v4][0][0]*s4) + rand() % world.tileset[v4][1][0],
                                int(world.tileset[v4][0][1]*s4) + rand() % world.tileset[v4][1][1],
                                int(world.tileset[v4][0][2]*s4) + rand() % world.tileset[v4][1][2],
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

            particles[p].Move(vx, vy, delta, world.Collision(int(x+vx), int(y+vy)));
            if ( particles[p].destroys && world.Collision(particles[p].x, particles[p].y) )
            {
                world.matrix[int(particles[p].y+(vy+0.5))*world.width+int(particles[p].x+(vx+0.5))] = world.AIR;
            }
            if (particles[p].duration > 0.0)
            {
                particles[p].duration -= delta;
                Draw(particles[p].x-(player.x-(width/2)), particles[p].y-(player.y-(height/2)), olc::Pixel(particles[p].r, particles[p].g, particles[p].b, particles[p].a));
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
        //std::string standingon = world.tiles[world.matrix[(player.y+1)*world.width+player.x]];
        std::string lookingat = "Air";
        std::string selectedtile = world.tiles[selected_tile];
        std::string selectedcount = "";
        std::string collision_at = std::to_string(world.Collision((player.x-(width/2)+GetMouseX()), (player.y-(height/2)+GetMouseY())));

        if ( ( (lookindex < world.width*world.height) && lookindex > 0) && (world.matrix[lookindex] < world.total_tiles) )
        {
            lookingat = world.tiles[world.matrix[lookindex]];
        }
        if (player_inv.HasItem(selected_tile))
        {
            selectedcount = std::to_string(player_inv.data[selected_tile]);
        }

        //DrawStringDecal({ 4,4  }, "Particles: " + std::to_string(particles.size()), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,8 }, "State: " + std::to_string(player.state), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,12 }, "Position: (" + std::to_string(player.x) + ", " + std::to_string(player.y) + ")", olc::WHITE, { font, font });
        //DrawStringDecal({ 4,16 }, "Standing On: " + standingon, olc::WHITE, { font, font });
        //DrawStringDecal({ 4,28 }, "Light: " + std::to_string(sky.time), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,24 }, "Hue: " + std::to_string(sky.hue), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,28 }, "Clouds: " + std::to_string(sky.humidity), olc::WHITE, { font, font });
        ProgressBar(4, 2, player.hp, player.HP, 32, 255, 0, 0, 64, 0, 0);
        ProgressBar(4, 4, player.jp, player.JP, 32, 0, 255, 0, 0, 64, 0);
        ProgressBar(4, 6, player.bp, player.BP, 32, 0, 0, 255, 0, 0, 64);
        DrawStringDecal({ 4,8  }, "Looking At: " + lookingat, olc::WHITE, { font, font });
        DrawStringDecal({ 4,12 }, "Selected Tile: " + selectedtile + " " + selectedcount, olc::WHITE, { font, font });
        DrawStringDecal({ 4,16 }, "Collision: " + collision_at, olc::WHITE, { font, font });
        DrawStringDecal({ 4,20 }, "Day: " + std::to_string(sky.day), olc::WHITE, { font, font });
        DrawStringDecal({ 4,24 }, "Year: " + std::to_string(sky.year), olc::WHITE, { font, font });

    }

    void DrawTitle()
    {
        Clear(olc::BLACK);

        float Tx = (width/2)-((sAppName.size()*16)/2);
        float Ty = (height*0.25);

        float Nx = (width/2)-50;
        float Lx = (width/2)+4;
        float By = (height*0.75);

        DrawStringDecal({ Tx,Ty }, sAppName, olc::WHITE, { 2.0, 2.0 });
        
        Button bNew = Button();
        bNew.Setup(Nx, By, 48, 16, 1.0, "New");
        Button bLoad = Button();
        bLoad.Setup(Lx, By, 48, 16, 1.0, "Load");

        DrawStringDecal({ bNew.TextX(),bNew.TextY() }, bNew.text, olc::WHITE, { 1.0, 1.0 });
        DrawRect(bNew.x, bNew.y, bNew.width, bNew.height, olc::DARK_GREY);
        DrawStringDecal({ bLoad.TextX(),bLoad.TextY() }, bLoad.text, olc::WHITE, { 1.0, 1.0 });
        DrawRect(bLoad.x, bLoad.y, bLoad.width, bLoad.height, olc::DARK_GREY);

        if (bNew.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bNew.x, bNew.y, bNew.width, bNew.height, olc::WHITE);
            if (GetMouse(0).bReleased)
            {
                Clear(olc::BLACK);
                game_state = CUSTOM;
            }
        }
        if (bLoad.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bLoad.x, bLoad.y, bLoad.width, bLoad.height, olc::WHITE);
            if (GetMouse(0).bReleased)
            {
                Clear(olc::BLACK);
                game_state = CUSTOM;
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

        DrawRect(2, 2, 100, 100, olc::GREY);  // Preview Box
        DrawRect(183, 2, 70, 90, olc::GREY);  // Generation Steps Box
        DrawRect(2, 105, 251, 36, olc::GREY);  // Information Box
        DrawRect(105, 2, 32, 32, olc::GREY);  // Neighbors Box

        DrawRect(bsave.x, bsave.y, bsave.width, bsave.height, olc::DARK_GREY);
        DrawStringDecal({ bsave.TextX(),bsave.TextY() }, bsave.text, olc::WHITE, { bsave.font, bsave.font });
        DrawRect(bload.x, bload.y, bload.width, bload.height, olc::DARK_GREY);
        DrawStringDecal({ bload.TextX(),bload.TextY() }, bload.text, olc::WHITE, { bload.font, bload.font });
        
        DrawRect(bcopy.x, bcopy.y, bcopy.width, bcopy.height, olc::DARK_GREY);
        DrawStringDecal({ bcopy.TextX(),bcopy.TextY() }, bcopy.text, olc::WHITE, { bcopy.font, bcopy.font });
        DrawRect(bpaste.x, bpaste.y, bpaste.width, bpaste.height, olc::DARK_GREY);
        DrawStringDecal({ bpaste.TextX(),bpaste.TextY() }, bpaste.text, olc::WHITE, { bpaste.font, bpaste.font });
        
        DrawRect(bclear.x, bclear.y, bclear.width, bclear.height, olc::DARK_GREY);
        DrawStringDecal({ bclear.TextX(),bclear.TextY() }, bclear.text, olc::WHITE, { bclear.font, bclear.font });
        DrawRect(bconfig.x, bconfig.y, bconfig.width, bconfig.height, olc::DARK_GREY);
        DrawStringDecal({ bconfig.TextX(),bconfig.TextY() }, bconfig.text, olc::WHITE, { bconfig.font, bconfig.font });
        DrawRect(brandom.x, brandom.y, brandom.width, brandom.height, olc::DARK_GREY);
        DrawStringDecal({ brandom.TextX(),brandom.TextY() }, brandom.text, olc::WHITE, { brandom.font, brandom.font });

        DrawRect(bpreview.x, bpreview.y, bpreview.width, bpreview.height, olc::DARK_GREY);
        DrawStringDecal({ bpreview.TextX(),bpreview.TextY() }, bpreview.text, olc::WHITE, { bpreview.font, bpreview.font });
        DrawRect(bgenerate.x, bgenerate.y, bgenerate.width, bgenerate.height, olc::DARK_GREY);
        DrawStringDecal({ bgenerate.TextX(),bgenerate.TextY() }, bgenerate.text, olc::WHITE, { bgenerate.font, bgenerate.font });

        DrawRect(bminusgs.x, bminusgs.y, bminusgs.width, bminusgs.height, olc::DARK_GREY);
        DrawStringDecal({ bminusgs.TextX(),bminusgs.TextY() }, bminusgs.text, olc::WHITE, { btile.font, bminusgs.font });
        DrawRect(bplusgs.x, bplusgs.y, bplusgs.width, bplusgs.height, olc::DARK_GREY);
        DrawStringDecal({ bplusgs.TextX(),bplusgs.TextY() }, bplusgs.text, olc::WHITE, { bplusgs.font, bplusgs.font });

        DrawRect(btile.x, btile.y, btile.width, btile.height, olc::DARK_GREY);
        DrawStringDecal({ btile.TextX(),btile.TextY() }, btile.text, olc::WHITE, { btile.font, btile.font });
        DrawRect(bmode.x, bmode.y, bmode.width, bmode.height, olc::DARK_GREY);
        DrawStringDecal({ bmode.TextX(),bmode.TextY() }, bmode.text, olc::WHITE, { bmode.font, bmode.font });
        DrawRect(bdense.x, bdense.y, bdense.width, bdense.height, olc::DARK_GREY);
        DrawStringDecal({ bdense.TextX(),bdense.TextY() }, bdense.text, olc::WHITE, { bdense.font, bdense.font });
        DrawRect(biter.x, biter.y, biter.width, biter.height, olc::DARK_GREY);
        DrawStringDecal({ biter.TextX(),biter.TextY() }, biter.text, olc::WHITE, { biter.font, biter.font });

        DrawRect(bminx.x, bminx.y, bminx.width, bminx.height, olc::DARK_GREY);
        DrawStringDecal({ bminx.TextX(),bminx.TextY() }, bminx.text, olc::WHITE, { bminx.font, bminx.font });
        DrawRect(bmaxx.x, bmaxx.y, bmaxx.width, bmaxx.height, olc::DARK_GREY);
        DrawStringDecal({ bmaxx.TextX(),bmaxx.TextY() }, bmaxx.text, olc::WHITE, { bmaxx.font, bmaxx.font });
        DrawRect(bminy.x, bminy.y, bminy.width, bminy.height, olc::DARK_GREY);
        DrawStringDecal({ bminy.TextX(),bminy.TextY() }, bminy.text, olc::WHITE, { bminy.font, bminy.font });
        DrawRect(bmaxy.x, bmaxy.y, bmaxy.width, bmaxy.height, olc::DARK_GREY);
        DrawStringDecal({ bmaxy.TextX(),bmaxy.TextY() }, bmaxy.text, olc::WHITE, { bmaxy.font, bmaxy.font });

        DrawRect(bprobn.x, bprobn.y, bprobn.width, bprobn.height, olc::DARK_GREY);
        DrawStringDecal({ bprobn.TextX(),bprobn.TextY() }, bprobn.text, olc::WHITE, { bprobn.font, bprobn.font });
        DrawRect(bprobs.x, bprobs.y, bprobs.width, bprobs.height, olc::DARK_GREY);
        DrawStringDecal({ bprobs.TextX(),bprobs.TextY() }, bprobs.text, olc::WHITE, { bprobs.font, bprobs.font });
        DrawRect(bprobe.x, bprobe.y, bprobe.width, bprobe.height, olc::DARK_GREY);
        DrawStringDecal({ bprobe.TextX(),bprobe.TextY() }, bprobe.text, olc::WHITE, { bprobe.font, bprobe.font });
        DrawRect(bprobw.x, bprobw.y, bprobw.width, bprobw.height, olc::DARK_GREY);
        DrawStringDecal({ bprobw.TextX(),bprobw.TextY() }, bprobw.text, olc::WHITE, { bprobw.font, bprobw.font });

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
            DrawRect(bminusgs.x, bminusgs.y, bminusgs.width, bminusgs.height, olc::WHITE);
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
            DrawRect(bplusgs.x, bplusgs.y, bplusgs.width, bplusgs.height, olc::WHITE);
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
            DrawRect(btile.x, btile.y, btile.width, btile.height, olc::WHITE);
            if (GetMouse(0).bReleased) world.selected_param = world.pTILE;
        }
        // Density Value
        if (bdense.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability A Material Will Spawn Per Cell";
            dtls_text = "(Add Layer, Seed Material)";
            DrawRect(bdense.x, bdense.y, bdense.width, bdense.height, olc::WHITE);
            if (GetMouse(0).bReleased) world.selected_param = world.pDENSE;
        }
        if (biter.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "How Many Times to Repeat Current Step";
            //dtls_text = "()";
            DrawRect(biter.x, biter.y, biter.width, biter.height, olc::WHITE);
            if (GetMouse(0).bReleased) world.selected_param = world.pITER;
        }
        // X Values
        if (bminx.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Minimum Width Range Of Effect";
            dtls_text = "(0-100 %)";
            DrawRect(bminx.x, bminx.y, bminx.width, bminx.height, olc::WHITE);
            if (GetMouse(0).bReleased) world.selected_param = world.pMINX;
        }
        if (bmaxx.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Maximum Width Range Of Effect";
            dtls_text = "(0-100 %)";
            DrawRect(bmaxx.x, bmaxx.y, bmaxx.width, bmaxx.height, olc::WHITE);
            if (GetMouse(0).bReleased) world.selected_param = world.pMAXX;
        }
        // Y values
        if (bminy.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Minimum Height Range Of Effect";
            dtls_text = "(0-100 %)";
            DrawRect(bminy.x, bminy.y, bminy.width, bminy.height, olc::WHITE);
            if (GetMouse(0).bReleased) world.selected_param = world.pMINY;
        }
        if (bmaxy.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Maximum Height Range Of Effect";
            dtls_text = "(0-100 %)";
            DrawRect(bmaxy.x, bmaxy.y, bmaxy.width, bmaxy.height, olc::WHITE);
            if (GetMouse(0).bReleased) world.selected_param = world.pMAXY;
        }
        // Neighbor Values
        if (bprobn.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That A Northern Neighbor Will Spawn";
            //dtls_text = "()";
            DrawRect(bprobn.x, bprobn.y, bprobn.width, bprobn.height, olc::WHITE);
            if (GetMouse(0).bReleased) world.selected_param = world.pPROBN;
        }
        if (bprobs.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That A Southern Neighbor Will Spawn";
            //dtls_text = "()";
            DrawRect(bprobs.x, bprobs.y, bprobs.width, bprobs.height, olc::WHITE);
            if (GetMouse(0).bReleased) world.selected_param = world.pPROBS;
        }
        if (bprobe.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That An Eastern Neighbor Will Spawn";
            //dtls_text = "()";
            DrawRect(bprobe.x, bprobe.y, bprobe.width, bprobe.height, olc::WHITE);
            if (GetMouse(0).bReleased) world.selected_param = world.pPROBE;
        }
        if (bprobw.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That A Western Neighbor Will Spawn";
            //dtls_text = "()";
            DrawRect(bprobw.x, bprobw.y, bprobw.width, bprobw.height, olc::WHITE);
            if (GetMouse(0).bReleased) world.selected_param = world.pPROBW;
        }
        // Mode Value
        if (bmode.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Changes Generation Mode";
            //dtls_text = "()";
            DrawRect(bmode.x, bmode.y, bmode.width, bmode.height, olc::WHITE);
            if (GetMouse(0).bReleased) world.selected_param = world.pMODE;
        }

        // Clear Values
        if (bclear.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Clears All Generation Data";
            DrawRect(bclear.x, bclear.y, bclear.width, bclear.height, olc::WHITE);
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
            DrawRect(bconfig.x, bconfig.y, bconfig.width, bconfig.height, olc::WHITE);
            if (GetMouse(0).bReleased)
            {
                world.PresetData();
            }
        }
        // Randomize Seed
        if (brandom.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Randomizes Game Seed";
            DrawRect(brandom.x, brandom.y, brandom.width, brandom.height, olc::WHITE);
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
            DrawRect(bsave.x, bsave.y, bsave.width, bsave.height, olc::WHITE);
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
            DrawRect(bload.x, bload.y, bload.width, bload.height, olc::WHITE);
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
            DrawRect(bcopy.x, bcopy.y, bcopy.width, bcopy.height, olc::WHITE);
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
            DrawRect(bpaste.x, bpaste.y, bpaste.width, bpaste.height, olc::WHITE);
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
            DrawRect(bgenerate.x, bgenerate.y, bgenerate.width, bgenerate.height, olc::WHITE);
            if (GetMouse(0).bReleased)
            {
                world.InitializeMatrix(world_width, world_height);
                srand(game_seed);
                game_state = LOADING;
            }
        }
        // Generate Preview
        if (bpreview.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Updates The Preview Box";
            DrawRect(bpreview.x, bpreview.y, bpreview.width, bpreview.height, olc::WHITE);
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
                    //std::cout << v;
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
                    case world.pTILE : DrawStringDecal({ float(186),float((list_height*9)+10) }, tile_text, olc::WHITE, { 0.5, 0.5 }); break;
                    case world.pMODE : DrawStringDecal({ float(186),float((list_height*9)+10) }, mode_text, olc::WHITE, { 0.5, 0.5 }); break;
                    default : DrawStringDecal({ float(186),float((list_height*9)+10) }, vlue_text, olc::WHITE, { 0.5, 0.5 }); break;
                }
            }
            else
            {
                switch (world.selected_param)
                {
                    case world.pTILE : DrawStringDecal({ float(186),float((list_height*9)+10) }, tile_text, olc::DARK_GREY, { 0.5, 0.5 }); break;
                    case world.pMODE : DrawStringDecal({ float(186),float((list_height*9)+10) }, mode_text, olc::DARK_GREY, { 0.5, 0.5 }); break;
                    default : DrawStringDecal({ float(186),float((list_height*9)+10) }, vlue_text, olc::DARK_GREY, { 0.5, 0.5 }); break;
                }
            }
            list_height++;
        }
        // Draw Info
        DrawStringDecal({ 5,109 }, info_text, olc::WHITE, { 0.5, 0.5 });
        DrawStringDecal({ 5,115 }, dtls_text, olc::WHITE, { 0.5, 0.5 });

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

        DrawStringDecal({ msg_x, msg_y }, message, olc::WHITE, { 0.5, 0.5 });
        ProgressBar(prog_x, prog_y, world.generation_step, world.generation_steps, width/2);

    }

    void GameLoop(float fElapsedTime)
    {
        // Stuff
        if (GetMouse(0).bHeld) SpawnParticle(float(GetMouseX()), float(GetMouseY()));

        if (GetMouse(1).bHeld)
        {
            int index = (GetMouseY()+(player.y-(height/2)))*world.width+(GetMouseX()+(player.x-(width/2)));
            int tile = world.matrix[index];
            if (tile != world.MANTLE)
            {
                if (selected_tile != world.AIR)
                {
                    if (player_inv.HasItem(selected_tile))
                    {
                        int amnt = 1;
                        if (tile == world.AIR) amnt = 0;
                        player_inv.UseItem(selected_tile, 1);
                        player_inv.AddItem(tile, amnt);
                        world.matrix[index] = selected_tile;
                    }
                }
                else if (selected_tile == world.AIR)
                {
                    if (tile != world.AIR) player_inv.AddItem(tile, 1);
                    world.matrix[index] = selected_tile;
                }
            }
        }

        if (GetKey(olc::Key::Q).bPressed && selected_tile < world.total_tiles-1) selected_tile++;
        if (GetKey(olc::Key::E).bPressed && selected_tile > 0) selected_tile--;

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
        if (GetKey(olc::Key::T).bHeld) player.status = player.TRIP;

        // Update World
        if (game_tick == tick_delay)
        {
            sky.Update(fElapsedTime);
            DrawSky();
            game_tick = 0;
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
                case world.LAVA:
                {
                    player.status = player.BURN;
                }
                break;
            }
            if (!world.IsColliding(player.x+player.vx, player.y+player.vy)) player.Move(player.vx, player.vy);
            DrawPlayer();
        }
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
            case LOADING : DrawLoading(); break;
            case CUSTOM : DrawCustom(); break;
            case TITLE : DrawTitle(); break;
        }
        return !GetKey(olc::Key::ESCAPE).bPressed;
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
