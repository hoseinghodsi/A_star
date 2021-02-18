#ifndef BOARDPARSER_H
#define BOARDPARSER_H

#include <vector>
#include <string>

enum class State;
std::vector<State> ParseLine(std::string line);
std::vector<std::vector<State>> ReadBoardFile(std::string path);
void AddToOpen(int x, int y, int g, int h, std::vector<std::vector<int>> &openlist, std::vector<std::vector<State>> &grid);
void ExpandNeighbors(const std::vector<int> &current, int goal[2], std::vector<std::vector<int>> &openlist, std::vector<std::vector<State>> &grid);
std::vector<std::vector<State>> Search(std::vector<std::vector<State>> grid, int init[2], int goal[2]);


#endif