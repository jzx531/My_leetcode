/*
 * @lc app=leetcode.cn id=944 lang=java
 *
 * [944] 删列造序
 */

// @lc code=start
class Solution {
    public int minDeletionSize(String[] strs) {
        int n = strs.length;
        if(n == 0) return 0;
        int m = strs[0].length();
        int res = 0;
        for(int j = 0; j < m; j++)
        {
            for(int i = 1; i < n; i++)
            {
                if(strs[i].charAt(j) < strs[i-1].charAt(j))
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
}
// @lc code=end

