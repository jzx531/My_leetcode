/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
    public:
        string simplifyPath(string path) {
            vector<string> stack;
            string dir;
            stringstream ss(path);
    
            while (getline(ss, dir, '/')) {
                if (dir == "" || dir == ".") continue;
                if (dir == "..") {
                    if (!stack.empty()) stack.pop_back();
                } else {
                    stack.push_back(dir);
                }
            }
    
            string res = "/";
            for (int i = 0; i < stack.size(); ++i) {
                res += stack[i];
                if (i != stack.size() - 1) res += "/";
            }
            
            return res;
        }
    };
    
// @lc code=end

