/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        int zip = (numRows >2)? (numRows -2):0;
        int loop = zip +numRows;
        string res="";
        for (int i=0;i<numRows;i++)
        {
            for (int pos = i;pos<s.length();pos+=loop)
            {
               res += s.at(pos);
               if(i!=0 && i!=numRows-1)
               {
                   int offset = pos+loop -2*i;
                   if(offset<s.length()){
                    res+=s.at(offset);
                   }
               }
            }
        }
        return res;
    }
};
// @lc code=end

