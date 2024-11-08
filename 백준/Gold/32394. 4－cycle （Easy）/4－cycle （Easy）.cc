#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

int N, M;
vector<pii> edge;
int adj[1005][1005];

void solve() {
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edge.push_back({a, b});
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    
    ll ans = 0;
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            int a = edge[i].first, b = edge[i].second, c = edge[j].first, d = edge[j].second;
            set<int> s;
            s.insert(a), s.insert(b), s.insert(c), s.insert(d);
            if (s.size() != 4) continue;
            if (adj[a][c] && adj[b][d]) ans++;
            if (adj[a][d] && adj[b][c]) ans++;
        }
    }
    
    cout << ans / 2;
    
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