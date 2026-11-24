#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
vector<int> children[MAXN];
bool inV[MAXN];
long long S[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        inV[a] = true;
    }
    
    // BFS 构建有向树
    vector<int> order;
    vector<bool> visited(n + 1, false);
    order.push_back(1);
    visited[1] = true;
    for (int i = 0; i < (int)order.size(); i++) {
        int u = order[i];
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                children[u].push_back(v);
                order.push_back(v);
            }
        }
    }
    
    // 后序遍历计算 S[i]
    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int u = order[i];
        S[u] = inV[u] ? 1 : 0;
        for (int v : children[u]) {
            S[u] += S[v];
        }
    }
    
    // 计算答案：cnt[i] = S[i]^2 - sum(S[child]^2)
    for (int i = 1; i <= n; i++) {
        long long ans = S[i] * S[i];
        for (int v : children[i]) {
            ans -= S[v] * S[v];
        }
        cout << ans << " \n"[i == n];
    }
    
    return 0;
}