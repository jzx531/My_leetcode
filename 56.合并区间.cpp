/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:

    // // 自定义哈希函数
    // struct VectorHash {
    //     size_t operator()(const std::vector<int>& vec) const {
    //         std::hash<int> hasher;
    //         size_t seed = 0;
    //         for (int num : vec) {
    //             // 使用哈希组合技术（如 boost::hash_combine）
    //             seed ^= hasher(num) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    //         }
    //         return seed;
    //     }
    // };

    // // 自定义相等比较函数
    // struct VectorEqual {
    //     bool operator()(const std::vector<int>& a, const std::vector<int>& b) const {
    //         return a == b; // 直接使用 vector 的 == 运算符
    //     }
    // };

    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     vector<vector<int>> res = intervals;
    //     unordered_set<vector<int>, VectorHash, VectorEqual> s;
    //     while(1){
    //         vector<int> Range = res[0];
    //         res.erase(res.begin());
    //         for(int i = 0; i < res.size(); i++){
    //             if(res[i][0]<= Range[1]&&res[i][0] >= Range[0]){
    //                 Range[0] = min(Range[0], res[i][0]);
    //                 Range[1] = max(Range[1], res[i][1]);
    //                 res.erase(res.begin()+i);
    //                 i--;
    //             }
    //         }
    //         res.push_back(Range);
    //         auto ret = s.insert(Range);
    //         if(ret.second) break;
    //     }
    //     return res;
    // }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res = intervals;
        sort(res.begin(), res.end());
        int n = res.size();
        for(int i = 1; i < n; i++){
            if(res[i][0] <= res[i-1][1]){
                res[i][0] = min(res[i][0], res[i-1][0]);
                res[i][1] = max(res[i][1], res[i-1][1]);
                res.erase(res.begin()+i-1);
                i--;
                n--;
            }
        }
        return res;
    }

};
// @lc code=end

