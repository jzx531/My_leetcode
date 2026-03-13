/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long result=0;
        if (dividend==0) return 0;
        if(divisor == dividend) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor==INT_MIN) return 0;
        long dd = dividend;
        long dr = divisor;
        int sign = (dividend > 0) ^ (divisor > 0);
        if(dividend<0) dd = -dd;
        if(divisor<0) dr = -dr;
        while(dd>=dr){
            long temp = dr;
            long addr = 1;
            while((temp<<1) < dd){
                temp <<= 1;
                addr <<= 1;
            }
            dd -= temp;
            result += addr;
        }
        return sign? -result : result;
    }

};
// @lc code=end

