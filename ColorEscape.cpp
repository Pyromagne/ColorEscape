////////////////////////////////////////////////////////////
// MIT License
//
// Copyright (c) 2024 Pyromagne
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
////////////////////////////////////////////////////////////

#include "colorescape.hpp"

////////////////////////////////////////////////////////////
void enable_vtp(void)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
namespace ce
{
    ////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////
    void reset(void)
    {
        std::cout << "\x1B[0m";
    }
    ////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////

}
////////////////////////////////////////////////////////////


//future update
// void setForegroundColor(std::ostream& os, int color)
// {
//     if (color >= 0 && color <= 255)
//     {
//         os << "\x1B[38;5;" + std::to_string(color) + 'm';
//     }
// }
