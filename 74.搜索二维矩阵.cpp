/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] <= target && matrix[i][n-1] >= target) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == target) {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;

    }
};
// @lc code=end

