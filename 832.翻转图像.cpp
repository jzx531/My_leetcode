/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> res(image.size(), vector<int>(image[0].size()));
        for (int i = 0; i < image.size(); i++) {
            for (int j = 0; j < image[0].size(); j++) {
                res[i][j] = image[i][image[0].size() - 1 - j] ^ 1;
            }
        }
        return res;
    }
};
// @lc code=end

