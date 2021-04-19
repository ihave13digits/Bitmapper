class Button
{
public:

    int x = 0;
    int y = 0;

    int width = 0;
    int height = 0;

    float font = 0.0;
    std::string text = "";

    void Setup(int X, int Y, int W, int H, float fnt, std::string txt)
    {
        x = X;
        y = Y;
        
        width = W;
        height = H;

        font = fnt;
        
        text = txt;
    }

    float TextX()
    {
        return float( (x + ((width/2)) - ((text.size())*(4*font))) );
    }

    float TextY()
    {
        return float( y + (height/2) - (4*font) );
    }
    
    bool IsColliding(int X, int Y)
    {
        return ((X > x && X < x+width) && (Y > y && Y < y+height));
    }
};
