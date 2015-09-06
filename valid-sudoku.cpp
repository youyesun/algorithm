/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated. 
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>rowcheck(9,vector<int>(9,0));
        vector<vector<int>>colcheck(9,vector<int>(9,0));
        vector<vector<int>>boxcheck(9,vector<int>(9,0));
        for(int i = 0; i < board.size(); i++){
            for(int j=0; j <board[0].size();j++){
                if(board[i][j] == '.')
                    continue;
                int box = i/3*3 + j/3;
                int num = board[i][j] - '1';
                if(rowcheck[i][num] || colcheck[j][num] || boxcheck[box][num])
                    return false;
                rowcheck[i][num]=1;
                colcheck[j][num]=1;
                boxcheck[box][num]=1;
            }
        }
        return true;
    }
};
