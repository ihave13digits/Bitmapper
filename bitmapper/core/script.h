// Possibly look into 'cstdarg'
/*
struct Command
{
    std::string cmd; std::map<std::string, int> args;
    Command(std::string c, int s, int i, int f) { cmd = c; args["string"] = s; args["int"] = i; args["float"] = f; }
};
*/
namespace script
{

    /*
    std::vector<Command> commands = {
        Command("exit",            0, 0, 0),
        Command("quit",            0, 0, 0),
        Command("toggle_creative", 0, 0, 0),
        Command("get",             1, 0, 0),
        Command("set",             1, 0, 0),
        Command("int",             0, 2, 0),
        Command("float",           0, 1, 1),
        Command("neighbors",       0, 2, 0),
        Command("gas_collision",   0, 2, 0),
        Command("fume_collision",  0, 2, 0),
        Command("fluid_collision", 0, 0, 0),
        Command("gel_collision",   0, 0, 0),
        Command("grain_collision", 0, 0, 0),
        Command("dual_collision",  0, 0, 0),
        Command("is_colliding",    0, 0, 0),
        Command("collision",       0, 0, 0),
        Command("teleport",        0, 0, 0),
        Command("swap",            0, 3, 0),
        Command("soft_swap",       0, 3, 0),
    };
    */

    //
    /// Variables
    //
    
    std::vector<std::string> args;
    std::vector<std::string> cmds = {"","","","","","","",""};
    int max_vars = 8;
    int max_cmds = 8;
    int cmd_index = 0;
    int int_pool[8];
    float float_pool[8];



    void SetHistory(std::string n)
    {
        max_cmds = std::stoi(n);
        while (cmds.size() < max_cmds) { cmds.insert(cmds.begin(), ""); }
        while (cmds.size() > max_cmds) { cmds.erase(cmds.end()-1); }
        
        for (int i = 0; i < cmds.size(); i++) { std::cout << cmds[i] << std::endl; }
    }
    void StoreCommand(std::string cmd)
    { if (cmds[cmds.size()-1] != cmd && cmd != cmds[cmds.size()-1]) cmds.push_back(cmd); if (cmds.size() > max_cmds) { cmds.erase(cmds.begin()); } }

    //
    /// Commands
    //
    
    // User Variables
    int GetInt(int i) { if (i < max_vars) return int_pool[i]; else return int_pool[0]; }
    float GetFloat(int i) { if (i < max_vars) return float_pool[i]; else return float_pool[0]; }
    void SetInt(int i, int n) { if (i < max_vars) int_pool[i] = n; }
    void SetFloat(int i, float n) { if (i < max_vars) float_pool[i] = n; }
    // Misc
    void Teleport(int x, int y)
    { if (x > 0 && x < tCell::width && y > 0 && y < tCell::height) { iSystem::player.x = x; iSystem::player.y = y; } }
    void Warp(int x, int y)
    {
        int _x = x+iSystem::player.x; int _y = y+iSystem::player.y;
        if (_x > 0 && _x < tCell::width && _y > 0 && _y < tCell::height) { iSystem::player.x += x; iSystem::player.y += y; }
    }
    // World
    std::string GetMouse() { std::string mouse = "(" + std::to_string(iSystem::MouseX()) + "," + std::to_string(iSystem::MouseY()) + ")"; return mouse; }
    int GetTile(std::string tile) { int index = -1; for (int i = 0; i < tTile::total_tiles; i++) { if (tTile::NAME[i] == tile) { index = i; break; } } return index; }
    std::string GetType(std::string tile)
    { int index = GetTile(tile); std::string t = "None"; if (index != -1) { t = tTile::TYPE_NAME[tTool::GetType(index)]; } return t; }
    float GetWeather() { return float(iSystem::sky.humidity)/float(iSystem::sky.cloudcount); }
    void SetWeather(std::string s)
    {
        iSystem::sky.humidity = int(std::stof(s)*iSystem::sky.cloudcount);
        if (iSystem::sky.humidity > iSystem::sky.cloudcount) { iSystem::sky.humidity = iSystem::sky.cloudcount; }
    }
    void SetTick(std::string s)
    { core::tick_delay = 1.0/std::stof(s); if (core::tick_delay < 1.0/60.0) { core::tick_delay = 1.0/60.0; } }
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

    void A(std::string cmd)
    {
        std::string e = "";
        if      (cmd == "quit")            { e = "QUIT"; core::game_state = core::EXIT; }
        else if (cmd == "exit")            { e = "EXIT"; core::game_state = core::EXIT; }
        if (e != "") std::cout << e << std::endl;
    }

    void AB(std::string c1="", std::string c2="")
    {
        std::string e = "";
        if (c1 == "get")
        {
            if      (c2 == "hp")      { e = "HEALTH = "     +    std::to_string(iSystem::player.hp); }
            else if (c2 == "HP")      { e = "HEALTH_MAX = " +    std::to_string(iSystem::player.HP); }
            else if (c2 == "mp")      { e = "MANA = "       +    std::to_string(iSystem::player.mp); }
            else if (c2 == "MP")      { e = "MANA_MAX = "   +    std::to_string(iSystem::player.MP); }
            else if (c2 == "jp")      { e = "JUMP = "       +    std::to_string(iSystem::player.jp); }
            else if (c2 == "JP")      { e = "JUMP_MAX = "   +    std::to_string(iSystem::player.JP); }
            else if (c2 == "bp")      { e = "BREATH = "     +    std::to_string(iSystem::player.bp); }
            else if (c2 == "BP")      { e = "BREATH_MAX = " +    std::to_string(iSystem::player.BP); }
            else if (c2 == "reach")   { e = "REACH = "      + std::to_string(iSystem::player.reach); }
            else if (c2 == "tick")    { e = "TICK = "       +      std::to_string(core::tick_delay); }
            else if (c2 == "time")    { e = "TIME = "       +     std::to_string(iSystem::sky.time); }
            else if (c2 == "mouse")   { e = "MOUSE = "      +                            GetMouse(); }
            else if (c2 == "history") { e = "HISTORY = "    +              std::to_string(max_cmds); }
            else if (c2 == "weather") { e = "WEATHER = "    +          std::to_string(GetWeather()); }
        }
        else if (c1 == "collision")
        {
            if      (c2 == "gas")       { e = "GAS_COLLISION = "   +   std::to_string(int(tTool::GasCollision(iSystem::MouseX(), iSystem::MouseY()))); }
            else if (c2 == "fume")      { e = "FUME_COLLISION = "  +  std::to_string(int(tTool::FumeCollision(iSystem::MouseX(), iSystem::MouseY()))); }
            else if (c2 == "fluid")     { e = "FLUID_COLLISION = " + std::to_string(int(tTool::FluidCollision(iSystem::MouseX(), iSystem::MouseY()))); }
            else if (c2 == "gel")       { e = "GEL_COLLISION = "   +   std::to_string(int(tTool::GelCollision(iSystem::MouseX(), iSystem::MouseY()))); }
            else if (c2 == "grain")     { e = "GRAIN_COLLISION = " + std::to_string(int(tTool::GrainCollision(iSystem::MouseX(), iSystem::MouseY()))); }
            else if (c2 == "dual")      { e = "DUAL_COLLISION = "  +  std::to_string(int(tTool::DualCollision(iSystem::MouseX(), iSystem::MouseY()))); }
            else if (c2 == "body")      { e = "BODY_COLLISION = "  +  std::to_string(int(tTool::BodyCollision(iSystem::MouseX(), iSystem::MouseY()))); }
            else if (c2 == "any")       { e = "COLLISION = "       +      std::to_string(int(tTool::Collision(iSystem::MouseX(), iSystem::MouseY()))); }
        }
        else if (c1 == "toggle")
        {
            if      (c2 == "creative")      { e = "TOGGLE_CREATIVE"; core::creative_mode = !core::creative_mode; }
        }
        if (e != "") std::cout << e << std::endl;
    }

    void ABC(std::string c1="", std::string c2="", std::string c3="")
    {
        std::string e = "";
        if (c1 == "get")
        {
            if      (c2 == "type")                            { e = "TYPE = " +                                   GetType(c3); }
            else if (c2 == "int" && textTool::IsNumber(c3))   { e = "INT = "          + std::to_string(GetInt(std::stoi(c3))); }
            else if (c2 == "float" && textTool::IsNumber(c3)) { e = "FLOAT = "      + std::to_string(GetFloat(std::stoi(c3))); }
            else if (c2 == "index")     { e = "INDEX = " + std::to_string((iSystem::MouseY()*tCell::width)+iSystem::MouseX()); }
        }
        else if (c1 == "set")
        {
            if      (c2 == "hp" && textTool::IsValidNumber(c3))      { e = "HEALTH";      iSystem::player.hp = std::stoi(c3); }
            else if (c2 == "HP" && textTool::IsValidNumber(c3))      { e = "HEALTH_MAX";  iSystem::player.HP = std::stoi(c3); }
            else if (c2 == "mp" && textTool::IsValidNumber(c3))      { e = "MANA";        iSystem::player.mp = std::stoi(c3); }
            else if (c2 == "MP" && textTool::IsValidNumber(c3))      { e = "MANA_MAX";    iSystem::player.MP = std::stoi(c3); }
            else if (c2 == "jp" && textTool::IsValidNumber(c3))      { e = "JUMP";        iSystem::player.jp = std::stoi(c3); }
            else if (c2 == "JP" && textTool::IsValidNumber(c3))      { e = "JUMP_MAX";    iSystem::player.JP = std::stoi(c3); }
            else if (c2 == "bp" && textTool::IsValidNumber(c3))      { e = "BREATH";      iSystem::player.bp = std::stoi(c3); }
            else if (c2 == "BP" && textTool::IsValidNumber(c3))      { e = "BREATH_MAX";  iSystem::player.BP = std::stoi(c3); }
            else if (c2 == "reach" && textTool::IsValidNumber(c3))   { e = "REACH";    iSystem::player.reach = std::stoi(c3); }
            else if (c2 == "season")                                 { e = "SET_SEASON";                       SetSeason(c3); }
            else if (c2 == "year" && textTool::IsValidNumber(c3))    { e = "SET_YEAR";                           SetYear(c3); }
            else if (c2 == "day" && textTool::IsValidNumber(c3))     { e = "SET_DAY";                             SetDay(c3); }
            else if (c2 == "time" && textTool::IsValidNumber(c3))    { e = "SET_TIME";                           SetTime(c3); }
            else if (c2 == "history" && textTool::IsValidNumber(c3)) { e = "SET_HISTORY";                     SetHistory(c3); }
            else if (c2 == "weather" && textTool::IsValidNumber(c3)) { e = "SET_WEATHER";                     SetWeather(c3); }
            else if (c2 == "tick" && textTool::IsValidNumber(c3))    { e = "SET_TICK";                           SetTick(c3); }
        }
        else if (c1 == "int"      && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "INT";              SetInt(std::stoi(c2), std::stoi(c3)); }
        else if (c1 == "float"    && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "FLOAT";            SetFloat(std::stoi(c2), std::stof(c3)); }
        else if (c1 == "teleport" && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "TELEPORT";         Teleport(std::stoi(c2), std::stoi(c3)); }
        else if (c1 == "warp"     && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "WARP";             Warp(std::stoi(c2), std::stoi(c3)); }
        else if (c1 == "swap"     && textTool::IsValidNumber(c2) && textTool::IsValidNumber(c3))
        { e = "SWAP";             tTool::Swap(std::stoi(c2), std::stoi(c3)); }
        if (e != "") std::cout << e << std::endl;
    }

    void EvaluateCommand(std::string cmd)
    {
        bool success = false;
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
            if      (arg_count == 1) { A(cmd); success = true; }
            else if (arg_count == 2) { AB(args[0], args[1]); success = true; }
            else if (arg_count == 3) { ABC(args[0], args[1], args[2]); success = true; }
        }
        if (success) { StoreCommand(cmd); }
        else { e = cmd; }
        if (e != "") std::cout << e << std::endl;
    }

}
