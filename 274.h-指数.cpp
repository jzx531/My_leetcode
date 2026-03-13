/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int res;
        for (int i = n;i>=0;i--) {
            res = 0;
            for (int j = 0;j<n;j++) {
                if (citations[j] >= i) {
                    res++;
                }
            }
            if (res >= i) {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end

