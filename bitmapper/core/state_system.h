namespace sSystem
{

    //
    ///
    //

    enum STATES
    {
        TITLE,
        CUSTOM,
        LOADING,
        PLAYING,
        INVENTORY,
        PAUSED,
        EXIT
    };



    //
    ///
    //

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
        if (GetKey(olc::Key::S).bPressed)
        {
            if (new_world::selected_step < new_world::generation_steps-2) new_world::selected_step++;
        }
        if (GetKey(olc::Key::W).bPressed)
        {
            if (new_world::selected_step > 0) new_world::selected_step--;
        }

        if (GetKey(olc::Key::A).bPressed)
        {
            if (new_world::generation_param[new_world::selected_step][new_world::selected_param] > 0)
            {
                new_world::generation_param[new_world::selected_step][new_world::selected_param]--;
            }
        }
        if (GetKey(olc::Key::D).bPressed)
        {
            switch (new_world::selected_param)
            {
                case new_world::pTILE :
                {
                    if (new_world::generation_param[new_world::selected_step][new_world::selected_param] < tTile::total_tiles-1)
                    { new_world::generation_param[new_world::selected_step][new_world::selected_param]++; }
                }
                break;
                case  new_world::pMODE :
                {
                    if (new_world::generation_param[new_world::selected_step][new_world::selected_param] < new_world::total_modes-1)
                    { new_world::generation_param[new_world::selected_step][new_world::selected_param]++;
                    }
                }
                break;
                default :
                {
                    if (new_world::generation_param[new_world::selected_step][new_world::selected_param] < 100)
                    { new_world::generation_param[new_world::selected_step][new_world::selected_param]++; }
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
            if (GetMouse(0).bReleased && new_world::generation_steps > 1)
            {
                new_world::generation_steps--;
                for (int i = new_world::selected_step; i < new_world::generation_steps; i++)
                {
                    for (int p = 0; p < new_world::total_parameters; p++)
                    {
                        new_world::generation_param[i][p] = new_world::generation_param[i+1][p];
                    }
                }
                if (new_world::selected_step > 0) new_world::selected_step--;
            }
        }
        if (bplusgs.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Inserts A Generation Step Into The List";
            //dtls_text = "()";
            DrawRect(bplusgs.x, bplusgs.y, bplusgs.width, bplusgs.height, select_color);
            if (GetMouse(0).bReleased && new_world::generation_steps < new_world::maximum_generation_steps)
            {
                new_world::generation_steps++;
                for (int i = new_world::generation_steps-1; i > new_world::selected_step+1; i--)
                {
                    for (int p = 0; p < new_world::total_parameters; p++)
                    {
                        new_world::generation_param[i-1][p] = new_world::generation_param[i-2][p];
                    }
                }
                for (int p = 0; p < new_world::total_parameters; p++)
                {
                    new_world::generation_param[new_world::selected_step][p] = 0;
                }
                if (new_world::selected_step > 0) new_world::selected_step--;
            }
        }

        // Tile Value
        if (btile.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Material To add To World";
            //dtls_text = "()";
            DrawRect(btile.x, btile.y, btile.width, btile.height, select_color);
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pTILE;
        }
        // Density Value
        if (bdense.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability A Material Will Spawn Per Cell";
            dtls_text = "(Add Layer, Seed Material)";
            DrawRect(bdense.x, bdense.y, bdense.width, bdense.height, select_color);
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pDENSE;
        }
        if (biter.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "How Many Times to Repeat Current Step";
            //dtls_text = "()";
            DrawRect(biter.x, biter.y, biter.width, biter.height, select_color);
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pITER;
        }
        // X Values
        if (bminx.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Minimum Width Range Of Effect";
            dtls_text = "(0-100 %)";
            DrawRect(bminx.x, bminx.y, bminx.width, bminx.height, select_color);
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pMINX;
        }
        if (bmaxx.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Maximum Width Range Of Effect";
            dtls_text = "(0-100 %)";
            DrawRect(bmaxx.x, bmaxx.y, bmaxx.width, bmaxx.height, select_color);
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pMAXX;
        }
        // Y values
        if (bminy.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Minimum Height Range Of Effect";
            dtls_text = "(0-100 %)";
            DrawRect(bminy.x, bminy.y, bminy.width, bminy.height, select_color);
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pMINY;
        }
        if (bmaxy.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Maximum Height Range Of Effect";
            dtls_text = "(0-100 %)";
            DrawRect(bmaxy.x, bmaxy.y, bmaxy.width, bmaxy.height, select_color);
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pMAXY;
        }
        // Neighbor Values
        if (bprobn.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That A Northern Neighbor Will Spawn";
            //dtls_text = "()";
            DrawRect(bprobn.x, bprobn.y, bprobn.width, bprobn.height, select_color);
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pPROBN;
        }
        if (bprobs.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That A Southern Neighbor Will Spawn";
            //dtls_text = "()";
            DrawRect(bprobs.x, bprobs.y, bprobs.width, bprobs.height, select_color);
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pPROBS;
        }
        if (bprobe.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That An Eastern Neighbor Will Spawn";
            //dtls_text = "()";
            DrawRect(bprobe.x, bprobe.y, bprobe.width, bprobe.height, select_color);
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pPROBE;
        }
        if (bprobw.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Probability That A Western Neighbor Will Spawn";
            //dtls_text = "()";
            DrawRect(bprobw.x, bprobw.y, bprobw.width, bprobw.height, select_color);
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pPROBW;
        }
        // Mode Value
        if (bmode.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Changes Generation Mode";
            //dtls_text = "()";
            DrawRect(bmode.x, bmode.y, bmode.width, bmode.height, select_color);
            if (GetMouse(0).bReleased) new_world::selected_param = new_world::pMODE;
        }

        // Clear Values
        if (bclear.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Clears All Generation Data";
            DrawRect(bclear.x, bclear.y, bclear.width, bclear.height, select_color);
            if (GetMouse(0).bReleased)
            {
                new_world::ClearData();
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
                new_world::PresetData();
            }
        }
        // Randomize Seed
        if (brandom.IsColliding(GetMouseX(), GetMouseY()))
        {
            info_text = "Randomizes Game Seed";
            DrawRect(brandom.x, brandom.y, brandom.width, brandom.height, select_color);
            if (GetMouse(0).bReleased)
            {
                core::seed = rand() % 9999999999;
                srand(core::seed);
                new_world::ClearMatrix();
                new_world::InitializeMatrix(100, 100);
                for (int i = 0; i < new_world::generation_steps; i++)
                {
                    new_world::GeneratePreview();
                }
                new_world::generation_step = 1;
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
                for (int p = 0; p < new_world::total_parameters; p++)
                {
                    new_world::clipboard_param[p] = new_world::generation_param[new_world::selected_step][p];
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
                new_world::generation_steps++;
                for (int i = new_world::generation_steps-1; i > new_world::selected_step; i--)
                {
                    for (int p = 0; p < new_world::total_parameters; p++)
                    {
                        new_world::generation_param[i-1][p] = new_world::generation_param[i-2][p];
                    }
                }
                for (int p = 0; p < new_world::total_parameters; p++)
                {
                    new_world::generation_param[new_world::selected_step][p] = new_world::clipboard_param[p];
                }
                if (new_world::selected_step > 0) new_world::selected_step--;
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
                for (int i = 0; i < new_world::generation_steps; i++)
                {
                    if (new_world::generation_param[i][0] != tTile::AIR) is_data_valid = true;
                }
                if (!is_data_valid) new_world::PresetData();
                new_world::InitializeMatrix(world_width, world_height);
                srand(core::seed);
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
                srand(core::seed);
                new_world::ClearMatrix();
                new_world::InitializeMatrix(100, 100);
                for (int i = 0; i < new_world::generation_steps; i++)
                {
                    new_world::GeneratePreview();
                }
                new_world::generation_step = 1;
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
            try { if (new_world::generation_param[i][new_world::selected_param] < new_world::total_modes) mode_text = new_world::modes[new_world::generation_param[i][new_world::selected_param]]; }
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

        if (loading)
        {
            message = new_world::GenerateWorld();

            if (new_world::generation_step > new_world::generation_steps)
            {
                sky.GenerateSky(width, height, core::seed);
                player.x = int(tCell::width/2);
                player.y = player.height+2;
                while (!tTool::IsColliding(player.x, player.y+1)) player.Move(0, 1);
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
        ProgressBar(prog_x, prog_y, new_world::generation_step-1, new_world::generation_steps, width/2);

    }

    void GamePaused()
    {
        if (GetKey(olc::Key::ESCAPE).bPressed) game_state = PLAYING;
        if (GetKey(olc::Key::TAB).bPressed) game_state = INVENTORY;

        if (GetKey(olc::Key::Q).bPressed) { if (grid_subdivision > 1) grid_subdivision /= 2; }
        if (GetKey(olc::Key::E).bPressed) { if (grid_subdivision < 8) grid_subdivision *= 2; }
        if (GetKey(olc::Key::G).bPressed) { show_grid = !show_grid; }

        if (player.state == player.DEAD) return;

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
            int index = (GetMouseY()+(player.y-(height/2)))*tCell::width+(GetMouseX()+(player.x-(width/2)));
            int tile = tCell::matrix[index];
            int _tile = selected_tile;
            if (player.hotbar[selected_hotbar][0] == itTILE)
            {
                int index = (GetMouseY()+(player.y-(height/2)))*tCell::width+(GetMouseX()+(player.x-(width/2)));
                int tile = tCell::matrix[index];
                int _tile = player.hotbar[selected_hotbar][1];
                if (tile != tTile::MANTLE)
                {
                    if (_tile != tTile::AIR)
                    {
                        if (player.inventory.HasItem(_tile) || creative_mode)
                        {
                            int amnt = 1;
                            if (tile == tTile::AIR) amnt = 0;
                            player.inventory.UseItem(_tile, 1);
                            player.inventory.AddItem(tile, amnt);
                            tCell::matrix[index] = _tile;
                        }
                    }
                    else if (_tile == tTile::AIR)
                    {
                        if (tile != tTile::AIR) player.inventory.AddItem(tile, 1);
                        tCell::matrix[index] = _tile;
                    }
                }
            }
        }

        if (GetKey(olc::Key::SPACE).bPressed)
        {
            world.SettleTiles(player.x-(width), player.y-(height), width*2, height*2);
        }
        DrawSky();
        DrawTerrain();
        DrawPlayer();
        HotbarInput();
        DrawHUD();
    }

    void GameInventory()
    {
        if (GetKey(olc::Key::ESCAPE).bPressed) game_state = PAUSED;
        if (GetKey(olc::Key::TAB).bPressed) game_state = PLAYING;

        if (GetKey(olc::Key::Q).bPressed && selected_tile < tTile::total_tiles-1) selected_tile++;
        if (GetKey(olc::Key::E).bPressed && selected_tile > 0) selected_tile--;

        if (GetKey(olc::Key::I).bPressed) pause_state = psTILES;
        if (GetKey(olc::Key::W).bPressed) pause_state = psWANDS;

        if (pause_state == psWANDS) DrawWands();
        if (pause_state == psTILES) DrawInventory();

        HotbarInput();
        DrawHUD();
    }

    void GameLoop(float fElapsedTime)
    {
        if (player.state == player.DEAD)
        {
            if (GetKey(olc::Key::ESCAPE).bPressed) game_state = PAUSED;
            return;
        }

        if (!tTool::IsColliding(player.x, player.y+1) && !tTool::IsColliding(player.x-1, player.y+1) && player.state != player.JUMP)
        {
            player.vy = 1;
            player.state = player.FALL;
        }
        if (tTool::IsColliding(player.x, player.y+1) || tTool::IsColliding(player.x-1, player.y+1))
        {
            player.state = player.IDLE;
        }

        if (GetKey(olc::Key::ESCAPE).bPressed) game_state = PAUSED;
        if (GetKey(olc::Key::TAB).bPressed) game_state = INVENTORY;
        //
        HotbarInput();
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
            int index = (GetMouseY()+(player.y-(height/2)))*tCell::width+(GetMouseX()+(player.x-(width/2)));
            int tile = tCell::matrix[index];
            int _tile = selected_tile;
            if (player.hotbar[selected_hotbar][0] == itTILE)
            {
                int index = (GetMouseY()+(player.y-(height/2)))*tCell::width+(GetMouseX()+(player.x-(width/2)));
                int tile = tCell::matrix[index];
                int _tile = player.hotbar[selected_hotbar][1];
                if (tile != tTile::MANTLE)
                {
                    if (_tile != tTile::AIR)
                    {
                        if (player.inventory.HasItem(_tile) || creative_mode)
                        {
                            int amnt = 1;
                            if (tile == tTile::AIR) amnt = 0;
                            player.inventory.UseItem(_tile, 1);
                            player.inventory.AddItem(tile, amnt);
                            tCell::matrix[index] = _tile;
                        }
                    }
                    else if (_tile == tTile::AIR)
                    {
                        if (tile != tTile::AIR) player.inventory.AddItem(tile, 1);
                        tCell::matrix[index] = _tile;
                    }
                }
            }
        }
        // Vertical Movement
        if (GetKey(olc::Key::W).bHeld)
        {
            if ((!tTool::IsColliding(player.x, player.y-player.height)) &&
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

        if (GetKey(olc::Key::W).bReleased) { player.vy = 0; player.state = player.IDLE; }

        if (GetKey(olc::Key::S).bPressed)
        {
            int tile = tCell::matrix[(player.y+(player.height-1))*tCell::width+player.x];
            if (tile == tTile::PLANKS) { player.Move(0, 1); }
        }

        if (!tTool::IsColliding(player.x, player.y+1) && player.state != player.JUMP)
        { player.vy = 1; player.state = player.FALL; }

        // Horizontal Movement
        if (GetKey(olc::Key::A).bHeld && player.x > width/2)
        {
            if (player.state != player.FALL && player.state != player.JUMP) player.vy = 0;
            if (!tTool::IsColliding(player.x-2, player.y) ) { player.vx = -1; }
            else if (tTool::IsColliding(player.x-2, player.y) ||
                    tTool::IsColliding(player.x-2, player.y-1)
                    )
            { player.vx = -1; player.Move(0, -1); }
            if (!GetKey(olc::Key::W).bHeld && player.state != player.FALL) { player.state = player.WALK; }
            player.direction = -1;
        }
        if (GetKey(olc::Key::D).bHeld && player.x < tCell::width-(width/2))
        {
            if (player.state != player.FALL && player.state != player.JUMP) player.vy = 0;
            if (!tTool::IsColliding(player.x+1, player.y) ) { player.vx = 1; }
            else if (tTool::IsColliding(player.x+1, player.y) ||
                    tTool::IsColliding(player.x+1, player.y-1) )
            { player.vx = 1; player.Move(0, -1); }
            if (!GetKey(olc::Key::W).bHeld && player.state != player.FALL) { player.state = player.WALK; }
            player.direction = 1;
        }

        if (GetKey(olc::Key::A).bReleased) { player.vx = 0; }
        if (GetKey(olc::Key::D).bReleased) { player.vx = 0; }

        if (GetKey(olc::Key::G).bPressed) { show_grid = !show_grid; }

        // Update World
        sky.Update(fElapsedTime);
        if (game_tick > tick_delay)
        {
            game_tick -= tick_delay;
            DrawSky();
            world.SettleTiles(player.x-(width), player.y-(height), width*2, height*2);
            DrawTerrain();
            DrawHUD();
        }

        // Update Player
        player.Update(fElapsedTime);
        if (player.hp < 1) player.state = player.DEAD;

        if (!PlayerVsWorld())
        {
            player.Move(player.vx, player.vy);
        }
        DrawPlayer();
        //player.UpdateWands(fElapsedTime);
        DrawParticles(fElapsedTime);
        //DrawHUD();

        // End Frame
        game_tick += fElapsedTime;
    }


    bool Update()
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

}
