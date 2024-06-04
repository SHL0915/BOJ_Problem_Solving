#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 1e15;

int N, M;
vector<pair<int, pii>> graph[100005];

void Dijkstra(int start, int t, vector<ll> &dist) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[start] = t;
    pq.push({t, start});
    while (pq.size()) {
        pii tt = pq.top();
        pq.pop();
        ll now = tt.second, v = tt.first;
        if (dist[now] < v) continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            ll a = graph[now][i].second.first, b = graph[now][i].second.second;
            if (v + a > b) continue;
            if (dist[next] > v + a) {
                dist[next] = v + a;
                pq.push({v + a, next});
            }
        }
    }
    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        graph[a].push_back({b, {c, d}});
        graph[b].push_back({a, {c, d}});
    }
    
    int l = 0, r = 1e9, ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        vector<ll> dist(N + 5, INF);
        Dijkstra(1, m, dist);
        if (dist[N] != INF) {
            l = m + 1;
            ans = m;
        } else r = m - 1;
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