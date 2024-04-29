#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M;
vector<pair<int, pii>> graph[300005];
ll ans[500005];
ll dist[300005];

void Dijkstra(int start) {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (pq.size()) {
        pii t = pq.top();
        pq.pop();
        ll now = t.second, v = t.first;
        if (dist[now] < v) continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first, cost = graph[now][i].second.first, t = graph[now][i].second.second;
            if (dist[next] > v + cost) {
                dist[next] = v + cost;
                if (t != -1) ans[t] = 1;
                pq.push({v + cost, next});
            }
        }
    }
    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, {c, i}});
        graph[b].push_back({a, {2 * c, -1}});
    }
    
    Dijkstra(1);
    
    ll sum = 0;
    for (int i = 1; i <= N; i++) sum += dist[i];
    
    cout << sum << '\n';
    for (int i = 0; i < M; i++) cout << ans[i] << " ";
    
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