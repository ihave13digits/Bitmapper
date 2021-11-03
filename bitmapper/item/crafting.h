struct Recipe
{

public:

    uint8_t item_type;
    std::vector<uint8_t> takes;
    std::vector<uint8_t> gives;
};

class Craft
{

public:

    void Show(int data) { std::cout << data << std::endl; }

};
