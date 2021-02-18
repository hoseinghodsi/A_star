#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

enum class State {kEmpty, kObstacle, kClosed, kPath, kStart, kFinish};

std::vector<State> ParseLine(std::string line) {
    std::istringstream sline(line);
    int n;
    char c;
    std::vector<State> row;
    while (sline >> n >> c && c == ',') {
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}

std::vector<std::vector<State>> ReadBoardFile(std::string path) {
  std::ifstream myfile (path);
  std::vector<std::vector<State>> board{};
  if (myfile) {
    std::string line;
    while (getline(myfile, line)) {
      std::vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}