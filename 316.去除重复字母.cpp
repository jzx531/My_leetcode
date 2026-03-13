/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
    public:
        string removeDuplicateLetters(string s) {
            vector<int> left(26), in_ans(26);
            for (char c : s) {
                left[c - 'a']++; // 统计每个字母的出现次数
            }
            string ans;
            for (char c : s) {
                left[c - 'a']--;
                if (in_ans[c - 'a']) { // ans 中不能有重复字母
                    continue;
                }
                while (!ans.empty() && c < ans.back() && left[ans.back() - 'a']) {
                    // (设 x=ans.back()) 如果 c < x，且右边还有 x，那么可以把 x 去掉，
                    // 因为后面可以重新把 x 加到 ans 中
                    in_ans[ans.back() - 'a'] = false; // 标记 x 不在 ans 中
                    ans.pop_back();
                }
                ans += c; // 把 c 加到 ans 的末尾
                in_ans[c - 'a'] = true; // 标记 c 在 ans 中
            }
            return ans;
        }
    };

// @lc code=end

