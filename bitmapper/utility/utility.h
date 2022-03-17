namespace textTool
{

    inline bool IsNumber(std::string c)
    {
        bool can_do = false;
        if ( c=="-" || c=="." || c=="1" || c=="2" || c=="3" || c=="4" || c=="5" || c=="6" || c=="7" || c=="8" || c=="9" || c=="0" ) { can_do = true; }
        return can_do;
    }

    inline bool IsValidNumber(std::string s)
    { bool can_do = true; for (int i = 0; i < s.length(); i++) { std::string c = s.substr(i, 1); if (!IsNumber(c)) { can_do = false; break; } } return can_do; }

    inline bool IsLetter(std::string c)
    {
        bool can_do = false;
        if (c=="a" || c=="b" || c=="c" || c=="d" || c=="e" || c=="f" || c=="g" || c=="h" || c=="i" || c=="j" ||
            c=="k" || c=="l" || c=="m" || c=="n" || c=="o" || c=="p" || c=="q" || c=="r" || c=="s" || c=="t" ||
            c=="u" || c=="v" || c=="w" || c=="x" || c=="y" || c=="z" ||
            c=="A" || c=="B" || c=="C" || c=="D" || c=="E" || c=="F" || c=="G" || c=="H" || c=="I" || c=="J" ||
            c=="K" || c=="L" || c=="M" || c=="N" || c=="O" || c=="P" || c=="Q" || c=="R" || c=="S" || c=="T" ||
            c=="U" || c=="V" || c=="W" || c=="X" || c=="Y" || c=="Z")
        { can_do = true; }
        return can_do;
    }

    inline bool IsSymbol(std::string c)
    {
        bool can_do = false;
        if (c=="!" || c=="@" || c=="#" || c=="$" || c=="%" || c=="^" || c=="&" || c=="*" || c=="(" || c==")" ||
            c=="{" || c=="}" || c=="[" || c=="]" || c==";" || c==":" || c=="'" || c=="\"" || c=="," || c=="." ||
            c=="<" || c==">" || c=="/" || c=="?" || c=="`" || c=="~")
        { can_do = true; }
        return can_do;
    }

    inline bool IsValidSave(std::string c)
    {
        bool can_do = false;
        if (IsLetter(c) ||
           c=="!" || c=="@" || c=="#" || c=="$" || c=="%" || c=="^" || c=="&" || c=="*" || c=="(" || c==")" ||
            c=="{" || c=="}" || c==";" || c==":" || c=="'" || c=="\"" || c=="." ||
            c=="<" || c==">" || c=="/" || c=="?" || c=="`" || c=="~"
                )
        { can_do = true; }
        return can_do;
    }

    inline bool IsValidCharacter(std::string c) { return (IsNumber(c) && IsSymbol(c) && IsLetter(c)); }
}
