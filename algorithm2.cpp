// Louis Oporto, Florentino Becerra, Haron Taher, John Michael Lott
// CPSC 335-04, Spring 2024
// Project 3
// Algorithm 2: Dynamic Programming

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Function prototype for the dynamic programming solution.
int soccer_dyn_prog(const vector<vector<char>> &F);

int main()
{
  vector<vector<char>> grid; // Grid to represent the soccer field.
  int choice = 0;            // User choice for grid size.
  bool valid = false;        // Validity check for user input.

  // Loop until a valid grid choice is made.
  while (!valid)
  {
    // Prompt user for grid size.
    cout << "\n1.2x2\n"
            "2.4x4\n"
            "3.8x8\n"
            "4.12x12\n"
            "5.16x16\n"
            "Which size grid would you like to test? ";

    cin >> choice; // Get user input.

    // Create grid based on user choice.
    switch (choice)
    {
    case 1:
      grid = {
          {'.', '.'},
          {'X', '.'}};
      valid = true;
      break;

    case 2:
      grid = {
          {'.', '.', 'X', '.'},
          {'X', '.', '.', 'X'},
          {'.', 'X', '.', '.'},
          {'.', '.', '.', '.'}};
      valid = true;
      break;

    case 3:
      grid = {
          {'.', '.', '.', '.', '.', '.', 'X', '.'},
          {'X', '.', '.', '.', '.', '.', '.', '.'},
          {'.', '.', '.', 'X', '.', '.', '.', 'X'},
          {'.', '.', 'X', '.', '.', '.', '.', 'X'},
          {'.', 'X', '.', '.', '.', '.', 'X', '.'},
          {'.', '.', 'X', '.', '.', '.', '.', '.'},
          {'.', '.', '.', '.', 'X', '.', '.', '.'},
          {'.', '.', '.', '.', '.', '.', '.', '.'}};
      valid = true;
      break;

    case 4:
      grid = {
          {'.', '.', '.', '.', '.', '.', 'X', '.', '.', '.', 'X', '.'},
          {'X', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'.', '.', '.', 'X', '.', '.', '.', 'X', '.', '.', 'X', '.'},
          {'.', '.', 'X', '.', '.', '.', '.', 'X', '.', '.', '.', '.'},
          {'.', 'X', '.', '.', '.', '.', 'X', '.', '.', '.', 'X', '.'},
          {'.', '.', 'X', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'.', '.', '.', '.', 'X', '.', '.', 'X', '.', '.', '.', '.'},
          {'.', '.', '.', '.', '.', '.', '.', '.', '.', 'X', '.', '.'},
          {'.', 'X', '.', '.', '.', 'X', '.', '.', '.', '.', '.', '.'},
          {'.', 'X', 'X', 'X', '.', '.', '.', 'X', '.', '.', 'X', '.'},
          {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'X', '.', '.', 'X', '.', '.', '.', '.', 'X', '.', '.', '.'},
      };
      valid = true;
      break;

    case 5:
      grid = {
          {'.', '.', '.', '.', '.', '.', 'X', '.', '.', '.', 'X', '.', '.', 'X', '.', 'X'},
          {'X', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'.', '.', '.', 'X', '.', '.', '.', 'X', '.', '.', 'X', '.', '.', '.', '.', '.'},
          {'.', '.', 'X', '.', '.', '.', '.', 'X', '.', '.', '.', '.', '.', 'X', '.', '.'},
          {'.', 'X', '.', '.', '.', '.', 'X', '.', '.', '.', 'X', '.', '.', '.', '.', '.'},
          {'.', '.', 'X', '.', '.', '.', '.', '.', '.', '.', '.', 'X', '.', '.', 'X', '.'},
          {'.', '.', '.', '.', 'X', '.', '.', 'X', '.', '.', '.', '.', 'X', '.', '.', '.'},
          {'.', '.', '.', '.', '.', '.', '.', '.', '.', 'X', '.', '.', '.', '.', '.', '.'},
          {'.', 'X', '.', '.', '.', 'X', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'.', 'X', 'X', 'X', '.', '.', '.', 'X', '.', '.', 'X', 'X', 'X', '.', '.', '.'},
          {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'X', '.', '.'},
          {'X', '.', '.', 'X', '.', 'X', '.', '.', 'X', '.', '.', '.', '.', '.', '.', '.'},
          {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'.', '.', '.', 'X', 'X', '.', '.', '.', '.', '.', '.', '.', 'X', '.', '.', '.'},
          {'.', '.', '.', '.', '.', '.', '.', 'X', '.', '.', 'X', '.', '.', '.', '.', '.'},
          {'.', 'X', '.', '.', '.', 'X', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
      valid = true;
      break;

    default:
      cout << "Not a valid option.\n";
      break;
    }

    if (valid)
    {
      char restart;                                   // User choice to restart or not.
      auto start = chrono::steady_clock::now();       // Start timer.
      int result = soccer_dyn_prog(grid);             // Compute number of pathways.
      auto end = chrono::steady_clock::now();         // End timer.
      chrono::duration<double> elapsed = end - start; // Calculate elapsed time.

      // Display results.
      cout << "There are " << result << " possible pathways to get to the goal" << '\n';
      cout << "It took " << chrono::duration_cast<chrono::seconds>(elapsed).count() << " seconds." << '\n';
      cout << "Would you like to try another grid? (y/n) ";
      cin >> restart;

      // Validate user choice to restart or exit.
      while (restart != 'y' && restart != 'Y' && restart != 'n' && restart != 'N')
      {
        cout << "Invalid input\n";
        cout << "Would you like to try another grid? (y/n) ";
        cin >> restart;
      }
      if (restart == 'y' || restart == 'Y')
      {
        valid = false; // Reset valid to false to continue the loop.
      }
    }
  }

  return 0;
}

int soccer_dyn_prog(const vector<vector<char>> &F)
{
  int r = F.size();                            // Number of rows.
  int c = F[0].size();                         // Number of columns.
  vector<vector<int>> A(r, vector<int>(c, 0)); // DP table.

  if (F[0][0] == 'X') // Initial cell is blocked.
  {
    return 0;
  }

  A[0][0] = 1; // Start at the top-left corner.

  // Populate the DP table.
  for (int i = 0; i < r; ++i)
  {
    for (int j = 0; j < c; ++j)
    {
      if (F[i][j] == 'X') // If the cell is blocked, skip it.
      {
        A[i][j] = 0;
        continue;
      }

      if (i > 0 && F[i - 1][j] != 'X') // Move down.
      {
        A[i][j] += A[i - 1][j];
      }

      if (j > 0 && F[i][j - 1] != 'X') // Move right.
      {
        A[i][j] += A[i][j - 1];
      }
    }
  }

  return A[r - 1][c - 1]; // Return the value in the bottom-right corner.
}