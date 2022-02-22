#include "include/ProcessData.h"

/*
 * This function processes the data such that the size of the file
 * is the % of the total size of all the files.
 * Returns a map<string, float>
 */
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
