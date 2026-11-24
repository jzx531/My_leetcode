#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Query {
    int l, r, idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> last1(n + 1, 0);
    for (int j = 1; j <= n; j++) {
        last1[j] = (s[j - 1] == '1') ? j : last1[j - 1];
    }

    vector<long long> S(n + 1, 0);
    for (int j = 1; j <= n; j++) {
        S[j] = S[j - 1] + last1[j];
    }

    int q;
    cin >> q;
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }

    // 按 l 从大到小排序
    sort(queries.begin(), queries.end(), [](const Query& a, const Query& b) {
        return a.l > b.l;
    });

    vector<long long> ans(q);
    int j0 = n + 1;

    for (const auto& qu : queries) {
        int l = qu.l, r = qu.r, idx = qu.idx;
        
        while (j0 > l && last1[j0 - 1] >= l) {
            j0--;
        }
        int start = max(j0, l);

        if (start <= r) {
            long long sumLast = S[r] - S[start - 1];
            long long cnt = r - start + 1;
            ans[idx] = sumLast - (long long)(l - 1) * cnt;
        } else {
            ans[idx] = 0;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}

// #include <cstdint>
// #include <iostream>
// #include <vector>
// #include <string>
// #include <cctype>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     std::vector<uint8_t> bits;
//     bits.resize(n);
//     string s;
//     cin >> s;
//     for (int i = 0; i < n; i++) {
//         bits[i] = s[i] - '0';   // 字符转数字：'1' - '0' = 1
//     }

//     int k;
//     cin >> k;
//     std::vector<std::pair<int, int>> intervals(k);
//     // intervals.resize;
//     for (int i = 0; i < k; i++) {
//         cin >> intervals[i].first >> intervals[i].second;
//     }

//     /* 超时
//     for (int j = 0; j < k; j++) {
//         int L = intervals[j].first  - 1;
//         int R = intervals[j].second - 1;
//         long long ans = 0;

//         for (int i = L; i <= R; i++) {        // 子串左端点
//             int tmp = 0;
//             for (int r = i; r <= R; r++) {    // 子串右端点
//                 tmp |= bits[r];                // 增量或，不用重算
//                 ans += tmp;
//             }
//         }
//         cout << ans << "\n";
//     }
   

//     for ( int j = 0; j < k; j++) {
//         int L = intervals[j].first  - 1;
//         int R = intervals[j].second - 1;
//         long long ans = 0;
//         ans = (R - L + 1) * (R - L + 2) /2;
//         for(int i = L ;i <= R;)
//         {
//             int zeros = 0;
//             while(i++<=R && bits[i - 1] == 0)
//             {
//                 ++zeros;
//                 // ++i;
//             }
//             ans-= (zeros+1)*zeros/2;
//         }
//         std::cout << ans <<std::endl;
//     } */

    

//     return 0;
// }