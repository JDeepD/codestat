#ifndef _LISTFILES_H
#define _LISTFILES_H

#include <filesystem>
#include <map>
#include <string>
#include <vector>
#include <sys/types.h>
#include <iostream>

std::map<std::string, int> filedata(std::string dir = ".", std::vector<std::string> ignored = {""});
bool isPresent(std::vector<std::string> ign_paths, std::string str);

#endif
