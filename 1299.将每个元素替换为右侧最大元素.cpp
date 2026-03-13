/*
 * @lc app=leetcode.cn id=1299 lang=cpp
 *
 * [1299] 将每个元素替换为右侧最大元素
 */

// @lc code=start
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res(arr.size(), -1);
        int max_val = -1;
        for(int i = arr.size()-1; i>=0; i--){
            res[i] = max_val;
            max_val = max(max_val, arr[i]);
        }
        return res;
    }
};
// @lc code=end

