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
        bool can_do = bool(data.count(item));
        if (can_do) { if (data[item] <= 0) { return false; } }
        return true;
    }

};
