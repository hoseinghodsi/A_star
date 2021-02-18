#ifndef UTIL_H
#define UTIL_H

#include "boardParser.h"
#include <vector>
#include <string>

std::string CellString(State cell);
void PrintBoard(const std::vector<std::vector<State>> board);

#endif