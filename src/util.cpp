#include "boardParser.h"
#include <iostream>
#include <vector>

enum class State {kEmpty, kObstacle, kClosed, kPath, kStart, kFinish};

std::string CellString(State cell) {
  char myChar;
  std::string output;
  switch(cell) {
    case State::kObstacle: {
        myChar = 35;
        output = {myChar};
        return output;
    }
    case State::kPath: {
        myChar = 43;
        output = {myChar};
        return output;       
    }
    case State::kStart: {
        myChar = 157;
        output = {myChar};
        return output;  
    }
    case State::kFinish: {
        myChar = 64;
        output = {myChar};
        return output;         
    }
    case State::kClosed: {
        myChar = 36;
        output = {myChar};
        return output;         
    }
    default: {
        myChar = 46;
        output = {myChar};
        return output;           
    } 
  }
}

void PrintBoard(const std::vector<std::vector<State>> board) {
  std::cout << "\n\n";
  for (int i = 0; i < board.size(); i++) {
    std::cout << "\t\t\t";
    for (int j = 0; j < board[i].size(); j++) { 
      std::cout << CellString(board[i][j]) << "   ";
    }
    std::cout << "\n";
  }
  std::cout << "\n\n";
}