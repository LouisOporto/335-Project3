// Louis Oporto, Florentino Becerra, Haron Taher, John Michael Lott
// CPSC 335-04, Spring 2024
// Project 3
// Algorithm 1: Exhaustive Search

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Function prototypes
int soccer_exhaustive(vector<vector<char>> &grid, int rows, int cols);
bool isValidPath(string candidatePath, vector<vector<char>> &grid, int row, int col);

int main()
{
    // Grid declaration and definition
    vector<vector<char>> grid;
    int choice = 0;
    bool vaild = false;
    while (!vaild)
    {

        cout << "\n1.2x2\n"
                "2.4x4\n"
                "3.8x8\n"
                "4.12x12\n"
                "5.16x16\n"
                "Which size grid would you like to test? ";

        cin >> choice;
        switch (choice)
        {
        case 1:
            grid = {
                {'.', '.'},
                {'X', '.'}};
            vaild = true;
            break;

        case 2:
            grid = {
                {'.', '.', 'X', '.'},
                {'X', '.', '.', 'X'},
                {'.', 'X', '.', '.'},
                {'.', '.', '.', '.'}};
            vaild = true;
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
            vaild = true;
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
            vaild = true;
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
            vaild = true;
            break;

        default:
            cout << "Not a vaild option.\n";
            break;
        }

        if (vaild)
        {
            int row = grid.size();
            int col = grid[0].size();

            char restart;
            clock_t t;
            auto start = chrono::steady_clock::now();
            int result = soccer_exhaustive(grid, row, col);
            auto end = chrono::steady_clock::now();
            const chrono::duration<double> elapsed{end - start};

            cout << "There are " << result << " possible pathways to get to the goal" << '\n';
            cout << "It took " << chrono::duration_cast<chrono::seconds>(elapsed).count() << " seconds." << '\n';
            cout << "Would you like to try another grid? (y/n) ";
            cin >> restart;

            while (restart != 'y' && restart != 'Y' && restart != 'n' && restart != 'N')
            {
                cout << "Invalid input\n";
                cout << "Would you like to try another grid? (y/n) ";
                cin >> restart;
            }
            if (restart == 'y' || restart == 'Y')
            {
                vaild = false;
            }
        }
    }
    return 0;
}

int soccer_exhaustive(vector<vector<char>> &grid, int row, int col)
{
    int n = row + col - 2;
    int counter = 0;
    // Loop through all possible binary sequences (0 to 2^n - 1)
    for (int bits = 0; bits < (1 << n); bits++)
    {
        // cout << bits << '\n';
        // cout << bits << '\n';
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
        // cout << candidatePath << '\n';
        // cout << candidatePath << '\n';
        // Check if the path is valid (within grid, avoids opponents, reaches goal)
        if (isValidPath(candidatePath, grid, row, col))
        {
            // Read candidatePath incrementally ie(1 char, 2 char, 3 char, ... ,n chars)
            // Based on the number of 1s and 0s check that indexed location on the grid. If there is an X return false
            // If run through entire grid without X then return True
            counter++;
        }
    }
    return counter;
}

bool isValidPath(string candidatePath, vector<vector<char>> &grid, int row, int col)
{
    int n = candidatePath.length();
    int zeros = 0;
    int ones = 0;

    // TODO add a base case if grid[0][0] == X and maybe if grid[r - 1][c - 1] == X

    // Go through the pathway given by the binary string ie(0001 = down, down, down, right)
    for (int i = 0; i < n; i++)
    {
        // Increment to the next step of the grid (add a right or down)
        if (candidatePath[i] == '1')
            ones++;
        else
            zeros++;

        // Check if row is out of bounds
        if (zeros > grid.size() - 1)
            return false;

        // Check if col is out of bounds
        if (ones > grid[zeros].size() - 1)
            return false;

        // Check if an X is in bounds
        if (grid[zeros][ones] == 'X')
            return false;
    }
    return true;
}