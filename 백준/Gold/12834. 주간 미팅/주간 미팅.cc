#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, V, E, A, B;
vector<pii> graph[1005];

void Dijkstra(int start, vector<ll> &dist) {
    fill(dist.begin(), dist.end(), 1e9);
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[start] = 0;
    pq.push({dist[start], start});

    while (pq.size()) {
        pii t = pq.top();
        pq.pop();
        ll now = t.second, d = t.first;
        if (dist[now] < d) continue;
        for (auto i: graph[now]) {
            ll next = i.first, cost = i.second;
            if (d + cost < dist[next]) {
                dist[next] = d + cost;
                pq.push({dist[next], next});
            }
        }
    }
}

void solve() {
    cin >> N >> V >> E >> A >> B;
    vector<int> home(N);
    for (int i = 0; i < N; i++) cin >> home[i];

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vector<ll> da(V + 1), db(V + 1);
    Dijkstra(A, da);
    Dijkstra(B, db);

    ll ans = 0;
    for (int i: home) {
        if (da[i] == 1e9) ans += -1;
        else ans += da[i];

        if (db[i] == 1e9) ans += -1;
        else ans += db[i];
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