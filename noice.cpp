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
        if (player.state != player.TRIP) Clear(olc::Pixel(sky.R, sky.G, sky.B));
        
        if (sky.starlight > 0)
        {
            SetPixelMode(olc::Pixel::ALPHA);
            for (int i = 0; i < sky.starcount; i++)
            {
                int value = rand()%200+55;
                Draw(sky.stars[i][0], sky.stars[i][1], olc::Pixel(value, value, value, 255-sky.starlight));
            }
            SetPixelMode(olc::Pixel::NORMAL);
        }

        if (sky.time > 0.5) FillCircle(sky.sunx, sky.suny, sky.sun, olc::WHITE);
        else if (sky.time < 0.5) FillCircle(sky.moonx, sky.moony, sky.moon, olc::WHITE);

        SetPixelMode(olc::Pixel::ALPHA);
        for (int i = 0; i < sky.humidity; i++)
        {
            int x = sky.clouds[i][0];
            int y = sky.clouds[i][1];
            FillCircle(x, y, sky.clouds[i][2], olc::Pixel(sky.r, sky.g, sky.b, 8));
            if ((sky.humidity > sky.cloudcount/2) && (rand()%100 < 2))
            {
                world.matrix[y*world.width+(x+player.x-(width/2))] = world.WATER;
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
        Draw(int(width/2), int(height/2), olc::Pixel(255, 255, 255, 255));
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
        DrawStringDecal({ 4,4 }, "Looking At: " + lookingat, olc::WHITE, { font, font });
        DrawStringDecal({ 4,8 }, "Selected Tile: " + selectedtile, olc::WHITE, { font, font });
        DrawStringDecal({ 4,12 }, "Collision: " + std::to_string(world.Collision((player.x-(width/2)+GetMouseX()), (player.y-(height/2)+GetMouseY()))), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,32 }, "Light: " + std::to_string(sky.time), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,36 }, "Hue: " + std::to_string(sky.hue), olc::WHITE, { font, font });
        //DrawStringDecal({ 4,40 }, "Clouds: " + std::to_string(sky.humidity), olc::WHITE, { font, font });

    }

    void DrawLoading()
    {
        float x = width/2-(15*4);
        float y = (height/2)-4;
        Clear(olc::BLACK);
        DrawStringDecal({ x,y  }, "Generating World, Please Wait.", olc::WHITE, { 0.5, 0.5 });

        if (loading)
        {
            sky.GenerateSky(width, height, game_seed, tick_delay);
            world.GenerateWorld(world_width, world_height, game_seed);
            player.x = int(world.width/2);
            player.y = 0;
            while (!world.Collision(player.x, player.y+1)) player.Move(0, 1);
            loading = false;
            game_state = PLAYING;
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
        if (GetKey(olc::Key::W).bHeld && !world.Collision(player.x, player.y-1) && player.y > 0)
        {
            if ((player.jp > 0) && (player.y > 0) )
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
        if (GetKey(olc::Key::T).bHeld) player.state = player.TRIP;

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
            if (player.jp < player.JP && player.state != player.JUMP) player.jp++;
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
        if (game_state == PLAYING) GameLoop(fElapsedTime);
        else if (game_state == LOADING) DrawLoading();
        return !GetKey(olc::Key::ESCAPE).bPressed;
	}
};


int main()
{
	Noice demo;
	if (demo.Construct(256, 144, 4, 4, false, false, false))
		demo.Start();

	return 0;
}
