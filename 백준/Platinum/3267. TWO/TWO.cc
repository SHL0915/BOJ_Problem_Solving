#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, S;
vector<pii> tree[100005];
ll dist[100005];

void DFS(int node, int par, ll c) {
    dist[node] = c;
    for (auto &[next, cost]: tree[node]) {
        if (next == par) continue;
        DFS(next, node, c + cost);
    }
}

void solve() {
    cin >> N >> S;
    ll tot = 0;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
        tot += c;
    }
    
    ll ans = tot * 2;
    
    DFS(1, 0, 0);
    
    ll root = -1, m = -1;
    for (int i = 1; i <= N; i++) m = max(m, dist[i]);
    for (int i = 1; i <= N; i++) if (m == dist[i]) root = i;
    
    DFS(root, 0, 0);
    
    m = -1;
    for (int i = 1; i <= N; i++) m = max(m, dist[i]);
    
    cout << ans - m;
    
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