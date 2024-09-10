#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector<int> tree[30005];
int par[30005][21], level[30005];

void DFS(int node, int p) {
    par[node][0] = p;
    level[node] = level[p] + 1;
    for (int i = 1; i <= 20; i++) par[node][i] = par[par[node][i - 1]][i - 1];
    
    for (int next: tree[node]) {
        if (next == p) continue;
        DFS(next, node);
    }
}

int LCA(int a, int b) {
    if (level[a] < level[b]) swap(a, b);
    
    if (level[a] != level[b]) {
        for (int i = 20; i >= 0; i--) {
            if (level[par[a][i]] >= level[b]) a = par[a][i];
        }
    }
    
    int ret = a;
    if (a != b) {
        for (int i = 20; i >= 0; i--) {
            if (par[a][i] != par[b][i]) {
                a = par[a][i];
                b = par[b][i];
            }
            ret = par[a][i];
        }
    }
    
    return ret;
}

ll dist(int a, int b) {
    return abs(level[a] - level[b]);
}

void solve() {
    cin >> N;
    
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    DFS(1, 0);
    
    cin >> M;
    int now = 1;
    
    ll ans = 0;
    while (M--) {
        int a;
        cin >> a;
        int lca = LCA(now, a);
        
        ans += dist(now, lca) + dist(a, lca);
        now = a;
    }
    
    cout << ans;
    
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