/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        for (int i= n;i>=1;i--)  
        {
            if(citations[n-i]>=i)
            {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end

