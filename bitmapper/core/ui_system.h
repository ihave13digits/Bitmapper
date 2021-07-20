namespace uiSystem
{
    Icon icon = Icon();

    olc::Pixel hud_color = olc::Pixel(64, 64, 64);
    olc::Pixel hud_select_color = olc::Pixel(255, 255, 255);
    olc::Pixel grid_color = olc::Pixel(0, 0, 0, 64);
    olc::Pixel text_color = olc::Pixel(255, 255, 255);
    olc::Pixel panel_color = olc::Pixel(10, 10, 10);
    olc::Pixel border_color = olc::Pixel(80, 80, 80);
    olc::Pixel button_color = olc::Pixel(32, 32, 32);
    olc::Pixel select_color = olc::Pixel(64, 64, 64);



    //
    ///
    //

    void ProgressBar(int x, int y, int minv, int maxv, int W, int R=255, int G=255, int B=255, int r=64, int g=64, int b=64)
    {
        float completed = float(minv)/float(maxv);
        int x2 = W*completed;
        DrawLine(x, y, x+W, y, olc::Pixel(r, g, b));
        DrawLine(x, y, x+x2, y, olc::Pixel(R, G, B));
    }

    //
    ///
    //

    void DrawChunkGrid()
    {
        if (!show_grid) return;
        //grid_subdivision
        int _x = player.x % (world.chunk_size/grid_subdivision);
        int _y = player.y % (world.chunk_size/grid_subdivision);
        for (int y = 0; y < height+world.chunk_size; y += world.chunk_size/grid_subdivision)
        {
            DrawLine({0-_x, y-_y}, {width-_x+world.chunk_size, y-_y}, olc::Pixel(grid_color));
        }
        for (int x = 0; x < width+world.chunk_size; x += world.chunk_size/grid_subdivision)
        {
            DrawLine({x-_x, 0-_y}, {x-_x, height-_y+world.chunk_size}, olc::Pixel(grid_color));
        }
    }

    //
    ///
    //

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
                if (wand_value < player.wands.size())
                {
                    int wand_color = player.wands[wand_value].material;
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
                        player.hotbar[selected_hotbar][0] = itTILE;
                        player.hotbar[selected_hotbar][1] = std::stoi(b.text);
                    }
                }
            }
        }
    }

    //
    ///
    //
    
    void DrawHUD()
    {
        float font = 0.25;

        int lookindex = (player.y-(height/2)+GetMouseY())*tCell::width+(player.x-(width/2)+GetMouseX());

        std::string health = std::to_string(player.hp)+"/"+std::to_string(player.HP);
        std::string lookingat = "Air";
        std::string selectedtile = tTile::NAME[selected_tile];
        std::string selectedcount = "";
        std::string collision_at = std::to_string(tTool::Collision((player.x-(width/2)+GetMouseX()), (player.y-(height/2)+GetMouseY())));

        if ( ( (lookindex < tCell::width*tCell::height) && lookindex > 0) && (tCell::matrix[lookindex] < tTile::total_tiles) )
        {
            lookingat = tTile::NAME[tCell::matrix[lookindex]];
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
        if (player.hotbar[selected_hotbar][0] == itTILE) { selected_item = tTile::NAME[player.hotbar[selected_hotbar][1]]; }
        float select_x = (width/2)-(selected_item.size());
        DrawStringDecal({ select_x,15 }, selected_item, text_color, { 0.25, 0.25 });
        SetPixelMode(olc::Pixel::ALPHA);
        for (int i = 0; i < 9; i++)
        {
            int x = i*hb_size+hb_offset;
            DrawRect(x, 2, hb_size, hb_size, hud_color);

            if (player.hotbar[i][0] == itWAND)
            {
                int tile_value = player.hotbar[i][1];
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
            if (player.hotbar[i][0] == itTILE)
            {
                int tile_value = player.hotbar[i][1];
                int tile_type = tTool::GetType(tile_value);
                DrawIcon(x+1, 3, tile_type, tile_value);
            }
        }
        SetPixelMode(olc::Pixel::NORMAL);
        DrawRect(selected_hotbar*hb_size+hb_offset, 2, hb_size, hb_size, hud_select_color);
    }



}
