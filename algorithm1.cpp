#include <iostream>
#include <vector>
using namespace std;

// Exhaustive Search
/*
soccer_exhaustive(G):
  len = 𝑟 + 𝑐 − 2
  counter = 0
  for bits from 0 to 2^𝑙𝑒𝑛 − 1 inclusive:
    candidate = empty list of moves
    for k from 0 𝑡𝑜 𝑙𝑒𝑛 − 1 inclusive:
      bit = (bits >> 𝑘) & 1
      if bit == 1:
        candidate.add(→)
      else:
        candidate.add(↓)
    if candidate stays inside the grid, never crosses an X cell, and ends at (𝑟 − 1, 𝑐 − 1):
      counter++
  return counter
 */

// Function prototypes
int soccer_exhaustive(vector<char>& grid, int rows, int cols);
bool verified(vector<char>& grid, int rows, int cols, int i, int j, vector<char>& path);

int main() {
    // Grid declaration and definition
    vector<vector<char>> grid = {
    {'.', '.', '.', '.', '.', '.', 'X', '.', 'X'},
    {'X', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', 'X', '.', '.', '.', 'X', '.'},
    {'.', '.', 'X', '.', '.', '.', '.', 'X', '.'},
    {'.', 'X', '.', '.', '.', '.', 'X', '.', '.'},
    {'.', '.', '.', '.', 'X', '.', '.', '.', '.'},
    {'.', '.', 'X', '.', '.', '.', '.', '.', 'X'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };

  int row = 8;
  int col = 9;

  int result = soccer_exhaustive(grid, row, col);
  cout << "There are " << result << " possible pathways to get to the goal" << '\n';
  return 0;
}


int soccer_exhaustive(vector<vector<char>> &grid, int row, int col)
{
    int n = row + col - 2;
    int counter = 0;

    // Create a path vector to track visited cells
    vector<char> path(row * col, '.');

    // Loop through all possible binary sequences (0 to 2^n - 1)
    for (int bits = 0; bits < (1 << n); ++bits)
    {
        // Build the path based on the binary sequence
        string candidatePath = "";
        for (int k = 0; k < n; ++k)
        {
            if ((bits >> k) & 1)
            {
                candidatePath.push_back('1'); // 1 represents right
            }
            else
            {
                candidatePath.push_back('0'); // 0 represents down
            }
        }

        // Check if the path is valid (within grid, avoids opponents, reaches goal)
<<<<<<< HEAD
        if (verified(grid, rows, cols, 0, 0, path))
        {
            counter++;
        }
    }

    return counter;
}


bool verified(vector<char>& grid, int rows, int cols, int i, int j, vector<char>& path)
{
  // Check if within grid boundaries
  if (i < 0 || i >= rows || j < 0 || j >= cols)
    {
        return false;
    }

    // Check if opponent cell or already visited
    if (grid[i * cols + j] == 'X' || path[i * cols + j] == 'V')
    {
        return false;
    }

    // Mark cell as visited
  path[i * cols + j] = 'V';

    // Check if reached goal
    if (i == rows - 1 && j == cols - 1) {
        return true;
  }

    // Recursively explore right and down paths
    bool rightValid = verified(grid, rows, cols, i, j + 1, path);
    bool downValid = verified(grid, rows, cols, i + 1, j, path);

    // Unmark cell after exploration
    path[i * cols + j] = '.';

    return rightValid || downValid;
}
