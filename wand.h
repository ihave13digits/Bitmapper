class Wand
{

public:

    bool shuffle;
    int capacity;

    std::vector<Effect> effects;

    bool icon[64];

    void generate_wand()
    {
        generate_stats();
        generate_img();
    }

    void generate_stats()
    {
        shuffle = true;
        shuffle = false;
        capacity = 5;
    }

    void generate_image()
    {
        icon = {
            0,0,0,0,0,1,0,0,
            0,0,0,0,0,1,0,0,
            0,0,0,0,1,0,0,0,
            0,0,0,0,1,0,0,0,
            0,0,0,1,1,0,0,0,
            0,0,0,1,0,0,0,0,
            0,0,1,1,0,0,0,0,
            0,0,1,1,0,0,0,0,
        };
    }

    void cast()
    {
    }

};
