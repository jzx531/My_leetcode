/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i = 0,j=0,result =0;
        while(j<s.size())
        {
            auto ret = st.insert(s[j]);
            if(!ret.second){
                result = max(result,j-i);
                for (int k = i; k < j; ++k){
                    if(s[k]==s[j]){
                        i = k+1;
                        break;
                    }
                    st.erase(s[k]);
                }
            }
            ++j;
        }
        result = max(result,j-i);
        return result;
    }
};
// @lc code=end

