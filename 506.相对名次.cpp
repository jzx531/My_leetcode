/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> score_copy(score);
        sort(score.begin(), score.end(), greater<int>());
        vector<string> res(score.size());
        for (int i = 0; i < score.size(); i++) {
            for(int j = 0; j < score.size(); j++)
            {
                if(score_copy[j] == score[i])
                {
                    if(i==0){
                        res[j] = "Gold Medal";
                    }
                    else if(i==1){
                        res[j] = "Silver Medal";
                    }
                    else if(i==2){
                        res[j] = "Bronze Medal";
                    }
                    else{
                        res[j] = to_string(i+1);
                    }
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

