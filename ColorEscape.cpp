#include "ColorEscape.hpp"

void enable_vtp(void)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}


namespace ce
{
    void setForegroundColor(int colorValue)
    {
        if (colorValue >= 0 && colorValue <= 255)
        {
            std::cout << "\x1B[38;5;" + std::to_string(colorValue) + 'm';
        }
        else
        {
            std::cerr << "Invalid color value: " << colorValue << std::endl;
        }

    }

    void setBackgroundColor(int colorValue)
    {
        if (colorValue >= 0 && colorValue <= 255)
        {
            std::cout << "\x1B[48;5;" + std::to_string(colorValue) + 'm';
        }
        else
        {
            std::cerr << "Invalid color value: " << colorValue << std::endl;
        }
    }

    void reset(void)
    {
        std::cout << "\x1B[0m";
    }

    std::string colorIn(int colorValue, std::string text)
    {
        std::string sColor;
        if (colorValue >= 0 && colorValue <= 255)
        {
            sColor = "\x1B[38;5;" + std::to_string(colorValue) + 'm';
            return RESET_COLOR + sColor + text + RESET_COLOR;
        }
        else
        {
            std::cerr << "Invalid color value: " << colorValue << std::endl;
        }
        return RESET_COLOR + sColor + text + RESET_COLOR;
    }

    std::string colorIn2(int colorValueF, int colorValueB, std::string text)
    {
        std::string sColorValueF;
        std::string sColorValueB;
        if ((colorValueF >= 0 && colorValueF <= 255) && (colorValueB >= 0 && colorValueB <= 255))
        {
            sColorValueF = "\x1B[38;5;" + std::to_string(colorValueF) + 'm';
            sColorValueB = "\x1B[48;5;" + std::to_string(colorValueB) + 'm';

            return RESET_COLOR + sColorValueF + sColorValueB + text + RESET_COLOR;
        }
        else
        {   
            std::cerr << "Invalid color value: " << colorValueF << " or " << colorValueB <<std::endl;
        }
        return RESET_COLOR + sColorValueF + sColorValueB + text + RESET_COLOR;
    }
}


// void setForegroundColor(std::ostream& os, int color)
// {
//     if (color >= 0 && color <= 255)
//     {
//         os << "\x1B[38;5;" + std::to_string(color) + 'm';
//     }
// }
