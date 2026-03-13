/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
    public:
        int maxProduct(vector<string>& words) {
            int n = words.size();
            vector<int> masks(n, 0);
            int res = 0;
            
            // 预处理每个单词的位掩码
            for (int i = 0; i < n; ++i) {
                for (char c : words[i]) {
                    masks[i] |= 1 << (c - 'a');
                }
            }
            
            // 比较所有单词对
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if ((masks[i] & masks[j]) == 0) { // 没有共同字母
                        int product = words[i].length() * words[j].length();
                        res = max(res, product);
                    }
                }
            }
            
            return res;
        }
    };
// @lc code=end

