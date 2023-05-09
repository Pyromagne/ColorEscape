#ifndef COLORESCAPE_HPP
#define COLORESCAPE_HPP

#include <iostream>

const std::string COLRES = "\x1B[0m";

namespace color
{
    void setForegroundColor(int);
    void setBackgroundColor(int);
    void reset(void);
    std::string colorIn(int, std::string);
    std::string colorIn2(int, int, std::string);
}

#endif

