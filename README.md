# ColorEscape

ColorEscape is a C++ library that allows you to print text with colors and backgrounds on the terminal. It provides several functions to set the foreground and background colors of the text and to reset the colors back to their defaults. Additionally, it has two functions that take a text string and a color value, and return the text wrapped in the color codes.

## Usage

To use the ColorEscape library, include the "ColorEscape.hpp" header file in your C++ program. Then, you can call any of the functions provided by the library.

### Functions

- `void setForegroundColor(int color)`: Sets the foreground color of the text to the specified color value (0-255).
- `void setBackgroundColor(int color)`: Sets the background color of the text to the specified color value (0-255).
- `void reset()`: Resets the text colors to their default values.
- `std::string colorIn(int value, std::string text)`: Takes a color value and a text string, and returns the text wrapped in the color code for the specified color.
- `std::string colorIn2(int valueF, int valueB, std::string text)`: Takes two color values and a text string, and returns the text wrapped in the color codes for the specified foreground and background colors.

### Example

```cpp
#include <iostream>
#include "ColorEscape.hpp"

int main()
{
    std::cout << "Hello, " << ce::colorIn(33, "world") << "!" << std::endl;
    ce::setForegroundColor(202);
    std::cout << "This text has a foreground color of 202." << std::endl;
    ce::setBackgroundColor(67);
    std::cout << "This text has a background color of 67." << std::endl;
    ce::reset();
    std::cout << "This text has the default colors." << std::endl;
    std::cout << ce::colorIn2(221, 45, "This text has a foreground color of 221 and a background color of 45.") << std::endl;
    return 0;
}
```

## Implementation Details

The ColorEscape library is implemented as a single header file, "ColorEscape.hpp", which contains all the function definitions and necessary includes. The library uses ANSI escape codes to set the text color and background color. The `colorIn()` and `colorIn2()` functions return a string with the appropriate color codes wrapped around the text.

## Limitations

The ColorEscape library relies on the terminal supporting ANSI escape codes for setting colors. Some terminals may not support these codes, or may support them in a limited way. Additionally, the library does not provide any error checking or handling for invalid color values.