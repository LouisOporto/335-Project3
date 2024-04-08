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
bool isValidPath(string candidatePath, vector<vector<char>> &grid, int row, int col);

int main() {
    // Grid declaration and definition
    /*
    vector<vector<char>> grid = {
    {'.', '.', '.'},
    {'X', '.', '.'},
    {'.', '.', '.'}
    };
    */

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


  int row = grid.size();
  int col = grid[0].size();

  int result = soccer_exhaustive(grid, row, col);
  cout << "There are " << result << " possible pathways to get to the goal" << '\n';
  return 0;
}


int soccer_exhaustive(vector<vector<char>> &grid, int row, int col)
{
    int n = row + col - 2;
    int counter = 0;

    // Loop through all possible binary sequences (0 to 2^n - 1)
    for (int bits = 0; bits < (1 << n); bits++)
    {
        // Build the path based on the binary sequence
        string candidatePath = "";
        for (int k = 0; k < n; k++)
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
        if (isValidPath(grid, rows, cols, 0, 0, path))
        {
            // Read candidatePath incrementally ie(1 char, 2 char, 3 char, ... ,n chars)
            // Based on the number of 1s and 0s check that indexed location on the grid. If there is an X return false
            // If run through entire grid without X then return True
            counter++;
        }
    }
    return counter;
}

bool isValidPath(string candidatePath, vector<vector<char>> &grid, int row, int col) {
    int n = candidatePath.length();
    int zeros = 0;
    int ones = 0;

    // TODO add a base case if grid[0][0] == X and maybe if grid[r - 1][c - 1] == X

    //Go through the pathway given by the binary string ie(0001 = down, down, down, right)
    for (int i = 0; i < n; i++) {
        // Increment to the next step of the grid (add a right or down)
        if (candidatePath[i] == '1') ones++;
        else zeros++;

        // Check if row is out of bounds
        if(zeros > grid.size() - 1) return false;

        // Check if col is out of bounds
        if(ones > grid[zeros].size() - 1) return false;

        // Check if an X is in bounds
        if(grid[zeros][ones] == 'X') return false;
    }
    return true;
}
