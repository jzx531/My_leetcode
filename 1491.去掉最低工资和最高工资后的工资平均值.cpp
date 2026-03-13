/*
 * @lc app=leetcode.cn id=1491 lang=cpp
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
 */

// @lc code=start
class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        int sum = 0;
        for (int i = 1; i < salary.size() - 1; i++) {
            sum += salary[i];
        }
        return (double)sum / (salary.size() - 2);
    }
};
// @lc code=end

