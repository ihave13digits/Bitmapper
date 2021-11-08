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

    int direction = 1;
    int state = 0;
    int status = 0;

    float tick = 0.0;
    float tick_delay = 0.0125;
    int damage_tick = 0;
    int damage_delay = 10;
    int burn_tick = 0;
    int toxic_tick = 0;

    int x = 0;
    int y = 0;
    int vx = 0;
    int vy = 0;

    int height = 8;

    int HP = 100;
    int hp = 100;
    int MP = 100;
    int mp = 100;
    int JP = 100;
    int jp = 100;
    int bp = 100;
    int BP = 100;

    float defense = 0.0;

    char frame = 0;
    char anim = 0;
    float anim_tick = 0.0;
    float anim_delay = 0.125;

    //bool status[9] = { true, false, false, false, false, false, false, false, false };
    int hotbar[9][2] = { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} };

    char animations[14][4] = {
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

    char image[18][64] = {
        { // Idle Right 1
            0,0,0,0,7,8,0,0,
            0,0,0,0,6,7,0,0,
            0,0,0,3,2,0,0,0,
            0,0,6,2,1,0,0,0,
            0,0,7,1,1,0,0,0,
            0,0,0,3,3,0,0,0,
            0,0,0,3,2,0,0,0,
            0,0,0,2,1,0,0,0,
        },
        { // Idle Left 1
            0,0,8,7,0,0,0,0,
            0,0,7,6,0,0,0,0,
            0,0,0,2,3,0,0,0,
            0,0,0,1,2,6,0,0,
            0,0,0,1,1,7,0,0,
            0,0,0,3,3,0,0,0,
            0,0,0,2,3,0,0,0,
            0,0,0,1,2,0,0,0,
        },
        { // Idle Right 2
            0,0,0,0,0,0,0,0,
            0,0,0,0,8,8,0,0,
            0,0,0,3,6,8,0,0,
            0,0,6,2,1,0,0,0,
            0,0,7,1,1,0,0,0,
            0,0,0,3,3,0,0,0,
            0,0,0,3,2,0,0,0,
            0,0,0,2,1,0,0,0,
        },
        { // Idle Left 2
            0,0,0,0,0,0,0,0,
            0,0,8,7,0,0,0,0,
            0,0,7,6,3,0,0,0,
            0,0,0,1,2,6,0,0,
            0,0,0,1,1,7,0,0,
            0,0,0,3,3,0,0,0,
            0,0,0,2,3,0,0,0,
            0,0,0,1,2,0,0,0,
        },
        {// Walk
            0,0,0,0,7,8,0,0,
            0,0,0,0,6,7,0,0,
            0,0,0,3,2,0,0,0,
            0,0,6,2,1,0,0,0,
            0,7,0,1,1,8,0,0,
            0,0,0,4,4,4,0,0,
            0,0,0,4,0,1,0,0,
            0,0,0,2,0,0,0,0,
        },
        {
            0,0,8,7,0,0,0,0,
            0,0,7,6,0,0,0,0,
            0,0,0,2,3,0,0,0,
            0,0,0,1,2,6,0,0,
            0,0,8,1,1,0,7,0,
            0,0,4,4,4,0,0,0,
            0,0,1,0,4,0,0,0,
            0,0,0,0,2,0,0,0,
        },
        {
            0,0,0,0,7,8,0,0,
            0,0,0,0,6,7,0,0,
            0,0,0,3,2,0,0,0,
            0,0,0,6,1,0,0,0,
            0,0,0,1,7,0,0,0,
            0,0,0,4,4,0,0,0,
            0,0,2,4,3,0,0,0,
            0,0,0,0,1,0,0,0,
        },
        {
            0,0,8,7,0,0,0,0,
            0,0,7,6,0,0,0,0,
            0,0,0,2,3,0,0,0,
            0,0,0,1,6,0,0,0,
            0,0,0,7,1,0,0,0,
            0,0,0,4,4,0,0,0,
            0,0,0,3,4,2,0,0,
            0,0,0,1,0,0,0,0,
        },
        { // Run
            0,0,0,0,0,0,0,0,
            0,0,0,0,7,8,0,0,
            0,0,0,3,6,7,0,0,
            0,0,0,2,1,0,0,0,
            0,0,6,1,1,6,0,0,
            0,7,0,4,4,4,0,0,
            0,0,0,4,0,1,0,0,
            0,0,0,2,0,0,0,0,
        },
        {
            0,0,0,0,0,0,0,0,
            0,0,8,7,0,0,0,0,
            0,0,7,6,3,0,0,0,
            0,0,0,1,2,0,0,0,
            0,0,0,1,1,6,0,0,
            0,0,4,4,4,0,7,0,
            0,0,1,0,4,0,0,0,
            0,0,0,0,2,0,0,0,
        },
        {
            0,0,0,0,0,0,0,0,
            0,0,0,0,7,8,0,0,
            0,0,0,3,6,7,0,0,
            0,0,0,1,1,0,0,0,
            0,0,0,6,1,0,0,0,
            0,0,0,4,7,0,0,0,
            0,0,2,4,3,0,0,0,
            0,0,0,0,1,0,0,0,
        },
        {
            0,0,0,0,0,0,0,0,
            0,0,8,7,0,0,0,0,
            0,0,7,6,3,0,0,0,
            0,0,0,1,1,0,0,0,
            0,0,0,1,6,0,0,0,
            0,0,0,7,4,0,0,0,
            0,0,0,3,4,2,0,0,
            0,0,0,1,0,0,0,0,
        },
        // Swim
        {
            0,0,0,0,0,7,8,0,
            0,0,0,0,0,6,7,0,
            0,0,0,0,3,2,0,0,
            0,0,0,2,1,6,0,0,
            0,0,2,1,2,0,7,0,
            0,0,4,4,0,0,0,0,
            0,3,4,3,0,0,0,0,
            0,2,1,0,0,0,0,0,
        },
        {
            0,8,7,0,0,0,0,0,
            0,7,6,0,0,0,0,0,
            0,0,2,3,0,0,0,0,
            0,0,6,1,2,0,0,0,
            0,7,0,2,1,2,0,0,
            0,0,0,0,4,4,0,0,
            0,0,0,0,3,4,3,0,
            0,0,0,0,0,1,2,0,
        },
        {
            0,0,0,0,0,7,8,0,
            0,0,0,0,0,6,7,0,
            0,0,0,0,3,2,0,0,
            0,0,0,2,1,6,7,0,
            0,0,2,1,2,0,0,0,
            0,0,4,4,0,0,0,0,
            0,3,4,3,0,0,0,0,
            0,2,1,0,0,0,0,0,
        },
        {
            0,8,7,0,0,0,0,0,
            0,7,6,0,0,0,0,0,
            0,0,2,3,0,0,0,0,
            0,7,6,1,2,0,0,0,
            0,0,0,2,1,2,0,0,
            0,0,0,0,4,4,0,0,
            0,0,0,0,3,4,3,0,
            0,0,0,0,0,1,2,0,
        },
        // Dead
        {
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,2,4,4,2,1,7,8,
            1,4,4,4,1,1,6,7,
        },
        {
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            8,7,1,2,4,4,2,0,
            7,6,1,1,4,4,4,1,
        },
    };

    Inventory inventory = Inventory();
    std::vector<Wand> wands;



    void Setup()
    {
        Wand w = Wand();
        w.GenerateWand();
        wands.push_back(w);
    }

    void Move(int X, int Y) { if (can_move) { x += X; y += Y; } can_move = false; }
    void TakeDamage(int damage) { hp -= int(damage-(damage*defense)); state = HURT; }

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
        if (bp < BP && state != DROWN) bp++;
        // Update Tick Damage
        if (status != FINE) damage_tick++;
        if (damage_tick > damage_delay)
        {
            damage_tick = 0;
            switch (status)
            {
                case DROWN : { TakeDamage(1); } break;
                case BURN : {
                    TakeDamage(1); burn_tick++;
                    if (burn_tick > 25) { burn_tick = 0; status = FINE; } } break;
                case POISON : {
                    TakeDamage(1); toxic_tick++;
                    if (toxic_tick > 25) { toxic_tick = 0; status = FINE; } } break;
            }
        }
        // Tile Effects
        switch (tCell::matrix[(y+1)*tCell::width+x])
        {
            case tTile::LAVA :  { status = BURN; } break;
            case tTile::MAGMA : { status = BURN; } break;
        }
        switch (tCell::matrix[(y-core::height)*tCell::width+x])
        {
            case tTile::AIR  : { if (status == DROWN) status = FINE; } break;
            case tTile::LAVA : { status = BURN; } break;
        }
    }

    void UpdateWands(float delta) { for (int i = 0; i < wands.size(); i++) { wands[i].Update(delta); } }

    void SaveData(std::string data_dir = "0")
    {
        std::fstream data_file; std::string _dir = os::GetCWD() + dataTool::path_player + "/player_data";
        data_file.open(_dir);
        if (data_file.is_open())
        {
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
                if (line == "#tiles") { read_state = "#tiles"; }
                if (read_state == "#tiles")
                {
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
