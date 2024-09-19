#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M, S, T, U, V;
vector<pii> graph[200005];
ll dist[200005], vst[200005];
vector<int> path[200005];
set<pii> mark;

void DFS(int now, int E) {
    if (vst[now]) return;
    else vst[now] = 1;
    
    if (now == E) return;
    for (int next: path[now]) {
        mark.insert({now, next});
        DFS(next, E);
    }
}

void Dijkstra(int start) {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<>> pq;
    for (int i = 1; i <= N; i++) path[i].clear();
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (pq.size()) {
        auto t = pq.top();
        pq.pop();
        ll now = t.second, v = t.first;
        if (dist[now] < v) continue;
        for (auto [next, cost]: graph[now]) {
            if (mark.count({now, next})) cost = 0;
            ll ncost = v + cost;
            if (dist[next] > ncost) {
                path[next].clear();
                path[next].push_back(now);
                dist[next] = ncost;
                pq.push({ncost, next});
            } else if (dist[next] == ncost) path[next].push_back(now);
        }
    }
}

void solve() {
    cin >> N >> M >> S >> T >> U >> V;
    for (int i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    Dijkstra(S);
    DFS(T, S);
    Dijkstra(U);
    ll ans = dist[V];
    Dijkstra(V);
    ans = min(ans, dist[U]);
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