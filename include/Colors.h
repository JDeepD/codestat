#ifndef _COLORS_H
#define _COLORS_H
#include <string>
#include <sstream>
#include <iostream>


#define CSI "\033["
#define RESET "\033[0m"
#define BOLD_FG "1;38;2;"
std::string parse_rgb(std::string text, int red = 255, int green = 255, int blue = 255);

#endif
