#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

enum class State {kEmpty, kObstacle};

std::vector<State> parseLine(std::string line) {
    std::istringstream myStream(line);
    int n;
    char c;
    std::vector<State> thisRow;

    while (myStream >> n >> c && c == ',') {
        if (n == 0){
            thisRow.push_back(State::kEmpty);
        }
        else if (n == 1) {
            thisRow.push_back(State::kObstacle);
        }
    }
    return thisRow;
}

std::vector<std::vector<State>> readBoardFile(std::string path) {
    std::string line;
    std::vector<std::vector<State>> board;
    
    std::ifstream myFile;
    myFile.open(path);
    
    if (myFile) {
        std::vector<State> thisRow;
        while (std::getline(myFile, line)) {
            thisRow = parseLine(line);
            board.push_back(thisRow);
        }
    }
    return board;
}

std::string cellString(State cell) {
    switch(cell) {
        case State::kObstacle: return "*   ";
        default: return "0   "; 
    }
}

void displayVector(std::vector<std::vector<State>> vec){
    for (auto row : vec) {
        for (auto element : row) {
            std::cout << cellString(element) << " " ;
        }
        std::cout << "\n";
    }
}

int main() {
    std::string path = "../files/1.board";
    std::vector<std::vector<State>> myBoard;

    myBoard = readBoardFile(path);
    displayVector(myBoard);
}