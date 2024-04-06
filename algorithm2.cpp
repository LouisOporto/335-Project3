#include <iostream>

using namespace std;

//Dynamic Programming
/* 
soccer_dyn_prop(F):
  //corner case: inital cell is impassible
  if F[0][0] == X:
    return 0
  A = new rXc matrix intialized to zeros
  //base case
  A[0][0] = 1
  //general cases
  for i from 0 to r - 1 inclusive:
    for j from 0 to c - 1 inlcude:
      if F[i][j] == X:
        A[i][j] = 0
        continue
      above = from_left = 0
      if i > 0 and F[i - 1][j] == .:
        above = A[i - 1][j]
      if j > 0 and F[i][j - 1] == .:
        left = A[i][j - 1]
      A[i][j] += above + left
  return A[r - 1][c - 1]
*/

int* soccer_dyn_prop(char[][10]){
  static int result[LEN][WID];

};

const int LEN = 8;
const int WID = 9;

int main() {
  
  char field[][10] = {"......X.X","X........",
  "...X...X.","..X....X.",
  ".X....X..","....X....",
  "..X.....X","........."};

  int* result = soccer_dyn_prop(field);

  

  return 0;
}