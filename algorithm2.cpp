// Louis Oporto, Florentino Becerra, Haron Taher, John Michael Lott
// CPSC 335-04, Spring 2024
// Project 3
// Algorithm 2: Dynamic Programming

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int soccer_dyn_prog(const vector<vector<char>> &F);

int main()
{
  vector<vector<char>> F_example = {
    {'.', '.', '.', '.', '.', '.', 'X', '.', 'X'},
    {'X', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', 'X', '.', '.', '.', 'X', '.'},
    {'.', '.', 'X', '.', '.', '.', '.', 'X', '.'},
    {'.', 'X', '.', '.', '.', '.', 'X', '.', '.'},
    {'.', '.', '.', '.', 'X', '.', '.', '.', '.'},
    {'.', '.', 'X', '.', '.', '.', '.', '.', 'X'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };

  auto start = chrono::steady_clock::now();
  int result = soccer_dyn_prog(F_example);
  auto end = chrono::steady_clock::now();
  const chrono::duration<double> elapsed{end - start};

  cout << "There are " << result << " possible pathways to get to the goal" << '\n';
    cout << "It took " << chrono::duration_cast<chrono::seconds>(elapsed).count() << " seconds." << '\n';

  return 0;
}

int soccer_dyn_prog(const vector<vector<char>> &F)
{
  int r = F.size();
  int c = F[0].size();
  vector<vector<int>> A(r, vector<int>(c, 0));

  // Corner case: initial cell is impassable
  if (F[0][0] == 'X')
  {
    return 0;
  }

  // Base case
  A[0][0] = 1;

  // General cases
  for (int i = 0; i < r; ++i)
  {
    for (int j = 0; j < c; ++j)
    {
      if (F[i][j] == 'X')
      {
        A[i][j] = 0;
        continue;
      }

      if (i > 0 && F[i - 1][j] != 'X')
      {
        A[i][j] += A[i - 1][j];
      }

      if (j > 0 && F[i][j - 1] != 'X')
      {
        A[i][j] += A[i][j - 1];
      }
    }
  }

  return A[r - 1][c - 1];
}