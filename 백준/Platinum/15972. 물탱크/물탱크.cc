#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f3f;

int N, M, H, sink;
vector<pii> graph[1000005];
int dist[1000005];

int convert(int y, int x);

void Dijkstra(int start);

void solve() {
    cin >> N >> M >> H;
    sink = N * M;
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < M; j++) {
            int now = convert(i, j);
            int prev = convert(i - 1, j);
            int a;
            cin >> a;
            if (a == -1) continue;
            else {
                if (i == 0) prev = sink;
                else if (i == N) now = sink;
                graph[now].push_back({prev, a});
                graph[prev].push_back({now, a});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M + 1; j++) {
            int now = convert(i, j);
            int prev = convert(i, j - 1);
            int a;
            cin >> a;
            if (a == -1) continue;
            else {
                if (j == 0) prev = sink;
                else if (j == M) now = sink;
                graph[now].push_back({prev, a});
                graph[prev].push_back({now, a});
            }
        }
    }

    Dijkstra(sink);

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans += min(H, dist[convert(i, j)]);
        }
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

int convert(int y, int x) {
    return (M * y) + x;
}

void Dijkstra(int start) {
    memset(dist, INF, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (pq.size()) {
        pii t = pq.top();
        pq.pop();
        int now = t.second;
        int val = t.first;

        if (dist[now] < val) continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int nval = max(val, graph[now][i].second);

            if (dist[next] > nval) {
                dist[next] = nval;
                pq.push({nval, next});
            }
        }
    }
    return;
}