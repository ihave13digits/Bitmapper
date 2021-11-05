struct Recipe { public: uint8_t item_type; std::vector<uint8_t> takes; std::vector<uint8_t> gives; };

class Craft
{

public:

    std::vector<Recipe> recipes;

    void GenerateRecipes()
    {
        Recipe mud = Recipe(); mud.item_type = 1;
        mud.takes = {tTile::WATER, tTile::DIRT, };
        mud.gives = {tTile::MUD, tTile::MUD, };
        recipes.push_back(mud);
        
        Recipe ice_wall = Recipe(); ice_wall.item_type = 2;
        ice_wall.takes = {tTile::ICE};
        ice_wall.gives = {tTile::ICE_WALL};
        recipes.push_back(ice_wall);
        
        Recipe wand = Recipe(); wand.item_type = 3;
        wand.takes = {tTile::STICK};
        wand.gives = {};
        recipes.push_back(wand);
        
        Recipe axe = Recipe(); axe.item_type = 4;
        axe.takes = {tTile::IRON, tTile::NICKEL, tTile::STICK, };
        axe.gives = {};
        recipes.push_back(axe);
        
        Recipe pickaxe = Recipe(); pickaxe.item_type = 5;
        pickaxe.takes = {tTile::IRON, tTile::COBALT, tTile::STICK};
        pickaxe.gives = {};
        recipes.push_back(pickaxe);
        
        Recipe hammer = Recipe(); hammer.item_type = 6;
        hammer.takes = {tTile::COBALT, tTile::NICKEL, tTile::STICK};
        hammer.gives = {};
        recipes.push_back(hammer);
        
        Recipe wrench = Recipe(); wrench.item_type = 7;
        wrench.takes = {tTile::IRON, tTile::NICKEL, tTile::COBALT};
        wrench.gives = {};
        recipes.push_back(wrench);
    }

    void Show(int data) { std::cout << data << std::endl; }

};
