#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<pii> tree[300005];
int ans[300005], dp[300005];

int DP(int node, int par) {
    int &ret = dp[node];
    if (ret != -1) return ret;
    ret = 0;
    for (pii next: tree[node]) {
        if (next.first == par) continue;
        if (!DP(next.first, node)) ret++;
    }
    
    return ret;
}

void DFS(int node, int par) {
    if (node != 1) {
        if (!dp[node]) {
            if (dp[par] <= 1) dp[node]++;
        } else {
            if (!dp[par]) dp[node]++;
        }
    }
    for (pii next: tree[node]) {
        if (next.first == par) continue;
        DFS(next.first, node);
    }
    return;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }
    
    memset(dp, -1, sizeof(dp));
    
    DP(1, 1);
    DFS(1, 1);
    
    for (int i = 1; i <= N; i++) {
        if (dp[i]) cout << "Zeze\n";
        else cout << "Portuga\n";
    }
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}