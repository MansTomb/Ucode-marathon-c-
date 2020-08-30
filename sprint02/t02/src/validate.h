#pragma once

#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <map>
#include <vector>
#include <dirent.h>

std::vector<std::string> GetCommandArgs(std::string &command);
bool IfBookExist(std::string &book);
