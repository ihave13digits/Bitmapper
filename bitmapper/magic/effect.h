class Effect
{

public:

    bool sticky;
    bool bouncy;
    bool heavy;

    bool destroys;
    bool becomes;
    bool damages;
    bool pierces;
    bool poisons;
    bool trails;
    bool mines;
    bool trips;
    bool stuns;
    bool burns;

    int tile_trail;
    int tile_value;
    int damage;
    int drain;

    std::string name;

};

namespace effectID
{
    int total_effects = 13;

    std::string NAME[13] = 
    {
        "Sticky",
        "Bouncy",
        "Heavy",
        "Destroys",
        "Becomes",
        "Damages",
        "Pierces",
        "Poisons",
        "Trails",
        "Mines",
        "Trips",
        "Stuns",
        "Burns",
    };

    enum EFFECTS
    {
        STICKY,
        BOUNCY,
        HEAVY,
        DESTROYS,
        BECOMES,
        DAMAGES,
        PIERCES,
        POISONS,
        TRAILS,
        MINES,
        TRIPS,
        STUNS,
        BURNS,
    };
}
