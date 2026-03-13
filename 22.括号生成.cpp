/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    void genParentheses(vector<string> &res,string s,int n,int left,int right){
        if(left<right){
            return;
        }
        if(left==n){
            for(int i=left+right;i<2*n;i++){
                s.push_back(')');
            }
            res.push_back(s);
            return;
        }
        genParentheses(res,s+'(',n,left+1,right);
        genParentheses(res,s+')',n,left,right+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        genParentheses(res,"",n,0,0);
        return res;
    }
};
// @lc code=end

