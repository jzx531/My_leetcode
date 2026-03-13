/*
 * @lc app=leetcode.cn id=497 lang=cpp
 *
 * [497] 非重叠矩形中的随机点
 */

// @lc code=start
class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        this->n = rects.size();
        this->sum_area = 0;
        for (int i = 0; i < n; i++) {
            int x1 = rects[i][0];
            int y1 = rects[i][1];
            int x2 = rects[i][2];
            int y2 = rects[i][3];
            int w = x2 - x1 + 1;
            int h = y2 - y1 + 1;
            sum_area += w * h;
            areas.push_back(sum_area);
        }
    }
    
    vector<int> pick() {
        int area = rand() % sum_area;
        int index=0;
        while (index < n && area >= areas[index]) {
            index++;
        }
        int x1 = rects[index][0];
        int y1 = rects[index][1];
        int x2 = rects[index][2];
        int y2 = rects[index][3];
        int w = x2 - x1 + 1;
        int h = y2 - y1 + 1;
        int x = x1 + rand() % w;
        int y = y1 + rand() % h;
        return {x, y};
    }
    private:
        vector<vector<int>> rects;
        vector<int> areas;
        int n;
        int sum_area;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end

