/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> digits;
        int product = 1;
        int sum = 0;
        while (n > 0) {
            digits.push_back(n % 10);
            product *= n % 10;
            sum += n % 10;
            n /= 10;
        }
        return product - sum;
    }
};
// @lc code=end

