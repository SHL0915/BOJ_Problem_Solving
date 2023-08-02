#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, A, B, K, G;
int adj[1005][1005];
pii range[1005][1005];
int dist[1005];

void Dijkstra(int start) {
    memset(dist, INF, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[start] = K;
    pq.push({K, start});

    while (pq.size()) {
        pii t = pq.top();
        pq.pop();

        int now = t.second;
        int val = t.first;

        if (dist[now] < val) continue;

        for (int i = 1; i <= N; i++) {
            int next = i;
            if (adj[now][next] == INF) continue;
            int nval;
            if (val >= range[now][next].first && val <= range[now][next].second)
                nval = range[now][next].second + adj[now][next];
            else nval = val + adj[now][next];

            if (dist[next] > nval) {
                dist[next] = nval;
                pq.push({nval, next});
            }
        }
    }

    return;
}

void solve() {
    cin >> N >> M;
    cin >> A >> B >> K >> G;
    vector<int> v;
    for (int i = 0; i < G; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    memset(adj, INF, sizeof(adj));

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }

    int t = 0;
    for (int i = 1; i < v.size(); i++) {
        int now = v[i], pre = v[i - 1];
        range[pre][now] = {t, t + adj[pre][now]};
        range[now][pre] = {t, t + adj[pre][now]};
        t += adj[pre][now];
    }

    Dijkstra(A);

    cout << dist[B] - K;
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