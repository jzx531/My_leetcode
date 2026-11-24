#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<vector<long long>> a(n, vector<long long>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        // 枚举同一行内合法的选择状态。
        vector<int> states;

        for (int mask = 0; mask < (1 << m); ++mask) {
            if ((mask & (mask << 1)) == 0) {
                states.push_back(mask);
            }
        }

        int s = static_cast<int>(states.size());

        // compatible[cur]：可以与当前状态相接的上一行状态下标。
        vector<vector<int>> compatible(s);

        for (int cur = 0; cur < s; ++cur) {
            for (int prev = 0; prev < s; ++prev) {
                int x = states[cur];
                int y = states[prev];

                if ((x & y) == 0 &&
                    (x & (y << 1)) == 0 &&
                    (x & (y >> 1)) == 0) {
                    compatible[cur].push_back(prev);
                }
            }
        }

        const long long NEG = -(1LL << 60);

        vector<long long> dp(s, NEG);

        // 尚未处理任何行时，只有“空状态”可达。
        // states 按 mask 从小到大生成，因此 states[0] == 0。
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            // 计算当前行每个合法状态的得分。
            vector<long long> value(s, 0);

            for (int cur = 0; cur < s; ++cur) {
                for (int j = 0; j < m; ++j) {
                    if (states[cur] & (1 << j)) {
                        value[cur] += a[i][j];
                    }
                }
            }

            vector<long long> nextDp(s, NEG);

            for (int cur = 0; cur < s; ++cur) {
                for (int prev : compatible[cur]) {
                    if (dp[prev] == NEG) {
                        continue;
                    }

                    nextDp[cur] = max(
                        nextDp[cur],
                        dp[prev] + value[cur]
                    );
                }
            }

            dp.swap(nextDp);
        }

        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }

    return 0;
}