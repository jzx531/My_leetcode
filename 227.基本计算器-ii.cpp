/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<int> sn;
        stack<char> sop;
        int num = 0;
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if('0'<=s[i] && s[i]<='9')
            {
                num = num * 10 + (s[i] - '0');
            }
            else if(s[i] == '*' || s[i] == '/'|| s[i] == '+' || s[i] == '-')
            {
                sn.push(num);
                // sop.push(s[i]);
                num = 0;
                if(s[i] == '+' || s[i] == '-'&&!sop.empty()){
                    while(!sop.empty()){
                        char op = sop.top();
                        sop.pop();
                        int num2 = sn.top();
                        sn.pop();
                        int num1 = sn.top();
                        sn.pop();
                        switch (op)
                        {
                        case '+':
                            sn.push(num1 + num2);
                            break;
                        case '-':
                            sn.push(num1 - num2);
                            break;
                        case '*':
                            sn.push(num1 * num2);
                            break;
                        case '/':
                            sn.push(num1 / num2);
                            break;
                        default:
                            break;
                        }
                    }
                }
                else if(s[i] == '*' || s[i] == '/'&&!sop.empty()){
                    while(!sop.empty()&&sop.top()!='+'&&sop.top()!='-'){
                        char op = sop.top();
                        sop.pop();
                        int num2 = sn.top();
                        sn.pop();
                        int num1 = sn.top();
                        sn.pop();
                        switch (op)
                        {
                        case '*':
                            sn.push(num1 * num2);
                            break;
                        case '/':
                            sn.push(num1 / num2);
                            break;
                        default:
                            break;
                        }
                    }
                }
                sop.push(s[i]);
            }
            else;
        }
        sn.push(num);

        while(!sop.empty()&&!sn.empty())
        {
            char op = sop.top();
            sop.pop();
            int num2 = sn.top();
            sn.pop();
            int num1 = sn.top();
            sn.pop();
            if(op == '*')
            {
                sn.push(num1 * num2);
            }
            else if(op == '/')
            {
                sn.push(num1 / num2);
            }
            else if(op == '+')
            {
                sn.push(num1 + num2);
            }
            else if(op == '-')
            {
                sn.push(num1 - num2);
            }
        }
        return sn.top();
    }
};
// @lc code=end

