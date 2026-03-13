/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start
class Solution {
public:
    
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int countBit(int n)
    {
        int count = 0;
        while(n > 0){
            if(n & 1) count++;
            n >>= 1;
        }
        return count;
    }
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(int i = left; i <= right; i++)
        {
            if(isPrime(countBit(i))) ++res;
        }
        return res;
    }
};
// @lc code=end

