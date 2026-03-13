/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0 && !visited[i][j]) {
                    visited[i][j] = 1;
                    for (int k = 0; k < m; k++) {
                        if(matrix[k][j]!= 0){
                        visited[k][j] = 1;
                        matrix[k][j] = 0;
                        }
                    }
                    for (int k = 0; k < n; k++) {
                        if(matrix[i][k]!= 0){
                            matrix[i][k] = 0;
                            visited[i][k] = 1;
                        }
                    }
                }
            }
        }
    }
};
// @lc code=end

