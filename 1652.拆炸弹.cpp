/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

// @lc code=start
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n,0);
        if (k == 0) return res;
        else if(k >0){
            for (int i = 0; i < n; i++){
                for (int j = 1; j <= k; ++j) {
                    res[i] += code[(i + j) % n];
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                for(int j = 1; j <= -k; ++j) {
                    res[i] += code[(i - j + n) % n];
                }
            }
        }
        return res;
    }
};
// @lc code=end

// The new version of the code is almost the same as the old version, except for the else if statement. The else if statement is added to handle the case when k is positive. In the else if statement, we iterate through the code array and add the values of the elements that are k positions away from the current element. We use the modulo operator to handle the case when the index goes out of bounds.
