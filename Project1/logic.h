// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifndef __LOGIC_H_INCLUDED__
#define __LOGIC_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

class Equipment;

void readFromFile(std::vector<Equipment*>& Table);
void readFromConsole(std::vector<Equipment*>& Table);
void commandPrint(std::vector<Equipment*>& Table);

#endif 
