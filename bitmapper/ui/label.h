class Label
{

public:

    int cursor = 0;
    int max_chars = 16;
    float x;
    float y;
    float font;
    std::string text;
    
    //
    //
    //

    int Size() { return text.length(); }
    float Width() { return ( float(text.length()) * (font * 4.0) ); }
    //
    void CursorM() { if (cursor > 0) { cursor--; if (Size() == 0) cursor = 0; } }
    void CursorP() { if (cursor < max_chars-1) { cursor++; } if (cursor > Size()) cursor = Size(); }
    //
    void AddChar(std::string c) { if (Size() < max_chars) { text.insert(cursor, c); CursorP(); } }
    void DelChar()              { if (cursor >= 0 && cursor != Size()) { text.erase(text.begin()+cursor); } }
    void BackChar()             { if (cursor > 0) { text.erase(text.begin()+cursor-1); CursorM(); } }
    void Replace(std::string c) { text.replace(text.begin()+cursor, text.begin()+cursor+1, c); }

    void Update(std::string cmd)
    {
        if      (cmd.size() == 1) { AddChar(cmd); }
        else if (cmd == "DEL")    {    DelChar(); }
        else if (cmd == "BACK")   {   BackChar(); }
        else if (cmd == "LEFT")   {    CursorM(); }
        else if (cmd == "RIGHT")  {    CursorP(); }
    }

};
