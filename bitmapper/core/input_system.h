namespace control
{
    char selected_hotbar = 0;
    char selected_tile = 0;
    char selected_wand = 0;
    int input_value = 0;

    bool ShiftKey()
    {
        bool shift;
        if (GetKey(olc::Key::SHIFT).bHeld) { shift = true}
        return shift;
    }

    bool CtrlKey()
    {
        bool ctrl;
        return ctrl;
    }

    std::string GetCharacter()
    {
        std::string c;
        if (!SHiftKey())
        {
            if (GetKey(olc::Key::A).bPressed) {c = "a";}
            if (GetKey(olc::Key::B).bPressed) {c = "b";}
            if (GetKey(olc::Key::C).bPressed) {c = "c";}
            if (GetKey(olc::Key::D).bPressed) {c = "d";}
            if (GetKey(olc::Key::E).bPressed) {c = "e";}
            if (GetKey(olc::Key::F).bPressed) {c = "f";}
            if (GetKey(olc::Key::G).bPressed) {c = "g";}
            if (GetKey(olc::Key::H).bPressed) {c = "h";}
            if (GetKey(olc::Key::I).bPressed) {c = "i";}
            if (GetKey(olc::Key::J).bPressed) {c = "j";}
            if (GetKey(olc::Key::K).bPressed) {c = "k";}
            if (GetKey(olc::Key::L).bPressed) {c = "l";}
            if (GetKey(olc::Key::M).bPressed) {c = "m";}
            if (GetKey(olc::Key::N).bPressed) {c = "n";}
            if (GetKey(olc::Key::O).bPressed) {c = "o";}
            if (GetKey(olc::Key::P).bPressed) {c = "p";}
            if (GetKey(olc::Key::Q).bPressed) {c = "q";}
            if (GetKey(olc::Key::R).bPressed) {c = "r";}
            if (GetKey(olc::Key::S).bPressed) {c = "s";}
            if (GetKey(olc::Key::T).bPressed) {c = "t";}
            if (GetKey(olc::Key::U).bPressed) {c = "u";}
            if (GetKey(olc::Key::V).bPressed) {c = "v";}
            if (GetKey(olc::Key::W).bPressed) {c = "w";}
            if (GetKey(olc::Key::X).bPressed) {c = "x";}
            if (GetKey(olc::Key::Y).bPressed) {c = "y";}
            if (GetKey(olc::Key::Z).bPressed) {c = "z";}
            if (GetKey(olc::Key::K0).bPressed) {c = "0";}
            if (GetKey(olc::Key::K1).bPressed) {c = "1";}
            if (GetKey(olc::Key::K2).bPressed) {c = "2";}
            if (GetKey(olc::Key::K3).bPressed) {c = "3";}
            if (GetKey(olc::Key::K4).bPressed) {c = "4";}
            if (GetKey(olc::Key::K5).bPressed) {c = "5";}
            if (GetKey(olc::Key::K6).bPressed) {c = "6";}
            if (GetKey(olc::Key::K7).bPressed) {c = "7";}
            if (GetKey(olc::Key::K8).bPressed) {c = "8";}
            if (GetKey(olc::Key::K9).bPressed) {c = "9";}
            if (GetKey(olc::Key::SPACE).bPressed) {c = " ";}
        }
        if (ShiftKey())
        {
            if (GetKey(olc::Key::A).bPressed) {c = "A";}
            if (GetKey(olc::Key::B).bPressed) {c = "B";}
            if (GetKey(olc::Key::C).bPressed) {c = "C";}
            if (GetKey(olc::Key::D).bPressed) {c = "D";}
            if (GetKey(olc::Key::E).bPressed) {c = "E";}
            if (GetKey(olc::Key::F).bPressed) {c = "F";}
            if (GetKey(olc::Key::G).bPressed) {c = "G";}
            if (GetKey(olc::Key::H).bPressed) {c = "H";}
            if (GetKey(olc::Key::I).bPressed) {c = "I";}
            if (GetKey(olc::Key::J).bPressed) {c = "J";}
            if (GetKey(olc::Key::K).bPressed) {c = "K";}
            if (GetKey(olc::Key::L).bPressed) {c = "L";}
            if (GetKey(olc::Key::M).bPressed) {c = "M";}
            if (GetKey(olc::Key::N).bPressed) {c = "N";}
            if (GetKey(olc::Key::O).bPressed) {c = "O";}
            if (GetKey(olc::Key::P).bPressed) {c = "P";}
            if (GetKey(olc::Key::Q).bPressed) {c = "Q";}
            if (GetKey(olc::Key::R).bPressed) {c = "R";}
            if (GetKey(olc::Key::S).bPressed) {c = "S";}
            if (GetKey(olc::Key::T).bPressed) {c = "T";}
            if (GetKey(olc::Key::U).bPressed) {c = "U";}
            if (GetKey(olc::Key::V).bPressed) {c = "V";}
            if (GetKey(olc::Key::W).bPressed) {c = "W";}
            if (GetKey(olc::Key::X).bPressed) {c = "X";}
            if (GetKey(olc::Key::Y).bPressed) {c = "Y";}
            if (GetKey(olc::Key::Z).bPressed) {c = "Z";}
        }
        return c;
    }

    void HotbarInput()
    {
        if (GetKey(olc::Key::K1).bPressed) {selected_hotbar = 0;}
        if (GetKey(olc::Key::K2).bPressed) {selected_hotbar = 1;}
        if (GetKey(olc::Key::K3).bPressed) {selected_hotbar = 2;}
        if (GetKey(olc::Key::K4).bPressed) {selected_hotbar = 3;}
        if (GetKey(olc::Key::K5).bPressed) {selected_hotbar = 4;}
        if (GetKey(olc::Key::K6).bPressed) {selected_hotbar = 5;}
        if (GetKey(olc::Key::K7).bPressed) {selected_hotbar = 6;}
        if (GetKey(olc::Key::K8).bPressed) {selected_hotbar = 7;}
        if (GetKey(olc::Key::K9).bPressed) {selected_hotbar = 8;}
    }
}
