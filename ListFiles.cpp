#include "include/ListFiles.h"
#include <algorithm>
#include <vector>

/* int main() */
/* { */
/* 	std::map<std::string, int> dat = filedata("../Open-Palm", {".pack", ".jpg", ".pdf", ".sample", ".png", ""}); */
/* 	for(const auto& elem : dat){ */
/*    		std::cout << elem.first << " " << elem.second << "\n"; */
/* 	} */
/* } */

/*
 * This function looks up all the files in a directory("." by default)
 * recursively and returns a map of filename(string) and filesize(int).
 *
 * Give the directory it has to search as input(string)
 * WIP
 */

std::map<std::string, int> filedata(std::string dir, std::vector<std::string> ignored){
	std::map<std::string, int> data;
	
	const std::filesystem::path ROOTDIR {dir};

	for (std::filesystem::path const& filent : std::filesystem::recursive_directory_iterator{ROOTDIR}) {
		if (std::filesystem::is_regular_file(filent)) {
			if (!isPresent(ignored, filent.extension().string())) {
				data[filent.extension().string()] += std::filesystem::file_size(filent);
			}
		}
	}
	return data;
}

bool isPresent(std::vector<std::string> ign_exts, std::string str){
	bool invec = std::find(ign_exts.begin(), ign_exts.end(), str) != ign_exts.end();	
	return invec;
}
