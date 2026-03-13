/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 统计各位数字都不同的数字个数
 */

// @lc code=start
class Solution {
public:
        // 计算阶乘
    unsigned long long factorial(int n) {
        if (n == 0 || n == 1) return 1;
        return n * factorial(n - 1);
    }

    // 直接计算组合数
    unsigned long long combination(int n, int k) {
        if (k < 0 || k > n) return 0;
        return factorial(n) / (factorial(k) * factorial(n - k));
    }

    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;  
        if(n==1) return 10;
        int pre = 1;
        for(int i = 0;i<n-1;i++)
        {
            pre*=combination(9-i,1);
        }
        int res=pre*(n-1+combination(9-n+1,1));
        res =res + countNumbersWithUniqueDigits(n-1);
        return res;
    }
};
// @lc code=end

