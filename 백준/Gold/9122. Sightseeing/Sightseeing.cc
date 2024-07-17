#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M, S, F;
vector<pii> graph[1005];
ll dist[1005], dp[1005][2];
vector<int> path[1005], sec_path[1005];

void init() {
    for (int i = 1; i <= N; i++) graph[i].clear(), path[i].clear(), sec_path[i].clear();
    return;
}

void Dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (pq.size()) {
        pii t = pq.top();
        pq.pop();
        ll now = t.second, d = t.first;
        if (dist[now] < d - 1) continue;
        for (auto &[next, cost]: graph[now]) {
            ll ncost = d + cost;
            if (ncost < dist[next]) {
                dist[next] = ncost;
                pq.push({ncost, next});
            }
        }
    }

    return;
}

ll DP(int now, int t) {
    if (now == S) return 1;
    ll &ret = dp[now][t];
    if (ret != -1) return ret;
    ret = 0;
    if (t) for (int a: path[now]) ret += DP(a, 1);
    else {
        for (int a: sec_path[now]) ret += DP(a, 1);
        for (int a: path[now]) ret += DP(a, 0);
    }
    return ret;
}

void solve() {
    cin >> N >> M;

    init();

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    cin >> S >> F;

    Dijkstra(S);

    for (int i = 1; i <= N; i++) {
        for (auto &[next, cost]: graph[i]) {
            if (dist[i] + cost == dist[next]) path[next].push_back(i);
            if (dist[i] + cost == dist[next] + 1) sec_path[next].push_back(i);
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << DP(F, 0) << '\n';

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}