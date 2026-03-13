/*
 * @lc app=leetcode.cn id=1486 lang=cpp
 *
 * [1486] 数组异或操作
 */

// @lc code=start
class Solution {
public:
    int xorOperation(int n, int start) {
        if(n == 0) return 0;
        else {
            return (start + 2 * (n - 1))^xorOperation(n-1, start);
        }
    }
};
// @lc code=end

