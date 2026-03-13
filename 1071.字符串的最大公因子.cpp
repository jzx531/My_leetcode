/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
 */

// @lc code=start
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string divisor = str1.size() < str2.size()? str1 : str2;
        string dividend = str1.size() < str2.size()? str2 : str1;
        string res;
        bool flag;
        for(int i = divisor.size();i>0;--i){
            res = divisor.substr(0,i);
            flag = true;
            for(int j = 0;j< dividend.size();j+=i){
                if(dividend.substr(j,i)!= res){
                    flag = false;
                    break;
                }
            }
            for(int j = 0;j< divisor.size();j+=i)
            {
                if(divisor.substr(j,i)!= res){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return res;
            }
        }
        return "";
    }
};
// @lc code=end

