#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    vector<long long> t(n);
    for (auto& x : t) {
        cin >> x;
    }

    array<int, 3> order = {0, 1, 2};
    // order[j] 代表当前气球属于0，1，2的哪一段了因为只能是者三个颜色的排列组合有六种
    long long answer = LLONG_MAX;

    // 枚举三种颜色的全部 6 种顺序
    do {
        array<long long, 3> dp = {0, 0, 0};

        /*
        next[0] = dp[0] + cost0;
        next[1] = min(dp[0], dp[1]) + cost1;
        next[2] = min({dp[0], dp[1], dp[2]}) + cost2;
        */
        for (int i = 0; i < n; ++i) {
            array<long long, 3> next{};
            long long best = LLONG_MAX;

            for (int j = 0; j < 3; ++j) {
                // best = min(dp[0], ..., dp[j])
                best = min(best, dp[j]);

                long long cost =
                    (s[i] - '0' == order[j]) ? 0 : t[i];

                next[j] = best + cost;
            }

            dp = next;
        }

        answer = min(answer, *min_element(dp.begin(), dp.end()));

    } while (next_permutation(order.begin(), order.end()));

    cout << answer << '\n';
    return 0;
}

