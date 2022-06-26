class Button
{
public:

    float x;
    float y;

    float width;
    float height;

    float font;
    std::string text = "";

    Button(int X=0, int Y=0, int W=0, int H=0, float fnt=1.0, std::string txt="") { x=X; y=Y; width=W; height=H; font=fnt; text=txt; }
    void SetText(std::string txt) {text = txt;}

    float TextX() { return float( (x + ((width/2.0)) - (float(text.size())*(4.0*font))) ); }
    float TextY() { return float( y + (height/2.0) - (4.0*font) ); }

    bool IsColliding() { return ((core::mouse_x > x && core::mouse_x < x+width) && (core::mouse_y > y && core::mouse_y < y+height)); }
};
