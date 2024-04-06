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

int soccer_exhaustive(int F[], int row, int col);
bool verified(std::string candidiate);

int main() {

  // Sample Code for algorithm input (change later to be user inputted or what is required)
  int F[] = {1, 2, 3};
  int row = 3;
  int col = 1;

  int result = soccer_exhaustive(F, row, col);
  std::cout << "There are " << result << " possible pathways to get to the goal" << '\n';
  return 0;
}

int soccer_exhaustive(int F[], int row, int col) {
  int maxIteration = row + col - 2; // Total number of different paths orginating at (0,0) and ending at (r-1,c-1)
  int counter = 0; // Number of valid paths in F

  for(int i = 0; i < 2^maxIteration - 1; i++) {
    std::string candidate;
    for(int j = 0; j < maxIteration - 1; j++) {
      //TODO - need to adjust bit to check current location or return 1
      /* bit = (bits >> k) & 1; */
      int bit = 0;
      if (bit == 1) {
        candidate.push_back('1'); // 1 for right
      }
      else {
        candidate.push_back('0'); // 0 for down
      }
    }
    if (verified(candidate)) {
      counter++;
    }
  }

  return counter;
}

bool verified(std::string candidate) {
  //TODO check if candidate stays in the grid, never cross an X cell, and ends at (r - 1)(c - 1)
  return true; // If all conditions apply
}