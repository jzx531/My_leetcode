/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public: 
    void dfs(vector<vector<char>>& board, int i, int j, string& word, int index, vector<vector<bool>>& visited,bool &found) {
        if (index == word.size()) {
            found = true;
            return;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j]!= word[index]) {
            return;
        }
        visited[i][j] = true;
        dfs(board, i + 1, j, word, index + 1, visited, found);
        dfs(board, i - 1, j, word, index + 1, visited, found);
        dfs(board, i, j + 1, word, index + 1, visited, found);
        dfs(board, i, j - 1, word, index + 1, visited, found);
        visited[i][j] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    dfs(board, i, j, word, 0, visited, found);
                    if (found) {
                        return true;
                    }
                }
            }
        }
        return false;   
    }
};
// @lc code=end

