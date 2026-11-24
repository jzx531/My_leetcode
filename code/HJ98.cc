#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n + 1);
    long long total = 0;
    int totalPositive = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        total += a[i];

        if (a[i] > 0) {
            ++totalPositive;
        }
    }

    // 三段和相等，而且每段都必须至少有一个正数。
    if (n < 3 || total % 3 != 0 || totalPositive < 3) {
        cout << 0 << '\n';
        return 0;
    }

    const long long target = total / 3;

    long long prefix = 0;
    int positive = 0;

    long long firstCuts = 0;
    long long usableFirst = 0;
    long long answer = 0;

    // 枚举第二刀的位置 j，第三段必须非空，所以 j < n。
    for (int j = 1; j < n; ++j) {
        prefix += a[j];

        if (a[j] > 0) {
            ++positive;

            // 此时，之前所有候选第一刀的右侧，
            // 到当前位置为止都至少包含一个正数 a[j]。
            usableFirst = firstCuts;
        }

        // 前两段总和为 2 * target。
        // 同时，第三段必须至少包含一个正数。
        if (prefix == 2 * target &&
            positive < totalPositive) {
            answer += usableFirst;
        }

        // 把当前位置登记为后续可用的第一刀。
        // 第一段必须和为 target，并且至少有一个正数。
        if (prefix == target && positive > 0) {
            ++firstCuts;
        }
    }

    cout << answer << '\n';
    return 0;
}