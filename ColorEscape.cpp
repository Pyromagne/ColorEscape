#include "ColorEscape.hpp"

void enable_vtp(void)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}


namespace color
{
    void setForegroundColor(int color)
    {
        if (color >= 0 && color <= 255)
        {
            std::cout << "\x1B[38;5;" + std::to_string(color) + 'm';
        }
        //else throw std::invalid_argument("Invalid color value");

    }

    void setBackgroundColor(int color)
    {
        if (color >= 0 && color <= 255)
        {
            std::cout << "\x1B[48;5;" + std::to_string(color) + 'm';
        }
        //else throw std::invalid_argument("Invalid color value");
    }

    void reset(void)
    {
        std::cout << "\x1B[0m";
    }

    std::string colorIn(int value, std::string text)
    {
        if (value >= 0 && value <= 255)
        {
            std::string color = "\x1B[38;5;" + std::to_string(value) + 'm';
            return COLRES + color + text + COLRES;
        }
        else return "COLOR_OUT_OF_BOUND";
    }

    std::string colorIn2(int valueF, int valueB, std::string text)
    {
        if ((valueF >= 0 && valueF <= 255) && (valueB >= 0 && valueB <= 255))
        {
            std::string colorF = "\x1B[38;5;" + std::to_string(valueF) + 'm';
            std::string colorB = "\x1B[48;5;" + std::to_string(valueB) + 'm';

            return COLRES + colorF + colorB + text + COLRES;
        }
        else return "COLOR_OUT_OF_BOUND";
    }
}
