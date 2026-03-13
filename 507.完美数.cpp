/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

// @lc code=start
class Solution {
    public:
        bool checkPerfectNumber(int num) {
            if (num == 1) return false; // 1 不是完美数
            vector<int> factors;
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    factors.push_back(i);
                    if (i != num / i && i>1) { // 避免重复和排除num本身
                        factors.push_back(num / i);
                    }
                }
            }
            int sum = accumulate(factors.begin(), factors.end(), 0);
            return sum == num;
        }
};
// @lc code=end

