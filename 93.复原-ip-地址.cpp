/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    void dfs(string s, int start, int count, string path, vector<string>& res) {
        if(start == s.size() && count == 4) {
            path.pop_back();
            res.push_back(path);
            return;
        }
        if(count > 4) {
            return;
        }
        for(int i = 0; i < 3 && start + i < s.size(); i++)
        {
            string sub = s.substr(start, i+1);
            if(sub[0] == '0' && i > 0) {
                break;
            }
            int num = stoi(sub);
            if(num > 255) {
                break;
            }
            if(count == 0) {
                dfs(s, start+i+1, count+1, path+sub+".", res);
            }
            else {
                dfs(s, start+i+1, count+1, path+sub+".", res);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(s, 0, 0, "", res);
        return res;
    }
};
// @lc code=end

