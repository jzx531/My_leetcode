/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 */

// @lc code=start

class Solution {
    public:
        int countArrangement(int n) {
            vector<int> memo(1 << n, -1); // -1 表示没有计算过
            auto dfs = [&](this auto&& dfs, int s) -> int {
                if (s == 0) {
                    return 1;
                }
                int& res = memo[s]; // 注意这里是引用
                if (res != -1) { // 之前计算过
                    return res;
                }
                res = 0;
                int i = popcount((unsigned) s);
                for (int j = 1; j <= n; j++) {
                    if (s >> (j - 1) & 1 && (i % j == 0 || j % i == 0)) {
                        res += dfs(s ^ (1 << (j - 1)));
                    }
                }
                return res;
            };
            return dfs((1 << n) - 1);
        }
    };
    
// @lc code=end

