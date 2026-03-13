/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> copy(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                copy[i][j] = board[i][j];
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int count = 0;
                for(int ii = max(i-1,0); ii <= min(i+1,m-1); ii++)
                {
                    for(int jj = max(j-1,0); jj <= min(j+1,n-1); jj++)
                    {
                        if(ii==i && jj==j) continue;
                        if(copy[ii][jj] & 1) count++;
                    }
                }
                if(copy[i][j] & 1){
                    if(count < 2 || count > 3) board[i][j] &= ~1;
                }
                else{
                    if(count == 3) board[i][j] |= 1;
                }
            }
        }
    }
};
// @lc code=end

