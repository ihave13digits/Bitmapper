class Camera
{

private:

    int min_x = core::width/2;
    int min_y = core::height/2;
    int max_x = tCell::width - core::width/2;
    int max_y = tCell::height - core::height/2;

public:

    int target_x = core::width/2;
    int target_y = core::height/2;

    int offset_x = core::width/2;
    int offset_y = core::height/2;

    float x;
    float y;

    void SetLimits()
    {
        min_x = core::width/2;
        min_y = core::height/2;
        max_x = tCell::width - core::width/2;
        max_y = tCell::height - core::height/2;
    }

    void Update(float X, float Y)
    {
        x = X;
        y = Y;
        
        // Clamp Offset
        if (X > max_x) { offset_x = tCell::width-X; }
        else if (X < min_x) { offset_x = X; }
        else { offset_x = core::width/2; }
        
        if (Y > max_y) { offset_y = tCell::width-Y; }
        else if (Y < min_y) { offset_y = Y; }
        else { offset_y = core::height/2; }
        
        offset_x = std::min(std::max(offset_x, 0), core::width);
        offset_y = std::min(std::max(offset_y, 0), core::height);
    }
};
