/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<int> nums;
        for (string& token : tokens) {
            if ('0'<=token[0]&&token[0]<='9'||token.size()>1) {
                nums.push(stoi(token));
            } else {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                switch (token[0]) {
                    case '+':
                        nums.push(num1 + num2);
                        break;
                    case '-':
                        nums.push(num1 - num2);
                        break;
                    case '*':
                        nums.push(num1 * num2);
                        break;
                    case '/':
                        nums.push(num1 / num2);
                        break;
                    default:
                        break;
                }
            }
        }
        return nums.top();
    }
};
// @lc code=end

