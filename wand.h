class Wand
{

public:

    bool shuffle;
    int capacity;

    std::vector<Effect> effects;

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

};
