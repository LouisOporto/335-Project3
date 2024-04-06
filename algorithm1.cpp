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

int main() {

  return 0;
}