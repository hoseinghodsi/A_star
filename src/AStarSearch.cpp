#include "boardParser.h"
#include <iostream>
#include <vector>
#include <algorithm>

const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

enum class State {kEmpty, kObstacle, kClosed, kPath, kStart, kFinish};

bool Compare(const std::vector<int> a, const std::vector<int> b) {
  int f1 = a[2] + a[3]; // f1 = g1 + h1
  int f2 = b[2] + b[3]; // f2 = g2 + h2
  return f1 > f2; 
}

/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(std::vector<std::vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}


// Calculate the manhattan distance
int Heuristic(int x1, int y1, int x2, int y2) {
  return std::abs(x2 - x1) + std::abs(y2 - y1);
}


/** 
 * Check that a cell is valid: on the grid, not an obstacle, and clear. 
 */
bool CheckValidCell(int x, int y, std::vector<std::vector<State>> &grid) {
  bool on_grid_x = (x >= 0 && x < grid.size());
  bool on_grid_y = (y >= 0 && y < grid[0].size());
  if (on_grid_x && on_grid_y)
    return grid[x][y] == State::kEmpty;
  return false;
}


/** 
 * Add a node to the open list and mark it as open. 
 */
void AddToOpen(int x, int y, int g, int h, std::vector<std::vector<int>> &openlist, std::vector<std::vector<State>> &grid) {
  //std::cout << x << "  ";
  //std::cout << y << "  ";
  //std::cout << g << "  ";
  //std::cout << h << "  ";
  //std::cout << "\n";
  openlist.push_back(std::vector<int>{x, y, g, h});
  grid[x][y] = State::kClosed;
}


/** 
 * Expand current nodes's neighbors and add them to the open list.
 */
void ExpandNeighbors(const std::vector<int> &current, int goal[2], std::vector<std::vector<int>> &openlist, std::vector<std::vector<State>> &grid) {
  // Get current node's data.
  int x = current[0];
  int y = current[1];
  int g = current[2];

  // Loop through current node's potential neighbors.
  for (int i = 0; i < 4; i++) {
    int x2 = x + delta[i][0];
    int y2 = y + delta[i][1];

    // Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
    if (CheckValidCell(x2, y2, grid)) {
      // Increment g value and add neighbor to open list.
      int g2 = g + 1;
      int h2 = Heuristic(x2, y2, goal[0], goal[1]);
      AddToOpen(x2, y2, g2, h2, openlist, grid);
    }
  }
}


/** 
 * Implementation of A* search algorithm
 */
std::vector<std::vector<State>> Search(std::vector<std::vector<State>> grid, int init[2], int goal[2]) {
  std::vector<std::vector<int>> open {};
  
  // Initialize the starting node.
  int x = init[0];
  int y = init[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0],goal[1]);
  AddToOpen(x, y, g, h, open, grid);

  while (open.size() > 0) {
    CellSort(&open);
    std::cout << "************" << "\n";
    for (auto i : open) {
        for (auto e : i) {
            std::cout << e << " ";
        }
        std::cout << "\n";
    }
    auto current = open.back();
    open.pop_back();
    std::cout << "-@-@-@-@-@-@-@-@-@-@" << "\n";
    for (auto i : open) {
        for (auto e : i) {
            std::cout << e << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << "***** CURRENT ****" << "\n";    
    x = current[0];
    y = current[1];
    std::cout << x << " " << y << "\n\n";
    grid[x][y] = State::kPath;

    // Check if we're done.
    if (x == goal[0] && y == goal[1]) {
      grid[init[0]][init[1]] = State::kStart;
      grid[goal[0]][goal[1]] = State::kFinish;
      return grid;
    }
    
    // If we're not done, expand search to current node's neighbors.
    ExpandNeighbors(current, goal, open, grid);
  }
  
  // We've run out of new nodes to explore and haven't found a path.
  std::cout << "No path found!" << "\n";
  return std::vector<std::vector<State>>{};
}