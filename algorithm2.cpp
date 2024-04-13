#include <iostream>
#include <string>
#include <chrono>
using namespace std;

/* Names:
    Louis Oporto
    Florentino Becerra
    Haron Taher
    John Michael Lott
*/

//Dynamic Programming Psuedocode
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

const int LEN = 8;
const int WID = 9;

int soccer_dyn_prop(string[]);

int main() {
  
  int result;
  string field[] = {"......X.X","X........",
  "...X...X.","..X....X.",
  ".X....X..","....X....",
  "..X.....X","........."};

  clock_t t;
  auto start = chrono::steady_clock::now();
  result = soccer_dyn_prop(field);
  auto end = chrono::steady_clock::now();
  const chrono::duration<double> elapsed{end - start};

  cout << "There are " << result << " possible pathways to get to the goal." << '\n';
  cout << "It took " << elapsed.count() << "." << '\n';

  return 0;
}

int soccer_dyn_prop(string field[]){
  int result[LEN][WID];
  int above, left;
  if(field[0][0] == 'X')
    return 0;
  for(int i = 0; i < LEN;i++){
    for(int j = 0; j < WID; j++)
      result[i][j] = 0;
  }
  result[0][0] = 1;
  for(int i = 0; i < LEN; i++){
    for(int j = 0; j < WID;j++){
      if(field[i][j] == 'X'){
        result[i][j] = 0;
        continue;
      }
      above = left = 0;
      if(i > 0 && field[i-1][j] == '.')
        above = result[i-1][j];
      if(j > 0 && field[i][j-1] == '.')
        left = result[i][j-1];
      result[i][j] += (above + left);
    }
  }
  return result[LEN - 1][WID - 1];
}