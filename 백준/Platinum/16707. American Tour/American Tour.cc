#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int SZ = 21505;

struct edge {
    int to, cap, rev, cost;
};

int N, M;
vector<edge> graph[SZ]; // 도시 1 ~ N, 간선 N + 1 ~ N + 2 * M, source 0, sink N + 2 * M + 1;

inline int in(int a) { return N + a * 2 - 1; };

inline int out(int a) { return N + a * 2; };

void add_edge(int u, int v, int ca, int co) {
    graph[u].push_back({v, ca, (int) graph[v].size(), co});
    graph[v].push_back({u, 0, (int) graph[u].size() - 1, -co});
    return;
}

void connect(int a, int b, int e) {
    add_edge(a, in(e), INF, 0);
    add_edge(b, in(e), INF, 0);
    add_edge(out(e), a, INF, 0);
    add_edge(out(e), b, INF, 0);
}

pii MCMF(int s, int e) {
    int mc = 0, mf = 0;
    while (1) {
        vector<int> mark(SZ, 0), dist(SZ, INF), par(SZ, -1), idx(SZ, -1);
        queue<int> q;
        q.push(s);
        mark[s] = 1;
        dist[s] = 0;
        while (q.size()) {
            int now = q.front();
            q.pop();
            mark[now] = 0;
            int cnt = 0;
            for (auto next: graph[now]) {
                if (next.cap > 0 && dist[next.to] > dist[now] + next.cost) {
                    dist[next.to] = dist[now] + next.cost;
                    par[next.to] = now;
                    idx[next.to] = cnt;
                    if (mark[next.to] == 0) {
                        q.push(next.to);
                        mark[next.to] = 1;
                    }
                }
                cnt++;
            }
        }
        if (par[e] == -1) break;
        int val = INF;
        for (int i = e; i != s; i = par[i]) val = min(val, graph[par[i]][idx[i]].cap);
        for (int i = e; i != s; i = par[i]) {
            mc += val * graph[par[i]][idx[i]].cost;
            graph[par[i]][idx[i]].cap -= val;
            int r = graph[par[i]][idx[i]].rev;
            graph[i][r].cap += val;
        }
        mf += val;
    }

    return {mf, mc};
}

void solve() {
    cin >> N >> M;
    int S = 0, E = N + 2 * M + 1;
    auto in = [&](int a) { return N + a * 2 - 1; };
    auto out = [&](int a) { return N + a * 2; };
    for (int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(in(i), out(i), 1, c);
        connect(a, b, i);
    }
    add_edge(S, 2, 2, 0);
    add_edge(1, E, 1, 0);
    add_edge(N, E, 1, 0);

    cout << MCMF(S, E).second;
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