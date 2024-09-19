#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M, S, T, U, V;
ll ans, dp1[200005], dp2[200005];
vector<ll> A, B, C;
int in_degree[200005], vst[200005];
vector<pii> graph[200005];
vector<int> path[200005], crit[200005];

void DFS(int now) {
    if (vst[now]) return;
    else vst[now] = 1;

    for (int next: path[now]) {
        crit[now].push_back(next);
        DFS(next);
    }
}

void toposort() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        dp1[i] = B[i];
        dp2[i] = C[i];
        if (!in_degree[i]) q.push(i);
    }

    for (int i = 1; i <= N; i++) {
        int now = q.front();
        q.pop();
        for (int next: crit[now]) {
            if (--in_degree[next] == 0) q.push(next);
            dp1[next] = min(dp1[next], dp1[now]);
            dp2[next] = min(dp2[next], dp2[now]);
        }
    }

    ans = 1e18;
    for (int i = 1; i <= N; i++) ans = min({ans, C[i] + dp1[i], B[i] + dp2[i]});
}

void Dijkstra(int start, vector<ll> &dist) {
    fill(dist.begin(), dist.end(), 1e18);
    priority_queue<pii, vector<pii>, greater<>> pq;
    for (int i = 1; i <= N; i++) path[i].clear();

    dist[start] = 0;
    pq.push({0, start});

    while (pq.size()) {
        auto t = pq.top();
        pq.pop();
        ll now = t.second, v = t.first;
        if (dist[now] < v) continue;
        for (auto &[next, cost]: graph[now]) {
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

    A.resize(N + 5), B.resize(N + 5), C.resize(N + 5);

    Dijkstra(U, B);
    Dijkstra(V, C);
    Dijkstra(S, A);
    DFS(T);
    for (int i = 1; i <= N; i++) {
        for (int next: crit[i]) in_degree[next]++;
    }

    toposort();

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