/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */

// @lc code=start
class Solution {
    public:
        int largestAltitude(vector<int>& gain) {
            int max_altitude = 0, current_altitude = 0;
            for (const int &g : gain) {
                current_altitude += g;
                if (current_altitude > max_altitude) {
                    max_altitude = current_altitude;
                }
            }
            return max_altitude;
        }
    };
    // @lc code=end