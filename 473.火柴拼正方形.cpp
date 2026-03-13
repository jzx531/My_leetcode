/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 */

// @lc code=start
class Solution {
public:
    // void backtrace(vector<int>& matchsticks, int target_len, int tmplen,int start, int count,vector<int>& used,bool &res,bool &flag){
    //     if(flag) return;
    //     if(res) return;
    //     if(tmplen > target_len) return;
    //     if(tmplen == target_len){
    //         tmplen = 0;
    //         count++;
    //         if (count == 4 && accumulate(used.begin(), used.end(), 0) == matchsticks.size()) {
    //             res = true;
    //             return;
    //         }
    //     }
    //     for(int i = 0; i < matchsticks.size(); i++){
    //         if(used[i] == 1) continue;
    //         if(matchsticks[i] > target_len) {
    //             flag = true;
    //             return;
    //         }
    //         used[i] = 1;
    //         backtrace(matchsticks, target_len, tmplen + matchsticks[i], i, count, used, res, flag);
    //         used[i] = 0;            
    //     }
    // }
    // bool makesquare(vector<int>& matchsticks) {
    //     int total_len = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    //     if (total_len % 4 != 0) {
    //         return false;
    //     }
    //     int target_len = total_len / 4;
    //     cout<<target_len<<endl;
    //     sort(matchsticks.begin(),matchsticks.end());
    //     vector<int> used(matchsticks.size(), 0);
    //     bool res = false;
    //     bool flag = false;
    //     backtrace(matchsticks, target_len, 0, 0, 0, used, res,flag);
    //     return res;
    // }
    bool backtrack(vector<int>& matchsticks, vector<int>& sides, int index, int target) 
    {
        if (index == matchsticks.size()) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        
        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] > target) {
                continue;
            }
            
            // Skip duplicate combinations
            int j = i;
            while (--j >= 0) {
                if (sides[j] == sides[i]) {
                    break;
                }
            }
            if (j != -1) continue;
            
            sides[i] += matchsticks[index];
            if (backtrack(matchsticks, sides, index + 1, target)) {
                return true;
            }
            sides[i] -= matchsticks[index];
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;
        
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) return false;
        
        int target = total / 4;
        sort(matchsticks.rbegin(), matchsticks.rend()); // Sort in descending order
        
        vector<int> sides(4, 0);
        return backtrack(matchsticks, sides, 0, target);
    }
};
// @lc code=end

