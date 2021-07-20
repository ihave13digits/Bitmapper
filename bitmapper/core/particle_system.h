namespace pSystem
{
    std::vector<Particle> particles;

    void SpawnParticle(float X, float Y, Effect e)
    {
        float W = core::width/2;
        float H = core::height/2;
        Particle p = Particle();
        p.SetEffect(e);
        p.Position(iSystem::player.x+(iSystem::player.direction*(iSystem::player.height/2)), iSystem::player.y-iSystem::player.height/2);
        p.Velocity(float((X-W)*0.1), float((Y-H)*0.1));
        p.Color(tTile::R[e.tile_value], tTile::G[e.tile_value], tTile::B[e.tile_value], tTile::A[e.tile_value]);
        particles.push_back(p);
    }

    void DrawParticles(float delta, off_x, off_y)
    {
        for (int p = 0; p < (particles.size()); p++)
        {
            float x = particles[p].x;
            float y = particles[p].y;
            float vx = particles[p].vx;
            float vy = particles[p].vy;

            int collision_x = int(x)+int(vx);
            int collision_y = int(y)+int(vy);

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
                    player.inventory.AddItem(tCell::matrix[collision_index], 1);
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
            if (particles[p].duration > 0.0)
            {
                particles[p].duration -= delta;
                engine::Draw(x-off_x, y-off_y, olc::Pixel(particles[p].r, particles[p].g, particles[p].b, particles[p].a));
                //Draw(x-(player.x-(width/2)), y-(player.y-(height/2)), olc::Pixel(particles[p].r, particles[p].g, particles[p].b, particles[p].a));
            }
            else
            {
                particles.erase(particles.begin()+p);
            }
        }
    }
}
