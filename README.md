# Project 3
Assignment - Project 3

[Github Link](https://github.com/LouisOporto/335-Project3) 


## Members
Member 1
> Name -Louis Oporto
>
> Email - louisoporto042@csu.fullerton.edu
>

Member 2
> Name -Florentino Becerra
>
> Email - becerra_f@csu.fullerton.edu
>

Member 3
> Name - Haron Taher
>
> Email - htaher1@csu.fullerton.edu
>

Member 4
> Name - John Michael Lott
>
> Email - jlott1004@csu.fullerton.edu
>


# Run Code
## Algorithm 1
Compile g++ -std=c++20 -o alogrithm1 algorithm1.cpp
Run ./algorithm1

## Algorithm 2
Compile g++ -std=c++20 -o algorithm2 algorithm2.cpp
Run ./algorithm2


# Pseudocode
## Algorithm 1 Pseudocode: Exhaustive Search

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

## Algorithm 2 Pseudocode: Dynamic Programming

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
