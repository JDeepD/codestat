#include "include/Colors.h"
#include "include/ListFiles.h"
#include "include/ProcessData.h"


int main(int argc, char **argv){
	std::string ROOTDIR = ".";
	if (argc > 1){
		ROOTDIR = argv[1];
	}

	std::map<std::string, int> dat = filedata(ROOTDIR, {".pack", ".jpg", ".pdf", ".sample", ".png", ""});
	std::map<std::string, float> processed_data = process(dat);

	for (auto& [format, percent] : processed_data) {
		std::cout << parse_rgb(format, 109, 91, 212) << "\t" << parse_rgb(std::to_string(percent) + " %", 100, 90, 200)<<"\n";
	}
}
