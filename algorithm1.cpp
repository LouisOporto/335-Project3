#include <iostream>

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

// Need to fix input matrix, not sure this is right !!
int soccor_exhaustive(vector<char>& grid, int rows, int cols);
bool verified(std::string candidiate);

int main() {

  // Sample Code for algorithm input (change later to be user inputted or what is required)
  int F[3][3] = {{0,0,0},
             {0,0,0},
             {0,0,0}};
  int row = 3;
  int col = 3;

  int result = soccer_exhaustive(F, row, col);
  std::cout << "There are " << result << " possible pathways to get to the goal" << '\n';
  return 0;
}

int soccor_exhaustive(vector<char>& grid, int rows, int cols)
{
    int n = rows + cols - 2;
    int counter = 0;

    // Create a path vector to track visited cells
    vector<char> path(rows * cols, '.');

    // Loop through all possible binary sequences (0 to 2^n - 1)
    for (int bits = 0; bits < (1 << n); ++bits)
    {
        // Build the path based on the binary sequence
        vector<char> candidatePath;
        for (int k = 0; k < n; ++k)
        {
            if ((bits >> k) & 1)
            {
                candidatePath.push_back('→');
            }
            else
            {
                candidatePath.push_back('↓');
            }
        }

        // Check if the path is valid (within grid, avoids opponents, reaches goal)
        if (isValidPath(grid, rows, cols, 0, 0, path))
        {
            counter++;
        }
    }

    return counter;
}
