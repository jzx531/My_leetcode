/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), [](int a, int b){
            string sa = to_string(a), sb = to_string(b);
            return sa + sb > sb + sa;
        });
        for(int num : nums){
            res += to_string(num);
        }
        return res.empty() || res[0] == '0'? "0" : res;
    }
};
// @lc code=end

