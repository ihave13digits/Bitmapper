#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "sky.h"
#include "world.h"
#include "player.h"
#include "particle.h"
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

    int selected_tile = 0;

    int width = 256;
    int height = 144;
    int world_width = 4096;
    int world_height = 2048;

    std::vector<Particle> particles;

    Sky sky = Sky();
    World world = World();
    Player player = Player();

    // Temporary

    World preview_world = World();



    void SpawnParticle(int X, int Y)
    {
        int W = width/2;
        int H = height/2;
        Particle p = Particle();
        p.Position(W, H);
        p.Velocity(X-W, Y-H);
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
        sky.Update();
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
            FillCircle(x, y, sky.clouds[i][2], olc::Pixel(sky.r, sky.g, sky.b, 8));
        }
        if (sky.humidity > sky.cloudcount/4)
        {
            if (rand()%sky.cloudcount < sky.humidity)
            {
                if (sky.day < sky.year_length*0.9) world.matrix[256*world.width+((rand()%width)+player.x-(width/2))] = world.WATER;
                else if (sky.day >= sky.year_length*0.9) world.matrix[256*world.width+((rand()%width)+player.x-(width/2))] = world.SNOW;
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
            int x = particles[p].x+(player.x-(width/2));
            int y = particles[p].y+(player.y-(height/2));
            int vx = particles[p].vx;
            int vy = particles[p].vy;

            if (!world.Collision(x+vx, y+vy)) particles[p].Move(vx, vy);
            if ( particles[p].destroys && world.Collision(x, y) ) world.matrix[(y)*world.width+(x)] = world.AIR;
            
            if (particles[p].duration > 0.0)
            {
                particles[p].duration -= delta;
                Draw(particles[p].x, particles[p].y, olc::Pixel(particles[p].r, particles[p].g, particles[p].b, particles[p].a));
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

        if ( ( (lookindex < world.width*world.height) && lookindex > 0) && (world.matrix[lookindex] < world.total_tiles) )
            lookingat = world.tiles[world.matrix[lookindex]];

        //DrawStringDecal({ 4,4  }, "Particles: " + std::to_string(particles.size()), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,8 }, "State: " + std::to_string(player.state), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,12 }, "Position: (" + std::to_string(player.x) + ", " + std::to_string(player.y) + ")", olc::WHITE, { font, font });
        //DrawStringDecal({ 4,16 }, "Standing On: " + standingon, olc::WHITE, { font, font });
        //DrawStringDecal({ 4,20 }, "Light: " + std::to_string(sky.time), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,24 }, "Hue: " + std::to_string(sky.hue), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,28 }, "Clouds: " + std::to_string(sky.humidity), olc::WHITE, { font, font });
        ProgressBar(4, 2, player.hp, player.HP, 32, 255, 0, 0, 64, 0, 0);
        ProgressBar(4, 4, player.jp, player.JP, 32, 0, 255, 0, 0, 64, 0);
        ProgressBar(4, 6, player.bp, player.BP, 32, 0, 0, 255, 0, 0, 64);
        DrawStringDecal({ 4,8  }, "Looking At: " + lookingat, olc::WHITE, { font, font });
        DrawStringDecal({ 4,12 }, "Selected Tile: " + selectedtile, olc::WHITE, { font, font });
        DrawStringDecal({ 4,16 }, "Collision: " + std::to_string(world.Collision((player.x-(width/2)+GetMouseX()), (player.y-(height/2)+GetMouseY()))), olc::WHITE, { font, font });
        DrawStringDecal({ 4,20 }, "Day: " + std::to_string(sky.day), olc::WHITE, { font, font });
        DrawStringDecal({ 4,24 }, "Year: " + std::to_string(sky.year), olc::WHITE, { font, font });

    }

    void DrawTitle()
    {
        Clear(olc::BLACK);

        float Tx = (width/2)-((sAppName.size()*16)/2);
        float Ty = (height*0.25);

        float Nx = (width/2)-36;
        float Lx = (width/2)+4;
        float By = (height*0.75);

        DrawStringDecal({ Tx,Ty }, sAppName, olc::WHITE, { 2.0, 2.0 });
        
        DrawStringDecal({ Nx,By }, "New", olc::WHITE, { 1.0, 1.0 });
        DrawStringDecal({ Lx,By }, "Load", olc::WHITE, { 1.0, 1.0 });

        if (GetMouse(0).bReleased) game_state = CUSTOM;
    }

    void DrawCustom()
    {
        //Clear(olc::BLACK);

        bool can_draw = false;

        // Update Parameters
        if (GetKey(olc::Key::S).bPressed)
        {
            if (preview_world.selected_step < 255) preview_world.selected_step++;
        }
        if (GetKey(olc::Key::W).bPressed)
        {
            if (preview_world.selected_step > 0) preview_world.selected_step--;
        }

        if (GetKey(olc::Key::A).bPressed)
        {
            if (preview_world.generation_param[preview_world.selected_step][preview_world.selected_param] > 0)
            {
                preview_world.generation_param[preview_world.selected_step][preview_world.selected_param]--;
            }
        }
        if (GetKey(olc::Key::D).bPressed)
        {
            if (preview_world.generation_param[preview_world.selected_step][preview_world.selected_param] < preview_world.total_tiles-1)
            {
                preview_world.generation_param[preview_world.selected_step][preview_world.selected_param]++;
            }
        }

        // Buttons
        Button bpreview = Button();
        bpreview.Setup(8, 104, 32, 16, 0.25, "Preview");
        Button bgenerate = Button();
        bgenerate.Setup(8, 124, 32, 16, 0.25, "Generate");
        
        Button btile = Button();
        btile.Setup(56, 88, 16, 8, 0.25, "Tile");
        Button bmode = Button();
        bmode.Setup(56, 96, 16, 8, 0.25, "Mode");
        Button bdense = Button();
        bdense.Setup(56, 104, 16, 8, 0.25, "Density");
        Button biter = Button();
        biter.Setup(56, 112, 16, 8, 0.25, "Repeat");

        Button bminx = Button();
        bminx.Setup(78, 88, 16, 8, 0.25, "Min X");
        Button bmaxx = Button();
        bmaxx.Setup(78, 96, 16, 8, 0.25, "Max X");
        Button bminy = Button();
        bminy.Setup(78, 104, 16, 8, 0.25, "Min Y");
        Button bmaxy = Button();
        bmaxy.Setup(78, 112, 16, 8, 0.25, "Max Y");

        Button bprobn = Button();
        bprobn.Setup(120, 88, 8, 8, 0.25, "N");
        Button bprobs = Button();
        bprobs.Setup(120, 104, 8, 8, 0.25, "S");
        Button bprobe = Button();
        bprobe.Setup(128, 96, 8, 8, 0.25, "E");
        Button bprobw = Button();
        bprobw.Setup(112, 96, 8, 8, 0.25, "W");

        DrawRect(7, 7, 130, 74, olc::GREY);  // Preview Box
        DrawRect(142, 0, 113, 143, olc::GREY);  // Generation Steps

        DrawRect(bpreview.x, bpreview.y, bpreview.width, bpreview.height, olc::DARK_GREY);
        DrawStringDecal({ bpreview.TextX(),bpreview.TextY() }, bpreview.text, olc::WHITE, { bpreview.font, bpreview.font });
        DrawRect(bgenerate.x, bgenerate.y, bgenerate.width, bgenerate.height, olc::DARK_GREY);
        DrawStringDecal({ bgenerate.TextX(),bgenerate.TextY() }, bgenerate.text, olc::WHITE, { bgenerate.font, bgenerate.font });

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

        DrawRect(bprobn.x, bprobn.y, bprobn.width, bprobn.height, olc::DARK_GREY);  // Probability North
        DrawStringDecal({ bprobn.TextX(),bprobn.TextY() }, bprobn.text, olc::WHITE, { bprobn.font, bprobn.font });
        DrawRect(bprobs.x, bprobs.y, bprobs.width, bprobs.height, olc::DARK_GREY);  // Probability South
        DrawStringDecal({ bprobs.TextX(),bprobs.TextY() }, bprobs.text, olc::WHITE, { bprobs.font, bprobs.font });
        DrawRect(bprobe.x, bprobe.y, bprobe.width, bprobe.height, olc::DARK_GREY);  // Probability East
        DrawStringDecal({ bprobe.TextX(),bprobe.TextY() }, bprobe.text, olc::WHITE, { bprobe.font, bprobe.font });
        DrawRect(bprobw.x, bprobw.y, bprobw.width, bprobw.height, olc::DARK_GREY);  // Probability West
        DrawStringDecal({ bprobw.TextX(),bprobw.TextY() }, bprobw.text, olc::WHITE, { bprobw.font, bprobw.font });

        for (int i = 0; i < preview_world.generation_steps; i++)
        {
            if (preview_world.selected_param == preview_world.pTILE)
            {
                DrawStringDecal(
                    { float(144),float((i*8)+8) },
                    preview_world.tiles[preview_world.generation_param[i][preview_world.selected_param]],
                    olc::WHITE, { 0.5, 0.5 });
            }

            else if (preview_world.selected_param == preview_world.pMODE)
            {
                DrawStringDecal(
                    { float(144),float((i*8)+8) },
                    preview_world.modes[preview_world.generation_param[i][preview_world.selected_param]],
                    olc::WHITE, { 0.5, 0.5 });
            }
            else
            {
                DrawStringDecal(
                    { float(144),float((i*8)+8) },
                    std::to_string(preview_world.generation_param[i][preview_world.selected_param]),
                    olc::WHITE, { 0.5, 0.5 });
            }
        }
        // Tile Value
        if (btile.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(btile.x, btile.y, btile.width, btile.height, olc::WHITE);
            if (GetMouse(0).bReleased) preview_world.selected_param = preview_world.pTILE;
        }
        // Density Value
        if (bdense.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bdense.x, bdense.y, bdense.width, bdense.height, olc::WHITE);
            if (GetMouse(0).bReleased) preview_world.selected_param = preview_world.pDENSE;
        }
        if (biter.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(biter.x, biter.y, biter.width, biter.height, olc::WHITE);
            if (GetMouse(0).bReleased) preview_world.selected_param = preview_world.pITER;
        }
        // X Values
        if (bminx.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bminx.x, bminx.y, bminx.width, bminx.height, olc::WHITE);
            if (GetMouse(0).bReleased) preview_world.selected_param = preview_world.pMINX;
        }
        if (bmaxx.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bmaxx.x, bmaxx.y, bmaxx.width, bmaxx.height, olc::WHITE);
            if (GetMouse(0).bReleased) preview_world.selected_param = preview_world.pMAXX;
        }
        // Y values
        if (bminy.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bminy.x, bminy.y, bminy.width, bminy.height, olc::WHITE);
            if (GetMouse(0).bReleased) preview_world.selected_param = preview_world.pMINY;
        }
        if (bmaxy.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bmaxy.x, bmaxy.y, bmaxy.width, bmaxy.height, olc::WHITE);
            if (GetMouse(0).bReleased) preview_world.selected_param = preview_world.pMAXY;
        }
        // Neighbor Values
        if (bprobn.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bprobn.x, bprobn.y, bprobn.width, bprobn.height, olc::WHITE);
            if (GetMouse(0).bReleased) preview_world.selected_param = preview_world.pPROBN;
        }
        if (bprobs.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bprobs.x, bprobs.y, bprobs.width, bprobs.height, olc::WHITE);
            if (GetMouse(0).bReleased) preview_world.selected_param = preview_world.pPROBS;
        }
        if (bprobe.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bprobe.x, bprobe.y, bprobe.width, bprobe.height, olc::WHITE);
            if (GetMouse(0).bReleased) preview_world.selected_param = preview_world.pPROBE;
        }
        if (bprobw.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bprobw.x, bprobw.y, bprobw.width, bprobw.height, olc::WHITE);
            if (GetMouse(0).bReleased) preview_world.selected_param = preview_world.pPROBW;
        }
        // Mode Value
        if (bmode.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bmode.x, bmode.y, bmode.width, bmode.height, olc::WHITE);
            if (GetMouse(0).bReleased) preview_world.selected_param = preview_world.pMODE;
        }

        // Generate World
        if (bgenerate.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bgenerate.x, bgenerate.y, bgenerate.width, bgenerate.height, olc::WHITE); // Generate World
            if (GetMouse(0).bReleased)
            {
                world.InitializeMatrix(world_width, world_height);
                for (int i = 0; i < preview_world.generation_steps; i++)
                {
                    for (int j = 0; j < world.total_parameters; j++)
                    {
                        world.generation_param[i][j] = preview_world.generation_param[i][j];
                    }
                }
                preview_world.ClearMatrix();
                game_state = LOADING;
            }
        }
        // Generate Preview
        if (bpreview.IsColliding(GetMouseX(), GetMouseY()))
        {
            DrawRect(bpreview.x, bpreview.y, bpreview.width, bpreview.height, olc::WHITE); // Generate Preview
            if (GetMouse(0).bReleased)
            {
                preview_world.ClearMatrix();
                preview_world.InitializeMatrix(128, 72);
                for (int i = 1; i < preview_world.generation_steps; i++)
                {
                    preview_world.GenerateWorld(game_seed);
                }
                preview_world.generation_step = 1;
                can_draw = true;
            }
        }

        if (can_draw)
        {
            FillRect(8, 8, 128, 72, olc::BLACK);
            SetPixelMode(olc::Pixel::ALPHA);
            for (int y = 0; y < 72; y++)
            {
                for (int x = 0; x < 128; x++)
                {
                    int v = preview_world.matrix[y*preview_world.width+x];
                    Draw(x+8, y+8, olc::Pixel(
                        int(preview_world.tileset[v][0][0]),
                        int(preview_world.tileset[v][0][1]),
                        int(preview_world.tileset[v][0][2]),
                        preview_world.tileset[v][0][3])
                        );
                }
            }
            SetPixelMode(olc::Pixel::NORMAL);
        }

    }

    void DrawLoading()
    {
        Clear(olc::BLACK);
        
        std::string message = "Generating World, Please Wait.";
        
        if (loading)
        {
            message = world.GenerateWorld(game_seed);
            
            if (world.generation_step > world.generation_steps)
            {
                sky.GenerateSky(width, height, game_seed, tick_delay);
                player.x = int(world.width/2);
                player.y = player.height;
                while (!world.Collision(player.x, player.y+1)) player.Move(0, 1);
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
        if (GetMouse(0).bHeld) SpawnParticle(GetMouseX(), GetMouseY());

        if ((GetMouse(1).bHeld) && (world.matrix[(GetMouseY()+(player.y-(height/2)))*world.width+(GetMouseX()+(player.x-(width/2)))] != world.MANTLE))
        {
            world.matrix[(GetMouseY()+(player.y-(height/2)))*world.width+(GetMouseX()+(player.x-(width/2)))] = selected_tile;
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
            DrawSky();
            game_tick = 0;
            world.SettleTiles(player.x-(width/2), player.y-(height*2), width, height*3);
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
        sky.tick++;
    }



	bool OnUserCreate() override
	{
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
