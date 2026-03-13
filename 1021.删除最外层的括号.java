/*
 * @lc app=leetcode.cn id=1021 lang=java
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
class Solution {
    public String removeOuterParentheses(String s) {
        String res = "";
        int count = 0;
        boolean flag = false;
        for(char c:s.toCharArray())
        {
            if(c == '(')
            {
                if(flag){
                    res += c;
                    count++;
                }
                else{
                    flag = true;
                    count++;
                }
            }
            else
            {
                if(count ==1){
                    count --;
                    flag = false;
                }
                else{
                    res += c;
                    count--;
                }
            }
        }
        return res;
    }
}
// @lc code=end

