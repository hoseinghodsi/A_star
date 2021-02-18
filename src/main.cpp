#include "boardParser.h";
#include "AStarSearch.h";
#include "util.h";

int main() {
  int init[2]{0, 0};
  int goal[2]{0, 7};
  //int init[2]{0, 0};
  //int goal[2]{4, 5};  
  auto board = ReadBoardFile("../files/10x10.board");
  auto solution = Search(board, init, goal);
  PrintBoard(solution);
}