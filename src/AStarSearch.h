#ifndef ASTARSEARCH_H
#define ASTARSEARCH_H

#include "boardParser.h"
#include <vector>
#include <string>

bool Compare(const std::vector<int> a, const std::vector<int> b);
void CellSort(std::vector<std::vector<int>> *v);
int Heuristic(int x1, int y1, int x2, int y2);
bool CheckValidCell(int x, int y, std::vector<std::vector<State>> &grid);


#endif