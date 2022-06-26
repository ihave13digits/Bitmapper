class Player
{
public:

    enum ANIMATION
    {
        aIDLE_RIGHT,
        aIDLE_LEFT,
        aWALK_RIGHT,
        aWALK_LEFT,
        aRUN_RIGHT,
        aRUN_LEFT,
        aJUMP_RIGHT,
        aJUMP_LEFT,
        aFALL_RIGHT,
        aFALL_LEFT,
        aSWIM_LEFT,
        aSWIM_RIGHT,
        aDEAD_RIGHT,
        aDEAD_LEFT,
    };

    enum STATUS
    {
        FINE,
        HURT,
        BURN,
        COLD,
        STUN,
        TRIP,
        DROWN,
        POISON,
        CONFUSED,
    };

    enum STATES
    {
        IDLE,
        WALK,
        JUMP,
        FALL,
        SWIM,
        DEAD,
    };

    bool can_move;
    bool is_hurt;
    bool is_burn;
    bool is_cold;
    bool is_stun;
    bool is_trip;
    bool is_drown;
    bool is_poison;
    bool is_confused;

    int8_t direction = 1;
    uint8_t state = 0;
    uint8_t status = 0;

    float tick = 0.0;
    float tick_delay = 0.0125;
    uint8_t damage_tick = 0;
    uint8_t damage_delay = 10;
    uint8_t burn_tick = 0;
    uint8_t toxic_tick = 0;

    int x = 0;
    int y = 0;
    uint8_t vx = 0;
    uint8_t vy = 0;

    uint8_t reach = 72;
    const uint8_t height = 8;

    int HP = 100;
    int hp = 100;
    int MP = 100;
    int mp = 100;
    int JP = 100;
    int jp = 100;
    int bp = 100;
    int BP = 100;

    float defense = 0.0;

    uint8_t frame = 0;
    uint8_t anim = 0;
    float anim_tick = 0.0;
    float anim_delay = 0.125;

    uint8_t hotbar[9][2] = { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} };

    uint8_t animations[14][4] = {
        {  0,  2,  0,  2 }, // Idle Right
        {  1,  3,  1,  3 }, // Idle Left
        {  2,  4,  2,  6 }, // Walk Right
        {  3,  5,  3,  7 }, // Walk Left
        {  2,  8,  2, 10 }, // Run Right
        {  3,  9,  3, 11 }, // Run Left
        {  4,  4,  4,  4 }, // Jump Right
        {  5,  5,  5,  5 }, // Jump Left
        {  8,  8,  8,  8 }, // Fall Right
        {  9,  9,  9,  9 }, // Fall Left
        { 12, 14, 12, 14 }, // Swim Right
        { 13, 15, 13, 15 }, // Swim Left
        { 16, 16, 16, 16 }, // Dead Right
        { 17, 17, 17, 17 }, // Dead Left
    };

    uint8_t image[18][64] = {
        // Idle
        { 0,0,0,0,7,8,0,0, 0,0,0,0,6,7,0,0, 0,0,0,3,2,0,0,0, 0,0,6,2,1,0,0,0, 0,0,7,1,1,0,0,0, 0,0,0,3,3,0,0,0, 0,0,0,3,2,0,0,0, 0,0,0,2,1,0,0,0, }, // R 1
        { 0,0,8,7,0,0,0,0, 0,0,7,6,0,0,0,0, 0,0,0,2,3,0,0,0, 0,0,0,1,2,6,0,0, 0,0,0,1,1,7,0,0, 0,0,0,3,3,0,0,0, 0,0,0,2,3,0,0,0, 0,0,0,1,2,0,0,0, }, // L 1
        { 0,0,0,0,0,0,0,0, 0,0,0,0,8,8,0,0, 0,0,0,3,6,8,0,0, 0,0,6,2,1,0,0,0, 0,0,7,1,1,0,0,0, 0,0,0,3,3,0,0,0, 0,0,0,3,2,0,0,0, 0,0,0,2,1,0,0,0, }, // R 2
        { 0,0,0,0,0,0,0,0, 0,0,8,7,0,0,0,0, 0,0,7,6,3,0,0,0, 0,0,0,1,2,6,0,0, 0,0,0,1,1,7,0,0, 0,0,0,3,3,0,0,0, 0,0,0,2,3,0,0,0, 0,0,0,1,2,0,0,0, }, // L 2
        // Walk
        { 0,0,0,0,7,8,0,0, 0,0,0,0,6,7,0,0, 0,0,0,3,2,0,0,0, 0,0,6,2,1,0,0,0, 0,7,0,1,1,8,0,0, 0,0,0,4,4,4,0,0, 0,0,0,4,0,1,0,0, 0,0,0,2,0,0,0,0, }, // R 1
        { 0,0,8,7,0,0,0,0, 0,0,7,6,0,0,0,0, 0,0,0,2,3,0,0,0, 0,0,0,1,2,6,0,0, 0,0,8,1,1,0,7,0, 0,0,4,4,4,0,0,0, 0,0,1,0,4,0,0,0, 0,0,0,0,2,0,0,0, }, // L 1
        { 0,0,0,0,7,8,0,0, 0,0,0,0,6,7,0,0, 0,0,0,3,2,0,0,0, 0,0,0,6,1,0,0,0, 0,0,0,1,7,0,0,0, 0,0,0,4,4,0,0,0, 0,0,2,4,3,0,0,0, 0,0,0,0,1,0,0,0, }, // R 2
        { 0,0,8,7,0,0,0,0, 0,0,7,6,0,0,0,0, 0,0,0,2,3,0,0,0, 0,0,0,1,6,0,0,0, 0,0,0,7,1,0,0,0, 0,0,0,4,4,0,0,0, 0,0,0,3,4,2,0,0, 0,0,0,1,0,0,0,0, }, // L 2
        // Run
        { 0,0,0,0,0,0,0,0, 0,0,0,0,7,8,0,0, 0,0,0,3,6,7,0,0, 0,0,0,2,1,0,0,0, 0,0,6,1,1,6,0,0, 0,7,0,4,4,4,0,0, 0,0,0,4,0,1,0,0, 0,0,0,2,0,0,0,0, }, // R 1
        { 0,0,0,0,0,0,0,0, 0,0,8,7,0,0,0,0, 0,0,7,6,3,0,0,0, 0,0,0,1,2,0,0,0, 0,0,0,1,1,6,0,0, 0,0,4,4,4,0,7,0, 0,0,1,0,4,0,0,0, 0,0,0,0,2,0,0,0, }, // L 1
        { 0,0,0,0,0,0,0,0, 0,0,0,0,7,8,0,0, 0,0,0,3,6,7,0,0, 0,0,0,1,1,0,0,0, 0,0,0,6,1,0,0,0, 0,0,0,4,7,0,0,0, 0,0,2,4,3,0,0,0, 0,0,0,0,1,0,0,0, }, // R 2
        { 0,0,0,0,0,0,0,0, 0,0,8,7,0,0,0,0, 0,0,7,6,3,0,0,0, 0,0,0,1,1,0,0,0, 0,0,0,1,6,0,0,0, 0,0,0,7,4,0,0,0, 0,0,0,3,4,2,0,0, 0,0,0,1,0,0,0,0, }, // L 2
        // Swim
        { 0,0,0,0,0,7,8,0, 0,0,0,0,0,6,7,0, 0,0,0,0,3,2,0,0, 0,0,0,2,1,6,0,0, 0,0,2,1,2,0,7,0, 0,0,4,4,0,0,0,0, 0,3,4,3,0,0,0,0, 0,2,1,0,0,0,0,0, }, // R 1
        { 0,8,7,0,0,0,0,0, 0,7,6,0,0,0,0,0, 0,0,2,3,0,0,0,0, 0,0,6,1,2,0,0,0, 0,7,0,2,1,2,0,0, 0,0,0,0,4,4,0,0, 0,0,0,0,3,4,3,0, 0,0,0,0,0,1,2,0, }, // L 1
        { 0,0,0,0,0,7,8,0, 0,0,0,0,0,6,7,0, 0,0,0,0,3,2,0,0, 0,0,0,2,1,6,7,0, 0,0,2,1,2,0,0,0, 0,0,4,4,0,0,0,0, 0,3,4,3,0,0,0,0, 0,2,1,0,0,0,0,0, }, // R 2
        { 0,8,7,0,0,0,0,0, 0,7,6,0,0,0,0,0, 0,0,2,3,0,0,0,0, 0,7,6,1,2,0,0,0, 0,0,0,2,1,2,0,0, 0,0,0,0,4,4,0,0, 0,0,0,0,3,4,3,0, 0,0,0,0,0,1,2,0, }, // L 2
        // Dead
        { 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,2,4,4,2,1,7,8, 1,4,4,4,1,1,6,7, }, // R 1
        { 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 8,7,1,2,4,4,2,0, 7,6,1,1,4,4,4,1, }, // L 1
    };

    Inventory inventory = Inventory();
    std::vector<Wand> wands;



    bool IsColliding()
    {
        bool colliding = false;
        int f = animations[anim][frame];
        for (int Y = 0; Y < 8; Y++)
        {
            for (int X = 0; X < 8; X++)
            {
                int index = Y*8+X;
                if (image[f][index] > 0) { if (tTool::BodyCollision((x+vx)+(X-4), (y+vy)+(Y-7)) ) { colliding = true; break; } }
            }
        }
        return colliding;
    }

    void AutoDrop()
    {
        int lfoot = tCell::matrix[(y+1)*tCell::width+(x-1)]; int rfoot = tCell::matrix[(y+1)*tCell::width+x];
        if (tTool::GetType(lfoot) == tTile::PLATFORM || tTool::GetType(rfoot) == tTile::PLATFORM)
        { can_move = true; Move(0, 1); }
    }

    bool AutoJump(int d)
    {
        bool can_jump = false;
        if      (direction == 1)
        {
            if (tTool::BodyCollision(x+1, y) && !tTool::BodyCollision(x+1, y-1)) { can_jump = true; }
        }
        else if (direction == -1)
        {
            if (tTool::BodyCollision(x-2, y) && !tTool::BodyCollision(x-2, y-1)) { can_jump = true; }
        }
        return can_jump;
    }



    void Setup()
    {
        Wand w = Wand();
        w.GenerateWand();
        wands.push_back(w);
    }

    inline void Move(int X, int Y) { if (can_move) { x += X; y += Y; } can_move = false; }
    inline void TakeDamage(int damage) { hp -= int(damage-(damage*defense)); state = HURT; }

    void UpdateState()
    {
        switch (state)
        {
            case IDLE : { if (direction == 1) {anim = aIDLE_RIGHT; } else if (direction == -1) {anim = aIDLE_LEFT; } } break;
            case WALK : { if (direction == 1) {anim = aWALK_RIGHT; } else if (direction == -1) {anim = aWALK_LEFT; } } break;
            case JUMP : { if (direction == 1) {anim = aJUMP_RIGHT; } else if (direction == -1) {anim = aJUMP_LEFT; } } break;
            case FALL : { if (direction == 1) {anim = aFALL_RIGHT; } else if (direction == -1) {anim = aFALL_LEFT; } } break;
            case SWIM : { if (direction == 1) {anim = aSWIM_RIGHT; } else if (direction == -1) {anim = aSWIM_LEFT; } } break;
            case DEAD : { if (direction == 1) {anim = aDEAD_RIGHT; } else if (direction == -1) {anim = aDEAD_LEFT; } } break;
        }
    }

    void Update(float delta)
    {
        UpdateWands(delta); UpdateState();
        anim_tick += delta; if (anim_tick > 0.25) { anim_tick -= anim_delay; frame++; if (frame > 3) frame = 0; }
        tick += delta; if (tick > tick_delay) { tick -= tick_delay; can_move = true; }
        // Update Counters
        if (jp < JP && state != JUMP) jp++;
        if (bp < BP && !is_drown) bp++;
        // Update Tick Damage
        if (status != FINE) damage_tick++;
        if (damage_tick > damage_delay)
        {
            damage_tick = 0;
            switch (status)
            {
                case DROWN : { TakeDamage(1); } break;
                case BURN : { TakeDamage(1); burn_tick++; if (burn_tick > 25) { burn_tick = 0; status = FINE; } } break;
                case POISON : { TakeDamage(1); toxic_tick++; if (toxic_tick > 25) { toxic_tick = 0; status = FINE; } } break;
            }
        }
        // Tile Effects
        switch (tCell::matrix[(y-height)*tCell::width+x])
        {
            case tTile::LAVA :  { status = BURN; } break;
            case tTile::MAGMA : { status = BURN; } break;
        }
        switch (tCell::matrix[(y-height)*tCell::width+x])
        {
            case tTile::AIR  : { if (is_drown) is_drown = false; } break;
            case tTile::LAVA : { status = BURN; } break;
        }
        if (tTool::GetType(tCell::matrix[(y-height)*tCell::width+x]) == tTile::FLUID ||
            tTool::GetType(tCell::matrix[(y-height)*tCell::width+x]) == tTile::GEL) { is_drown = true; }
        if (hp < 1) state = DEAD;
        
        if      ((!tTool::FootCollision(x, y+1) && !tTool::FootCollision(x-1, y+1)) && state != JUMP) { vy = 1; state = FALL; }
        else if ((!tTool::FootCollision(x, y+1) && !tTool::FootCollision(x-1, y+1)) && state != JUMP && state != WALK) { vy = 1; state = FALL; }
        else if ((tTool::FootCollision(x, y+1) || tTool::FootCollision(x-1, y+1)) && state != JUMP) { vy = 0; state = IDLE; }
    }

    void UpdateWands(float delta) { for (int i = 0; i < wands.size(); i++) { wands[i].Update(delta); } }

    void SaveData(std::string data_dir = "0")
    {
        std::fstream data_file; std::string _dir = os::GetCWD() + dataTool::path_player + "/player_data";
        data_file.open(_dir);
        if (data_file.is_open())
        {
            data_file << "#stats" << std::endl;
            data_file << "x=" << std::to_string(x) << std::endl;
            data_file << "y=" << std::to_string(y) << std::endl;
            data_file << "reach=" << std::to_string(reach) << std::endl;
            data_file << "defense=" << std::to_string(defense) << std::endl;
            data_file << "hp=" << std::to_string(hp) << std::endl;
            data_file << "HP=" << std::to_string(HP) << std::endl;
            data_file << "mp=" << std::to_string(mp) << std::endl;
            data_file << "MP=" << std::to_string(MP) << std::endl;
            data_file << "jp=" << std::to_string(jp) << std::endl;
            data_file << "JP=" << std::to_string(JP) << std::endl;
            data_file << "bp=" << std::to_string(bp) << std::endl;
            data_file << "BP=" << std::to_string(BP) << std::endl;
            data_file << "#tiles" << std::endl;
            for (int i = 0; i < inventory.data.size(); i++) { data_file << i << "=" << inventory.data[i] << std::endl; }
            data_file.close();
        }
        else
        { std::ofstream new_file (_dir); SaveData(data_dir); }
    }

    void LoadData(std::string data_dir = "0")
    {
        std::string line; std::fstream data_file; std::string _dir = os::GetCWD() + dataTool::path_player + "/player_data";
        data_file.open(_dir);
        if (data_file.is_open())
        {
            std::string read_state = "";

            while (getline(data_file, line))
            {
                if (line.substr(0, 1) == "#") { read_state = line; }
                if (read_state == "#stats")
                {
                    //std::cout << "Loading Stats" << std::endl;
                    bool next = false; std::string var = ""; std::string val = "";
                    for (int i = 0; i < line.length(); i++)
                    {
                        std::string c = line.substr(i, 1);
                        if      (textTool::IsLetter(c)) { var = var + c; }
                        else if (textTool::IsNumber(c)) { val = val + c; }
                    }
                    if (line.substr(0, 1) != "#")
                    {
                        if      (var == "x") x = std::stoi(val);
                        else if (var == "y") y = std::stoi(val);
                        else if (var == "reach") reach = std::stoi(val);
                        else if (var == "defense") defense = std::stof(val);
                        else if (var == "hp") hp = std::stoi(val);
                        else if (var == "HP") HP = std::stoi(val);
                        else if (var == "mp") mp = std::stoi(val);
                        else if (var == "MP") MP = std::stoi(val);
                        else if (var == "jp") jp = std::stoi(val);
                        else if (var == "JP") JP = std::stoi(val);
                        else if (var == "bp") bp = std::stoi(val);
                        else if (var == "BP") BP = std::stoi(val);
                        else if (var == "is_hurt") is_hurt = std::stoi(val);
                        else if (var == "is_burn") is_burn = std::stoi(val);
                        else if (var == "is_cold") is_cold = std::stoi(val);
                        else if (var == "is_stun") is_stun = std::stoi(val);
                        else if (var == "is_trip") is_trip = std::stoi(val);
                        else if (var == "is_drown") is_drown = std::stoi(val);
                        else if (var == "is_poison") is_poison = std::stoi(val);
                        else if (var == "is_confused") is_confused = std::stoi(val);
                    }
                }
                else if (read_state == "#tiles")
                {
                    //std::cout << "Loading Tiles" << std::endl;
                    bool next = false; std::string itm = ""; std::string amnt = "";
                    for (int i = 0; i < line.length(); i++)
                    {
                        std::string c = line.substr(i, 1);
                        if (c == "=") { next = true; }
                        if (textTool::IsNumber(c)) { if (!next) {  itm = itm + c; } else { amnt = amnt + c; } }
                    }
                    if (line.substr(0, 1) != "#") { int item = std::stoi(itm); int amount = std::stoi(amnt); inventory.AddItem(item, amount); }
                }
            }
        data_file.close();
        }
    }

};
