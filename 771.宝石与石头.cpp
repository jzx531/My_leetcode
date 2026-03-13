/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> jewel_count;
        for (char c : stones) {
            jewel_count[c]++;
        }
        int count = 0;
        unordered_set<char> jewels_set(jewels.begin(), jewels.end());
        for (char c : jewels_set) {
            count += jewel_count[c];
        }
        return count;
    }
};
// @lc code=end

