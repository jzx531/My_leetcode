/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        int tmp = 0;
        if(num == 0) return "0";
        string res = "";
        int sign = num>=0?1:-1;
        num = sign*num;
        while(num>0){
            tmp = num%7;
            num = num/7;
            res = to_string(tmp) + res;
        }
        if(sign == -1) res = "-" + res;
        return res;
    }
};
// @lc code=end

