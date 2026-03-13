/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        int res = 0; // 初始化 res
        for (string s : operations) {
            if (s == "D") {
                scores.push(scores.top() * 2);
            } else if (s == "C") {
                scores.pop();
            } else if (s == "+") {
                int score1 = scores.top();
                scores.pop();
                int score2 = scores.top();
                scores.push(score1);
                scores.push(score1 + score2);
            } else {
                scores.push(stoi(s)); // 使用 stoi 转换字符串
            }
        }
        while (!scores.empty()) {
            res += scores.top();
            scores.pop();
        }
        return res;
    }
};
// @lc code=end

