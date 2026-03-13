/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

// @lc code=start
class Solution {
public:
string destCity(vector<vector<string>>& paths) {
    unordered_map<string, int> outDegree;
    unordered_set<string> cities;
    
    for (const auto& path : paths) {
        string from = path[0];
        string to = path[1];
        outDegree[from]++;
        cities.insert(from);
        cities.insert(to);
    }
    
    for (const string& city : cities) {
        if (outDegree[city] == 0) {
            return city;
        }
    }
    
    return ""; // Should not reach here as per problem statement
}
};
// @lc code=end

