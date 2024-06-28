/*
 * Name: Jake Eklund
 * Date Submitted: November 13, 2023
 * Lab Section: 001
 * Assignment Name: Lab 9: Using Recursion to Solve the N-Queens Problem
 */

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<int> &board, int row, int col, int n) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col) {
            return false;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i] == j) {
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i] == j) {
            return false;
        }
    }
    return true;
}

int placeQueens(vector<int> &board, int row, int n) {
    if (row == n) {
        return 1;
    }

    int moves = 0;
    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row] = col;
            moves += placeQueens(board, row + 1, n);
        }
    }
    return moves;
}

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions
    vector<int> board(n, -1);
    return placeQueens(board, 0, n);
}

/*
int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}
*/