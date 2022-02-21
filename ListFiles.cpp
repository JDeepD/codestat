#include "include/ListFiles.h"

/*
 * This function looks up all the files in a directory
 * recursively and returns a vector of file names.
 * Optionally, provide a vector of strings of files/dir to ignore while search[WIP]
 *
 * Give the directory it has to search as input(string)
 * WIP
 */

std::vector<std::string> listfiles(std::string dir, std::vector<std::string> ignored)
{
	std::vector<std::string> FILES;

	const std::filesystem::path ROOTDIR {dir};

	for (std::filesystem::path const& dirent : std::filesystem::recursive_directory_iterator{ROOTDIR}) {
		if (std::filesystem::is_regular_file(dirent)) {
			std::string filename = dirent.string();
			FILES.push_back(filename);
		}
	}

	return FILES;
}


int main()
{
	std::map<std::string, int> dat = filedata("../Open-Palm");
	for(const auto& elem : dat){
   		std::cout << elem.first << " " << elem.second << "\n";
	}
}


/*
 * This function looks up all the files in a directory("." by default)
 * recursively and returns a map of filename(string) and filesize(int).
 *
 * Give the directory it has to search as input(string)
 * WIP
 */

std::map<std::string, int> filedata(std::string dir){
	std::map<std::string, int> data;
	
	const std::filesystem::path ROOTDIR {dir};

	for (std::filesystem::path const& filent : std::filesystem::recursive_directory_iterator{ROOTDIR}) {
		if (std::filesystem::is_regular_file(filent)) {
			data[filent.extension().string()] += std::filesystem::file_size(filent);
		}
	}
	return data;
}
