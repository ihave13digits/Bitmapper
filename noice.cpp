#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "sky.h"
#include "world.h"
#include "player.h"
#include "particle.h"

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



    int Normal(int n, int m)
    {
        float value = n/m;
        return value;
    }

    void SpawnParticle(int X, int Y)
    {
        int W = width/2;
        int H = height/2;
        Particle p = Particle();
        p.Position(W, H);
        p.Velocity(X-W, Y-H);
        particles.push_back(p);
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
            FillCircle(sky.moonx, sky.moony, sky.moon*0.95, olc::Pixel(225, 225, 225));
            FillCircle(sky.moonx-2, sky.moony+1, sky.moon/2, olc::GREY);
            FillCircle(sky.moonx+3, sky.moony+3, sky.moon/2, olc::GREY);
            FillCircle(sky.moonx+2, sky.moony-1, sky.moon/3, olc::DARK_GREY);
            FillCircle(sky.moonx-3, sky.moony-4, sky.moon/3, olc::DARK_GREY);
            FillCircle(sky.moonx-2, sky.moony+3, sky.moon/4, olc::DARK_GREY);
            FillCircle(sky.moonx+3, sky.moony+4, sky.moon/4, olc::DARK_GREY);
            FillCircle(sky.moonx+3, sky.moony-2, sky.moon/5, olc::VERY_DARK_GREY);
            FillCircle(sky.moonx-4, sky.moony-3, sky.moon/5, olc::VERY_DARK_GREY);
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
            case player.POISON :   {r=0;   g=255; b=0;  } break;
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
        std::string standingon = world.tiles[world.matrix[(player.y+1)*world.width+player.x]];
        std::string lookingat = "Air";
        std::string selectedtile = world.tiles[selected_tile];

        if ( ( (lookindex < world.width*world.height) && lookindex > 0) && (world.matrix[lookindex] < world.total_tiles) )
            lookingat = world.tiles[world.matrix[lookindex]];

        //DrawStringDecal({ 4,4  }, "Particles: " + std::to_string(particles.size()), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,8  }, "Jump: " + std::to_string(player.jp), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,12 }, "State: " + std::to_string(player.state), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,16 }, "Position: (" + std::to_string(player.x) + ", " + std::to_string(player.y) + ")", olc::WHITE, { font, font });
        //DrawStringDecal({ 4,20 }, "Standing On: " + standingon, olc::WHITE, { font, font });
        ProgressBar(4, 2, player.hp, player.HP, 32);
        ProgressBar(4, 4, player.jp, player.JP, 32);
        DrawStringDecal({ 4,8  }, "Looking At: " + lookingat, olc::WHITE, { font, font });
        DrawStringDecal({ 4,12 }, "Selected Tile: " + selectedtile, olc::WHITE, { font, font });
        DrawStringDecal({ 4,16 }, "Collision: " + std::to_string(world.Collision((player.x-(width/2)+GetMouseX()), (player.y-(height/2)+GetMouseY()))), olc::WHITE, { font, font });
        DrawStringDecal({ 4,20 }, "Day: " + std::to_string(sky.day), olc::WHITE, { font, font });
        DrawStringDecal({ 4,24 }, "Year: " + std::to_string(sky.year), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,32 }, "Light: " + std::to_string(sky.time), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,36 }, "Hue: " + std::to_string(sky.hue), olc::WHITE, { font, font });
        DrawStringDecal({ 4,40 }, "Clouds: " + std::to_string(sky.humidity), olc::WHITE, { font, font });

    }

    void ProgressBar(int x, int y, int minv, int maxv, int W)
    {
        float completed = float(minv)/float(maxv);
        int x2 = W*completed;
        DrawLine(x, y, x+W, y, olc::VERY_DARK_GREY);
        DrawLine(x, y, x+x2, y, olc::WHITE);
    }

    void DrawLoading()
    {
        Clear(olc::BLACK);
        
        // Show Message
        float msg_x = width/2-(15*4);
        float msg_y = (height/2)-4;
        std::string message = "Generating World, Please Wait.";
        DrawStringDecal({ msg_x, msg_y }, message, olc::WHITE, { 0.5, 0.5 });
        
        // Progress Bar
        //float completed = float(world.generation_step)/float(world.generation_steps);
        int prog_x = (width/2)-(width/4);
        int prog_y = (height/2)+4;
        //DrawLine(prog_x1, prog_y, prog_x1+prog_x2, prog_y, olc::WHITE);
        ProgressBar(prog_x, prog_y, world.generation_step, world.generation_steps, width/2);

        if (loading)
        {
            world.GenerateWorld(world_width, world_height, game_seed);
            
            if (world.generation_step > world.generation_steps)
            {
                sky.GenerateSky(width, height, game_seed, tick_delay);
                player.x = int(world.width/2);
                player.y = 0;
                while (!world.Collision(player.x, player.y+1)) player.Move(0, 1);
                loading = false;
                game_state = PLAYING;
            }
        }
        if (!loading) loading = true;
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
            if ((!world.Collision(player.x, player.y-player.height)) &&
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

        if (!world.Collision(player.x, player.y+1) && player.state != player.JUMP)
        {
            player.vy = 1;
            player.state = player.FALL;
        }
    
        // Horizontal Movement
        if (GetKey(olc::Key::A).bHeld && player.x > width/2)
        {
            if (player.state != player.FALL && player.state != player.JUMP) player.vy = 0;
            if (!world.Collision(player.x-1, player.y))
            {
                player.state = player.WALK;
                player.vx = -1;
            }
            else if (world.Collision(player.x-1, player.y) && !world.Collision(player.x-1, player.y-1))
            {
                player.state = player.WALK;
                player.vx = -1;
                player.Move(0, -1);
            }
        }
        if (GetKey(olc::Key::D).bHeld && player.x < world.width-(width/2))
        {
            if (player.state != player.FALL && player.state != player.JUMP) player.vy = 0;
            if (!world.Collision(player.x+1, player.y))
            {
                player.state = player.WALK;
                player.vx = 1;

            }
            else if (world.Collision(player.x+1, player.y) && !world.Collision(player.x+1, player.y-1))
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
            player.tick = 0;
            // Check Death
            if (player.hp < 1) player.hp = player.HP;
            // Tile Effects
            switch (world.matrix[(player.y+1)*world.width+player.x])
            {
                case world.LAVA:
                {
                    player.status = player.BURN;
                }
            }
            // Update Counters
            if (player.jp < player.JP && player.state != player.JUMP) player.jp++;
            // Update Tick Damage
            if (player.status != player.FINE) player.damage_tick++;
            if (player.damage_tick > player.damage_delay)
            {
                player.damage_tick = 0;
                if (player.status == player.BURN)
                {
                    player.TakeDamage(1);
                    player.burn_tick++;
                    if (player.burn_tick > 25)
                    {
                        player.burn_tick = 0;
                        player.status = player.FINE;
                    }
                }
            }
            if (!world.Collision(player.x+player.vx, player.y+player.vy)) player.Move(player.vx, player.vy);
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
        }
        return !GetKey(olc::Key::ESCAPE).bPressed;
	}
};


int main()
{
	Noice demo;
	//if (demo.Construct(256, 144, 4, 4, false, false, false))
    if (demo.Construct(256, 144, 4, 4, false))
		demo.Start();

	return 0;
}
