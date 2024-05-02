#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, M;
vector<int> tree[250005];
int dp[250005][2], vst[250005][2];

int DP(int node, int t, int par) {
    int &ret = dp[node][t];
    if (ret != -1) return ret;
    ret = t;
    
    for (int next: tree[node]) {
        if (next == par) continue;
        int a = DP(next, 0, node), b = DP(next, 1, node);
        if (t) ret += a;
        else ret += max(a, b);
    }
    
    return ret;
}

void DFS(int node, int t, int par) {
    if (vst[node][t]) return;
    vst[node][t] = 1;
    if (t == 0) M++;
    for (int next: tree[node]) {
        if (next == par) continue;
        if (t) DFS(next, 0, node);
        else {
            if (DP(next, 0, node) > DP(next, 1, node)) DFS(next, 0, node);
            else if (DP(next, 0, node) == DP(next, 1, node)) DFS(next, 0, node), DFS(next, 1, node);
            else DFS(next, 1, node);
        }
    }
    return;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    memset(dp, -1, sizeof(dp));
    
    if (DP(1, 0, 0) > DP(1, 1, 0)) DFS(1, 0, 0);
    else if (DP(1, 0, 0) == DP(1, 1, 0)) DFS(1, 0, 0), DFS(1, 1, 0);
    else DFS(1, 1, 0);
    
    cout << M * (N - M) + (M * (M - 1) / 2);
    
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