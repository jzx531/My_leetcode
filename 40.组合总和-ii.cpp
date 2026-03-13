/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
// void dfs(vector<int>& candidates,int start,int target,vector<int> path,int sum,vector<vector<int>>& res)
// {
//     if(sum>target)
//         return;
//     if(sum==target)
//     {
//         res.push_back(path);
//         return;
//     }
//     for(int i=start;i<candidates.size();i++)
//     {
//         if(sum+candidates[i]>target)
//             break;
//         int equal = 0;
//         while((i+equal)<(candidates.size()-1)&&candidates[i]==candidates[i+equal+1])
//         {
//             equal++;
//         }
//         if(equal>0){
//             for (int k = equal+1; k >= 1; --k) {  // Try using the candidate twice (k=2) and once (k=1)
//                 for (int j = 0; j < k; ++j) {
//                     path.push_back(candidates[i]);
//                 }
//                 dfs(candidates, i + equal + 1, target, path, sum + k * candidates[i], res);
//                 for (int j = 0; j < k; ++j) {
//                     path.pop_back();
//                 }
//             }
//             i+=equal;
//         }
//         else{
//             path.push_back(candidates[i]);
//             dfs(candidates,i+1,target,path,sum+candidates[i],res);
//             path.pop_back();
//         }
//     }
// }

// vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//     vector<vector<int>> res;
//     sort(candidates.begin(),candidates.end());
//     dfs(candidates,0,target,vector<int>(),0,res);
//     return res;
// }

void dfs(vector<int>& candidates, int start, int target, vector<int>& path, int sum, vector<vector<int>>& res) {
    if (sum == target) {
        res.push_back(path);
        return;
    }
    
    for (int i = start; i < candidates.size(); i++) {
        // Skip duplicates to avoid duplicate combinations
        if (i > start && candidates[i] == candidates[i-1]) 
            continue;
            
        if (sum + candidates[i] > target)
            break;
            
        path.push_back(candidates[i]);
        dfs(candidates, i + 1, target, path, sum + candidates[i], res);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());
    vector<int> path;
    dfs(candidates, 0, target, path, 0, res);
    return res;
}
    
};
// @lc code=end

