/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start
class Solution {
public:
    int countBits(int num) {
        int count = 0;
        while (num) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if(countBits(a) == countBits(b)) {
                return a < b;
            }
            return countBits(a) < countBits(b);
        });
        return arr;
    }
};
// @lc code=end

