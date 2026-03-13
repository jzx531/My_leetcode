/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int bottom = max(ay1, by1);
        int top = min(ay2, by2);
        if(right < left || top < bottom) return area1 + area2;
        int overlap = (right - left) * (top - bottom);
        return area1 + area2 - overlap;
    }
};
// @lc code=end

