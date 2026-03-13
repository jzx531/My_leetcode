/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<n-1;i++){
            int base = matrix[0][i];
            for (int j=1;j<m;j++)
            {
                if(i+j>=n){
                    break;
                }
                if(matrix[j][i+j]!=base){
                    return false;
                } 
            }
        }
        for (int i = 1; i < m; i++)
        {
            int base = matrix[i][0];
            for (int j = 1; j < n; j++)
            {
                if(i+j>=m){
                    break;
                }
                if(matrix[i+j][j]!=base){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

