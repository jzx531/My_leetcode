/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */

// @lc code=start
class Solution {
public:
vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    vector<int> res;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        // 找到当前行的最小值及其列索引
        auto min_it = min_element(matrix[i].begin(), matrix[i].end());
        int min_num = *min_it;
        int col = distance(matrix[i].begin(), min_it);
        
        // 检查该列的所有行是否都 ≤ min_num
        bool is_lucky = true;
        for (int j = 0; j < m; j++) {
            if (matrix[j][col] > min_num) {
                is_lucky = false;
                break;
            }
        }
        
        if (is_lucky) {
            res.push_back(min_num);
        }
    }
    return res;
}
};
// @lc code=end

