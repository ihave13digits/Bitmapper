class Effect
{

public:

    bool sticky = false;
    bool bouncy = false;
    bool heavy = false;

    bool destroys = false;
    bool becomes = false;
    bool damages = false;
    bool poisons = false;
    bool mines = false;
    bool trips = false;
    bool stuns = false;
    bool burns = false;

    int tile_value = 0;
    int damage = 0;
    int drain = 0;

    std::string name = "Template";

};
