/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
    public:
        vector<int> diffWaysToCompute(string expression) {
            vector<int> result;
            
            // Base case: if the expression is just a number
            if (expression.size() <= 2) {
                bool isNumber = true;
                for (char c : expression) {
                    if (!isdigit(c)) {
                        isNumber = false;
                        break;
                    }
                }
                if (isNumber) {
                    return {stoi(expression)};
                }
            }
            
            for (int i = 0; i < expression.size(); i++) {
                char c = expression[i];
                if (c == '+' || c == '-' || c == '*') {
                    vector<int> left = diffWaysToCompute(expression.substr(0, i));
                    vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                    
                    for (int a : left) {
                        for (int b : right) {
                            switch (c) {
                                case '+':
                                    result.push_back(a + b);
                                    break;
                                case '-':
                                    result.push_back(a - b);
                                    break;
                                case '*':
                                    result.push_back(a * b);
                                    break;
                            }
                        }
                    }
                }
            }
            
            // If no operators found (shouldn't happen due to base case)
            if (result.empty()) {
                return {stoi(expression)};
            }
            
            return result;
        }
    };
// @lc code=end

