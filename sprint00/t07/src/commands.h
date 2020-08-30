#pragma once

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <fstream>

#define TYPES "wfap"

void insert(std::vector<std::string>& inventory);
void remove(std::vector<std::string>& inventory);
void show(std::vector<std::string>& inventory);
void help(void);
std::vector<std::string> GetCommandArgs(std::string &command);
