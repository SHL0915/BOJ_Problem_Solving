#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll N, M, K;
vector<pii> graph[400005]; // 0 시작점, K + 1 끝점
vector<pii> a[200005], b[200005];
ll dist[400005];

void Dijkstra(int start) {
    memset(dist, INF, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<>> pq;

    dist[start] = 0;
    pq.push({start, 0});

    while (pq.size()) {
        pii t = pq.top();
        pq.pop();

        ll val = t.first, now = t.second;
        if (dist[now] < val) continue;

        for (pii next: graph[now]) {
            ll nval = val + next.second;
            if (dist[next.first] > nval) {
                dist[next.first] = nval;
                pq.push({nval, next.first});
            }
        }
    }

    return;
}

void solve() {
    cin >> M >> N >> K;

    for (int i = 1; i <= K; i++) {
        int x, y;
        cin >> x >> y;
        a[y].push_back({x, i + K});
        b[x].push_back({y, i});

        graph[i].push_back({i + K, 1});
        graph[i + K].push_back({i, 1});
    }

    for (int i = 1; i <= M; i++) {
        sort(b[i].begin(), b[i].end());
        for (int j = 0; j < b[i].size(); j++) {
            ll now = b[i][j].first, idx = b[i][j].second;
            if (i == 1 && j == 0) graph[0].push_back({idx, now - 1});
            if (j > 0) {
                ll pre = b[i][j - 1].first, pidx = b[i][j - 1].second;
                graph[pidx].push_back({idx, now - pre});
                graph[idx].push_back({pidx, now - pre});
            }
            if (i == M && j == b[i].size() - 1) graph[idx].push_back({2 * K + 1, N - now});
        }
    }

    for (int i = 1; i <= N; i++) {
        sort(a[i].begin(), a[i].end());
        for (int j = 0; j < a[i].size(); j++) {
            ll now = a[i][j].first, idx = a[i][j].second;
            if (i == N && j == a[i].size() - 1) graph[idx].push_back({2 * K + 1, M - now});
            if (j > 0) {
                ll pre = a[i][j - 1].first, pidx = a[i][j - 1].second;
                graph[pidx].push_back({idx, now - pre});
                graph[idx].push_back({pidx, now - pre});
            }
        }
    }

    Dijkstra(0);

    ll ans = dist[2 * K + 1];
    if (ans == INF) cout << -1;
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