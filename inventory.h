#include <map>

class Inventory
{

public:

    std::map<int, int> data;

    void AddItem(int item, int amnt)
    {
        if (!HasItem(item)) data[item] = 0;
        data[item] += amnt;
    }

    void UseItem(int item, int amnt)
    {
        if (HasItem(item))
        {
            if (data[item] >= amnt)
            {
                data[item] -= amnt;
            }
        }
    }

    bool HasItem(int item)
    {
        return bool(data.count(item));
    }
};
