/*
 * @lc app=leetcode.cn id=1275 lang=cpp
 *
 * [1275] 找出井字棋的获胜者
 */

// @lc code=start
class Solution {
    public:
        string tictactoe(vector<vector<int>>& moves) {
            vector<vector<char>> board(3, vector<char>(3, ' '));
            
            for (int i = 0; i < moves.size(); ++i) {
                int row = moves[i][0];
                int col = moves[i][1];
                if (i % 2 == 0) {
                    board[row][col] = 'X'; // Player A
                } else {
                    board[row][col] = 'O'; // Player B
                }
                
                // Check if current player wins
                if (checkWin(board, row, col)) {
                    return (i % 2 == 0) ? "A" : "B";
                }
            }
            
            // Check if the game is pending or draw
            return (moves.size() == 9) ? "Draw" : "Pending";
        }
        
    private:
        bool checkWin(const vector<vector<char>>& board, int row, int col) {
            char player = board[row][col];
            
            // Check row
            if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
                return true;
            }
            
            // Check column
            if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
                return true;
            }
            
            // Check diagonal
            if (row == col && board[0][0] == player && board[1][1] == player && board[2][2] == player) {
                return true;
            }
            
            // Check anti-diagonal
            if (row + col == 2 && board[0][2] == player && board[1][1] == player && board[2][0] == player) {
                return true;
            }
            
            return false;
        }
    };
// @lc code=end

