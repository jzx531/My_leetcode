/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    enum RomanNumerals {
        I = 1,
        V = 5,
        X = 10,
        L = 50,
        C = 100,
        D = 500,
        M = 1000
    };
    int romanToInt(string s) {
        static const unordered_map<char, RomanNumerals> romanMap = {
            {'I', I}, {'V', V}, {'X', X}, {'L', L},
            {'C', C}, {'D', D}, {'M', M}
        };
        int result = 0;
        const int n = s.length();
        int prev = 0;
        int curr = 0;
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            ++flag;
            if(flag==2){
                curr = romanMap.at(s[i]);
                if(curr<=prev){
                    result+=prev;
                    flag = 1;
                    prev = curr;
                }
                else{
                    result+=curr - prev;
                    flag = 0;
                    prev = 0;
                }
                continue;
            }
            prev = romanMap.at(s[i]);
        }
        return result+prev;
    }
};
// @lc code=end

