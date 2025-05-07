/*
    Problem Statement:
        You are given a 9×9 Sudoku board. Write a C++ function to check whether it is valid according to Sudoku rules.
        A valid Sudoku board (partially filled) must satisfy the following:
            1. Each row must contain the digits '1' to '9' without repetition.
            2. Each column must contain the digits '1' to '9' without repetition.
            3. Each of the 9 3×3 sub-boxes of the grid must contain the digits '1' to '9' without repetition.

        Note:
            1. The board may be partially filled, where empty cells are denoted by the character '.'.
            2. You only need to validate the current state of the board. You do not need to solve it.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isValidSudoku(const vector<vector<char>> &board){
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> cols(9);
    vector<unordered_set<char>> grid(9);
    char current_char;

    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            current_char = board[i][j];
            if (board[i][j] != '.'){

                if(rows[i].count(current_char) || cols[j].count(current_char) || grid[(i/3) * 3 + (j/3)].count(current_char)){
                    return false;
                }
                rows[i].insert(current_char);
                cols[j].insert(current_char);
                grid[(i/3) * 3 + (j/3)].insert(current_char);
            }
        }
    }

    return true;
}

int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << (isValidSudoku(board) ? "Valid" : "Invalid") << endl;

    board = {
        {'5','3','.','.','7','.','.','3','.'}, // '3' is repeated in the row
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << (isValidSudoku(board) ? "Valid" : "Invalid") << endl;

    return 0;
}