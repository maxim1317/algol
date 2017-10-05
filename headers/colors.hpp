#ifndef __COLORS_HPP__
#define __COLORS_HPP__
#endif


    // Regular Colors

    // Value   Color
    // \e[0;30m    Black
    // \e[0;31m    Red
    // \e[0;32m    Green
    // \e[0;33m    Yellow
    // \e[0;34m    Blue
    // \e[0;35m    Purple
    // \e[0;36m    Cyan
    // \e[0;37m    White
    
    // Bold

    // Value   Color
    // \e[1;30m    Black
    // \e[1;31m    Red
    // \e[1;32m    Green
    // \e[1;33m    Yellow
    // \e[1;34m    Blue
    // \e[1;35m    Purple
    // \e[1;36m    Cyan
    // \e[1;37m    White
    
    // High Intensty

    // Value   Color
    // \e[0;90m    Black
    // \e[0;91m    Red
    // \e[0;92m    Green
    // \e[0;93m    Yellow
    // \e[0;94m    Blue
    // \e[0;95m    Purple
    // \e[0;96m    Cyan
    // \e[0;97m    White
    
    // Bold High Intensty

    // Value   Color
    // \e[1;90m    Black
    // \e[1;91m    Red
    // \e[1;92m    Green
    // \e[1;93m    Yellow
    // \e[1;94m    Blue
    // \e[1;95m    Purple
    // \e[1;96m    Cyan
    // \e[1;97m    White
    

    // Reset

    // Value   Color
    // \e[0m   Reset

const char* conColor (int code)
{
    std::string res;
    if (code == 0)
    {   
        res = "\033[0m";
        return res.c_str();
    }
    res = "\033[";
    int bold = code/ 100;
    int fg = (code / 10) % 10;
    int bg = code % 10;
    res += std::to_string(bold) + ";";
    res += std::to_string(fg+30) + ";";
    res += std::to_string(bg+40) + "m";

    return res.c_str();
}