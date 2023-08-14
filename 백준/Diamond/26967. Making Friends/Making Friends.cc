#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
set<int> graph[200005];

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        graph[a].insert(b);
    }

    ll ans = 0;

    for (int i = 1; i <= N; i++) {
        if (graph[i].size() == 0) continue;
        int nxt = *graph[i].begin();
        graph[i].erase(nxt);
        ll sz = graph[nxt].size();
        
        if (graph[nxt].size() < graph[i].size()) swap(graph[nxt], graph[i]);

        for (int a: graph[i]) graph[nxt].insert(a);

        ans += graph[nxt].size() - sz;
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