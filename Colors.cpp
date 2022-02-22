#include "include/Colors.h"

/*
 * parse_rgb parses a given string text into a CSI sequence of specified rgb colors
 * Default rgb is set to 255,255,255 (white)
 *
 */

std::string parse_rgb(std::string text, int red, int green, int blue){
	std::stringstream str;
	str << CSI << BOLD_FG << red << ";" << green << ";" << blue << "m" << text << RESET;
	return str.str();
}


int main(){
	std::cout << parse_rgb("Hello World", 109, 91, 212) << "\n";
}
