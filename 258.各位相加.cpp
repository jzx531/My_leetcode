/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        int res = num;
        while (res >= 10) {
            int sum = 0;
            while (res) {
                sum += res % 10;
                res /= 10;
            }
            res = sum;
        }
        return res;
    }
};
// @lc code=end

