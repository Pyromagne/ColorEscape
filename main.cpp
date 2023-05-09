#include "ColorEscape.hpp"
#include <iostream>

int main()
{
    enable_vtp();

    std::cout << "Hello, " << color::colorIn(33, "world") << "!" << std::endl;

    color::setForegroundColor(202);
    std::cout << "This text has a foreground color of 202." << std::endl;

    color::setBackgroundColor(67);
    std::cout << "This text has a background color of 67." << std::endl;

    color::reset();

    std::cout << "This text has the default colors." << std::endl;
    
    std::cout << color::colorIn2(221, 45, "This text has a foreground color of 221 and a background color of 45.") << std::endl;

    return 0;
}