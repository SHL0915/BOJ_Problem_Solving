#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M, K;
vector<pii> graph[100005];
ll arr[100005];

void Dijkstra(int start, vector<ll> &dist) {
    fill(dist.begin(), dist.end(), 1e18);
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (pq.size()) {
        pii t = pq.top();
        pq.pop();
        ll now = t.second, val = t.first;
        if (dist[now] < val) continue;
        for (auto &[next, cost]: graph[now]) {
            ll ncost = val + cost;
            if (dist[next] > ncost) {
                dist[next] = ncost;
                pq.push({ncost, next});
            }
        }
    }
    return;
}

void solve() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    for (int i = 1; i <= N; i++) cin >> arr[i];

    vector<ll> distA(N + 5), distB(N + 5);
    Dijkstra(1, distA);
    Dijkstra(N, distB);

    ll ans = 1e18;
    for (int i = 1; i <= N; i++) {
        if (arr[i] == -1) continue;
        ans = min(ans, distA[i] + distB[i] + arr[i] * (K - 1));
    }

    if (ans == 1e18) cout << -1;
    else cout << ans;

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