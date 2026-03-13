/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
vector<int> singleNumber(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num: nums) {
        ++freq[num];
    }
    vector<int> ans;
    for (const auto& [num, occ]: freq) {
        if (occ == 1) {
            ans.push_back(num);
        }
    }
    return ans;
}

};
// @lc code=end

