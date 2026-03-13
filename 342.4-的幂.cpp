/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0)&&(!(n&(n-1)));
    }
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n < 4) return false;
        if(n == 4) return true;
        if(n%4!= 0) return false;
        else return isPowerOfFour(n/4);
    }
};
// @lc code=end

