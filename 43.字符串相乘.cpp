/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);  // 结果最多m+n位
        
        // 从低位开始计算
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int sum = product + res[i + j + 1];  // 加上之前的进位
                res[i + j + 1] = sum % 10;          // 当前位
                res[i + j] += sum / 10;             // 进位
            }
        }
        
        // 去掉前导零
        int k = 0;
        while (k < res.size() && res[k] == 0) k++;
        
        // 转换为字符串
        string ans;
        for (; k < res.size(); k++) {
            ans.push_back(res[k] + '0');
        }
        
        return ans;
    }
};
// @lc code=end

