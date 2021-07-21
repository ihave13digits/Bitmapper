namespace iSystem
{

    Sky sky = Sky();
    World world = World();
    Player player = Player();
    Camera camera = Camera();
    std::vector<Particle> particles;

    void SpawnParticle(float X, float Y, Effect e)
    {
        float W = core::width/2;
        float H = core::height/2;
        Particle p = Particle();
        p.SetEffect(e);
        p.Position(player.x+(player.direction*(player.height/4)), player.y-player.height/2);
        p.Velocity(float(((X-(player.height/2))-W)*0.1), float(((Y-(player.height-1))-H)*0.1));
        p.Color(tTile::R[e.tile_value], tTile::G[e.tile_value], tTile::B[e.tile_value], tTile::A[e.tile_value]);
        particles.push_back(p);
    }

    void UpdateParticle(float delta, int p, float x, float y)
    {
        float vx = particles[p].vx;
        float vy = particles[p].vy;

        int collision_x = int(x+vx);
        int collision_y = int(y+vy);

        particles[p].Move(vx, vy, delta, tTool::IsColliding(int(x+vx), int(y+vy)));
        if ( tTool::IsColliding(collision_x, collision_y) )
        {
            int collision_index = collision_y*tCell::width+collision_x;
            if ( particles[p].effect.destroys )
            {
                tCell::matrix[collision_index] = tTile::AIR;
            }
            if ( particles[p].effect.mines )
            {
                iSystem::player.inventory.AddItem(tCell::matrix[collision_index], 1);
                tCell::matrix[collision_index] = tTile::AIR;
            }
            if (particles[p].effect.becomes)
            {
                if (tTool::GetType(particles[p].effect.tile_value) == tTile::BOOM)
                {
                    if (!particles[p].effect.pierces) particles.erase(particles.begin()+p);
                    tCell::matrix[collision_index-tCell::width] = tTile::FIRE;
                }
                tCell::matrix[collision_index] = particles[p].effect.tile_value;
            }
        }
        if (particles[p].effect.trails && particles[p].CanDrop(delta))
        {
            tCell::matrix[collision_y*tCell::width+collision_x] = particles[p].effect.tile_trail;
        }
    }
}
