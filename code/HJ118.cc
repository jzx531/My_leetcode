#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> d(n + 1);
    int sum = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        sum += d[i];
    }

    if (sum % 2) {
        cout << -1 << '\n';
        return 0;
    }

    int target = sum / 2;

    // from[s]：首次凑出和 s 时，最后选中的点。
    vector<int> from(target + 1, -1);
    from[0] = 0;

    for (int i = 1; i <= n; ++i) {
        // 倒序遍历，保证每个点最多选择一次。
        for (int s = target; s >= d[i]; --s) {
            if (from[s] == -1 && from[s - d[i]] != -1) {
                from[s] = i;
            }
        }
    }

    if (from[target] == -1) {
        cout << -1 << '\n';
        return 0;
    }

    // 还原左侧点集。
    vector<bool> inLeft(n + 1, false);
    for (int s = target; s > 0; ) {
        int i = from[s];
        inLeft[i] = true;
        s -= d[i];
    }

    vector<int> left, right;
    for (int i = 1; i <= n; ++i) {
        if (inLeft[i]) left.push_back(i);
        else right.push_back(i);
    }

    // 边数等于任意一侧的度数和。
    cout << target << '\n';

    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        int u = left[i], v = right[j];
        int cnt = min(d[u], d[v]);

        // 同一对点之间允许输出多条边。
        for (int k = 0; k < cnt; ++k) {
            cout << u << ' ' << v << '\n';
        }

        d[u] -= cnt;
        d[v] -= cnt;

        if (d[u] == 0) ++i;
        if (d[v] == 0) ++j;
    }

    return 0;
}


// #include <iostream>
// #include <numeric>
// #include <vector>
// #include <algorithm>
// #include <unordered_set>
// using namespace std;

// void dfs(std::vector<int> &nums, int n,int & divide,int tmpsum, int & ans,int cuts,int l,bool has_positive)
// {
//     tmpsum+=nums[l];
//     if(nums[l]>0){
//         has_positive = true;
//     }
//     ++l;
//     bool old_positive = has_positive;
//     if(tmpsum==divide && has_positive){
//         cuts++;
//         tmpsum = 0;
//         has_positive = false;
//     }
//     if(cuts == 3 && old_positive && l==n){
//         ans++;
//         return;
//     }
//     if(l == n)
//     {
//         return;
//     }

//     dfs(nums,n,divide,tmpsum,ans,cuts,l,has_positive);
// }

// int main() {
//     int n;
//     cin >> n;

//     std::vector<int> nums;
//     for (int i=0;i<n;i++)
//     {
//         int m;
//         cin >> m;
//         nums.push_back(m);
//     }

//     int sum = std::accumulate(nums.begin(),nums.end(),0);
    
//     if(sum % 3){
//         cout << 0 <<endl;
//         return 0;
//     }
//     int divide = sum / 3;

//     int ans = 0;
//     dfs(nums,n,divide,0,ans,0,0,false);
//     std::cout<<ans<<std::endl;
//     return 0;

// }
// // 64 位输出请用 printf("%lld")