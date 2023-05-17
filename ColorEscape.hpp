

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #define RESET_COLOR "\x1B[0m"
#endif

#ifndef COLORESCAPE_HPP
#define COLORESCAPE_HPP

    #include <iostream>
    #include <string>
    #include <windows.h>

    void enable_vtp(void);

    namespace ce
    {
        enum Color
        {
            Red = 160,
            Orange = 208,
            Yellow = 220,
            Green = 28,
            Blue = 27,
            Purple = 127,
            White = 255,
            Black = 0,
        };

        void setForegroundColor(int);
        void setBackgroundColor(int);
        void reset(void);
        std::string colorIn(int, std::string);
        std::string colorIn2(int, int, std::string);
    }

#endif

