/*
 * @lc app=leetcode.cn id=478 lang=cpp
 *
 * [478] 在圆内随机生成点
 */

// @lc code=start
class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        double x,y;
        double r = sqrt(rand() / (double)RAND_MAX) * radius;
        double theta = rand() / (double)RAND_MAX * 2 * M_PI;
        x = x_center + r * cos(theta);
        y = y_center + r * sin(theta);
        return {x,y};
    }
    private:
        double radius, x_center, y_center;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end

