namespace script
{

    enum OPS {
        oPLUS,
        oMINUS,
        oGREATER,
        oEQUAL,
        oLESSER,
        oBRACKET_L,
        oBRACKET_R,
    };

    enum FUNC {
        //
        /// Tile Tool
        //
        
        //
        fGET_TYPE,
        fGET_DURABILITY,
        //
        fGET_LIGHT_VALUE,
        fNEIGHBORS,
        //
        fGAS_COLLISION,
        fFUME_COLLISION,
        fFLUID_COLLISION,
        fGEL_COLLISION,
        fGRAIN_COLLISION,
        fDUAL_COLLISION,
        fIS_COLLIDING,
        fCOLLISION,
        //
        fSET,
        fSWAP,
        fSOFT_SWAP,
    };

    std::vector<std::string> single = {
        "toggle_creative",
        "exit",
        "quit",
    };

    std::vector<std::string> prefix = {
        "int",
        "float",
        "set",
        "get",
        //"set_time",
        "teleport",
        //
        "neighbors",
        "gas_collision",
        "fume_collision",
        "fluid_collision",
        "gel_collision",
        "grain_collision",
        "dual_collision",
        "is_colliding",
        "collision",
        "swap",
        "soft_swap",
    };

    std::vector<std::string> suffix = {
        // Set
        "int",
        "float",
        "hp",
        "HP",
        "mp",
        "MP",
        "jp",
        "JP",
        "bp",
        "BP",
        "season",
        "year",
        "day",
        //"set_time",
        
        // Get
        "type",
        "durability",
        "light_value",
    };

    std::vector<std::string> math = {
        "*","/","%","+","-"
    };

    //
    ///
    //
    
    std::vector<std::string> args;

    int max_vars = 8;
    int int_pool[8];
    float float_pool[8];

    //
    ///
    //
    
    // User Variables

    int GetInt(int i) { if (i < max_vars) return int_pool[i]; else return int_pool[0]; }
    float GetFloat(int i) { if (i < max_vars) return float_pool[i]; else return float_pool[0]; }
    void SetInt(int i, int n) { if (i < max_vars) int_pool[i] = n; }
    void SetFloat(int i, float n) { if (i < max_vars) float_pool[i] = n; }

    //

    bool IsSingle(std::string c) { bool _is = false; for (int i = 0; i < single.size(); i++) { if ( single[i] == c) { _is = true; break; } } return _is; }
    bool IsPrefix(std::string c) { bool _is = false; for (int i = 0; i < prefix.size(); i++) { if ( prefix[i] == c) { _is = true; break; } } return _is; }
    bool IsMath(std::string c)     { bool _is = false; for (int i = 0; i < math.size(); i++) { if (   math[i] == c) { _is = true; break; } } return _is; }

    void SetTime(std::string s) { iSystem::sky.time = std::stof(s); iSystem::sky.UpdateTime(0.0); }
    void SetDay(std::string s) { iSystem::sky.day = std::stoi(s); tCell::season = iSystem::sky.day/(iSystem::sky.year_length/12); }
    void SetYear(std::string s) { iSystem::sky.year = std::stoi(s);}

    void SetSeason(std::string s)
    {
        if      (s == "early_spring") { tCell::season = seasonID::EARLY_SPRING; iSystem::sky.day =   0; }
        else if (s == "spring")       { tCell::season = seasonID::SPRING;       iSystem::sky.day =  30; }
        else if (s == "late_spring")  { tCell::season = seasonID::LATE_SPRING;  iSystem::sky.day =  60; }
        else if (s == "early_summer") { tCell::season = seasonID::EARLY_SUMMER; iSystem::sky.day =  90; }
        else if (s == "summer")       { tCell::season = seasonID::SUMMER;       iSystem::sky.day = 120; }
        else if (s == "late_summer")  { tCell::season = seasonID::LATE_SUMMER;  iSystem::sky.day = 150; }
        else if (s == "early_autumn") { tCell::season = seasonID::EARLY_AUTUMN; iSystem::sky.day = 180; }
        else if (s == "autumn")       { tCell::season = seasonID::AUTUMN;       iSystem::sky.day = 210; }
        else if (s == "late_autumn")  { tCell::season = seasonID::LATE_AUTUMN;  iSystem::sky.day = 240; }
        else if (s == "early_winter") { tCell::season = seasonID::EARLY_WINTER; iSystem::sky.day = 270; }
        else if (s == "winter")       { tCell::season = seasonID::WINTER;       iSystem::sky.day = 300; }
        else if (s == "late_winter")  { tCell::season = seasonID::LATE_WINTER;  iSystem::sky.day = 330; }
    }

    //
    /// Evaluation
    //

    void EvaluateMath(std::string cmd)
    {
    }

    void A(std::string cmd)
    {
        std::string e = "";
        if      (cmd == "toggle_creative") { e = "TOGGLE_CREATIVE"; core::creative_mode = !core::creative_mode; }
        else if (cmd == "quit") { e = "QUIT"; core::game_state = core::EXIT; }
        else if (cmd == "exit") { e = "EXIT"; core::game_state = core::EXIT; }
        if (e != "") std::cout << e << std::endl;
    }

    void AB(std::string c1="", std::string c2="")
    {
        std::string e = "";
        if (c1 == "get")
        {
            if      (c2 == "hp")   { e = "HEALTH = "     + std::to_string(iSystem::player.hp); }
            else if (c2 == "HP")   { e = "HEALTH_MAX = " + std::to_string(iSystem::player.HP); }
            else if (c2 == "mp")   { e = "MANA = "       + std::to_string(iSystem::player.mp); }
            else if (c2 == "MP")   { e = "MANA_MAX = "   + std::to_string(iSystem::player.MP); }
            else if (c2 == "jp")   { e = "JUMP = "       + std::to_string(iSystem::player.jp); }
            else if (c2 == "JP")   { e = "JUMP_MAX = "   + std::to_string(iSystem::player.JP); }
            else if (c2 == "bp")   { e = "BREATH = "     + std::to_string(iSystem::player.bp); }
            else if (c2 == "BP")   { e = "BREATH_MAX = " + std::to_string(iSystem::player.BP); }
        }
        if (e != "") std::cout << e << std::endl;
    }

    void ABC(std::string c1="", std::string c2="", std::string c3="")
    {
        std::string e = "";
        if (c1 == "get")
        {
            if      (c2 == "type")
            { e = "TYPE = " + std::to_string(tTool::GetType(std::stoi(c3))); }
            else if (c2 == "int" && textTool::IsNumber(c3))
            { e = "INT = "          + std::to_string(GetInt(std::stoi(c3))); }
            else if (c2 == "float" && textTool::IsNumber(c3))
            { e = "FLOAT = "      + std::to_string(GetFloat(std::stoi(c3))); }
        }
        else if (c1 == "set")
        {
            if      (c2 == "hp" && textTool::IsValidNumber(c3))     { e = "HEALTH";     iSystem::player.hp = std::stoi(c3); }
            else if (c2 == "HP" && textTool::IsValidNumber(c3))     { e = "HEALTH_MAX"; iSystem::player.HP = std::stoi(c3); }
            else if (c2 == "mp" && textTool::IsValidNumber(c3))     { e = "MANA";       iSystem::player.mp = std::stoi(c3); }
            else if (c2 == "MP" && textTool::IsValidNumber(c3))     { e = "MANA_MAX";   iSystem::player.MP = std::stoi(c3); }
            else if (c2 == "jp" && textTool::IsValidNumber(c3))     { e = "JUMP";       iSystem::player.jp = std::stoi(c3); }
            else if (c2 == "JP" && textTool::IsValidNumber(c3))     { e = "JUMP_MAX";   iSystem::player.JP = std::stoi(c3); }
            else if (c2 == "bp" && textTool::IsValidNumber(c3))     { e = "BREATH";     iSystem::player.bp = std::stoi(c3); }
            else if (c2 == "BP" && textTool::IsValidNumber(c3))     { e = "BREATH_MAX"; iSystem::player.BP = std::stoi(c3); }
            else if (c2 == "season" && textTool::IsValidNumber(c3)) { e = "SET_SEASON";                      SetSeason(c3); }
            else if (c2 == "year" && textTool::IsValidNumber(c3))   { e = "SET_YEAR";                          SetYear(c3); }
            else if (c2 == "day" && textTool::IsValidNumber(c3))    { e = "SET_DAY";                            SetDay(c3); }
            else if (c2 == "time" && textTool::IsValidNumber(c3))   { e = "SET_TIME";                          SetTime(c3); }
        }
        else if (c1 == "int"             && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "INT";                     SetInt(std::stoi(c2), std::stoi(c3)); }
        else if (c1 == "float"           && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "FLOAT";                   SetFloat(std::stoi(c2), std::stof(c3)); }
        else if (c1 == "teleport"        && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "TELEPORT";                iSystem::player.x += std::stoi(c2); iSystem::player.y += std::stoi(c3); }
        else if (c1 == "gas_collision"   && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "GAS_COLLISION = "         + std::to_string(int(tTool::GasCollision(std::stoi(c2), std::stoi(c3)))); }
        else if (c1 == "fume_collision"  && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "FUME_COLLISION = "        + std::to_string(int(tTool::FumeCollision(std::stoi(c2), std::stoi(c3)))); }
        else if (c1 == "fluid_collision" && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "FLUID_COLLISION = "       + std::to_string(int(tTool::FluidCollision(std::stoi(c2), std::stoi(c3)))); }
        else if (c1 == "gel_collision"   && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "GEL_COLLISION = "         + std::to_string(int(tTool::GelCollision(std::stoi(c2), std::stoi(c3)))); }
        else if (c1 == "grain_collision" && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "GRAIN_COLLISION = "       + std::to_string(int(tTool::GrainCollision(std::stoi(c2), std::stoi(c3)))); }
        else if (c1 == "dual_collision"  && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "DUAL_COLLISION = "        + std::to_string(int(tTool::DualCollision(std::stoi(c2), std::stoi(c3)))); }
        else if (c1 == "is_colliding"    && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "IS_COLLIDING = "          + std::to_string(int(tTool::IsColliding(std::stoi(c2), std::stoi(c3)))); }
        else if (c1 == "collision"       && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "COLLISION = "             + std::to_string(int(tTool::Collision(std::stoi(c2), std::stoi(c3)))); }
        if (e != "") std::cout << e << std::endl;
    }

    void ABCD(std::string c1="", std::string c2="", std::string c3="", std::string c4="")
    {
    }

    void EvaluateCommand(std::string cmd)
    {
        args.clear();
        std::string e = "";
        std::string arg = "";
        if (cmd.length() > 0)
        {
            // Pull Arguments From String
            uint8_t arg_count = 0;
            for (int i = 0; i < cmd.length(); i++)
            {
                std::string c = cmd.substr(i, 1);
                if (c == " ") { args.push_back(arg); arg = ""; arg_count++; }
                else { arg += c; }
            }
            if (arg != "") { arg_count++; args.push_back(arg); arg = "";}
            //
            if      (arg_count == 1) { A(cmd); }
            else if (arg_count == 2) { AB(args[0], args[1]); }
            else if (arg_count == 3) { ABC(args[0], args[1], args[2]); }
        }
        if (e != "") std::cout << e << std::endl;
    }

}
