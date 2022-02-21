#include "include/ProcessData.h"
#include "include/ListFiles.h"

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


std::map<std::string, float> process(std::map<std::string, int>& data)
{
	std::map<std::string, float> processed_data;
	long int sum = 0;
	for (auto& elem : data) {
		sum += elem.second;
	}

	for (auto& [elem, value] : data) {
		processed_data[elem] = ((float)value*100/sum);
	}

	return processed_data;

}

int main()
{
	std::map<std::string, int> mp = filedata(".");
	std::map<std::string, float> mp2 = process(mp);

	for (auto& elem : mp2) {
		std::cout << elem.first << " "<< elem.second << "\n";
	}
}
