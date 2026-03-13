/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        else {
            int temp = x;
            long rev = 0;
            while(temp != 0) {
                rev = rev * 10 + temp % 10;
                temp /= 10;
            }
            return x == (int)rev;
        }
    }
};
// @lc code=end

