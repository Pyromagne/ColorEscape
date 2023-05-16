#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

#ifndef COLORESCAPE_HPP
#define COLORESCAPE_HPP

    #include <iostream>
    #include <windows.h>

    void enable_vtp(void);

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

