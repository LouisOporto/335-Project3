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
    // Grid declaration and initialization
    vector<vector<char>> grid;
    int choice = 0;
    bool valid = false;

    while (!valid)
    {
        // Display grid size options
        cout << "\n1.2x2\n"
                "2.4x4\n"
                "3.8x8\n"
                "4.12x12\n"
                "5.16x16\n"
                "Which size grid would you like to test? ";

        // Get user's choice
        cin >> choice;

        // Assign the corresponding grid based on the user's choice
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
            // Handle invalid option
            cout << "Not a valid option.\n";
            break;
        }

        // If a valid grid is selected
        if (valid)
        {
            int row = grid.size();
            int col = grid[0].size();

            char restart;
            auto start = chrono::steady_clock::now();
            int result = soccer_exhaustive(grid, row, col); // Assume soccer_exhaustive is a defined function
            auto end = chrono::steady_clock::now();
            const chrono::duration<double> elapsed{end - start};

            // Output the result and time taken
            cout << "There are " << result << " possible pathways to get to the goal" << '\n';
            cout << "It took " << chrono::duration_cast<chrono::seconds>(elapsed).count() << " seconds." << '\n';
            cout << "Would you like to try another grid? (y/n) ";
            cin >> restart;

            // Handle invalid input for restart
            while (restart != 'y' && restart != 'Y' && restart != 'n' && restart != 'N')
            {
                cout << "Invalid input\n";
                cout << "Would you like to try another grid? (y/n) ";
                cin >> restart;
            }
            if (restart == 'y' || restart == 'Y')
            {
                valid = false; // Continue to allow another grid selection
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