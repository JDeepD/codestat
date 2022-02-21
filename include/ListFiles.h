#ifndef _LISTFILES_H
#define _LISTFILES_H

#include <filesystem>
#include <map>
#include <string>
#include <vector>
#include <sys/types.h>
#include <iostream>

std::vector<std::string> listfiles(std::string dir, std::vector<std::string> ignored = {""});
std::map<std::string, int> filedata(std::string dir = ".");

#endif
