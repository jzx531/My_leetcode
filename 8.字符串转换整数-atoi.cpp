/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    bool isNumber(char c){
        return (c >= '0' && c <= '9');
    }
    int myAtoi(string s) {
        const int lstr = s.length();
        int index = 0;
        long result=0;
        int sign = 1;
        while((index<lstr)&&s.at(index) ==' '){
            index++;
        }
        if((index<lstr)&&(s.at(index) == '-'||s.at(index) == '+')){
            sign = (s.at(index) == '-')? -1 : 1;
            index++;
        }
        while((index<lstr)&&s.at(index) == '0'){
            index++;
        }
        while((index<lstr)&&isNumber(s.at(index))){
            result = result*10 + (s.at(index) - '0');
            index++;
            if(result*sign > INT_MAX){
                return INT_MAX;
            }
            if(result*sign < INT_MIN){
                return INT_MIN;
            }
        }
        return result*sign;
    }
};
// @lc code=end

