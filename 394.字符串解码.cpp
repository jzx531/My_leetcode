/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        int num = 0;
        string res = "";
        vector<string> tmp;
        tmp.push_back("");
        int countleft = 0;
        for(char c : s){
            if(isdigit(c)){
                num = num*10 + (c - '0');
            }
            else if(c == '['){
                numStack.push(num);
                num = 0;
                ++countleft;
                if((countleft+1) > tmp.size())
                {
                    tmp.push_back("");
                }
            }
            else if(c == ']'){
                string tmpStr = "";
                int n = numStack.top();
                numStack.pop();
                for(int i=0;i<n;i++){
                    tmpStr += tmp[countleft];
                }
                tmp[countleft] = "";
                countleft--;
                tmp[countleft] += tmpStr;
            }
            else if(c<='z'&&c>='a'){
                tmp[countleft] +=c;
            }
        }
        return tmp[0];
    }
};
// @lc code=end

